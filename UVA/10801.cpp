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
#define what_is(x) cout << #x << " is " << x << endl;
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
const int N = 5 + 3, M = 1e4 + 5, mod = 10056;
vector<vector<int>>adj;
int cst[N];
unordered_map<int, map<int, int>>mp;
unordered_map<int, int>dis;
void dijkstra(int en) {
	set<pair<int,pair<int,int>>>s;
	if (mp.find(0) != mp.end())
		for (auto e : mp[0])
			s.insert({ 0, {e.first, 0} });
	dis[0] = 0;
	while (s.size()) {
		auto cur = *s.begin();
		s.erase(s.begin());
		int floor = cur.second.second;
		int elevator = cur.second.first;
		int cost = cur.first;
		if (floor == en) {
			cout << cost << endl;
			return;
		}
		for (auto ee : mp[floor]) {
			for (auto e : adj[ee.first]) {
				if (e == floor)continue;
				int ncost = cost + cst[ee.first] * (abs(e - floor));
				if (ee.first != elevator)
					ncost += 60;
				if (dis.find(e) == dis.end() || dis[e] > ncost) {
					if (dis.find(e) != dis.end())
						s.erase({ dis[e],{ee.first,e} });
					dis[e] = ncost;
					s.insert({ ncost, {ee.first, e} });
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//kolo ray7 , ya 5raby
	int n, en;
	while (cin >> n >> en) {
		for (int i = 0; i < n; i++)
			cin >> cst[i];
		adj.clear(); adj.resize(n);
		mp.clear(); cin.ignore();
		string str; dis.clear();
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			istringstream ss(str);
			int x;
			while (ss >> x) {
				adj[i].emplace_back(x);
				mp[x][i];
			}
		}
		dijkstra(en);
	}
	return 0;
}