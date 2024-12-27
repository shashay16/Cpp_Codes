#include <iostream>

using namespace std;

class Base {
    private:
        int val;
    public:
        Base() {
            cout << "Ctr called" << endl;
        }

        ~Base() {
            cout <<"Dtr called" << endl;
        }
};

int main()
{
    Base* bp = new Base();
    delete bp;

    // placement new
    char* memory = new char[(10*sizeof(Base))];
    Base* bp1 = new (&memory[0]) Base();
    Base* bp2 = new (&memory[1]) Base();
    Base* bp3 = new (&memory[2]) Base();

    bp1->~Base();
    bp2->~Base();
    bp3->~Base();

    delete[] memory;

    return 0;
}