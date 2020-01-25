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
const int N = 32 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int prm[N];
ll ans[N];
vector<int>prime;
void sieve() {
	for (int i = 4; i < N; i += 2)
		prm[i] = 1;
	prime.emplace_back(2);
	for (int j = 3; j < N; j += 2) {
		if (!prm[j]) {
			prime.emplace_back(3);
			for (int i = j+j; i < N; i += j)
				prm[i] = 1;
		}
	}
}
ll get(ll x) {
	return (1LL << (x - 1)) * ((1LL << x) - 1);
}
bool check(ll n) {
	ull sum = 1;
	for (ll i = 2; i*i <=n; i++) {
		if (n % i == 0) {
			sum += i;
			if (i * i != n)
				sum += n/i;
		}
	//	cout << sum << " " << n << endl;
		if (sum > n)return 0;
	}
	//cout << n << " " << sum << endl;
	return sum == n;
}

int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	sieve();
	/*for (int i = 2; i < 32; i++) {
		ll x = get(i);
		cout << "ans[" << i << "]=";
		if (check(x))
			cout << x<<";" << endl;
		else cout << 0<<";" << endl;
	}
	*/ans[2] = 6;
	ans[3] = 28;
	ans[4] = 0;
	ans[5] = 496;
	ans[6] = 0;
	ans[7] = 8128;
	ans[8] = 0;
	ans[9] = 0;
	ans[10] = 0;
	ans[11] = 0;
	ans[12] = 0;
	ans[13] = 33550336;
	ans[14] = 0;
	ans[15] = 0;
	ans[16] = 0;
	ans[17] = 8589869056;
	ans[18] = 0;
	ans[19] = 137438691328;
	ans[20] = 0;
	ans[21] = 0;
	ans[22] = 0;
	ans[23] = 0;
	ans[24] = 0;
	ans[25] = 0;
	ans[26] = 0;
	ans[27] = 0;
	ans[28] = 0;
	ans[29] = 0;
	ans[30] = 0;
	ans[31] = 2305843008139952128;
	int n;
	while (cin >> n) {
		if (!n)break;
		if (ans[n])
			cout << "Perfect: " << ans[n] << "!\n";
		else if (prm[n])
			cout << "Given number is NOT prime! NO perfect number is available.\n";
		else cout << "Given number is prime. But, NO perfect number is available.\n";
	}
	return 0;
}