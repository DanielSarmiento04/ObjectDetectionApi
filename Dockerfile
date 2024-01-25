FROM ubuntu:20.04

LABEL mantainer="Daniel Sarmiento <josedanielsarmiento219@gmail.com>"

WORKDIR /opt/build

ARG DEBIAN_FRONTEND=noninteractive

# OpenCV Version
ARG OPENCV_VERSION="4.8.0"

# Install build dependencies
RUN apt-get clean && \
    apt-get update && \
    apt-get install -y --no-install-recommends --fix-missing \
        build-essential binutils \
        ca-certificates cmake cmake-qt-gui curl \
        dbus-x11 \
        ffmpeg \
        gdb gcc g++ gfortran git \
        tar \
        lsb-release \
        procps \
        manpages-dev \
        unzip \
        zip \
        wget \
        xauth \
        swig \
        python3-pip python3-dev python3-numpy python3-distutils \
        python3-setuptools python3-pyqt5 python3-opencv \
        libboost-python-dev libboost-thread-dev libatlas-base-dev libavcodec-dev \
        libavformat-dev libavutil-dev libcanberra-gtk3-module libeigen3-dev \
        libglew-dev libgl1-mesa-dev libgl1-mesa-glx libglib2.0-0 libgtk2.0-dev 

RUN apt-get -qq update \
    && apt-get -qq install -y --no-install-recommends \
        build-essential \
        cmake \
        git \
        wget \
        unzip \
        yasm \
        pkg-config \
        libswscale-dev \
        libtbb2 \
        libtbb-dev \
        libjpeg-dev \
        libpng-dev \
        libtiff-dev \
        libopenjp2-7-dev \
        libavformat-dev \
        libpq-dev 


# FROM alpine:3.14

# RUN apk update \
#   && apk upgrade 

# # Add Edge repos
# RUN echo -e "\n\
# @edgemain http://nl.alpinelinux.org/alpine/edge/main\n\
# @edgecomm http://nl.alpinelinux.org/alpine/edge/community\n\
# @edgetest http://nl.alpinelinux.org/alpine/edge/testing"\
# >> /etc/apk/repositories

# RUN apk add --no-cache \
#   bash \
#   build-base \
#   ca-certificates \
#   clang-dev \
#   clang \
#   cmake \
#   coreutils \
#   curl \ 
#   freetype-dev \
#   ffmpeg-dev \
#   ffmpeg-libs \
#   gcc \
#   g++ \
#   git \
#   gettext \
#   lcms2-dev \
#   libavc1394-dev \
#   libc-dev \
#   libffi-dev \
#   libjpeg-turbo-dev \
#   libpng-dev \
#   libressl-dev \
#   libtbb@edgetest \
#   libtbb-dev@edgetest \
#   libwebp-dev \
#   linux-headers \
#   make \
#   musl \
#   openblas@edgecomm \
#   openblas-dev@edgecomm \
#   openjpeg-dev \
#   openssl \
#   openjpeg-dev \
#   tiff-dev \
#   unzip \
#   zlib-dev
    
# RUN apk update \
#   && apk upgrade 

# ADD . /code/

# RUN rm -rf /tmp
# RUN mkdir /tmp && cd /tmp && \
#   wget -O opencv.zip https://github.com/opencv/opencv/archive/4.8.1.zip && \
#   wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.8.1.zip

# RUN unzip /tmp/opencv.zip -d /tmp && \
#   unzip /tmp/opencv_contrib.zip -d /tmp

# RUN rm /tmp/opencv.zip && rm /tmp/opencv_contrib.zip

# WORKDIR /tmp/opencv-4.8.1

# RUN mkdir build && cd build && \
#   cmake -D CMAKE_BUILD_TYPE=RELEASE \
#   -D CMAKE_INSTALL_PREFIX=/usr/local \
#   -D OPENCV_EXTRA_MODULES_PATH=/tmp/opencv_contrib-4.8.1/modules \
#   -D CMAKE_C_COMPILER=/usr/bin/clang \
#   -D CMAKE_CXX_COMPILER=/usr/bin/clang++ \
#   -D CMAKE_INSTALL_PREFIX=/usr/local \
#   -D INSTALL_PYTHON_EXAMPLES=OFF \
#   -D INSTALL_C_EXAMPLES=OFF \
#   -D WITH_FFMPEG=ON \
#   -D OPENJPEG_LIBRARIES=/usr/lib/libopenjp2.so \
#   -D WITH_TBB=ON \
#   ..

# # WORKDIR /code
# # Build the project dependencies oatpp
# # RUN ./utility/install-oatpp-modules.sh

# # Build OpenCv dependencies



# # # build  the project
# # RUN mkdir -p /code/build \
# #   && cd /code/build 

# # WORKDIR /code/build/
# # RUN cmake ..
# # RUN make -j4

# # EXPOSE 8000 8000

# # ENTRYPOINT ["./api_machine_learning-exe"]
