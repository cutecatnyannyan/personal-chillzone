#include<bits\stdc++.h>

using namespace std;

vector<int> path;

bool dfs(int64_t a, int64_t b){
    if(a > b) return false;
    if(a == b){ 
        path.push_back(a);
        return true;    
    }
    if(dfs(2 * a, b)){
        path.push_back(a);
        return true;
    }
    if(dfs(10 * a + 1, b)){
        path.push_back(a);
        return true;
    }
    return false;
}

void solve(){
    int a, b;
    cin >> a >> b;
    if(dfs(a, b)){
        cout << "YES\n";
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for(int i : path){
            cout << i << ' ';
        }
        cout << '\n';
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