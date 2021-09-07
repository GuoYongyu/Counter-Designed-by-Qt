#ifndef FILTER_H
#define FILTER_H

#include <public_variable.h>

class Filter
{
public:
    Filter();
    Filter(string str);
    ~Filter() {}

    pair<string, StringType> get_next(); // get next number or operator
    int get_index();

private:
    string expression;
    int index; // index of expression
};

#endif // FILTER_H
