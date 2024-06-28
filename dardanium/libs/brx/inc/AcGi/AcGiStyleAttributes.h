// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcGiLineAttributes;

/** _ */
class BRX_IMPORTEXPORT AcGiStyleAttributes
{
public:
    enum AttributeFlags
    {
        kNothing = 0,
        kColor = 1,
        kLine = 2,
        kLineType = 4,
        kPlotStyle = 8,
        kEverything = (kColor|kLine|kLineType|kPlotStyle)
    };

    AcGiStyleAttributes();
    virtual ~AcGiStyleAttributes();
    AcGiStyleAttributes(const AcGiStyleAttributes&);

    virtual void EnsureColorVisibility(AcCmEntityColor&) = 0;
    AcCmEntityColor& getColorAttribute();
    const AcCmEntityColor& getColorAttribute() const;
    virtual AcGiLineAttributes* getLineAttribute() = 0;
    virtual const AcGiLineAttributes* getLineAttribute() const = 0;
    AcDbObjectId linetypeObjectId() const;
    AcDbObjectId plotStyleNameId() const;
    void setColorAttribute(const AcCmEntityColor&);
    virtual void setLineAttribute(const AcGiLineAttributes*) = 0;
    void setLinetypeObjectId(const AcDbObjectId&);
    void setPlotStyleName(const AcDbObjectId&);

protected:
    AcDbObjectId m_idLinetype;
    AcDbObjectId m_idPlotstyle;
    AcCmEntityColor m_colorAttribute;
};
