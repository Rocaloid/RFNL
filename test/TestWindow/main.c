#include <RUtil2.h>
#include <math.h>
#include "FWindow/FWindow.h"

float Hanning(float x, int Size)
{
    return 0.5 * (1.0f - cos(2 * 3.1415927 / (Size - 1.0f) * x));
}
int HanningSize(float x)
{
    return (int)x;
}

void RFNL_Use();
int main()
{
    int i;
    RFNL_Use();
    RFNL_FWindow_Gnrc_Float fwin;
    RFNL_FWindow_Gnrc_Float_Ctor(& fwin);
    RFNL_FWindow_Gnrc_Float_SetPara(& fwin, 21, 1028, 1);
    RFNL_FWindow_Gnrc_Float_SetFunc(& fwin, HanningSize, Hanning);
    RFNL_FWindow_Gnrc_Float_Initialize(& fwin);
    
    float Dest[1024];
    int Size = 1024;
    RFNL_FWindow_Gnrc_Float_Generate(& fwin, Dest, Size);
    for(i= 0; i < Size; i ++)
        printf("%d %f\n", i, Dest[i]);
    
    RFNL_FWindow_Gnrc_Float_Dtor(& fwin);
    return 0;
}

