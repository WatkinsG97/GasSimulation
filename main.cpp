#include <iostream>
#include <cstdlib>
#include <fstream>
#include "functions.h"
#include "Box.h"
#include "random.h"

using namespace std;

int main() {
    bool t1 = test1();
    if(t1) {cout << "Test 1 SUCCESS" << endl;}
    else {cout << "Test 1 FAILED" << endl;}

    bool t2 = testModulus();
    if(t2) {cout << "Test Modulus : SUCCESS" << endl;}
    else {cout << "Test Modulus : FAILED" << endl;}

    bool t3 = testDistance();
    if(t3) {cout << "Test Distance : SUCCESS" << endl;}
    else {cout << "Test Distance : FAILED" << endl;}

    bool t4 = testDot();
    if(t4) {cout << "Test Dot : SUCCESS" << endl;}
    else {cout << "Test Dot : FAILED" << endl;}

    bool t5 = testScale();
    if(t5) {cout << "Test Scale : SUCCESS" << endl;}
    else {cout << "Test Scale : FAILED" << endl;}

    bool t6 = testUnit();
    if(t6) {cout << "Test Unit : SUCCESS" << endl;}
    else {cout << "Test Unit : FAILED" << endl;}

    bool t7 = testCross();
    if(t7) {cout << "Test Cross : SUCCESS" << endl;}
    else {cout << "Test Cross : FAILED" << endl;}

    bool t8 = testOperators();
    if(t8) {cout << "Test Operators : SUCCESS" << endl;}
    else {cout << "Test Operators : FAILED" << endl;}

    bool t9 = testParticle();
    if(t9) {cout << "Test Particle : SUCCESS" << endl;}
    else {cout << "Test Particle : FAILED" << endl;}

    bool t10 = testMove();
    if(t10) {cout << "Test Move : SUCCESS" << endl;}
    else {cout << "Test Move : FAILED" << endl;}

    bool t11 = testCollision();
    if(t11) {cout << "Test Collision : SUCCESS" << endl;}
    else {cout << "Test Collision : FAILED" << endl;}

    bool(t12) = testCollision1();
    if(t12) {cout << "Test Collision 1 : SUCCESS" << endl;}
    else {cout << "Test Collision 1 : FAILED" << endl;}

    Box box;
    for(int i=1;i<=1000;++i) {

        int rand1,rand2,rand3;
        do {
            rand1 = rand();
        }while(rand1>30000 || rand1%250==0);
        rand1= rand1%250;
        do {
            rand2 = rand();
        }while(rand2>30000 || rand2%250==0);
        rand2= rand2%250;
        do {
            rand3 = rand();
        }while(rand3>30000 || rand3%250==0);
        rand3= rand3%250;

        Vector pos(rand1,rand2,rand3),
               vel(Random::randomNorm(0,10),
                   Random::randomNorm(0,10),
                   Random::randomNorm(0,10));
        Particle p(1,pos,vel);
        box.addParticle(p);
    }
    float timeElapsed=0;
    ofstream output;
    output.open("D:/Collisions.txt");

    for(int i=0;i<=10001;++i) {

        if(i%100==0) {output <<i<<" "<<timeElapsed<<" "<<box.nParticlesOctant()[0]<<" "<<box.nParticlesOctant()[1]
                    <<" "<<box.nParticlesOctant()[2]<<" "<<box.nParticlesOctant()[3]
                    <<" "<<box.nParticlesOctant()[4]<<" "<<box.nParticlesOctant()[5]
                    <<" "<<box.nParticlesOctant()[6]<<" "<<box.nParticlesOctant()[7]<<endl;
        }if(i==10000){break;}
        timeElapsed+=box.Step();
   }
    output.close();
    return 0;
}