#include "infix2postfix.h"

Infix2Postfix::Infix2Postfix() {
    infix = "";
    postfix = "";
    filter = Filter();
}

Infix2Postfix::Infix2Postfix(string str) {
    infix = str;
    postfix = "";
    filter = Filter();
}

void Infix2Postfix::set_infix(string str) {
    infix = str;
}

string Infix2Postfix::get_infix() {
    return infix;
}

string Infix2Postfix::get_postfix() {
    return postfix;
}

string Infix2Postfix::to_postfix() {
    if (!is_legal_expression(infix)) {
        cout << "illegal expression" << endl;
        return "";
    }

    infix = decorate_expression(infix);
    filter = Filter(infix);

    stack<StringType> op;
    pair<string, StringType> next;
    while (true) {
        next = filter.get_next();
        if (next.second == ERR) {
            cout << "error" << endl;
            postfix.clear();
            break;
        } else if (next.second == END) {
            break;
        } else if (next.second == NUM) {
            postfix += next.first + " ";
        } else if (next.second == LBR) {
            op.push(next.second);
        } else if (next.second != RBR) {
            if (op.empty()) {
                op.push(next.second);
            } else {
                while (!op.empty()) {
                    StringType type = op.top();
                    if (get_operator_priority(next.second) <= get_operator_priority(type)) {
                        postfix += type2op(type) + " ";
                        op.pop();
                    } else {
                        break;
                    }
                }
                op.push(next.second);
            }
        } else {
            while (op.top() != LBR) {
                postfix += type2op(op.top()) + " ";
                op.pop();
            }
            op.pop();
        }
    }
    while (!op.empty()) {
        postfix += type2op(op.top()) + " ";
        op.pop();
    }
    return postfix;
}
