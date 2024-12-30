#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
public:
    shared_ptr<B> ptr;
    ~A() {
        cout << "DTR" << endl;
    }
};

class B
{
public:
    weak_ptr<A> ptr;
    ~B() {
        cout << "DTR" << endl;
    }
};

int main() {
    {
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        a->ptr = b;
        b->ptr = a;
        cout << "a count: " << a.use_count() << endl;
        cout << "b count: " << b.use_count() << endl;
    }
    cout << "No DTR" << endl;
    return 0;
}