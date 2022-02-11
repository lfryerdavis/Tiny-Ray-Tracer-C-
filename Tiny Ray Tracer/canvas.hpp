//
//  canvas.hpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2022-02-11.
//

#ifndef canvas_hpp
#define canvas_hpp

#include "utilities.hpp"
#include "imgWriter.hpp"

class canvas
{
public:
    canvas(uint32 rows, uint32 cols, uint32 depth);
    colourmatrix mImg;
private:
    uint32 mRows;
    uint32 mCols;
    uint8 mDepth;
};

#endif /* canvas_hpp */
