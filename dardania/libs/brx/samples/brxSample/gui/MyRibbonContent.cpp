// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// This is an example how to use the C++ Ribbon API for BRX

#include "StdAfx.h"
#include <tchar.h>
#include "AcString.h"


#ifndef BRX_APP  // // dummy implemented for ARX build
bool addRibbonContent()
{
    return false;
}
#endif // !BRX_APP


#ifdef BRX_APP  // not available with ARX

#include "MyRibbonContent.h"

static AcRibbonTab* createTab(const ACHAR* id,
                              const ACHAR* title,
                              const ACHAR* name)
{
    AcRibbonTab* pNewTab = new AcRibbonTab();
    pNewTab->setTitle(title);
    pNewTab->setId(id);
    pNewTab->setName(name);
    return pNewTab;
}

static AcRibbonPanelSource* createPanelSrc(const ACHAR* id,
                                           const ACHAR* title,
                                           const ACHAR* name)
{
    AcRibbonPanelSource* pNewPanelSrc = new AcRibbonPanelSource();
    pNewPanelSrc->setTitle(title);
    pNewPanelSrc->setId(id);
    pNewPanelSrc->setName(name);
    return pNewPanelSrc;
}

static void setItemData( AcRibbonItem* pItem,
                         const ACHAR* id,
                         const ACHAR* text,
                         const ACHAR* tooltip,
                         const ACHAR* imagePath,
                         bool isExternalImg = false)
{
    pItem->setText(text);
    pItem->setToolTip(tooltip);
    pItem->setId(id);
#if __BRXTARGET < 21
    pItem->setImagePath(imagePath, isExternalImg);
#else
    pItem->setImagePath(imagePath);
#endif
}

static AcRibbonControl* ribbonControl()
{
    if (!AcRibbonServices::ribbonPaletteSet())
        AcRibbonServices::createRibbonPaletteSet();
    if (!AcRibbonServices::ribbonPaletteSet()->isShown())
        AcRibbonServices::ribbonPaletteSet()->show(true);
    return AcRibbonServices::ribbonPaletteSet()->ribbonControl();
}

static AcString generateId()
{
    static unsigned int id = 0;
    AcString newId;
    newId.format(_T("RBN_%u"), id++);
    return newId;
}

static bool loadRibbonContent()
{
    bool isOk = true;
    AcRibbonControl* pRibbonCtrl = ribbonControl();
    if (!pRibbonCtrl)
        return false;
    AcString newTabId = generateId();
    AcRibbonTab* pTab = createTab(newTabId.constPtr(), _T("BRX Ribbon Tab"), _T("My Tab"));
    AcRibbonUtils::AcResult res;
    if (pRibbonCtrl->addTab(pTab) == AcRibbonUtils::eRbnOk)
        acutPrintf(_T("Tab with Id \"%s\" has been added to RibbonControl."), newTabId.constPtr());
    else
        acutPrintf(_T("Error when adding Tab with Id \"%s\"."), newTabId.constPtr());

    pRibbonCtrl->setActiveTab(pTab);

    // 1st ribbon panel : Add buttons and split buttons using row panels
    AcRibbonPanel* pPanel = new AcRibbonPanel();
    AcRibbonPanelSource* pPanelSrc = createPanelSrc(generateId().constPtr(),
                                                _T("Buttons and Split Buttons"),
                                                _T("Buttons and Split Buttons"));
    isOk = pPanel->setSource(pPanelSrc);
    res = pTab->addPanel(pPanel);

    AcRibbonSplitButton* pSplitButton = new AcRibbonSplitButton();
    setItemData(pSplitButton,
                generateId().constPtr(),
                _T("Split Button"),
                _T("Tooltip for split button"),
                _T("circle"));

    AcRibbonButton* pButton1 = new AcRibbonButton();
    setItemData(pButton1,
                generateId().constPtr(),
                _T("Button 1"),
                _T("Tooltip with Title\n+Description"),
                _T("rectang"));
    pButton1->setCommandParameter(_T("rectang"));
    pButton1->setButtonStyle(AcRibbonUtils::eLargeWithHorizontalText);

    AcRibbonButton* pButton2 = new AcRibbonButton();
    setItemData(pButton2,
                generateId().constPtr(),
                _T("Button 2"),
                _T("Tooltip with Title\n+Description"),
                _T("pline"));
    pButton2->setCommandParameter(_T("pline"));

    res = pSplitButton->addItem(pButton1);
    res = pSplitButton->addItem(pButton2);

    AcRibbonButton* pButton3 = new AcRibbonButton();
    setItemData(pButton3,
                generateId().constPtr(),
                _T("Button 3"),
                _T("Tooltip with Title\n+Description"),
                _T("polygon"));
    pButton3->setCommandParameter(_T("polygon"));

    AcRibbonButton* pButton4 = new AcRibbonButton();
    setItemData(pButton4,
                generateId().constPtr(),
                _T("Button 4"),
                _T("Tooltip with Title\n+Description"),
                _T("circle_r"));
    pButton4->setCommandParameter(_T("circle"));

    pSplitButton->setCurrentItem(pButton2);
    pSplitButton->setButtonStyle(AcRibbonUtils::eLargeWithText);

    res = pPanelSrc->addItem(pSplitButton);
    AcRibbonRowPanel* pRowPanel = new AcRibbonRowPanel();
    res = pPanelSrc->addItem(pRowPanel);
    res = pRowPanel->addItem(pButton1);
    res = pRowPanel->addItem(new AcRibbonRowBreak());
    res = pRowPanel->addItem(pButton2);
    res = pRowPanel->addItem(new AcRibbonSeparator());
    res = pRowPanel->addItem(pButton3);
    AcRibbonSeparator* pSeparator = new AcRibbonSeparator();
    pSeparator->setSeparatorStyle(AcRibbonUtils::eLine);
    res = pRowPanel->addItem(pSeparator);
    res = pRowPanel->addItem(pButton4);

    // 2nd ribbon panel : Add toggle buttons and combo box
    pPanel = new AcRibbonPanel();
    pPanelSrc = createPanelSrc(generateId().constPtr(),
                               _T("Combo and Toggle button"),
                               _T("Combo and Toggle button"));
    isOk = pPanel->setSource(pPanelSrc);
    res = pTab->addPanel(pPanel);

    AcRibbonCombo* pCombo = new AcRibbonCombo();
    pCombo->setId(_T("MY_COMBO"));
    pButton1 = new AcRibbonButton();
    setItemData(pButton1,
                generateId().constPtr(),
                _T("Combo Item 1"),
                _T("Tooltip 1"),
                _T("rectang"));
    pButton1->setCommandParameter(_T("rectang"));

    pButton2 = new AcRibbonButton();
    setItemData(pButton2,
                generateId().constPtr(),
                _T("Combo Item 2"),
                _T("Tooltip 2"),
                _T("pline"));
    pButton2->setCommandParameter(_T("pline"));

    pButton3 = new AcRibbonButton();
    setItemData(pButton3,
                generateId().constPtr(),
                _T("Combo Item 3"),
                _T("Tooltip 3"),
                _T("polygon"));
    pButton3->setCommandParameter(_T("polygon"));

    res = pCombo->addItem(pButton1);
    res = pCombo->addItem(pButton2);
    res = pCombo->addItem(pButton3);
    res = pCombo->setCurrentItem(pButton2);
    pCombo->setWidth(180);

    AcRibbonToggleButton* pToggleButton1 = new AcRibbonToggleButton();
    setItemData(pToggleButton1,
                generateId().constPtr(),
                _T("Toggle Button 1"),
                _T("Tooltip 1"),
                _T("download_32"),  // External image, add images path to SRCHPATH or use absolute path
                true);
    pToggleButton1->setButtonStyle(AcRibbonUtils::eLargeWithHorizontalText);
    pToggleButton1->setCheckState(true);

    AcRibbonToggleButton* pToggleButton2 = new AcRibbonToggleButton();
    setItemData(pToggleButton2,
                generateId().constPtr(),
                _T("Toggle Button 2"),
                _T("Tooltip 2"),
                _T("custom_1"),     // External image, add images path to SRCHPATH or use absolute path
                true);

    pRowPanel = new AcRibbonRowPanel();

    res = pPanelSrc->addItem(pToggleButton1);
    res = pPanelSrc->addItem(pRowPanel);
    res = pRowPanel->addItem(pCombo);
    res = pRowPanel->addItem(new AcRibbonRowBreak());
    res = pRowPanel->addItem(pToggleButton2);

    // 3rd ribbon panel : Add text box
    pPanel = new AcRibbonPanel();
    pPanelSrc = createPanelSrc(generateId().constPtr(),
                                _T("Panel with text box"),
                                _T("Panel with text box"));
    isOk = pPanel->setSource(pPanelSrc);
    res = pTab->addPanel(pPanel);

    AcRibbonTextBox* pTextBox = new AcRibbonTextBox();
    pTextBox->setText(_T("Static text"));
    pTextBox->setTextValue(_T("Text area"));
    pTextBox->setImagePath(_T("pline"));
    pTextBox->setShowImage(true);
    pTextBox->setShowText(true);
    pTextBox->setWidth(300);

    res = pPanelSrc->addItem(pTextBox);

    // Enable and Disable tabs, panels and items
    isOk = pPanel->enable(false);
    isOk = pSplitButton->enable(false);
    isOk = pToggleButton1->enable(false);

    return true;
}

void editRibbonContent()
{
    AcRibbonControl* pRibbonControl = ribbonControl();
    if (!pRibbonControl)
        return;

    int action = -1;
    ACHAR tabName[256];
    ACHAR panelName[256];
    ACHAR itemText[256], itemId[256];
    ACHAR tabId[256], panelId[256];
    AcString title;
    AcRibbonPanel* pPanel = nullptr;
    AcRibbonPanelSource* pSource = nullptr;
    AcRibbonItem* pItem = nullptr;
    AcRibbonButton* pButton = nullptr;
    AcRibbonTab* pTab = nullptr;


    if (acedGetInt(L"[1] Add Tab\n[2] Remove Tab\n[3] Add Panel\n[4] Remove Panel\n[5] Add Item\n[6] Remove Item\n", &action) != RTNORM)
        return;

    switch (action)
    {
        case 1:
            acedGetString(1, _T("Enter the Name for the new tab: "), tabName);
            {
                AcString id = generateId();
                pTab = createTab(id.constPtr(), tabName, tabName);
                if (pRibbonControl->addTab(pTab) == AcRibbonUtils::eRbnOk)
                    acutPrintf(_T("Tab with Id \"%s\" has been added to RibbonControl."), id.constPtr());
                else
                    acutPrintf(_T("Failed to add Tab with Id \"%s\"."), id.constPtr());
            }

            break;

        case 2:
            acedGetString(1, _T("Enter the Tab Id to be removed: "), tabId);
            pTab = pRibbonControl->findTab(tabId);
            if (pTab)
            {
                pTab->title(title);
                if (pRibbonControl->removeTab(pTab) == AcRibbonUtils::eRbnOk)
                    acutPrintf(_T("Tab with Title \"%s\" was removed."), title.constPtr());
                else
                    acutPrintf(_T("Failed to remove Tab with Id \"%s\"."), tabId);
            }
            else
                acutPrintf(_T("Tab with Id \"%s\" was not found."), tabId);

            break;

        case 3:
            acedGetString(1, L"Enter the Tab Id where the new Panel will be added: ", tabId);
            acedGetString(1, L"Enter the PanelSource Title for the new Panel: ", panelName);
    
            pTab = pRibbonControl->findTab(tabId);
            if (pTab)
            {
                AcString panelId = generateId();
                pSource = createPanelSrc(panelId.constPtr(), panelName, panelName);
                pPanel = new AcRibbonPanel();
                pPanel->setSource(pSource);
                if (pTab->addPanel(pPanel))
                    acutPrintf(_T("Panel with Id \"%s\" has been added to RibbonControl."), panelId.constPtr());
                else
                    acutPrintf(_T("Failed to add Panel with Id \"%s\"."), panelId.constPtr());
            }
            else
                acutPrintf(_T("The Tab with Id \"%s\" was not found."), tabId);

            break;

        case 4:
            acedGetString(1, L"Enter the Panel Id to be removed: ", panelId);
            pPanel = pRibbonControl->findPanel(panelId, pTab);
            if (pPanel && pTab)
            { 
                pTab->removePanel(pPanel);
                pPanel->source()->title(title);
                acutPrintf(_T("Panel with Title \"%s\" was removed."), title.constPtr());
            }
            else
                acutPrintf(_T("Panel with Id \"%s\" was not found."), panelId);

            break;

        case 5:
            acedGetString(1, L"Enter the Panel Id where the Button will be added: ", panelId);
            acedGetString(1, L"Enter the Button Text to be added: ", itemText);
            
            pPanel = pRibbonControl->findPanel(panelId, false);
            if (pPanel && pPanel->source())
            {
                pButton = new AcRibbonButton();
                pButton->setButtonStyle(AcRibbonUtils::RibbonButtonStyle::eLargeWithHorizontalText);
                pButton->setText(itemText);
#if __BRXTARGET < 21
                pButton->setImagePath(L"rectang", false);
#else
                pButton->setImagePath(L"rectang");
#endif
                pButton->setCommandParameter(L"rectang");
                if (pPanel->source())
                    pPanel->source()->addItem(pButton);
                else
                    acutPrintf(_T("Panel with Id \"%s\" has no Source."), panelId);
            }
            else
                acutPrintf(_T("Panel with Id \"%s\" was not found."), panelId);

            break;

        case 6:
            acedGetString(1, L"Enter the Button Id to be removed (no subitems): ", itemId);
            
            pItem = pRibbonControl->findItem(itemId, false, pPanel, pTab, true);
            if (pItem && pPanel)
                pPanel->source()->removeItem(pItem);
            else
                acutPrintf(_T("Button with Id \"%s\" was not found."), itemId);

            break;
    }
}

bool addRibbonContent()
{
    int action = -1;
    if (acedGetInt(_T("[1] Add ribbon content\n[2] Edit ribbon content\n"), &action) != RTNORM)
        return false;

    if (action == 1)
        loadRibbonContent();
    else if (action == 2)
        editRibbonContent();

    return true;
}

#endif // BRX_APP
