#include<bits\stdc++.h>

using namespace std;

int n, k, mx;
int cur = 0;
int cnt = 0;
vector<vector<int>> g;
vector<vector<int>> paths;
vector<bool> used;

void dfs(int v){
    used[v] = true;
    if(cnt >= mx) cnt = 0, ++cur;
    paths[cur].push_back(v);
    ++cnt;
    for(int to : g[v]){
        if(used[to]) continue;

        dfs(to);
        if(cnt < mx){
            ++cnt;
            paths[cur].push_back(v);
        }
    }
}

void solve(){
    int m;
    cin >> n >> m >> k;
    g.assign(n, {});
    paths.assign(k, {});
    used.assign(n, false);

    mx = 2 * n / k + (2 * n % k == 0 ? 0 : 1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);

    for(int i = 0; i < k; ++i){
        if(paths[i].empty()) paths[i].push_back(0);
        cout << paths[i].size() << ' ';
        for(int j : paths[i]){
            cout << j + 1 << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}