////////////////////////////////////////////////////////////////////////////////
/// @file MAPReader.h
///     MAP file analysis and loading routines header.
/// @par Purpose:
///     Library for loading MAP file entries.
/// @author TQN <truong_quoc_ngan@yahoo.com>
/// @author TL <mefistotelis@gmail.com>
/// @date 2004.09.11 - 2018.11.08
/// @par  Copying and copyrights:
///     This program is free software; you can redistribute it and/or modify
///     it under the terms of the GNU General Public License as published by
///     the Free Software Foundation; either version 2 of the License, or
///     (at your option) any later version.
////////////////////////////////////////////////////////////////////////////////

#ifndef MAPREADER_H_
#define MAPREADER_H_

#include <cstdio>

#define MAXNAMELEN 512
#define INVALID_MAPFILE_SIZE (0xffffffff)

namespace MapFile
{

    typedef enum
    {
        NO_SECTION = 0,
        MSVC_MAP,
        BCCL_NAM_MAP,
        BCCL_VAL_MAP,
        WATCOM_MAP,
        GCC_MAP
    } SectionType;

    typedef enum
    {
        OPEN_NO_ERROR = 0,
        WIN32_ERROR,
        FILE_EMPTY_ERROR,
        FILE_BINARY_ERROR
    } MAPResult;

    typedef enum
    {
        SKIP_LINE = 0,
        INVALID_LINE,
        COMMENT_LINE,
        SYMBOL_LINE,
    } ParseResult;

    typedef struct
    {
        unsigned long seg;
#ifdef __EA64__
        unsigned long long addr;
#else
        unsigned long addr;
#endif
        char name[MAXNAMELEN + 1];
    } MAPSymbol;

    void closeMAP(const void *lpAddr, const size_t &dwSize);
    MAPResult openMAP(const char *lpszFileName, char *&lpMapAddr, size_t &dwSize);
    const char *skipSpaces(const char *pStart, const char *pEnd);
    const char *findEOL(const char *pStart, const char *pEnd);
    MapFile::SectionType recognizeSectionStart(const char *pLine, size_t lineLen);
    MapFile::SectionType recognizeSectionEnd(MapFile::SectionType secType, const char *pLine, size_t lineLen);
    MapFile::ParseResult parseMsSymbolLine(MapFile::MAPSymbol &sym, const char *pLine, size_t lineLen, size_t minLineLen, size_t numOfSegs);
    MapFile::ParseResult parseWatcomSymbolLine(MapFile::MAPSymbol &sym, const char *pLine, size_t lineLen, size_t minLineLen, size_t numOfSegs);
    MapFile::ParseResult parseGccSymbolLine(MapFile::MAPSymbol &sym, const char *pLine, size_t lineLen, size_t minLineLen, size_t numOfSegs);

};

// Converts address in linear form into seg:offs, using target executable sections list
#ifdef __EA64__
void linearAddressToSymbolAddr(MapFile::MAPSymbol &sym, unsigned long long linear_addr);
#else
void linearAddressToSymbolAddr(MapFile::MAPSymbol &sym, unsigned long linear_addr);
#endif

#endif
