#include "Point3D.hpp"

Point3D::Point3D(void)
{ 
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Point3D::Point3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}