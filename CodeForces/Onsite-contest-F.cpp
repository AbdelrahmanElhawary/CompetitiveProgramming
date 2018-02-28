#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int arr[26];
long long d=0;
int main()
{
//cout<<fixed<<setprecision(2);
string s; cin>>s;
bool f1=0,f2=0; int str=0,en;
long long c=0,cc=0;
for(int i=0;i<26;i++)
    cin>>arr[i];

    for(int i=0;i<s.size();i++)
    {
    if(f1&&s[i]!='?'){f2=1; en=i-1;  }
     if(s[i]=='?'&&!f1){f1=1; str=i;}
    if(f2)
    {
        if(str==0)
        {
            char cccc=s[en+1];
            for(int j=0;j<s[en+1]-'a';j++)
            if(arr[s[en+1]-'a']==arr[j]){cccc=char(j+'a'); break;}
            for(int j=str;j<=en;j++)
                s[j]=cccc;
        }
        else
        {
            int mn=1e9; char ch;
            for(int j=0;j<26;j++)
            {
                int xy= abs(arr[s[str-1]-'a']-arr[j])+abs(arr[s[en+1]-'a']-arr[j]);
                if(xy<mn){mn=xy; ch=(char)(j+'a'); }
            }
           // cout<<str<<" "<<en<<endl;
            for(int j=str;j<=en;j++)
                s[j]=ch;
        }
        f1=0; f2=0;
    }

    }
     en=s.size()-1;
    if(f1)
    {
         char cccc=s[str-1]; if(str==0)cccc='a';
            for(int j=0;j<s[str-1]-'a';j++)
            if(arr[s[str-1]-'a']==arr[j]){cccc=char(j+'a'); break;}
            for(int j=str;j<=en;j++)
                s[j]=cccc;
    }


    for(int i=1;i<s.size();i++)
    c+=abs(arr[s[i-1]-'a']-arr[s[i]-'a']);
        cout<<c<<endl;
    cout<<s<<endl;
    return 0;
}