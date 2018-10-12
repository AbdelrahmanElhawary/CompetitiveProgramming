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
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
const int N = 1e6 + 2;
int n, m, component[N], cur_index;
int inde[N], low[N];
bool instack[N];
vector<int> stk, adj[N];
vector< vector<int> > comps;
void tarjan(int ind)
{
	//cout << ind << " why\n";
	inde[ind] = cur_index;
	low[ind] = cur_index;
	cur_index++;
	stk.push_back(ind);
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
	for (int i = 1; i <= n; i++) {
		if (inde[i] == -1) tarjan(i);
	}
	return;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		adj[i].push_back(v[i]);
		//cout << i << " " << v[i] << endl;
	}
	SCC();
	v.clear();
//	cout << comps.size() << endl;;
	for (auto &e : comps)
	{
		v.push_back(e.size());
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	int i = 0;
	if (v.size() >= 2)
	{
		ans = 1LL*(v[0] + v[1])*(v[0] + v[1]);
		i = 2;
	}
	for (; i < v.size(); i++)
	{
		ans += (1LL*v[i] * v[i]);
	}
	cout << ans << endl;
	pause();
	return 0;
}