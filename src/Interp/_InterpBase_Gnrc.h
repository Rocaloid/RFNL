//Generic Template Base Interpolation Functions Header & Implementation

RTFunc(_T1, RFNL_Interp_Non, _T1 a0, _T1 a1, _T1 r);
RTFunc(_T1 __inline__, RFNL_Interp_Non, _T1 a0, _T1 a1, _T1 r)
{
    return 0.5f * (a0 + a1);
}

RTFunc(_T1, RFNL_Interp_Linear, _T1 a0, _T1 a1, _T1 r);
RTFunc(_T1 __inline__, RFNL_Interp_Linear, _T1 a0, _T1 a1, _T1 r)
{
    return a0 + (a1 - a0) * r;
}

RTFunc(_T1, RFNL_Interp_Sine, _T1 a0, _T1 a1, _T1 r);
RTFunc(_T1 __inline__, RFNL_Interp_Cosine, _T1 a0, _T1 a1, _T1 r)
{
    return a0 - 0.5f * (a1 - a0) * 
        (RCall(RFNL_PCos_LPrec, _T1)(r * M_PI) - 1.0f);
}

