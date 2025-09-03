//This is a demo of Arthur Golubev 19850316 algorithm of ordering ag85aor2.

#include <climits>
#include <cstdint>
#include <iostream>
#include <stack>

int main(){

    typedef uint8_t ItemType;

    ItemType seq[] = {8, 13, 5, 8, 8, 2, 14, 15};

    size_t seqLen = (sizeof(seq) / sizeof(seq[0]));
    std::cout << "Input sequence (" << seqLen << " items):";
    for (
        size_t printInpSeqNumbsCntr = 0
        ; printInpSeqNumbsCntr < seqLen
        ; ++printInpSeqNumbsCntr)
    {
        std::cout << " " << (int)(seq[printInpSeqNumbsCntr]);
    }
    std::cout << std::endl;

    ItemType * bigBorderToProccessPtr = seq + (seqLen - 1);

    if (bigBorderToProccessPtr < seq) {
        std::cout << "Because input set is empty, not running ordering." << "\n";
        return EXIT_SUCCESS;
    }

    std::stack<ItemType *> wrkOrdStk;

    ItemType* firstMaxItemPtr = &(seq[0]);

    while(bigBorderToProccessPtr > seq){
   
        if(wrkOrdStk.empty()){
            wrkOrdStk.push(&(seq[0]));
        }

        ItemType* wrkPtr1 = firstMaxItemPtr;

        ItemType currMaxItemValue = *(wrkOrdStk.top());

        for(; wrkPtr1 <= bigBorderToProccessPtr; ++wrkPtr1){

            if(*wrkPtr1 >= currMaxItemValue){
                wrkOrdStk.push(wrkPtr1);
                if(*wrkPtr1 > currMaxItemValue){
                    currMaxItemValue = *wrkPtr1;
                }
            }

        }

        do{
            
            std::swap(*(wrkOrdStk.top()), *bigBorderToProccessPtr);

            firstMaxItemPtr = wrkOrdStk.top();

            wrkOrdStk.pop();

            --bigBorderToProccessPtr;

        } while(
            !wrkOrdStk.empty()
            && (*(wrkOrdStk.top()) == currMaxItemValue)
        );

    }

    std::cout << "With repeatings result (" << seqLen << " items):";
    for (
        size_t printResSeqNmbsCntr = 0
        ; printResSeqNmbsCntr < seqLen
        ; ++printResSeqNmbsCntr)
    {
        std::cout << " " << (int)(seq[printResSeqNmbsCntr]);
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

//Author: Arthur Golubev 19850316
