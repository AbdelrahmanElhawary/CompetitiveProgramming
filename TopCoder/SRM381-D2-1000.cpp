#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
	string s1 = a + b, s2 = b + a;
	return s1 < s2;
}
class TheNumbersLord {
public:
	string create(vector<int>v, int n) {
		sort(v.begin(), v.end());
		while (v.size() < n)
			v.push_back(v.back());
		vector<string>ve(n);
		for (int i = 0; i < n; i++)
			ve[i] = to_string(v[i]);
		sort(ve.rbegin(), ve.rend(),cmp);
		string ans = "";
		for (auto e : ve)ans += e;
		return ans;
	}
};