/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: anish_sk
 * Time: 2020-05-14 01:10:20
**/
#include<bits/stdc++.h>
#include<iomanip>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#include<stdlib.h>
#include<stdio.h>
using namespace __gnu_pbds; //required
#define ll long long
#define ull unsigned ll
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mul(x,y) ((ll)(x)*(y))%mod
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define forn(i, n)    for(int i = 0; i < n; i++)
#define FOR(i, x, y)  for(size_t i=size_t(x); i<size_t(y); i++)
#define ROF(i, x, y)  for(size_t i=size_t(x-1); i>=size_t(y); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
int clz(unsigned long long N) {
    return N ? 64 - __builtin_clzll(N) : -INFINITY;
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;
gp_hash_table<long long, int, custom_hash> safe_hash_table;
template<typename T>
ostream& operator<<(ostream& os, const pair<T,T> &p){
    os<<"["<<p.first<<", "<<p.second<<" ]";
    return os ;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}
template <typename T>
istream& operator>>(istream& os, vector<T>& v)
{
    //int temp;
    for (unsigned int i = 0; i < v.size(); ++i) {
        os>>v[i];
    }
    return os;
}
template <typename T>
void o1(vector<T> &v){
    for(auto i: v) cout<<i<<" ";
    cout<<"\n";
}
//template<typename T>
void google(int cas){
    cout<<"Case #"<<cas<<": ";
}
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define vll vector<ll>
#define vvl vector<vll>
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void make_set(ll v, vll &parent, vll &size) {
    parent[v] = v;
    size[v] = 1;
}
ll find_set(ll v, vll &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v],parent);
}
void union_sets(ll a, ll b,vll &parent, vll &size) {
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
void dfsvisit(vvl &adj,vll &visited, ll v, vll &col){
    visited[v]=1;
    for(auto i: adj[v]){
        if(!visited[i]){
        col[i] = 1 - col[v];
        dfsvisit(adj, visited, i, col);
        }
    }
}
ll MPOW( ll a, ll b, ll m) { if(b==0) return 1; ll x=MPOW(a,b/2,m); x=(x*x)%m; if(b%2==1) x=(x*a)%m; return x;}
ll MINV( ll a, ll m) { return MPOW(a,m-2,m);}
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
inline T ceil(T a, T b){
    return ((a+b-1)/b);
}
void dfs(vector<vll> &adj,ll u, ll v, vll &depth, vll &count){
    count[u]=1;
    for(auto i : adj[u]){
        if(i==v) continue;
        depth[i]=depth[u]+1;
        dfs(adj, i, u, depth, count);
        count[u]+=count[i];
    }
} 
vector<vector<ll>> primes;
vector<vector<ll>> facts;
void init_prime(ll size=1e6+1)
{
	primes.resize(size);
 
	for(ll i=2;i<size;i++)
	{
		if(primes[i].size()==0)
		{
			for(ll j=i;j<size;j+=i)
			primes[j].push_back(i);
		}
	}
}
 
void init_facts(ll size=2e5+1)
{
	facts.resize(size);
 
	for(ll i=1;i<size;i++)
	{
		for(ll j=i;j<size;j+=i)
		facts[j].push_back(i);
	}
}
ll p =1e9+7;
string hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        ll n; cin>>n;vector<vector<bool>> a;
        forn(i,n){
            string s = "";
            forn(j, n/4){
                char c; cin>>c;
                s+=hex_char_to_bin(c);
            }
            vector<bool> b;
            for (auto j: s) {
                b.pb(j=='1');
            }
            a.pb(b);
        }

        
        vector<vector<int>> pre(n+1, vector<int>(n+1,0));
        vector<vector<int>> vert(n+1, vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vert[i][j] = vert[i-1][j] + a[i-1][j-1];
                pre[i][j] = pre[i][j-1] + vert[i][j];
            }
        }
        //for(auto i: pre){
        //    cout<<i<<"\n";
        //}
        int ans = 0;
        int x = 1;
        for(x=n;x>=1;x--){
            if(n%x == 0){
                bool flag = 1;
                for(int i=0; i<n/x; i++){
                    for(int j=0; j<n/x; j++){
                        int l1 = i*x, l2=l1 + x;
                        int r1 = j*x, r2 =r1+x;
                        int s = pre[l2][r2] - pre[l1][r2] - pre[l2][r1] + pre[l1][r1];
                        if(s!= x*x && s!=0){
                            flag = 0;
                        }
                    }
                }
                if(flag) break;
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}
