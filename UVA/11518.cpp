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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
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
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector<int>adj[10005];
bool vis[10005];
int ans = 0;
void dfs(int u)
{
	vis[u] = 1,ans++;
	for (auto &v : adj[u])
		if (!vis[v])
			dfs(v);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t;
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof vis);
		for (auto &v : adj)
			v.clear();
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		ans = 0;
		for (int i = 0; i < k; i++)
		{
			int u; cin >> u;
			if (!vis[u])
				dfs(u);
		}
		cout << ans << endl;
	}
	pause();
	return 0;
}