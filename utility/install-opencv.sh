##########################################################
#!/bin/sh

rm -rf tmp

mkdir tmp
cd tmp

## install opencv
OPENCV_VERSION="4.8.1"
MODULE_NAME="opencv"

mkdir /opt && cd /opt && \
  wget -O ${MODULE_NAME}.zip https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip && \
  wget -O ${MODULE_NAME}_contrib.zip https://github.com/opencv/opencv_contrib/archive/${OPENCV_VERSION}.zip


unzip -o ${MODULE_NAME}.zip -d ${MODULE_NAME}
unzip -o ${MODULE_NAME}_contrib.zip -d ${MODULE_NAME}
# wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/${OPENCV_VERSION}.zip \


# git clone --depth=1 https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip 

# cd $MODULE_NAME
# mkdir build
# cd build

# cmake -DOATPP_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ..
# make install -j 6

# cd ../../

##########################################################

