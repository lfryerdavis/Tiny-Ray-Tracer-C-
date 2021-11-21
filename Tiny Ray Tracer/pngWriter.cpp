//
//  pngWriter.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-11-01.
//

#include "pngWriter.hpp"

using namespace std;

pngWriter::pngWriter(string outputFileName, int rows, int cols)
{
    mOutputFileName = outputFileName;
    mRows = rows;
    mCols = cols;

    // mImage is in an undefined state at this point
    
    mOutputFile.open(outputFileName, ios::binary);
    if (!mOutputFile.is_open())
        cout << "Error: could not open " << mOutputFileName << endl;
    
    writeHeader();
}

pngWriter::~pngWriter()
{
    mOutputFile.close();
}

void pngWriter::updateImage(const colourmatrix &image)
{
    mImage = image;
    
    // file start from beginning - overwrite existing file
    writeHeader();
    
    // send out the image to the file
}

void pngWriter::writeHeader()
{
    mOutputFile.put(0x89);
    mOutputFile.put(0x50);
    mOutputFile.put(0x4E);
    mOutputFile.put(0x47);
    mOutputFile.put(0x0D);
    mOutputFile.put(0x0A);
    mOutputFile.put(0x1A);
    mOutputFile.put(0x0A);
}
