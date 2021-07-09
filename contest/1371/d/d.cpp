/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: anish_sk
 * Time: 2020-07-01 19:05:03
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
  
// A utility function to find min of two integers 
int minu(int a, int b) 
{ return (a < b)? a: b; } 
  
// A utility function to find min of three integers 
int min(int a, int b, int c) 
{ return minu(minu(a, b), c);} 
  
// A utility function to find max of two integers 
int max(int a, int b) 
{ return (a > b)? a: b; } 
  
// The main function that prints given matrix in diagonal order 
void diagonalOrder(vvi matrix, int ROW, int COL) 
{ 
    // There will be ROW+COL-1 lines in the output 
    for (int line=1; line<=(ROW + COL -1); line++) 
    { 
        /* Get column index of the first element in this line of output. 
           The index is 0 for first ROW lines and line - ROW for remaining 
           lines  */
        int start_col =  max(0, line-ROW); 
  
        /* Get count of elements in this line. The count of elements is 
           equal to minimum of line number, COL-start_col and ROW */
         int count = min(line, (COL-start_col), ROW); 
  
        /* Print elements of this line */
        for (int j=0; j<count; j++) 
            printf("%5d ", matrix[minu(ROW, line)-j-1][start_col+j]); 
  
        /* Ptint elements of next diagonal on next line */
        printf("\n"); 
    } 
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll ct = 0;
        vvl matrix(n, vll(n,0));
        ll g = k/n;
        ll extra = k - g*n;
        for(int i=0; i<n;i++){
            ll count = g;
            if(i<extra) count++;
            for(int j = 0; j< count; j++){
                matrix[i][(i+j)%n] = 1; 
            }
        }
        ll f = 0;
        if(k%n) f = 2;
        cout<<f<<"\n";
        forn(i,n){
            forn(j,n){
                cout<<matrix[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
