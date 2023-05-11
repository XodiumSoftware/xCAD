// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"
#include "Misc/MiscGlobal.h"

#include "MFC/CAdUi/CAdUiPathEnums.h"

enum FS_TYPE
{
    NOFS = 0,
    UKFS,
    NTFS,
    FAT,
    VFAT,
    HPFS,
    CDFS,
    HFS,
    UFS
};

const ACHAR kAsterisk = _T('*');
const ACHAR kBackslash = _T('\\');
const ACHAR kColon = _T(':');
const ACHAR kDoubleQuote= _T('"');
const ACHAR kEOS = _T('\0');
const ACHAR kPeriod = _T('.');
const ACHAR kQuestionmark = _T('?');
const ACHAR kSlash = _T('/');
const ACHAR kSpace = _T(' ');
const ACHAR kZero = _T('0');

/** _ */
class CAdUiVolumeDescriptor
{
    friend class CAdUiPathname;
public:
    BOOL IsRemote() const;
    BOOL IsRemovable() const;
    CAdUiVolumeDescriptor();
    CAdUiVolumeDescriptor(const CString&);
    virtual BOOL AllowsCaseSensitiveLookup() const;
    virtual BOOL CheckReadOnly() const;
    virtual BOOL IsCaseSensitive() const;
    virtual BOOL PreservesCase() const;
    virtual BOOL ValidateFilename(const CString*,const BOOL = FALSE) const = 0;
    virtual BOOL ValidateSegment(const CString*,const BOOL = FALSE) const = 0;
    virtual BOOL VolMatch(const ACHAR*,const CString*) const;
    virtual BOOL VolMatch(const CString*,const CString*) const;
    virtual BOOL VolumeValid() const;
    virtual BOOL WillFit(DWORD) const;
    virtual const CString* GetLocalName() const;
    virtual LONG GetVolFreeSpace() const;
    virtual void VolCase(CString&) const;
    virtual ~CAdUiVolumeDescriptor();

#ifdef _DEBUG
    virtual void debug_dump(FILE*) const;
#endif
protected:
    typedef unsigned flagbits;

    ACHAR m_vol_slash;
    BOOL m_amodeMultiByte;
    const ACHAR* m_doubleslash;
    CString* m_connection_name;
    CString* m_vol_label;
    CString* m_vol_localname;
    DWORD m_fsflags;
    DWORD m_vol_serial;
    flagbits m_d_caseSensitive;
    flagbits m_d_cdrom;
    flagbits m_d_fixed;
    flagbits m_d_ramdisk;
    flagbits m_d_readonly;
    flagbits m_d_remote;
    flagbits m_d_removable;
    FS_TYPE m_vol_fs_type;
    int Find(const CString&,UINT) const;
    int IsControl(int) const;
    int m_max_component_size;
    int m_max_path_length;
    void GetConnectionName();
};
