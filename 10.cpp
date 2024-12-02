// #include<bits/stdc++.h>
// using namespace std ;


// int main(){
//     int n;
//     cout<<"Enter number of production rule ";
//     cin>>n;
//     string left_r[n],right_r[n];
//     string s;
//     cin.ignore();
//     for(int i=0;i<n;i++){
//         getline(cin,s);
//         //cout<<"The production rule is : "<<s<<endl;
//         left_r[i].push_back(s[0]);
//         for(int j=3;j<s.size();j++){
//             right_r[i].push_back(s[j]);
//         }

//     }
//     for(int i=0;i<n;i++){
//         cout<<left_r[i][0]<<"->";
//         for(int j=0;j<right_r[i].size();j++)
//             cout<<right_r[i][j];
//     cout<<"\n";
//     }
//     string stk,input;
//     cout<<"Take a input sentence: ";
//     cin>>input;
//     input.push_back('$');
//     stk.push_back('$');
//     //cout<<input<<endl;
//     while(input[0]!='$'){
//         stk.push_back(input[0]);
//         input.erase(input.begin());
//         cout<<"Shifted."<<endl;
//         bool b=0;
//         //cout<<"HJ "<<stk<<endl;
//         for(int i=0;i<n;i++){
//             if(stk.find(right_r[i])<stk.size()){
//                 stk.erase(stk.find(right_r[i]),stk.size());
//                 stk+=left_r[i];
//                 b=1;
//                 cout<<"Reduced by "<<left_r[i]<<"->"<<right_r[i]<<endl;
//             }
//             if(b)i=-1;
//             b=0;
//         }
//         //cout<<stk<<endl;
//     }
//     input.push_back('E');
//     //cout<<input<<"     "<<stk<<endl;
//     if(stk==input){
//         cout<<"Accepted\n";
//     }
//     else{
//         cout<<"Rejected\n";
//     }
// }



// // 4
// // E->E+E
// // E->E*E
// // E->(E)
// // E->id

// //sentence
// // E+E*E
// // E+E+E

#include<bits/stdc++.h>
using namespace std;
int n;
string rule_l[10],rule_r[10];

void ans(string sen){
    string stk,input;
    cout<<setw(15)<<"stack"<<setw(15)<<"input"<<setw(15)<<"action"<<endl;
    stk.push_back('$');
    input=sen;
    input.push_back('$');
    while(input[0]!='$'){
        stk.push_back(input[0]);
        cout<<setw(15)<<stk<<setw(15)<<input<<setw(15)<<"Shifted by "<<input[0]<<endl;
        input.erase(input.begin());
        for(int i=0;i<n;i++){
            if(stk.find(rule_r[i])<stk.size()){
                stk.erase(stk.begin()+1,stk.end());
                stk=stk+rule_l[i];
                cout<<setw(15)<<stk<<setw(15)<<input<<setw(15)<<"Reduced by "<<rule_l[i]<<"->"<<rule_r[i]<<endl;
                break;
            }
        }
    }
    input.push_back('E');
    if(input==stk)cout<<"SUCCESS";

}
int main(){
    string s,sen;
    cout<<"Take number of production rule : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Take production rule : ";
        cin>>s;
        rule_l[i]=s[0];
        for(int j=3;j<s.size();j++){
            rule_r[i]+=s[j];
        }
    }
    for(int i=0;i<n;i++){
        cout<<rule_l[i]<<"->"<<rule_r[i]<<endl;
    }
    cout<<"Take a input sentense: ";
    cin>>sen;
    cout<<endl;
    ans(sen);
}