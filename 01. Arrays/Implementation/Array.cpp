#include <bits/stdc++.h>
using namespace std;
// We create own custom vector
template <typename T>

class Array {
    T *arr;
    int Size;
    int Capacity;
public:
    Array() {
        Size = 0;
        Capacity = 0;
        arr = new T[Size];
    }
    Array(int n) {
        Size = n;
        Capacity = n;
        arr = new T[Size];
    }
    ~Array() {
        delete[] arr;
    }
    void push_back(T value) {
        if(Size == 0 && Capacity == 0) {
            arr[Size++] = value;
            Capacity = Size;
            return;
        } else if(Size == Capacity) {
            T* temp = new T[2 * Capacity];
            for(int i = 0; i < Capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            Capacity *= 2;
            arr = temp;
        }
        arr[Size++] = value;
    }
    int size() {
        return Size;
    }
    int capacity() {
        return Capacity;
    }
    void pop_back() {
        arr[Size--] = 0;
    }
    // Read only
    const T& operator[](int index) {
        return arr[index];
    }
    void resize(int n, T val = 0 or nullptr) {
        T *temp = new T[n];
        for(int i = 0; i < Size; i++) {
            temp[i] = arr[i];
        }
        for(int i = Size; i < n; i++) {
            temp[i] = val;
        }
        delete[] arr;
        arr = temp;
        Size = n;
        Capacity = n;
    }
    bool empty() {
        if(Size == 0) return true;
        else false;
    }

    T front() {
        return arr[0];
    }

    T back() {
        return arr[Size-1];
    }

    T at(int idx) {
        return arr[idx];
    }

};

int main() {
    Array<int> arr;
    cout << arr.size() << " " << arr.capacity()<<endl;
    arr.push_back(2);
    cout << arr.size() << " " << arr.capacity()<<endl;
    arr.push_back(3);
    cout << arr.size() << " " << arr.capacity()<<endl;
    arr.push_back(4);
    cout << arr.size() << " " << arr.capacity()<<endl;
    arr.push_back(5);
    cout << arr.size() << " " << arr.capacity()<<endl;
    arr.push_back(6);
    cout << arr.size() << " " << arr.capacity()<<endl;
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    arr.pop_back();
    arr.resize(10, 100);
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Array<char> ch;
    ch.resize(5, 'a');
    for(int i = 0; i < ch.size(); i++) {
        cout<<ch[i]<<endl;
    }
    cout<<arr.front();
}