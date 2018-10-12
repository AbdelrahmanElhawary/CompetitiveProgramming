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
#include <assert.h>
#include<complex>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
const double EPS = 1e-9;
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
ll grid[15][15];

int main() {
	int n; ll l;
	bool f=0;
	cin>>n>>l;
	int hf=(n-2)/2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	for(int mid=1;mid<n;mid++)
	{
		for(int mask=0;mask<(1<<n);mask+=2)
		{
			if(mask&(1<<mid))continue;
			if(__builtin_popcount(mask)!=hf)continue;
			set<ll>s;
			vector<int>v,v2;
			v.push_back(0);v2.push_back(0);
			for(int i=1;i<n;i++)
			{
				if(i==mid)continue;
				if(mask&(1<<i))v.push_back(i);
				else v2.push_back(i);
			}
			v.push_back(mid);v2.push_back(mid);
			do{
				ll cost=0;
				for(int i=0;i<v.size()-1;i++)
				{
					cost+=grid[v[i]][v[i+1]];
				}
				if(cost>l)continue;
				s.insert(cost);
			}while(next_permutation(v.begin()+1,v.end()-1));
				do{
				ll cost=0;
				for(int i=0;i<v2.size()-1;i++)
				{
					cost+=grid[v2[i]][v2[i+1]];
				}
				if(cost>l)continue;
				if(s.find(l-cost)!=s.end())
				f=1;
			}while(next_permutation(v2.begin()+1,v2.end()-1));
			
			
		}
	}
	if(f)cout<<"possible\n";
	else cout<<"impossible"<<endl;
	pause();
	return 0;
}