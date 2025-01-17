# DigitalArtifexWidgets
A collection of Qt widgets packaged as a QtCreator plugin
![alt text](https://github.com/DigitalArtifex/DigitalArtifexWidgets/blob/main/images/complete.png)

## Installation (Linux)
1) Download the appropriate QtSDK version for your version of QtCreator. This can be found in "Help -> About Qt Creator". The plugin will not work if the versions do not match.
2) Build the project on the target machine with QtCreator or qmake, making sure to use the "Profile" target so both Release and Debug get compiled.
3) Open a terminal and navigate to the appropriate build directory
4) Run `sudo ./install.sh`. If `--path=` is not supplied or blank, then it is assumed that Qt's installation path is `/opt/Qt`

## Installation (Windows)
While this plugin will also work on Windows, the installation script is not currently provided. Follow the first 2 steps from the Linux instructions then manually copy the headers to the `QTINSTALLPATH/VERSION/ARCH/include/DigitalArtifex` directory, then the libraries to both `QTINSTALLPATH/VERSION/ARCH/lib` and `QTINSTALLPATH/Tools/QtCreator/lib/Qt/plugins/designer/`. If you want it to work with the stand-alone designer, the libraries will also need to be copied to `QTINSTALLPATH/VERSION/ARCH/plugins/designer`
