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
const int N = 2e3 + 3, M = 1e4 + 5, mod = 10056;
const int MAX = 1e5 + 10;

int main() {
	fast_in_out();
	//	cout << fixed << setprecision(2);
	//kolo ray7 , ya 5raby
	int n, m;
	while (cin >> n >> m && n) {
		if (n > m)
			swap(n, m);
		bool turn = 1;
		while (m%n) {
			if (m / n >= 2)break;
			turn ^= 1;
			m = m % n;
			swap(n, m);
		}
		if (turn)
			cout << "Stan wins\n";
		else cout << "Ollie wins\n";
	}
	return 0;
}