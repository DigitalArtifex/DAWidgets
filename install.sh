#!/bin/bash

for i in "$@"; do
  case $i in
    -p=*|--path=*)
      INSTALLPATH="${i#*=}"
      shift # past argument=value
      ;;
    -c=*|--creator=*)
      CREATORVERSION="${i#*=}"
      shift # past argument=value
      ;;
    -a=*|--arch=*)
      ARCH="${i#*=}"
      shift # past argument=value
      ;;
    --skip-install)
      SKIPINSTALL=true
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

if [ -z "$INSTALLPATH" ]; then
    echo "** Path not supplied, assuming /opt/Qt"
    INSTALLPATH=/opt/Qt
fi

if [ -z "$ARCH" ]; then
    echo "** Arch version not supplied, assuming gcc_64"
    ARCH=gcc_64
fi

if [ -z "$CREATORVERSION" ]; then
    echo "** Creator version not supplied, assuming 15"
    CREATORVERSION=15
fi

if [[ $CREATORVERSION == 14 ]]; then
    CREATORARCHPATH="$INSTALLPATH/6.7.3/$ARCH"
    CREATORQMAKE="$CREATORARCHPATH/bin/qmake"

elif [[ $CREATORVERSION == 15 ]]; then
    CREATORARCHPATH="$INSTALLPATH/6.8.1/$ARCH"
    CREATORQMAKE="$CREATORARCHPATH/bin/qmake"
else
    echo "!! QtCreator Version incorrect. Only versions 14 & 15 are supported"
    exit
fi

if [[ $INSTALLPATH == */ ]]; then
        CREATORPATH="Tools/QtCreator/lib/Qt/plugins/designer/"
    else
        CREATORPATH="/Tools/QtCreator/lib/Qt/plugins/designer/"
fi

if [ -z "$SKIPINSTALL" ]; then
    SKIPINSTALL=false
fi

if ! [ -d build ]; then
    mkdir build
else
    rm -rf build/*
fi

cd build

echo "Building Library.."
OIFS=$IFS

IFS=$'\n';
SDKS=$(eval "ls $INSTALLPATH/ | grep -Eo '[4-6].[0-9].[0-9]'")
FIRSTSDK=true

for i in $SDKS; do
    QMAKE="$INSTALLPATH/$i/$ARCH/bin/qmake"

    if [ -f $QMAKE ]; then
        echo "** $i ($ARCH)"

        if [ $FIRSTSDK = true ]; then
            FIRSTSDK=false
            DIR=lib-$i
        else
            DIR=../lib-$i
        fi

        if ! [ -d $DIR ]; then
            mkdir $DIR
        else
            rm -rf $DIR/*
        fi

        cd $DIR

        OUTPUT=$(eval "$QMAKE ../../DigitalArtifexWidgets.pro")
        OUTPUT+=$(eval "make all")

        if [ $SKIPINSTALL = false ]; then
            echo "-- Installing Library"
            make install

            for libfile in ./*.so*; do
                echo "$libfile -> $INSTALLPATH/$i/$ARCH/lib/"
                cp $libfile $INSTALLPATH/$i/$ARCH/lib/
            done

            for libfile in ./*_metatypes.json; do
                echo "$libfile -> $INSTALLPATH/$i/$ARCH/metatypes/"
                cp $libfile $INSTALLPATH/$i/$ARCH/metatypes/
            done
        fi
    fi

done
IFS=$OIFS

echo "Building Plugin.."

if ! [ -d ../plugin ]; then
    mkdir ../plugin
else
    rm -rf ../plugin/*
fi

cd ../plugin
OUTPUT=$(eval "$CREATORQMAKE \"CONFIG+=plugin\" ../../DigitalArtifexWidgets.pro")
OUTPUT+=$(eval "make all")

if [ $SKIPINSTALL = false ]; then
    echo "** Installing Plugin"
    make install
fi
