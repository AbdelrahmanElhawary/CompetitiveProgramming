#include<bits/stdc++.h>
using namespace std;
class BouncingBalls {
public:
	// 0 1 2 5
	/*
	   1 0 1 0
	*/
	// .25+.25+.25=.75
	/*
	000  
		0 
	001
		0
	010
	    1
	011
	100
	101
	110
	111
	
	*/
	double expectedBounces(vector <int> x, int t) {
		int n = x.size();
		sort(x.begin(), x.end());
		double ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (x[j] - x[i] <= 2 * t)
					ans++;
		return ans / 4.;
	}
};