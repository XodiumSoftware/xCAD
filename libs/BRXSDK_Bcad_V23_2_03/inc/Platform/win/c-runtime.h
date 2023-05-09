// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows C RunTime types and functions

#pragma once

#ifndef _BS_CRUNTIME_INCLUDED_
#define _BS_CRUNTIME_INCLUDED_


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ======== Platform independent =========



// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  #define _LEADBYTE       0x8000                  /* multibyte leadbyte */


  // finddata structure
  struct _wfinddata32_t
  {
    unsigned    attrib;
    __time32_t  time_create;
    __time32_t  time_access;
    __time32_t  time_write;
    _fsize_t    size;
    wchar_t     name[MAX_FNAME];
  };


  // Math functions
  template<class Type>
  const Type&  min (const Type& _Left, const Type& _Right)
  {
      return (((_Left) < (_Right)) ? (_Left) : (_Right));
  };
  template<class Type>
  const Type&  max (const Type& _Left, const Type& _Right)
  {
      return (((_Left) > (_Right)) ? (_Left) : (_Right));
  };

  #define _fpclass(x) fpclassify(x)
  #define _FPCLASS_SNAN  FP_NAN
  #define _FPCLASS_QNAN  FP_NAN
  #define _FPCLASS_NINF  FP_INFINITE
  #define _FPCLASS_ND    FP_SUBNORMAL
  #define _FPCLASS_PD    FP_SUBNORMAL
  #define _FPCLASS_PINF  FP_INFINITE


  inline errno_t wcscpy_s (wchar_t * dest, size_t nchar, const wchar_t * src)
  {
     if (!dest || !src) return EINVAL;
     if (!nchar) return ERANGE;
     wcsncpy(dest, src, nchar);
     return 0;
  }

  // replacement code for the non-implemented "getumask()" function
  inline mode_t _getumask()
  {
     mode_t mask = umask(0);
     umask(mask);
     return mask;
  }


  inline int isleadbyte (int ch)
  {
     return (((unsigned char)ch) & _LEADBYTE);
  }

  // missing UNICODE string functions

  // we assume, that the target string is >= 24 characters; 22 is enough for 64bit int + sign
  inline wchar_t* _ltow (long number, wchar_t *wstr, int radix)
  {
     // radix is ignored, used as '10' always
     int len = swprintf(wstr, 24, L"%ld", number);
     if (len >= 0) wstr[len] = _T('\0');
     return wstr;
  }

  inline errno_t _ltow_s (long number, wchar_t *wstr, size_t sizeOfstr, int radix)
  {
     memset(wstr, 0, sizeOfstr * sizeof(TCHAR));
     int len = swprintf(wstr, sizeOfstr, L"%ld", number);
     if ((len >= 0) && (len < (int)sizeOfstr)) wstr[len] = _T('\0');
     return 0;
  }

  // we assume, that the target string is >= 24 characters; 22 is enough for 64bit int + sign
  inline wchar_t* _itow (int number, wchar_t *wstr, int radix)
  {
     return _ltow((long)number, wstr, radix);
  }

  inline int _wtoi (const wchar_t* str)
  {
     return (int)wcstol(str, NULL, 10);
  }

  inline long _wtol (const wchar_t* str)
  {
     return wcstol(str, NULL, 10);
  }

  inline double _wtof (const wchar_t* str)
  {
     return wcstod(str, NULL);
  }

  inline wchar_t* _wcsinc (const wchar_t* str)
  {
     return (str == NULL) ? NULL : const_cast<wchar_t*>(++str);
  }

  inline wchar_t* _wcsninc (const wchar_t* str, size_t count)
  {
     return (str == NULL) ? NULL : const_cast<wchar_t*>(str + (count * sizeof(wchar_t*)));
  }

  inline wchar_t* _wcsdec (const wchar_t* str)
  {
     if (str == NULL) return NULL;
     wchar_t* ret = const_cast<wchar_t*>(--str);
     return (ret >= str) ? ret : const_cast<wchar_t*>(str);
  }

  inline wchar_t* _wcsndec (const wchar_t* str, size_t count)
  {
     if (str == NULL) return NULL;
     wchar_t* ret = const_cast<wchar_t*>(str - (count * sizeof(wchar_t*)));
     return (ret >= str) ? ret : const_cast<wchar_t*>(str);
  }

  inline wchar_t* _wcsset (wchar_t *str, wchar_t ch)
  {
     if (str == NULL)
         return NULL;

     wchar_t* orgstr = str;
     while (*str)
     {
       *str = ch;
        ++str;
     }
     return orgstr;
  }

  inline wchar_t* _wcsnset (wchar_t *str, wchar_t ch, size_t count)
  {
     if (str == NULL)
         return NULL;

     size_t   ctr = 0;
     wchar_t* orgstr = str;
     while (*str && (ctr < count))
     {
       *str = ch;
        ++str;
        ++ctr;
     }
     return orgstr;
  }

  inline wchar_t* _wcslwr (wchar_t* str)
  {
     if (str == NULL)
         return NULL;

     wchar_t* orgstr = str;
     while (*str)
     {
       *str = towlower(*str);
        ++str;
     }
     return orgstr;
  }

  inline wchar_t* _wcsupr (wchar_t* str)
  {
     if (str == NULL)
         return NULL;

     wchar_t* orgstr = str;
     while (*str)
     {
       *str = towupper(*str);
        ++str;
     }
     return orgstr;
  }

  inline wchar_t* _wcsspnp (const wchar_t* string1, const wchar_t* string2)
  {
     if (!string1 || !string2)
        return (wchar_t*)string1;

     wchar_t* str = (wchar_t*)string1;
     while (*str)
     {
        if (!wcschr(string2, *str))
           return str;
        ++str;
     }
     return NULL;
  }

  // missing ANSI string functions

  inline char* strupr (char* str)
  {
     if (str == NULL)
         return NULL;

     char* orgstr = str;
     while (*str)
     {
        *str = toupper(*str);
         ++str;
     }
     return orgstr;
  }

  // missing UNICODE file related functions

  inline wchar_t* wcserror(int errnum)
  {
      static char _ansiMessage[16384];
      strcpy(_ansiMessage, strerror(errnum));

      static wchar_t _wideMessage[16384];
      CWideString msg(_ansiMessage);
      return _tcscpy(_wideMessage, msg);
  }

  inline int _wstat (const wchar_t *path, struct stat *buffer)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      return stat(pathName, buffer);
  }

  inline int _waccess (const wchar_t* path, int mode)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      int flag = F_OK;
      if (mode == 2) flag = W_OK;
      else
      if (mode == 4) flag = R_OK;
      else
      if (mode == 6) flag = W_OK | R_OK;
      return access(pathName, flag);
  }

  inline FILE * _wfopen (const wchar_t* path, const wchar_t* mode)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      return fopen(pathName, T2ANSI(mode));
  }

  inline int _wopen (const wchar_t *path, int oflag, int pmode = _getumask())
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      return open(pathName, oflag, pmode);
  }

  inline FILE * _wfsopen (const wchar_t* filename, const wchar_t* mode, int shflag)
  {
      CAnsiString pathName(filename);
      adjustSlashes(pathName);
      pathName.expand();
      FILE * filehandle = fopen(pathName, T2ANSI(mode));
      if (!filehandle) return NULL;

      int fd = fileno(filehandle);
      if (shflag == _SH_DENYNO)
      {
          int lockStat = lockf(fd, F_ULOCK, 0);
          if (lockStat == -1)
          {
          }
      }
      else
      {
          if ((shflag == _SH_DENYRD) || (shflag == _SH_DENYRW) || (shflag == _SH_DENYWR))
          {
              int lockStat = lockf(fd, F_TLOCK, 0);
              if (lockStat == -1)
                  fclose(filehandle);
              filehandle = NULL;
          }
      }
      return filehandle;
  }

  inline int _wsopen (const wchar_t *filename, int oflag, int shflag, int pmode = _getumask())
  {
      CAnsiString pathName(filename);
      adjustSlashes(pathName);
      pathName.expand();
      int fd = open(pathName, oflag, pmode);
      if (fd == -1) return -1;

      if (shflag == _SH_DENYNO)
      {
          int lockStat = lockf(fd, F_ULOCK, 0);
          if (lockStat == -1)
          {
          }
      }
      else
      {
          if ((shflag == _SH_DENYRD) || (shflag == _SH_DENYRW) || (shflag == _SH_DENYWR))
          {
              int lockStat = lockf(fd, F_TLOCK, 0);
              if (lockStat == -1)
              {
                  close(fd);
                  fd = -1;
              }
          }
      }
      return fd;
  }

  inline int _wrename (const wchar_t *oldname, const wchar_t *newname)
  {
      CAnsiString oldName(oldname);
      CAnsiString newName(newname);
      adjustSlashes(oldName);
      adjustSlashes(newName);
      oldName.expand();
      newName.expand();
      int res = rename(oldName, newName);
      return res;
  }

  inline int _wremove (const wchar_t * path)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      int res = remove(pathName);
      return res;
  }

  inline int _wrmdir (const wchar_t *path)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      int res = rmdir(pathName);
      return res;
  }

  inline int _wmkdir (const wchar_t *path)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      return mkdir(pathName, S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
  }

  inline wchar_t* _wgetcwd (wchar_t *buffer, int maxlen)
  {
     char  mbpath[_MAX_FNAME];
     if (!getcwd(mbpath, _MAX_FNAME))
        return NULL;

     if (!buffer)
     {
        buffer = (wchar_t*)malloc( (maxlen+1) * sizeof(wchar_t) );
     }
     return _tcscpy(buffer, ANSI2T(mbpath));
  }

  inline int _wchdir (const wchar_t* path)
  {
      CAnsiString pathName(path);
      adjustSlashes(pathName);
      pathName.expand();
      return chdir(pathName);
  }

  inline wchar_t* _wfullpath (wchar_t *absPath, const wchar_t *relPath, size_t maxLength)
  {
     TCHAR curDir[_MAX_PATH+1];
     _tgetcwd(curDir, _MAX_PATH);

     int len = swprintf(absPath, maxLength, L"%ls/%ls", curDir, relPath);
     if (len >= 0) absPath[len] = _T('\0');
     return absPath;
  }

  inline wchar_t * _wtmpnam (wchar_t * tmpfile)
  {
     if (!tmpfile) return NULL;
     char tmp[_MAX_FNAME+1] = "XXXXXX";
     int tempfd = mkstemp(tmp);
     if (tempfd == -1) return NULL;
     close(tempfd);
     return _tcscpy(tmpfile, ANSI2T(tmp));
  }

  inline wchar_t * _wtempnam (const wchar_t * dir, const wchar_t * prefix)
  {
     // dir is ignored
     char tmp[_MAX_FNAME+1] = "";
     if (prefix) strcat(tmp, T2ANSI(prefix));
     strcat(tmp, "XXXXXX");
     int tempfd = mkstemp(tmp);
     if (tempfd == -1) return NULL;
     close(tempfd);
     return _tcsdup(ANSI2T(tmp));
  }

  inline int _wputenv (const wchar_t* var)
  {
     return (putenv((char*)static_cast<const char*>(T2ANSI(var))) == 0) ? 0 : -1;
  }

  inline errno_t localtime_s (struct tm* _tmlocal, const time_t* timer)
  {
      if (!_tmlocal || !timer)
          return EINVAL;
      struct tm * localtm = localtime(timer);
      if (!localtm)
          return EINVAL;
     _tmlocal->tm_isdst = localtm->tm_isdst;
     _tmlocal->tm_yday  = localtm->tm_yday;
     _tmlocal->tm_wday  = localtm->tm_wday;
     _tmlocal->tm_year  = localtm->tm_year;
     _tmlocal->tm_mon   = localtm->tm_mon;
     _tmlocal->tm_mday  = localtm->tm_mday;
     _tmlocal->tm_hour  = localtm->tm_hour;
     _tmlocal->tm_min   = localtm->tm_min;
     _tmlocal->tm_sec   = localtm->tm_sec;
     return 0;
  }

  inline errno_t gmtime_s (struct tm* _tmgreenwich, const time_t* timer)
  {
      if (!_tmgreenwich || !timer)
          return EINVAL;
     struct tm * greemwtm = gmtime(timer);
      if (!greemwtm)
          return EINVAL;
     _tmgreenwich->tm_isdst = greemwtm->tm_isdst;
     _tmgreenwich->tm_yday  = greemwtm->tm_yday;
     _tmgreenwich->tm_wday  = greemwtm->tm_wday;
     _tmgreenwich->tm_year  = greemwtm->tm_year;
     _tmgreenwich->tm_mon   = greemwtm->tm_mon;
     _tmgreenwich->tm_mday  = greemwtm->tm_mday;
     _tmgreenwich->tm_hour  = greemwtm->tm_hour;
     _tmgreenwich->tm_min   = greemwtm->tm_min;
     _tmgreenwich->tm_sec   = greemwtm->tm_sec;
     return 0;
  }

  inline wchar_t* _wctime (const time_t *timep)
  {
      static TCHAR strTime[64];
      return _tcscpy(strTime, ANSI2T(ctime(timep)));
  }


  BRXEXPORT wchar_t * _wgetenv (const wchar_t * envvar);

  BRXEXPORT int  _wunlink    (const wchar_t * filename);
  BRXEXPORT int  _wchmod     (const wchar_t * filename, int pmode);
  BRXEXPORT void _wsearchenv (const wchar_t * infile, const wchar_t * varname, wchar_t * retfile);
  BRXEXPORT void _wsplitpath (const wchar_t * _FullPath, wchar_t * _Drive, wchar_t * _Dir,
                              wchar_t * _Filename, wchar_t * _Ext);
  BRXEXPORT wchar_t* _wcsrev (wchar_t* pszStr);
  BRXEXPORT int aswprintf    (wchar_t **strp, const wchar_t* fmt, ...);
  BRXEXPORT int vaswprintf   (wchar_t **strp, const wchar_t* fmt, va_list ap);

  BRXEXPORT intptr_t _wfindfirst  (const wchar_t * filespec, struct _wfinddata_t * fileinfo);
  BRXEXPORT int      _wfindnext   (intptr_t handle, struct _wfinddata_t * fileinfo);
  BRXEXPORT int      _findclose   (intptr_t handle);

#endif // !_WIN32


#endif // _BS_CRUNTIME_INCLUDED_
