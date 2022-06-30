#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> sup(m, 0);
    vector<vector<int>> v(n, sup);
    for(auto& r : v){
        for(int& i : r){
            cin >> i;
        }
    }

    vector<pair<int, int>> sup1(m);
    vector<vector<pair<int, int>>> dp(n, sup1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dp[i][j].first = max((i > 0) ? dp[i - 1][j].first : 0, (j > 0) ? dp[i][j - 1].first : 0) + (v[i][j] == 1);
            dp[i][j].second = max((i > 0) ? dp[i - 1][j].second : 0, (j > 0) ? dp[i][j - 1].second : 0) + (v[i][j] == -1);
        }
    }

    bool flag = ((n + m) % 2 != 0);
    if(dp[n - 1][m - 1].first < (n + m - 1) / 2 || dp[n - 1][m - 1].second < (n + m - 1) / 2){
        flag = false;
    }
    if(flag){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
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