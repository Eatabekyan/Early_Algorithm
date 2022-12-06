#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include "Grammar.hpp"
#include "Situation.hpp"


using namespace std;



class EarleyAnalyse {
public:
    EarleyAnalyse(const vector<Grammar>& grammars, char first_symbol);
    bool CompriseSymbol(const string& symbol);
private:
    bool Build(char first_symbol, const string& symbol);
    void CompletePredict(int config_index);
    char first_symbol;
    unordered_map<char, unordered_set<Grammar, Grammar::Hash>> grammar_set;
    vector<unordered_set<Situation, Situation::Hash>> configs;
};

class Earley {
public:
    static void Predict(unordered_map<char, unordered_set<Grammar, Grammar::Hash>>& grammar_set,
        vector<unordered_set<Situation, Situation::Hash>>& configs, int config_index);
    static void Scan(vector<unordered_set<Situation, Situation::Hash>>& configs, char next_symbol, int config_index);
    static void Complete(vector<unordered_set<Situation, Situation::Hash>>& configs, int config_index);
    static void SetRule(unordered_map<char, unordered_set<Grammar, Grammar::Hash>>& grammar_set,
        const vector<Grammar>& grammars);
};
