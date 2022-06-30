#include<bits\stdc++.h>


using namespace std;

vector<int64_t> sz, dp;
int64_t ans= 0;
int n = 0;

vector<vector<int>> g;

void fdfs(int v, int p){
    dp[v] = 0;
    sz[v] = 1;
    for(int to : g[v]){
        if(to == p) continue;

        fdfs(to, v);

        dp[v] += dp[to];
        sz[v] += sz[to];
    }
    dp[v] += sz[v];
}

void dfs(int v, int p){
    ans = max(ans, dp[v]);
    for(int to : g[v]){
        if(to == p) continue;
        int szv = sz[v], szto = sz[to], dpv = dp[v], dpto = dp[to];

        sz[v] = n - sz[to];
        sz[to] = n;
        dp[v] -= szto + dp[to];
        dp[to] += sz[v] + dp[v];

        dfs(to, v);

        sz[v] = szv;
        sz[to] = szto;
        dp[v] = dpv;
        dp[to] = dpto;
    }
}

void solve(){
    cin >> n;

    g.assign(n, {});
    dp.assign(n, 0);
    sz.assign(n, 0);

    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y; 
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    fdfs(0, -1);
    dfs(0, - 1);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}