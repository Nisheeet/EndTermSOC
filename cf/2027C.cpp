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

#define len(ITERABLE) ((int)(ITERABLE).size())
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
    inp(n); inp(m);
    int high = (n*(n+1))/2;
    int low = n;
    if(m < low or m > high){
        pr(-1);
        return;
    } 
    int val = 8*(m-n)+1;
    int s = sqrt(val);
    vi mins;
    int a = (s+1)/2;
    if(s*s == val){
        int c = n-a;
        it(i,c) mins.pb(1);
        it(i,a) mins.pb(i+1);
    }
    else{
        int c = n-a-1;
        int b = m-c-(a*(a+1))/2;
        it(i,c) mins.pb(1);
        // pr(a); pr(b); pr(c);
        it(i,a){
            if(i+1 == b) mins.pb(i+1);
            mins.pb(i+1);
        }
    }
    reverse(all(mins));
    set<int> vals;
    it(i,n) vals.insert(i+1);

    int cur = n+1;
    vi line(n);
    pt(mins);
    
    it(i,n){
        line[i] = cur == mins[i] ? *vals.rbegin() : mins[i];
        cur = mins[i];
        vals.erase(line[i]);
    }
    pr(line[0]); nl;
    it(i,n-1){
        pr(line[i]); pr(line[i+1]); nl;
    }
}