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
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	string str = s;
	bool f = 1;
	for (int i = 0; i < n&&k; i++)
	{
		char ch1 = s[i];
		int dif1 = 'z' - ch1,dif2=ch1-'a';
		if (dif1 > dif2)
			ch1 = 'z'; 
		else ch1 = 'a', dif1 = dif2;
		if (k >= dif1)
		{
			str[i] = ch1;
			k -= dif1;
			continue;
		}
		else {
			if (ch1 == 'z') str[i] = (s[i] + k);
			else str[i] = (s[i] - k);
			k = 0;
			break;
		}
	}
	if (k)cout << -1 << endl;
	else cout << str << endl;
	pause();
	return 0;
}