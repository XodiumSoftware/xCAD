import cython
import brx23

cdef class PyAcGiGeometry:
    cdef AcGiGeometry* thisptr

    def __cinit__(self):
        self.thisptr = new AcGiGeometry()

    def __dealloc__(self):
        del self.thisptr

    cpdef polyline(self, giPolyline):
        # FIXME: unused variables
        cdef AcGiPolyline* polyline_ptr = <AcGiPolyline*>giPolyline._get_thisptr()
        return self.thisptr.polyline(giPolyline_ptr)
