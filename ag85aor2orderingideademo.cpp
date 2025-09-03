//This is a demo of Arthur Golubev 19850316 algorithm of ordering ag85aor2.

#include <climits>
#include <cstdint>
#include <iostream>
#include <stack>

int main(){

    typedef uint8_t ItemType;

    ItemType seq[] = {8, 13, 5, 8, 8, 2, 1, 0};
    
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

    long long bigBorderToProccess = (seqLen - 1);

    if (bigBorderToProccess < 0) {
        std::cout << "Because input set is empty, not running ordering." << "\n";
        return EXIT_SUCCESS;
    }

    std::stack<size_t> wrkOrdStk;

    size_t firstMaxItemPos = 0;

    while(bigBorderToProccess > 0){
   
        if(wrkOrdStk.empty()){
            wrkOrdStk.push(0);
        }

        size_t ind1 = firstMaxItemPos;

        for(; ind1 <= bigBorderToProccess; ++ind1){

            if(seq[ind1] >= seq[wrkOrdStk.top()]){
                wrkOrdStk.push(ind1);
            }

        }

        ItemType currMaxItem = seq[wrkOrdStk.top()];
        
        do{
            
            std::swap(seq[wrkOrdStk.top()], seq[bigBorderToProccess]);

            firstMaxItemPos = wrkOrdStk.top();

            wrkOrdStk.pop();

            --bigBorderToProccess;

        } while(
            !wrkOrdStk.empty()
            && (seq[wrkOrdStk.top()] == currMaxItem)
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
