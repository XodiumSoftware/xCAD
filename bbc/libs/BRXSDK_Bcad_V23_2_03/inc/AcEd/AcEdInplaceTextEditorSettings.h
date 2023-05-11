// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcEdInplaceTextEditorSettingsImp;

/** _ */
class BRX_IMPORTEXPORT AcEdInplaceTextEditorSettings
{
public:
    enum EntityType
    {
        kDefault = 0,
        kTableCell = 1,
        kMultiAttribute = 2
    };

    enum EditFlags
    {
        kForceOpaqueBackground = 0x1,
        kSelectAll = 0x2,
        kCursorAtEnd = 0x4
    };

public:
    AcEdInplaceTextEditorSettings();
    ~AcEdInplaceTextEditorSettings();

private:
    AcEdInplaceTextEditorSettings(const AcEdInplaceTextEditorSettings& editor);
    AcEdInplaceTextEditorSettings& operator=(const AcEdInplaceTextEditorSettings& editor);

public:
    int editFlags() const;
    Acad::ErrorStatus setEditFlags(int flags);

    EntityType sourceEntityType() const;
    Acad::ErrorStatus setSourceEntityType(EntityType type);

    bool tabSupported() const;
    Acad::ErrorStatus setSupportTab(bool bTab);

    bool simpleMText() const;
    Acad::ErrorStatus setSimpleMText(bool bSimpleMText);

    double definedHeight() const;
    Acad::ErrorStatus setDefinedHeight(double height);

protected:
    AcEdInplaceTextEditorSettingsImp* m_pImp;
};
