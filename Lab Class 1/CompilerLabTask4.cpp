
#include <iostream>

using namespace std;

long long calculateFactorial(int number) {
    if (number < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return -1;
    }

    long long factorial = 1;
    for (int i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int userInput;

    cout << "Enter a number to calculate its factorial: ";
    cin >> userInput;

    long long result = calculateFactorial(userInput);
    if (result != -1) {
        cout << "The factorial of " << userInput << " is: " << result << endl;
    }

    return 0;
}
