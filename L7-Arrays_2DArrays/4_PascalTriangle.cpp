#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int> > answer;
    for (int i = 1; i <= 10; i++){
        vector<int> temp;
        int ans = 1;
        temp.push_back(ans);
        for (int j = 1; j < i; j++){
            ans *= (i - j);
            ans /= j;
            temp.push_back(ans);
        }
        answer.push_back(temp);
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j <= i; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}