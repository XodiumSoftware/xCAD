// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbTextEditor.h"
#include "AcDb/AcDbTextEditorParagraph.h"

class AcEdInplaceTextEditorImp;
class IAcEdInplaceTextEditorHost;
class AcEdInplaceTextEditorSettings;
class IPE_Editor;

/** _ */
class BRX_IMPORTEXPORT AcEdInplaceTextEditor : public AcDbTextEditor
{
public:
    enum TextUndoType
    {
        kUndoTyping = 1,
        kUndoBoldOn = 2,
        kUndoBoldOff = 3,
        kUndoItalicOn = 4,
        kUndoItalicOff = 5,
        kUndoUnderlineOn = 6,
        kUndoUnderlineOff = 7,
        kUndoOverlineOn = 8,
        kUndoOverlineOff = 9,
        kUndoFont = 10,
        kUndoHeight = 11,
        kUndoColor = 12,
        kUndoObliqueAngle = 13,
        kUndoWidthScale = 14,
        kUndoTrackingFactor = 15,
        kUndoLanguage = 16,
        kUndoBackspace = 17,
        kUndoDelete = 18,
        kUndoPaste = 19,
        kUndoCut = 20,
        kUndoStack = 21,
        kUndoUnstack = 22,
        kUndoStackProperties = 23,
        kUndoFieldInsert = 24,
        kUndoFieldConvert = 25,
        kUndoFieldUpdate = 26,
        kUndoSymbolInsert = 27,
        kUndoAutoField = 28,
        kUndoAutoStack = 29,
        kUndoAutoSymbol = 30,
        kUndoAutoDTextEscape = 31,
        kUndoAutoMifOrCif = 32,
        kUndoAutoDimension = 33,
        kUndoAutoDimBreak = 34,
        kUndoAutoSpell = 35,
        kUndoStyle = 36,
        kUndoAttachment = 37,
        kUndoChangeCase = 38,
        kUndoImportText = 39,
        kUndoCombineParagraphs = 40,
        kUndoRemoveCharFormatting = 41,
        kUndoRemoveParaFormatting = 42,
        kUndoRemoveAllFormatting = 43,
        kUndoReplaceAll = 44,
        kUndoReplace = 45,
        kUndoParagraphAttributes = 46,
        kUndoSetDefinedWidth = 47,
        kUndoSetDefinedHeight = 48,
        kUndoCharAttributes = 49,
        kUndoWipeout = 50,
        kUndoDimensionInsert = 51,
        kUndoDimBreakInsert = 52,
        kUndoCustomConvert = 53,
        kUndoDeleteAndMoveSelection = 54,
        kUndoParagraphNumbering = 55,
        kUndoCursorAttributes = 56,
        kUndoColumns = 57,
        kUndoAnnoState = 58,
        kUndoDimensionTweak = 59,
        kUndoDimensionSymbol = 60,
        kUndoDimensionTemplate = 61
    };

protected:
    AcEdInplaceTextEditor();
    ~AcEdInplaceTextEditor();
    AcEdInplaceTextEditor(const AcEdInplaceTextEditor&);
    AcEdInplaceTextEditor& operator=(const AcEdInplaceTextEditor&);

public:
    static AcEdInplaceTextEditor* current();

    static Acad::ErrorStatus invoke(AcDbMText*, const AcEdInplaceTextEditorSettings*);
    static Acad::ErrorStatus invoke(AcDbText*, AcDbObjectIdArray*);

    void setHost(IAcEdInplaceTextEditorHost*);

    void close(ExitStatus stat) override;

    Acad::ErrorStatus addUndoMarker(TextUndoType);
    bool annotative() const;
    Acad::ErrorStatus attachmentMenusInput(AcGePoint2d*, HWND);
    bool canCopy() const;
    bool canCut() const;
    bool canExitInplaceEditor();
    bool canPaste() const;
    bool canRedo() const;
    bool canUndo() const;
    Acad::ErrorStatus columnMenusInput(AcGePoint2d*, HWND);
    Acad::ErrorStatus contextMenusInput(AcGePoint2d*, HWND);
    Acad::ErrorStatus copy();
    Acad::ErrorStatus cut();
    void drawHighlight();
    void enableWysiwyg();
    void findMatchItem(int, const AcString&) const;
    bool forcedOpaqueBackground();
    AcDbTextEditorParagraph::AlignmentType getAlignmentFromAttachment() const;
    void insertFile(const AcString&);
    Acad::ErrorStatus invokeColumnsDialog(int = 0);
    Acad::ErrorStatus invokeFieldDialog(AcDbField* = NULL);
    Acad::ErrorStatus invokeFindReplaceDialog();
    Acad::ErrorStatus invokeHelpDialog();
    Acad::ErrorStatus invokeHightlightColorDialog();
    Acad::ErrorStatus invokeImportTextDialog();
    Acad::ErrorStatus invokeNewFeatureWorkshop();
    Acad::ErrorStatus invokeParagraphDialog();
    Acad::ErrorStatus invokeSpellerDictionaryDialog();
    Acad::ErrorStatus invokeSpellSettingDialog();
    Acad::ErrorStatus invokeStackPropertyDialog();
    Acad::ErrorStatus invokeWipeoutDialog();
    bool isMultiAttribute() const;
    bool isParagraphSupported() const;
    bool isSimpleMtext() const;
    bool isTableCell() const;
    bool isText() const;
    COLORREF layerColor() const;
    Acad::ErrorStatus lineSpaceMenusInput(AcGePoint2d*, HWND);
    Acad::ErrorStatus numberingMenusInput(AcGePoint2d*, HWND);
    bool opaqueBackground();
    void otherSymbol();
    Acad::ErrorStatus paste();
    Acad::ErrorStatus pasteWithoutFormats();
    Acad::ErrorStatus redo();
    void removeHightlight();
    void replaceAllMatchItems(int, const AcString&, const AcString&) const;
    void replaceCurrentMatchItem(int, const AcString&, const AcString&) const;
    bool rulerHidden() const;
    bool rulerSupported() const;
    Acad::ErrorStatus setAnnotative(bool);
    void setCanExitInplaceEditor(bool);
    void setOpaqueBackground(bool);
    void setRulerHidden(bool);
    Acad::ErrorStatus setStaticColumnsWithCount(int);
    Acad::ErrorStatus setTextLayer(const AcString&);
    void setToolbarHidden(bool);
    void setToolbarOptionHidden(bool);
    Acad::ErrorStatus setUndoRecordingDisable(bool);
    bool spellerEnabled() const;
    Acad::ErrorStatus symbolMenusInput(AcGePoint2d*, HWND);
    void toggleSpelling();
    bool toolbarHidden() const;
    bool toolbarOptionHidden() const;
    Acad::ErrorStatus undo();
    bool undoRecordingDisabled();
    bool wysiwyg();

protected:
    friend AcEdInplaceTextEditorImp;
    AcEdInplaceTextEditorImp* m_pEditorImp;
    IPE_Editor* m_pIPEEditorImp;
};
