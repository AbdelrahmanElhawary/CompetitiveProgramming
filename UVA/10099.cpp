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
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int n, m, ans;
int s, e, d;
vector<pair<int, int>>adj[102];
vector<bool>vis;
void dfs(int u, int e,int mny,int k)
{
	if (u == e)
	{
		ans = min((int)ceil((ld)d / (mny-1)),ans);
		return;
	}
	vis[u] = 1;
	for (auto &v : adj[u])
	{
		if (!vis[v.first]&&v.second>=k)
			dfs(v.first, e, min(mny, v.second),k);
	}
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(2);
	int n, m,tt=1;
	while (cin >> n >> m && (n || m))
	{
		vis.clear();
		vis.resize(n + 1);
		for (auto &v : adj)
			v.clear();
		vector<int>vc(m);
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			adj[u].push_back({ v,d });
			adj[v].push_back({ u,d });
			vc[i] = d;
		}
		cin >> s >> e >> d;
		ans = 1e9;
		int ansy = 1e9;
		sort(vc.begin(), vc.end());
		for (int i = 0; i < m; i++)
		{
			vis.clear();
			vis.resize(n + 1);
			ans = 1e9;
			dfs(s, e, 1e9, vc[i]);
			if (ans == 1e9)break;
			ansy = min(ansy, ans);
		}
		cout << "Scenario #" << tt++ << endl << "Minimum Number of Trips = " << ansy << endl << endl;
	}
	pause();
	return 0;
}