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
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(3);
	string s1, s2;
	bool f = 0;
	while (cin >> s1 >> s2)
	{
		vector<int>ans(111);
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		for (int i = 0; i < s1.size(); i++)
			ans[i] += s1[i] == '1';
		for (int i = 0; i < s2.size(); i++)
			ans[i] += s2[i] == '1';
		if (f)cout << endl;
		f = 1;
		int re = 1;
		while (re) {
			re = 0;
			for (int i = 0; i < 111; i++)
			{
				if (ans[i] && ans[i + 1])
				{
					ans[i + 2]++;
					ans[i]--;
					ans[i + 1]--;
					re = 1;
				}
				if (ans[i] > 1)
				{
					ans[i] -= 2;
					ans[i + 1]++;
					if (i == 1)
						ans[0]++;
					if (i > 1)
						ans[i - 2]++;
					re = 1;
				}
			}
		}
		int ind = 0;
		for (int i = 0; i < 111; i++)
			if (ans[i])
				ind = i;
		for (int i = ind; i >= 0; i--)
			cout << ans[i]; cout << endl;
	}
	pause();
	return 0;
}