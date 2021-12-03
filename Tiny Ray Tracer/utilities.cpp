//
//  utilities.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-09-18.
//

#include "utilities.hpp"

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

    cout << endl;

    dtuple4 lhs4(1, 2, 3, 4);
    dtuple4 rhs4(-1, 2, 4, 6);

    lhs4.subtract(rhs4);
    cout << "lhs4 - rhs4 = " << lhs4 << " : should be [ 2 0 -1 -2]" << endl;
    lhs4.multiplyBy(1.5);
    cout << "lhs4.multiplyBy(1.5) = " << lhs4 << " : should be [ 3 0 -1.5, -3.5]" << endl;
    lhs4.negate();
    cout << "lhs4.negate() = " << lhs4 << " : should be [ -3 0 1.5 3.5]" << endl;

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

