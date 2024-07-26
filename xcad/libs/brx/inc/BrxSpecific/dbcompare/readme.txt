
BricsCAD provides a "DwgCompare" command to compare 2 drawings (the current one
with a specified one).

To allow BRX applications' custom entities to participate in "DwgCompare" operation,
BRX provides a utility function "bool acdbRegisterSchema(const ACHAR* schemaXmlFile)"
to register a description of the custom entity's data.

For each custom entity class, an own .txds Schema file needs to be registered;
ideally registration should be done close to rxInit() resp. kInitAppMsg;
unregistration of the .txds Schema is not necessary (and actually even not supported);
multiple registration is no problem.


A complete documentation for the Schema definition can be found here :
https://docs.opendesign.com/td/db_xmlScheme.html


Please see "BrxSpecific/dbcompare/dbCompare.h" for more details.

BRX SDK also provides a custom entity with related .txds Schema file :
   BrxSpecific/dbcompare/AcDbCustomEntitySample.cpp/h
   BrxSpecific/dbcompare/AcDbCustomEntitySample.txds
