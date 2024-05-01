"""This module contains the ifc model handling functionality."""

import ifcopenshell  # type: ignore[attr-defined]


class BIMObject:
    """Base class for BIM objects."""

    def __init__(self: "BIMObject") -> None:
        """Initialize the BIM object."""
        self.ifc_file = ifcopenshell.file()

    def create_project(self: "BIMObject") -> None:
        """Create a new IFC project."""
        self.project = self.ifc_file.createIfcProject(  # type: ignore[assignment]
            GlobalId=ifcopenshell.guid.new(),
            Name="My Project",
            LongName="My Complete Project",
            Phase="Design",
        )

    def create_wall(self: "BIMObject") -> None:
        """Create a new IFC wall."""
        self.wall = self.ifc_file.createIfcWall(  # type: ignore[assignment]
            GlobalId=ifcopenshell.guid.new(),
            Name="My Wall",
            ObjectType="Basic Wall",
            ObjectPlacement=None,
            Representation=None,
            Tag="Wall-1",
        )
        self.ifc_file.add(self.wall)  # type: ignore[call-arg]

    def write_to_file(self: "BIMObject", filename: str = "test.ifc") -> None:
        """Write the IFC file to disk."""
        self.ifc_file.write(filename)  # type: ignore[no-untyped-call]

    def read_from_file(
        self: "BIMObject",
        filename: str = "test.ifc",
    ) -> ifcopenshell.file:
        """Read the IFC file from disk."""
        ifc_file = ifcopenshell.open(filename)  # type: ignore[no-untyped-call]
        for entity in ifc_file:
            print(entity)
        return ifc_file


bim = BIMObject()
bim.create_project()
bim.create_wall()
bim.write_to_file()
bim.read_from_file("test.ifc")
