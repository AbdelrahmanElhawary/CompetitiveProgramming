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
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
#define mk make_pair
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
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<int>adj[100002];
int cost[100002];
bool vis[100002];
ll ret = 1e18;
void dfs(int node)
{
	ret = min(ret,(ll)cost[node]);
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
		if (!vis[adj[node][i]])
			dfs(adj[node][i]);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			dfs(i);
			ans += ret;
			ret = 1e18;
		}
	cout << ans << endl;
	pause();
	return 0;
}