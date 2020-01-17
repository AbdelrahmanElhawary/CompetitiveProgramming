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
void fast_in_out() {
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e5 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int cum[N];
int main() {
    fast_in_out();
    //cout << fixed << setprecision(4);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll q = 1LL*n*n, p = 0;
        string s; cin >> s;
        for (int i = 1; i <= n; i++) {
            cum[i] = (s[i - 1] == '1');
            cum[i] += cum[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int r = min(i + m, n), l = max(i - m, 1);
            int sz = r - l + 1;
            if (s[i - 1] == '1') {
                p += cum[r] - cum[l - 1];
            }
        }
        ll g = gcd(p, q);
        cout << p / g << "/" << q / g << endl;

    }
    return 0;
}