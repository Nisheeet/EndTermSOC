#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

#define int ll

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
    cout << "\n";
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        // cout << "\n";
    }
}


void solve(int tc){ //use tc for debugging
    inp(n); inp(t);
    vin(k,n);
    shot(k);
    int l = 0;
    int r = k[0]*t;
    int final = r;
    while(l <= r){
        int m = (l+r)/2;
        int floorsum=0;
        each(x,k){
            floorsum += m/x;
            if(floorsum >= t) break;
        }
        if(floorsum >= t){
            final=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout << final << "\n";
}