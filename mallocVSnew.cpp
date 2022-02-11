//#include <stdio.h>
#include <iostream>
using namespace std;

class test {
public:
    int i;
    test() {
        cout << "Called default constructor!" << endl;
        i = 100;
    }

    ~test() {
        cout << "Destructor called!" << endl; 
    }
};

int main()
{
    int x;
    cin >> x;
    int* ptr;
    ptr = (int *)malloc(x*sizeof(int));
    //ptr = new int[x];
    if(ptr==NULL)
        cout << "Memory is not allocated!";
    else {
        for(int i=0; i<x; i++)
            ptr[i]=i+1;
        for(int i=0; i<x; i++)
            cout << ptr[i] << " ";
    }
    cout << endl;

    int size;
    cin >> size;

  //test *cptr = (test*)malloc(sizeof(test)*size); //malloc return null pointer and only allocats the memory

    test *cptr = new test[size];
   // new allocates the memory as well as calls the default constructor of the class 
    cout << sizeof(int) << endl;
    cout << sizeof(int*) << endl;
    cout << cptr[1].i << endl;
    cout << sizeof(test) << endl;

    //delete[] cptr;
    free(cptr);

    int a = 10;
    float b;
    b = a/3.0;
    cout << b << endl;
    cout << endl;
}