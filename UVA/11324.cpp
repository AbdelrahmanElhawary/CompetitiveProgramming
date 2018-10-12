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
const int N = 1e3 + 2;
int n, m, component[N], cur_index;
int inde[N], low[N];
bool instack[N];
vector<int> stk, adj[N];
vector<set<int>>adj2;
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
		int j = adj[ind][i];
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
}

ll ansy;

void dfs(int u, int c)

{

	ansy = max(ansy, (ll)c);

	for (auto &v : adj2[u])
	
	dfs(v, c + comps[v].size());

}

int main()
 {

	fast_in_out();

	//cout << fixed << setprecision(6);
	
	int t; cin >> t;
	
	while (t--)
	
	{
		
		cin >> n>>m;

		for (auto&v : adj)

			v.clear();

		for (int i = 0; i < m; i++)

		{
			
			int u, v; cin >> u >> v;

			adj[u].push_back(v);

		//	adj[v].push_back(u);

		}

		SCC();

		map<int, int>cmp;
		int c = 0;
		for (auto &v : comps)
		{
			for (auto&e : v)
				cmp[e] = c;
			c++;
		}
		adj2.clear();
		adj2.resize(c);
		ansy = 0;
		for (int i = 1; i <= n; i++)
		{
			for (auto &u : adj[i])
				if (cmp[i] != cmp[u])
					adj2[cmp[i]].insert(cmp[u]);
		}
		for (int i = 0; i < c; i++)
		{
			dfs(i, comps[i].size());
		}
		cout << ansy << endl;
	}
	pause();
	return 0;
}