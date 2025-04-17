#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual float getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    float getTuition(string status, int creditHours) override {
        if (status == "undergraduate") {
            return creditHours * 200;
        } else if (status == "graduate") {
            return creditHours * 300;
        } else if (status == "doctoral") {
            return creditHours * 400;
        } else {
            return 0;
        }
    }
};

int main() {
    GraduateStudent g;

    string topic, status;
    int credits;

    cout << "Enter research topic: ";
    getline(cin, topic);
    g.setResearchTopic(topic);

    cout << "Enter student status (undergraduate / graduate / doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> credits;

    float tuition = g.getTuition(status, credits);

    cout << "\nResearch Topic: " << g.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << tuition << endl;

    return 0;
}

