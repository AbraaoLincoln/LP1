#ifndef COMMON_H
#define COMMON_H

struct Position
{
    unsigned i, j;
};

struct States
{
    unsigned lives{5};
    unsigned foods{0};
    unsigned level{1};
};

#endif