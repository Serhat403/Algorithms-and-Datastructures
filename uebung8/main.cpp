#include <iostream>
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
#include "BruteForce.hpp"
#include "BoyerMoore.hpp"

int main() {

    std::ifstream t("big.txt");
    std::string str;
    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(t)),
      std::istreambuf_iterator<char>());

    auto then = std::chrono::steady_clock::now();
    for (int i = 0; i < 10; ++i) {
        int index = -1;
        int count = -1;
        BruteForce bf("a", str);
        do {
            index = bf.Match(++index);
            count ++;
        }while (index != -1);
    }
    auto now = std::chrono::steady_clock::now();
    cout << "Time taken: " <<
         std::chrono::duration_cast<std::chrono::milliseconds>(now - then).count() << endl;

    //2
    auto then2 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10; ++i) {
        int index = -1;
        int count = -1;
        BruteForce bf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", str);
        do {
            index = bf.Match(++index);
            count ++;
        }while (index != -1);
    }
    auto now2 = std::chrono::steady_clock::now();
    cout << "Time taken: " <<
         std::chrono::duration_cast<std::chrono::milliseconds>(now2 - then2).count() << endl;


    BoyerMoore *test1 = new BoyerMoore("haus","raushaussein");
    //test1->Match(0);
    cout << test1->Match(0)<< endl;

    BoyerMoore *test2 = new BoyerMoore("haus","Ichkommenichtmehrnachhaus");
    //test1->Match(0);
    cout << test2->Match(0)<< endl;

    BoyerMoore *test3 = new BoyerMoore("haus","schmausRausLaushaus");
    //test1->Match(0);
    cout << test3->Match(0)<< endl;

    //3
    cout << "BoyarMooreStattBruteForce"<< endl;
    auto then3 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10; ++i) {
        int index = -1;
        int count = -1;
        BoyerMoore bf("a", str);
        do {
            index = bf.Match(++index);
            count ++;
        }while (index != -1);
    }
    auto now3 = std::chrono::steady_clock::now();
    cout << "Time taken: " <<
         std::chrono::duration_cast<std::chrono::milliseconds>(now3 - then3).count() << endl;
//4
    cout << "BoyarMooreStattBruteForce2"<< endl;
    auto then4 = std::chrono::steady_clock::now();
    for (int i = 0; i < 10; ++i) {
        int index = -1;
        int count = -1;
        BoyerMoore bf2("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", str);
        do {
            index = bf2.Match(++index);
            count ++;
        }while (index != -1);
    }
    auto now4 = std::chrono::steady_clock::now();
    cout << "Time taken: " <<
         std::chrono::duration_cast<std::chrono::milliseconds>(now4 - then4).count() << endl;

    //Was stellen Sie bei der Laufzeitanalyse der beiden Pattern und den beiden Algorithmen
    //(Boyer-Moore und Brute-Force) fest? Erklären Sie den Unterschied.

    // was man sagen kann ist das BoyarMoore mehr Zeit benötigt.
    // Boyar Moore braucht mehr Zeit wenn es nach einem Buchstaben sucht als wenn es nach mehreren Buchstaban sucht


}
