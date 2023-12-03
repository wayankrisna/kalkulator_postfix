#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;

// Fungsi untuk mengevaluasi ekspresi postfix
double evaluatePostfix(string postfix) {
    stack<double> operandStack;

    for (char& c : postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0'); // Mengonversikan karakter menjadi bilangan bulat
        } else if (c == ' ') {
            continue;
        } else {
            // Operator ditemukan
            double operand2 = operandStack.top();
            operandStack.pop();

            double operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(pow(operand1, operand2));
                    break;
                default:
                    cerr << "Operator tidak valid: " << c << endl;
                    exit(1);
            }
        }
    }

    return operandStack.top();
}

int main() {
    string postfix;

    cout << "Masukkan ekspresi postfix: ";
    getline(cin, postfix);

    double result = evaluatePostfix(postfix);

    cout << "Hasil evaluasi: " << result << endl;

    return 0;
}
