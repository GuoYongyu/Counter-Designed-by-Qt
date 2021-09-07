#ifndef CALCULATE_H
#define CALCULATE_H

#include "filter.h"

class Calculate
{
public:
    Calculate();
    Calculate(string str, int prec);
    ~Calculate() {}

    string get_expression();
    double simple_calculation(char op, double num1, double num2);
    string get_value();
    void set_expression(string str);
    void set_presion(int prec);

private:
    string expression;
    int precision;
    Filter filter;
};

#endif // CALCULATE_H
