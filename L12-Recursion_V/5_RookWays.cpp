#include<iostream>
using namespace std;

int Rookways(int i, int j){
    if (i == 0 && j == 0){
        return 1;
    }
    
    int right = 0;
    for (int a = 0; a < j ; a++){
        right += Rookways(i, a);
    }

    int down = 0;
    for (int b = 0; b < i; b++){
        down += Rookways(b, j);
    }

    return right + down;
}

int main(){
    cout << Rookways(3,3) << endl;
}