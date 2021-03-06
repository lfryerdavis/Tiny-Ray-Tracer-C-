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

    dtuple3 lhs2(1, -2, 3), rhs2(3, 0, 1);
    dtuple3 cross;
    cross = lhs2.cross(rhs2);
    cout << lhs2 << " . " << rhs2 << " equals " << lhs2.dot(rhs2) << " : should be 6" << endl;
    cout << lhs2 << " x " << rhs2 << " equals " << cross << " : should be [ -2 8 6 ]" << endl;
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
    dtuple4 lhs42(1, -2, 3, 2), rhs42(3, 0, 1, -1);
    cout << lhs42 << " . " << rhs42 << " equals " << lhs42.dot(rhs42) << " : should be 4" << endl;

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
    stream << "( " << int(obj.red*255) << ", " << int(obj.green*255) << ", " << int(obj.blue*255) << ", " << int(obj.alpha*255) << ")";

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

ostream &operator<<(ostream &stream, matrix3x3double &obj)
{
    stream << "[ [" << endl;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            stream << "  " << obj.mValues[i][j] << endl;
        }
        stream << "]" << endl;
    }
    stream << "]" << endl;

    return stream;
}

ostream &operator<<(ostream &stream, matrix4x4double &obj)
{
    stream << "[ [" << endl;
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            stream << "  " << obj.mValues[i][j] << endl;
        }
        stream << "]" << endl;
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

double dtuple3::dot(dtuple3 rhs)
{
    return x*rhs.x + y*rhs.y + z*rhs.z;
}

dtuple3 dtuple3::cross(dtuple3 rhs)
{
    dtuple3 result(0,0,0);
    result.x = y*rhs.z - z*rhs.y;
    result.y = z*rhs.x - x*rhs.z;
    result.z = x*rhs.y - y*rhs.x;

    return result;
}

double dtuple3::operator[](int i)
{
    if (i == 0)
        return x;
    if (i == 1)
        return y;
    if (i == 3)
        return z;
    return NAN;
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

double dtuple4::dot(dtuple4 rhs)
{
    return x*rhs.x + y*rhs.y + z*rhs.z + w*rhs.w;
}

double dtuple4::operator[](int i)
{
    if (i == 0)
        return x;
    if (i == 1)
        return y;
    if (i == 3)
        return z;
    if (i == 4)
        return w;
    return NAN;
}

matrix3x3double::matrix3x3double(double values[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mValues[row][col] = values[row][col];
        }
    }
}
    
void matrix3x3double::negate()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mValues[row][col] = -mValues[row][col];
        }
    }
}

void matrix3x3double::multiplyBy(double scalingValue)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mValues[row][col] *= scalingValue;
        }
    }
}

dtuple3 matrix3x3double::multiplyBy(dtuple3 rhs)
{
    dtuple3 retVal;
    vector<double> result;
    
    for (int row = 0; row < 3; row++)
    {
        double sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += mValues[row][col] * rhs[row];
        }
        result.push_back(sum);
    }
    retVal.x = result[0];
    retVal.y = result[1];
    retVal.z = result[2];
    
    return retVal;
}

void matrix3x3double::multiplyBy(matrix3x3double rhs)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            double sum = 0;
            for (int k = 0; k < 3; k++)
                sum += mValues[row][k] * rhs.mValues[k][col];
                
            mValues[row][col] = sum;
        }
    }
}

void matrix3x3double::add(matrix3x3double rhs)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mValues[row][col] += rhs.mValues[row][col];
        }
    }
}

void matrix3x3double::subtract(matrix3x3double rhs)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mValues[row][col] -= rhs.mValues[row][col];
        }
    }
}

bool matrix3x3double::isEqual(matrix3x3double rhs)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (mValues[row][col] != rhs.mValues[row][col])
                return false;
        }
    }

    return true;
}

matrix4x4double::matrix4x4double(double values[4][4])
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            mValues[row][col] = values[row][col];
        }
    }
}
    
void matrix4x4double::negate()
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            mValues[row][col] = -mValues[row][col];
        }
    }
}

void matrix4x4double::multiplyBy(double scalingValue)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            mValues[row][col] *= scalingValue;
        }
    }
}

dtuple4 matrix4x4double::multiplyBy(dtuple4 rhs)
{
    dtuple4 retVal;
    vector<double> result;
    
    for (int row = 0; row < 4; row++)
    {
        double sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += mValues[row][col] * rhs[row];
        }
        result.push_back(sum);
    }
    retVal.x = result[0];
    retVal.y = result[1];
    retVal.z = result[2];
    retVal.w = result[3];

    return retVal;
}

void matrix4x4double::multiplyBy(matrix4x4double rhs)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            double sum = 0;
            for (int k = 0; k < 4; k++)
                sum += mValues[row][k] * rhs.mValues[k][col];
                
            mValues[row][col] = sum;
        }
    }
}

void matrix4x4double::add(matrix4x4double rhs)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            mValues[row][col] += rhs.mValues[row][col];
        }
    }
}

void matrix4x4double::subtract(matrix4x4double rhs)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            mValues[row][col] -= rhs.mValues[row][col];
        }
    }
}

bool matrix4x4double::isEqual(matrix4x4double rhs)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (mValues[row][col] != rhs.mValues[row][col])
                return false;
        }
    }

    return true;
}

