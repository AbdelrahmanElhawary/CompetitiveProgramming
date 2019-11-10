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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
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
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 501;
int n, m, q;
int ans[N*N];
int par[N*N], rnk[N*N];
int arr[N][N];
vector<set<int>>adj;
void pre() {
	for (int i = 0; i < N*N; i++)
		par[i] = i, rnk[i] = 1;
}
int find(int ind)
{
	if (par[ind] == ind) return ind;
	return par[ind] = find(par[ind]);
}
void go(int xRoot,int yRoot,int cost) {
	int u = xRoot, v = yRoot;
	if (adj[u].size() < adj[v].size())
		adj[u].swap(adj[v]);
	for (auto ee : adj[v]) {
		if (adj[u].find(ee) != adj[u].end()) {
			adj[u].erase(ee);
			ans[ee] = cost;
		}
		else {
			adj[u].insert(ee);
		}
	}
}
void merge(int x, int y,int cost)
{
	int xRoot = find(x);
	int yRoot = find(y);
	if (rnk[xRoot] > rnk[yRoot]) {
		par[yRoot] = xRoot, rnk[xRoot] += rnk[yRoot];
		go(xRoot, yRoot, cost);
	}
	if (rnk[xRoot] < rnk[yRoot]) {
		par[xRoot] = yRoot, rnk[yRoot] += rnk[xRoot];
		go(yRoot,xRoot, cost);
	}
	if (rnk[xRoot] == rnk[yRoot])
	{
		par[xRoot] = yRoot;
		rnk[yRoot] += rnk[xRoot];
		go(yRoot, xRoot, cost);
	}
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	pre();
	cin >> n >> m >> q;
	vector < pair<int, pair<int, int>>>v(n*m);
	adj.resize(n*m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			v[i*m + j] = { arr[i][j],{i,j} };
		}
	}
	int id = 0;
	//for(int x1=0;x1<n;x1++)
	//	for(int y1=0;y1<m;y1++)
	//		for(int x2=0;x2<n;x2++)
	//			for (int y2 = 0; y2 < m; y2++)
	//			{
	//				ans[x1*m + y1] = arr[x1][y1];
	//				ans[x2*m + y2] = arr[x2][y2];
	//				adj[x1*m + y1].insert(id);
	//				adj[x2*m + y2].insert(id);
	//				cout <<"id = "<<id<<" : "<< x1 << " " << y1 << " => " << x2 << " " << y2 << "\n";
	//				id++;
	//			}
	for (int i = 0; i < q; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		if(x1==x2&&y1==y2)
		{
			ans[i] = arr[x1][y1];
			continue;
		}
		adj[x1*m + y1].insert(i);
		adj[x2*m + y2].insert(i);
	}
	sort(v.begin(), v.end());
	for (auto e : v) {
		int cost = e.first, x = e.second.first, y = e.second.second;
		for (int i = 0; i < 4; i++) {
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			if (xx >= n || xx < 0 || yy < 0 || yy >= m)
				continue;
			if (arr[xx][yy] > cost)
				continue;
			if (find(x*m + y) == find(xx*m + yy))
				continue;
			merge(x*m + y, xx*m + yy, cost);	
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}