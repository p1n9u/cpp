#include <iostream>

/* Defines the class template numeric_limits and two enumerations concerning floating-point representations and rounding. */
#include <limits>

using namespace std;

int main(void)
{
    /* Declaration, Assignment */

    int x;
    x = 0;
    cout << x << endl;

    /* C Style */
    int y = 1;
    cout << y  << endl;

    /* C++ Style */
    int z(2);
    cout << z << endl;

    /* Integer Literal */

    int num0 = 11;
    int num1 = 0b11;
    int num2 = 011;
    int num3 = 0x11;
    cout << "num0 " << num0 << endl;
    cout << "num1 " << num1 << endl; 
    cout << "num2 " << num2 << endl;
    cout << "num3 " << num3 << endl;

    /* sizeof operator */

    int intNum = 0;
    long longNum = 0;
    int *intPointer = &intNum;
    cout << "sizeof(int) " << sizeof(intNum) << endl;
    cout << "sizeof(long) " << sizeof(longNum) << endl;
    cout << "sizeof(int *) " << sizeof(intPointer) << endl;

    int8_t num00 = 0;
    int16_t num11 = 0;
    int32_t num22 = 0;
    cout << "sizeof(int8_t) " << sizeof(num00) << endl;
    cout << "sizeof(int16_t) " << sizeof(num11) << endl;
    cout << "sizeof(int32_t) " << sizeof(num22) << endl;

    /* https://en.cppreference.com/w/cpp/types/numeric_limits */

    cout << "numeric_limits<uint> 8 16 32 64, max()" << endl;
    cout << (int)numeric_limits<uint8_t>::max() << endl;
    cout << numeric_limits<uint16_t>::max() << endl;
    cout << numeric_limits<uint32_t>::max() << endl;
    cout << numeric_limits<uint64_t>::max() << endl;

    cout << "numeric_limits<int> 8 16 32 64, max()" << endl;
    cout << (int)numeric_limits<int8_t>::max() << endl;
    cout << numeric_limits<int16_t>::max() << endl;
    cout << numeric_limits<int32_t>::max() << endl;
    cout << numeric_limits<int64_t>::max() << endl;

    cout << "numeric_limits<int> 8 16 32 64, min()" << endl;
    cout << (int)numeric_limits<int8_t>::min() << endl;
    cout << numeric_limits<int16_t>::min() << endl;
    cout << numeric_limits<int32_t>::min() << endl;
    cout << numeric_limits<int64_t>::min() << endl;

    return 0;
}
