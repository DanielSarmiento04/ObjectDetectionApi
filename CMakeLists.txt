cmake_minimum_required(VERSION 3.5)

set(project_name api_machine_learning) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 17)

add_library(${project_name}-lib
        src/AppComponent.hpp
        src/controller/MyController.cpp
        src/controller/MyController.hpp
        src/dto/DTOs.hpp
        src/ia/inference.cpp
        src/ia/inference.h
)

## link libs

find_package(oatpp 1.3.0 REQUIRED)

# Set custom OpenCV_DIR here
set(OpenCV_DIR /usr/lib/cmake/opencv4)
find_package(OpenCV 4.5.0 REQUIRED)
# find_package(Protobuf REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC ${OpenCV_LIBS}
        # PUBLIC ${PROTOBUF_LIBRARY} 
        # PUBLIC ${PROTOBUF_PROTOC_LIBRARY}
)

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/App.cpp
        test/app/MyApiTestClient.hpp)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
        test/app/TestComponent.hpp
        test/app/MyApiTestClient.hpp
        test/MyControllerTest.cpp
        test/MyControllerTest.hpp
)

target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe ${project_name}-test PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

enable_testing()
add_test(project-tests ${project_name}-test)