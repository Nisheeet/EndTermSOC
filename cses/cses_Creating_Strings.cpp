#include<bits/stdc++.h>
using namespace std;

#define int ll

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

#define it(ITR,END) for (int ITR = (0); ITR < (END); ++ITR)
#define ite(ITR,START,END) for (int ITR = (START); ITR < (END); ++ITR)
#define rite(ITR,START,END_INCLUSIVE) for (int ITR = (START); ITR >= (END_INCLUSIVE); --ITR)

#define each(ELEMENT,ITERABLE) for (auto &ELEMENT : ITERABLE)
#define pt(ITER) each(EL,ITER) cout << EL << " "; cout << '\n'
#define vin(VECTER,NUM) vi VECTER(NUM); each(LEE,VECTER) cin >> LEE

#define yn(condition) cout << ((condition) ? "YES\n" : "NO\n")
#define inp(NUMERO) int NUMERO; cin >> NUMERO
#define sip(SENTENC) string SENTENC; cin >> SENTENC

#define len(ITERABLE) (int)(ITERABLE).size()
#define all(ITERABLE) (ITERABLE).begin(), (ITERABLE).end()
#define rall(ITERABLE) (ITERABLE).rbegin(), (ITERABLE).rend()
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort(rall(ITERABLE))

#define bit_len(NUMERO) (NUMERO == 0 ? 0 : 64 - __builtin_clzll(NUMERO))

#define pb push_back
#define F first
#define S second

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); //comment when interactive
    int TOTAL=1;
    // cin >> TOTAL; //comment when singular
    // cout << "\n";
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        // cout << "\n";
    }
}

vector<string> VEC;
void make(int LEN, vi& VIT, string STR=""){
    if(LEN == 0){   
        VEC.pb(STR);
        return;
    }
    each(CHAR,STR){
        if(VIT[CHAR-'a']){
            VIT[CHAR-'a']--;
            STR.pb(CHAR);
            make(LEN-1, VIT, STR);
            STR.pop_back();
            VIT[CHAR-'a']++;
        }
    }
}

void solve(int tc){ //use tc for debugging
    sip(s);
    vi fr(26,0);
    each(c,s){
        fr[c-'a']++;
    }
    make(len(s),fr);
    cout << len(VEC) << "\n";
    each(sin,VEC) cout << sin << "\n";
}