//
// Created by Serhat on 29.12.2021.
//

#ifndef UEBUNG8_BOYERMOORE_HPP
#define UEBUNG8_BOYERMOORE_HPP

#include <fstream>
#include <streambuf>
#include <chrono>
#include <algorithm>
#include <utility>

class BoyerMoore {
    std:: string pattern;
    std:: string text;
    int last[256]; // exactly as long as the alphabet
    int *match; // exactly as long as the pattern

    void calculateLast() {
        int zaehler;
        for (zaehler = 0; zaehler < 256; zaehler++){
            last[zaehler] = -1;
        }
        for (zaehler = 0; zaehler < pattern.size(); zaehler++){
            last[(int) pattern[zaehler]] = zaehler;
        }
    }

    void calculateMatchTable();

public:
    BoyerMoore(std:: string pattern,std:: string text) {
        this->pattern=std::move(pattern);
        this->text=std::move(text);
    }
    // hier wird new benützt deswegen einfach pattern und text auf null
    ~BoyerMoore() {
        this->pattern=nullptr;
        this->text= nullptr;
    }

    int Match(int startIndex) {
        int zaehlerPattern = pattern.size();
        int zaehlerText = text.size();
        calculateLast();
        int uStart = startIndex;

        while(uStart <= (zaehlerText - zaehlerPattern)){
                int zaehler = zaehlerPattern - 1;
                while(zaehler >= 0 && pattern[zaehler] == text[uStart + zaehler]){
                    zaehler--;
                }
                if (zaehler < 0)
                {
                    return uStart;
                }
                else{
                    uStart += std::max(1, zaehler - last[text[uStart + zaehler]]);
                }
        }
        return -1;
    }
};

#endif //UEBUNG8_BOYERMOORE_HPP
