//
//  utilities.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-09-18.
//

#include "utilities.hpp"

void testUtilities()
{
    // print dtuples
    dtuple3 dt3test(1, 2, 3);
    dtuple4 dt4test(1, 2, 3, 4);
    
    cout << "d3test = " << dt3test << " d4test = " << dt4test << endl;

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

dtuple3 dtuple3::add(dtuple3 lhs, dtuple3 rhs)
{
    dtuple3 result = lhs;
    
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;

    return result;
}

dtuple3 dtuple3::subtract(dtuple3 lhs, dtuple3 rhs)
{
    dtuple3 result = lhs;
    
    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;
    result.z = lhs.z - rhs.z;

    return result;
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

dtuple4 dtuple4::add(dtuple4 lhs, dtuple4 rhs)
{
    dtuple4 result = lhs;
    
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;
    result.w = lhs.w + rhs.w;

    return result;
}

dtuple4 dtuple4::subtract(dtuple4 lhs, dtuple4 rhs)
{
    dtuple4 result = lhs;
    
    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;
    result.z = lhs.z - rhs.z;
    result.w = lhs.w - rhs.w;

    return result;
}

