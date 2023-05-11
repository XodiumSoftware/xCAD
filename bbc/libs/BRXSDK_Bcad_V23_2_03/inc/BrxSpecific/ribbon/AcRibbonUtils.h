// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

/**
*@namespace AcRibbonUtils
*@brief Commonly used enumerations and structures by the Ribbon API.
*/

namespace AcRibbonUtils
{
    /*! Used by Ribbon API for showing a status code for when working with controls. */
    enum AcResult
    {
        eRbnNullPtr,
        eRbnTabAlreadyAdded,
        eRbnPanelAlreadyAdded,
        eRbnItemAlreadyAdded,
        eRbnNoParent,
        eRbnOk,
        eRbnCreateFailed,
        eRbnTabNotFound,
        eRbnPanelNotFound,
        eRbnItemNotFound,
        eRbnWrongItemType,
        eRbnEmptyCollection
    };

    /*! All types of controls used in Ribbon API. */
    enum RibbonToolType
    {
        eRibbonUnspecified = -1,
        eRibbonBar,
        eRibbonTab,
        eRibbonPanel,
        eRibbonSeparator,
        eRibbonItem,
        eRibbonButton,
        eRibbonItemCtrl,
        eRibbonButtonCtrl,
        eRibbonCommandButton,
        eRibbonToggleButton,
        eRibbonControl,
        eRibbonRowPanel,
        eRibbonRowBreak,
        eRibbonSplitButton,
        eRibbonCombo,
        eRibbonTextBox,
        eRibbonPanelBreak
    };

    /*! Control properties used for sending reactor notifications. */
    enum RibbonProperty
    {
        eUnknownProperty = -1,
        eLabelProperty,
        eNameProperty,
        eIdProperty,
        eTextProperty,
        eToolTipProperty,
        eComboDropDownVisibilityProperty,
        eSelectionProperty, 
        eCheckStateProperty
    };

    /*! Used by Ribbon Items for displaying/hiding text and for choosing image size. */
    enum RibbonButtonStyle
    {
        eLargeWithText,
        eLargeWithHorizontalText,
        eSmallWithText,
        eSmallWithoutText,
        eLargeWithoutText,
        eNoStyle
    };

    /*! Used by AcRibbonSplitButton. */
    enum RibbonSplitButtonBehavior
    {
        eDropDownFollow = 1,    /*!< Split button acts as a drop-down list and display the most recent selection. */
        eDropDownNoFollow,      /*!< Split button acts as a drop-down list and display the first item from the list. */
        eSplitFollow,           /*!< Split button acts as a button and a drop-down list and display the most recent selection. */
        eSplitNoFollow,         /*!< Split button acts as a button and a drop-down list and display the first item from the list. */
        eSplitFollowStaticText  /*!< Same as <i>eSplitFollow</i> except that split button text doesn't change. */
                    
    };

    /*! Used by AcRibbonSeparator. */
    enum RibbonSeparatorStyle { eLine = 1, eSpacer };

    /*! Used by AcRibbonReactor as parameters. */
    template <typename Type>
    struct RibbonPropertyEventArgs
    {
        RibbonPropertyEventArgs(const Type& newVal = Type(),
                                const Type& oldVal = Type(),
                                RibbonProperty propType = eUnknownProperty)
        : m_newValue(newVal), m_oldValue(oldVal), m_propType(propType)
        {}

        Type oldValue() const { return m_oldValue; }
        Type newValue() const { return m_newValue; }
        RibbonProperty property() const { return m_propType; }
        void set( const Type& newVal,
                  const Type& oldVal,
                  RibbonProperty propType)
        {
            m_newValue = newVal;
            m_oldValue = oldVal;
            m_propType = propType;
        }

    private:
        RibbonProperty m_propType;
        Type m_oldValue;
        Type m_newValue;
    };
};
