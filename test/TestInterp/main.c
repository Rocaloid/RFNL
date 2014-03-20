#include <RUtil2.h>
#include <math.h>
#include "Interp/Interp.h"

void RFNL_Use();
int main()
{
    int i;
    RFNL_Use();
    double src[1024];
    for(i = 0; i < 1024; i ++)
    {
        src[i] = RFNL_PSin_Double(i * 0.05f);
        printf("%f\n", src[i]);
    }
    PMatch Dest;
    RNew(PMatch, & Dest);
    RFNL_GenPeak_Gnrc_Double_Double(& Dest, src, 100, 1024);
    PMatch_Print(& Dest);
    printf("%f\n", RFNL_VMaxElmt_Gnrc_Double(src, 0, 1024));
    RDelete(& Dest);
    return 0;
}

