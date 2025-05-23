#include<iostream>
#include<vector>
using namespace std;

class Minheap{
    vector<int> Cbt;
    void heapify(int i){
        int left = 2*i;
        int right = left + 1;
        int mini = i;
        if (left < Cbt.size() && Cbt[left] < Cbt[mini]){
            mini = left;
        }
        if (right < Cbt.size() && Cbt[right] < Cbt[mini]){
            mini = right;
        }

        if (mini != i){
            swap(Cbt[mini], Cbt[i]);
            heapify(mini);
        }
    }
    public:
    Minheap(){
        Cbt.push_back(-1);
    }
    
    void push(int d){
        Cbt.push_back(d);
        int c = Cbt.size() - 1;
        int p = c / 2;
        while (p > 0 && Cbt[p] > Cbt[c]){
            swap(Cbt[p], Cbt[c]);
            c = p;
            p /= 2;
        }
    }

    void pop(){
        swap(Cbt[1], Cbt[Cbt.size() - 1]);
        Cbt.pop_back();

        heapify(1);
    }

    int find(){
        return Cbt[1];
    }

    bool empty(){
        return Cbt.size() == 1;
    }
};

int main(){
    Minheap heap;

    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(0);

    heap.pop();

    cout << heap.find() << endl;
}