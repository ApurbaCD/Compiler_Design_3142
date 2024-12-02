#include<bits/stdc++.h>
using namespace std ;

int pre(char c){
    if(c=='+')return 1;
    else if(c=='-')return 1;
    else if(c=='*')return 2;
    else if(c=='/')return 3;
    else if(c=='^')return 4;
    else return 0;
}

string ans(string s){
    string f="";
    stack<char>stk;
    stk.push('(');
    s=s+')';
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            f.push_back(s[i]);
        }
        else if(s[i]=='('){
            stk.push(s[i]);
        }
        else if(s[i]==')'&&!stk.empty()){
            while(stk.top()!='('){
                f.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else{
            while(!stk.empty()&&(pre(stk.top())>pre(s[i]))){
                f.push_back(stk.top());
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    return f;
}

int main (){
    string s="(A-B)*(D/E)";
    //string s="a+b";
    cout<<ans(s)<<endl;
}
