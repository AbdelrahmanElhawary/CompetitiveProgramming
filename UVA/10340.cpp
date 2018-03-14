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
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
#define endl '\n'

using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int l = 0, r = 0;
		for (; l < s1.size() && r < s2.size(); r++)
			if (s1[l] == s2[r])l++;
		if (l == s1.size())cout << "Yes\n"; else cout << "No\n";
	}
	//system("pause");
	return 0;
}