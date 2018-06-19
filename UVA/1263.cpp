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
const int N = 2e3 + 2;

bool check(ll x,ll y,ll d,ll xx,ll yy)
{
	ll x1 = x - d, x2 = x + d;
	ll y1 = y - d, y2 = y + d;
	return xx >= x1 && xx <= x2 && yy >= y1 && yy <= y2;
}
struct point { ll x, y, d; };
point arr[2002];
vector<int>adj[2002];
bool vis[2005];
stack<int>st;
bool f = 1;
void dfs(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
		if (!vis[v])
			dfs(v);
	if (f)st.push(u);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof vis);
		for (auto &v : adj)
			v.clear();
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			ll x, y, d;
			cin >> x >> y >> d;
			arr[i] = { x,y,d/2.0 };
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j)continue;
				if (check(arr[i].x, arr[i].y, arr[i].d, arr[j].x, arr[j].y))
					adj[i].push_back(j);
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