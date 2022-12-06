#include "Situation.hpp"

size_t Situation::Hash::operator()(const Situation& situation_) const {
    return hash<size_t>()(hash<string>()(situation_.right) + hash<char>()(situation_.left)
        + hash<int>()(situation_.cur_point + situation_.start));
}

Situation::Situation(char left, const string& right, int start, int index = 0)
    : Grammar(left, right), start(start), cur_point(index) {}

Situation::Situation(const Grammar& grammar, int start, int index) :
    Grammar(grammar), start(start), cur_point(index) {}

bool Situation::operator==(const Situation& other) const {
    return left == other.left && right == other.right
        && start == other.start && cur_point == other.cur_point;
} 