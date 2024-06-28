.NET API:

The supported .NET Framework is version 4.8:

To setup a project with Visual studio:
Create a class library using the class library wizard under your preferred .NET language.  There are currently two DLLs that need to be referenced, BrxMgd.DLL and TD_Mgd.DLL. These DLLs are located in your BricsCAD installation folder. An important note:  when referencing these two DLLs, its important to set the 'Copy Local' property  to false. All other DLLs such as referenced COM DLLs or satellite DLLs can have their the 'Copy Local' property to true, or as needed by your project.

Additionally, the provided samples also reference BricsCAD’s COM API. To compile the samples, or use the COM API in your module, please reference axbricscadapp1.dll and axbricscaddb1.dll located in your installation folder, with the Copy Local fag set to true or the Embed Interop Types flag set to true.  The COM API is platform specific, modules that reference 64bit modules may not run on 32bit platforms. 

**Changes in V22**
Commands that need to access the implied selection set (pickfirst set) are now required to specify either CommandFlags.UsePickset or CommandFlags.Redraw. The supported .NET Framework version changed to version 4.8. BRX21.DLL has been updated as BRX22.DLL; P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V21**
New 2D constraints classes have been implemented in the new assembly TD_MgdDbConstraints.dll. The CivilTin namespace from V20 was renamed to just Civil, and the Civil API has been enhanced and expanded to be more similar to other platforms. BRX20.DLL has been updated as BRX21.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V20**
BRX19.DLL has been updated as BRX20.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V19**
VS 2017 is the new build environment.
BRX18.DLL has been updated as BRX19.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V18**
Added Bricscad.Internals.Utils class. BRX17.DLL has been updated as BRX18.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V17**
BRX16.DLL has been updated as BRX17.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V16**
VS 2013 is the new build environment.
BRX15.DLL has been updated as BRX16.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.

**Changes in V15**
BRX14.DLL has been updated as BRX15.DLL, P/Invoke signatures depending on this file will need to be updated accordingly.


