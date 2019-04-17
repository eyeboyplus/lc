#include "./../lc.h"

int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;
    vector<int> childern(n, 0);
    int i = -1, cnt = n, step = 0;
    while(cnt > 0) {
        i++;
        if(i == n) i = 0;
        if(childern[i] == -1)
            continue;
        step ++;
        if(step == m) {
            childern[i] = -1;
            if(cnt == 1)
                cout << i + 1 << endl;
            else
                cout << i + 1 << " ";
            step = 0;
            cnt --;
        }
    }
    for(int i = 0; i < n; i++)
        if(childern[i] != -1)
            cout << i + 1;

    return 0;
}