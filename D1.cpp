#include<bits\stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<pair<int, int>> dp;

void dfs(int v, int p){
    dp[v].first = 1e9;
    dp[v].second = 1e9;
    int sum = 0;
    vector<int> ch;
    for(int to : g[v]){
        if(to == p) continue;
        dfs(to, v);
        sum += min(dp[to].first, dp[to].second);
        ch.push_back(to);
    }
    if(ch.empty()){
        dp[v].first = 1;
        dp[v].second = 1;
        return;
    }
    for(int i = 0; i < (int)ch.size(); ++i){
        dp[v].first = min(dp[v].first, dp[ch[i]].first + sum - min(dp[ch[i]].first, dp[ch[i]].second));
    }
    if(ch.size() == 1){
        dp[v].second = dp[v].first;
    }
    else{
        dp[v].second = dp[v].first - 1;
    }
}

void solve(){
    int n;
    cin >> n;
    g.assign(2 * n, {});
    dp.assign(n, {});
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(n == 1){
        cout << 0 << '\n';
        return;
    }

    dfs(0, -1);

    cout << min(dp[0].first, dp[0].second) << '\n';

}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int ttt = 1;
    cin >> ttt;
    while(ttt--){
        solve();
    }

    return 0;
}