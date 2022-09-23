#include <iostream>
#include <vector>
using namespace std;
 
int main(void){
	int n;
	cin >> n;
	int arr[5010];
	vector<int> v;
 
	if(n == 1){
        cout << 1;
        return 0;
    }
    
	int first = n/2;
 
	while(1){
		if(v.size() == n){
			break;
		}
		for(int i = first;i<=n;i=i+(n/2)){
			v.push_back(i);
		}
		first--;
 
	}
 
	for(int i = 0;i<v.size();i++){
		cout << v[i] << ' ';
	}
}