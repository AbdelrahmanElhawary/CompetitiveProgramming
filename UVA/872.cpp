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
const int N = 2505, M = 1e4 + 5, mod = 1e9 + 7;
string s;
vector<vector<int>>adj;
bool okay;
int vis[26];
int vid;
bool check(char ch) {
	if (vis[ch - 'A'] == vid)
		return 0;
	for (auto e : adj[ch - 'A'])
		if (vis[e] == vid)
			return 0;
	return 1;
}
void dfs(string str="") {
	if (str.size() == s.size()) {
		okay = 1;
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << " \n"[i == str.size() - 1];
		return;
	}
	for (auto e : s) {
		if (!check(e))continue;
		vis[e - 'A'] = vid;
		dfs(str + e);
		vis[e - 'A'] = 0;
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//kolo ray7 , ya 5raby
	int t; cin >> t;
	bool f = 0;
	cin.ignore();
	string str;
	getline(cin, str);
	while (t--) {
		if (f)cout << endl;
		f = 1; ++vid; okay = 0;
		string str;
		getline(cin, str);
		stringstream ss(str);
		char ch;
		s = "";
		while (ss >> ch)
			s += ch;
		sort(s.begin(), s.end());
		getline(cin, str);
		ss.clear();
		ss.str(str);
		char u, v;
		adj.clear(); adj.resize(26);
		while (ss >> u >> ch >> v)
			adj[u - 'A'].push_back(v - 'A');
		dfs();
		//cout << okay << endl;
		if (!okay)cout << "NO\n";
		getline(cin, str);
	}
	return 0;
}