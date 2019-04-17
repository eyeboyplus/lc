#include "./../lc.h"

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = gas.size() - 1, end = 0;
    int remain = gas[start] - cost[start];
    
    while(end < start) {
        if(remain >= 0) {
            remain += gas[end] - cost[end];
            end ++;
        } else {
            start --;
            remain += gas[start] - cost[start];
        }
    }
    return remain >= 0 ? start : -1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}