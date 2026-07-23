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

int MAXN = 1e6;
vi spf(MAXN+1, -1);
void init(){
    for(int i = 2; i <= MAXN; i++) {
        if(spf[i] == -1 && i * i <= MAXN) {
            for(int j = i * i; j <= MAXN; j += i){
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
}

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); nl;//comment when interactive
    int TOTAL=1;
    cin >> TOTAL; //comment when singular
    init();
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
    }
}


void solve(int tc){ //use tc for debugging
    inp(n);
    vin(v,n);
    if(is_sorted(all(v))){
        ab(0); return;
    }
    vvi facs(n,vi(1,1));
    it(i,n){
        int x = v[i];
        while(x > 1){
            if(spf[x] == -1){
                facs[i].pb(x);
                break;
            }
            else{
                facs[i].pb(spf[x]);
                x /= spf[x];
            }
        }
    }
    bool res=false;
    it(i,n-1){
        if(facs[i].back() > (spf[v[i+1]] == -1 ? v[i+1] : spf[v[i+1]])){
            res=true;
            break;
        }
    }
    if(res == false){
        it(i,n){
            if((len(facs[i]) > 2) and (facs[i].back() > facs[i][1])){
                res=true;
                break;
            }
        }
    }
    ab(res);
}