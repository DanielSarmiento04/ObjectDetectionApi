# **Object Detection Api**

<div >
<img alt="C++" src="https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B"> <img alt="Onnx-runtime" src="https://img.shields.io/badge/OnnxRuntime-717272.svg?logo=Onnx&logoColor=white">
</div>


## Abstract



## Table of Contents
- [What is OAT++](#what-is-oat)
- [What is OpenCV](#what-is-opencv)
- [Setup](#setup)
- [References](#references)

## What is oat++?

Oat++ is a C++ web framework designed to build high-performance and scalable web applications. It is open-source and primarily focuses on providing developers with a simple and efficient way to create RESTful APIs (Representational State Transfer) and web services.

- Important Notes:
1. Compatibility with `SQLite`, `PostgreSQL` and `MongoDB`.
2. High demand supported (5 million concurrent).
3. Zero Dependency

## What is OpenCV?

> Note that actually this project is tested using opencv 4.8.1 


## SetUP

To run this project there are two way to compile the solve, the best way to compatibility is using docker, and the second is build the solution using cmake as package involve solution.

1. Cmake:

    build the oat++ library, to see all cmake params, please go to this [link](https://oatpp.io/docs/installation/unix-linux/)
    
    ```bash
        git clone https://github.com/oatpp/oatpp.git
        cd oatpp
        mkdir build && cd build
        cmake --build . --config Release 
        sudo make install
    ```

    build the opencv library, will depend ind most cases of your hardware and software installed, but take consider that it project your the dnn component of opencv and it require to compile with ProtoBuf

    If your are using macos and you are use brew as package manager, the las version `4.9.0` don't use protobuf, please install the last 4.8.1 
    
    ```bash 
        brew install --build-from-source ./opencv.rb    
    ```

    Another SO
    
    ```bash
        OPENCV_VERSION="4.8.1"
        MODULE_NAME="opencv"

        wget -O ${MODULE_NAME}.zip https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip && \
        wget -O ${MODULE_NAME}_contrib.zip https://github.com/opencv/opencv_contrib/archive/${OPENCV_VERSION}.zip
        
        unzip -o ${MODULE_NAME}.zip -d ${MODULE_NAME}
        unzip -o ${MODULE_NAME}_contrib.zip -d ${MODULE_NAME}

        cd ${MODULE_NAME}-${OPENCV_VERSION}

        cmake -D CMAKE_BUILD_TYPE=RELEASE \
        -D CMAKE_INSTALL_PREFIX=/usr/local \
        -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.8.1/modules \
        -D CMAKE_C_COMPILER=/usr/bin/clang \
        -D CMAKE_CXX_COMPILER=/usr/bin/clang++ \
        -D CMAKE_INSTALL_PREFIX=/usr/local \
        -D INSTALL_PYTHON_EXAMPLES=OFF \
        -D INSTALL_C_EXAMPLES=OFF \
        -D WITH_FFMPEG=ON \
        -D OPENJPEG_LIBRARIES=/usr/lib/libopenjp2.so \
        -D WITH_TBB=ON \
        ..

    ```

    



## References
[1] Jocher, G., Chaurasia, A., & Qiu, J. (2023). Ultralytics YOLO (Version 8.0.0) [Computer software]. https://github.com/ultralytics/ultralytics

[2] Bradski, G. (2000). The OpenCV Library. Dr. Dobb&#x27;s Journal of Software Tools.

[3] Stryzhevskyi, L., & Mokroß, B.-A. (n.d.). OATPP/OATPP: 🌱light and powerful C++ web framework for highly scalable and resource-efficient web application. it’s zero-dependency and easy-portable. GitHub. https://github.com/oatpp/oatpp 


https://github.com/petronetto/opencv-alpine/tree/master