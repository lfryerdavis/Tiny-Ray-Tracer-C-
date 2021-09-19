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

typedef vector<int> ivec;
typedef vector<ivec> imatrix;

typedef vector<uint8> i8vec;
typedef vector<i8vec> i8matrix;

typedef vector<colour> colourvec;
typedef vector<colourvec> colourmatrix;

ostream &operator<<(ostream &stream, ivec &obj);
ostream &operator<<(ostream &stream, imatrix &obj);

ostream &operator<<(ostream &stream, i8vec &obj);
ostream &operator<<(ostream &stream, i8matrix &obj);

ostream &operator<<(ostream &stream, colour &obj);
ostream &operator<<(ostream &stream, colourvec &obj);
ostream &operator<<(ostream &stream, colourmatrix &obj);

#endif /* utilities_hpp */
