#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int64_t> cnt(1e5 + 1, 0);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++cnt[x];
    }

    vector<int64_t> dp(1e5 + 1, 0);
    vector<int64_t> mx(1e5 + 1, 0);
    dp[1] = cnt[1];
    mx[1] = cnt[1];

    for(int64_t i = 2; i <= 1e5; ++i){
        dp[i] = mx[i - 2] + cnt[i] * i;
        mx[i] = max(mx[i - 1], dp[i]);
    }

    cout << mx.back() << '\n';
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