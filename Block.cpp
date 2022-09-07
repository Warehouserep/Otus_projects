#include <stdio.h>
#include <string>

#include "E:\ArchiveCode\SmartContracts\Blockchain\include\Block.h"
#include "E:\ArchiveCode\SmartContracts\Blockchain\include\TransactionData.h"

//конструктор_блока_с_данными
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    //получение_индекса
    index = idx;
    //получение_данных
    data = d;
    //предыдущий_хэш
    previousHash = prevHash;
    //сгенерированный_хэш
    blockHash = generateHash();
}

//получение_индекса
int Block::getIndex()
{
    return index;
}

//генерируем_блок
size_t Block::generateHash()
{
    //генерация_строки_с_передаваемыми_данными
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    
    //комбинация_двух_хэшей
    std::hash<std::string> tDataHash;
    std::hash<std::string> prevHash; 
    
    //генерация_для_блока_хэшей_и_данных
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

//возвращение_хэша_блока
size_t Block::getHash()
{
    return blockHash;
}

//возвращение_предыдущего_хэша_блока
size_t Block::getPreviousHash()
{
    return previousHash;
}

//проверка_блока_на_данные
bool Block::isHashValid()
{
    return generateHash() == getHash();
}
