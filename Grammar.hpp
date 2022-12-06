#pragma once
#include <iostream>
#include <string>

using namespace std;

class Grammar {
public:
    struct Hash {
        size_t operator()(const Grammar& grammar_) const;
    };
    char left;
    string right;
    Grammar(char left, const string& right);
    bool operator==(const Grammar& other) const;
};

