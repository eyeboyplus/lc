#include "./../lc.h"

void recursive(vector<int> nums, int level, 
    int h, int m, int s,
    int &ret_h, int &ret_m, int &ret_s) {
    if(level == 3) {
        if(h == - 1 || m == -1 || s == -1)
            return;
            
        if(h >= ret_h) {
            ret_h = h;ret_m = m;ret_s = s;
            if( h== ret_m && m >= ret_m) {
                ret_m = m;
                ret_s = s;
                if(m == ret_m && s >= ret_s)
                    ret_s = s;
            }
        }
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == -1) continue;
        
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] == -1) continue;

            if(level == 0) {
                int hour = nums[i] * 10 + nums[j];
                if(hour >= 0 && hour <= 24) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, hour, m, s, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
                hour = nums[j] * 10 + nums[i];
                if(hour >= 0 && hour <= 24) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, hour, m, s, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
            } else if(level == 1){
                int minute = nums[i] * 10 + nums[j];
                if(minute >= 0 && minute <= 59) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, h, minute, s, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
                minute = nums[j] * 10 + nums[i];
                if(minute >= 0 && minute <= 59) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, h, minute, s, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
            } else {
                int second = nums[i] * 10 + nums[j];
                if(second >= 0 && second <= 59) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, h, m, second, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
                second = nums[j] * 10 + nums[i];
                if(second >= 0 && second <= 59) {
                    int x = nums[i];
                    int y = nums[j];
                    nums[i] = -1;
                    nums[j] = -1;
                    recursive(nums, level + 1, h, m, second, ret_h, ret_m, ret_s);
                    nums[i] = x;
                    nums[j] = y;
                }
            }
        }
    }
}


int main(int argc, char **argv) {

    string input, s;
    cin >> input;
    istringstream iss(input);
    
    vector<int> nums;
    while(getline(iss, s, ','))
        nums.push_back(stoi(s));
    
    int hour = -1, min = -1, sec = -1;
    recursive(nums, 0, 0, 0, 0, hour, min, sec);

    std::cout << "done.";
    return 0;
}