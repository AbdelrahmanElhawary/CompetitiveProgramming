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
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() != s2.size()) { cout << "No\n"; continue; }
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] >= 'A'&&s1[i] <= 'Z')s1[i] += 32;
			if (s2[i] >= 'A'&&s2[i] <= 'Z')s2[i] += 32;
			if (s1[i] == 'p')s1[i] = 'b';
			if (s1[i] == 'i')s1[i] = 'e';
			if (s2[i] == 'p')s2[i] = 'b';
			if (s2[i] == 'i')s2[i] = 'e';
		}
		if (s1 == s2)cout << "Yes\n";
		else cout << "No\n";
	}

	//	system("pause");
		return 0;
}