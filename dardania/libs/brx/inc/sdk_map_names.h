// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// this header profides following features :
// provides name mangling for ARX <= 2009 vs. ARX >= 2010 vs. BRX 12/13
// ("subWorldDraw" vs. "worldDraw"); it wraps both "old" and "new" naming convention to
// the correct one, depending on ARX/BRX build version

// You must have "BRX_APP" defined for BRX builds (without BRX_APP, it is an ARX build)!


#ifdef BRX_APP  // BRX builds
  #include "brx_version.h"
#else           // ARX builds
  #include "arx_version.h"
#endif // BRX_APP
