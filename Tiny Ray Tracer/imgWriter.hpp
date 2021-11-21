//
//  pngWriter.hpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-11-19.
//

#ifndef imgWriter_hpp
#define imgWriter_hpp

#include <iostream>
#include <string>
#include <fstream>
#include "utilities.hpp"

using namespace std;

class imgWriter
{
public:
    imgWriter(string outputFileName, int rows, int cols);
    ~imgWriter();
    
    void updateImage(const colourmatrix &image);
    
private:
    void writeHeader();
    
    string mOutputFileName;
    ofstream mOutputFile;
    int mRows;
    int mCols;
    colourmatrix mImage;
    bool mIsOutputOpen;
};

#endif /* imgWriter_hpp */
