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
    vector<string>keyword = { "int","double","floot","long long int ",
                            "true","false",
                            "or","and","xor",
                            "for","if","else if","else","do","while","break","continue",
                            "char","string","void","auto","new","switch",
                            "namespace","class","const","sizeof","typeof",
                            "delete","nullptr"                            
    };
    vector<string> arithmetic_operation = { "=","+","-","/","*","++","--","%","&","&&","||","|","^","+=","-=","*=","/=","==",">=","<=","<",">","!="};
    ifstream in("file_for_8_problem.txt");
    if(!in.is_open()){
        cout<<"Error in opening file\n";
    }
    string line;
    while(getline(in,line)){
        cout<<line<<" ";
    }
    endline;
    ifstream in1("file_for_8_problem.txt");
    while(getline(in1,line)){
        //cout<<line<<endl;
        // string word;
        // istringstream ass(line);
        // while(ass>>word){
        //     cout<<word<<endl;
        // }
        if(find(keyword.begin(),keyword.end(),line)!=keyword.end()){
            cout<<line<<" is a keyword.\n";

        }
        else if(find(arithmetic_operation.begin(),arithmetic_operation.end(),line)!=arithmetic_operation.end()){
            cout<<line<<" is a Arithmetic operation.\n";
        }
        else if((line[0]>='a'&&line[0]<='z')||(line[0]>='a'&&line[0]<='z')){
            bool flag = 1;
            for(int i=0;i<line.size();i++){
                if(isalnum(line[i])||line[i]=='_'){
                    continue;
                }
                else{
                    flag=false;
                }
            }
            if(flag){
                cout<<line<<" is a indentifier.\n";
            }
            else{
                cout<<"Invalid\n";
            }
        }
        else if(line[0]>='0'&&line[0]<='9'){
            bool flag=0,d=0,in=0;
            for(int i=0;i<line.size();i++){
                if(isdigit(line[i])){
                    in=1;
                }
                else if(line[i]=='.'){
                    d=1;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"Invalid\n";
            }
            else if(d){
                cout<<line<<" Float number.\n";
            }
            else{
                cout<<line<<" Integer number\n";
            }
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