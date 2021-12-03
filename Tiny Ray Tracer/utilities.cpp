//
//  utilities.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-09-18.
//

#include "utilities.hpp"

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

