#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
using namespace std;
map<string, int>mp;
map<int, string>mp1;
map<string, int>::iterator it;
string calc(string str)
{
	string s2;
	istringstream iss(str.substr(1));
	string ans = "";
	char s = '+';
	int sum = 0;
	while (iss >> s2)
	{
		if (mp.find(s2) != mp.end())
		{
			if (s == '+')
			{
				sum += mp[s2];
			}
			else if (s == '-')
			{
				sum -= mp[s2];
			}
		}
		else
		{
			ans = "unknown";
			return str.substr(1) + " " + ans;
		}
		iss >> s;
	}
	if (mp1.find(sum) != mp1.end())
	{
		ans = mp1[sum];
	}
	else
	{
		ans = "unknown";
	}
	return str.substr(1) + " " + ans;
}
int main()
{

	string s;
	while (cin >> s)
	{
		if (s == "clear") { mp.clear(); mp1.clear(); continue; }
		if (s == "def")
		{
			string str; int v;
			cin >> str >> v;
			if (mp.find(str) != mp.end())
			{
				int va = mp[str];
				mp.erase(str);
				mp1.erase(va);
			}
			mp[str] = v;
			mp1[v] = str;
			//S.insert(ch);
			//cout << ch << " " << mp[ch] << endl;
			continue;
		}
		else
		{
			string str;
			getline(cin, str);
			cout << calc(str) << endl;

		}
	}


 //   system("pause");
	return 0;
}