#include <RUtil2.h>
#include "Vec/Vec.h"

int main()
{
    #define test 1
    #define test2 3
    #if test==test2
    printf("yes\n");
    #else
    printf("no\n");
    #endif
    return 0;
}

