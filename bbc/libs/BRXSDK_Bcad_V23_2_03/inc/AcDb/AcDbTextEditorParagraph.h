// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbTextEditorSelectable.h"

class AcDbImpTextEditorParagraph;
class AcDbTextEditorLocation;
class AcDbTextEditorParagraphTab;

/** _ */
class BRX_IMPORTEXPORT AcDbTextEditorParagraph : public AcDbTextEditorSelectable
{
public:
    enum AlignmentType
    {
        kAlignmentDefault = 0,
        kAlignmentLeft = 1,
        kAlignmentCenter = 2,
        kAlignmentRight = 3,
        kAlignmentJustify = 4,
        kAlignmentDistribute = 5
    };

    enum LineSpacingStyle
    {
        kLineSpacingDefault = 0,
        kLineSpacingExactly = 1,
        kLineSpacingAtLeast = 2,
        kLineSpacingMultiple = 3
    };

    enum NumberingType
    {
        kOff = 0,
        kBullet = 1,
        kNumber = 2,
        kLetterLower = 3,
        kLetterUpper = 4,
        kNumberWide = 5,
        kLetterLowerWide = 6,
        kLetterUpperWide = 7
    };

private:
    AcDbTextEditorParagraph();
    ~AcDbTextEditorParagraph();

public:
    AcDbTextEditorLocation* startOfText() override;
    AcDbTextEditorLocation* endOfText() override;

    Acad::ErrorStatus addTab(const AcDbTextEditorParagraphTab&);
    AlignmentType alignment() const;
    Acad::ErrorStatus continueNumbering();
    double firstIndent() const;
    Acad::ErrorStatus getTab(int i, AcDbTextEditorParagraphTab&);
    double leftIndent() const;
    double lineSpacingFactor() const;
    LineSpacingStyle lineSpacingStyle() const;
    double maxLineSpacingFactor() const;
    double maxSpaceValue() const;
    double minLineSpacingFactor() const;
    double minSpaceValue() const;
    NumberingType numberingType() const;
    void release();
    Acad::ErrorStatus removeTab(const AcDbTextEditorParagraphTab&);
    Acad::ErrorStatus restartNumbering();
    double rightIndent() const;
    Acad::ErrorStatus setAlignment(AlignmentType);
    Acad::ErrorStatus setFirstIndent(double);
    Acad::ErrorStatus setLeftIndent(double);
    Acad::ErrorStatus setLineSpacingFactor(double);
    Acad::ErrorStatus setLineSpacingStyle(LineSpacingStyle);
    Acad::ErrorStatus setNumberingType(NumberingType);
    Acad::ErrorStatus setRightIndent(double);
    Acad::ErrorStatus setSpaceAfter(double);
    Acad::ErrorStatus setSpaceBefore(double);
    double spaceAfter() const;
    double spaceBefore() const;
    int tabsCount() const;

private:
    AcDbImpTextEditorParagraph* m_pImp;

private:
    AcDbTextEditorParagraph(const AcDbTextEditorParagraph&);
    AcDbTextEditorParagraph& operator=(const AcDbTextEditorParagraph&);
};
