//
//  utilities.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-09-18.
//

#include "utilities.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double epsilon = 0.000000001;

void testUtilities()
{
    cout << endl << "*********************" << endl;
    cout << "Testing Utilities" << endl;
    cout << "*********************" << endl << endl;

    // print dtuples
    dtuple3 dt3test(1, 2, 3);
    dtuple4 dt4test(1, 2, 3, 4);
    
    cout << "d3test = " << dt3test << " d4test = " << dt4test << " : should be [ 1 2 3 ] and [ 1 2 3 4 ]" << endl << endl;

    dtuple3 lhs(1, 2, 3);
    dtuple3 rhs(-1, 2, 4);

    lhs.subtract(rhs);
    cout << "lhs - rhs = " << lhs << " : should be [ 2 0 -1]" << endl;
    lhs.multiplyBy(1.5);
    cout << "lhs.multiplyBy(1.5) = " << lhs << " : should be [ 3 0 -1.5]" << endl;
    lhs.negate();
    cout << "lhs.negate() = " << lhs << " : should be [ -3 0 1.5]" << endl;
    cout << lhs << " is equal to " << rhs << " " << boolalpha << lhs.isEqual(rhs) << " : should be false" << endl;
    dtuple3 testd3(-3,0,1.5 + epsilon/2);
    cout << lhs << " is equal to " << setprecision(11) << testd3 << " " << boolalpha << lhs.isEqual(testd3) << " : should be true" << endl;
    testd3.normalize();
    cout << lhs << " normalized is equal to " << testd3 << " : should be [ -0.89442719094 0 0.44721359562 ]" << endl;

    cout << endl;

    dtuple4 lhs4(1, 2, 3, 4);
    dtuple4 rhs4(-1, 2, 4, 6);

    lhs4.subtract(rhs4);
    cout << "lhs4 - rhs4 = " << lhs4 << " : should be [ 2 0 -1 -2]" << endl;
    lhs4.multiplyBy(1.5);
    cout << "lhs4.multiplyBy(1.5) = " << lhs4 << " : should be [ 3 0 -1.5, -3]" << endl;
    lhs4.negate();
    cout << "lhs4.negate() = " << lhs4 << " : should be [ -3 0 1.5 3]" << endl;
    cout << lhs4 << " is equal to " << rhs4 << " " << boolalpha << lhs4.isEqual(rhs4) << " : should be false" << endl;
    dtuple4 testd4(-3,0,1.5 + epsilon/2, 3);
    cout << lhs4 << " is equal to " << setprecision(11) << testd4 << " " << boolalpha << lhs4.isEqual(testd4) << " : should be true" << endl;
    testd4.normalize();
    cout << lhs << " normalized is equal to " << testd4 << " : should be [-0.66666666664 0 0.33333333343 0.66666666664 ]" << endl;

    cout << endl << "*********************" << endl;
    cout << "End Testing Utilities" << endl;
    cout << "*********************" << endl << endl;
}

ostream &operator<<(ostream &stream, dtuple3 &obj)
{
    stream << "[ ";
    stream << obj.x << " " << obj.y << " " << obj.z << " ";
    
    stream << "]";
    return stream;
}

ostream &operator<<(ostream &stream, dtuple4 &obj)
{
    stream << "[ ";
    stream << obj.x << " " << obj.y << " " << obj.z << " " << obj.w << " ";
    
    stream << "]";
    return stream;
}

ostream &operator<<(ostream &stream, ivec &obj)
{
    stream << "[ ";
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << obj[i] << " ";
    }
    
    stream << "]";
    return stream;
}

ostream &operator<<(ostream &stream, imatrix &obj)
{
    stream << "[ " << endl;
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << obj[i] << endl;
    }
    stream << " ]" << endl;

    return stream;
}

ostream &operator<<(ostream &stream, i8vec &obj)
{
    stream << "[ ";
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << obj[i] << " ";
    }
    
    stream << "]";
    return stream;
}

ostream &operator<<(ostream &stream, i8matrix &obj)
{
    stream << "[ " << endl;
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << obj[i] << endl;
    }
    stream << " ]" << endl;

    return stream;
}

ostream &operator<<(ostream &stream, colour &obj)
{
    stream << "( " << int(obj.red) << ", " << int(obj.green) << ", " << int(obj.blue) << ", " << int(obj.alpha) << ")";

    return stream;
}

ostream &operator<<(ostream &stream, colourvec &obj)
{
    stream << "[ ";
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << obj[i] << " ";
    }
    
    stream << "]";
    return stream;
}

ostream &operator<<(ostream &stream, colourmatrix &obj)
{
    stream << "[" << endl;
    for (uint32 i = 0; i < obj.size(); i++)
    {
        stream << "  " << obj[i] << endl;
    }
    stream << "]" << endl;

    return stream;
}

void dtuple3::negate()
{
    x = -x;
    y = -y;
    z = -z;
}

void dtuple3::multiplyBy(double scalingValue)
{
    x *= scalingValue;
    y *= scalingValue;
    z *= scalingValue;
}

void dtuple3::add(dtuple3 rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}

void dtuple3::subtract(dtuple3 rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

double dtuple3::magnitude()
{
    return sqrt(x*x+y*y+z*z);
}

void dtuple3::normalize()
{
    if ( x == 0 && y == 0 && z == 0)
        return;
    double scale = magnitude();
    x /= scale;
    y /= scale;
    z /= scale;
}

bool dtuple3::isEqual(dtuple3 rhs)
{
    return (fabs(x - rhs.x) < epsilon) && (fabs(y - rhs.y) < epsilon) && (fabs(z - rhs.z) < epsilon);
}

void dtuple4::negate()
{
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

void dtuple4::multiplyBy(double scalingValue)
{
    x *= scalingValue;
    y *= scalingValue;
    z *= scalingValue;
    w *= scalingValue;
}

void dtuple4::add(dtuple4 rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
}

void dtuple4::subtract(dtuple4 rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
}

double dtuple4::magnitude()
{
    return sqrt(x*x+y*y+z*z+w*w);
}

void dtuple4::normalize()
{
    if ( x == 0 && y == 0 && z == 0 && w == 0)
        return;
    double scale = magnitude();
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
}

bool dtuple4::isEqual(dtuple4 rhs)
{
    return (fabs(x - rhs.x) < epsilon) && (fabs(y - rhs.y) < epsilon) && (fabs(z - rhs.z) < epsilon) && (fabs(w - rhs.w) < epsilon);
}
