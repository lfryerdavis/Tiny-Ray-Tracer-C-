//
//  imgWriter.cpp
//  Tiny Ray Tracer
//
//  Created by Leyland Fryer-Davis on 2021-11-19.
//

#include "imgWriter.hpp"

using namespace std;

imgWriter::imgWriter(string outputFileName, int rows, int cols)
{
    mOutputFileName = outputFileName;
    mRows = rows;
    mCols = cols;
    mIsOutputOpen = false;
}

imgWriter::~imgWriter()
{
    if (!mIsOutputOpen)
        mOutputFile.close();
}

void imgWriter::updateImage(const colourmatrix &image)
{
    mImage = image;
    
    // file start from beginning - overwrite existing file
    writeHeader();
    
    // send out the image to the file
    for (int row = 0; row < mRows; row++)
    {
        mOutputFile << "# row " << row << endl;
        for (int col = 0; col < mCols; col++)
        {
            colour currColour = image[row][col];
            mOutputFile << int(currColour.red*255) << " " << int(currColour.green*255) << " " << int(currColour.blue*255) << endl;
        }
    }
}

void imgWriter::writeHeader()
{
    // clear the file
    if (!mIsOutputOpen) // check this way to make sure we don't have to determine if the file is in an undefined state
        mOutputFile.open(mOutputFileName);
    if (!mOutputFile.is_open())
        cout << "Error: could not open " << mOutputFileName << endl;
    mOutputFile << "P3" << endl;
    mOutputFile << int(mRows) << " " << int(mCols) << " " << "255" << endl;
}
