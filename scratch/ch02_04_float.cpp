#include <iostream>

/* Includes the Standard C library header. */
#include <cmath>
#include <cfloat>
#include <cstring>

using namespace std;

/* https://codetorial.net/articles/floating_point.html */
int main(void)
{
    /* Declaration, Assignment */
    {
        
        float num0 = 1.5;
        float num1 = num0 * 1.5;
        float num2 = num0 / 2;
        float num3 = num0 - 3;

        cout << "num0 " << num0 << endl;
        cout << "num1 " << num1 << endl;
        cout << "num2 " << num2 << endl;
        cout << "num3 " << num3 << endl;
    }
    /* sizeof operator */
    {
        
        float fnum = 1.0f;
        double dnum = 1.0;
        long double ldnum = 1.0L;

        cout << "sizeof(float) " << sizeof(fnum) << endl; 
        cout << "sizeof(double) " << sizeof(dnum) << endl;
        cout << "sizeof(long double) " << sizeof(ldnum) << endl; 
    }
    /* https://en.cppreference.com/w/cpp/header/iostream <ios> class ios_base */
    cout.precision(64);
    {
        /* 
         * float : sign 1bit, exponent 8bits, mantissa 23bits
         * double : sign 1bit, exponent 11bits, mantissa 52bits
         * long double : sign 1bit, exponent 15bits, mantissa 112bits
         */
        unsigned int uintNum;
        float fnum = -118.625f;
        memcpy(&uintNum, &fnum, sizeof(fnum));

        /* 
         * decimal -118.625 -> binary -1110110.101
         * nomalization : binary -1.110110101 * 2^6
         * sign 1bit : binary 1
         * exponent 8bits : 2^6
         ** decimal 127 set to 0 for negative : decimal 133 is 6 -> binary 1000 0101
         * mantissa 23bits : binary 1101 1010 1
         * result 1 1000 0101 1101 1010 1 000 ... 0000
         * 3270328320
         * -118.625
         */
        cout << "1100,0010,1110,1101,0100,0000,0000,0000 :" << endl;
        cout << "   unsinged int : " << uintNum << endl;
        cout << "   float : " << fnum << endl;
    }
    {
        cout << "num0(0.1f), num1(0.02f * 5.0f)" << endl;
        float num0 = 0.1f;
        float num1 = 0.02f * 5.0f;

        cout << "   num0 : " << num0 << endl; 
        cout << "   num1 : " << num1 << endl; 
        cout << "   0.1f : " << 0.1f << endl;
        cout << "   0.1  : " << 0.1 << endl;
        cout << "   0.1L : " << 0.1L << endl;

        num0 = 1.0f;
        num1 = 0.0f;
        cout << "num0(1.0f), num1 : for (i=0;i<1000;i++) num1 += 0.001f -> 1.0 + err" << endl;
        for (int i = 0; i < 1000; i++)
            num1 = num1 + 0.001f;
        
        cout << "   num0 == num1 : ";
        if (num0 == num1)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "   fabsf(num0-num1) <= FLT_EPSILON : ";   
        if (fabsf(num0 - num1) <= FLT_EPSILON)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    /* Derivation FLT_EPSILON */
    {
        cout << "Derivation FLT_EPSILON" << endl;
        /*
         * 0 01111111 00000000000000000000000
         * sign 1bits : 0
         * exponent 8bits : 01111111 (2^0)
         * mantissa 23bits : 00000000000000000000000
         * Value actually stored in float : 1
        */
        unsigned int intNum0 = 0b00111111100000000000000000000000;
        float fNum0;
        memcpy(&fNum0, &intNum0, sizeof(intNum0));
        cout << "   fNum0   [0b00111111100000000000000000000000] : " << fNum0 << endl;

        /*
         * ADD mantissa 1bit
         * 0 01111111 00000000000000000000000
         * sign 1bits : 0
         * exponent 8bits : 01111111 (2^0)
         * mantissa 23bits : 00000000000000000000001
         * Decimal representation : 1.00000011920928955078125
        */
        unsigned int intNum1 = 0b00111111100000000000000000000001;
        float fNum1;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));
        cout << "   fNum1   [0b00111111100000000000000000000001] : " << fNum1 << endl;
        
        float epsilon = fNum1 - fNum0;
        cout << "   epsilon = fNum1 - fNum0 : " << epsilon << endl;
        cout << "   FLT_EPSILON             : " << FLT_EPSILON << endl;

        cout << "   epsilon == FLT_EPSILON  : ";
        if (epsilon == FLT_EPSILON)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    {
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110100000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));

        cout << "mantissa is 23bits, float can detect to 2^-23." << endl;
        cout << "   127 - 23 = 104 : 0110 1000" << endl;
        cout << "   Epsilon : 1.0 * 2^-23   [0b0 0110 1000 00000000000000000000000]" << endl;
        cout << "   1.0f               : " << fNum0 << endl;
        cout << "   1.0 * 2^-23        : " << fNum1 << endl;
        cout << "   1.0f + 1.0 * 2^-23 : " << fNum0 + fNum1 << endl;
    }
    {
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));

        cout << "CASE 2^-24 :" << endl;
        cout << "   127 + 23 = 104 : 0110 0111" << endl;
        cout << "   1.0 * 2^-24 [0b0 0110 0111 00000000000000000000000]" << endl;
        cout << "   1.0f               : " << fNum0 << endl;
        cout << "   1.0 * 2^-24        : " << fNum1 << endl;
        cout << "   1.0f + 1.0 * 2^-24 : " << fNum0 + fNum1 << endl;
    }
    {
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));

        cout << "CASE 2^23 :" << endl;
        cout << "   127 + 23 = 150 : 1001 0110" << endl;
        cout << "   1.0 * 2^23  [0b0 1001 0110 00000000000000000000000]" << endl;
        cout << "   1.0f              : " << fNum0 << endl;
        cout << "   1.0 * 2^23        : " << fNum1 << endl;
        cout << "   1.0f + 1.0 * 2^23 : " << fNum0 + fNum1 << endl;
    }
    {
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));

        cout << "CASE 2^24 :" << endl;
        cout << "   127 + 25 = 104 : 1001 0111" << endl;
        cout << "   1.0 * 2^24  [0b0 1001 0111 00000000000000000000000]" << endl;
        cout << "   1.0f              : " << fNum0 << endl;
        cout << "   1.0 * 2^24        : " << fNum1 << endl;
        cout << "   1.0f + 1.0 * 2^24 : " << fNum0 + fNum1 << endl;
    }
    {
        /* 
         * https://en.wikipedia.org/wiki/Exponent_bias
         * 1(127-126) ~ 254(127+127) (0 and 255 have special meanings)
         * 2^-126 ~ 2^127
         * decimal 127 is binary 1111 1110
         */
        float fnum;
        unsigned int uintNum = 0b01111111011111111111111111111111;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << fnum << endl;

        cout << "FLT_MAX : " << FLT_MAX << endl;
        cout << "       [0b0 1111 1110 1111 1111 1111 1111 1111 111] : " << fnum << endl;

        cout << "   FLT_MAX ==  [0b0 1111 1110 1111 1111 1111 1111 1111 111] : ";
        if (FLT_MAX == fnum)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    {
        cout << "SPECIAL BITS CHECK" << endl;
        float fNum0, fNum1, fNum2, fNum3, fNum4, fNum5, fNum6, fNum7;
        unsigned int uintNum0 = 0b01111111111111111111111111111111;
        unsigned int uintNum1 = 0b00000000011111111111111111111111;
        unsigned int uintNum2 = 0b00000000000000000000000000000000;
        unsigned int uintNum3 = 0b01111111100000000000000000000000;
        unsigned int uintNum4 = 0b11111111111111111111111111111111;
        unsigned int uintNum5 = 0b10000000011111111111111111111111;
        unsigned int uintNum6 = 0b10000000000000000000000000000000;
        unsigned int uintNum7 = 0b11111111100000000000000000000000;
        memcpy(&fNum0, &uintNum0, sizeof(uintNum0));
        memcpy(&fNum1, &uintNum1, sizeof(uintNum1));
        memcpy(&fNum2, &uintNum2, sizeof(uintNum2));
        memcpy(&fNum3, &uintNum3, sizeof(uintNum3));
        memcpy(&fNum4, &uintNum4, sizeof(uintNum4));
        memcpy(&fNum5, &uintNum5, sizeof(uintNum5));
        memcpy(&fNum6, &uintNum6, sizeof(uintNum6));
        memcpy(&fNum7, &uintNum7, sizeof(uintNum7));

        cout << "   [0b0 1111 1111 11111111111111111111111] : " << fNum0 << endl;
        cout << "   [0b0 0000 0000 11111111111111111111111] : " << fNum1 << endl;
        cout << "   [0b0 0000 0000 00000000000000000000000] : " << fNum2 << endl;
        cout << "   [0b0 1111 1111 00000000000000000000000] : " << fNum3 << endl;
        cout << "   [0b1 1111 1111 11111111111111111111111] : " << fNum4 << endl;
        cout << "   [0b1 0000 0000 11111111111111111111111] : " << fNum5 << endl;
        cout << "   [0b1 0000 0000 00000000000000000000000] : " << fNum6 << endl;
        cout << "   [0b1 1111 1111 00000000000000000000000] : " << fNum7 << endl;
    }
    {
        float fnum;
        unsigned int uintNum = 0b00000000000000000000000000000001;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << "FLT_TRUE_MIN - min positive value          : " << FLT_TRUE_MIN << endl;
        cout << "   [0b0 0000 0000 00000000000000000000001] : " << fnum << endl;
        cout << "   2^-126(exception) * 2^-23" << endl;
    }
    {
        float fnum;
        unsigned int uintNum = 0b00000000100000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << "FLT_MIN - min normalized positive value    : " << FLT_MIN << endl;
        cout << "   [0b0 0000 0001 00000000000000000000000] : " << fnum << endl;
        cout << "   2^-126" << endl;
    }
    {
        float fnum;
        unsigned int uintNum = 0b00111111110000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << "[0b0 0111 1111 10000000000000000000000] : " << fnum << endl;
    }

    return 0;
}