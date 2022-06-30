#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int64_t m;

int n;
vector<int64_t> dp, ans;
vector<vector<int>> g;

void fdfs(int v, int p){
    dp[v] = 1;
    for(int to : g[v]){
        if(to == p) continue;
        
        fdfs(to, v);
        dp[v] = dp[v] * (dp[to] + 1) % m;
    }
}

void dfs(int v, int p){
    ans[v] = dp[v];
    vector<int64_t> pr;
    vector<int64_t> suf;
    pr.push_back(p == -1 ? 1 : (dp[p] + 1));
    suf.push_back(1);
    for(int i = 0; i < (int)g[v].size(); ++i){
        if(g[v][i] == p) continue;
        pr.push_back(pr.back() * (dp[g[v][i]] + 1) % m);
    }
    for(int i = (int)g[v].size() - 1; i >= 0; --i){
        if(g[v][i] == p) continue;
        suf.push_back(suf.back() * (dp[g[v][i]] + 1) % m);
    }
    int cur = 0;
    for(int to : g[v]){
        if(to == p) continue;
        int64_t dpv = dp[v], dpto = dp[to];
        dp[v] = pr[cur] * suf[(int)suf.size() - cur - 2] % m;
        dp[to] = dpto * (dp[v] + 1) % m;

        dfs(to, v);

        dp[v] = dpv;
        dp[to] = dpto; 
        ++cur;
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n, {});
    dp.assign(n, 0);
    ans.assign(n, 0);

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
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}