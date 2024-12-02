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

void sentances_Conso(string s){
    ll l=s.size();
    for(int i=0;i<l;i++){
        if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
             while(1){
                if(s[i]==32)break;
                cout<<s[i];
                i++;
             }
            cout<<" ";
        }
        else{
            while(s[i]!=32)i++;
        }
    }
    endline;
}
void sentances_Vow(string s){
    ll l=s.size();
    for(int i=0;i<l;i++){
        if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
            while(s[i]!=32)i++;
        }
        else{
            while(1){
                if(s[i]==32)break;
                cout<<s[i];
                i++;
            }
            cout<<" ";
        }
    }
    endline;
}

void ans(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s="Munmun is the student of Computer Science & Engineering ";
    string c =" ";
    int l=s.size(),vowels=0,consonants=0,a=0,e=0,ii=0,o=0,u=0;
    vector<string>v;
    vector<string>v3,v4;
    set<char>v1,v2;
    for(int i=0;i<l;i++){
        if((s[i]=='a')||(s[i]=='A')){vowels++; a++; v1.insert(s[i]);}
        else if((s[i]=='i')||(s[i]=='I')){vowels++; e++; v1.insert(s[i]);}
        else if((s[i]=='e')||(s[i]=='E')){vowels++; ii++; v1.insert(s[i]);}
        else if((s[i]=='o')||(s[i]=='O')){vowels++; o++; v1.insert(s[i]);}
        else if((s[i]=='u')||(s[i]=='U')){vowels++; u++; v1.insert(s[i]);}
        else if ((s[i]>=65&&s[i]<=90)||(s[i]>=97&&(s[i]<=122))){ consonants++; v2.insert(s[i]);}
    }
    cout<<"The Vowel Word       : ";
    sentances_Conso(s);
    
    cout<<"The Consonant Word   :   ";
    sentances_Vow(s);

    // cout<<s<<endl;
    cout<<"Numbers Of Vowel      "<<vowels<<endl;
    cout<<"Numbers Of constants  "<<consonants<<endl;
    cout<<"vowels are : ";

    for(auto x: v1){
       cout<<x<<" ";
    }endline;

    cout<<"consonants are : ";
    for(auto x: v2){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
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