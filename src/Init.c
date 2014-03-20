//When using RFNL you have to call this function to ensure libRFNL ls linked to
//  your program. Otherwise programs which calls only inline functions in RFNL
//  may crush(because constructors are not called).
void RFNL_Use()
{
    //Empty
}

