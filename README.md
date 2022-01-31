#Arm NN installation and Demo on NGDSystems CSDs

##Introduction

This is a branch of the ArmNN platform modified and used for NGD Systems' CSDs. It includes:

-    The codes from the master branch
-    The installation instruction from the sources (including the required dependencies)
-    This readme to provide instructions for installing the ArmNN on the CSDs
-    NGD Systems Demo files to replicate the demo

The final product will look like the following demo:


**For the master branch:**
https://github.com/ARM-software/armnn


##Installation Requirements:


##Installation Steps:

$ sudo apt-get update
$ sudo apt-get upgrade

**some tools**
$ sudo apt-get install scons git wget
$ sudo apt-get install autoconf
$ sudo apt-get install libtool

**make the directory**
$ mkdir armnn-pi
$ cd armnn-pi
$ export BASEDIR=`pwd`

**get the ARM libraries**
scons -j 4 extra_cxx_flags="-fPIC" Werror=0 debug=0 asserts=0 neon=1 opencl=0 os=linux arch=armv8a examples=

$ git clone https://github.com/Arm-software/ComputeLibrary.git
$ git clone https://github.com/Arm-software/armnn

**and the dependencies**
sudo apt install libboost1.71-all-dev

git clone https://github.com/google/protobuf.git
git clone https://github.com/google/flatbuffers.git
git clone https://github.com/tensorflow/tensorflow.git

**Making ARM Compute library using scons**

$ cd $BASEDIR/ComputeLibrary
scons -j 4 extra_cxx_flags="-fPIC" Werror=0 debug=0 asserts=0 neon=1 opencl=0 os=linux arch=armv8a examples=1


**Installing Protobuf**
cd $BASEDIR/protobuf
$ git submodule update --init --recursive
$ ./autogen.sh
$ ./configure --prefix=$BASEDIR/protobuf
$ make -j4
$ make install
$ make clean

