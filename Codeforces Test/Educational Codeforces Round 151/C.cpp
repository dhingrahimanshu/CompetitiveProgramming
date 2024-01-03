        
/* 

Author :: Bot Anshu 

        ~All our knowledge has its origins in our perceptions - Leonardo Da Vinci.

*/
    
    

#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print(a) for(auto i:a){ cout<<i<<' ' ;}cout<<endl; 
#define read(x) int x ; cin>>x;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple
#define eb emplace_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;


#ifdef botanshu
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef __int128 ell;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/

bool flag = false;

int n,m;
void helper(vector<vector<int>>& stor, string a , string b){
    vector<vector<pair<int,bool>>>dp;
    dp.resize(20 , vector<pair<int,bool>>(10 ,{0,false}));
    
    for(int i =(a[0]-'0');i<=(b[0]-'0');i++){
        auto it =lower_bound(all(stor[i]),0);
        if(it==stor[i].end()){
            flag = true;
            return;
        }else{ 
            dp[0][i].first = *it;
        }
    }
    
    
    for(int i =1 ;i<m;i++){
        for(int j = (a[i-1]-'0') ; j<=(b[i-1]-'0');j++){
            for(int k  = (a[i]-'0');k<=(b[i]-'0');k++){
                // cout << j << ' ' << k <<endl;
                if(dp[i-1][j].second){
                    dp[i][k].second = true;
                    dp[i][k].first = dp[i-1][j].first;
                }else{
                    int uf = dp[i-1][j].first;
                    auto it = lower_bound(all(stor[k]) ,uf+1);
                    // if(i==1 && j==2 && k==3){
                    //     cout << uf << " " << (*it) <<endl;
                    // }
                    if(it==stor[k].end()){
                       
                        dp[i][k].second=true;
                        flag = true;
                    }else{
                        dp[i][k].first = max(dp[i][k].first ,(*it));
                    }
                }
            }
        }
    }
    // cout << dp[3][3].first <<endl;
    
    for(int i =0;i<10;i++){
        if(dp[m-1][i].second){
            flag = true;
            return;
        }
    }

}

void solve() {
    flag = false;
    vector<vector<int>>stor;
     stor.resize(20 , vector<int>());
    
    string s; cin>>s;
    map <int , bool > val;
    for(int i =0 ;i<sz(s);i++){
        stor[(s[i]-'0')].pb(i);
        val[(s[i]-'0')]=1;
    } 
    // debug(stor);
    cin>>m;
    n = sz(s);
    string a,b; cin>>a>>b;
    if(m==1){
        bool flag = false;
        for(int i = (a[0]-'0');i<=(b[0]-'0');i++){
            if(val[i]==0){
                flag = true;
                break;
            }
        }
        cout << (flag?"YES":"NO") <<endl;
        return;
    }
    
    helper( stor ,a , b);
    cout << (flag?"YES":"NO") <<endl;
}



int main() {
#ifdef botanshu
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    int t =1;
    cin>>t;
    while(t--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef botanshu
    cerr <<endl<< "Time: " << duration . count() / 1000 << endl;
#endif
}
