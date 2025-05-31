#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm> //sort funkcijai
#include <random>
#include <fstream>
#include <chrono>
#include <deque> //v1.0
#include <list>
#include <iterator> //naudosiu std::advance list iteraciju skaiciavime
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::stoi;
using std::to_string;
using std::exception;
using std::runtime_error;
using std::cerr;
using std::sort;
using std::swap;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::ifstream;
using std::ofstream;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::filesystem::create_directories; //kad galetu sukurti student_files aplanka

std::mt19937 gen(std::random_device{}()); // atsitiktiniu skaiciu generatorius, sugeneruotas viena karta kad kaskart nereiktu sukurti atskiro mt19937

int randominis()
{
    static std::uniform_int_distribution<int> distrib(0, 10); // paskirsto sugeneruotus skaicius vienodu desningumu
    return distrib(gen);
}

bool arskaicius(string a) // tikrina ar ivestas string yra skaicius
{
    try{
        stoi(a); // bandome konvertuoti string i int
        return true;
    }
    catch (const std::invalid_argument&) {
        return false; // jei konvertavimas nepavyko, graziname false
    }
}

high_resolution_clock::time_point startTime;//globalus kintamasis laiko matavimui

void startTimer() {
    startTime = high_resolution_clock::now();
}

void stopTimer() {
    auto stopTime = high_resolution_clock::now();
    duration<double> duration = (stopTime - startTime);
    cout << "Laikas: " << fixed << setprecision(5) << duration.count() << " sekundziu" << endl;
}

#endif // MYLIB_H_INCLUDED
