#include "filter.h"

Filter::Filter() {
    expression = "";
    index = 0;
}

Filter::Filter(string str): expression(str), index(0) {}

bool is_legal_number(string num) {
    if (num[0] == '.') return false;

    int dot_cnt = 0; // count '.'
    for (auto ch: num) {
        if (ch == '.')
            dot_cnt++;
    }
    return dot_cnt <= 1;
}

int Filter::get_index() {
    return index;
}

pair<string, StringType> Filter::get_next() {
    // use lexical analysis algorithm
    int length = expression.length();
    if (index >= length) {
        return make_pair(string("\0"), END);
    }

    StringType type;
    string ret = "";
    if (is_digit(expression[index])) {
        while (index < length && is_digit(expression[index])) {
            ret += expression[index];
            index++;
        }
        if (is_legal_number(ret)) {
            type = NUM;
        } else {
            cout << "illegal number: " << ret << endl;
            type = ERR;
        }
    } else {
        ret = expression[index];
        index++;
        switch (ret[0]) {
        case '+':
            type = ADD;
            break;
        case '-':
            type = SUB;
            break;
        case '*':
            type = MUL;
            break;
        case '/':
            type = DIV;
            break;
        case '(':
            type = LBR;
            break;
        case ')':
            type = RBR;
            break;
        default:
            type = ERR;
            break;
        }
    }
    return make_pair(ret, type);
}
