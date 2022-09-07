#ifndef TransactionData_h
#define TransactionData_h

struct TransactionData
{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;
    
    TransactionData(){};
    
    TransactionData(double amt, std::string sender, std::string receiver, time_t time)
    {
        //значение
        amount = amt;
        //ключ_отправителя
        senderKey = sender;
        //ключ_получателя
        receiverKey = receiver;
        //данные_по_времени_отправления
        timestamp = time;
    };
};

#endif 
