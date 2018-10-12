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
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n; cin >> n;
	string s; cin >> s;
	vector<int>v(n);
	ll sum = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	int arr[26]{ 0 }, cnt = 0;;
	for (int i = 0; i<n / 2; i++)
		if (s[i] == s[n - i - 1]) {
			cnt++;
			arr[s[i] - 'a']+=2;
			sum -= min(v[i], v[n - i - 1]);
		}
	int mx = 0;
	char ch; bool f = 0;
	for (int i = 0; i<26; i++)
		if (mx < arr[i])
		{
			mx = arr[i];
			ch = (i+'a');
			if (mx > cnt)f = 1;
		}
	if (f) {
		multiset<int>se;
		for (int i = 0; i < n / 2; i++)
			if (s[i] != ch && s[n - i - 1] != ch && s[i] != s[n - i - 1])
				se.insert(min(v[i], v[n - i - 1]));
		int sz = mx - cnt;
		while (sz--)
		{
			sum -= *se.begin();
			se.erase(se.begin());
		}
	}
	cout << sum << endl;
	pause();
	return 0;
}