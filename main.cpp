#include <iostream>
#include <cmath>
#include <string>
#include "Quaternion.hpp"

// Main function to shwo the use of the Quaternion class
int main(int argc, char const *argv[])
{
    Quaternion q1(1,2,3,4);
    Quaternion q2(5,6,7,8);
    std::cout << "Quatirnio q1: " << q1 << std::endl;
    std::cout << "Quatirnio q2: " << q2 << std::endl;
    Quaternion q3 = q1 + q2;
    std::cout << "Sum of q1 and q2: " << q3 << std::endl;

    Quaternion q4 = q1 * q2;
    std::cout << "Product of q1 and q2: " << q4 << std::endl;

    Quaternion q5 = q1 * 2;
    std::cout << "Product of q1 and escalar 2: " << q5 << std::endl;

    Quaternion q6 = q1 + 2;
    std::cout << "Sum of q1 and escalar 2: " << q6 << std::endl;

    Quaternion q7 = ~q1;
    std::cout << "Conjugate of q1: " << q7 << std::endl;

    float q8 = &q1;
    std::cout << "Module q1: " << q8 << std::endl;

    return 0;
}
