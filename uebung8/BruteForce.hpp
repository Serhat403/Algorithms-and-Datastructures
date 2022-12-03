//
// Created by Serhat on 29.12.2021.
//

#ifndef UEBUNG8_BRUTEFORCE_HPP
#define UEBUNG8_BRUTEFORCE_HPP

#include <fstream>
#include <streambuf>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <streambuf>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

using namespace std;

class BruteForce {

    //std::string pattern;
    std::string text;
    std::basic_string<char> pattern;

public:

    BruteForce(std::string pattern,std::string text);
    ~BruteForce();
    int Match(int startIndex);
};

#endif //UEBUNG8_BRUTEFORCE_HPP
