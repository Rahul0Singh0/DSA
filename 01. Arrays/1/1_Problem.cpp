/**
 * Given an array of marks of students, if the marks of any student is less than 
 * 35 print its roll number.
 */

#include <bits/stdc++.h>
using namespace std;

struct Student {
    int marks;
    int rollno;
};

int main() {
    int n;
    cin>>n;
    Student *s = new Student[n];
    for(int i = 0; i < n; i++) {
        cout<<"Enter mark of student rollno with "<<i+1<<" : ";
        cin>>s[i].marks;
        s[i].rollno = i+1;
    }
    for(int i = 0; i < n; i++) {
        if(s[i].marks < 35) cout<<"Roll no "<<s[i].rollno<<" with mark "<<s[i].marks<<endl;
    }

    return 0;
}