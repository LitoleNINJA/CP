#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define rep(i, s, n) for(int i=s; i<n; i++)
#define rrep(i, n, s) for(int i=n; i>=s; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
const int mod = 1e9 + 7;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif






// dp(i, 1) = # of ways to build tower of height i where ith level is 2 blocks of size 1
// dp(i, 2) = # of ways to build tower of height i where ith level is 1 block of size 2
// dp(i, 2) = 2 * dp(i-1, 2) + dp(i-1, 1) 
// dp(i, 1) = dp(i-1, 2) + 4 * dp(i-1, 1) 
ll dp[1000005][3];
int n;
ll rec(int i, int prev) {
    debug(i, prev);
    if(i == 1)
        return 1;

    if(dp[i][prev] != -1)
        return dp[i][prev];

    ll ans = 0;
    if(prev == 1)
        ans = (ans + 4ll * rec(i-1, 1) % mod + rec(i-1, 2)) % mod;
    else if(prev == 2)
        ans = (ans + rec(i-1, 1) + 2ll * rec(i-1, 2) % mod) % mod;

    return dp[i][prev] = ans;
}
void Solve()
{
    cin >> n;
    ll ans = (rec(n, 1) + rec(n, 2)) % mod;
    cout<<ans<<'\n';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        Solve();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cerr << "\n\nTime : " << fixed
         << time_taken << setprecision(9);
    cerr << " sec" << endl;
    return 0;
}