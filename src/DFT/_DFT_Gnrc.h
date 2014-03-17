RTFunc(void, RFNL_RFFT_Gnrc, _T1* DestReal, _T1* DestImag,
                             _T1* SorcReal,
                             int Power);
RTFunc(void, RFNL_CFFT_Gnrc, _T1* DestReal, _T1* DestImag,
                             _T1* SorcReal, _T1* SorcImag,
                             int Power);
RTFunc(void, RFNL_IRFFT_Gnrc, _T1* DestReal,
                              _T1* SorcReal, _T1* SorcImag,
                              int Power);
RTFunc(void, RFNL_ICFFT_Gnrc, _T1* DestReal, _T1* DestImag,
                              _T1* SorcReal, _T1* SorcImag,
                              int Power);

RTFunc(void, RFNL_FFTReflect_Gnrc, _T1* DestReal, _T1* DestImag, int Power);

