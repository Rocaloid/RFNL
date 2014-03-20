//Common Template Fast Math Header

_T1* _C(__RFNL_SinTable, _, _T1);
_T1* _C(__RFNL_CosTable, _, _T1);

RTFunc(void __attribute__ ((constructor)), __RFNL_Init_SinCosTable);
RTFunc(void __attribute__ ((destructor)),  __RFNL_Exit_SinCosTable);

