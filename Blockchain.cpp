#include <stdio.h>
#include <ctime>
#include <string>
#include <vector>

#include "E:\ArchiveCode\SmartContracts\Blockchain\include\Block.h"
#include "E:\ArchiveCode\SmartContracts\Blockchain\include\Blockchain.h"

//Конструктур_для_цепочки_блоков
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

std::vector<Block> Blockchain::getChain() {
    return chain;
}

Block Blockchain::createGenesisBlock()
{
    //получение_текущего_времени
    std::time_t current;
    
    //установка_начальных_данных
    TransactionData d(0, "Genesis", "Genesis", time(&current));
    
    //возврат_значения_блока
    Block genesis(0, d, 0);
    return genesis;
}

Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    std::size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

//оценка_изменение_блокчейна
bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
        
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }
    
    return true;
}

//печать_параметров_цепочки_блоков
void Blockchain::printChain() {
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nIs Block Valid: %d", currentBlock.isHashValid());
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nHash: %zu", currentBlock.getHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
    }
}

