// 3_LargestPrimeFactor_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdint>
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

uint64_t largestPrimeFactor_2(uint64_t number) {
    uint64_t remProd = number;
    uint64_t testPrime;
    uint64_t retPrimeFac = 1;
    vector<uint64_t> primeNumbers;  // List of known prime numbers less than remProd
    vector<uint64_t> primeFactors;  // List of known prime factors of number

    testPrime = 2;
    primeNumbers.push_back(testPrime);

    if (number < 2 || number > 0x7fffffffffffffff)
    {
        cout << "Invalid value! Number has to be between 2 to " << 0x7fffffffffffffff << endl;
        return number;
    }

    // Starting from 2, check to see if remProd is dividable by testPrime
    while (remProd >= testPrime)
    {
#ifdef _DEBUG
        cout << "Calculating " << remProd << '/' << testPrime << "...\n";
#endif // DEBUG
        if (remProd % testPrime == 0)
        {   // If remProd is diviable by testPrime
            // Mark testPrime as a PrimeFactor, if not already
            if (primeFactors.size() <= 0 || primeFactors.back() != testPrime)
            {
                primeFactors.push_back(testPrime);
                cout << "\t[F] Found new prime factor => " << testPrime << endl;
            }

            // Update remProd value
            remProd /= testPrime;
            cout << "\t[R] remProd update => " << remProd << endl;
        }
        else
        {   // If remProd is not dividble by testPrime, move onto the next prime number
            for ( testPrime = testPrime + 1; testPrime <= remProd; testPrime++)
            {
                bool isDividible = false;
                // Test if i is a prime number
                for (uint64_t j = 0; isDividible == false && j < primeNumbers.size(); j++)
                {
                    if ( testPrime % primeNumbers[j] == 0)
                    {
                        isDividible = true;
                    }
                }
                // If the i is not dividible by any of the known prime number, it's a prime number as well
                if (!isDividible)
                {
                    primeNumbers.push_back( testPrime );
#ifdef _DEBUG
                    cout << "\t[P] Next testing prime: " << testPrime << endl;
#endif // DEBUG
                    break;
                }
            }
        }
    }

    cout << "Found Prime Factors for " << number << "...\n";
    for( int k = 0; k < primeFactors.size(); k++ )
    { 
        cout << primeFactors[k] << ' ';
    }
    cout << endl;

    retPrimeFac = primeFactors.back();
    return retPrimeFac;
}

int main()
{
    uint64_t eVal = 0;
    cout << "Enter a number: ";
    cin >> eVal;

    cout << "Searching prime factors for " << eVal << "!!" << endl;
    uint64_t largestPrime = largestPrimeFactor_2(eVal);
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
