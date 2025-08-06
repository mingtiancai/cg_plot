#include "Vector3d.h"
#include <iostream>

void testVector3d()
{
    auto p0 = Vector3d(100, 100, 0);
    auto p1 = Vector3d(-100, 100, -100);
    auto p2 = Vector3d(100, -100, 100);

    auto l1=p1-p0;
    auto l2=p2-p0;

    auto n=Cross(l1,l2).Normalize();

    double a,b,c,d;

    a=n.GetX();
    b=n.GetY();
    c=n.GetZ();
    d=-(a*p0.GetX()+b*p0.GetY()+c*p0.GetZ());

    std::cout << "Plane equation: " << a << "x + " << b << "y + " << c << "z + " << d << " = 0" << std::endl;

    std::cout << "p0 "<< a*p0.GetX()+b*p0.GetY()+c*p0.GetZ()+d << std::endl;
    std::cout << "p1 "<< a*p1.GetX()+b*p1.GetY()+c*p1.GetZ()+d << std::endl;
    std::cout << "p2 "<< a*p2.GetX()+b*p2.GetY()+c*p2.GetZ()+d << std::endl;
}

int main(int argc, char** argv)
{
    testVector3d();
    return 0;
}