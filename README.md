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

    



## References
[1] Jocher, G., Chaurasia, A., & Qiu, J. (2023). Ultralytics YOLO (Version 8.0.0) [Computer software]. https://github.com/ultralytics/ultralytics

[2] Bradski, G. (2000). The OpenCV Library. Dr. Dobb&#x27;s Journal of Software Tools.

[3] Stryzhevskyi, L., & Mokroß, B.-A. (n.d.). OATPP/OATPP: 🌱light and powerful C++ web framework for highly scalable and resource-efficient web application. it’s zero-dependency and easy-portable. GitHub. https://github.com/oatpp/oatpp 


https://github.com/petronetto/opencv-alpine/tree/master