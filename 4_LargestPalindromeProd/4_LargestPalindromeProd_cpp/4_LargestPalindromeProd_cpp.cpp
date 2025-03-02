// 4_LargestPalindromeProd_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPalindromic(long val)
{
    bool ret = true;
    string strNum = to_string(val);

    int iBegin, iEnd;
    for (iBegin = 0, iEnd = strNum.length() - 1; iBegin < iEnd && ret; iBegin++, iEnd--)
    {
        if (strNum[iBegin] != strNum[iEnd])
        {
            ret = false;
        }
    }

    return ret;
}

int main()
{
    int digits;
    std::cout << "Enter number of digits for numbers: ";
    cin >> digits;

    int num1, num2;
    int minNum, maxNum;
    long product;
    long maxPalProd = 0 ;

    // Establish the min/max number for the number of digits given
    minNum = int( pow(10, digits - 1) );
    maxNum = int( pow(10, digits) ) - 1;

    cout << "Finding largest palindrome with multiples between " << minNum << '~' << maxNum << endl;
    for (num1 = maxNum; num1 >= minNum; num1--)
    {
        for (num2 = num1; num2 >= minNum; num2--)
        {
            product = num1 * num2;
#ifdef _DEBUG
            cout << num1 << " x " << num2 << " = " << product << endl;
#endif // _DEBUG
            if (isPalindromic( product ) )
            {
                cout << "Found Palindromic Value => " << product << " = " << num1 << " x " << num2 << endl;
                if (maxPalProd < product)
                {
                    maxPalProd = product;
                }
            }
        }
    }

    cout << "Found max Palindromic: " << maxPalProd << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
