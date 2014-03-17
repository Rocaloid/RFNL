RTFunc(void, RFNL_RFFT_Generic, _T1* DestReal, _T1* DestImag,
                                _T1* SorcReal,
                                int Power);
RTFunc(void, RFNL_CFFT_Generic, _T1* DestReal, _T1* DestImag,
                                _T1* SorcReal, _T1* SorcImag,
                                int Power);
RTFunc(void, RFNL_IRFFT_Generic, _T1* DestReal,
                                 _T1* SorcReal, _T1* SorcImag,
                                 int Power);
RTFunc(void, RFNL_ICFFT_Generic, _T1* DestReal, _T1* DestImag,
                                 _T1* SorcReal, _T1* SorcImag,
                                 int Power);

RTFunc(void, RFNL_FFTReflect_Generic, _T1* DestReal, _T1* DestImag, int Power);

