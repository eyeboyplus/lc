#include "./../lc.h"

vector<int> solution(vector<int> &nums) {
    vector<int> result;
    if(nums.empty())
        return result;
    // 仅有两个候选人
    int candidateA = nums[0];
    int candidateB = nums[0];
    int cntA = 0, cntB = 0;

    for(vector<int>::const_iterator it = nums.cbegin(); 
    it != nums.cend(); it++) {
        int num = *it;
        if(num == candidateA) {     // 投A
            cntA++;
            continue;
        }
        if(num == candidateB) {     // 投B
            cntB++;
            continue;
        }

        // 更换候选人
        if(cntA == 0) {             
            candidateA = num;
            cntA ++;
            continue;
        }
        if(cntB == 0) {
            candidateB = num;
            cntB ++;
            continue;
        }
        // 当前两个候选人都没投
        cntA--;
        cntB--;
    }
    // 统计两个候选人具体票数，上面只是相对票数
    cntA = 0;
    cntB = 0;
    for(vector<int>::const_iterator it = nums.cbegin(); 
        it != nums.cend(); it++) {
        int num = *it;
        if(num == candidateA)
            cntA++;
        else if(num == candidateB)
            cntB++;
    }
    // 判断是否候选人票数是否超过n/3
    if(cntA > nums.size() / 3)
        result.push_back(candidateA);  
    if(cntB > nums.size() / 3)
        result.push_back(candidateB);  

    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}