// 3_LargestPrimeFactor_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

long largestPrimeFactor(long number) {
    int  largestPrimeFac = 0;
    // Edge case 1: number is less than 2
    if (number < 2)
    {
        return largestPrimeFac;
    }

    // Find the prime numbers less than "number"
    vector<long> primeNum; // List of known primary number less than "number"
    primeNum.push_back(2);

    for (long i = 3; i <= number; i++)
    {
        bool isDividible = false;
        // Test if i is a prime number
        for (long j = 0; isDividible == false && j < primeNum.size(); j++)
        {
            if (i % primeNum[j] == 0)
            {
                isDividible = true;
            }
        }
        // If the i is not dividible by any of the known prime number, it's a prime number as well
        if (!isDividible)
        {
            primeNum.push_back(i);
            cout << "/tFound prime: " << i << endl;
        }
    }

    // Finding the largest prime number whick is also a factor of "number"
    for (long i = primeNum.size() - 1; i >= 0; i--)
    {
        if (number % primeNum[i] == 0)
        {
            largestPrimeFac = primeNum[i];
            break;
        }
    }

    return largestPrimeFac;
}

int main()
{
    long eVal = 0;
    cout << "Enter a number: ";
    cin >> eVal;

    long largestPrime = largestPrimeFactor(eVal);
    cout << "Largest factor for " << eVal << " is " << largestPrime << endl;

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
