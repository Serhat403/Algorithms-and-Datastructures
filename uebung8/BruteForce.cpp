//
// Created by Serhat on 29.12.2021.
//

#include "BruteForce.hpp"
#include <fstream>
#include <streambuf>
#include <chrono>
#include <algorithm>
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
BruteForce::BruteForce(string pattern, string text) {
    this->pattern=pattern;
    this->text=text;
}
// wird nicht benötigt weil keine dynamisch ressourcen allokation
BruteForce::~BruteForce() {}

int BruteForce::Match(int startIndex) {
    int zaehlerPattern=pattern.length();
    int zaehlerText=text.length();
    for(int i = startIndex;i<(zaehlerText-zaehlerPattern);i++){
        int j;
        for(j=0;j<zaehlerPattern;j++);{
                if(text[j+i]!=pattern[j])
                    return -1;
        }
        if(zaehlerPattern==j)
            return i;
    }
    //vlt hier auch return -1
    return -1;
}
