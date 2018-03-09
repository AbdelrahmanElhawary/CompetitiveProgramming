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
	//	cout << fixed << setprecision();
	int t; cin >> t;
	while (t--)
	{
		map<string, string>mp;
		map<string, string>::iterator it;
		set<string>s1, s2, s3;
		string str1, str2,strr1="",strr2="";
		bool f1 = 0, f2 = 0;
		cin >> str1 >> str2;
		for (int i = 1; i < str1.size(); i++)
		{
			if (str1[i] == ':') { f1 = 1; continue; }
			if (str1[i] == ',' || str1[i] == '}') { f1 = 0; if(strr1!="")mp[strr1] = strr2; if(strr1!="")s2.insert(strr1); strr1 = ""; strr2 = ""; continue; }
			if (!f1)strr1 += str1[i];
			if (f1)strr2 += str1[i];
		}
		for (int i = 1; i < str2.size(); i++)
		{
			if (str2[i] == ':') { f1 = 1; continue; }
			if (str2[i] == ',' || str2[i] == '}') {
				f1 = 0;
				if (strr1 != "") {
					it = mp.find(strr1);
					if (it != mp.end())
					{
						if (mp[strr1] != strr2)s3.insert(strr1);
						s2.erase(s2.find(strr1));
					}
					else s1.insert(strr1);
				}
				strr1 = ""; strr2 = "";
				continue;
			}
			if (!f1)strr1 += str2[i];
			if (f1)strr2 += str2[i];
		}
		//	cout << s1.size() << " " << s2.size() << " " << s3.size() << endl;
			if(!s1.size()&&!s2.size()&&!s3.size())
			{
				cout << "No changes\n\n"; continue;
			}
			if (s1.size())cout << '+';
			while (s1.size())
			{
				cout << *s1.begin();
				s1.erase(s1.begin());
				if (s1.size())cout << ',';
				else cout << endl;
			}
			if (s2.size())cout << '-';
			while (s2.size())
			{
				cout << *s2.begin();
				s2.erase(s2.begin());
				if (s2.size())cout << ',';
				else cout << endl;
			}
			if (s3.size())cout << '*';
			while (s3.size())
			{
				cout << *s3.begin();
				s3.erase(s3.begin());
				if (s3.size())cout << ',';
				else cout << endl;
			}
			cout << endl;
		}
	//system("pause");
	return 0;
}
