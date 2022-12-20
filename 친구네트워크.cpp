#include <map>
#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
 
int t;
vector<pair<string,string>> allRelations;
map<string,string> Parent;
map<string,int> Sizes;
set<string> allNames;
 
void InputCase(){
    cin >> t;
}
 
void InputRelations(){
    int n;
    cin >> n;
    Sizes.clear();    
    Parent.clear();
    allNames.clear();
    allNames.clear();
    allRelations.clear();
 
    for(int i = 0;i<n;i++){
        string first,second;
        cin >> first >> second;
        if(allNames.count(first) == 0){
            allNames.insert(first);
            Sizes.insert({first,1});
            Parent[first] = first;
        }       
        if(allNames.count(second) == 0){
            allNames.insert(second);
            Sizes.insert({second,1});
            Parent[second] = second;
        }
        allRelations.push_back({first,second});
    }
}
string getParent(string a){
    if(Parent[a] == a){
        return a;
    }
    else{
        Parent[a] = getParent(Parent[a]);
        return Parent[a];
    }
}
 
int setSizes(string a,string b){
 
    string A = getParent(a);
    string B = getParent(b);
    if(A<B){
        Sizes[A] += Sizes[B];
        Parent[B] = A;
        Sizes[B] = Sizes[A];
        return Sizes[A];
    }
    else if(A == B){
        return Sizes[A];
    }
    else if(A>B){
        Sizes[B] += Sizes[A];
        Parent[A] = B;
        Sizes[A] = Sizes[B];
        return Sizes[B];
    }
}
 
void setParents(){
    for(int i = 0;i<allRelations.size();i++){
        string first = allRelations[i].first;
        string second = allRelations[i].second;
        cout << setSizes(first,second) << '\n';
    }
}
 
int main(void){
    InputCase();
    while(t--){
        InputRelations();
        setParents();
    }
}