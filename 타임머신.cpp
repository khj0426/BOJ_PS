#include <iostream>
#include <algorithm>
#include <vector>
#define MAXVALUE 1e8

using namespace std;

int n, m;

struct Node {
    int From;
    int To;
    int cost;
};

typedef struct Node N;

bool HasCycle = false;
vector<N> E;
long long arr[501];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        arr[i] = MAXVALUE;
    }
}

void Solve(int Start) {
    arr[Start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < E.size(); j++) {
            int Cur = E[j].From;
            int Next = E[j].To;
            int Cost = E[j].cost;

            if (arr[Next] > arr[Cur] + Cost && arr[Cur] != MAXVALUE) {
                arr[Next] = arr[Cur] + Cost;
            }
        }
    }

    for(int j = 0; j < E.size(); j++){
        int Cur = E[j].From;
        int Next = E[j].To;
        int Cost = E[j].cost;

        if(arr[Next] > arr[Cur] + Cost && arr[Cur] != MAXVALUE){
            cout << -1;
            HasCycle = true;
            break;
        }
    }

}

int main(void) {
    cin >> n >> m;
    init(n);

    for (int i = 0; i < m; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        E.push_back({ A-1, B-1, C });
    }

    Solve(0);

    if(HasCycle == false){
        for(int i = 1; i < n; i++){
            if(arr[i] == MAXVALUE){
                cout << -1 << '\n';
            }
            else{
                cout << arr[i] << '\n';
            }
        }
    }

}