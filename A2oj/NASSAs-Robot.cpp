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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int t; cin >> t;
	while (t--)
	{
		int mnx = 0, mny = 0, mxx = 0, mxy = 0;
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '?') { mnx--; mny--; mxx++; mxy++; continue; }
			if (s[i] == 'U') { mxy++; mny++; }
			if (s[i] == 'D') { mxy--; mny--; }
			if (s[i] == 'R') { mxx++; mnx++; }
			if (s[i] == 'L') { mxx--; mnx--; }
		}
		cout << mnx << " " << mny << " " << mxx << " " << mxy << endl;
	}

		//system("pause");
		return 0;
}