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

int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n; cin >> n;
	vector<int>v(n);
	string s;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> s;
	ll ansy = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'B')
			ansy += v[i];
	ll ansy2 = ansy,ans=ansy;
	for (int i = 0, j = n - 1; i < n; i++, j--)
	{
		if (s[i] == 'A')
			ansy += v[i];
		else ansy -= v[i];
		if (s[j] == 'A')
			ansy2 += v[j];
		else ansy2 -= v[j];
		ans = max({ ans,ansy,ansy2 });
	}
	cout << ans << endl;
	pause();
	return 0;
}