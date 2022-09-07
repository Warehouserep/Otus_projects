#ifndef Blockchain_h
#define Blockchain_h

#include <vector>

//инициализация_класса_для_цепочки
class Blockchain
{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    //инициализация_конструктора
    Blockchain();

    //создание_цепочки_блоков
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif 
