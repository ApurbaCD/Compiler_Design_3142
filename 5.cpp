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
    ifstream in("file_for_5_problem.txt");
    if(!in.is_open()){
        cout<<"Error occur\n";
    }
    string line;
    while(getline(in,line)){
        bool b=1;
        int cnt = 0;
      //  cout<<line<<endl;
        for ( int i = 0; i<line.size(); i++ ){
            if(line[i]=='.')cnt++;
        }
        if((line[0]>='A'&&line[0]<=72)||(line[0]>=97&&line[0]<=104)||(line[0]>=111&&line[0]<=122)||(line[0]>=89&&line[0]<=90)){
            for(int i=1;i<line.size();i++){
                if((line[i]>=65&&line[i]<=90)||(line[i]>=97&&line[i]<=122)||(line[i]>=48&&line[i]<=97)){
                    continue;
                }
                else{
                    cout<<"Otherwise\n";
                    b=0;break;
                }
            }
            if(b){
                cout<<"Float variable\n";
            }

        }
        else if(cnt==1){
            bool b1=1;
            if(line[0]=='0'){
                if(line[1]=='.'){
                    int digit_cnt=0;
                    for(int i=2;i<line.size();i++){
                        if(line[i]>='0'&&line[i]<='9'){
                            digit_cnt++;
                        }
                        else{
                            b1=0;
                            cout<<"Otherwise\n";
                            break;
                        }
                    }
                    if(b1){
                    if(digit_cnt==2){
                        cout<<"Float\n";
                    }   
                    else if(digit_cnt>=3){
                        cout<<"double\n";
                    }
                    else{
                        cout<<"Otherwise\n";
                    }
                    }
                }
            }

            else{
                bool b1=1,b2=1;
                if(line[0]>='1' && line[0]<='9'){
                    int i=0;
                    while(line[i]!='.'){
                        if(line[i]>='0' && line[i]<='9'){
                            i++;continue;
                        }
                        else{
                            cout<<"Otherwise\n";
                            b1=0;break;
                        }
                    }
                    if(b1){
                        int digit_cnt1=0;
                        for(int j=i;j<line.size();j++){
                           if(line[j]>='0' && line[j]<='9'){
                            digit_cnt1++;
                            continue;
                            }
                            else if(line[j]=='.')continue;
                            else{
                                b2=0;
                            }
                        }
                        if(b1&&b2){
                            if(digit_cnt1==2){
                                cout<<"Float\n";
                            }   
                            else if(digit_cnt1>=3){
                                cout<<"double\n";
                            }
                            else{
                                cout<<"Otherwise\n";
                            }
                        }
                        

                    }
                }
            }
        }
        else{
            cout<<"Otherwise\n";
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