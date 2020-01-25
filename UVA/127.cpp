#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
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
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }

bool cmp(string s1, string s2) {
	return (s1[0] == s2[0] || s1[1] == s2[1]);
}
vector<vector<string>>v;
int get(int ind,int cnt) {
	for (int i = ind - 1; i > -1; --i)
	{
		if (v[i].size())--cnt;
		if (!cnt)return i;
	}
	return -1;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	while (true) {
		string s; cin >> s;
		if (s == "#")break;
		v.clear(); v.resize(52);
		v[0].emplace_back(s);
		for (int i = 1; i < 52; i++) {
			cin >> s;
			v[i].emplace_back(s);
		}
		for (int i = 1; i < 52; i++) {
			if (v[i].empty())continue;
			int l = get(i, 3);
			if ((l = get(i, 3)) != -1 && cmp(v[i].back(), v[l].back())) {
				v[l].push_back(v[i].back());
				v[i].pop_back();
				i = l - 1;
				continue;
			}
			if ((l = get(i, 1)) != -1 && cmp(v[i].back(), v[l].back())) {
				v[l].push_back(v[i].back());
				v[i].pop_back();
				i = l - 1;
				continue;
			}

			
		}
		int cnt = 0;
		for (int i = 0; i < 52; i++)
			if (v[i].size())++cnt;
		if (cnt > 1) {
			cout << cnt << " piles remaining:";
			for (int i = 0; i < 52; i++)
				if (v[i].size())cout << " " << v[i].size(); cout << endl;
		}
		else cout << "1 pile remaining: 52\n";
		}
	return 0;
}