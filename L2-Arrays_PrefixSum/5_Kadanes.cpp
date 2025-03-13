#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int a[] = {1,2,-3,-4,-5};
    int n = sizeof(a)/sizeof(int);
    int ans = INT_MIN;

    bool isPositivePresent = false;
    for (int i = 0; i < n; i++){
        if(a[i] > 0) {
            isPositivePresent = true;
        }
        ans = max(ans,a[i]);
    }

    if (isPositivePresent == true){
        //Max Sum Algo
        for(int i = 0; i < n; i++){
            sum += a[i]; //ELements ko add krte jao
            if (sum < 0) sum = 0; //agr -ve aaye toh zero krdo
            ans = max(ans, sum); // ans ke andar max lete jao
        }
    }
    cout << "Sum :" << ans << endl;

    return 0;
}