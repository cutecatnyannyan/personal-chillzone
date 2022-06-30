#include<bits\stdc++.h>

using namespace std;

struct Matrix{
    vector<vector<int>> v;
    int n;
    int m;

    Matrix(int n_, int m_){
        n = n_;
        m = m_;
        vector<int> sup(m, 0);
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
                    ans.v[i][j] += v[i][k] * b.v[k][j]; 
                }
            }
        }

        return ans;
    }

};


Matrix binpow(Matrix a, int p){
    assert(a.isSquare());
    if(p == 0) return Matrix(a.n, a.m, true);
    else if(p & 1){
        return a * binpow(a, p - 1);
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
    int n;
    cin >> n;
    Matrix m(n, n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> m.v[i][j];
        }
    }

    cout << binpow(m, 2);

    return 0;
}