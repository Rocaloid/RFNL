#include <RUtil2.h>
#include <math.h>
#include "Interp/Interp.h"

void RFNL_Use();
int main()
{
    int i;
    RFNL_Use();
    Float src[1024];
    for(i = 0; i < 1024; i ++)
    {
        src[i] = RFNL_PSin_Float(i * 0.05f) * i
               + fabs(RFNL_PTan_Float(i)) > 0.5 ?
                 0.5 : fabs(RFNL_PTan_Float(i));
    }
    PMatch_Float_Float Dest;
    RNew(PMatch_Float_Float, & Dest);
    RFNL_GenPeak_Gnrc_Float_Float(& Dest, src, 50, 1024);
    PMatch_Float_Float_Print(& Dest);
    for(i = 0; i < 850000; i ++)
    RFNL_MatchInterp_Linear_Gnrc_Float_Float(src, & Dest, TopOf(Dest.Y), 1024);
    for(i = 0; i < 1024; i ++)
        printf("%4d %9f\n", i, src[i]);
    RDelete(& Dest);
    return 0;
}

