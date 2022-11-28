#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parents[100001];
vector<pair<int,int>> graph[100001];
int getParent(int x){
    if(parents[x] == x){
        return x;
    }
    else{
        parents[x] = getParent(parents[x]);
        return parents[x];
    }
}

void merge(int a,int b){
    int parentA = getParent(a);
    int parentB = getParent(b);
    if(parentA < parentB){
        parents[parentB] = parentA;
    }
    else if(parentA > parentB){
        parents[parentA] = parentB;
    }
}

int hasCycle(int a,int b){
    if(getParent(a) == getParent(b)){
        return true;
    }
    return false;
}
