#include<bits/stdc++.h>
using namespace std;

map<char,vector<string>>grammer;
map<char,set<char>>first;
map<char,set<char>>follow;
vector<char>order;

void flw(){
    follow['E'].insert('$');
    for(auto target:order){ // target nonterminal or variables
        for(auto c:order){  // to check all the production rule
            for(auto str:grammer[c]){ // to check the following of a targer variable or nonterminal (every str contain a string of production)
                bool stop=0;
                int j=0;
                for(int i=0;i<str.size();i++){ //
                    if(str[i]==target){ //if i get the targeted variable in the production rule
                        for(j=i+1;j<str.size();j++){  // for the following variable/terminal
                            if(str[j]>='A'&&str[i]<='Z'){  //variable/non-termianl
                                for(auto fst:first[str[j]]){
                                    if(fst!='@')follow[target].insert(fst);
                                }
                                if(first[str[j]].find('@')==first[str[j]].end()){  // if i not efsilon
                                    stop=1;break;
                                }
                            }
                            else{
                                follow[target].insert(str[j]); // terninal 
                                stop=1;break;
                            }
                        }
                    }
                    if(stop)break;
                }
                if(j==str.size()){  // if the targeted variable is at the last
                    for(auto flw:follow[c]){
                        follow[target].insert(flw);
                    }
                }
            }
        }
    }

    //print follow 
    for(auto c:order){
        cout<<"Follow of "<<c<<"= {" ;
        for(auto val:follow[c]){
            cout<<val<<", ";
        }
        cout<<"}\n";
    }
}
void print_first(){
     //first
    for(auto c: order){
        cout<<"First of "<<c<<"= { ";
        for(auto x:first[c]){
            cout<<x<<", ";
        }
        cout<<"}\n";
    }
}
void table(){
    map<pair<char,char>,string>parse_table;

     for(auto row:order){
        for(auto col:first[row]){
            if(col!='@'){
                bool set=false;
                for(auto str:grammer[row]){
                    //cout<<str<<endl;
                    if(str[0]==col){
                        parse_table[{row,col}]=string(1,row)+"->"+str;
                        set=true;
                    }
                }
            if(!set) //cout<<endl;
               parse_table[{row,col}]=string(1, row) + "->" + grammer[row][0];
            }
        }
        if(first[row].find('@')!=first[row].end()){
            for(auto col:follow[row])
            parse_table[{row,col}]=string(1,row)+"->@";
        }
    }

    //print table 

    cout<<"    Parsing Table     \n";
    vector<char>column={'i','+','*','(',')','$'};
    for(auto c:column)cout<<setw(8)<<c;
    cout<<"\n";
        for(auto row:order){
            cout<<"     ";
            for(auto col: column){
                if(!parse_table[{row,col}].empty()){
                    cout<<left<<setw(8)<<parse_table[{row,col}];
                }
                else{
                    cout<<"        ";
                }
            }
            cout<<"\n";
        }

}

int main(){
    // freopen("14.txt","r",stdin);
    // string production;
    // while(getline(cin,production)){
    //     grammer[production[0]].push_back(production.substr(3));
    //     if(find(order.begin(),order.end(),production[0])==order.end()){
    //         order.push_back(production[0]);
    //     }
    // }
    order={'E','P','T','U','F'};
// E->TP
// P->+TP
// P->@
// T->FU
// U->*FU
// U->@
// F->(E)
// F->i

    //Grammer
    grammer['E']={"TP"};
    grammer['P']={"+TP","@"};
    grammer['T']={"FU"};
    grammer['U']={"*FU","@"};
    grammer['F']={"(E)","i"};

    // for(auto c:order){
    //     cout<<c<<"->";
    //     //cout<<grammer[c].size()<<endl;
    //     for(auto x:grammer[c]){
    //         cout<<x<<"|";
    //     }cout<<"\n";
    // }


    //First
    first['E']={'i','('};
    first['P']={'+','@'};
    first['T']={'i','('};
    first['U']={'*','@'};
    first['F']={'i','('};

    //call follow
    flw();

    //call first
    print_first();

    //parse table 
    table();

}



