cmake_minimum_required(VERSION 3.11)

project(Transformation)

# 手动指定 Eigen3 路径（如果需要）
set(EIGEN3_INCLUDE_DIR "C:/Program Files (x86)/Eigen3/include")

# 使用 Eigen3
find_package(Eigen3 REQUIRED)

# 设置包含目录
include_directories(${EIGEN3_INCLUDE_DIR})

# 添加执行文件
add_executable(Transformation main.cpp)
