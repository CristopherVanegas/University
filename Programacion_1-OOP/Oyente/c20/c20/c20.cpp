// c20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <format>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    double variable{ 3.1415926536 };
    double var2{ 4.3453546454 };

    // cout << endl << format("{}", variable.setprecision(2));
    cout << endl << setprecision(10) << variable;
    cout << endl << var2;


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
