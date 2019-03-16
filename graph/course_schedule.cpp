#include "./../lc.h"

vector<vector<int>> buildGraph(int numCourses, vector<pair<int, int>> &prerequistites) {
    vector<vector<int>> graph(numCourses);
    for(auto p : prerequistites)
        graph[p.second].push_back(p.first);
    
    return graph;
}

// dfs
bool solution(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
    vector<bool> todo(numCourses, false), done(numCourses, false);
    for(int i = 0; i < numCourses; i++) {
        if(!done[i] && !acyclic(graph, todo, done, i))
            return false;
    }
    return true;
}

bool acyclic(vector<vector<int>> &graph, vector<bool> &todo, vector<bool> &done, int node) {
    if(todo[node]) return false;
    if(done[node]) return true;
    todo[node] = done[node] = true;
    for(int v : graph[node])
        if(!acyclic(graph, todo, done, v))
            return false;
    todo[node] = false;
    return true;
}

// 
bool solution_2(int n, vector<pair<int, int>> &pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> indegree(n, 0);
    for(auto &p : pre) {
        adj[p.second].push_back(p.first);
        indegree[p.first] ++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        n --;
        for(auto next : adj[curr])
            if(--indegree[next] == 0)
                q.push(next);
        return n == 0;
    }
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}