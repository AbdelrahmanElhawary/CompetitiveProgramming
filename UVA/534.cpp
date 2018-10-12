#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#includeiostream
#includemap
#includecmath
#includealgorithm
#includestring
#includeset
#includesstream
#includevector
#includestring.h
#includequeue
#includelist
#includeiterator
#includefunctional 
#includeiomanip
#includebitset
#includestack
#include assert.h
#includecomplex
#define point complexdouble
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl 'n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
using namespace std;
void fast_in_out() {
	stdios_basesync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system(pause);
#endif
}
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int par[100005], rnk[100005];
vectorpairint, intv;
int find(int ind)
{
	if (par[ind] == ind) return ind;
	return par[ind] = find(par[ind]);
}
void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);

	if (rnk[xRoot]  rnk[yRoot])
		par[yRoot] = xRoot;
	if (rnk[xRoot]  rnk[yRoot])
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
	cout  fixed  setprecision(3);
	int n; int tt = 1;
	while (cin  n && n)
	{
		vectorpairll, llv(n);
		for (int i = 0; i  n; i++)
			cin  v[i].first  v[i].second;
		vector  pairll, pairint, intadj;
		for(int i=0;in;i++)
			for(int j=i+1;jn;j++)
				adj.push_back({ (ll)(v[i].first - v[j].first)(v[i].first - v[j].first) + (ll)(v[i].second - v[j].second)(v[i].second - v[j].second),{ i,j } });
		for (int i = 0; i  n; i++)
			par[i] = i, rnk[i] = 1;
		ld ansy = 0;
		sort(adj.begin(), adj.end());
		for (int i = 0; i  adj.size(); i++)
		{
			if (find(0) == find(1))
				break;
			int u = adj[i].second.first, v = adj[i].second.second;
			ll d = adj[i].first;
			if (find(u) == find(v))
				continue;
			merge(u, v);
			ansy = sqrt((ld)d);
		}
		cout  Scenario #  tt++  endl  Frog Distance =   ansy  endl  endl;

	}
	pause();
	return 0;
}