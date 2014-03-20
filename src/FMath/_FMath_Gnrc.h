#undef __RFNL_Trig_CheckSign
#undef __RFNL_Trig_Indexing
#undef __RFNL_Trig_InterpRet
#undef __RFNL_Trig_NoInterpRet

#define __RFNL_Trig_CheckSign() \
    if(x < 0) \
        x = M_PI - x

#define __RFNL_Trig_Indexing() \
    x = x / M_PI / 2.0f; \
    x -= (int)x; \
    x *= RFNL_TableSize; \
    i = x

#define __RFNL_Trig_InterpRet(Table) \
    return _C(Table, _, _T1)[i] + \
          (_C(Table, _, _T1)[i + 1] - \
           _C(Table, _, _T1)[i]) * r

#define __RFNL_Trig_NoInterpRet(Table) \
    return _C(Table, _, _T1)[i]

//Sine
RTFunc(_T1, RFNL_Sin, _T1 x);
RTFunc(_T1 __inline__, RFNL_Sin, _T1 x)
{
    _T1 r;
    int i;
    
    __RFNL_Trig_CheckSign();
    __RFNL_Trig_Indexing();
    r = x - i;
    
    __RFNL_Trig_InterpRet(__RFNL_SinTable);
}

//Low precision(no interpolation) sine
RTFunc(_T1, RFNL_Sin_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_Sin_LPrec, _T1 x)
{
    int i;
    
    __RFNL_Trig_CheckSign();
    __RFNL_Trig_Indexing();
    
    __RFNL_Trig_NoInterpRet(__RFNL_SinTable);
}

//Positive-only sine
RTFunc(_T1, RFNL_PSin, _T1 x);
RTFunc(_T1 __inline__, RFNL_PSin, _T1 x)
{
    _T1 r;
    int i;
    
    __RFNL_Trig_Indexing();
    r = x - i;
    
    __RFNL_Trig_InterpRet(__RFNL_SinTable);
}

//Positive-only, low precision(no interpolation) sine
RTFunc(_T1, RFNL_PSin_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_PSin_LPrec, _T1 x)
{
    int i;
    
    __RFNL_Trig_Indexing();
    
    __RFNL_Trig_NoInterpRet(__RFNL_SinTable);
}

//Cosine
RTFunc(_T1, RFNL_Cos, _T1 x);
RTFunc(_T1 __inline__, RFNL_Cos, _T1 x)
{
    _T1 r;
    int i;
    
    __RFNL_Trig_CheckSign();
    __RFNL_Trig_Indexing();
    r = x - i;
    
    __RFNL_Trig_InterpRet(__RFNL_CosTable);
}

//Low precision(no interpolation) cosine
RTFunc(_T1, RFNL_Cos_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_Cos_LPrec, _T1 x)
{
    int i;
    
    __RFNL_Trig_CheckSign();
    __RFNL_Trig_Indexing();
    
    __RFNL_Trig_NoInterpRet(__RFNL_CosTable);
}

//Positive-only cosine
RTFunc(_T1, RFNL_PCos, _T1 x);
RTFunc(_T1 __inline__, RFNL_PCos, _T1 x)
{
    _T1 r;
    int i;
    
    __RFNL_Trig_Indexing();
    r = x - i;
    
    __RFNL_Trig_InterpRet(__RFNL_CosTable);
}

//Positive-only, low precision(no interpolation) cosine
RTFunc(_T1, RFNL_PCos_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_PCos_LPrec, _T1 x)
{
    int i;
    
    __RFNL_Trig_Indexing();
    
    __RFNL_Trig_NoInterpRet(__RFNL_CosTable);
}

//Tan

RTFunc(_T1, RFNL_Tan, _T1 x);
RTFunc(_T1 __inline__, RFNL_Tan, _T1 x)
{
    return RCall(RFNL_Sin, _T1)(x) / RCall(RFNL_Cos, _T1)(x);
}

RTFunc(_T1, RFNL_PTan, _T1 x);
RTFunc(_T1 __inline__, RFNL_PTan, _T1 x)
{
    return RCall(RFNL_PSin, _T1)(x) / RCall(RFNL_PCos, _T1)(x);
}

RTFunc(_T1, RFNL_Tan_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_Tan_LPrec, _T1 x)
{
    return RCall(RFNL_Sin_LPrec, _T1)(x) / RCall(RFNL_Cos_LPrec, _T1)(x);
}

RTFunc(_T1, RFNL_PTan_LPrec, _T1 x);
RTFunc(_T1 __inline__, RFNL_PTan_LPrec, _T1 x)
{
    return RCall(RFNL_PSin_LPrec, _T1)(x) / RCall(RFNL_PCos_LPrec, _T1)(x);
}

