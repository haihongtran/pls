#include <iostream>
#include "point3d.h"
#include "vector3d.h"

void Point3d::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")" << std::endl;
}

void Point3d::moveByVector(Vector3d &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}
