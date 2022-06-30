#include<bits\stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> val;
vector<int> d;

void dfs(int v, int p, int m){
    if(d[v] > m) return;
    for(int to : g[v]){
        if(to == p) continue;
        if(val[to])d[to] = d[v] + val[to];
        else d[to] = 0;
        dfs(to, v, m);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    val.assign(n, 0);
    d.assign(n, -1);
    for(int& i : val){
        cin >> i;
    }

    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    d[0] = val[0];
    dfs(0, -1, m);

    int ans = 0;
    for(int i = 1; i < n; ++i){
        if(g[i].size() == 1 && d[i] <= m && d[i] != -1){
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}