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
    vector<string>pn={"Sagor","Selim","Salma","Nipu"};
    vector<string>p={"he","she","I","we","you","they"};
    vector<string>n={"book","cow","dog","home","grass","rice","mango"};
    vector<string>v={"read","eat","take","run","write"};
    ifstream in("file_for_9_problem.txt");
    if(!in.is_open()){
        cout<<"Error in file opening.";
    }
    string line;
    while(getline(in,line)){
        //cout<<line<<endl;
        bool f=0,s=0,t=0;
        vector<string>words;
        string tmp="";
        for(int i=0;i<line.size();i++){
            if(line[i]==' '){
                words.push_back(tmp);
                tmp="";
            }
            else{
                tmp+=line[i];
            }
        }
        words.push_back(tmp);
        for(int i=0;i<words.size();i++){
            cout<<words[i]<<" ";
        }
        endline;
        if(words.size()>3||words.size()<2){
            cout<<"Invalid.";
        }
        if((find(pn.begin(),pn.end(),words[0])!=pn.end())||(find(p.begin(),p.end(),words[0])!=p.end())){
            f=1;
        }
        if(find(v.begin(),v.end(),words[1])!=v.end()){
            s=1;
        }
        if(words.size()==3){
            if(find(n.begin(),n.end(),words[2])!=n.end()){
                t=1;
            }
            if(f&&s&&t){
                cout<<"Valid.\n";
            }
            else{
                cout<<"Invalid.\n";
            }
        }
        else if(f&&s){
            cout<<"Valid.\n";
        }
        else{
            cout<<"Invalid.\n";
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