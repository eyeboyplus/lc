#include "./../lc.h"

int main(int argc, char **argv) {
    string s_costs, s_calls;
    vector<int> costs;
    vector<int> calls;
    vector<int> profits;
    int k;

    cin >> s_costs >> s_calls >> k;

    istringstream iss_costs(s_costs);
    string s;
    while(getline(iss_costs, s, ',')) {
        costs.push_back(stoi(s));
    }

    istringstream iss_calls(s_calls);
    while(getline(iss_calls, s, ','))
        calls.push_back(stoi(s));

    for(int i = 0; i < costs.size(); i++)
        profits.push_back(calls[i] - costs[i]);

    int n = costs.size();
    vector<bool> visited(n, false);

    while(true) {
        bool hasSelled = false;
        for(int i = 0; i < n && !visited[i]; i++) {
            if(k > costs[i] && profits[i] > 0) {
                k += profits[i];
                visited[i] = true;
                hasSelled = true;
            }
        }
        if(!hasSelled)
            break;
    }

    cout << k << endl;
    return 0;
}