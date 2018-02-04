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
int main(){
	int n; cin >> n;
	string s; cin >> s;
	int mn = 0, mx = 0, c1 = 0; bool f = 0;
	for (int i = 0; i < s.size(); i++)
	{

		if (f&&s[i] != 'v'&&s[i] != 'w') { mn += ceil(c1 / 2.0); f = 0; c1 = 0; }
		if (s[i] != 'v'&&s[i] != 'w'&&!f) { mn++; mx++; continue; }
		if (s[i] == 'v') { mx++; c1++; f = 1; }
		if (s[i] == 'w') { mx += 2; c1 += 2; f = 1; }
	}
	mn += ceil(c1 / 2.0); f = 0; c1 = 0;
	cout << mn << " " << mx << endl;
	//system("pause");
	return 0;
}