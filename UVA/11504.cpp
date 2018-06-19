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
vector<int>adj[100005];
bool vis[100005];
stack<int>st;
bool f=1;
void dfs(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
		if (!vis[v])
			dfs(v);
	if(f)st.push(u);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (auto &v : adj)
			v.clear();
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			//adj[v].push_back(u);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		memset(vis, 0, sizeof vis); f = 0;
		while (st.size())
		{
			if (!vis[st.top()])
			{
				dfs(st.top());
				cnt++;
			}
			st.pop();
		}
		cout << cnt << endl; f = 1;
	}
	pause();
	return 0;
}