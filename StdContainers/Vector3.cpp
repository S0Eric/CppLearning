#include "Vector3.h"

#include <iostream>

using namespace std;

Vector3::Vector3(int x, int y, int z) : x(x), y(y), z(z) {
    //cout << "Vector3 Constructed: " << hex << this << dec << endl;
}

Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {
    //cout << "Vector3 Copied: " << hex << this << " = " << &v << dec << endl;
}

std::ostream& operator<<(std::ostream& stream, const Vector3& v) {
    stream << "V3(" << v.x << "," << v.y << "," << v.z << ")";
    return stream;
}