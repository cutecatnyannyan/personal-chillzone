#include<bits\stdc++.h>

using namespace std;

int64_t mod = 1000000000 + 7;

int64_t add(int64_t a, int64_t b){
    return (a + b + mod) % mod;
}

int64_t mult(int64_t a, int64_t b){
    return a * b % mod;
}

int n;
vector<int64_t> dp, sz, val;
vector<vector<int>> g;
int64_t ans = 0;

void fdfs(int v, int p){
    sz[v] = 1;
    dp[v] = val[v];
    for(int to : g[v]){
        if(to == p) continue;
        
        fdfs(to, v);

        dp[v] = add(dp[v], add(mod - dp[to], mult(sz[to], val[v])));
        sz[v] += sz[to];
    }
}

void dfs(int v, int p){
    ans = add(ans, dp[v]);
    for(int to : g[v]){
        if(to == p) continue;
        int64_t szv = sz[v], szto = sz[to], dpv = dp[v], dpto = dp[to];

        sz[v] = n - sz[to];
        sz[to] = n; 
        dp[v] = add(dp[v], add(dp[to], mod - mult(szto, val[v])));
        dp[to] = add(dp[to], add(mod - dp[v], mult(val[to], sz[v])));
        dfs(to, v);
        
        dp[v] = dpv;
        dp[to] = dpto;
        sz[v] = szv;
        sz[to] = szto;
    }
}


void solve(){
    cin >> n;
    g.assign(n, {});
    dp.assign(n, 0);
    sz.assign(n, 0);
    val.assign(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> val[i];
    }
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    fdfs(0, -1);
    dfs(0, -1);

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}