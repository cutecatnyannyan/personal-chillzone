#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
const int SIZE = 1e7;
int l[SIZE], r[SIZE], NODES = 0;
int64_t st[SIZE];
int newleaf(int value) {
    int p = ++NODES;
    l[p] = r[p] = 0; // null
    st[p] = value;
    return p;
}
int newparent(int lef, int rig) {
    int p = ++NODES;
    l[p] = lef;
    r[p] = rig;
    st[p] = st[lef] + st[rig]; // immediately update value from children
    return p;
}

#define M ((L+R)/2)
int build(vector<int>& v, int L=0, int R=n-1) {
    if (L == R) return newleaf(v[L]); // construct as leaf
    else return newparent(build(v, L, M), build(v, M+1, R)); // construct as parent
}

bool hasflag[SIZE]; // if node has a flag (sometimes, you can omit this)
int flag[SIZE];     // the actual value of the flag

// returns a new node with a lazy flag
int newlazykid(int node, int delta, int L, int R) {
    int p = ++NODES;
    l[p] = l[node];
    r[p] = r[node];
    flag[p] = flag[node] + delta; // need this since lazy kid might be lazy before
    hasflag[p] = true;
    
    /* range increase */
    st[p] = st[node] + (R - L + 1) * delta;
    /* edit depending on the problem */
    
    return p;
}

void propagate(int p, int L, int R) {
    if (hasflag[p]) {
        if (L != R) { // spread the laziness
            l[p] = newlazykid(l[p], flag[p], L, M);
            r[p] = newlazykid(r[p], flag[p], M + 1, R);
        }
        // reset flag
        hasflag[p] = false;
        flag[p] = 0;
    }
}

int update(int a, int b, int x, int p, int L=0, int R=n-1) {
    if (b < L || R < a)   return p;
    if (a <= L && R <= b) return newlazykid(p, x, L, R); 
    propagate(p, L, R); // always do this before going down
    return newparent(update(a, b, x, l[p], L, M),
                     update(a, b, x, r[p], M + 1, R));
}

int64_t query(int a, int b, int p, int L=0, int R=n-1) {
    if (b < L || R < a)   return 0;
    if (a <= L && R <= b) return st[p];
    propagate(p, L, R); // always do this before going down
    return query(a, b, l[p], L, M) + query(a, b, r[p], M + 1, R);
}