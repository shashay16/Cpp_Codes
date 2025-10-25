#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
public:
    shared_ptr<B> ptr;

    void set_ptr(shared_ptr<B>& p) {
        ptr = p;
    }

    ~A() {
        cout << "DTR A" << endl;
    }
};

class B
{
public:
    weak_ptr<A> ptr;

    void set_ptr(shared_ptr<A>& p) {
        ptr = p;
    }

    ~B() {
        cout << "DTR B" << endl;
    }
};

void func() {
    shared_ptr<A> objA = make_shared<A>();
    shared_ptr<B> objB = make_shared<B>();

    objA->set_ptr(objB);
    objB->set_ptr(objA);

    cout << objA.use_count() << " " << objB.use_count() << endl;

}

int main() {
    func();
    // destructors are not called because of cyclic reference

    // To fix this, we can use weak_ptr
    return 0;
}