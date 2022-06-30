#include<bits\stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<vector<int>> g;
set<array<int, 3>> ban;

vector<int> bfs(){
    deque<pair<int, int>> q;
    vector<int> d(g.size() * g.size(), 1e9);
    vector<int> p(g.size() * g.size(), - 1);
    q.push_back({0, 0});
    d[0] = 0;
    while(!q.empty()){
        auto [pr, v] = q.front();
        q.pop_front();
        for(int to : g[v]){
            if(d[v * n + to] != 1e9 || ban.count({pr, v, to})) continue;
            d[v * n + to] = d[pr * n + v] + 1;
            p[v * n + to] = pr * n + v;
            q.push_back({v, to});
        }
    }

    int cur = -1;
    int ans = 1e9;
    for(int i = 0; i < n - 1; ++i){
        if(d[i * n + n - 1] < ans){
            ans = d[i * n + n - 1];
            cur = i * n + n - 1;
        }
    }

    vector<int> path;
    while(cur != -1){
        path.push_back(cur % n);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());

    return path;
}

void solve(){
    int m, k;
    cin >> n >> m >> k;
    g.assign(n, {});
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < k; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        --x, --y, --z;
        ban.insert({x, y, z});
    }

    vector<int> ans = bfs();
    if(ans.empty() || ans[0] != 0){
        cout << -1 << '\n';
    }
    else{
        cout << (int)ans.size() - 1 << '\n';
        for(int i : ans){
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}