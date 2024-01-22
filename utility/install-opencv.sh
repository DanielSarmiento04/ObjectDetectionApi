##########################################################

cd /tmp
## install opencv

OPENCV_VERSION="4.8.0"
MODULE_NAME="opencv"


wget -O ${MODULE_NAME}.zip https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/${OPENCV_VERSION}.zip \


# git clone --depth=1 https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip 

# cd $MODULE_NAME
# mkdir build
# cd build

# cmake -DOATPP_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release ..
# make install -j 6

# cd ../../

##########################################################

