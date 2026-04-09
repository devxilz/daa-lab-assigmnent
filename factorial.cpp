#include<iostream>
using  namespace std;

void factorial(int n) {
    if (n == 0) {
        cout << "Factorial: 1" << endl;
        return;
    }
    int result = 1;
    int step_count = 0;
    for (int i = 1; i <= n; i++) {
        result *= i;
        step_count++;
    }
    cout << "Factorial: " << result << endl;
    cout << "Steps taken: " << step_count << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    factorial(n);
    cout <<"name - dev , roll no - 2401730237"<<endl; 
    return 0;
}