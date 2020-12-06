#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    cout << "         char : " << sizeof(char) 
         << ", min:  " << CHAR_MIN
         << ", max:  " << CHAR_MAX
         << ", umax: " << UCHAR_MAX
         << endl;

    cout << "     w_char_t : " << sizeof(wchar_t) 
         << ", min: "  << WCHAR_MIN
         << ", max: "  << WCHAR_MAX
         << endl;
    
    cout << "          int : " << sizeof(int) 
         << ", min: "  << INT_MIN
         << ", max: "  << INT_MAX
         << ", umax: " << UINT_MAX
         << endl;

    cout << "    short int : " << sizeof(short int) 
         << ", min: "  << SHRT_MIN
         << ", max: "  << SHRT_MAX
         << ", umax: " << USHRT_MAX
         << endl;

    cout << "     long int : " << sizeof(long int) 
         << ", min: "  << LONG_MIN
         << ", max: "  << LONG_MAX
         << ", umax: " << ULONG_MAX
         << endl;

    cout << "long long int : " << sizeof(long long int) 
         << ", min: "  << LLONG_MIN
         << ", max: "  << LLONG_MAX
         << ", umax: " << ULLONG_MAX
         << endl;

    cout << "        float : " << sizeof(float) 
         << ", min: " << FLT_MIN
         << ", max: " << FLT_MAX 
         << endl;

    cout << "       double : " << sizeof(double) 
         << ", min: " << DBL_MIN
         << ", max: " << DBL_MAX
         << endl;
         
    cout << "  long double : " << sizeof(long double) 
         << ", min: " << LDBL_MIN
         << ", max: " << LDBL_MAX
         << endl;

    return 0;
}