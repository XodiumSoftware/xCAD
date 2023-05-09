#pragma once

class  MyWxApp : public wxApp
{
public:
    virtual bool OnInit();
    static bool initWxApp();
    static void uninitWxApp();
    static wxWindow* mainWindow();
};
