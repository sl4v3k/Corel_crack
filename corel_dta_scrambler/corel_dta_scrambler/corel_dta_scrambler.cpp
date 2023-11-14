// corel_dta_scrambler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <Windows.h>

__int64 dta_file_read(const WCHAR* filename, int8_t* bufout)
{
    DWORD NumberOfBytesRead = 0;
    HANDLE hFile;

    hFile = CreateFileW(filename, GENERIC_READ, 1u, 0i64, 3u, 0x80u, 0i64);
    if (hFile != (HANDLE)-1i64)
    {
        if (!ReadFile(hFile, bufout, 0xC8u, &NumberOfBytesRead, 0i64))
            if (NumberOfBytesRead < 0xC8u)
                NumberOfBytesRead = 0;
        CloseHandle(hFile);
        
    }
    return NumberOfBytesRead;
}

__int64 dta_file_write(const WCHAR* filename, int8_t* bufout)
{
    DWORD NumberOfBytesWritten = 0;
    HANDLE hFile;

    hFile = CreateFileW(filename, GENERIC_WRITE, 2u, 0i64, 2u, 0x80u, 0i64);
    if (hFile != (HANDLE)-1i64)
    {
        if (!WriteFile(hFile, bufout, 0xC8u, &NumberOfBytesWritten, 0i64))
            if (NumberOfBytesWritten < 0xC8u)
                NumberOfBytesWritten = 0;
        CloseHandle(hFile);

    }
    return NumberOfBytesWritten;
}

int32_t seed_shuffle(int32_t a2)
{
    int v3; // [rsp+0h] [rbp-18h]

    v3 = 16807 * (a2 % 0x1F31D) - 0xB14 * (a2 / 0x1F31D);
    if (v3 <= 0)
        return (unsigned int)(v3 + 0x7FFFFFFF);
    else
        return (unsigned int)(16807 * (a2 % 0x1F31D) - 0xB14 * (a2 / 0x1F31D));
}


uint32_t checksum(int8_t *buf, uint32_t len)
{
    int32_t v4 = 0x56780001;


    for (int i = 0; i < len; i++)
    {
        v4 = (11 * (int32_t)(buf[i])) + (13 * v4);
    }

    return v4;
}

#define DTABUFSIZE 0xC8

void descramble(char *dta_fileName)
{
    int8_t bufout[DTABUFSIZE];
    int32_t seed = 0;
    uint32_t chksum = 0;
    uint32_t calc_chksum = 0;

    const size_t WCHARBUF = 1024;
    wchar_t  fileName[WCHARBUF];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, dta_fileName, -1, fileName, WCHARBUF);

    if (dta_file_read(fileName, bufout) > 0)
    {
        seed = ((int32_t*)bufout)[0];
        chksum = ((uint32_t*)bufout)[(DTABUFSIZE / sizeof(uint32_t)) - 1];
        std::cout << "initial seed -> " << std::dec << seed << ", 0x" << std::hex << std::setw(8) << std::setfill('0') << seed << std::endl;
        std::cout << "check sum in file -> " << std::dec << chksum << ", 0x" << std::hex << std::setw(8) << std::setfill('0') << chksum << std::endl;

        for (uint32_t i = 4; i < 0xC4; i++)
        {
            seed = seed_shuffle(seed);
            bufout[i] ^= (uint8_t)((seed >> 16) & 0xff);
        }

        ((uint32_t*)bufout)[(DTABUFSIZE / sizeof(uint32_t)) - 1] = 0;

        calc_chksum = checksum(bufout, DTABUFSIZE);
        std::cout << "calculated check sum -> " << std::dec << calc_chksum << ", 0x" << std::hex << std::setw(8) << std::setfill('0') << calc_chksum << std::endl;

        if (chksum != calc_chksum)
        {
            std::cout << "ERROR: wrong checksum" << std::endl;
        }
        else
        {
            dta_file_write(L"out.dta", bufout);
            std::cout << "SUCCESS: checkusm OK, data written to -> out.dta" << std::endl;
        }
    }
    else
        std::cout << "ERROR: wrong dta file, expected size -> 0xC8" << std::endl;
}


void scramble(char* dta_fileName)
{
    int8_t bufout[DTABUFSIZE];
    int32_t seed = 0;
    uint32_t calc_chksum = 0;

    const size_t WCHARBUF = 1024;
    wchar_t  fileName[WCHARBUF];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, dta_fileName, -1, fileName, WCHARBUF);

    if (dta_file_read(fileName, bufout) > 0)
    {
        seed = ((int32_t*)bufout)[0];
        if (seed == 0)
        {
            seed = GetTickCount() >> 4; //this is what Corel is doing

            if (seed == 0)
            {
                seed = 0x1234567; //this is what Corel is doing
            }
        }

        std::cout << "initial seed -> " << std::dec << seed << ", 0x" << std::hex << std::setw(8) << std::setfill('0') << seed << std::endl;

        ((uint32_t*)bufout)[(DTABUFSIZE / sizeof(uint32_t)) - 1] = 0;

        calc_chksum = checksum(bufout, DTABUFSIZE);
        std::cout << "calculated check sum -> " << std::dec << calc_chksum << ", 0x" << std::hex << std::setw(8) << std::setfill('0') << calc_chksum << std::endl;


        for (uint32_t i = 4; i < 0xC4; i++)
        {
            seed = seed_shuffle(seed);
            bufout[i] ^= (uint8_t)((seed >> 16) & 0xff);
        }

        ((uint32_t*)bufout)[(DTABUFSIZE / sizeof(uint32_t)) - 1] = calc_chksum;
        dta_file_write(L"out.dta", bufout);
        std::cout << "SUCCESS: checkusm set, data written to -> out.dta" << std::endl;
    }
    else
        std::cout << "ERROR: wrong dta file, expected size -> 0xC8" << std::endl;
}

void usage()
{
    std::cout << "usage -> descramble: corel_dta_scrambler  0 <scrambled_dta_filename>" << std::endl;
    std::cout << "usage -> scrable:    corel_dta_scrambler  1 <descrambled_dta_filename>" << std::endl;
}

int main(int argc, char* argv[])
{


    if (argc == 3)
    {
        if (argv[1][0] == 0x30)
            descramble(argv[2]);
        else
            if (argv[1][0] == 0x31)
                scramble(argv[2]);
            else
                usage();
    }
    else
    {
        usage();
    }

}

