#include<bits/stdc++.h>
using namespace std;

map<char,vector<string>>grammer;
map<char,vector<string>>::iterator it;
map<char,set<char>>follow;
map<char,set<char>>first;
vector<char>order;
void frst(){
    for(int i=order.size()-1;i>=0;i--){
        for(auto x:grammer[order[i]]){
            for(int j=0;j<x.size();j++){
                if(x[j]>='A'&&x[j]<='Z'){
                    for(auto f:first[x[j]]){
                        first[order[i]].insert(f);//all first of nonterminal variable of production rule 
                    }
                    if(first[x[j]].find('@')==first[x[j]].end())break; //if i get efsilon in nonterminal variable first set
                }
                else{
                    first[order[i]].insert(x[j]); //if i get terminal in production rule
                    break;
                }
            }
        }
    }
    
    //first
    for(auto c: order){
        cout<<"First of "<<c<<"= {";
        for(auto x:first[c]){
            cout<<x<<",";
        }
        cout<<"}\n";
    }
}

void flow(){
    follow['E'].insert('$');
    for(auto target:order){ // to find all the follow of nonterminal  
        for(auto c:order){ // to get which the follow of a perticular nonterminal
            for(auto x:grammer[c]){
                bool stop=false;
                int j=0;
                for(int i=0;i<x.size();i++){
                    if(x[i]==target){
                        for(j=i+1;j<x.size();j++){
                            if(x[j]>='A'&&x[j]<='Z'){
                                for(auto f:first[x[j]]){
                                    if(f!='@')follow[target].insert(f);
                                }
                                if(first[x[j]].find('@')==first[x[j]].end()){
                                    stop=true;//if nonterminal doesn't contain epsilon
                                    break;
                                }
                            }
                            else{
                                follow[target].insert(x[j]);
                                stop=true;break;
                            }
                        }
                    }
                    if(stop)break;
                }
                if(j==x.size()){ //when the nonterminal is not following anyone
                    for(auto tmp:follow[c]){
                        follow[target].insert(tmp); //to push the follow set of the own follow set
                    }
                }  
            }
            
        }
    }
    
    // follow

    for(auto c: order){
        cout<<"Follow of "<<c<<"= {";
        for(auto x:follow[c]){
            cout<<x<<",";
        }
        cout<<"}\n";
    }
}
int main(){

    freopen("13.txt","r",stdin);
    string production;
    while(getline(cin,production)){
        grammer[production[0]].push_back(production.substr(3));
        if(find(order.begin(),order.end(),production[0])==order.end()){
            order.push_back(production[0]);
        }
    }
    // for(it=grammer.begin();it!=grammer.end();it++){
    //     cout<<it->first<<"->";
    //     for(int i=0;i<it->second.size();i++){
    //         cout<<it->second[i]<<"|";
    //     }
    //     cout<<endl;
    // }
    for(auto c:order){
        cout<<c<<"->";
        for(auto x:grammer[c]){
            cout<<x<<"|";
        }cout<<"\n";
    }
    frst();
    flow();
}