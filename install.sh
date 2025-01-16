#!/bin/bash

for i in "$@"; do
  case $i in
    -e=*|--path=*)
      INSTALLPATH="${i#*=}"
      shift # past argument=value
      ;;
    -*|--*)
      echo "Unknown option $i"
      exit 1
      ;;
    *)
      ;;
  esac
done

if [ -z "$INSTALLPATH" ]
    then INSTALLPATH=/opt/Qt
fi

if [[ $INSTALLPATH == */ ]]
    then
        SUBPATH="Tools/QtCreator/lib/Qt/plugins/designer/"
    else
        SUBPATH="/Tools/QtCreator/lib/Qt/plugins/designer/"
fi

echo "Copying dependencies"
make install

echo "Copying plugins to $INSTALLPATH$SUBPATH"
cp 'libdigitalartifexwidgets.so' $INSTALLPATH$SUBPATH
cp 'libdigitalartifexwidgets.so.debug' $INSTALLPATH$SUBPATH
echo "Finished"
