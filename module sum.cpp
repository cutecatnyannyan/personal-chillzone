#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& i : a){
        cin >> i;
        i %= m;
    }

    vector<bool> sup(m, false);
    vector<vector<bool>> dp(n + 1, sup);
    if(n > m * (m - 1) / 2){
        cout << "YES\n";
        return;
    }

    

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j){
            if(j == a[i - 1]){
                dp[i][j] = true;
            }
            else dp[i][j] = dp[i - 1][(j - a[i - 1] + m) % m] || dp[i - 1][j];
        }
    }

    if(dp[n][0]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}