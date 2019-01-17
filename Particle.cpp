#include <cmath>
#include "Particle.h"

void Particle::move(double t) {
    Vector delta(v);
    delta.scale(t);
    p+=delta;
}
double Particle::timeToCollision(const Particle & p2) {
    Vector r0(p2.p.getX() - p.getX(),p2.p.getY() - p.getY(),p2.p.getZ() - p.getZ()),
           V(p2.v.getX()-v.getX(),p2.v.getY()-v.getY(),p2.v.getZ()-v.getZ());

    if(V.mod()<0.000001) {return FLT_MAX;}
    double tca= -r0.dot(V)/V.modSqr();
    if(tca<0) {return FLT_MAX;}

    Vector s(V);
    s.scale(tca);
    double bSqr= r0.modSqr() - s.modSqr(),
           radSqr= p2.radius*p2.radius;

    if(bSqr>4*radSqr) {return FLT_MAX;}

    double tcol= tca - (sqrt(4*radSqr - bSqr))/V.mod();
    if(tcol>0) {return tcol;} else {return FLT_MAX;}
}
void Particle::collideParticles(Particle & p2) {

    double collisionTime = timeToCollision(p2);

    if(collisionTime < 0 || FLT_MAX-collisionTime < 1000) {return;}

    move(collisionTime);
    p2.move(collisionTime);
    Vector n= (p2.p-p).unit(),v1(n),v2(n);

    v1.scale(v.dot(n));
    v2.scale(p2.v.dot(n));
    Vector deltaV= v2-v1;
    v+=deltaV; p2.v-=deltaV;
}