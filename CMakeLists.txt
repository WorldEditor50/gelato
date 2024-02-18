cmake_minimum_required(VERSION 3.5)

project(gelato LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THIRDPARTY_DIR "D:/home/3rdparty")
# opencv
set(OpenCV_DIR ${THIRDPARTY_DIR}/opencv48)
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    message("found opencv:${OpenCV_LIBRARIES}")
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()
# eigen
set(Eigen3_DIR ${THIRDPARTY_DIR}/eigen3/share/eigen3/cmake)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
if (EIGEN3_FOUND)
    message(STATUS "found eigen3:${EIGEN3_INCLUDE_DIRS}")
    include_directories(${EIGEN3_INCLUDE_DIRS})
endif()
# sophus

# opengl
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    message(STATUS "found opengl:${OPENGL_LIBRARY}")
endif()
# glfw
set(GLFW3_DIR ${THIRDPARTY_DIR}/GLFW/lib/cmake/glfw3)
set(GLFW3_INCLUDE_DIRS ${THIRDPARTY_DIR}/GLFW/include)
if (WIN32)
    file(GLOB GLFW3_LIBRARIES ${THIRDPARTY_DIR}/GLFW/lib/glfw3.lib)
endif()
include_directories(${GLFW3_INCLUDE_DIRS})
# glew
set(GLEW_INCLUDE_DIRS ${THIRDPARTY_DIR}/glew-2.1.0/include)
if (WIN32)
    file(GLOB GLEW_LIBRARIES ${THIRDPARTY_DIR}/glew-2.1.0/lib/Release/x64/glew32.lib)
endif()
include_directories(${GLEW_INCLUDE_DIRS})
# glm
set(GLM_DIR ${THIRDPARTY_DIR}/glm/share/glm)
set(GLM_INCLUDE_DIRS ${THIRDPARTY_DIR}/glm/include)
if (WIN32)
    file(GLOB GLM_LIBRARIES ${THIRDPARTY_DIR}/glm/lib/glm.lib)
endif()
include_directories(${GLM_INCLUDE_DIRS})
# test opencv
add_executable(test_opencv test/test_opencv.cpp)
target_link_libraries(test_opencv PRIVATE ${OpenCV_LIBRARIES})
# test eigen3
add_executable(test_eigen3 test/test_eigen3.cpp)
# test opengl
add_executable(test_gl test/test_gl.cpp)
target_link_libraries(test_gl PRIVATE
    ${OPENGL_LIBRARY}
    ${GLM_LIBRARIES}
    ${GLFW3_LIBRARIES}
    ${GLEW_LIBRARIES})
# gelato
add_executable(gelato main.cpp)
