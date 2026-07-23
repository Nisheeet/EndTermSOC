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
#define pr(THING) cout << (THING)
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
    cin.tie(nullptr);//comment when interactive
    int TOTAL=1;
    // cin >> TOTAL; //comment when singular
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
    }
}


void solve(int tc){ //use tc for debugging
    inp(n);
    vin(v,n);
    vi freq(101);
    it(i,n) freq[v[i]]++;
    set<int> one,too,many;
    it(i,101){
        if(freq[i] == 1) one.insert(i);
        else if(freq[i] == 2) too.insert(i);
        else if(freq[i] > 2) many.insert(i);
    }

    if(len(one) & 1 and len(many) == 0){
        yn(0);
        return;
    }
    yn(1);
    bool Switch = 1;
    set<int> one1,one2;
    each(num,one){
        if(Switch) one1.insert(num);
        else one2.insert(num);
        Switch ^= 1;
    }
    
    int chosen_one = -1;
    bool done=false;

    if(len(one) & 1){
        each(x,many){
            one2.insert(x);
            chosen_one =x;
            break;
        }
    }
    it(i,n){
        if(one1.find(v[i]) != one1.end()) pr("B");
        else if(((v[i] == chosen_one and done==false) or (v[i] != chosen_one)) and one2.find(v[i]) != one2.end()){
            pr("A");
            if(v[i] == chosen_one) done=true;
        }
        else if(too.find(v[i]) != too.end()){
            if(freq[v[i]] == 2) pr("A");
            else pr("B");
            freq[v[i]]--;
        }
        else pr("B");
    }
    nl;
}