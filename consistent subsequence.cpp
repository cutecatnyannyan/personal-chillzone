#include<bits\stdc++.h>

using namespace std;


void solve(){
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    map<int, int> dp;
    for(int& i : a){
        cin >> i;
        dp[i] = 0;
    }

    for(int i = 0; i < n; ++i){
        dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
    }

    int ans = 0;
    int lst = -1;
    for(auto [val, cnt] : dp){
        if(cnt > ans){
            ans = cnt;
            lst = val;
        }
    }

    vector<int> ss;
    for(int i = n - 1; i >= 0; --i){
        if(a[i] == lst){
            ss.push_back(i + 1);
            --lst;
        }
    }

    reverse(ss.begin(), ss.end());

    cout << ans << '\n';
    for(int i : ss){
        cout << i << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    solve();

    return 0;
}