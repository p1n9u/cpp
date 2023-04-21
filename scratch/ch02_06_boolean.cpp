#include <iostream>

using namespace std;

int main(void)
{
    /* Declaration, Assignment */
    {
        bool b0 = 0 == 0;
        bool b1 = 0 < 1;
        bool b2 = 0 > 1;

        cout << "b0(0 == 0) : " << b0 << endl;
        cout << "b1(0 < 1)  : " << b1 << endl;
        cout << "b2(0 > 1)  : " << b2 << endl;

        /* https://en.cppreference.com/w/cpp/header/iostream <ios> class ios_base */
        cout.setf(ios_base::boolalpha);
        cout << "cout.setf(ios_base::boolalpha);" << endl;
        cout << "b0         : " << b0 << endl;
        cout << "b1         : " << b1 << endl;
        cout << "b2         : " << b2 << endl;
    }
    /* relation with integer */
    {
        int itrue = true;
        int ifalse = false;

        cout << itrue << endl;
        cout << ifalse << endl;

        bool btrue = 100;
        bool bfalse = 0;

        cout << btrue << endl;
        cout << bfalse << endl;
    }

    return 0;
}