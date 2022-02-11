//
//  canvas.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2022-02-11.
//

#include "canvas.hpp"

canvas::canvas(uint32 rows, uint32 cols, uint32 depth)
{
    mRows = rows;
    mCols = cols;
    mDepth = depth;
    
    for (uint32 row = 0; row < mRows; row++)
    {
        colourvec imgRow;
        for (uint32 col = 0; col < mCols; col++)
        {
            colour temp(0, 0, 0, 0);
            imgRow.push_back(temp);
        }
        mImg.push_back(imgRow);
    }
}

