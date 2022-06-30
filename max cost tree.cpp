#include<bits\stdc++.h>

using namespace std;

int n;
vector<int64_t> dp, sum, val;
vector<vector<int>> g;
int64_t ans = 0;

void fdfs(int v, int p){
    dp[v] = 0;
    sum[v] = val[v];
    for(int to : g[v]){
        if(to == p) continue;

        fdfs(to, v);

        dp[v] += dp[to] + sum[to];
        sum[v] += sum[to];
    }
}

void dfs(int v, int p){
    ans = max(ans, dp[v]);
    for(int to : g[v]){
        if(to == p) continue;
        int64_t dpv = dp[v], dpto = dp[to], sumv = sum[v], sumto = sum[to];

        sum[to] = sumv;
        sum[v] -= sumto;
        dp[v] = dp[v] - dp[to] - sumto;
        dp[to] = dp[to] + dp[v] + sum[v];

        dfs(to, v);

        dp[v] = dpv;
        dp[to] = dpto;
        sum[v] = sumv;
        sum[to] = sumto;
    }
}

void solve(){
    cin >> n;
    g.assign(n, {});
    dp.assign(n, 0);
    sum.assign(n, 0);
    val.assign(n, 0);
    for(int64_t& i : val){
        cin >> i;
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