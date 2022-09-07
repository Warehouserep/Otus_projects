#include <iostream>
#include <ctime>
#include <vector>

#include "E:\ArchiveCode\SmartContracts\Blockchain\include\TransactionData.h"
#include "E:\ArchiveCode\SmartContracts\Blockchain\include\Block.h"
#include "E:\ArchiveCode\SmartContracts\Blockchain\include\Blockchain.h"

using namespace std;

int main()
{
    //
    Blockchain awesomeCoin;
    
    //Данные_для_первого_блока
    time_t data1Time;
    TransactionData data1(1.723, "NFT_1", "NFT_2", time(&data1Time));
    awesomeCoin.addBlock(data1);
    
    //Данные_для_второго_блока
    time_t data2Time;
    TransactionData data2(5.9348, "NFT_2", "Bank_2", time(&data2Time));
    awesomeCoin.addBlock(data2);

    //Данные_для_третьего_блока
    time_t data3Time;
    TransactionData data3(4.4893, "Bank_2", "Bank_3", time(&data3Time));
    awesomeCoin.addBlock(data3);

    //Данные_для_четвертого_блока
    time_t data4Time;
    TransactionData data4(7.9475, "Bank_3", "NFT_2", time(&data4Time));
    awesomeCoin.addBlock(data4);

    //Данные_для_пятого_блока
    time_t data5Time;
    TransactionData data5(6.8563, "NFT_7", "NFT_3", time(&data5Time));
    awesomeCoin.addBlock(data5);

    //Данные_для_шестого_блока
    time_t data6Time;
    TransactionData data6(7.9475, "NFT_7", "Bank_10", time(&data6Time));
    awesomeCoin.addBlock(data6);

    //Данные_для_седьмого_блока
    time_t data7Time;
    TransactionData data7(9.8118, "Bank_10", "Bank_11", time(&data7Time));
    awesomeCoin.addBlock(data7);

    //Данные_для_восьмого_блока
    time_t data8Time;
    TransactionData data8(1.1212, "Bank_11", "NFT_1", time(&data8Time));
    awesomeCoin.addBlock(data8);

    //печать_блока
    awesomeCoin.printChain();
    printf("\nIs chain still valid: %d\n", awesomeCoin.isChainValid());
    
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 2; 
    hackBlock->data.receiverKey = "NFT_1"; 
    awesomeCoin.printChain();
    printf("\nIs chain still valid: %d\n", awesomeCoin.isChainValid());
    
    return 0;
}
