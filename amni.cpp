#include <bits/stdc++.h>
using namespace std;

map<char,string>rule;
string left;

void ans(){
    ifstream in("amni.txt");
    string line;
    while(getline(in,line)){
        left.push_back(line[0]);
        rule[line[0]]=line.substr(3,line.size());
    }
}

int main(){

}