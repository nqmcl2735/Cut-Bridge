//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll,ll>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct dinh
{
    ll low = 0, num = 0, pre;
};
vector <ll> ke[maxn];
ll n, m, time_DFS;
dinh a[maxn];
pii res[maxn];
ll socau = 0;
ll s[maxn];
void dfs (ll u)
{
    a[u].num = a[u].low = ++time_DFS;
    for (int i = 0; i < sz(ke[u]); i ++)
    {
        ll v = ke[u][i];
        if (v == a[u].pre) continue;
        if (!a[v].num)
        {
            a[v].pre = u;
            dfs(v);
            a[u].low = min(a[u].low, a[v].low);
            if (a[v].low == a[v].num) res[++ socau] = {u, v};
            s[u] += s[v];
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
}
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        ll u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
}
int main() {
    ll tplt = 0;
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    nhap();
    for (int i = 1; i <= n; i ++) s[i] = 1;
    for (int i = 1; i <= n; i ++)
        if (!a[i].num)
        {
            a[i].pre = 0;
            dfs(i);
            tplt ++;
        }
    if (tplt > 2) {
        cout << 0;
        return 0;
    }
    if (tplt == 2)
        for (int i = 1; i <= n; i ++)
            if(!a[i].pre)
            {
                ll ans = (m - socau) * s[i] * (n - s[i]) ;
                cout << ans ;
                return 0;
            }

    ll ans = 0;
    for (int i = 1; i <= socau; i ++) {
        int v = res[i].S;
        ans += s[v] *(n - s[v]) - 1;
    }
    ans += (m - socau) * ( n * (n - 1)/2 - m);
    cout << ans;
}
