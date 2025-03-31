#include<iostream>
#include<vector>
using namespace std;

// Badi Problem -> output m saare sorted character ho ..input se fetch krke and input se remove bhi krna h use
// Choti Problem -> ek character ham dal dete h ....baki recursion dal dega 

// Recurrence relation
// BP = CP + ek character ham dal denge ...ese dale ki input ka og order wesa hi rhe remove krne k baad

void PrintSortedPerm(string input, string output){
    // Base case
    if (input.size() == 0){                 // remove krte krte ek time pr input khali ho jaega
        cout << output << endl;
        return;
    }

    // Recursive case
    for (int i = 0; i < input.size(); i++){
        // output = output + input[i];                          // adding in output .....isko recursion k bahar nhi kr skte kyuki recursion as parameter le rha h
        // input = input.substr(0, i) + input.substr(i+1);                 // removing selected element from input
        PrintSortedPerm(input.substr(0, i) + input.substr(i+1), output + input[i]);
    }

}

int main(){
    string arr = "abc";
    sort(arr.begin(), arr.end());
    PrintSortedPerm(arr, "");
    return 0;
}