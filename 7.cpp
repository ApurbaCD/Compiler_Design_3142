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
    int i;
    set<string>all_keyword={"if","else","switch","case","default","for","while","do","break","continue","goto","return","int","float","double",
    "char","bool","void","wchar_t","short","long","signed","unsigned","const","volatile","mutable class","struct","union","enum","private","protected", 
    "public","tatic_cast","dynamic_cast","const_cast","reinterpret_cast","new","delete","namespace","using","inline","operator","this","template","typename",
    "decltype","constexpr", "inline","virtual","explicit","constexpr","consteval","static","extern","mutable","register","thread_local","true","false","asm",
    "sizeof","typedef","typeid","decltype","alignas","alignof","nullptr","concept","requires","co_await","co_return","co_yield","constexpr","static_assert",
    "if","constexpr","constexpr","decltype","noexcept","nullptr","static_assert","thread_local","string","int","floot","double"};

    set<string>::iterator it,it1;
    set<string>all_operator={"+","-","*","/","=","==","!=","&","&&","||","^","%","<<",">>","+=","-=","/=","*=","++","--"};

    ifstream in("file_for_7_problem.txt");
    if(!in.is_open()){
        cout<<"problem in opening txt file.";
    }
    string line;
    while(getline(in,line)){
        cout<<line<<endl;
        istringstream iss(line); // Convert the line into a stream // space differ two word, so it is important
        string word;
        while (iss >> word) {
            // Process each word (here we simply print it)
            //cout << word <<endl;
            //keyword
            it=all_keyword.find(word);
            if(it!=all_keyword.end()){
                cout<<word<<" is a keyword.\n";
                //return;
                continue;
            }
            //operator
            it1=all_operator.find(word);
            if(it1!=all_operator.end()){
                cout<<word<<" is a Operator.\n";
                //return;
                continue;
            }

            //Identifier
            if(word[0]=='_'||(word[0]>='a'&&word[0]<='z')||(word[0]>='A'&&word[0]<='Z')){
                bool b=1;
                for(int i=0;i<word.size();i++){
                    if(word[i]=='_'||(word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z')||(word[i]>='1'&&word[i]<='10')){
                        continue;
                    }
                    else{
                        b=0;
                    }
                }
                if(b){
                    cout<<word<<" is a identifier.\n";
                    //return;
                    continue;
                }
            }

            //constans
            // string constant a space not allowed
            if(word[0]=='"'&&word[word.size()-1]=='"'){
                cout<<word<<" is a constant\n";
                //return;
                continue;
            }
            bool b1 = 1;
            for(int i=0;i<word.size();i++){
                if(!isdigit(word[i])){
                    b1=0;
                }
            }
            if(b1){
                cout<<word<<" is a constant.\n";
                //return;
                continue;
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