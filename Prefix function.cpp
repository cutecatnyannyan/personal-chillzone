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
    vector<int> p = prefix(s);

    return 0;
}