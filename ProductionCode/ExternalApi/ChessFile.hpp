//
//  ChessFile.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-14.
//
#pragma once

#include <vector>

namespace Chess
{
enum class File : uint8_t
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
};

std::vector<File> allFiles();
std::vector<File> allFilesExcept(const File file);
std::vector<File> allFilesIncreasingGreaterThan(const File file);
std::vector<File> allFilesDecreasingLessThan(const File file);
}
