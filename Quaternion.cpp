#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Quaternion.hpp"
using namespace std;
using std::vector;

// Auxiliary function print the Quaternion class
bool all_zeros_before(float arr[], int i) {
    for (int j = 0; j < i; j++) {
        if (arr[j] != 0) {
            return false;
        }
    }
    return true;
}

// Main function to print the Quaternion class
ostream& operator<<(ostream& os, const Quaternion &q) {
        string result = "";
        string buffer;
        int buffer_size;
        if (q.a != 0) {
            buffer = to_string(q.a);
            buffer_size = buffer.size();
            result += buffer.substr(0, buffer_size - 4);
        }
        string units[3] = {"i", "j", "k"};
        float coeffs[4] = {q.a, q.b, q.c, q.d};

        for (int index = 1; index < 4; index++) {
            string unit = units[index-1];
            float coeff = coeffs[index];
            buffer = to_string(coeff);
            buffer_size = buffer.size();
            buffer = buffer.substr(0, buffer_size - 4);
            float prev_coeff = coeffs[index-1];
            if (coeff == 1) {
                result += !all_zeros_before(coeffs,index) ? " + "+unit : unit;
    
            } else if (coeff == -1) {
                result += !all_zeros_before(coeffs,index) ? " - "+unit : "-"+unit;
    
            } else if (coeff < 0) {
                result += !all_zeros_before(coeffs,index) ? " - "+ buffer + unit :  buffer + unit;
    
            } else if (coeff > 0) {
                result += !all_zeros_before(coeffs,index) ? " + "+ buffer + unit:  buffer + unit;
    
            }
        }
        return os << result;
}