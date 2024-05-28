// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class  MyWxApp : public wxApp
{
public:
    virtual bool OnInit();
    static bool initWxApp();
    static void uninitWxApp();
    static wxWindow* mainWindow();
};
