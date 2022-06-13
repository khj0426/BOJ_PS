#include <iostream>
using namespace std;

//¹éÁØ 21758 ²Üµû±â

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
int arr[100001];
int sum[100001];
int main(void) {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];

    }

    int left = 0;
    int right = n - 1;

    int max_sum = 0;
    for (int i = 1; i < n - 1; i++) {
        int l = sum[n - 1] - arr[left] - (sum[n - 1] - sum[i]);
        int r = sum[n - 1] - arr[right] - sum[i] + arr[i];
        max_sum = max(max_sum, l + r);

    }


    for (int i = 1; i < n; i++) {
        int l = sum[n - 1] - arr[0] - arr[i];
        int r = sum[n - 1] - sum[i];
        max_sum = max(max_sum, l + r);

    }

    for (int i = 1; i < n - 1; i++) {
        int r = sum[n - 1] - arr[n - 1] - arr[i];
        int l = sum[i] - arr[i];
        max_sum = max(max_sum, l + r);
    }
    cout << max_sum << '\n';

}