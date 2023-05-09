#pragma once

# ifdef BRXMGD_MODULE
#   define BRXMGD_API   __declspec(dllexport)
# else
#   define BRXMGD_API   __declspec(dllimport)
# endif

class BrxMgdObjectFactoryBaseImpl;
class AcRxClass;
class AcRxObject;

class BRXMGD_API BrxMgdObjectFactoryBase
{
private:
    BrxMgdObjectFactoryBaseImpl* m_pImpl;

public:
    BrxMgdObjectFactoryBase();
    virtual ~BrxMgdObjectFactoryBase();
    virtual gcroot<Teigha::Runtime::DisposableWrapper^> createRCW(AcRxObject* unmanagedPointer, bool autoDelete) = 0;

protected:
    void addPE(AcRxClass* pClass);
    void delPE(AcRxClass* pClass);
};

template <typename RCW, typename ImpObj>
class BrxMgdObjectFactory : public BrxMgdObjectFactoryBase
{
public:
    BrxMgdObjectFactory()
    {
        addPE(ImpObj::desc());
    }
    virtual ~BrxMgdObjectFactory()
    {
        delPE(ImpObj::desc());
    }
    virtual gcroot<Teigha::Runtime::DisposableWrapper^> createRCW(AcRxObject* unmanagedPointer, bool autoDelete)
    {
        return gcnew RCW(System::IntPtr(static_cast<ImpObj*>(unmanagedPointer)),autoDelete);
    }
};

#define AcMgObjectFactoryBase BrxMgdObjectFactoryBase
#define AcMgObjectFactory BrxMgdObjectFactory