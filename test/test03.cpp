#include "./../lc.h"

int indexOfLast1Bit(int num) {
    int mask = 1, offset = 0;
    while((num & mask) == 0 && offset < (sizeof(int) * 8)) {
        mask <<= 1;
        offset ++;
    }
    return offset;
}

int findBit(int num, int offset) {
    int mask = 1 << offset;
    return num & mask;
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int tmp = 0;
    for(vector<int>::const_iterator it = data.begin(); it != data.end(); it++)
        tmp ^= (*it);

    int offset = indexOfLast1Bit(tmp);
    for(vector<int>::const_iterator it = data.begin(); it != data.end(); it++) {
        if(findBit(*it, offset) == 0)
            (*num1) ^= (*it);
        else
            (*num2) ^= (*it);
    }
}

int main(int argc, char **argv) {
    vector<int> data = {2,4,3,6,3,2,5,5};
    int num1 = 0, num2 = 0;
    FindNumsAppearOnce(data, &num1, &num2);
    std::cout << "done.";
    return 0;
}