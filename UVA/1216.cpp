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
vector<pair<int, int>>v;
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
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int x, y,k=0; 
		v.clear();
		while (cin >> x && x != -1)
		{
			cin >> y;
			v.push_back({ x,y });
		}
		vector <pair< ll,pair<int, int>>> adj;
		for (int i = 0; i < v.size(); i++)
			for (int j = i + 1; j < v.size(); j++)
				adj.push_back({ (ll)(v[i].first - v[j].first)*(v[i].first - v[j].first) + (ll)(v[i].second - v[j].second)*(v[i].second - v[j].second),{i,j} });
		sort(adj.begin(), adj.end());
		for (int i = 0; i < v.size(); i++)
			par[i] = i, rnk[i] = 1;
		ld ansy = 0;
		for (int i = 0; i < adj.size(); i++)
		{
			if (find(adj[i].second.first) == find(adj[i].second.second))
				continue;
			merge(adj[i].second.first, adj[i].second.second);
			k++;
			if (k + n >= v.size()) {
				ansy = sqrt((ld)adj[i].first);
				break;
			}
		}
		cout << ceil(ansy) << endl;
	}
	pause();
	return 0;
}