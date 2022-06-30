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

    int mx = -1e9 - 1;
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] > mx){
                mx = v[i][j];
                pos.clear();
                pos.push_back({i, j});
            }
            if(v[i][j] == mx){
                pos.push_back({i, j});
            }
        }
    }

    int h = 1e9;
    int w = 1e9;
    for(auto [x, y] : pos){
        int curh = max({x + 1, n - x});
        int curw = max({y + 1, m - y});
        h = min(h, curh);
        w = min(w, curw);
    }

    cout << h * w << '\n';
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