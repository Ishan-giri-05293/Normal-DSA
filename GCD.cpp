#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    cout << gcd << endl;
    return 0;
}
// This program calculates the GCD (Greatest Common Divisor) of two numbers entered by the user.