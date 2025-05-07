#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void writeLog(const string& logText) {
    string base = "log";
    int fileNum = 1;
    string fileName = base + to_string(fileNum) + ".txt";

    while (fs::exists(fileName) && fs::file_size(fileName) >= 1024 * 1024) {
        ++fileNum;
        fileName = base + to_string(fileNum) + ".txt";
    }

    ofstream logFile(fileName, ios::app);
    logFile << logText << "\n";
    logFile.close();
}

int main() {
    for (int i = 0; i < 100; ++i) {
        writeLog("Log entry " + to_string(i));
    }
    cout << "Logs written with rotation.\n";
    return 0;
}

