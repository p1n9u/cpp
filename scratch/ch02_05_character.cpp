#include <iostream>

using namespace std;

int main(void)
{
    {
        /* string */
        cout << "Hello World" << endl;
    }
    {
        /* char */
        cout << 'h' << endl;
    }
    {
        /* relation with integer */
        char ch = 'a';
        cout << ch << endl;

        char ch0 = 'a';
        char ch1 = 97;

        cout << "ch0 : " << ch0 << endl;
        cout << "ch1 : " << ch1 << endl;

        cout << "ch0 : " << (int)ch0 << endl;
        cout << "ch1 : " << int(ch1) << endl;

        cout << (char)97 << endl;
        cout << 97 << endl;
    }
    /* sizeof operator */
    {
        cout << "sizeof(char) : " << sizeof(char) << endl;
    }
    /* Escape Sequence */
    {
        
        cout << "New Line" << endl;
        cout << "Hello World";
        cout << '\n';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Tab" << endl;
        cout << "Hello World";
        cout << '\t';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Backspace" << endl;
        cout << "Hello World";
        cout << '\b';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Audio" << endl;
        cout << "Hello World";
        cout << '\a';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Single Quotation Mark" << endl;
        cout << "Hello World";
        cout << '\'';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Double Quotation Mark" << endl;
        cout << "\"Hello World\"";
        cout << "Hello World";
        cout << endl << endl;

        cout << "Hex" << endl;
        cout << '\x61';
        cout << endl << endl;

        cout << "Oct" << endl;
        cout << '\141';
        cout << endl << endl;
    }
    /* MultiCharacter Literal - not standard
     * {
     * char ch = 'ab';
     * int num = 'ab';
     * cout << ch << endl;
     * cout << num << endl;
     * }
     */

     return 0;
}