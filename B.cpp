#include<bits\stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a){
        cin >> i;
    }

    if(n % 2 == 0){
        int pos = min_element(a.begin(), a.end()) - a.begin();
        if(pos % 2 == 0){
            cout << "Joe\n";
        }
        else{
            cout << "Mike\n";
        }
    }
    else{
        cout << "Mike\n";
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