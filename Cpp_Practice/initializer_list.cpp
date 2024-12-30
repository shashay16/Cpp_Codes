#include<iostream>

// 1. Initializating non-static const data members
// 2. Initialization of reference data members
// 3. Initialization of member objects that do not have a default constructor
// 4. Initialization of Base Class Members
// 5. When the Constructor’s Parameter Name is the Same as Data Member
// Parameter Init() vs Uniform Init{}

class Base
{
    public:
        virtual void fun1()
        { std::cout << "Base Fun1" << std::endl;}
        void fun2()
        {
            
        }
};


int main()
{
    

    return 0;
}