// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef __WXMSW__

class WxUserInteraction
{
    HWND m_activeWindow;
    std::vector<HWND> m_wnds;
public:
    WxUserInteraction();
    WxUserInteraction(AcApDocument* pDocument,bool prompting);
    virtual ~WxUserInteraction(void);
  protected:
    void userInteraction(AcApDocument* pDocument,bool prompting);
    void undoUserInteraction();
};

#else

class WxUserInteraction
{
  wxWindow *m_activeWindow;
  std::vector<wxWindow*> m_wnds;
public:
  WxUserInteraction();
  WxUserInteraction(AcApDocument* pDocument,bool prompting);
  virtual ~WxUserInteraction(void);
 protected:
  void userInteraction(AcApDocument* pDocument,bool prompting);
  void undoUserInteraction();
};


#endif
