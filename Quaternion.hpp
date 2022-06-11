#ifndef Quaternion_cpp
#define Quaternion_cpp

#include <iostream>
#include <cmath>
using namespace std;

class Quaternion {
public:
    float a, b, c, d;
    Quaternion(float w = 0, float x = 0, float y = 0, float z = 0) {
        this->a = w;
        this->b = x;
        this->c = y;
        this->d = z;
    }

    // Sum of two quaternions
    Quaternion operator+(const Quaternion& q) {
        Quaternion r;
        r.a = a + q.a;
        r.b = b + q.b;
        r.c = c + q.c;
        r.d = d + q.d;
        return r;
    }

    // Sum of a quaternion and a scalar quantity
    Quaternion operator+(const float& f) {
        Quaternion r;
        r.a = a + f;
        r.b = b;
        r.c = c;
        r.d = d;
        return r;
    }

    // Conjugate operator
    Quaternion operator~() {
        Quaternion r;
        r.a = a;
        r.b = -b;
        r.c = -c;
        r.d = -d;
        return r;
    }

    // Product of two quaternions
    Quaternion operator*(const Quaternion& q) {
        Quaternion r;
        r.a = a * q.a - b * q.b - c * q.c - d * q.d;
        r.b = a * q.b + b * q.a + c * q.d - d * q.c;
        r.c = a * q.c - b * q.d + c * q.a + d * q.b;
        r.d = a * q.d + b * q.c - c * q.b + d * q.a;
        return r;
    }

    // Product of a quaternion and a scalar quantity
    Quaternion operator*(const float& f) {
        Quaternion r;
        r.a = a * f;
        r.b = b;
        r.c = c;
        r.d = d;
        return r;
    }

    // Module operator
    float operator&() {
        return sqrt(a * a + b * b + c * c + d * d);
    }

    friend ostream& operator<<(ostream& os, const Quaternion &q);

};

bool all_zeros_before(float arr[], int i);

ostream& operator<<(ostream& os, const Quaternion &q);

#endif