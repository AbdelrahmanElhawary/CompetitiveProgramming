#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
ll dp[2005][2005][2][2];
const int mod = 1e9 + 7;
int n,d,m;
string a, b;
ll solve(int ind=0, int rem=0, bool f1=0, bool f2=0,int st=1) {
	if (ind == n) 
		return rem == 0;
	ll &ret = dp[ind][rem][f1][f2];
	if (ret!=-1)
		return ret;
	ret = 0;
	for (int i = st; i <= 9; i++) {
		if ((ind & 1) == (i != d)) continue;
		if (((f1) || (i >= (a[ind] - '0'))) && (f2 || (i <= b[ind] - '0'))) {
			bool ff1 = f1, ff2 = f2;
			if ((i > a[ind] - '0'))ff1 = 1;
			if ((i < b[ind] - '0'))ff2 = 1;
			int nerem = (rem * 10 + i) % m;
			ret += solve(ind + 1, nerem, ff1, ff2, 0);
			ret %= mod;
		}
	}
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	cin >> m >> d;
	cin >> a >> b;
	n = a.size();
	memset(dp, -1, sizeof dp);
	cout << solve() << endl;
	
	pause();
	return 0;
}