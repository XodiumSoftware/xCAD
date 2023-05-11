// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbTextEditorSelectable.h"
#include "AcDb/AcDbTextEditorSelectionBase.h"
#include "AcDb/AcDbMText.h"

class AcDbTextEditorColumns;
class AcDbTextEditorWipeout;
class AcDbTextEditorSelection;
class AcDbTextEditorCursor;
class AcDbTextEditorLocation;
class AcDbTextEditorParagraphIterator;
class TextEditor;

/** _ */
class BRX_IMPORTEXPORT AcDbTextEditor : public AcDbTextEditorSelectable
{
public:
    enum TextFindFlags
    {
        kFindMatchCase = 0x1,
        kFindWholeWord = 0x2,
        kFindHalfFullForm = 0x4,
        kFindIgnoreAccent = 0x8,
        kFindUseWildcards = 0x10
    };

    enum ExitStatus
    {
        kExitQuit = 0,
        kExitSave = 1
    };

private:
    AcDbTextEditor(const AcDbTextEditor&);
    AcDbTextEditor& operator=(const AcDbTextEditor&);

protected:
    AcDbTextEditor();

public:
    ~AcDbTextEditor();

    static AcDbTextEditor* createDbTextEditor(AcDbMText*);

    virtual void close(ExitStatus);
    virtual AcDbTextEditorSelection* selection();
    virtual AcDbTextEditorCursor* cursor();

    double actualHeight() const;
    double actualWidth() const;
    AcDbMText::AttachmentPoint attachment() const;
    bool autoCAPS();
    bool autolistEnabled() const;
    Acad::ErrorStatus clearSelection();
    AcDbTextEditorColumns* columns();
    int currentStyleIndex() const;
    AcDbTextEditorSelectionBase::FlowAlign defaultStackAlignment() const;
    double defaultStackScale() const;
    double definedHeight() const;
    double definedWidth() const;
    AcDbTextEditorLocation* endOfText() override;
    Acad::ErrorStatus findText(const ACHAR*, int, AcDbTextEditorLocation*&, AcDbTextEditorLocation*&);
    AcString getFontName(int) const;
    int getFontCount() const;
    int getIndexFromStyleName(const AcString&);
    int getStyleCount() const;
    AcString getStyleName(int) const;
    bool isAnnotativeStyle(int) const;
    bool isTrueTypeFont(int) const;
    bool isVerticalSHX() const;
    bool isVerticalTTF() const;
    Acad::ErrorStatus makeSelection(const AcDbTextEditorLocation*, const AcDbTextEditorLocation*);
    AcDbTextEditorParagraphIterator* newParagraphsIterator();
    bool numberingEnabled() const;
    void redraw();
    Acad::ErrorStatus selectAll();
    Acad::ErrorStatus setAttachment(AcDbMText::AttachmentPoint);
    Acad::ErrorStatus setAutoCAPS(bool);
    Acad::ErrorStatus setAutolistEnabled(bool);
    Acad::ErrorStatus setDefaultStackAlignment(AcDbTextEditorSelectionBase::FlowAlign);
    Acad::ErrorStatus setDefaultStackScale(double);
    Acad::ErrorStatus setDefinedHeight(double);
    Acad::ErrorStatus setDefinedWidth(double);
    Acad::ErrorStatus setEnableNumbering(bool);
    Acad::ErrorStatus setStyle(AcDbObjectId);
    Acad::ErrorStatus setStyle(int);
    Acad::ErrorStatus setTabOnlyDelimiter(bool);
    Acad::ErrorStatus setTextHeight(double);
    int stackCount() const;
    AcDbTextEditorLocation* startOfText() override;
    AcDbObjectId style(int) const;
    bool tabOnlyDelimiter() const;
    double textHeight() const;
    AcDbTextEditorWipeout* wipeout();

protected:
    TextEditor* m_pImp;
};
