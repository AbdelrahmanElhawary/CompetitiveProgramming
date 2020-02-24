/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
ICPC DREAM
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
const int N = 2e2 + 3, M = 1e4 + 5, mod = 10056;
const int MAX = 1e5 + 10;
int n, par[MAX], rnk[MAX];
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
struct edge {
	int u, v, w;
}edges[N];
int edg[N];
int vis[N], vid;
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(4);
	//kolo ray7 , ya 5raby
	int t, m, tt = 1;
	cin >> t;
	while (t--) {
		cout << "Case #"<<tt++<<" : ";
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			par[i] = i, rnk[i] = 1;
		for (int i = 0; i < m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		sort(edges, edges + m, cmp);
		int ans = 0, cnt = 0;
		++vid;
		for (int i = 0; i < m; i++) {
			if (find(edges[i].u) != find(edges[i].v))
			{
				ans += edges[i].w;
				merge(edges[i].u, edges[i].v);
				edg[cnt++] = i;
				if (cnt == n - 1)break;
			}
		}
		if (cnt != n - 1) {
			cout << "No way\n";
			continue;
		}
		int ansy = 1e9;
		for (int j = 0; j < cnt; j++) {
			int cc = 0,ansr=0;
			for (int i = 1; i <= n; i++)
				par[i] = i, rnk[i] = 1;
			for (int i = 0; i < m; i++) {
				if (edg[j] == i)continue;
				if (find(edges[i].u) != find(edges[i].v))
				{
					ansr += edges[i].w;
					merge(edges[i].u, edges[i].v);
					++cc;
					if (cc == n - 1)break;
				}
			}
			if (cc == n - 1)
				ansy = min(ansy, ansr);
		}
		if (ansy == 1e9)
			cout << "No second way\n";
		else cout << ansy << endl;
	}
	return 0;
}