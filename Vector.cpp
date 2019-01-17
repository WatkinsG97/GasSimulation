#include <cmath>
#include "Vector.h"

double Vector::modSqr() const {
    double modsqr= x*x+y*y+z*z;
    return modsqr;
}
double Vector::mod() const {
    double mod= sqrt(x*x+y*y+z*z);
    return mod;
}
double Vector::dot(const Vector & vec) const {
    double dot= x*vec.x + y*vec.y + z*vec.z;
    return dot;
}
double Vector::distance(const Vector & v) const {
    Vector v1(v.x-x,v.y-y,v.z-z);

    double dist= sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
    return dist;
}
void Vector::scale(double f) {
    x= x*f, y= y*f, z= z*f;
}
Vector Vector::unit() {
    Vector v(x,y,z);
    v.scale(1/v.mod());
    return v;
}
Vector Vector::cross(const Vector & v) {
    double crossX = x*v.z - z*v.y,
           crossY = z*v.x - x*v.z,
           crossZ = x*v.y - y*v.x;
    Vector vec(crossX,crossY,crossZ);
    return vec;
}