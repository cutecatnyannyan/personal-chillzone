#include<bits\stdc++.h>

using namespace std;

vector<vector<int>> g;
int n;

vector<int> bfs(int start){
    deque<int> q;
    vector<int> d(n, -1);
    q.push_back(start);
    d[start] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(int to : g[v]){
            if(d[to] != -1) continue;
            d[to] = d[v] + 1;
            q.push_back(to);
        }
    }

    return d;
}