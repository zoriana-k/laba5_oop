#pragma once
#include <iostream>
#include <vector>
#include "employeer.h"
#include "resourceManager.h"
using namespace std;

class teamLeader : public employeer, public resourceManager {
private:
    string teamName;

public:
    // Конструктор з параметрами
    teamLeader(const char* name, int age, const char* contactInfo, const string& address, const string& position, int experience, int taskBudget, const string& teamName)
        : employeer(name, age, contactInfo, address, position, experience, taskBudget), teamName(teamName) {
        cout << "TeamLeader created\n";
    }

    // Метод для виведення інформації про лідера команди
    void printInfo() const override {
        employeer::printInfo();
        cout << "Team Name: " << teamName << endl;
        printResources();
    }

    virtual void organizeMeeting() const {
        cout << "Team Leader organizes a team meeting." << endl;
    }

    ~teamLeader() {
        cout << "TeamLeader destroyed\n";
    }//деструктор
};