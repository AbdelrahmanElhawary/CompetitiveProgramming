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
int par[1003], rnk[1003];
ll dis(pair<int, int>a, pair<int, int>b)
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
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
	cout << fixed << setprecision(2);
	int n; 
	while (cin >> n && n)
	{
		vector<int>x(n), y(n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i],par[i]=i,rnk[i]=1;
		vector<pair<ll, pair<int, int>>>v;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				v.push_back({ dis({ x[i],y[i] }, {x[j],y[j]}),{i,j} });
		sort(v.begin(), v.end());
		int k = n - 1,i=0;
		ld ans = 0;
		while (k&&i < v.size())
		{
			int u = v[i].second.first, e = v[i].second.second;
			ld d = v[i].first; i++;
			if (find(u) == find(e))
				continue;
			merge(u, e);
			k--;
			ans += sqrt(d);
		}
		cout << ans << endl;
	}
		pause();
	return 0;
}