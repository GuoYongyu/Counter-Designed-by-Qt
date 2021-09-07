#include "public_variable.h"

string type2op(StringType type) {
    // convert StringType to respective operator
    switch (type) {
    case ADD:
        return "+";
    case SUB:
        return "-";
    case MUL:
        return "*";
    case DIV:
        return "/";
    case LBR:
        return "(";
    case RBR:
        return ")";
    default:
        return "\0";
    }
}

int op2int(char op) {
    switch (op) {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '#':
        return 6;
    default:
        return -1;
    }
}

int get_operator_priority(StringType type) {
    int level = 0;
    switch(type) {
        case LBR:
            level = 1;
            break;
        case ADD:
        case SUB:
            level = 2;
            break;
        case MUL:
        case DIV:
            level = 3;
            break;
        default:
            break;
    }
    return level;
}

bool is_digit(char ch) {
    return ('0' <= ch && ch <= '9') || ch == '.';
}

bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

bool is_legal_expression(string str) {
    // use parenthesis matching algorithm
    if (str[0] == '*' || str[0] == '/') {
        return false; // *1+2 is wrong
    }
    stack<char> check; // match bracket
    for (unsigned int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            check.push('(');
        } else if (str[i] == ')') {
            if (check.empty()) {
                return false; // no ( match )
            } else {
                check.pop();
            }
        } else if (i < str.length() - 1 && is_operator(str[i]) && is_operator(str[i+1])
                   && str[i] != '(' && str[i] != ')') {
            return false; // 1++1 or 1+*1 or (1+2*) is wrong
        } else if (i < str.length() - 1 && is_operator(str[i]) && is_operator(str[i+1])
                   && str[i] == '('&& str[i+1] == '*' && str[i+1] == '/') {
            return false; // (*1+2) is wrong
        }
    }
    if (!check.empty()) {
        return false; // no ) match (
    } else {
        return true;
    }
}

string decorate_expression(string str) {
    // -1*2 -> 0-1*2
    // owing to do not consider 1*-2, so converting -1*2 to (-1*2) is unnecessary
    string ret = "";
    if (str[0] == '-' || str[0] == '+') {
        ret = "0";
    }
    unsigned int i = 0;
    while (i < str.length()) {
        if (i + 1 < str.length() && str[i] == '(' && (str[i+1] == '-' || str[i+1] == '+')) {
            ret += str[i];
            ret += "0"; // ret += str[i] + "0" is useless
        } else {
            ret += str[i];
        }
        i++;
    }
    return ret;
}
