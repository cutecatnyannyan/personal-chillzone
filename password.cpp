#include<bits\stdc++.h>

using namespace std;

vector<int> prefix(string s){
    int n = s.size();
    vector<int> p(n, 0);

    for(int i = 1; i < n; ++i){
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = p[j - 1];
        }
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }

    return p;
}

int main(){
    string s;
    cin >> s;

    int n = s.size();

    vector<int> p = prefix(s);

    int ans = 0;

    for(int i = 0; i < n - 1; ++i){
        if(p[i] == p.back()){
            ans = p.back();
        }
    }

    if(ans == 0 && p.back() != 0){
        ans = p[p.back() - 1];
    }

    if(ans == 0){
        cout << "Just a legend\n";
    }
    else{
        cout << s.substr(0, ans) << '\n';
    }

    return 0;
}