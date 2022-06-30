#include<bits\stdc++.h>


using namespace std;

void solve(){
    int v;
    cin >> v;

    array<int, 9> a;

    for(int i = 0; i < 9; ++i){
        cin >> a[i];
    }

    int mn = *min_element(a.begin(), a.end());

    int cnt = v / mn;

    string ans = "";
    for(int i = 1; i <= cnt; ++i){
        for(int j = 8; j >= 0; --j){
            if(a[j] + (cnt - i) * mn <= v){
                ans.push_back(char('1' + j));
                v -= a[j];
                break;
            }
        }
    }
    if(cnt == 0) ans = "-1";

    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int ttt = 1;

    while(ttt--){
        solve();
    }

    return 0;
}