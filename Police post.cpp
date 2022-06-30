#include<bits\stdc++.h>

using namespace std;

vector<vector<int>> g;

set<pair<int, int>> bfs(vector<int> p){
    int n = g.size();
    deque<int> q;
    vector<int> d(n, -1);
    for(int i = 0; i < p.size(); ++i){
        q.push_back(p[i]);
        d[p[i]] = i;
    }

    set<pair<int, int>> ans;
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(int to : g[v]){
            if(d[to] != -1){
                if(d[to] != d[v]){
                        ans.insert({min(v, to), max(v, to)});
                }
                continue;
            }
            d[to] = d[v];
            q.push_back(to);
        }       
    }

    return ans;
}

void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> p(k, 0);
    g.assign(n, {});
    for(int& i : p){
        cin >> i;
        --i;
    }
    map<pair<int, int>, int> num;
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
        num[{min(x, y), max(x, y)}] = i;
    }

    set<pair<int, int>> ans = bfs(p);

    cout << ans.size() << '\n';
    for(auto e : ans){
        cout << num[e] + 1 << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}