//
//  ChessFile.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-15.
//

#include "ChessFile.hpp"

using namespace Chess;
using namespace std;

vector<File> Chess::allFiles()
{
    vector<File> files{
        File::A,
        File::B,
        File::C,
        File::D,
        File::E,
        File::F,
        File::G,
        File::H};
    return files;
}

vector<File> Chess::allFilesExcept(const File file)
{
    vector<File> files = allFiles();
    
    for (auto fileIterator = files.begin(); fileIterator != files.end(); ++fileIterator)
    {
        if (file == *fileIterator)
        {
            files.erase(fileIterator);
            return files;
        }
    }
    
    return files;
}

vector<File> Chess::allFilesIncreasingGreaterThan(const File file)
{
    vector<File> files = allFiles();
    vector<File> resultFiles;
    bool reachedStartPoint = false;
    
    for (auto fileIterator = files.begin(); fileIterator != files.end(); ++fileIterator)
    {
        if (reachedStartPoint)
        {
            resultFiles.push_back(*fileIterator);
        }
        if (file == *fileIterator)
        {
            reachedStartPoint = true;
        }
    }
    
    return resultFiles;
}

vector<File> Chess::allFilesDecreasingLessThan(const File file)
{
    vector<File> files = allFiles();
    vector<File> resultFiles;
    bool reachedStartPoint = false;
    
    for (auto fileIterator = files.rbegin(); fileIterator != files.rend(); ++fileIterator)
    {
        if (reachedStartPoint)
        {
            resultFiles.push_back(*fileIterator);
        }
        if (file == *fileIterator)
        {
            reachedStartPoint = true;
        }
    }
    
    return resultFiles;
}

