#include<bits\stdc++.h>

using namespace std;

const int64_t mod = 1000000007;

void solve(){
    int t, k;
    cin >> t >> k;
    
    vector<pair<int64_t, int64_t>> dp(1e5 + 1, {0, 0});
    dp[0] = {0, 1};

    for(int i = 1; i <= 1e5; ++i){
        if(i - k >= 0){
            dp[i].first = (dp[i - k].second + dp[i - k].first) % mod;
        }
        dp[i].second = (dp[i - 1].first + dp[i - 1].second) % mod;
    }

    vector<int64_t> sum(1e5 + 1, 0);
    for(int i = 1; i <= 1e5; ++i){
        sum[i] = (sum[i - 1] + dp[i].first + dp[i].second) % mod;
    }

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1] + mod) % mod << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int ttt = 1;
    //cin >> ttt;
    while(ttt--){
        solve();
    }

    return 0;
}