#include "./../lc.h"


void recursive(const vector<int> &atks, const vector<int> &golds, int target, int path_atks, int path_expenses, int &ret) {
    if(target == atks.size()) {
        ret = min(ret, path_expenses);
        return;
    }
    if(atks[target] <= path_atks)    // 可以不贿赂
        recursive(atks, golds, target + 1, path_atks, path_expenses, ret);    // 不贿赂
   
    recursive(atks, golds, target + 1, path_atks + atks[target], path_expenses + golds[target], ret); 
}

int main(int argc, char **argv) {
    int n;
    cin >> n;
    vector<int> atks(n, 0);
    vector<int> golds(n, 0);
    
    for(int i = 0; i < n; i++)
        cin >> atks[i];
    for(int i = 0; i < n; i++)
        cin >> golds[i];
    int ret = INT_MAX;
    recursive(atks, golds, 0, 0, 0, ret);
    
    cout << ret << endl;
    return 0;
}