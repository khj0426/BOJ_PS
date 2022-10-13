#include <iostream>
using namespace std;
//백준 1991 트리 순회

struct TREE{ //트리를 표현하는 구조체
    char left = '\0';
    char right = '\0';
    char data = '\0';
};
 
typedef struct TREE tree;
 
 
tree arr[27];
 
 
void preorder(tree a){
    // 전위순회(루트 왼쪽 오른쪽)
    if(a.data == '\0' || a.data == '.'){
        return;
    }
    cout << a.data;
    if(a.left != '\0' && a.left != '.'){
        preorder(arr[a.left-'A']);
    }
    if(a.right != '\0' && a.right != '.'){
        preorder(arr[a.right-'A']);
    }
}
 
void order(tree a){ 
    // 중위순회(왼쪽 루트 오른쪽)
 
 
 
    if(a.left != '\0' && a.left != '.'){
        order(arr[a.left-'A']);
    }
     if(a.data == '\0' || a.data == '.'){
        return;
    }
    if(a.data != '\0' && a.data != '.'){
        cout << a.data;
    }
 
    if(a.right != '\0' && a.right != '.'){
        order(arr[a.right-'A']);
    }
}
 
void lastorder(tree a){ 
    //후위순회(왼쪽 오른쪽 루트)
 
    if(a.left != '\0' && a.left != '.'){
        lastorder(arr[a.left-'A']);
    }
    if(a.right != '\0' && a.right != '.'){
        lastorder(arr[a.right-'A']);
    }
    if(a.data != '\0' && a.data != '.'){
        cout << a.data;
    }
}
 
int main(void){
 
 
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        char a,b,c;
        cin >> a >> b >> c;
        arr[a-'A'].data = a;
        arr[a-'A'].left = b;
        arr[a-'A'].right = c;
    }
    preorder(arr['A'-'A']);
    cout << '\n';
    order(arr['A'-'A']);
    cout << '\n';
    lastorder(arr['A'-'A']);
 
 
}