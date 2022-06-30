#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n1, n2, k1, k2;

    cin >> n1 >> n2 >> k1 >> k2;

    int dp[101][101][11][11];

    dp[0][0][0][0] = 1;

    for(int i = 1; i <= n1; ++i){
        for(int j = 1; j <= n2; ++j){
            for(int k = 0; k <= k1; ++k){
                for(int l = 0; l <= k2; ++l){
                    dp[i][j][k][l] = ((i > 0 && k > 0) ? dp[i - 1][j][k - 1][l] : 0) + ((j > 0 && l > 0) ? dp[i][j - 1][k][l - 1] : 0);
                }
            }
        }
    }

    cout << dp[n1][n2][k1][k2] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int ttt = 1;
    while(ttt--){
        solve();
    }

    return 0;
}