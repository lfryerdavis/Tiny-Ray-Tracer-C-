//
//  utilities.hpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-09-18.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <iostream>
#include <vector>

using namespace std;

void testUtilities();

typedef unsigned int uint32;
typedef unsigned char uint8;

struct colour
{
    double red;
    double green;
    double blue;
    double alpha;
    
    colour(double Red = 0, double Green = 0, double Blue = 0, double Alpha = 0) {red = Red; green = Green; blue = Blue; alpha = Alpha;};
};

struct dtuple3
{
    double x;
    double y;
    double z;
    
    dtuple3(double X = 0, double Y = 0, double Z = 0) {x = X; y = Y; z = Z;};
    void negate();
    void multiplyBy(double scalingValue);
    void add(dtuple3 rhs);
    void subtract(dtuple3 rhs);
    double magnitude();
    void normalize();
    bool isEqual(dtuple3 rhs);
    double dot(dtuple3 rhs);
    dtuple3 cross(dtuple3 rhs);
};

struct dtuple4
{
    double x;
    double y;
    double z;
    double w;
    
    dtuple4(double X = 0, double Y = 0, double Z = 0, double W = 0) {x = X; y = Y; z = Z; w = W;};
    void negate();
    void multiplyBy(double scalingValue);
    void add(dtuple4 rhs);
    void subtract(dtuple4 rhs);
    double magnitude();
    void normalize();
    bool isEqual(dtuple4 rhs);
    double dot(dtuple4 rhs);
};

typedef vector<int> ivec;
typedef vector<ivec> imatrix;

typedef vector<uint8> i8vec;
typedef vector<i8vec> i8matrix;

typedef vector<colour> colourvec;
typedef vector<colourvec> colourmatrix;

ostream &operator<<(ostream &stream, dtuple3 &obj);
ostream &operator<<(ostream &stream, dtuple4 &obj);

ostream &operator<<(ostream &stream, ivec &obj);
ostream &operator<<(ostream &stream, imatrix &obj);

ostream &operator<<(ostream &stream, i8vec &obj);
ostream &operator<<(ostream &stream, i8matrix &obj);

ostream &operator<<(ostream &stream, colour &obj);
ostream &operator<<(ostream &stream, colourvec &obj);
ostream &operator<<(ostream &stream, colourmatrix &obj);

#endif /* utilities_hpp */
