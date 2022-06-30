#include<bits\stdc++.h>

using namespace std;

int n;
set<int> used;
set<pair<int, int>> bans;

void dfs(int v){
    used.erase(v);
    //cout << 1;
    auto cur = used.lower_bound(0);
    while(!used.empty() && cur != used.end()){
        int to = *cur;
        if(bans.count({v, to})){
            cur = used.upper_bound(to);
            continue;
        }
        dfs(to);
        cur = used.upper_bound(to);
    }
}

void solve(){
    int m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        bans.insert({x, y});
        bans.insert({y, x});
    }
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        if(!bans.count({0, i})) ++cnt;
    }
    for(int i = 1; i < n; ++i){
        used.insert(i);
    }

    int pp = 0;
    for(int i = 1; i < n; ++i){
        if(!used.count(i) || bans.count({0, i})) continue;
        dfs(i);
        ++pp;
    }

    if(used.empty() && cnt >= k && pp <= k){
        cout << "possible\n";
    }
    else{
        cout << "impossible\n";
    }

}

int main(){
    //ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}