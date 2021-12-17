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

uint32 rows = 800;
uint32 cols = 1200;

colourmatrix img;
colour black(0, 0, 0);
colour white(1, 1, 1);
colour midgrey(0.5, 0.5, 0.5);

int main(int argc, const char * argv[])
{
    // testUtilities();
    
    for (uint32 row = 0; row < rows; row++)
    {
        colourvec imgRow;
        for (uint32 col = 0; col < cols; col++)
        {
            colour temp((double) row / (double) rows, (double) col / (double) cols, (double) row / (double) rows, 0);
            imgRow.push_back(temp);
        }
        img.push_back(imgRow);
    }
    
    // cout << img << endl;
    
    imgWriter imgWrite("testFile.pbm", rows, cols);
    imgWrite.updateImage(img);
    
    return 0;
}
