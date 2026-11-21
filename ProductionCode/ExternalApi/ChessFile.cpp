//
//  ChessFile.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-15.
//

#include "ChessFile.hpp"

using namespace Chess;

std::vector<File> Chess::allFiles()
{
    std::vector<File> files{
        File::A,
        File::B,
        File::C,
        File::D,
        File::E,
        File::F,
        File::G,
        File::H};
    return files;
};

std::vector<File> Chess::allFilesExcept(const File file)
{
    std::vector<File> files = allFiles();
    
    for (auto fileIterator = files.begin(); fileIterator != files.end(); ++fileIterator)
    {
        if (file == *fileIterator)
        {
            files.erase(fileIterator);
            return files;
        }
    }
    
    return files;
};
