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
#define Task "proG"
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
vector <int> con[maxn];
int in[maxn], out[maxn];
int n, m, time_DFS = 0, time2 = 0;
dinh a[maxn];
bool khop[maxn];

void dfs (int u)
{
    int child = (a[u].pre != 0);
    a[u].num = a[u].low = ++time_DFS;
    in[u] = ++time2;
    for (int i = 0; i < sz(ke[u]); i ++)
    {

        int v = ke[u][i];
        if (v == a[u].pre) continue;
        if (!a[v].num)
        {
            a[v].pre = u;
            dfs(v);
            a[u].low = min(a[u].low, a[v].low);
            con[u].PB(v);
            if (a[v].low >= a[u].num) child ++;
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
    if (child >= 2) khop[u] = 1;
    out[u] = ++time2;
}
bool cau(int u, int v)
{
    return a[v].low < a[v].num;
}
bool check_lt(int v, int u)
{
    return (in[u] <= in[v] && out[v] <= out[u]);
}
bool sol1(int x, int y, int c, int d)
{
    if (in[c] > in[d]) swap(c,d);
    if (cau(c, d)) return 1;
    return (check_lt(x, d) == check_lt(y, d));
}
bool comp(int p, int q){
    return in[p] < in[q];
}
int getChild(int v, int u)
{
    if (!check_lt(v, u)) return -1;
    int x = *(upper_bound(con[u].begin(), con[u].end(), v, comp) -1);
    if (a[x].low < a[u].num) return -1;
    return x;
}
bool sol2(int x, int y, int u)
{
    if (!khop[u]) return 1;
    return (getChild(x, u) == getChild(y, u));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    for (int i = 1; i <= n; i ++)
        if (!a[i].num)
        {
            a[i].pre = 0;
            dfs(i);
        }
    int q;
    cin >> q;
    while (q --)
    {
        int type, a, b, c, d;
        cin >> type >> a >> b >> c;
        if (type == 1)
        {
            cin >> d;
            if (sol1(a, b, c, d)) cout << "yes\n"; else cout << "no\n";
        }
        else if (sol2(a, b, c)) cout << "yes\n"; else cout << "no\n";
    }
}

