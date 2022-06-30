#include<bits\stdc++.h>

using namespace std;

vector<int> kbfs(int start, int k, vector<vector<pair<int, int>>> const& g){
    int n = g.size();
    vector<deque<int>> q(k + 1);
    vector<int> d(n, 1e9);
    vector<bool> used(n, false);

    q[0].push_back(start);
    d[start] = 0;
    int pos = 0;
    int cnt = 1;
    while(cnt > 0){
        while(q[pos].empty()){
            pos = (pos + 1) % (k + 1);
        }

        int u = q[pos].front();
        q[pos].pop_front();
        --cnt;

        if(used[u]) continue;

        used[u] = true;

        for(auto [to, w] : g[u]){
            if(d[u] + w < d[to]){
                d[to] = d[u] + w;
                q[d[w] % (k + 1)].push_back(to);
                ++cnt;
            }
        }
    }

    return d;
}

