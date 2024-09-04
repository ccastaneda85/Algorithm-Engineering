#include <iostream>
#include <string>
using namespace std;

void printBinary(char ch) {
    // Convert the character to its ASCII value
    int asciiValue = static_cast<int>(ch);

    // Output the binary representation of the ASCII value
    for (int i = 128; i > 0; i /= 2) {
        if (asciiValue >= i) {
            cout << "1";
            asciiValue -= i;
        }
        else {
            cout << "0";
        }
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "Binary representation: ";
    cout << endl;
    int index = 0;
    while (index < input.size()) {
        printBinary(input[index]);
        cout << endl;
        ++index;
        
    }
    cout << endl;

    return 0;

}