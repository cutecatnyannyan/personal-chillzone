#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n, 0);
    for(int& i : p){
        cin >> i;
    }

    vector<int64_t> sum(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + p[i - 1];
    }

    vector<int64_t> sup(k + 1, 0);
    vector<vector<int64_t>> dp(n + 1, sup);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i][j] = max(dp[i - 1][j], (i - m + 1 > 0) ? (dp[i - m][j - 1] + sum[i] - sum[i - m]) : 0);
        }
    }

    cout << dp[n][k] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    solve();

    return 0;
}