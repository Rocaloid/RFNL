//Generic Template Series Mapping, Compression & Expansion Header

#define __RFNL_Define_MapStretch(Post1, Post2) \
    RTFunc(void, _C(RFNL_MapStretch_, Post1, _, Post2, _Gnrc), \
                _T2* Dest, _T2* Sorc, _T1* DestAnchor, _T1* SorcAnchor, \
                int INum, int Size)

__RFNL_Define_MapStretch(Non, Non);
__RFNL_Define_MapStretch(Non, Linear);
__RFNL_Define_MapStretch(Non, Cosine);
__RFNL_Define_MapStretch(Linear, Non);
__RFNL_Define_MapStretch(Linear, Linear);
__RFNL_Define_MapStretch(Linear, Cosine);
__RFNL_Define_MapStretch(Cosine, Non);
__RFNL_Define_MapStretch(Cosine, Linear);
__RFNL_Define_MapStretch(Cosine, Cosine);

