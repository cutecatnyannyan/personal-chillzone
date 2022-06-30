#include<bits\stdc++.h>

using namespace std;

const int64_t mod = 1000000000 + 7;

vector<int64_t> fac;
vector<int64_t> rfac;

int64_t mult(int64_t a, int64_t b){
    return a * b % mod;
}

int64_t add(int64_t a, int64_t b){
    return (a + b) % mod;
}

int64_t binpow(int64_t a, int p){
    if(!p) return 1;
    else if(p & 1) return a * binpow(a, p ^ 1) % mod;
    else{
        int64_t temp = binpow(a, p >> 1);
        return temp * temp % mod;
    }
}

int64_t rev(int64_t a){
    return binpow(a, mod - 2);
}

void calc(int n){
    fac.assign(n + 1, 1);
    rfac.assign(n + 1, 1);
    for(int i = 1; i <= n; ++i){
        fac[i] = mult(fac[i - 1], i);
    }

    rfac[n] = rev(fac[n]);
    for(int i = n - 1; i > 0; --i){
        rfac[i] = mult(rfac[i + 1], i + 1);
    }
}

int64_t pol(vector<int> k){
    int64_t ans = 1;
    int64_t sz = 0;
    for(int i : k){
        sz += i;
        ans = mult(ans, rfac[i]);
    }
    ans = mult(ans, fac[sz]);

    return ans;
}


vector<int> dp, sz;
vector<int> ans;
int n = 0;

vector<vector<int>> g;

void fdfs(int v, int p){
    sz[v] = 1;
    dp[v] = 1;
    for(int to : g[v]){
        if(to == p) continue;

        fdfs(to, v);

        sz[v] += sz[to];
        dp[v] = mult(dp[v], mult(dp[to], rfac[sz[to]]));
    }

    dp[v] = mult(dp[v], fac[sz[v] - 1]);
}

void dfs(int v, int p){
    ans[v] = dp[v];
    for(int to : g[v]){
        if(to ==p) continue;
        int szv = sz[v], szto = sz[to], dpto = dp[to], dpv = dp[v];

        sz[v] = n - sz[to];
        sz[to] = n;
        dp[v] = mult(mult(mult(rfac[n - 1], mult(fac[szto], fac[sz[v] - 1])), rev(dpto)), dpv);
        dp[to] = mult(dpto, mult(dp[v], mult(fac[n - 1], mult(rfac[szto - 1], rfac[sz[v]]))));

        dfs(to, v);

        dp[v] = dpv;
        dp[to] = dpto;
        sz[v] = szv;
        sz[to] = szto;
    }
}

void solve(){
    cin >> n;
    g.assign(n, {});
    dp.assign(n, 0);
    sz.assign(n, 0);
    ans.assign(n, 0);
    calc(n);

    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    fdfs(0, -1);
    dfs(0, -1);

    for(int i : ans){
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}