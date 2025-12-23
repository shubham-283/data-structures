#include <iostream>
using namespace std;

void print1toN(int n,int curr) {
    if (n == 0) {
        return;
    }
    print1toN(n - 1,curr);
    cout << n << " ";
    if (n == curr) {
        cout << endl;
    }
}


void printNto1(int n,int curr) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printNto1(n - 1,curr);
    if (n == curr) {
        cout << endl;
    }
}



int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}





int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}





//golden ratio = 1.617
void printFibo(int n, int a = 0, int b = 1) {
    if (n == 1) {
        return;
    }
    cout << a << " ";
    printFibo(n - 1, b, a + b);
}



float squareRoot(float num,float n){
    float s = num/n;
    float avg = (s + n) / 2;
    // cout << "avg: " << avg << endl;
    if(avg * avg - num < 0.0001)
        return avg;
    return squareRoot(num, avg);
}



double squareRoot2(float num,float n){
    double s = num/n;
    double avg = (s + n) / 2;
    // cout << "avg: " << avg << endl;
    if(avg * avg - num < 0.0001)
        return avg;
    return squareRoot(num, avg);
}




int main() {
    float num;
    cout << "enter number: ";
    cin >> num;
    cout << "Enter n: ";
    float n;
    cin >> n;
    // printNto1(n,1);
    // print1toN(n,1);
    // cout << factorial(n)<<endl;
    // printFibo(n);
    cout<< squareRoot2(num,n) <<endl;
    // cout<<"a";
}