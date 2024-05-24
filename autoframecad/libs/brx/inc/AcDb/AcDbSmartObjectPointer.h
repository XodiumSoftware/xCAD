// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once


#include "AcDb/AcDbGlobal.h"

template<class OBJ> inline Acad::ErrorStatus accessAcDbObjectForRead(OBJ*& obj, AcDbObjectId objId, bool& opened, bool openErased = false)
{
    return ::accessAcDbObjectForRead((AcDbObject*&)obj, objId, &OBJ::desc, opened, openErased);
};

template<> inline Acad::ErrorStatus accessAcDbObjectForRead<AcDbObject>(AcDbObject*& obj, AcDbObjectId objId, bool& opened, bool openErased)
{
    return ::accessAcDbObjectForRead(obj, objId, nullptr, opened, openErased);
}

template<class OBJ> class AcDbSmartObjectPointer;

/** _ */
template<class OBJ> class ReadableAcDbObject
{
private:
    ReadableAcDbObject(const ReadableAcDbObject&);
    ReadableAcDbObject& operator=(const ReadableAcDbObject&);

public:
    ReadableAcDbObject() : mpObject(NULL), mStatus(Acad::eNotOpenForRead), mbOpened(false) {}
    ReadableAcDbObject(OBJ*& pObject, AcDbObjectId objId, bool openErased, bool immediate = true)
        : mpObject(NULL), mStatus(Acad::eNotOpenForRead), mbOpened(false)
    {
        if (immediate)
            enableRead(pObject, objId, openErased);
    }
    ~ReadableAcDbObject()
    {
        revertRead();
    };

    void enableRead(OBJ*& pObject, AcDbObjectId objId, bool openErased)
    {
        revertRead();
        pObject = NULL;
        if (mStatus == Acad::eNotOpenForRead)
        {
            mStatus = accessAcDbObjectForRead(pObject, objId, mbOpened, openErased);
            mpObject = pObject;
        }
    };
    void revertRead()
    {
        if (mpObject)
        {
            if (mpObject->objectId().isNull())
                delete mpObject;
            else if (mStatus == Acad::eOk && mbOpened)
                mpObject->close();
            mpObject = NULL;
        }
        mStatus = Acad::eNotOpenForRead;
    };
    bool isReadable() const { return (mpObject && mpObject->isReadEnabled()); };
    const OBJ* object() const { return (mStatus == Acad::eOk) ? mpObject : NULL; };
    OBJ* object() { return (mStatus == Acad::eOk) ? mpObject : NULL; };
    Acad::ErrorStatus statusCode() const { return mStatus; };

    // Support for AcDbObjectPointer functionality
    friend AcDbSmartObjectPointer<OBJ>;
    ReadableAcDbObject(AcDbObjectId objId, bool openErased, bool immediate = true)
        : mpObject(NULL), mStatus(Acad::eNotOpenForRead), mbOpened(false)
    {
        if (immediate)
            enableRead(mpObject, objId, openErased);
    }
    void forgetCurrentAndAcceptNewAsIs(OBJ* pNewObj)
    {
        if (mpObject != pNewObj)
        {
            mpObject = pNewObj;
            mStatus = pNewObj ? Acad::eOk : Acad::eNotOpenForRead;
            mbOpened = (pNewObj != NULL);
        }
    };

private:
    OBJ* mpObject;
    Acad::ErrorStatus mStatus;
    bool mbOpened;
};


/** _ */
class WritableAcDbObject
{
private:
    WritableAcDbObject(const WritableAcDbObject&);
    WritableAcDbObject& operator=(const WritableAcDbObject&);

public:
    WritableAcDbObject()
        : mpObject(NULL), mStatus(Acad::eNullObjectPointer), mbOpenLocked(false)
        , mbWasNotify(false), mbWasWrite(false), mClosed(0) {}
    WritableAcDbObject(AcDbObject* pObject, bool immediate = true, bool openLocked = false)
        : mpObject(NULL), mStatus(Acad::eNullObjectPointer), mbOpenLocked(openLocked)
        , mbWasNotify(false), mbWasWrite(false), mClosed(0)
    {
        replaceObject(pObject, immediate);
    }
    ~WritableAcDbObject()
    {
        revertWrite();
    };

    void replaceObject(AcDbObject* pObject, bool immediate = true)
    {
        revertWrite();
        mpObject = pObject;
        if (!pObject)
        {
            mStatus = Acad::eNullObjectPointer;
            return;
        }
        mStatus = Acad::eNotOpenForWrite;
        if (immediate)
            enableWrite();
    }
    bool enableWrite() {
        if (isWritable())
            return true;
        if (!mpObject)
            return false;
        mStatus = accessAcDbObjectForWrite(mpObject, mbWasNotify, mbWasWrite, mClosed, mbOpenLocked);
        return isWritable();
    };
    void revertWrite()
    {
        if (mpObject && !mpObject->objectId().isNull())
            mStatus = revertAcDbObjectFromWrite(mpObject, mStatus, mbWasNotify, mbWasWrite, mClosed);
        forget();
    };
    bool isWritable() const { return (mStatus == Acad::eOk && mpObject); };
    Acad::ErrorStatus statusCode() const { return mStatus; };
    void forget() { mpObject = NULL; mStatus = Acad::eNullObjectPointer; };
    void setOpenOnLockedLayer(bool openLocked) { mbOpenLocked = openLocked; }

private:
    AcDbObject* mpObject;
    Acad::ErrorStatus mStatus;
    bool mbWasNotify;
    bool mbWasWrite;
    bool mbOpenLocked;
    int mClosed;
};


/** _ */
template<class OBJ> class AcDbSmartObjectPointer
{
protected:
    ReadableAcDbObject<OBJ> mReadable;
    WritableAcDbObject mWritable;

public:
    AcDbSmartObjectPointer() {}
    AcDbSmartObjectPointer(AcDbObjectId id, AcDb::OpenMode mode = AcDb::kForRead, bool openErased = false, bool openLocked = false)
        : mReadable(id, openErased), mWritable(mReadable.object(), mode == AcDb::kForWrite, openLocked) {}
    ~AcDbSmartObjectPointer() {}
private:
    AcDbSmartObjectPointer(AcDbSmartObjectPointer&);
    AcDbSmartObjectPointer& operator=(AcDbSmartObjectPointer&);

public:
    Acad::ErrorStatus acquire(OBJ*&);
    Acad::ErrorStatus close();
    Acad::ErrorStatus create();
    Acad::ErrorStatus open(AcDbObjectId, AcDb::OpenMode = AcDb::kForRead, bool = false, bool = false);
    Acad::ErrorStatus openStatus() const;
    Acad::ErrorStatus release(OBJ*&);
    const OBJ* object() const { return mReadable.object(); }
    OBJ* object() { return mReadable.object(); }
    const OBJ* operator->() const { return object(); }
    OBJ* operator->() { return object(); }
    operator const OBJ*() const { return object(); }
    operator OBJ*() { return object(); }

private:
    Acad::ErrorStatus revertAccess();
};


template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::open(AcDbObjectId id, AcDb::OpenMode mode, bool openErased, bool openLocked)
{
    if (mReadable.isReadable())
    {
        Acad::ErrorStatus closeStatus = revertAccess();
        if (closeStatus != Acad::eOk)
            return closeStatus;
    }
    mReadable.enableRead(mReadable.mpObject, id, openErased);
    if (mReadable.isReadable())
    {
        mWritable.setOpenOnLockedLayer(openLocked);
        mWritable.replaceObject(mReadable.object(), (mode == AcDb::kForWrite));
    }
    return openStatus();
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::revertAccess()
{
    mWritable.revertWrite();
    mReadable.revertRead();
    return Acad::eOk;
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::acquire(OBJ*& pObj)
{
    revertAccess();
    mReadable.forgetCurrentAndAcceptNewAsIs(pObj);
    pObj = NULL;
    return Acad::eOk;
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::close()
{
    revertAccess();
    return Acad::eOk;
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::create()
{
    OBJ* pNewObject = new OBJ;
    if (!pNewObject)
        return Acad::eNullObjectPointer;
    revertAccess();
    mReadable.forgetCurrentAndAcceptNewAsIs(pNewObject);
    return Acad::eOk;
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::openStatus() const
{
    if (mWritable.isWritable())
        return mWritable.statusCode();
    switch (mWritable.statusCode())
    {
    case Acad::eNullObjectPointer: break;
    case Acad::eNotOpenForWrite: break;
    default: return mWritable.statusCode();
    }
    return mReadable.statusCode();
}

template<class OBJ>
Acad::ErrorStatus AcDbSmartObjectPointer<OBJ>::release(OBJ*& pObj)
{
    pObj = mReadable.object();
    mWritable.forget();
    mReadable.forgetCurrentAndAcceptNewAsIs(NULL);
    return Acad::eOk;
}
