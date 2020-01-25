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
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
vector<int>pos;
vector<stack<int>>v;
int n;
string s1, s2;
int n1, n2;
void remove_top(int x) {
	while (true) {
		int num = v[pos[x]].top();
		v[pos[x]].pop();
		if (num == x)break;
		pos[num] = num;
		v[num].push(num);
	}
}
vector<int>RemoveAndGetTop(int x) {
	vector<int>ret;
	while (true) {
		int num = v[pos[x]].top();
		v[pos[x]].pop();
		ret.push_back(num);
		if (num == x)break;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	cin >> n;
	v.resize(n);
	pos.resize(n);
	for (int i = 0; i < n; i++)
		v[i].push(i), pos[i] = i;
	int x = 0;
	while (cin >> s1) {
		if (s1 == "quit")break;
		x++;
		//cout << x << endl;
		cin >> n1 >> s2 >> n2;
		if (pos[n1] == pos[n2]) continue;
		if (s1 == "move" && s2 == "onto") {
			remove_top(n1);
			remove_top(n2);
			v[pos[n2]].push(n2);
			v[pos[n2]].push(n1);
			pos[n1] = pos[n2];
		}
		if (s1 == "move" && s2 == "over") {
			remove_top(n1);
			v[pos[n2]].push(n1);
			pos[n1] = pos[n2];
		}
		if (s1 == "pile" && s2 == "onto") {
			auto ve = RemoveAndGetTop(n1);
			remove_top(n2);
			v[pos[n2]].push(n2);
			for (auto e : ve)
				v[pos[n2]].push(e), pos[e] = pos[n2];
		}
		if (s1 == "pile" && s2 == "over") {
			auto ve = RemoveAndGetTop(n1);
			for (auto e : ve) {
				v[pos[n2]].push(e), pos[e] = pos[n2];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		vector<int>vv;
		while (v[i].size())vv.push_back(v[i].top()), v[i].pop();
		reverse(vv.begin(), vv.end());
		for (auto e : vv)
			cout << " " << e;
		cout << endl;
	}
	
	return 0;
}