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
    cin >> TOTAL; //comment when singular
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        nl;
    }
}

const int MOD = 998244353;
int power(int base, int exp){
    int ans = 1;
    while(exp > 0){
        if(exp&1) ans = ans * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}
void solve(int tc){ //use tc for debugging
    inp(n);
    vpii tree(n+1); //parent,level
    tree[1] = mp(0,0);
    vi depths(n+1,1);

    int max_depth = 0;
    it(i,n-1){
        inp(x);
        tree[i+2] = mp(x,tree[x].S+1);
        max_depth = max(max_depth,tree[x].S+1);
    }
    vvi levels(max_depth+1);
    ite(i,1,n+1){
        levels[tree[i].S].pb(i);
    }
    int ans = 0;
    ite(lvl,1,max_depth+1){
        // pt(levels[lvl]);
        set<int> uniq;
        each(house,levels[lvl]){
            uniq.insert(tree[house].F);
        }
        ans += (1 << len(uniq)) - 1;
    }
    // rite(i,max_depth,0){
    //     each(val,levels[i]){
    //         int parent = tree[val].F;
    //         depths[parent] += depths[val];
    //     }
    // }
    // ite(i,1,n+1){
    //     pr(i); pr(depths[i]); nl;
    //     ans += depths[i];
    // }
    // pt(depths);
    pr(ans);
}