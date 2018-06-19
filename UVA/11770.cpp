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
bool vis[1000005];
stack<int>st;
bool f = 1;
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
	int n, m, t;
	int tt = 1;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		memset(vis, 0, sizeof vis);
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
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i);
		memset(vis, 0, sizeof vis);
		f = 0; 
		while (st.size())
		{	
			if (!vis[st.top()])
				cnt++,dfs(st.top());
			st.pop();
		}
		cout <<"Case "<<tt++<<": "<< cnt << endl;
	}
	pause();
	return 0;
}