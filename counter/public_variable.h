#ifndef PUBLIC_VARIABLE_H
#define PUBLIC_VARIABLE_H

#include <bits/stdc++.h>

using namespace std;

enum StringType {
    NUM, ADD, SUB, MUL, DIV, LBR, RBR, ERR, END
}; // END is the end of expression

const char priority[7][7] = {
    /* +    -    *    /    (    )    # */
     {'>', '>', '<', '<', '<', '>', '>'},
     {'>', '>', '<', '<', '<', '>', '>'},
     {'>', '>', '>', '>', '<', '>', '>'},
     {'>', '>', '>', '>', '<', '>', '>'},
     {'<', '<', '<', '<', '<', '=', '>'},
     {'>', '>', '>', '>', '=', '>', '>'},
     {'<', '<', '<', '<', '<', ' ', '='}
};

string type2op(StringType type);

int op2int(char op);

int get_operator_priority(StringType type);

bool is_digit(char ch);

bool is_operator(char ch);

bool is_legal_expression(string str);

string decorate_expression(string str);

#endif // PUBLIC_VARIABLE_H
