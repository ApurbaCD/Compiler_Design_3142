#include<bits/stdc++.h>
using namespace std;
#define ll                long long int 
#define ull               unsigned long long int 
//#define vec             vector<int>
//copy from Mrinal da
#define vec               vector<ll>
#define vsort(v)          (v.begin(),v.end())
#define endline           cout<<"\n"
#define yes               cout<<"YES\n"
#define no                cout<<"NO\n"
#define loop(i,a,b)       for(ll i=a;i<=b;i++)
#define loop1(i,a,b)      for(ll i=a;i>=b;i--)
const ll siz=2e5+7;
const ll INF=__LONG_LONG_MAX__;



void ans(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    map<string,string>dept{
        {"CSE","Computer Science and Engineering"},
        {"EEE","Electrical and Electronics Engineering"}
    };
    map<string,string>semester{
        {"1","First semester"},
        {"2","Second semester"},
        {"3","Third semester"},
        {"4","Forth semester"},
        {"5","Fifth semester"},
        {"6","Sixth semester"},
        {"7","Seventh semester"},
        {"8","Eighth semester"},
    };
    map<string,string>year{
        {"1","First year"},
        {"2","Second year"},
        {"3","Third year"},
        {"4","Forth year"}
    };
    map<string,string>courses{
        {"3111", "Software Engineering"},
        {"3112", "Software Engineering Lab"},
        {"3121", "Database Management Systems"},
        {"3122", "Database Management Systems Lab"},
        {"3131", "Digital Signal Processing"},
        {"3132", "Digital Signal Processing Lab"},
        {"3141", "Compiler Design"},
        {"3142", "Compiler Design Lab"},
        {"3151", "Computer Networks"},
        {"3152", "Computer Networks Lab"},
        {"3162", "Software Development Lab"}

    };
    string s;
    cin>>s;
    cout<<dept[s.substr(0,3)]<<" ";
    cout<<year[s.substr(4,1)]<<" ";
    cout<<semester[s.substr(5,1)]<<" ";
    cout<<courses[s.substr(4,4)]<<" ";

}


int main(){
  ios::sync_with_stdio(false);cin.tie(0);
    ans();
}