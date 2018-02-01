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
#define F first
#define S second
#define ll long long
using namespace std;
int ar[] = { 6,2,5,5,4,5,6,3,7,6 };
bool cmp(char a, char b)
{
	return ar[a - '0'] < ar[b - '0'];
}
int main()
{
	string s;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; cin >> s;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += ar[s[i] - '0'] -2;
			s[i] = '1';
		}
		bool f = 0; int j;
		for (int i = 0; i < n; i++)
		{
			if (sum == (n - i) * 5) { j = i; f = 1; break; }
			if (sum >= 4) { s[i] = '9'; sum -= 4; continue; }
			else if (sum >= 1 && (n - i) > 1) { s[i] = '7'; sum--; continue; }
			else if (sum >= 1 && (n - i) == 1) { for (int k = 9; k > -1; k--)if (sum + 2 == ar[k]) { s[i] = char(48 + k); sum -= ar[k]; break; } }
		}
		if (f) {
			for (; j < n; j++)s[j] = '8';
	}
		cout << s << endl;
	}
	//system("pause");
	return 0;
}