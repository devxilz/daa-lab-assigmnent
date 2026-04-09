#include<iostream>
using  namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        cout << "Fibonacci: 0" << endl;
        return;
    }
    else if (n == 1) {
        cout << "Fibonacci: 1" << endl;
        return;
    }
    int a = 0, b = 1, c;
    int step_count = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        step_count++;
    }
    cout << "Fibonacci: " << c << endl;
    cout << "Steps taken: " << step_count << endl;
}
int recursion_count = 0;

int fibonacci_recursive(int n) {
    recursion_count++;

    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    fibonacci(n);
    int fibonacci = fibonacci_recursive(n);
    cout << "Fibonacci (recursive): " << fibonacci << endl;
    cout << "Number of recursive calls: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl; 
    return 0;
}