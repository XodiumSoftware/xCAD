// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// provides a generic SharedPointer template class for objects not derived from AcRxObject

#ifndef _AcSharedPtr_h_Included
#define _AcSharedPtr_h_Included

template <class T> class AcSharedPtr
{
    T*   _reference;
    int* _refCount;

public:
    AcSharedPtr() : _reference(0), _refCount(0) {};

    AcSharedPtr(T* pObject) : _refCount(0)
    {
        if ((_reference = pObject) != 0)
        {
            _refCount = (int*)::malloc(sizeof(int));
           *_refCount = 1;
        }
    };

    // the reference count, if present, is incremented (and shared) for both objects
    //
    AcSharedPtr(const AcSharedPtr& other)
    {
        _reference = other._reference;
        _refCount  = other._refCount;
        if (_refCount != 0)
            ++(*_refCount);
    };

    // decrements the reference count for the object referenced by this AcSharedPtr instance;
    // if the reference count reaches zero, the referenced object is deleted
    //
    ~AcSharedPtr()
    {
        if (_refCount && (--(*_refCount) == 0))
        {
            delete _reference;
            ::free(_refCount);
        }
    };

    AcSharedPtr& operator=(const AcSharedPtr& other)
    {
        if (_reference != other._reference)
        {
            if (_refCount && (--(*_refCount) == 0))
            {
                delete _reference;
                ::free(_refCount);
            }
            _reference = other._reference;
            _refCount  = other._refCount;
            if (_refCount != 0)
                ++(*_refCount);
        }
        return *this;
    };

    T* operator->() { return _reference; };
    const T* operator->() const { return _reference; };

    // returns the object referenced by this AcSharedPtr instance;
    // the reference count for the object remains unchanged
    //
    T* get() { return _reference; };
    const T* get() const { return _reference; };

    operator T*() { return _reference; };
    operator const T*() const { return _reference; };

    // returns the object referenced by this AcSharedPtr instance;
    // the reference count for the object remains unchanged
    //
    T& operator*() { return *_reference; };
    const T& operator*() const { return *_reference; };

    // returns true if this AcSharedPtr instance contains a null object.
    //
    bool isNull() const { return _reference == 0; };

    // detaches the referenced object from this AcSharedPtr instance;
    // NOTE : this method may be used only if reference count is 1 !
    // (when this AcSharedPtr instance is the only owner of the referenced object)
    //
    T* detach()
    {
        if (_refCount == 0)
            return 0;
        if (*_refCount > 1)
        {
            assert(false);
        }
        ::free(_refCount);
        _refCount = 0;
        T* ret = _reference;
        _reference = 0;
        return ret;
    };

    // returns the reference count for the object referenced by this AcSharedPtr instance
    //
    int refCount() const { return _refCount ? *_refCount : 0; };
};

#endif // _AcSharedPtr_h_Included
