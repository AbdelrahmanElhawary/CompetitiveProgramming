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
int par[100005], rnk[100005];
const int N = 1e5 + 5;
int n, m, component[N], cur_index;
int inde[N], low[N];
bool instack[N];
vector<int> stk; vector<pair<int,ll>> adj[N];
vector< vector<int> > comps;
void tarjan(int ind)
{
	inde[ind] = cur_index;
	low[ind] = cur_index;
	cur_index++;
	stk.pb(ind);
	instack[ind] = 1;
	for (int i = 0; i<adj[ind].size(); i++)
	{
		int j = adj[ind][i].first;
		if (inde[j] == -1)
		{
			tarjan(j);
			low[ind] = min(low[ind], low[j]);
		}
		else if (instack[j]) low[ind] = min(low[ind], inde[j]);
	}
	if (inde[ind] == low[ind])
	{
		vector<int> temp;
		while (stk.back() != ind)
		{
			temp.push_back(stk.back());
			instack[stk.back()] = 0;
			component[stk.back()] = comps.size();
			stk.pop_back();
		}
		temp.push_back(stk.back());
		instack[stk.back()] = 0;
		component[stk.back()] = comps.size();
		stk.pop_back();
		comps.push_back(temp);
	}
	return;
}
void SCC()
{
	memset(inde, -1, sizeof inde);
	memset(low, 0, sizeof low);
	comps.clear(); cur_index = 0;
	for (int i = 1; i <= n; i++)
		if (inde[i] == -1) tarjan(i);
	return;
}int find(int ind)
{
	if (par[ind] == ind) return ind;
	return par[ind] = find(par[ind]);
}
void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);

	if (rnk[xRoot] > rnk[yRoot])
		par[yRoot] = xRoot;
	if (rnk[xRoot] < rnk[yRoot])
		par[xRoot] = yRoot;
	if (rnk[xRoot] == rnk[yRoot])
	{
		par[xRoot] = yRoot;
		rnk[yRoot]++;
	}
	return;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(3);
	int t,tt=1; cin >> t;
	while (t--)
	{
		int a; cin >> n >> m >> a;
		for (auto &v : adj)
			v.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			adj[u].push_back({ v,cost });
			adj[v].push_back({ u,cost });
		}
		SCC();
		//cout << comps.size() << endl;
		vector<vector<pair<ll, pair<int, int>>>>vv(comps.size());
		for (int i = 1; i <= n; i++)
			for (auto &e : adj[i])
				if (component[i] == component[e.first])
					vv[component[i]].push_back({ e.second,{i,e.first} });
		for (int i = 1; i <= n; i++)
			par[i] = i, rnk[i] = 1;
		ll ansy =0, k = vv.size();
		ansy = k * a;
		for (auto&v:vv)
		{
			sort(v.begin(), v.end());
			for (auto&e : v)
			{
				int u = e.second.first, v = e.second.second;
				ll d = e.first;
				if (find(u) == find(v))
					continue;
				merge(u, v);
				if (d >= a)
					k++,ansy+=a;
				else ansy += d;
			}
		}
		cout<<"Case #"<<tt++<<": " << ansy << " " << k << endl;
				
	}
	pause();
	return 0;
}