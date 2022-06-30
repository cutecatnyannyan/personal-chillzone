#include<bits\stdc++.h>

using namespace std;

const double PI = atan2(0, -1);

using cd = complex<long double>;

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int64_t> mult(vector<int64_t> const& a, vector<int64_t> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int64_t> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for(int& i : a){
        cin >> i;
    }

    vector<int> s(n + 1, 0);
    s[0] = 0;
    for(int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + ((a[i - 1] < x) ? 1 : 0);
    }

    vector<int64_t> r(n + 1);
    for(int i = 0; i <= n; ++i){
        ++r[s[i]];
    }

    vector<int64_t> v(n + 1);
    for(int i = 0; i <= n; ++i){
        v[i] = r[n - i];
    }

    vector<int64_t> ans = mult(v, r);

    int64_t ans1 = 0;
    int l = 0;
    int rr = 0;
    while(rr < n){
        if(a[rr] < x){
            ans1 += (int64_t)(1 + rr - l) * (rr - l) / 2;
            l = rr + 1;
        }
        ++rr;
    }
    ans1 += (int64_t)(1 + rr - l) * (rr - l) / 2;
    cout << ans1 << ' ';

    for(int i = 1; i <= n; ++i){
        cout << ans[n + i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    solve();

    return 0;
}
