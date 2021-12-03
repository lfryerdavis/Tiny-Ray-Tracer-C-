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
    uint8 red;
    uint8 green;
    uint8 blue;
    uint8 alpha;
    
    colour(uint8 Red, uint8 Green, uint8 Blue, uint8 Alpha) {red = Red; green = Green; blue = Blue; alpha = Alpha;};
};

struct dtuple3
{
    double x;
    double y;
    double z;
    
    dtuple3(double X, double Y, double Z) {x = X; y = Y; z = Z;};
    void negate();
    void multiplyBy(double scalingValue);
    dtuple3 add(dtuple3 lhs, dtuple3 rhs);
    dtuple3 subtract(dtuple3 lhs, dtuple3 rhs);
};

struct dtuple4
{
    double x;
    double y;
    double z;
    double w;
    
    dtuple4(double X, double Y, double Z, double W) {x = X; y = Y; z = Z; w = W;};
    void negate();
    void multiplyBy(double scalingValue);
    dtuple4 add(dtuple4 lhs, dtuple4 rhs);
    dtuple4 subtract(dtuple4 lhs, dtuple4 rhs);
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
