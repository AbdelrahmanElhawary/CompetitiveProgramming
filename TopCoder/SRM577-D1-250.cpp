#include<bits/stdc++.h>
#define ld long double
using namespace std;
class EllysRoomAssignmentsDiv1 {
public:
	ld getAverage(vector<string>v) {
		vector<pair<int, int>>ve;
		int id = 0;
		string str = "";
		for (auto e : v) 
			str += e;
		stringstream ss(str);
		int x;
		while (ss >> x) {
			ve.push_back({ x,id++ });
		}
		sort(ve.rbegin(), ve.rend());
		int n = ve.size();
		int R = (n + 19) / 20;
		ld ret = 0;
		vector<ld>vee;
		bool last = 0;
		for (int i = 0; i < n; i += R) {
			bool ok = 0; int sum = 0;
			int c = 0;
			for (int j = i; j < min(n, i + R); j++) {
				sum += ve[j].first;
				if (!ve[j].second) { 
				vee.push_back(ve[j].first);
				 ret+=ve[j].first;
				if (i + R >= n)last = 1;
				 ok = 1; id = j; break;
				  }
				c++;
			}
			if (ok)continue;
			vee.push_back(sum * 1. / c);
			ret += vee.back();
		}
		ld q = n / R;
		if (n % R == 0) {

			return ret / q;
		}
		if (last){

		return ret / (q + 1);
		}
		ld p = (n % R) / (R * 1.);

		return ret / (q + 1) * p + (1. - p) * (ret - vee[q]) / q;
	}
};