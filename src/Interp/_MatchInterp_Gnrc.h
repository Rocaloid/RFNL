//Generic Template PMatch Interpolation Header

RTFunc(void, RFNL_MatchInterp_Non,
             _T2* Dest, _C(PMatch_, _T1, _, _T2)* Sorc, _T2 Fill, int Size);
             
RTFunc(void, RFNL_MatchInterp_Linear,
             _T2* Dest, _C(PMatch_, _T1, _, _T2)* Sorc, _T2 Fill, int Size);

RTFunc(void, RFNL_MatchInterp_Cosine,
             _T2* Dest, _C(PMatch_, _T1, _, _T2)* Sorc, _T2 Fill, int Size);
