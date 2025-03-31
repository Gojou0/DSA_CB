#include<bits/stdc++.h>
using namespace std;
void targetSum(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            cout << arr[left] << " and " << arr[right] << endl;
            left++;
            right--;
            while (left < right && arr[left] == arr[left-1]) left++;
            while (left < right && arr[right] == arr[right+1]) right--;
        }
    }
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    sort(arr, arr+n);
	int x;
	cin>>x;
	targetSum(arr,n,x);
	return 0;
}