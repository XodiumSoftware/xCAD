#include "StdAfx.h"
#include "CustomEntity.h"

namespace CustomManagedEntity
{

#ifdef _BCAD
CMyManagedEntity::CMyManagedEntity() : Entity( mgdCtorHelper(new CMyEntity), true )
#else
CMyManagedEntity::CMyManagedEntity() : Entity( System::IntPtr(new CMyEntity()), true )
#endif
{
}

#ifdef _BCAD
CMyManagedEntity::CMyManagedEntity(System::IntPtr unmanagedPointer, bool autoDelete) :
                                       Entity(mgdCtorHelper(unmanagedPointer),autoDelete)
#else
CMyManagedEntity::CMyManagedEntity(System::IntPtr unmanagedPointer, bool autoDelete) :
                                       Entity(unmanagedPointer,autoDelete)
#endif
{
}

#ifdef _BCAD
CMyEntity* CMyManagedEntity::GetImpObj()
{
return getImpObjHelper<CMyEntity>(UnmanagedObject);
}
#else
CMyEntity* CMyManagedEntity::GetImpObj()
{
return static_cast<CMyEntity*>(UnmanagedObject.ToPointer());
}
#endif

void CMyManagedEntity::Point1::set(Point3d point)
{
   Interop::Check(GetImpObj()->set_Point1(GETPOINT3D(point)));
}

void CMyManagedEntity::Point2::set(Point3d point)
{
   Interop::Check(GetImpObj()->set_Point2(GETPOINT3D(point)));
}

void CMyManagedEntity::Point3::set(Point3d point)
{
   Interop::Check(GetImpObj()->set_Point3(GETPOINT3D(point)));
}

//////////////////////////////////////////////////////////////////////////
// Derived from CMyManagedEntity / CMyEntity
// does not need the constructor helpers
CMyManagedEntityDerived::CMyManagedEntityDerived() 
    : CMyManagedEntity( System::IntPtr(new CMyEntityDerived()), true )
{
}

CMyManagedEntityDerived::CMyManagedEntityDerived(System::IntPtr unmanagedPointer, bool autoDelete) 
    : CMyManagedEntity(unmanagedPointer,autoDelete)
{
}

CMyEntityDerived* CMyManagedEntityDerived::GetImpObj()
{
    return static_cast<CMyEntityDerived*>(CMyManagedEntity::GetImpObj());
}


};
