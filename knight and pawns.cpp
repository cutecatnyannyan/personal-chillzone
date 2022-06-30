#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<string> f(n);
    for(auto& s : f){
        cin >> s;
    }
    
    vector<int> sup(n + 1, -1e8);
    vector<vector<int>> dp(n + 1, sup);

    for(int j = 0; j < n; ++j){
        for(int i = 0; i < n; ++i){
            if(j > 0){
                dp[i][j] = max({(i > 0) ? dp[i - 1][j - 1] : 0, (i < (n - 1)) ? dp[i + 1][j - 1] : 0, dp[i][j - 1]});
            }
            if(f[i][j] == 'P'){
                dp[i][j] += 1;
            }
            else if(f[i][j] == 'K'){
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, dp[i][n - 1]);
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int ttt;
    cin >> ttt;
    while(ttt--){
        solve();
    }
}