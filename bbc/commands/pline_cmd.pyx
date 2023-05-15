import bbc.wrappers.PyAcGiGeometry


# TODO: replace "your_header_file.h" and "your_namespace" with the appropriate names.
cdef extern from "your_header_file.h" namespace "your_namespace":
    cdef cppclass AcGiGeometry:
        virtual Adesk::Boolean polyline(const AcGiPolyline& giPolyline) const

    cdef cppclass AcGiPolyline:
        # Define the members of the AcGiPolyline class if necessary
        pass


cdef PyAcGiGeometry geometry = PyAcGiGeometry()

# Create an instance of AcGiPolyline
cdef AcGiPolyline giPolyline = AcGiPolyline()
# Set up the giPolyline object if needed
# TODO: Add own functionality here

# Call the polyline function
cdef Adesk::Boolean success = geometry.polyline(giPolyline)

# Check the result
if success == Adesk::kFalse:
    print("Drawing the AcGiPolyline object was successful.")
else:
    print("Failed to draw the AcGiPolyline object.")
