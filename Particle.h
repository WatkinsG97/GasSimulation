#ifndef EX3_3_PARTICLE_H
#define EX3_3_PARTICLE_H


#include "Vector.h"
#include <cfloat>

class Particle {
private:
    Vector p,v;
    double radius;
public:
    Particle(double r = 1,const Vector & p = Vector(), const Vector & v = Vector()) : radius(r),p(p),v(v) {;}

    void setPosition(const Vector & a) {p=a;}
    Vector getPosition() const{return p;}
    void setVelocity(const Vector & b) {v=b;}
    Vector getVelocity() const{return v;}
    double getRadius() const{return radius;}

    void move(double t);
    double timeToCollision(const Particle & p2);
    void collideParticles(Particle & p2);
};


#endif //EX3_3_PARTICLE_H
