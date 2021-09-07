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

#define NUM_0_IMG ":/image/num_0.png"
#define NUM_1_IMG ":/image/num_1.png"
#define NUM_2_IMG ":/image/num_2.png"
#define NUM_3_IMG ":/image/num_3.png"
#define NUM_4_IMG ":/image/num_4.png"
#define NUM_5_IMG ":/image/num_5.png"
#define NUM_6_IMG ":/image/num_6.png"
#define NUM_7_IMG ":/image/num_7.png"
#define NUM_8_IMG ":/image/num_8.png"
#define NUM_9_IMG ":/image/num_9.png"

#define OP_ADD_IMG ":/image/op_add.png"
#define OP_SUB_IMG ":/image/op_sub.png"
#define OP_MUL_IMG ":/image/op_mul.png"
#define OP_DIV_IMG ":/image/op_div.png"
#define OP_LBR_IMG ":/image/op_lbr.png"
#define OP_RBR_IMG ":/image/op_rbr.png"
#define OP_EQU_IMG ":/image/op_equ.png"
#define OP_CLEAR_IMG ":/image/op_clear.jpg"
#define OP_POSTFIX_IMG ":/image/op_postfix.jpg"

const int btn_width = 160;
const int btn_height = 200;
const int edge_size = 40;
const int scrn_width = 4 * btn_width + 3 * edge_size;
const int scrn_height = 100;

#endif // PUBLIC_VARIABLE_H
