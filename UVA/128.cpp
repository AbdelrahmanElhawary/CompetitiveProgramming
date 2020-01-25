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
char trans(int a) {
	if (a <= 9)return a + '0';
	return a + 'A' - 10;
}
string get(int a) {
	string s = "";
	while (a) {
		s += (trans(a % 16));
		a /= 16;
	}
	while (s.size() < 2)s += '0';
	reverse(s.begin(), s.end());
	return s;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	string s;
	while (getline(cin, s)) {
		if (s == "#")return 0;
		ll ret = 0;
		int g = 34943;
		for (auto e : s) {
			ret <<= 8;
			ret |= e;
			ret %= g;
		}
		ret <<= 16;
		ll add = 0;
		if (ret)add = g - (ret % g);
		ret += add;
		ll a = ret & (255);
		ll b = (ret>>8) & (255);
		cout<<get(b)<<" "<<get(a)<<endl;
	}
	return 0;
}