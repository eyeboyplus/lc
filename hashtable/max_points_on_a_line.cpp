#include "./../lc.h"

int solution(vector<Point> &points) {
    int n = points.size();
    unordered_map<double, int> map;

    int maxP = 0;
    for(int i = 0; i < n; ++i) {
        map.clear();
        int dup = 1;
        for(int j = i + 1; j < n; j++) {
            if(points[j].x == points[i].x && points[j].y == points[i].y) {
                dup ++;
                continue;
            }
            float slope = (points[j].x == points[i].x) ? INT_MAX : (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
            map[slope] ++;
        }
        maxP = max(maxP, dup);
        for(auto pair : map) {
            maxP = max(maxP, pair.second + dup);
        }
    }
    return maxP;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}