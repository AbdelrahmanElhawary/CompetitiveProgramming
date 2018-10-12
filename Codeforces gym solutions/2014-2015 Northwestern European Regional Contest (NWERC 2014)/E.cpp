#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define endl "\n"
double n = 1000,p = 20,s=15,v=12;
double c =1.12;
double eq1(double md){
	c = md;
	return n *pow(log2(n),c * sqrt(2)) / (p *1000000000);
}
double eq2(double md){
	c = md;
	return s * (1 + 1.0/c) / v;
}
int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

	cout<<setprecision(10)<<fixed;
	cin>>n>>p>>s>>v;

	double s1 = 0,e1 = 	200,ans=1e18,ans2;
	int cnt = 0;
	while(cnt<1000){
		double md = cnt++;
		double md1 = (s1*2 + e1) / 3.0;
		double md2 = (s1+2*e1) / 3.0;
		if(eq1(md1) + eq2(md1) < eq1(md2) + eq2(md2)){
			if(eq1(md1) + eq2(md1) < ans){
				ans = eq1(md1) + eq2(md1);
				ans2= md1;
			}
			e1 = md2;
		}
		else {
			//cout <<eq1(md2) + eq2(md2)  <<endl;

			if(eq1(md2) + eq2(md2) < ans){
				ans = eq1(md2) + eq2(md2);
				ans2= md2;
			}
			s1 = md1;
		}
	}
	cout<<setprecision(10)<<fixed;
	cout<<ans<<" "<<ans2<<endl;
	return 0;
}