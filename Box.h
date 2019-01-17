#ifndef EX3_3_BOX_H
#define EX3_3_BOX_H

#include <vector>
#include "Particle.h"

class Box {
private:
    std::vector<Particle> particles;
    double size;
public:
    Box(double s = 500) : size(s) {;}

    void addParticle(const Particle & p);
    double timeToWallCollision(int wall, const Particle & p);
    void doWallCollision(int wall, Particle & p1);
    double Step();
    std::vector<int> nParticlesOctant() const;
};


#endif //EX3_3_BOX_H
