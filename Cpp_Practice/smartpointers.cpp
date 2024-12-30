#include <iostream>
#include <memory>

using namespace std;


class MyClass {
public:
    MyClass() {
        cout << "CTR" << endl;
    }

    ~MyClass() {
        cout << "DTR" << endl;
    }
};


int main()
{
    unique_ptr<MyClass> ptr = make_unique<MyClass>();
    shared_ptr<MyClass> ptr1 = make_shared<MyClass>();
    shared_ptr<MyClass> ptr2 = ptr1;
    weak_ptr<MyClass> wPtr = ptr1;
    cout << wPtr.use_count() << endl;
    if(auto shared = wPtr.lock()) {
        cout << "Still used" << endl;
    }
    MyClass* ptr3 = new MyClass();
    delete ptr3;
    return 0;
}