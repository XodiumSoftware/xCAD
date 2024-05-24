Requirements:
-.NET runtime version 4.8
-Platform toolset is v142 (Visual Studio 2019)
 Note: The project is already set to the proper platform toolset - if you encounter the dialog "Review Project and Solution Changes" please choose "Cancel"
-AutoCAD 2021/2022

For compiling the sample:
1. First choose the Configuration (Debug Acad or Release Acad).
If "Solution Platforms" combo box is missing from Visual Studio toolbar, you cand add it from "Standard Toolbar Options" button.
2. Add the system variable AUTOCAD32_PATH for AutoCAD 32-bit or AUTOCAD64_PATH for AutoCAD 64-bit, it should contains as a value the path to the AutoCAD installation folder e.g: "C:\Program Files\Autodesk\AutoCAD 2021"
3. Build CMyManagedEntity project, as a result the assembly CMyManagedEntity.dll is created on Projects\Acad\CMyManagedEntity\"Platform"\"Configuration" folder.
4. Add the assemblies: accoremgd.dll (Copy Local=False), acdbmgd.dll (Copy Local=False), acmgd.dll (Copy Local=False) and CMyManagedEntity.dll (Copy Local=True) to the project CMyManagedEntityUI references
5. Build CMyManagedEntityUI project

For running the sample:
1. Go to CMyManagedEntityUI project properties
2. From Debug tab select "Start External program" and fill the text box with AutoCAD executable path
3. Pick "Set as Startup project" for CMyManagedEntityUI (right click on it)
4. Run the project (F5 or Ctrl+F5)
5. Type the NETLOAD command
  From Projects\Acad\CMyManagedEntityUI\bin\"Platform"\"Configuration" folder, load only CMyManagedEntityUI.dll
6. Type one of the following available commands:
-CustMgdEnt
-CustMgdEntDerived
-GetCustomEnt





