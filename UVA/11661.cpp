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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main()
{
	fast_in_out();
	int n;
	while (cin >> n && n)
	{
		string s; cin >> s;
		int l, r, miny = 1e9,c=0; bool f1 = 0, f2 = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'Z') { miny = 0; break; }
			if (s[i] == '.' && !f1 && !f2)continue;
			if (s[i] == '.') { c++; continue; }
			if (!f2&&s[i] == 'R') { l = i; f1 = 1; c = 1; continue; }
			if (f1&&s[i] == 'D') { miny = min(c, miny); c = 1; f2 = 1; f1 = 0; continue; }
			if (!f1&&s[i] == 'D') { c=1; f2++; continue; }
			if (f2&&s[i] == 'R') { miny = min(miny, c); c = 1; f2 = 0; f1 = 1; continue; }
		}
		cout << miny << endl;

	}
	
//	system("pause");
	return 0;
}
