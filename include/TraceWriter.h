#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class CTraceWriter
{
    ofstream tracer_{};
public:
    CTraceWriter(const string& filename, ios_base::openmode mode);
    bool open(const string& filename, ios_base::openmode mode);
    template <typename T>
    bool write(T&& elem);
    template <typename T, typename ... Ts>
    bool write(T&& t, Ts&& ... ts);
};
