#ifndef EX3_3_VECTOR_H
#define EX3_3_VECTOR_H


class Vector {
private:
    double x,y,z;
public:
    void setX(double u) {x=u;}
    double getX() const{return x;}
    void setY(double v) {y=v;}
    double getY() const{return y;}
    void setZ(double w) {z=w;}
    double getZ() const{return z;}

    Vector(double a=0, double b=0, double c=0) : x(a),y(b),z(c) {;}

    double modSqr() const;
    double mod() const;
    double dot(const Vector & vec) const;
    double distance(const Vector & v) const;
    void scale(double f);
    Vector unit();
    Vector cross(const Vector & v);

    Vector & operator+=(const Vector & v2) {
        x+= v2.x; y+= v2.y; z += v2.z;
        return *this;
    }
    Vector operator+(const Vector & v2)const {
        Vector v1(*this);
        return v1+=v2;
    }
    Vector & operator-=(const Vector & v2) {
        x-= v2.x; y-= v2.y; z -= v2.z;
        return *this;
    }
    Vector operator-(const Vector & v2)const {
        Vector v1(*this);
        return v1-=v2;
    }
    Vector operator-() const {
        Vector v1;
        v1.x=-x; v1.y=-y;v1.z=-z;
        return v1;
    }
};


#endif //EX3_3_VECTOR_H