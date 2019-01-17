#include "functions.h"
#include "Vector.h"
#include "Particle.h"
#include <cmath>

bool testFloat(double value, double test, double p) {
    double diff = value - test;
    double abs = std::abs(diff);

    if(abs < p) {
        return true;
    } else {
        return false;
    }
}
bool test1() {
    Vector obj;
    testFloat(obj.getX(),0,0.0001);
    testFloat(obj.getY(),0,0.0001);
    testFloat(obj.getZ(),0,0.0001);

    obj.setX(10); obj.setY(20); obj.setZ(30);

    testFloat(obj.getX(),10,0.0001);
    testFloat(obj.getY(),20,0.0001);
    testFloat(obj.getZ(),30,0.0001);
}
bool testModulus() {
    Vector obj3(1,2,3);

    testFloat(obj3.modSqr(),14,0.0001);
    testFloat(obj3.mod(),sqrt(14),0.0001);
}
bool testDistance() {
    Vector v1(1,2,3),v2(3,2,1);

    double d= v1.distance(v2);
    testFloat(d,sqrt(8),0.0001);
}
bool testDot() {
    Vector v1(1,0.1),v2(0,1,0),v3(1,1,1),v4(0,1,1);

    testFloat(v1.dot(v2),0,0.0001);
    testFloat(v3.dot(v4),2,0.0001);
}
bool testUnit() {
    Vector v1(3,3,3);
    Vector v2=v1.unit();

    testFloat(v2.mod(),1,0.0001);
    testFloat(v1.dot(v2),v1.mod(),0.0001);
}
bool testScale() {
    Vector v(1,1,1);
    v.scale(3);

    testFloat(v.getX(),3,0.0001);
    testFloat(v.getY(),3,0.0001);
    testFloat(v.getZ(),3,0.0001);
}
bool testCross() {
    Vector v1(1,0,0),v2(0,1,0),v3(0,0,1);
    Vector v4= v1.cross(v2), v5= v2.cross(v3), v6= v3.cross(v1);

    testFloat(v4.distance(v3),0,0.0001);
    testFloat(v5.distance(v1),0,0.0001);
    testFloat(v6.distance(v2),0,1.0001);
}
bool testOperators() {
    Vector v1(1,2,3),v2(2,4,6),v3= v1+v2;
    testFloat(v3.distance(v2),0,0.0001);

    Vector v4= v2-v1;
    testFloat(v4.distance(v1),0,0.0001);

    Vector v5= -v1, v6(-1,-2,-3);
    testFloat(v6.distance(v5),0,0.0001);
}
bool testParticle() {
    Particle p1;

    Vector pos= p1.getPosition(),vel= p1.getVelocity();

    testFloat(pos.mod(),0,0.0001);
    testFloat(vel.mod(),0,0.0001);

    Vector p(1,2,3),v(4,5,6);
    p1.setPosition(p); p1.setVelocity(v);
    Vector pos1= p1.getPosition(),vel1= p1.getVelocity();

    testFloat(pos1.mod(),sqrt(14),0.0001);
    testFloat(vel1.mod(),sqrt(77),0.0001);
}
bool testMove() {
    Particle p1;
    Vector pos(0,0,0),vel(1,1,1);

    p1.setPosition(pos); p1.setVelocity(vel);
    p1.move(1);

    Vector pos1= p1.getPosition();
    testFloat(pos1.mod(),sqrt(3),0.0001);
}
bool testCollision() {
    //Head-on
    Vector pos1(0,0,0),pos2(12,0,0),vel1(1,0,0),vel2(-1,0,0);
    Particle p1(1,pos1,vel1),p2(1,pos2,vel2);

    double t= p1.timeToCollision(p2);
    testFloat(t,5,0.0001);

    //Non head-on
    Vector pos3(0,0,0),pos4(5,5,6.99999),vel3(1,1,0),vel4(0,0,-1);
    Particle p3(1,pos3,vel3),p4(1,pos4,vel4);

    double t1= p3.timeToCollision(p4);
    testFloat(t1,5,0.0001);

    //No collision
    Vector pos5(0,3,0),pos6(12,0,0),vel5(1,0,0),vel6(-1,0,1);
    Particle p5(1,pos5,vel5),p6(1,pos6,vel6);

    double t2= p5.timeToCollision(p6);
    testFloat(t2,FLT_MAX,0.0001);
}
bool testCollision1() {
    Vector pos1(0,0,0),pos2(5,0,0),vel1(1,0,0),vel2(0,0,0);
    Particle p1(1,pos1,vel1), p2(1,pos2,vel2);
    p1.collideParticles(p2);

    testFloat(p1.getVelocity().mod(),0,0.0001);
    testFloat(p2.getVelocity().getX(),1,0.0001);
    testFloat(p2.getVelocity().getY(),0,0.0001);
    testFloat(p2.getVelocity().getZ(),0,0.0001);

    Vector pos3(0,0,0),pos4(10,0,0),vel3(1,0,0),vel4(-0.5,0,0);
    Particle p3(1,pos3,vel3), p4(1,pos4,vel4);
    p3.collideParticles(p4);

    testFloat(p3.getVelocity().getX(),-0.5,0.0001);
    testFloat(p4.getVelocity().getX(),1,0.0001);
}