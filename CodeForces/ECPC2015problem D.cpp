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
int n, m;
vector<pair<ll,int>>adj[100005];
vector<ll>ans;
bool vis[100005];
void dfs(int u, ll cost)
{
//	vis[u] = 1;
	bool f = 1;
	int last;
	for (auto &v : adj[u])
	{
		//if (vis[v.second])continue;
		if (f) {
			last = v.first;
			dfs(v.second, cost + v.first);
			f = 0;
		}
		else dfs(v.second, cost + last + (v.first - last) * 2);
	}
	if(f)ans.push_back(cost);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back({ v,i });
		}
		for (int i = 1; i <= n; i++)
			sort(adj[i].begin(), adj[i].end());
		dfs(1,0);
		sort(ans.begin(), ans.end());
		int q;
		cin >> q;
		while (q--)
		{
			ll t; cin >> t;
			cout << upper_bound(ans.begin(), ans.end(), t) - ans.begin() << endl;
		}
		ans.clear();
		for (auto &v : adj)
			v.clear();
		memset(vis, 0, sizeof vis);
	}

	pause();
	return 0;
}