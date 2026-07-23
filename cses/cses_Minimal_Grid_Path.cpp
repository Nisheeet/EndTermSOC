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

void solve(int tc){ //use tc for debugging
    inp(n);
    vector<string> v(n);
    it(i,n) cin >> v[i];
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    string ans(2*n-1,' ');
    ans[0] = v[0][0]; dp[0][0] = true;
    ite(k,1,2*n-1){
        char mnc = 'z';
        for(int i=max(0ll,k-n+1);i<n and k-i>=0 and k-i<n; i++){
            if((i > 0 and dp[i-1][k-i]) or (k-i > 0 and dp[i][k-i-1])) mnc=min(mnc,v[i][k-i]);
        }
        for(int i=max(0ll,k-n+1);i<n and k-i>=0 and k-i<n; i++){
            if(v[i][k-i] == mnc and ((i > 0 and dp[i-1][k-i]) or (k-i > 0 and dp[i][k-i-1]))) dp[i][k-i] = true;
        }
        ans[k] = mnc;
    }
    pr(ans);
    
}