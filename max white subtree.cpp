#include<bits\stdc++.h>

using namespace std;

vector<int> color, dp;
vector<int> ans;
int n = 0;
vector<vector<int>> g;

void fdfs(int v, int p){
    dp[v] = (color[v] == 1) ? 1 : -1;
    for(int to : g[v]){
        if(to == p) continue;

        fdfs(to, v);

        dp[v] += max(dp[to], 0);
    }
}

void dfs(int v, int p){
    ans[v] = dp[v];
    for(int to : g[v]){
        if(to == p) continue;
        int dpto = dp[to], dpv = dp[v];

        dp[v] -= max(dpto, 0);
        dp[to] += max(0, dp[v]);
        dfs(to, v);

        dp[to] = dpto;
        dp[v] = dpv;
    }
}

void solve(){
    cin >> n;
    g.assign(n, {});
    dp.assign(n, 0);
    ans.assign(n, 0);
    color.assign(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> color[i];
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

    for(int i : ans){
        cout << i << ' ';
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}