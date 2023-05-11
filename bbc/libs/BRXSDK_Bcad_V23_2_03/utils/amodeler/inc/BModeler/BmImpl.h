// Copyright (C) 2009 Henrik Vallgren/Streamspace.
#pragma once

namespace AModeler
{

template<typename T> 
class OwnRefPtr
{
public:
	typedef T	*OwnPtr;
	typedef T	*RefPtr;

	OwnRefPtr()	: owner_(NULL), reference_(NULL)	{}
	~OwnRefPtr()
	{
		resetOwner(NULL);
	}

	void resetOwner(T*t)
	{
		if	(owner_)
        {
            T* savedOwner = owner_;
            owner_ = NULL; // prevent recursion...
            delete savedOwner;
        }
		owner_=t;
	}

	operator bool() const
	{
		return (owner_ || reference_);
	}
	T*	get()
	{
		if	(owner_)
			return owner_;
		return reference_;
	}
	T* operator ->() { return get(); }

	T* owner() const { return owner_; }
	RefPtr	reference_;
private:
	OwnPtr	owner_;
};

template <typename OwnType, typename OwnPtr, typename RefType>
void bindOwningPointer(OwnType *owning_object, OwnPtr &owner, RefType *ref_object)
{
	owner->resetOwner(ref_object);
	ref_object->reference_=owning_object;
	owner->reference_=NULL;
	ref_object->resetOwner(NULL);
}

template <typename OwnType, typename RefType>
void bindInterfacePointer(OwnType *owning_object, RefType *ref_object)
{
	owning_object->resetOwner(ref_object);
	ref_object->m_pBrxImp->reference_=owning_object;
	owning_object->reference_=NULL;
	ref_object->m_pBrxImp->resetOwner(NULL);
}

template <typename FromPtr, typename ToPtr>
void transferOwnerShip(FromPtr &from, ToPtr &to)
{
	if	(to.owner())
		return;
	to.owner_=from.reference_;
	from.owner_=NULL;
	to.reference_=NULL;
}

}
