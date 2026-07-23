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
    sip(a); sip(b);
    
    int n=len(a);
    int m=len(b);
    vvi mod(n+1,vi(m+1));
    vi sa(n+1), sb(m+1);

    it(i,n) sa[i+1] = (sa[i] + a[i] - '0') % 10;
    it(i,m) sb[i+1] = (sb[i] + b[i] - '0') % 10;

    vpii valid; 
    ite(i,1,n+1){
        ite(j,1,m+1){
            mod[i][j] = (sa[i]-sb[j]+10)%10;
            if(mod[i][j] == 0) valid.pb(mp(i,j));
        }
    }
    shot(valid);
    // each(x,valid){
    //     pr(x.F);
    //     pr(x.S);
    //     nl;
    // }
    if(mod[n][m] != 0){
        pr(-1); return;
    }
    int ans = 0;
    int r = 0;
    int c = 0;
    auto it = valid.begin();
    while(true){
        auto it = upper_bound(all(valid),mp(r,c));
        if(it == valid.end()) break;
        // pr((*it).F);
        // pr((*it).S);
        // nl;
        r = (*it).F+1;
        c = (*it).S;
        ans++;
    }
    // each(v,mod){pt(v);}
    pr(ans);
}