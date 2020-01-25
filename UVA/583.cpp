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
const int N = 1e6 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int prm[N];
vector<int>prime;
void sieve() {
	for (int i = 2; i < N; i += 2)
		prm[i] = 2;
	prime.push_back(2);
	for (int j = 3; j < N; j += 2) {
		if (!prm[j]) {
			prime.emplace_back(j);
			for (int i = j; i < N; i += j)
				if (!prm[i])prm[i] = j;
		}
	}
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	int n; sieve();
	while (cin >> n) {
		if (n == 0)return 0;
		cout << n << " =";
		bool mul = 0;
		if (n < 0)cout << " -1", mul = 1;
		n = abs(n);
		for (int i = 0; i < n;i++) {
			if (1LL * prime[i] * prime[i] > n)break;
			int x = prime[i];
			while (n % x == 0) {
				if (mul)cout << " x";
				cout << " " << x;
				mul = 1;
				n /= x;
			}
		}
		if (n != 1)
			if (mul)cout << " x " << n << endl;
			else cout << " " << n << endl;
		else cout << endl;
	}
	return 0;
}