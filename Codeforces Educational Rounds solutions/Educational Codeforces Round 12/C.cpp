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
	string s; cin >> s;
	for (int i = 1; i < s.size(); i++)
	{
		if (i + 1 < s.size() && s[i] == s[i - 1] && s[i] == s[i + 1])
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
				if (s[i - 1] != ch) {
					s[i] = ch;
					break;
				}

		}
		else if (s[i] == s[i - 1])
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
				if (s[i - 1] != ch) {
					if (i + 1 < s.size() && s[i + 1] == ch)
						continue;
					s[i] = ch;
					break;
				}
		}
	}
	cout << s << endl;
	pause();
	return 0;
}