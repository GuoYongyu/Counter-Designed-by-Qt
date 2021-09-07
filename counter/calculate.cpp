#include "calculate.h"

Calculate::Calculate() {
    expression = "";
    precision = -1;
    filter = Filter();
}

Calculate::Calculate(string str, int prec):
    expression(str), precision(prec) {
    filter = Filter();
}

void Calculate::set_expression(string str) {
    expression = str;
}

void Calculate::set_presion(int prec) {
    precision = prec;
}

string Calculate::get_expression() {
    return expression;
}

double Calculate::simple_calculation(char op, double num1, double num2) {
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else {
        return num1 / num2;
    }
}

string double2string(const double& val, int prec)
{
    string str = to_string(val);
    std::stringstream ss;
    ss << setprecision(prec) << val;
    str = ss.str();
    return str;
}

string Calculate::get_value() {
    if (!is_legal_expression(expression)) {
        cout << "illegal expression" << endl;
        return "";
    }

    expression = decorate_expression(expression);
    filter = Filter(expression);

    stack<char> optr; // stack of operator
    stack<double> opnd; // stack of number
    optr.push('#'); // just for filling
    bool get = true; // wether perform get_next
    pair<string, StringType> next;
    while (filter.get_index() < int(expression.length()) || optr.top() != '#') {
        if (get)
            next = filter.get_next();

        if (next.second == NUM) {
            opnd.push(stod(next.first));
            get = true;
        } else {
            int p1 = op2int(optr.top());
            int p2 = op2int(next.first[0]);
            if (priority[p1][p2] == '<') {
                optr.push(next.first[0]);
                get = true;
            } else if (priority[p1][p2] == '=') { // ( match )
                optr.pop();
                get = true;
            } else {
                double num2 = opnd.top(); opnd.pop();
                double num1 = opnd.top(); opnd.pop();
                if (next.first[0] == '/' && num2 == 0.0) {
                    cout << "x / 0 is illegal";
                    return "0";
                }
                opnd.push(simple_calculation(optr.top(), num1, num2));
                optr.pop();
                get = false;
            }
        }
    }

    if (precision <= 0) {
        return to_string(int(opnd.top()));
    } else {
        int prec = precision;
        string res = to_string(opnd.top());
        if (res.find('.')) {
            prec = res.find('.') + 1 + precision;
        }
        return double2string(opnd.top(), prec);
    }
}
