#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> t(n);

    for(int& i : t){
        cin >> i;
    }
    sort(t.begin(), t.end());

    vector<int> sup(2 * n, 1e9);
    vector<vector<int>> dp(n + 1, sup);

    dp[0][0] = 0;

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < 2 * n; ++j){
            if(i == 0 && j == 0) continue;
            dp[i][j] = min((i > 0 && j > 0) ? (dp[i - 1][j - 1] + abs(j - t[i - 1])) : (int)1e9, (j > 0) ? dp[i][j - 1] : (int)1e9);
        }
    }

    cout << dp[n].back() << '\n';
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