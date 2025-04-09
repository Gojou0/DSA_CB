#include<iostream>
using namespace std;

int Replace(int n){
    if (n <= 0) return 0;

    if (n%10 == 0){
        return 5 + Replace(n/10) * 10;
    }else{
        return n % 10 + Replace(n/10) * 10;
    }

}

int main(){
    int n; 
    cin >> n;

    cout << Replace(n) << endl;
}