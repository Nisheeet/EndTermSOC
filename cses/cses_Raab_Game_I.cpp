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
    cin >> TOTAL; //comment when singular
    cout << "\n";
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        // cout << "\n";
    }
}


void solve(int tc){ //use tc for debugging
    inp(n);
    inp(a); inp(b);
    bool res = true;
    if(n < a+b or (a==0 ^ b==0)) res=false;
    yn(res);
    int ab=n,bb=n;
    int as=1,bs=1;
    vi bl(n,0);
    if(res){
        vi out(n);
        it(i,n){
            out[i] = i+1;
            cout << i+1 << " ";
        }
        cout << "\n";

        int done = (a+b);
        int pu = n-a;
        int pd = 1;
        while(done){
            pu %= n;
            out[pu] = pd;
            pu++;
            if(pd == b) pd=n-a+1;
            else pd++;
            done--;
        }
        it(i,n) cout << out[i] << " ";
        cout << "\n";
    }
}