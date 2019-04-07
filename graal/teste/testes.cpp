#include <iostream>
#include <iterator>
#include "../include/graal.h"

bool cmp1(void *a, void *b)
{
    byte *pa = (byte *)b;
    byte *pb = (byte *)b;

    return *pa < *pb;
}

int main(void)
{
    int A[]{1,2,3,4,5};
    auto result = (int *) graal::min(std::begin(A), std::end(A), sizeof(int), cmp1);
    std::cout << result << std::endl;
    return 0;
}