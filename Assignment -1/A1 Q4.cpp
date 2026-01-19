#include <iostream>
#include <climits>
using namespace std;
int maxCrossingSum(int arr[], int l, int m, int h){
    int sum=0;
    int left_sum=INT_MIN;
    for (int i=m; i>=l; i--) {
        sum= sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum=0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum=sum+arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}
int maxSubArraySum(int arr[], int l, int h){
    if (l == h)
        return arr[l];
    int m=(l + h)/2;
    int leftMax = maxSubArraySum(arr, l, m);
    int rightMax = maxSubArraySum(arr, m + 1, h);
    int crossMax = maxCrossingSum(arr, l, m, h);
    if(leftMax >= rightMax && leftMax >= crossMax) return leftMax;
    else if(rightMax >= leftMax && rightMax >= crossMax) return rightMax;
    else return crossMax;
}
int main(){
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
