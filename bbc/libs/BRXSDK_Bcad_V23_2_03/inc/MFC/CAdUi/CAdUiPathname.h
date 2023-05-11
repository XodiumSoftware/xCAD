// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiCDFSVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiFATVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiHPFSVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiNOFSVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiNTFSVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiUFSVolumeDescriptor.h"
#include "MFC/CAdUi/CAdUiVFATVolumeDescriptor.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiPathname
{
public:
    virtual ~CAdUiPathname();
    virtual PathErr Parse(LPCTSTR,const BOOL = FALSE);

    BOOL Exists();
    BOOL GetFullPath(CString&) const;
    BOOL GetFullPath(LPTSTR) const;
    BOOL GetUniqueName(CAdUiPathname&,BOOL = FALSE) const;
    BOOL HadPrefix() const;
    BOOL IsEmpty() const;
    BOOL IsPath() const;
    BOOL Open(CFile&,UINT);
    BOOL Open(FILE**,const ACHAR*);
    BOOL OpenReadOnly(HANDLE&);
    BOOL OpenWriteOnly(HANDLE&);
    BOOL ParseAndOSFind(LPCTSTR);
    BOOL PathMatch(const CAdUiPathname*) const;
    BOOL PathMatch(LPCTSTR) const;
    BOOL Remove();
    BOOL Rename(const ACHAR*);
    BOOL VerifyExtension(LPCTSTR) const;
    BOOL WasAbsolute() const;
    BOOL WasRoot() const;
    CAdUiPathname();
    CAdUiPathname(const CAdUiPathname&);
    const CAdUiPathname& operator=(const CAdUiPathname&);
    const CAdUiPathname& operator=(const CAdUiPathname*);
    const CAdUiVolumeDescriptor* GetVolumeDescriptor() const;
    LPCTSTR GetPathString() const;
    PathErr AddExtensionAlways(LPCTSTR);
    PathErr AddExtensionIfNoMatch(LPCTSTR);
    PathErr Append(LPCTSTR);
    PathErr AppendComponent(LPCTSTR);
    PathErr AppendSlash();
    PathErr ParseRelative(LPCTSTR,const CAdUiPathname*,const BOOL = FALSE);
    PathErr ReplaceExtensionAlways(LPCTSTR);
    PathErr ReplaceExtensionIfNoMatch(LPCTSTR);
    PathErr Trim();
    PathErr TrimComponent();
    PathErr TrimSlash();
    path_type GetPathType() const;
    void BaseToLower();
    void BaseToUpper();
    void Empty();
    void GetBasename(CString&) const;
    void GetDisplayName(CString&,int) const;
    void GetExtension(CString&) const;
    void GetFilename(CString&) const;
    void GetFullUNCPath(CString&) const;
    void GetParent(CAdUiPathname&) const;
    void RemoveExtensionAlways();
    void RemoveExtensionIfMatch(LPCTSTR);
    void RemoveSpaces();
protected:
    ACHAR GetSeparator() const;
    ACHAR m_separator;
    BOOL IsDeviceName(const CString&) const;
    BOOL m_had_prefix;
    const CAdUiVolumeDescriptor* FindVolumeDescriptor(const CString&) const;
    const CAdUiVolumeDescriptor* m_pvolume;
    const CAdUiVolumeDescriptor* NewVolDescriptor(const CString&) const;
    CString* m_pathbuffer;
    CString* m_relpath;
    FS_TYPE GetFileSystem(CString&) const;
    path_category m_path_cat;
    path_type m_this_type;
    static ACHAR GetLastCharacter(const CString&);
    static void Unquote(CString&);
    virtual void AssignCopy(const CAdUiPathname&);
};
