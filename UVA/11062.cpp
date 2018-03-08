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
set<string>s;
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	string se, str;
	while (getline(cin, se))
	{
		str += se;
		str += " ";
		//if (se == "1")break;
	}
	string st = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') { if(st!="")s.insert(st); st = ""; continue; }
		if (str[i] == '-'&&str[i+1]==' ') {i++; continue; }
		else if(str[i]=='-'&&str[i+1]!=' ') { st += str[i]; continue; }
		if (str[i] >= 'A'&&str[i] <= 'Z')str[i] += 32;
		if(str[i]>='a'&&str[i]<='z')st += str[i];
		else { if(st!="")s.insert(st); st = ""; }
	}
	if (st != "")s.insert(st);
	while (s.size())
	{
		st = *s.begin();
		s.erase(s.begin());
		cout << st << endl;
	}
	//system("pause");
	return 0;
}
