#ifndef Block_h
#define Block_h

#include "TransactionData.h"

//инициализация_класса_для_блока
class Block
{
private:
    int index;
    //текущий_хэш_блока 
    size_t blockHash;
    //предыдущий_хэш_блока
    size_t previousHash;
    //хэш_функция 
    size_t generateHash();
    
public:
    //конструктур_принимает_предыдущий_хэш_индекс_данные_транзакции
    Block(int idx, TransactionData d, size_t prevHash);
    
    //получение_индекса
    int getIndex();
    
    //пошлучение_текущего_хэша
    size_t getHash();
    
    //получение_предыдущего_хэша
    size_t getPreviousHash();
    
    //передача_данных
    TransactionData data;
    
    //проверка_правильности_хэша
    bool isHashValid();
};

#endif
