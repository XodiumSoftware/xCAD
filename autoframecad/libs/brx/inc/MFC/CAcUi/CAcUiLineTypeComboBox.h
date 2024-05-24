// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiLTypeRecord.h"
#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiLineTypeComboBox: public CAcUiMRUComboBox
{
public:
    AcDbObjectId getOIDCurSel();
    AcDbObjectId getOIDSel(int);
    bool getDbReload();
    bool isOtherSelected();
    CAcUiLineTypeComboBox();
    int getLastSelection();
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    virtual void OnComboBoxInit();
    virtual ~CAcUiLineTypeComboBox();
    void AddItems();
    void emptyLTypeLocalList();
    void forceSelectOther(BOOL);
    void setCurSelByOID(const AcDbObjectId&);
    void setDbReload(bool);
protected:
    AcDbDatabase* getLTLocalMapDB();
    AcDbDatabase* m_pLTLocalMapDB;
    bool m_bDbReload;
    CAcUiLTypeRecord* CreateLTRecord(CString&,AcDbObjectId&);
    CObList m_LTypeLocalList;
    int AddLTypeToControl(CAcUiLTypeRecord*);
    int FindItemByCargo(AcDbObjectId);
    INT_PTR GetItemCargo(int);
    virtual BOOL OnSelectOther(BOOL,int,int&);
    virtual int ImageWidth();
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    void LoadContentsFromDatabase();
    void setLTLocalMapDB(AcDbDatabase*);
    void ShowLTypes(bool = false);

    DECLARE_MESSAGE_MAP()
};
