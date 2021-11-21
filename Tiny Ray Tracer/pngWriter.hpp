//
//  pngWriter.hpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-11-01.
//

#ifndef pngWriter_hpp
#define pngWriter_hpp

#include <iostream>
#include <string>
#include <fstream>
#include "utilities.hpp"

using namespace std;

class pngWriter
{
public:
    pngWriter(string outputFileName, int rows, int cols);
    ~pngWriter();
    
    void updateImage(const colourmatrix &image);
    
private:
    void writeHeader();
    
    string mOutputFileName;
    ofstream mOutputFile;
    int mRows;
    int mCols;
    colourmatrix mImage;
};

#endif /* pngWriter_hpp */
