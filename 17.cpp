// //@Mehedi-Hasan-Shakil

// /*
// Write a program that converts the C++ statement to an intermediate code of 
// Post-fix notation form.
// */
// #include <bits/stdc++.h>
// using namespace std;

// int precedence(char ch);
// string infixtoPostfix(string infix);
// string solve(string infix);

// int main() {
//     // string infix = "if a then if b then c else if d then e else f else if g then h else i ";
//     freopen("17.txt", "r", stdin);
//     string infix;
//     getline(cin, infix);
//     cout<<solve(infix);
//     return 0;
// }

// string solve(string infix) {
//     string temp = "", postfix = "";
//     stack<string> stk;
//     for(char ch : infix) {
//         if(ch != ' ') temp += ch; // formation of keyword or expression
//         else {
//             if(temp == "then") {temp = ""; continue;}
//             if(temp == "if") stk.push(temp);
//             else if(temp == "else") {
//                 stk.push(temp);

//             }
//             else {
//                 // convert infix expression into postfix and add to the postfix string
//                 postfix += infixtoPostfix(temp);
//                 // pop if-else pair from stack and add "?" to the postfix string
//                 while(!stk.empty() && stk.top() == "else") {
//                     postfix += "?";
//                     stk.pop();
//                     stk.pop();
//                 }
//             }
//             temp = "";
//         }
//     }
//     return postfix;    
// }

// string infixtoPostfix(string infix) {
//     string postfix = "";
//     stack<char> stk;
//     for(char ch : infix) {
//         // add operands to postfix string
//         if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
//             postfix += ch;
//         }
//         // push open parentheses into stack
//         else if(ch == '(') stk.push(ch);

//         else if(ch == ')') {
//             // pop from stack and add to postfix until open parentheses appears
//             while (stk.top() != '(')
//             {
//                 postfix += stk.top();
//                 stk.pop();
//             }
//             stk.pop();
//         }
//         // push or pop operator based on their precedence
//         else if(ch != ' ') {
//             while(!stk.empty() && precedence(ch) <= precedence(stk.top())) {
//                 postfix += stk.top();
//                 stk.pop();
//             }
//             stk.push(ch);
//         }          
//     }
//     while (!stk.empty()) {
//         postfix += stk.top();
//         stk.pop();
//     }
//     return postfix;
// }

// int precedence(char ch) {
//     switch (ch)
//     {
//     case '^':
//         return 3;
//     case '/':
//     case '*':
//         return 2;
//     case '+':
//     case '-':
//         return 1;
//     default:
//         return 0;
//     }
// }


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

string infixtopostfix(string s){
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


string ans(string s){
    string tmp="";
    stack<string>stk;
    string f="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            tmp+=s[i];
        }
        else if(tmp=="then"){
            tmp.clear();
            continue;
            }
        else if(tmp=="if"||tmp=="else"){
            stk.push(tmp);
            tmp.clear();
        }
        else{
            string sub=infixtopostfix(tmp);
            f+=sub;
            if(stk.top()=="else"){
                f+='?';
                stk.pop();
                stk.pop();
            }
            tmp.clear();
        }
    }
    return f;

}


int main (){
    //last space is important 
    string s="if a then if c-d then a+c else a*c else a+b ";
    //string s="a+b";
    cout<<ans(s)<<endl;
}
