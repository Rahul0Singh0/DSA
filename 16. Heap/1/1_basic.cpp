#include<queue>
#include<iostream>
using namespace std;
int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(-1);
    pq.push(8);
    cout<<pq.top();
}