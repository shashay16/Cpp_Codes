#include <iostream>
#include <memory>

using namespace std;

//RAII - Resource Acquisition Is Initialization
class Wrapper {
    private: 
        int* res;
    public:
        Wrapper(int* value = nullptr) : res(value) {
            cout << "Wrapper acquired resource." << endl;
        }

        ~Wrapper() {
            delete res;
            cout << "Wrapper released resource." << endl;
        }
};


template <typename T>
class uniqueptr {
    private:
        T* res;
    public:
        uniqueptr(T* value = nullptr) : res(value) {

        }
        uniqueptr(const uniqueptr&) = delete; // Disable copy constructor
        uniqueptr& operator=(const uniqueptr&) = delete; // Disable copy assignment
        uniqueptr(uniqueptr&& other) {
            res = other.res;
            other.res = nullptr;
        }

        uniqueptr& operator=(uniqueptr&& other) {
            if(this != &other) {
                if(res) {
                    delete res;
                }
                res = other.res;
                other.res = nullptr;
            }
            return *this;
        }

        ~uniqueptr() {
            if(res) {
                delete res;
                res = nullptr;
            }
        }

        void reset(T* value = nullptr) {
            if(res) {
                delete res;
            }
            res = value;
        }

        T* get() const {
            return res;
        }

        T& operator*() const {
            return *res;
        }
        T* operator->() const {
            return res;
        }
};

int main()
{
    Wrapper w(new int(5));

    unique_ptr<int> p1 = make_unique<int>(10);
    unique_ptr<int> p2 = std::move(p1);
    //cout << *p1 << " " << p1 << endl;
    cout << *p2 << " " << p2 << endl;
    uniqueptr<int> up1(new int(20));
    cout << *up1 << " " << up1.get() << endl;

    return 0;
}