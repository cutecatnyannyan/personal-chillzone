#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(string& s : a){
        cin >> s;
    }

    vector<bool> sup(1 << n, false);
    vector<vector<bool>> dp(m + 1, sup);
    vector<pair<int, char>> sup1(1 << n);
    vector<vector<pair<int, char>>> prev(m + 1, sup1);

    dp[0][0] = true;
    for(int i = 1; i <= m; ++i){
        for(int mask = 0; mask < (1 << n); ++mask){
            for(char c = 'a'; c <= 'z'; ++c){
                int cur_mask = 0;
                bool flag = true;
                for(int k = 0; k < n; ++k){
                    cur_mask += (c != a[k][i - 1]) << k;
                    if(c != a[k][i - 1] && ((1 << k) & mask) == 0) flag = false;
                }
                if(!flag) continue;

                cur_mask = mask ^ cur_mask;
                if(dp[i - 1][cur_mask]){
                    dp[i][mask] = true;
                    prev[i][mask] = {cur_mask, c};
                    break;
                }
            }
        }
    }

    string ans = "";
    for(int mask = 0; mask < (1 << n); ++mask){
        if(dp.back()[mask]){
            int cur_mask = mask;
            for(int j = m; j > 0; --j){
                ans.push_back(prev[j][cur_mask].second);
                cur_mask = prev[j][cur_mask].first;
            }
            break;
        }
    }

    reverse(ans.begin(), ans.end());
    if(ans == "") ans = "-1";

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int ttt = 1;
    cin >> ttt;
    while(ttt--){
        solve();
    }

    return 0;
}