#include <RUtil2.h>
#include <math.h>
#include "DFT/DFT.h"

int main()
{
    float* Real, *Imag;
    float* DReal, *DImag;
    Real = RAlloc_Float(1024);
    Imag = RAlloc_Float(1024);
    DReal = RAlloc_Float(1024);
    DImag = RAlloc_Float(1024);
    int i;
    for(i = 0; i < 1024; i ++)
    {
        Real[i] = sin(i * 0.03f);
        Imag[i] = 0;
    }
    for(i = 0; i < 10000; i ++)
        RFNL_RFFT_Generic_Float(DReal, DImag, Real, 10);
    //for(i = 0; i < 1024; i ++)
    //    printf("%f\n", sqrt(DReal[i] * DReal[i] + DImag[i] * DImag[i]));
    RFree(Real);
    RFree(Imag);
    RFree(DReal);
    RFree(DImag);
    return 0;
}

