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
    ifstream in("file_for_6_number.txt");
    if(!in.is_open()){
        cout<<"error in file opening\n";
    }
    string line;
    while(getline(in,line)){
        string s=line;
        cout<<s<<endl;
        if(s[0]=='0'){
            bool b=1;
            for(int i=0;i<s.size();i++){
                if(s[i]!='0'&&s[i]!='1'){
                    cout<<"Invalid Input or Undefined\n";
                    b=0;
                    break;
                }
            }
            if(b){
                cout<<"Binary Number\n";
            }
        }
        else if(s.size()<4){
            cout<<"Invalid Input or Undefined\n";
        }
        else if(s[0]=='c'){
            bool b=1;
            for(int i=1;i<s.size();i++){

                if(i==1){
                    if(s[i]!='h'){
                        cout<<"Invalid Input or Undefined\n";
                        b=0;
                        break;
                    }
                }
                else if(i==2){
                    if(s[i]!='_'){
                        cout<<"Invalid Input or Undefined\n";
                        b=0;
                        break;
                    }
                }
                else{
                    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='1'&&s[i]<='9')){
                        continue;
                    }
                    else{
                        cout<<"Invalid Input or Undefined1\n";
                        b=0;
                        break;
                    }

                }
            }
            if(b){
                cout<<"Character Variable\n";
            }
        }
        else if(s[0]=='b'){
            bool b=1;
            for(int i=1;i<s.size();i++){

                if(i==1){
                    if(s[i]!='n'){
                        cout<<"Invalid Input or Undefined\n";
                        b=0;
                        break;
                    }
                }
                else if(i==2){
                    if(s[i]!='_'){
                        cout<<"Invalid Input or Undefined\n";
                        b=0;
                        break;
                    }
                }
                else{
                    if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='1'&&s[i]<='9')){
                        continue;
                    }
                    else{
                        cout<<"Invalid Input or Undefined1\n";
                        b=0;
                        break;
                    }

                }
            }
            if(b){
                cout<<"Binary Variable\n";
            }
        }
        else{
            cout<<"Invalid Input or Undefined\n";
        }
    }
}


int main(){
  ios::sync_with_stdio(false);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        ans();
    }
}