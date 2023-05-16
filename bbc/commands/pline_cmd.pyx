import cython
from types import CodeType
# from bbc import *

cdef extern from "acgiutil.h":
    double xx(int a)
# cdef class PyAcGiGeometry:
#     cdef AcGiGeometry* thisptr

#     def __cinit__(self):
#         self.thisptr = new AcGiGeometry()

#     def __dealloc__(self):
#         del self.thisptr

#     cpdef polyline(self, giPolyline):
#         cdef AcGiPolyline* polyline_ptr = <AcGiPolyline*>giPolyline._get_thisptr()
#         return self.thisptr.polyline(giPolyline_ptr)


# # TODO: replace "your_header_file.h" and "your_namespace" with the appropriate names.
# cdef extern from "your_header_file.h" namespace "your_namespace":
#     cdef cppclass AcGiGeometry:
#         virtual Adesk::Boolean polyline(const AcGiPolyline& giPolyline) 

#     cdef cppclass AcGiPolyline:
#         # Define the members of the AcGiPolyline class if necessary
#         pass


# cdef PyAcGiGeometry geometry = PyAcGiGeometry()

# # Create an instance of AcGiPolyline
# cdef AcGiPolyline giPolyline = AcGiPolyline()
# # Set up the giPolyline object if needed
# # TODO: Add own functionality here

# # Call the polyline function
# cdef Adesk::Boolean success = geometry.polyline(giPolyline)

# # Check the result
# if success == Adesk::kFalse:
#     print("Drawing the AcGiPolyline object was successful.")
# else:
#     print("Failed to draw the AcGiPolyline object.")
