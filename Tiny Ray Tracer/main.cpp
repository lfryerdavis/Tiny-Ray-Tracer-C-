//
//  main.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-06-15.
//

#include <iostream>
#include <vector>
#include "utilities.hpp"
#include "imgWriter.hpp"

using namespace std;

uint32 rows = 4;
uint32 cols = 8;

colourmatrix img;
colour black(0,0,0,0);

int main(int argc, const char * argv[])
{
    for (uint32 row = 0; row < rows; row++)
    {
        colourvec imgRow;
        for (uint32 col = 0; col < cols; col++)
        {
            colour temp = black;
            imgRow.push_back(temp);
        }
        img.push_back(imgRow);
    }
    
    cout << img << endl;
    
    imgWriter imgWrite("testFile.pbm", rows, cols);
    imgWrite.updateImage(img);
    
    return 0;
}
