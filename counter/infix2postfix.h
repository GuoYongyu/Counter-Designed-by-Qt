#ifndef INFIX2POSTFIX_H
#define INFIX2POSTFIX_H

#include "filter.h"

class Infix2Postfix
{
public:
    Infix2Postfix();
    Infix2Postfix(string str);
    ~Infix2Postfix() {}

    string to_postfix();
    string get_infix();
    string get_postfix();
    void set_infix(string str);

private:
    string infix;
    string postfix;
    Filter filter;
};

#endif // INFIX2POSTFIX_H
