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
int n, m,par[102],rnk[102];
vector<pair<int,pair<int,int>>>e;
int find(int ind)
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
//	cout << fixed << setprecision(2);
	while (cin >> n >> m &&n)
	{
		int mne = 1e9, mxe = -1;
		e.clear();
		e.resize(m);
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			e[i] = { d,{u,v} };
		}
		sort(e.begin(), e.end());
		int ansy = 1e9; bool f = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 1; j <= n; j++)
				par[j] = j, rnk[j] = 1;
			int edges = 0;
			int mxy = e[i].first;
			for (int j = i; j < m; j++)
			{
				int u = e[j].second.first,v=e[j].second.second,d=e[j].first;
				if (find(u) == find(v))
					continue;
				merge(u, v);
				edges++;
				mxy = d;
			}
			if(edges==n-1)f=1,ansy = min(ansy, mxy - e[i].first);
		}
		if (!f)ansy = -1;
		cout << ansy << endl;
	}
	pause();
	return 0;
}