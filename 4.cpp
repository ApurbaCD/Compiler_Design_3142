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

// File Content: 
// Hey Geek! Welcome to GfG. Happy Coding.
// I1234 213432 43234
// J327389023
// sdhjbbk
// 213333331323324345

void ans(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ifstream in("file_for_4_number_problem.txt");
    if(!in.is_open()){
        cout<<"Error in file opening \n ";
    }
    string line ;
    while(getline(in,line)){
        cout<<line<<endl;
        if(((line[0]>=73)&&(line[0]<=78))||((line[0]>=105)&&(line[0]<=110))){
            for(int i=1;i<line.size();i++){
                if(((line[i]>=65)&&(line[i]<=90))||((line[i]>=97)&&(line[i]<=122))||(isspace(line[i])))continue;
                else{
                    cout<<"Invalid Input or Undefined\n";
                    break;
                }
            }
            cout<<"Integer variable\n";
            //cout<<line[0]<<" "<<(char)line[0]<<endl;
        }
        else if(line[0]>=49&&line[0]<=57){
            int l=1;
            for(int i=1;i<line.size();i++){
                l++;
                if(line[i]>=48&&line[i]<=57)continue; 
                else{
                    cout<<"Invalid Input or Undefined\n";
                    l=-1;
                    break;
                }
            }
            if(l>0){
                if(l<5)cout<<"ShortInt Number\n";
                else cout<<"LongInt Number\n";
            }
        }
        else{
            cout<<"Invalid Input or Undefined\n";
        }
        //in.close();
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