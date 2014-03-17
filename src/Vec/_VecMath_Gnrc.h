RTFunc(void, RFNL_VSqr_Gnrc, _T1* Dest, _T1* Sorc, int Size);
RTFunc(void, RFNL_VRcp_Gnrc, _T1* Dest, _T1* Sorc, int Size);
RTFunc(void, RFNL_VRcpSqr_Gnrc, _T1* Dest, _T1* Sorc, int Size);

RTFunc(void, RFNL_VCplxMul_Gnrc, _T1* DestReal, _T1* DestImag,
                                 _T1* SorcReal, _T1* SorcImag,
                                 int Size);
RTFunc(void, RFNL_VCplxAbs_Gnrc, _T1* Dest,
                                 _T1* SorcReal, _T1* SorcImag,
                                 int Size);
RTFunc(void, RFNL_VCplxArg_Gnrc, _T1* Dest,
                                 _T1* SorcReal, _T1* SorcImag,
                                 int Size);

RTFunc(void, RFNL_VSin_Gnrc, _T1* Dest, _T1* Sorc, int Size);
RTFunc(void, RFNL_VCos_Gnrc, _T1* Dest, _T1* Sorc, int Size);

