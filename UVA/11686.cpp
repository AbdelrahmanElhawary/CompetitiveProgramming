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
vector<int>adj[1000002];
bool vis[1000005],viss[1000005];
vector<int>st;
bool f = 1;
void dfs(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
		if (!vis[v])
			dfs(v);
		else if (!viss[v])
			f = 0;
	viss[u] = 1;
	st.push_back(u);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		memset(vis, 0, sizeof vis);
		memset(viss, 0, sizeof viss);
		for (auto &v : adj)
			v.clear();
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		int cnt = 0;
		f = 1;
		st.clear();
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		if(f)
		while (st.size())
		{	
			cout << st.back() << endl;
			st.pop_back();
		}
		else cout << "IMPOSSIBLE\n";
	}
	pause();
	return 0;
}