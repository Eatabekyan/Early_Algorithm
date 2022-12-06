#include "Grammar.hpp"

size_t Grammar::Hash::operator()(const Grammar& grammar_) const {
    return hash<size_t>()(hash<string>()(grammar_.right)
        + hash<char>()(grammar_.left));
}
bool Grammar::operator==(const Grammar& other) const {
    return left == other.left && right == other.right;
}
Grammar::Grammar(char left, const string& right)
    : left(left), right(right) {}