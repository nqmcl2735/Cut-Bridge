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
#define maxn 100005
#define MOD
#define Task ""
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
int n, m, time_DFS = 0;
dinh a[maxn];
int res[maxn];
int cnt = 0;
void dfs (int u)
{
    int child = (a[u].pre != 0);
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
            if (a[v].low >= a[u].num) child ++;
        }
        else a[u].low = min(a[u].low, a[v].num);
    }
    if (child >= 2) res [++ cnt] = u;
}
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
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
    cout << cnt << "\n";
    sort(res + 1, res + cnt + 1);
    for (int i = 1; i <= cnt; i ++)
        cout << res[i] << " ";
}
