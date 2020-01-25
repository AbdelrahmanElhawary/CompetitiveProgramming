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
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	ll n, p;
	while (cin >> n >> p&&n) {
		ll r = sqrt(p);
		if (r % 2 == 0)++r;
		else if (r * r != p)
			r += 2;
		ll x = r/2, y = r/2;
		if (r != 1) {
			int cor = (r * r - p) / (r - 1);
			if (!cor)
				x -= r * r - p;
			if (cor == 1)
				x -= r - 1, y -= (r * (r - 1) - p + 1);
			if (cor == 2)
				y -= r - 1, x -= (r - 1) - (r * r - p - (r - 1)*2);
			if (cor == 3)
				y -= (r - 1) - (r * r - p - (r - 1) * 3);
		//	cout << cor << " ";
		}
		cout << "Line = " << x + n / 2 + 1 << ", column = " << y + n / 2 + 1 << ".\n";
	}
	return 0;
}