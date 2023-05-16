// od_ed_uicontext.h : OdEdUIContext, OdEdUIContextManager, OdEdUIContextsIterator interface
// Copyright © Menhirs NV. All rights reserved.
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"
#include "RxObject.h"
#include "IdArrays.h"

namespace OdEdUI
{
    enum EContextMenuType
    {
        eCMNone    = -1,
        eCMDefault = 0,
        eCMCommand,
        eCMEdit,
        eCMGrips,
        eCMRealtimeMotion,
        eCMSnap,
        eCMDropDrawingFiles,    // fileset dropped contains dwg/dxf file(s)
        eCMDropNonDrawingFiles, // fileset dropped doesn't contain dwg/dxf file(s)
    };
};// end namespace OdEdUI

class OdEdUIMenuInfo;
typedef OdSmartPtr<OdEdUIMenuInfo> OdEdUIMenuInfoPtr;

class ODAPI OdEdUIContext : public OdRxObject
{
protected:
    virtual ~OdEdUIContext(){};
public:
    ODRX_DECLARE_MEMBERS(OdEdUIContext);
        // Called when an entry in a client context menu is called
    virtual void onCommand(unsigned int) = 0;
        // Called directly before the client context menu is displayed
    virtual void OnUpdateMenu();
        // Called to retrieve the client context menu as a HMENU
    virtual OdEdUIMenuInfoPtr getMenuContext(const OdRxClass*, const OdDbObjectIdArray&) = 0;
        // Called to retrieve the client context menu as a HMENU
    virtual OdEdUIMenuInfoPtr getMenuContext(const OdRxClass*, const OdDbObjectIdArray&,
        const OdArray< OdArray< OdDbFullSubentPath> >&);
};
typedef OdSmartPtr<OdEdUIContext> OdEdUIContextPtr;

class ODAPI OdEdUIContextsIterator
{
protected:
    virtual ~OdEdUIContextsIterator(){};
public:
        // Returns the first context menu of given type (and class) or NULL
    virtual OdEdUIContext* begin() = 0;
        // Returns the next context menu of given type (and class) or NULL
    virtual OdEdUIContext* step() = 0;
        // Returns the string associated with the current menu or empty string
        // (Only OdEdUI::eCMDefault menus have string associated)
    virtual const OdString& label() = 0;
};

class OdEdUIMenuInfoIterator;
class ODAPI OdEdUIMenuInfo : public OdRxObject
{
public:
    typedef void(*ContextMenuCallback)(unsigned int);

    ODRX_DECLARE_MEMBERS(OdEdUIMenuInfo);

    void setCallback(ContextMenuCallback cb) { m_callback = cb; }
    void fireCallback(unsigned int id)
    {
        if (m_callback)
            m_callback(id);
    }

        // Sets label, id, enabled, checked
        // Being separator is the default, don't use set in this case
    virtual void set(const OdString& label,unsigned int id, bool enabled = true,bool checked = false) = 0;
        // Sets help string
    virtual void setHelp(const OdString&) = 0;
    virtual void setBmpRawData(void *, unsigned int, unsigned int) = 0;
    virtual void setEnabled(bool) = 0;
    virtual void setChecked(bool) = 0;
        // Adds a menu entry
    virtual void appendEntry(OdEdUIMenuInfo* subMenu) = 0;
    virtual const OdString& label() const = 0;
    virtual const OdString& help() const  = 0;
    virtual void* bmpRawData(unsigned int&, unsigned int&) const = 0;
    virtual unsigned int id() const  = 0;
    virtual bool enabled() const = 0;
    virtual bool checked() const = 0;
    virtual bool isSeparator() const = 0;
    virtual bool hasEntries() const  = 0;
        // Gets an iterator to iterate over all menu entries of this OdEdUIMenuInfo
    virtual OdEdUIMenuInfoIterator* newIterator() const = 0;
    virtual void deleteIterator(OdEdUIMenuInfoIterator*) const = 0;

private:
    ContextMenuCallback m_callback = nullptr;
};

class ODAPI OdEdUIMenuInfoIterator
{
protected:
    virtual ~OdEdUIMenuInfoIterator(){};
public:
        // Returns menu information for the first menu entry or NULL
    virtual const OdEdUIMenuInfo *begin() = 0;
        // Returns menu information for the next menu entry or NULL
    virtual const OdEdUIMenuInfo *step() = 0;
};

class ODAPI OdEdUIContextManager
{
protected:
    virtual ~OdEdUIContextManager(){};
public:
        // Add a context menu which has a name, this is the case for OdEdUI::eCMDefault menus
    virtual bool addContextMenu(OdEdUIContext*,OdEdUI::EContextMenuType, OdString&,const void* appid) = 0;
        // Add a context menu for a given class, this is the case for OdEdUI::eCMEdit menus
    virtual bool addContextMenu(OdEdUIContext*,OdEdUI::EContextMenuType, OdRxObject* pClassOrCmd,const void* appid) = 0;
        // To remove a OdEdUI::eCMEdit context menu the class has to be given
    virtual bool removeContextMenu(OdEdUIContext*,OdEdUI::EContextMenuType,OdRxObject* pClassOrCmd = NULL) = 0;
        // For an iterator over OdEdUI::eCMEdit context menus the class has to be given
        // The iterator will iterate over all registered menus for the given class and 
        // over all registered menus for the parent classes
        // For an iterator over OdEdUI::eCMDefault context menus just set first argument.
    virtual OdEdUIContextsIterator* newIterator(OdEdUI::EContextMenuType,OdRxObject* pClassOrCmd = NULL) = 0;
    virtual void deleteIterator(OdEdUIContextsIterator* ) = 0;
        // Creates a new menu information object.
    virtual OdEdUIMenuInfoPtr create() = 0;
};

OdEdUIContextManager* odedUIContextManager();
