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
    for (int i = 0; i < v.size(); ++i) {
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
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void make_set(int v, vector<int> &parent, vector<int> &size) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v,vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v],parent);
}
void union_sets(int a, int b,vector<int> &parent, vector<int> &size) {
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
void dfsvisit(vvi &adj,vi &visited, int v, vi &col){
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
void dfs(vector<vll> &adj,int u, int v, vll &depth, vll &count){
    count[u]=1;
    for(auto i : adj[u]){
        if(i==v) continue;
        depth[i]=depth[u]+1;
        dfs(adj, i, u, depth, count);
        count[u]+=count[i];
    }
}
void height_calc(vector<vll> &adj,int u, int v, vll &depth, vll &d, vll &h){
    //cout<<u<<" "<<flush;
    ll mx = 0;
    if(d[u]==1 && v!=-1){
        h[u]=0;
        return;
    }
    for(auto i : adj[u]){
        if(i!=v){
            height_calc(adj, i, u, depth, d, h);
        }
        mx=max(mx,h[i]);
    }
    h[u]=mx+1;
} 
ll eval(ll x, ll y, ll z){
    ll sum = 0;
    ll a = abs(x-y);
    ll b = abs(y-z);
    ll c= abs(x-z);
    sum+= a*a;
    sum+= b*b;
    sum+= c*c;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;
    //t=1;
    while(t--){
        ll r1,g1,b1; cin>>r1>>g1>>b1; vector<ll> r(r1),g(g1),b(b1); cin>>r;cin>>g;cin>>b;
        sort(all(r));sort(all(g));sort(all(b));
        ll sum= LLONG_MAX;
        ll mi = LLONG_MAX;
        forn(i,g1){
            ll y = g[i];
            ll xl=0,xu=0,zl=0,zu=0;
            if(upper_bound(all(r),y)==r.end()){
                xu = r.back();
            }
            else{
                xu=*upper_bound(all(r),y);
            }
            if(upper_bound(all(b),y)==b.end()){
                zu = b.back();
            }
            else{
                zu=*upper_bound(all(b),y);
            }
            size_t lx=0,lz=0;
            lx=(lower_bound(all(r),y)-r.begin());
            if(lx>0 && r[lx] == xu){
                xl=r[lx-1];
            }
            else{
                xl=r[lx];
            }
            lz=(upper_bound(all(b),y)-b.begin());
            if(lz > 0 && r[lz] == zu){
                zl = b[lz-1];
            }
            else{
                zl = zu;
            }
            sum = eval(xl,y,zl);
            mi = min(mi, sum);
            sum = eval(xu,y, zl);
            mi = min(mi, sum);
            sum = eval(xl,y,zu);
            mi = min(mi, sum);
            sum = eval(xu,y,zu);
            mi = min(mi, sum);
            // if(lx==0 && r1>0){
            //     xl=r[lx+1];
            // }
            // sum = eval(xl,y,zu);
            // mi = min(mi, sum);
            // sum = eval(xl,y,zl);
            // mi = min(mi, sum);
            //cout<<xl<<" "<<xu<<" "<<y<<" "<<zl<<" "<<zu<<"\n"; 
        }
        cout<<mi<<"\n";
    
    }   
    return 0;
}   
        
   
        
