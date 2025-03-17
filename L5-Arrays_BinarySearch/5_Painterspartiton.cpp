#include <iostream>
using namespace std;

int painters, boards;
int lengths[100005];

bool kyapainthopaya(int d){
    int painter = 1;
    int timetaken = 0;
    for (int i = 0; i < boards; i++){
        if (timetaken + lengths[i] <= d){
            timetaken += lengths[i];
        }else{
            painter++;
            timetaken = lengths[i];
        }
    }
    if (painter <= painters) return true;
    else return false;
}

int main(){
    cin >> painters >> boards;
    for (int i = 0; i < boards; i++){
        cin >> lengths[i];
    }

    // define search space
    int s = 0;
    int e = 1e9;
    for (int i = 0; i < boards; i++){
        s = max(s, lengths[i]);
        e += lengths[i];
    }
    
    int ans = 0;
    while (s <= e){
        int mid = s + (e - s) / 2;
        if (kyapainthopaya(mid)){
            ans = mid;
            e = mid - 1;
        }else {
            s = mid + 1;
        }
    }

    cout << ans << endl;
}