#include<bits/stdc++.h>
using namespace std;
vector<string>key={"int","floot","double","long long int ","for","endline","if","else if","else","break","goto",
                    "vector","string","char","main","include","cout","size"};
bool bracket(string s){
    stack<char>stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stk.push('(');
        }
        else if(s[i]==')'){
            if(!stk.empty()){
                stk.pop();
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

int iden(string s){
    if(find(key.begin(),key.end(),s)!=key.end()){
        return 50;
    }
    if(s[0]=='_'||isalpha(s[0])){
    for(int i=1;i<s.size();i++){
        if(!isalnum(s[i]))return 0;
    }
    return 1;
    }
    if(isdigit(s[0])){
        //cout<<"KJ "<<s.size()<<endl;
        for(int i=1;i<s.size();i++){
            if(!isdigit(s[i])){
                //cout<<"NK";
                return 0;
            }
        }
        //cout<<" i \n";
        return 1;
    }
    return 0;
}

bool oper(char c){
    if(c=='+')return 1;
    if(c=='-')return 1;
    if(c=='*')return 1;
    if(c=='/')return 1;
    return 0;
}
bool ans(string s){
    if(!bracket(s)){
        // cout<<"KL";
        return 0;
    }
    if(oper(s[0])||oper(s[s.size()-1])){
        return 0;
    }
    string tmp="";
    for(int i=1;i<s.size();i++){
        if(oper(s[i])){
            //cout<<"KL";
            if(oper(s[i-1])||(s[i-1]=='('||s[i-1]==')')){
                return 0;
            }
        }
        else if (s[i]!='('&&s[i]!=')'){
            if(s[i]!=' ')
            tmp+=s[i];
            if(s[i]==' '&&tmp.size()){
                //cout<<tmp.size()<<" s "<<tmp<<endl;
                //cout<<"u:"<<iden(tmp)<<endl;;
                if(!iden(tmp)){
                    //cout<<"L:"<<iden(tmp)<<endl;
                    return 0;
                }
                tmp.clear();
            }
        }
    }
    return 1;
}

int main (){
    string s="2 + 3 + ( 2 * 6 ) + 4 ";
    bool b =1;
    b=ans(s);
    cout<<b<<endl;
    if(!b){
        cout<<"Invalid \n";
    }
    else{
        cout<<"Valid\n";
    }
    //cout<<iden("2")<<endl;
}