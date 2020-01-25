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
const int N = 1e3 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
class DyckwordUniformer {
public:
	bool valid(string s) {
		int cnt = 0;
		for (auto e : s) {
			if (e == 'X')cnt++;
			else --cnt;
			if (cnt < 0)return 0;
		}
		if (cnt)return 0;
		return 1;
	}
	string solve(string s) {
		if (s.empty())return "";
		vector<string>v;
		int last = 0, cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'X')cnt++;
			else --cnt;
			if (cnt == 0) {
				v.emplace_back('X'+solve(s.substr(last + 1, i - last))+ 'Y');
				last = i + 1;
			}
		}
		sort(v.begin(), v.end());
		s = "";
		for (auto e : v)s += e;
		return s;
	}
	string uniform(string dyckword) {
		if (!valid(dyckword))
			return "";
		return solve(dyckword);
	}
};