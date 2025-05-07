#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        for (int i = 0; i < 5; ++i) {
            cout << ".";
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "\nJuice blended!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "\nJuice ground!" << endl;
    }
};

class JuiceMaker {
public:
    Blend blend;
    Grind grind;

    void blendJuice() {
        blend.blendJuice();
    }

    void grindJuice() {
        grind.grindJuice();
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.blendJuice();
    juiceMaker.grindJuice();
    return 0;
}

