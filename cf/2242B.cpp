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
#define ab(CONDITION) cout << ((CONDITION) ? "Alice\n" : "Bob\n")
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
    cin >> TOTAL; //comment when singular
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        nl;
    }
}


void solve(int tc){ //use tc for debugging
    inp(n); inp(d);
    vin(v,n);
    vi freq;
    int cur=-1;
    each(x,v){
        if(cur != x){
            cur = x;
            freq.pb(1);
        }
        else freq.back()++;
    }
    shot(freq);
    cur = 0;
    vpii fr;
    each(f,freq){
        if(cur != f){
            cur = f;
            fr.pb(mp(f,1));
        }
        else fr.back().S++;
    }
    int tr = 0;
    int l = len(freq);
    int ans = 0;
    each(f,fr){
        tr = f.F;
        n -= l*tr
        if((d-n) % l == 0) ans++;

        l -= f.S;
    }
    pr(ans);
}