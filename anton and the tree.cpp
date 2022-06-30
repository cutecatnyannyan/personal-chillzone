#include<iostream>
#include<vector>
#include<array>

using namespace std;

vector<int> color;
vector<vector<int>> g;
vector<array<pair<int, int>, 2>> dp;

void dfs(int v, int p){
    dp[v][0].second = 1;
    dp[v][1].second = 1;
    for(int to : g[v]){
        if(to == p) continue;

        dfs(to, v);
        if(color[v] == color[to]){
            dp[v][0].first += dp[v][0].first;
            dp[v][0].second += dp[v][0].second - 1;
            dp[v][1].first += dp[v][1].first;
            dp[v][1].second += dp[v][1].second - 1;
        }
        else{
            dp[v][0].first += dp[v][1].second;
            dp[v][0].second += min(dp[v][1].first, dp[v][0].first);
            dp[v][1].first += min(dp[v][0].second, dp[v][0].first);
            dp[v][1].second += dp[v][0].first;
        }
    }
    dp[v][0].first = min(dp[v][0].first, dp[v][0].second + 1);
    dp[v][1].second = min(dp[v][1].second, dp[v][1].first + 1);
}

void solve(){
    int n;
    cin >> n;
    g.assign(n, {});
    color.assign(n, 0);
    dp.assign(n, {});
    for(int& i : color){
        cin >> i;
    }
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    cout << min(dp[0][0].first, dp[0][1].second) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}

