#include<bits\stdc++.h>

using namespace std;

int64_t mod = 1000000007;

struct Matrix{
    vector<vector<int>> v;
    int n;
    int m;

    Matrix(int n_, int m_, int f = 0){
        n = n_;
        m = m_;
        vector<int> sup(m, f);
        v.assign(n, sup);
    }

    Matrix(int n_, int m_, bool flag){
        n = n_;
        m = m_;
        assert(n == m);
        vector<int> sup(m, 0);
        v.assign(n, sup);

        for(int i = 0; i < n; ++i){
            v[i][i] = 1;
        }
    }

    pair<int, int> size(){
        return {n, m};
    }

    bool isSquare(){
        return n == m;
    }

    bool isCorrect(){
        if(v.size() != n) return false;

        for(int i = 0; i < n; ++i){
            if(v[i].size() != m) return false;
        }

        return true;
    }

    int get(int i, int j){
        return v[i][j];
    }


    int operator[](pair<int, int> p){
        return v[p.first][p.second];
    }

    Matrix operator+(Matrix b){
        assert(size() == b.size());
        Matrix ans(n, m);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans.v[i][j] = v[i][j] + b.v[i][j];
            }
        }

        return ans;
    }

    Matrix operator-(){
        Matrix ans(n, m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans.v[i][j] = -v[i][j];
            }
        }
        return ans;
    }

    Matrix operator-(Matrix b){
        return *this + (-b);
    }

    Matrix operator*(int l){
        Matrix ans(n, m);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans.v[i][j] = l * v[i][j];
            }
        }

        return ans;
    }


    Matrix operator*(Matrix b){
        assert(m == b.n);
        Matrix ans(n, b.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < b.m; ++j){
                for(int k = 0; k < m; ++k){
                    ans.v[i][j] = (ans.v[i][j] + (int64_t)v[i][k] * b.v[k][j] % mod) % mod; 
                }
            }
        }

        return ans;
    }

    ~Matrix() = default;
};


Matrix binpow(Matrix& a, int64_t p){
    cerr << 1 << '\n';
    assert(a.isSquare());
    if(p == 0) return Matrix(a.n, a.m, true);
    else if(p & 1){
        return binpow(a, p - 1) * a;
    }
    else{
        Matrix temp = binpow(a, p >> 1);
        return temp * temp;
    }
}

ostream& operator<<(ostream& out, Matrix a){
    for(int i = 0; i < a.n; ++i){
        for(int j = 0; j < a.m; ++j){
            out << a.v[i][j] << ' ';
        }
        out << '\n';
    }

    return out;
}

int main(){
    int64_t n;
    int m, k;
    cin >> n >> m >> k;

    Matrix sup(m, m, 1);
    Matrix ed(m, 1, 1);

    for(int i = 0; i < k; ++i){
        string s;
        cin >> s;
        int a = (s[0] <= 'Z') ? s[0] - 'A' + 26 : s[0] - 'a';
        int b = (s[1] <= 'Z') ? s[1] - 'A' + 26 : s[1] - 'a';
        sup.v[a][b] = 0;
    }

    sup = binpow(sup, n - 1);

    Matrix sans = sup * ed;

    int64_t ans = 0;

    for(int i = 0; i < m; ++i){
        ans = (ans + sans.v[i].back()) % mod;
    }

    cout << ans << '\n';

    return 0;
}


