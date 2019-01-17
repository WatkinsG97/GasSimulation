#include "Box.h"

void Box::addParticle(const Particle & p) {
    particles.push_back(p);
}
double Box::timeToWallCollision(int wall, const Particle & p1) {
    double t=0,s=size/2;

    if(wall==1) { //Consider X
        double vX= p1.getVelocity().getX(),rX= p1.getPosition().getX();

        if(vX>0) {t=(s-rX)/vX;} else if(vX<0) {t=(-s-rX)/vX;} else if(vX==0) {t=FLT_MAX;}
    }
    else if(wall==2) { //Consider Y
        double vY= p1.getVelocity().getY(),rY= p1.getPosition().getY();

        if(vY>0) {t=(s-rY)/vY;} else if(vY<0) {t=(-s-rY)/vY;} else if(vY==0) {t=FLT_MAX;}
    }
    else if(wall==3) { //Consider Z
        double vZ= p1.getVelocity().getZ(),rZ= p1.getPosition().getZ();

        if(vZ>0) {t=(s-rZ)/vZ;} else if(vZ<0) {t=(-s-rZ)/vZ;} else if(vZ==0) {t=FLT_MAX;}
    }return t;
}
void Box::doWallCollision(int wall, Particle & p1) {
    double t= timeToWallCollision(wall,p1),vX= p1.getVelocity().getX(),
           vY= p1.getVelocity().getY(),vZ= p1.getVelocity().getZ();
    Vector v1(-vX,vY,vZ),v2(vX,-vY,vZ),v3(vX,vY,-vZ);

    p1.move(t);

    if(wall==1) {p1.setVelocity(v1);}
    else if(wall==2) {p1.setVelocity(v2);}
    else if(wall==3) {p1.setVelocity(v3);}
}
double Box::Step() {
    double timeToNextCollision= FLT_MAX;
    int collisionType= 0, collider1= -1, collider2= -1,wall;
    for(int i=0,n=particles.size();i<n;++i) {

        double t,t1= timeToWallCollision(1,particles[i]),
               t2= timeToWallCollision(2,particles[i]),
               t3= timeToWallCollision(3,particles[i]);

        if(t1<t2 && t1<t3) {t=t1;wall=1;}
        else if(t2<t1 && t2<t3) {t=t2;wall=2;}
        else if(t3<t1 && t3<t2) {t=t3;wall=3;}

        if(t<timeToNextCollision) {
            timeToNextCollision= t;
            collider1=i;
            collisionType=wall;
        }
    }
    for(int i=0,n=particles.size();i<n;++i) {
        for(int j=0,m=particles.size();j<m;++j) {
            double time=particles[j].timeToCollision(particles[i]);
            if(time<timeToNextCollision) {
                timeToNextCollision=time;
                collisionType=0;
                collider1=j;
                collider2=i;
            }
        }
    }
    if(collisionType==0) {
        particles[collider1].collideParticles(particles[collider2]);
    } else {
        doWallCollision(collisionType,particles[collider1]);
    }

    for(int k=0,l=particles.size();k<l;++k) {
        if(k!=collider1 && k!=collider2) {particles[k].move(timeToNextCollision);}
    }
    return timeToNextCollision;
}
std::vector<int> Box::nParticlesOctant() const {
    std::vector<int> vec;
    vec.resize(8);
    for(int i=0,n=particles.size();i<n;++i) {
        double X= particles[i].getPosition().getX(),
               Y= particles[i].getPosition().getY(),
               Z= particles[i].getPosition().getZ();


        if(X>0 && Y>0 && Z>0) {vec[0] += 1;} //Octant 0
        if(X>0 && Y>0 && Z<0) {vec[1] += 1;} //Octant 1
        if(X>0 && Y<0 && Z>0) {vec[2] += 1;} //Octant 2
        if(X>0 && Y<0 && Z<0) {vec[3] += 1;} //Octant 3
        if(X<0 && Y>0 && Z>0) {vec[4] += 1;} //Octant 4
        if(X<0 && Y>0 && Z<0) {vec[5] += 1;} //Octant 5
        if(X<0 && Y<0 && Z>0) {vec[6] += 1;} //Octant 6
        if(X<0 && Y<0 && Z<0) {vec[7] += 1;} //Octant 7
    }return vec;
}