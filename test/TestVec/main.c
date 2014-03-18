#include <RUtil2.h>
#include "Vec/Vec.h"

int main()
{
    float* a, *b;
    a = RAlloc_Float(1024);
    b = RAlloc_Float(1024);
    
    int i;
    for(i = 0; i < 1024; i ++)
        a[i] = 0.1f * i;
    
    for(i = 0; i < 1000000; i ++)
    {
        RFNL_VCopy_Gnrc_Float(b, a, 1024);
        /*
        int j;
        for(j = 0; j < 1024; j ++)
            b[j] += a[j];
        */
        RFNL_VAdd_Gnrc_Float(b, b, a, 1024);
    }
    
    for(i = 0; i < 1024; i ++)
        printf("%.4d %.9f\n", i, b[i]);
    
    RFree(a, b);
    return 0;
}

