#include <iostream>
using namespace std;

int painters, boards;
int lengths[100005];

int main(){
    cin >> painters >> boards;
    for (int i = 0; i < boards; i++){
        cin >> legths[i];
    }

    // define search space
    int s = 0;
    int e = 0;
    for (int i = 0; i < boards; i++){
        s = max(s, lengths[i]);
        e += lengths[i];
    }
    
    while (s <= e){
        int mid = (s + (e - s)) / 2;
    }
}