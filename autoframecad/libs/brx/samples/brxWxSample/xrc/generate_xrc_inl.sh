#!/bin/bash

if [ "$2" == "x64" ]
then
  CONFIGURATION=$1/x64
else
  CONFIGURATION=$1
fi

case $OSTYPE in
  linux*)
    WXRC=$WXWIDGETS30_PATH/build-gtk-$CONFIGURATION/utils/wxrc/wxrc
    LIB_PATH=$WXWIDGETS30_PATH/build-gtk-$CONFIGURATION/lib
  ;;
  darwin*)
    WXRC=$WXWIDGETS30_PATH/build-mac-$1/utils/wxrc/wxrc
    LIB_PATH=$WXWIDGETS30_PATH/build-mac-$1/lib/
  ;;
  *)
    echo " os-type not properly detected. expected linux*, darwin*. Found: $OSTYPE"
    exit 1
  ;;
esac


TXT_FILE=xrc/wxres_xrc.txt
INL_FILE=xrc/wxres_xrc.inl


if [ $INL_FILE -nt  $TXT_FILE ] ; then  # both files exist and INL_FILE newer than TXT_FILE
  echo "File $INL_FILE is up-to-date."
else
  echo "Regenerating $INL_FILE."
  DYLD_LIBRARY_PATH=$LIB_PATH LD_LIBRARY_PATH=$LIB_PATH $WXRC -c -o $INL_FILE xrc/common/*.xrc xrc/locale/en-US/*.xrc
fi

