#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbTable.h"

class BRX_IMPORTEXPORT AcDbTableIterator
{
protected:
    friend class AcDbLinkedTableData;
    friend class AcDbTable;

    AcDbTableIterator();
    void* m_pBrxImp;

public:
    AcDbTableIterator(const AcDbTable*);
    AcDbTableIterator(const AcDbTable*, const AcCellRange*, AcDb::TableIteratorOption);
    AcDbTableIterator(const AcDbLinkedTableData*);
    AcDbTableIterator(const AcDbLinkedTableData*, const AcCellRange*, AcDb::TableIteratorOption);
    AcDbTableIterator(const AcCellRange&);
    AcDbTableIterator(const AcCellRange&, AcDb::TableIteratorOption);
    ~AcDbTableIterator();

    bool done();
    AcCell getCell() const;
    int getColumn() const;
    int getRow() const;
    bool seek(const AcCell&);
    void start();
    void step();
};
