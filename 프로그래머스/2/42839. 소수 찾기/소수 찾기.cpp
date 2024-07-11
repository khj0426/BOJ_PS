#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool isPrime(int n){
    if(n == 1){
        return false;
    }
   
    for(int i = 2;i<=sqrt(n);i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    
    
    vector<int> v;
    
    for(int i = 0;i<numbers.size();i++){
        int number = numbers[i] - '0';
        v.push_back(number);
    }
    
    sort(v.begin(),v.begin() + v.size());
    
    do{
        if(v[0] == 0){
            continue;
        }
        string str = "";
        for(int i = 0;i<v.size();i++){
            str = str + to_string(v[i]);
       
            if(isPrime(stoi(str))){
                s.insert(stoi(str));
            }
        }
        
        
    }while(next_permutation(v.begin(),v.end()));
    
    return s.size();
}