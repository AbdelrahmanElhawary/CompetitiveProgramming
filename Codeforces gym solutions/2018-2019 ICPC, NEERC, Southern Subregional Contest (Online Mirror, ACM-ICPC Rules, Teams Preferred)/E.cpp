#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int MLOG = 35;
const int MAX = 2 * 100 * 1000 + 5;
int c, n, m;
ll t;
vector<int> v, g;
vector<int> tmp;
map<int, int>vis;
bool fun(int mx){
	tmp.clear();
	ll D = g[mx - 1];
	for (int i = 0; i < n; i++){
		if (v[i] <= D&&(int)(tmp.size()) < mx ){
			tmp.push_back(v[i]);
		}
	}
	ll cost = 0, lst = 0; int cnt = 0;
	for (int i = 0; i < tmp.size(); i++){
		lst += tmp[i];
		cnt++;
		if (cnt == m){
			if (i + 1 < tmp.size())
				cost += lst + lst;
			else cost += lst;
			lst = 0;
			cnt = 0;
		}

		if (cost > t)
			return 0;
	}
	cost += lst;

	return (cost <= t);
}
int main(){
	fast();

	cin >> c;
	while (c--){
		v.clear();
		g.clear();
		cin >> n >> m >> t;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			v.push_back(x);
			g.push_back(x);
		}
		sort(g.begin(), g.end());

		int lo = 1, hi = n, ans = 0;
		while (lo <= hi){
			int md = lo + hi >> 1;
			if (fun(md)){
				lo = md + 1;
				ans = md;
			}
			else hi = md - 1;
		}
		if (ans > 0)
			cout << ans << " " << g[ans - 1] << "\n";
		else cout << 0 << " " << 1 << "\n";
	}
	return 0;
}