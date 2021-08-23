//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 500005
#define MOD
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct dinh
{
    int low = 0, num = 0, pre;
};
vector <int> ke[maxn];
int n, m, time_DFS;
dinh a[maxn];
pii res[maxn];
int cnt = 0;
void dfs (int u)
{
    a[u].num = a[u].low = ++time_DFS;
    for (int i = 0; i < sz(ke[u]); i ++)
    {
        int v = ke[u][i];
        if (v == a[u].pre) continue;
        if (!a[v].num)
        {
            a[v].pre = u;
            dfs(v);
            a[u].low = min(a[u].low, a[v].low);
            if (a[v].low == a[v].num) res[++ cnt] = {min(u, v), max(v, u)};
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
}
void nhap() {
    fi >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        fi >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    nhap();
    for (int i = 1; i <= n; i ++)
        if (!a[i].num)
        {
            a[i].pre = 0;
            dfs(i);
        }
    fo << a[11973].num << " " << a[16337].low;
}
