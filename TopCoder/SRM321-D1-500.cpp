#include<bits/stdc++.h>
using namespace std;
class WeirdSort {
public:
	vector<int> sortArray(vector<int>v) {
		multiset<int>s(v.begin(), v.end());
		vector<int>ans;
		while (s.size()) {
			for (auto e : s) {
				if (ans.size() && ans.back() + 1 == e)continue;
				if (*s.begin() == e && *s.rbegin() == e + 1)continue;
				ans.emplace_back(e);
				s.erase(s.find(e)); break;
			}
		}
		return ans;
	}
};