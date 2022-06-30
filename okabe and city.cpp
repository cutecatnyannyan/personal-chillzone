#include<bits\stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;

int bfs(int start, int end){
    int n = g.size();
    deque<int> q;
    vector<int> d(n, -1);
    vector<int> p(n, -1);
    d[start] = 0;
    q.push_back(start);
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto [to, w] : g[v]){
            if(d[to] != -1) continue;
            d[to] = d[v] + w;
            p[to] = v;
            if(w == 0){
                q.push_front(to);
            }
            else{
                q.push_back(to);
            }
        }
    }

    return d[end];
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, int> z;
    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        z[{x, y}] = i;
    }
    g.assign(k + n + m, {});
    for(auto [p, i] : z){
        if(p.first - 1 >= 0){
            g[i].push_back({k + p.first - 1, 1});
            g[k + p.first - 1].push_back({i, 0});
        }
        if(p.first + 1 < n){
            g[i].push_back({k + p.first + 1, 1});
            g[k + p.first + 1].push_back({i, 0});
        }
        if(p.second - 1 >= 0){
            g[i].push_back({k + n + p.second - 1, 1});
            g[k + n + p.second - 1].push_back({i, 0});
        }
        if(p.second + 1 < m){
            g[i].push_back({k + n + p.second + 1, 1});
            g[k + n + p.second + 1].push_back({i, 0});
        }
        g[i].push_back({k + p.first, 1});
        g[i].push_back({k + n + p.second, 1});
        g[k + p.first].push_back({i, 0});
        g[k + n + p.second].push_back({i, 0});

        if(z.count({p.first - 1, p.second})){
            int j = z[{p.first - 1, p.second}];
            g[i].push_back({j, 0});
            g[j].push_back({i, 0});
        }
        if(z.count({p.first + 1, p.second})){
            int j = z[{p.first + 1, p.second}];
            g[i].push_back({j, 0});
            g[j].push_back({i, 0});
        }
        if(z.count({p.first, p.second - 1})){
            int j = z[{p.first, p.second - 1}];
            g[i].push_back({j, 0});
            g[j].push_back({i, 0});
        }
        if(z.count({p.first, p.second + 1})){
            int j = z[{p.first, p.second + 1}];
            g[i].push_back({j, 0});
            g[j].push_back({i, 0});
        }
    }
    if(!z.count({n - 1, m - 1})){
        int i = g.size();
        z[{n - 1, m - 1}] = i;
        g.push_back({});
        g[i].push_back({k + n - 1, 1});
        g[k + n - 1].push_back({i, 0});
        g[i].push_back({k + m - 1, 1});
        g[k + n + m - 1].push_back({i, 0});
    }

    int ans = bfs(z[{0, 0}], z[{n - 1, m - 1}]);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}