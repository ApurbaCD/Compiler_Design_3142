#include<bits/stdc++.h>
using namespace std ;
int a[27];
void ans(){
    string s="Md, Tareq Zaman.part-3,2011";
    vector<char>v;
    set<char>v1,v2;
    //cout<<s;
    //cout<<"KL";
    int l=s.size();
    //cout<<l<<endl;
    for(int i=0;i<l;i++){
        //cout<<s[i]<<" ";
        int tmp = (int)s[i];
        if((s[i]>=65)&&(s[i]<=90)){
            //cout<<s[i]<<" 45 ";
            tmp=tmp-66;
            a[tmp]++;
            v.push_back(s[i]);
        }
        else if((s[i]>=97)&&(s[i]<=122)){
            tmp=tmp-96;
            a[tmp]++;
            v.push_back(s[i]);
        }
        else if((s[i]>=48)&&(s[i]<58)){
            v1.insert(s[i]);
        }
        else{
            v2.insert(s[i]);
        }
    }
    for(int i=1;i<27;i++){
        char c=(char)(i+64);
        cout<<c<<" "<<a[i]<<endl;
    }
    cout<<"Numbers : \n";
    for(auto x : v1){
        int n=0;
        for(int i=0;i<l;i++){
            if(s[i]==x)n++;
        }
        cout<<x<<" have "<<n<<"times   \n";
    }
    cout<<endl;
    cout<<"Others characters : \n";
    for(auto x : v2){
        int n=0;
        for(int i=0;i<l;i++){
            if(s[i]==x)n++;
        }
        cout<<x<<" have "<<n<<"times   \n"; 
    }

}
int main(){
    ans();

}
