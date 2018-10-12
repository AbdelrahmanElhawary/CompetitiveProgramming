#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int n;
const int MAX = 1e5 + 10;
vector<vector<pair<int,pair<ll,ll>>>>adj;
ll depth[MAX], dp[MAX][18];
ll arr1[MAX], arr2[MAX];
void dfs(int u, int par,ll c1=0,ll c2=0)
{
	dp[u][0] = par;
	arr1[u] = c1;
	arr2[u] = c2;
	for (auto&v : adj[u])
		if (v .first!= par)
		{
			depth[v.first] = depth[u] + 1;
			dfs(v.first, u,c1+v.second.first,c2+v.second.second);
		}
}
void sparse_table()
{
	memset(dp, -1, sizeof dp);
	depth[1] = 0;
	dfs(1, -1);
	for (int k = 1; k <= 17; k++)
		for (int u = 1; u <= n; u++)
		{
			if (dp[u][k - 1] != -1)
				dp[u][k] = dp[dp[u][k - 1]][k - 1];
		}
}
int lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	for (int k = 17; k >= 0; k--)
		if (depth[u] - (1 << k) >= depth[v])
			u = dp[u][k];
	if (u == v)return u;
	for (int k = 17; k >= 0; k--)
		if (dp[u][k] != dp[v][k])
		{
			u = dp[u][k];
			v = dp[v][k];
		}
	return dp[u][0];
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		adj.clear();
		adj.resize(n + 1); ll ansy = 0;
		for (int i = 0; i < n-1; i++)
		{
			int u, v, c1, c2;
			cin >> u >> v >> c1 >> c2;
			adj[u].push_back({ v,{c1,c2} });
			adj[v].push_back({ u,{c2,c1} });
			ansy += c1 + c2;
		}
		sparse_table();
		int q; cin >> q;
		while (q--)
		{
			int u, v;
			cin >> u >> v;
			int e = lca(u, v);
			cout << ansy - arr1[u] - arr2[v] + arr1[e] + arr2[e] << endl;
		}
	}

	pause();
	return 0;
}