// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbImpTextEditorSelectionBase;

/** _ */
class BRX_IMPORTEXPORT AcDbTextEditorSelectionBase
{
public:
    enum FlowAlign
    {
        kFlowBase = 0,
        kFlowCenter = 1,
        kFlowTop = 2
    };

    enum InsertTextType
    {
        kUnicodeMTextFormat = 0,
        kMTextFormat = 1,
        kRichTextFormat = 2,
        kUnicodeDTextFormat = 3,
        kDTextFormat = 4,
        kUnicodeTextFormat = 5,
        kMultibyteTextFormat = 6
    };

protected:
    AcDbTextEditorSelectionBase();
    virtual ~AcDbTextEditorSelectionBase();
    AcDbTextEditorSelectionBase(const AcDbTextEditorSelectionBase&);
    AcDbTextEditorSelectionBase& operator=(const AcDbTextEditorSelectionBase&);

public:
    static double maxObliqueAngle();
    static double minObliqueAngle();
    static double maxTrackingFactor();
    static double minTrackingFactor();
    static double maxWidthScale();
    static double minWidthScale();

    bool bold() const;
    AcCmColor color() const;
    FlowAlign flowAlign() const;
    AcString font() const;
    double height() const;
    Acad::ErrorStatus inputSpecialChar(Adesk::UInt32);
    Acad::ErrorStatus insertColumnBreak();
    Acad::ErrorStatus insertImportedText(InsertTextType, void*);
    Acad::ErrorStatus insertString(const AcString&);
    Acad::ErrorStatus insertSymbol(ACHAR, Charset);
    bool isTrueType() const;
    bool italic() const;
    Charset language() const;
    double obliqueAngle() const;
    bool overline() const;
    Acad::ErrorStatus setColor(const AcCmColor&);
    Acad::ErrorStatus setFlowAlign(FlowAlign);
    Acad::ErrorStatus setFont(const AcString&, bool);
    Acad::ErrorStatus setHeight(double);
    Acad::ErrorStatus setLanguage(Charset);
    Acad::ErrorStatus setObliqueAngle(double);
    Acad::ErrorStatus setTrackingFactor(double);
    Acad::ErrorStatus setWidthScale(double);
    bool strikethrough() const;
    Acad::ErrorStatus toggleBold();
    Acad::ErrorStatus toggleItalic();
    Acad::ErrorStatus toggleOverline();
    Acad::ErrorStatus toggleStrikethrough();
    Acad::ErrorStatus toggleUnderline();
    double trackingFactor() const;
    bool underline() const;
    double widthScale() const;

protected:
    AcDbImpTextEditorSelectionBase* m_pImp;
};
