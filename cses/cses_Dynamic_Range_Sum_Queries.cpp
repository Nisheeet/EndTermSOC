#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

using pii = pair<int,int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;

#define it(ITR,TOTAL) for (int ITR = 0; ITR < (TOTAL); ++ITR)
#define ite(ITR,START,END) for (int ITR = (START); ITR < (END); ++ITR)
#define rit(ITR,TOTAL) for (int ITR = (TOTAL-1); ITR >= 0; --ITR)
#define rite(ITR,START,END_INCLUSIVE) for (int ITR = START; ITR >= END_INCLUSIVE; --ITR)
#define each(ELEMENT,ITERABLE) for (auto &ELEMENT : ITERABLE)

#define vin(VECTER,NUM) vi VECTER(NUM); each(LEE,VECTER) cin >> LEE
#define inp(NUMERO) int NUMERO; cin >> NUMERO
#define sip(SENTENC) string SENTENC; cin >> SENTENC

#define yn(CONDITION) cout << ((CONDITION) ? "YES\n" : "NO\n")
#define pr(THING) cout << (THING) << " "
#define nl cout << "\n"
#define pt(ITER) each(EL,ITER) cout << EL << " "; nl

#define len(ITERABLE) (int)(ITERABLE).size()
#define all(ITERABLE) (ITERABLE).begin(), (ITERABLE).end()
#define rall(ITERABLE) (ITERABLE).rbegin(), (ITERABLE).rend()
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort(rall(ITERABLE))

#define bit_len(NUMERO) ((NUMERO) == 0 ? 0 : 64 - __builtin_clzll(NUMERO))
#define pb push_back
#define mp make_pair
#define F first
#define S second

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); nl;//comment when interactive
    int TOTAL=1;
    // cin >> TOTAL; //comment when singular
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
    }
}

int sum(int a, int b, vi& tree, int n){
    a += n;
    b += n;
    int s=0;
    while(a<=b){
        if(a&1) s += tree[a++];
        if(!(b&1)) s += tree[b--];
        a >>= 1; b >>= 1;
    }
    return s;
}

void update(int k, int a, vi& tree, int n){
    k += n;
    tree[k] = a;
    k >>= 1;
    for(;k>0;k>>=1){
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

void solve(int tc){ //use tc for debugging
    inp(n); inp(q);
    if(n==1){
        inp(x);
        while(q--){
            inp(qt); inp(a); inp(b);
            if(qt == 1) x = b;
            else{
                pr(x);
                nl;
            }
        }
        return;
    }
    vin(v,n);
    int l = 1;
    while(l < n) l <<= 1;
    vi tree(2*l);
    it(i,n) tree[i+l] = v[i];
    rite(i,l-1,1) tree[i] = tree[2*i] + tree[2*i+1];
    while(q--){
        inp(qt); inp(a); inp(b);
        if(qt == 1){
            update(a-1,b,tree,l);
        }
        else{
            pr(sum(a-1,b-1,tree,l));
            nl;
        }
    }
    
}