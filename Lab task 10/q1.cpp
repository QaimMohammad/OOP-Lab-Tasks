#include <iostream>
#include <fstream>

using namespace std;

// Encrypt string by adding index to ASCII values
string encrypt(const string& text) {
    string encrypted = text;
    for (int i = 0; i < text.length(); ++i) {
        encrypted[i] = text[i] + (i + 1);
    }
    return encrypted;
}

// Decrypt string by subtracting index from ASCII values
string decrypt(const string& text) {
    string decrypted = text;
    for (int i = 0; i < text.length(); ++i) {
        decrypted[i] = text[i] - (i + 1);
    }
    return decrypted;
}

int main() {
    string input;
    cout << "Enter String: ";
    getline(cin, input);

    string encrypted = encrypt(input);
    cout << "Normal Text: " << input << "\n";

    // Write encrypted text to file
    ofstream outFile("encrypted.txt");
    outFile << encrypted;
    outFile.close();
    cout << "Encrypted text inserted in file.\n";

    // Read encrypted text back
    ifstream inFile("encrypted.txt");
    string fileContent;
    getline(inFile, fileContent);
    inFile.close();

    string decrypted = decrypt(fileContent);
    cout << "Decrypted text read and decoded from file:\n";
    cout << decrypted << "\n";

    return 0;
}

