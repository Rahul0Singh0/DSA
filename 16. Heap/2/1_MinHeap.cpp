#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class MinHeap {
private:
    int arr[50]; 
    int idx;
public:
    int size;
    MinHeap() {
        idx = 1;
        size = 0;
    }
    int top() {
        return arr[1];
    }
    void push(int x) {
        arr[idx] = x;
        int i = idx;
        idx++;
        // swapping of i with parent(i/2) till i == 1
        while(i > 1) {
            int parent = i/2;
            if(arr[i] < arr[parent]) 
               std::swap(arr[i], arr[parent]);
            else break;
            i = parent;
        }
        size = idx-1;    
    }
    void pop() {
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while(true) {
            int left = 2*i, right = 2*i+1;
            if(left > idx-1) break;
            if(right > idx-1) {
                if(arr[i] > arr[left]) {
                    std::swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
            if(arr[left] < arr[right]) {
                if(arr[i] > arr[left]) {
                    std::swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
            else {
                if(arr[i] > arr[right]) {
                    std::swap(arr[i], arr[right]);
                    i = right;
                }
                else break;
            }
        }
    }
    // int size() {
    //     return idx-1;
    // }
    void display() {
        for(int i = 1; i <= idx-1; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void Insert(int val) {
        int i = idx;
        while(i > 1 && val < arr[i/2]) {
            arr[i] = arr[i/2];
            i /= 2;
        }
        arr[i] = val;
        idx++;
        size = idx-1;
    }

    void Delete() {
        if(idx == 1) {
            idx = 1;
            size = idx-1;
            arr[1] = INT_MIN;
            return;
        }
        arr[1] = arr[idx];
        int i = 1;
        int j = 2*i;
        while(j <= idx-1) {
            if(j < idx-1 && arr[j+1] < arr[j]) j = j+1;  // right child is smaller than left
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                i = j;
                j = 2*i;
            }
            else break;
        }
        idx--;
        size = idx-1;
    }
};
int main() {
    MinHeap m;
    m.Insert(20);
    m.Insert(50);
    m.Insert(10);
    m.display();
    cout<<m.size<<endl;
    m.Insert(60);
    m.Insert(5);
    m.display();
    cout<<m.size<<endl;
    m.Delete();
    m.display();
    cout<<m.size<<endl;
    m.Insert(60);
    m.Insert(18);
    m.Insert(2);
    m.Insert(6);
    m.display();
    m.Delete();
    m.display();
    m.Delete();
    m.display();
}