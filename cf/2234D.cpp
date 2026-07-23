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

string xsor(string a, string b){
    if(len(a) != len(b)) return "-";
    int n = len(a);
    string ans(n,' ');
    it(i,n) ans[i] = (a[i] == b[i]) ? '0' : '1';
    return ans;
}

pii madefrom(int a){
    if(a%2 == 0) return mp(a-1,a+1);
    int k = (a >> 1) << 1;
    k &= -k;
    return mp(a-k,a+k);
}
int stebits(string s){
    int ct=0;
    each(x,s) if(x=='1')ct++;
    return ct;
}

void solve(int tc){ //use tc for debugging
    inp(n); inp(k);
    sip(s); sip(z);
    vi ones(3);
    vi mul(3);
    int num = ((1<<k)+1)/3;
    if(k&1) mul[0] = mul[1] = mul[2] = num;
    else {mul[0] = mul[2] = num+1; mul[1] = num;}
    it(i,n){
        if(s[i] == '1') ones[0]++;
        if(s[i] != z[i]) ones[1]++;
        if(z[i] == '1') ones[2]++;
    }
    int ans = 0;
    it(i,3) ans += ones[i]*(n-ones[i])*mul[i];
    pr(ans);
}