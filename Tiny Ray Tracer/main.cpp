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
#include "canvas.hpp"

using namespace std;

uint32 rows = 800;
uint32 cols = 1200;
uint8 depth = 8;

int main(int argc, const char * argv[])
{
    // testUtilities();

    string filename = "testOutput.pbm";
    canvas localCanvas(rows, cols, depth);
    
    for (uint32 row = 0; row < rows; row++)
    {
        for (uint32 col = 0; col < cols; col++)
        {
            colour temp((double) row / (double) rows, (double) col / (double) cols, (double) row / (double) rows, 0);
            localCanvas.mImg[row][col] = temp;
        }
    }
    
    // cout << img << endl;
    imgWriter imgWrite(filename, rows, cols);
    imgWrite.updateImage(localCanvas.mImg);

    return 0;
}
