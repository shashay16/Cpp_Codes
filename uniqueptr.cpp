#include <iostream>

using namespace std;

template <typename T>
class uniqueptr {
    private:
        T* res;
    public:
        uniqueptr(T* value = nulllptr) : res(value)

        uniqueptr(const T* &value) = delete
        

};