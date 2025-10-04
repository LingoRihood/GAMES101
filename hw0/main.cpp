#include <iostream>
#include <eigen3/Eigen/Core>
#include <cmath> // 包含数学函数库

using namespace std;

int main() {
    // 定义原点坐标 P(2,1)，并转换为齐次坐标 (x, y, 1)
    Eigen::Vector3f point(2.0f, 1.0f, 1.0f);

    // 旋转角度 45° 转换为弧度
    float theta = 45.0f * M_PI / 180.0f;

    // 创建旋转矩阵 (逆时针旋转 45°)
    Eigen::Matrix3f rotationMatrix;
    rotationMatrix<< cos(theta), -sin(theta), 0,
                     sin(theta),  cos(theta), 0,
                     0,           0,          1;
    
    // 创建平移矩阵 (平移 (1, 2))
    Eigen::Matrix3f translationMatrix;
    translationMatrix<< 1, 0, 1,
                        0, 1, 2,
                        0, 0, 1;
    
    // 先进行旋转，再进行平移：矩阵相乘
    Eigen::Matrix3f transformationMatrix = translationMatrix * rotationMatrix;

    // 计算变换后的坐标
    Eigen::Vector3f transformedPoint = transformationMatrix * point;

    // 输出结果
    std::cout << "The final coordinates after rotation and translation are: ("
              << transformedPoint(0) << ", " << transformedPoint(1) << ")" << std::endl;

    std::cout<< "The transformedPoint is:\n" << transformedPoint << std::endl; 

    return 0;
}