// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BrxMgdObjectFactory.h"

//////////////////////////////////////////////////////////////////////////
#pragma managed(push, off)
extern AcRxObject* ACfromDD(const OdRxObject* pOdObj);
extern OdRxObject* DDfromAC(const AcRxObject* pAcObj);
namespace Brx
{
    extern void DecOdRef(AcRxObject& acObj);
    extern int GetNumOdRefsAdded(AcRxObject& acObj);
};
#pragma managed(pop)

template<typename ACTYPE>
inline ACTYPE* getImpObjHelper(System::IntPtr odObject)
{
    OdRxObject* pOdObject = reinterpret_cast<OdRxObject*>(odObject.ToPointer());
    return static_cast<ACTYPE*>(ACfromDD(pOdObject));
}

class mgdCtorHelper
{
    int m_startRefs;
    AcRxObject* m_acRxObject;
    static AcRxObject* fromPtr(System::IntPtr ptr) { return reinterpret_cast<AcRxObject*>(ptr.ToPointer()); }
public:
    mgdCtorHelper(System::IntPtr acObject) : m_acRxObject(fromPtr(acObject)), m_startRefs(0)
        { if (m_acRxObject) m_startRefs += Brx::GetNumOdRefsAdded(*m_acRxObject); }
    mgdCtorHelper(AcRxObject* acRxObject, bool passOwnership = true) : m_acRxObject(acRxObject), m_startRefs(passOwnership ? 0 : 1)
        { if (m_acRxObject) m_startRefs += Brx::GetNumOdRefsAdded(*m_acRxObject); }
    ~mgdCtorHelper()
        { if (m_acRxObject && Brx::GetNumOdRefsAdded(*m_acRxObject) > m_startRefs) Brx::DecOdRef(*m_acRxObject); }
    operator System::IntPtr() const { return System::IntPtr(DDfromAC(m_acRxObject)); }
};

//////////////////////////////////////////////////////////////////////////
#define GETEXTENTS3D(val) (*reinterpret_cast<AcDbExtents*>(&(val)))
#define GETVECTOR3D(val) (*reinterpret_cast<AcGeVector3d*>(&(val)))
#define GETOBJECTID(val) (*reinterpret_cast<AcDbObjectId*>(&(val)))
#define GETTOL(val) (*reinterpret_cast<AcGeTol*>(&(val)))
#define GETVECTOR2D(val) (*reinterpret_cast<AcGeVector2d*>(&(val)))
#define GETSCALE2D(val) (*reinterpret_cast<AcGeScale2d*>(&(val)))
#define GETPOINT2D(val) (*reinterpret_cast<AcGePoint2d*>(&(val)))
#define GETMATRIX2D(val) (*reinterpret_cast<AcGeMatrix2d*>(&(val)))
#define GETPOINT3D(val) (*reinterpret_cast<AcGePoint3d*>(&(val)))
#define GETMATRIX3D(val) (*reinterpret_cast<AcGeMatrix3d*>(&(val)))
#define GETSUBENTITYID(val) (*reinterpret_cast<AcDbSubentId*>(&(val)))
#define GETSCALE3D(val) (*reinterpret_cast<AcGeScale3d*>(&(val)))

//NOTE: This class is intended only for inline use, because the string is only pinned
//while this class instance is alive. The returned native string pointer becomes
//invalid as soon as the managed string is moved in memory or garbage collected, so
//it should never be stored or assigned to a variable.
class StringToWchar
{
    typedef System::Runtime::InteropServices::GCHandle GCH;
    const wchar_t* m_ptr;
    void* m_pin;
public:
    StringToWchar(System::String^ str)
    {
        m_pin = GCH::operator System::IntPtr(GCH::Alloc(str, System::Runtime::InteropServices::GCHandleType::Pinned)).ToPointer();
        pin_ptr<const wchar_t> tempPinnedPtr = PtrToStringChars(str);
        m_ptr = tempPinnedPtr;
    }
    ~StringToWchar()
    {
        GCH h = GCH::operator System::Runtime::InteropServices::GCHandle(System::IntPtr(m_pin));
        m_pin = nullptr;
        h.Free();
    }
    operator const wchar_t*()
    {
        return m_ptr;
    }
};

inline System::String^ WcharToString(const wchar_t* value)
{
  return gcnew System::String(value);
}

inline Teigha::DatabaseServices::ObjectId ToObjectId(const AcDbObjectId& nativeVal)
{
    Teigha::DatabaseServices::ObjectId managedVal;
    GETOBJECTID(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Vector2d ToVector2d(const AcGeVector2d& nativeVal)
{
    Teigha::Geometry::Vector2d managedVal;
    GETVECTOR2D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Vector3d ToVector3d(const AcGeVector3d& nativeVal)
{
    Teigha::Geometry::Vector3d managedVal;
    GETVECTOR3D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Tolerance ToTolerance(const AcGeTol& nativeVal)
{
    Teigha::Geometry::Tolerance managedVal;
    GETTOL(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Matrix2d ToMatrix2d(const AcGeMatrix2d& nativeVal)
{
    Teigha::Geometry::Matrix2d managedVal;
    GETMATRIX2D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Scale3d ToScale3d(const AcGeScale3d& nativeVal)
{
    Teigha::Geometry::Scale3d managedVal;
    GETSCALE3D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Point3d ToPoint3d(const AcGePoint3d& nativeVal)
{
    Teigha::Geometry::Point3d managedVal;
    GETPOINT3D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::DatabaseServices::Extents3d ToExtents3d(const AcDbExtents& nativeVal)
{
    Teigha::DatabaseServices::Extents3d managedVal;
    GETEXTENTS3D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Matrix3d ToMatrix3d(const AcGeMatrix3d& nativeVal)
{
    Teigha::Geometry::Matrix3d managedVal;
    GETMATRIX3D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Point2d ToPoint2d(const AcGePoint2d& nativeVal)
{
    Teigha::Geometry::Point2d managedVal;
    GETPOINT2D(managedVal) = nativeVal;
    return managedVal;
}

inline Teigha::Geometry::Scale2d ToScale2d(const AcGeScale2d& nativeVal)
{
    Teigha::Geometry::Scale2d managedVal;
    GETSCALE2D(managedVal) = nativeVal;
    return managedVal;
}






