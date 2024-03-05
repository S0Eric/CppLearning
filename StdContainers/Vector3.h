#pragma once

#include <iostream>

class Vector3 {
public:
    Vector3(int x, int y, int z);
    Vector3(const Vector3& v);
    friend std::ostream& operator<<(std::ostream& stream, const Vector3& v);

    int x;
    int y;
    int z;
};

