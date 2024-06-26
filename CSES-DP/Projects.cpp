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






// dp(i) = max money of subseq where the last project is a[i]
// dp(i) = max(dp[j] + a[i]) where 0<=j<i 
void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, pii>> a(n);
    rep(i,0,n) {
        int l, r, c;
        cin>>l>>r>>c;
        a[i] = {l, {r, c}};
    }
    sort(all(a));

    vll dp(n+1);
    rrep(i,n-1,0) {
        // dont take
        dp[i] = dp[i+1];

        // take
        int r = a[i].second.first;
        int pos = upper_bound(all(a), mp(r, mp(INF, INF))) - a.begin();
        dp[i] = max(dp[i], dp[pos] + a[i].second.second);
    }

    cout<<dp[0]<<'\n';
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
    int t = 1;
    // cin >> t;
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