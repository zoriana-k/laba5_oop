#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "person.h"

class employeer : public person {
private:
    int experience;
    int taskBudget;
    bool isActive; // ������ ����������� isActive
    vector<string> assignedTasks;

public:
    employeer(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int experience, int taskBudget)
        : person(name, age, ID, address, position), experience(experience), taskBudget(taskBudget), isActive(true) {} // ����������� isActive

    // ����� ��� ��������� ���������� ��� ��������
    void printInfo() const override {
        if (isActive) {
            person::printInfo();
            cout << "Experience: " << experience << " years\nTask Budget: $" << taskBudget << endl;
        }
        else {
            cout << "This employeer is inactive." << endl;
        }
    }

    // ����� ��� ��������� ��������
    virtual void assignTask(const string& task) {
        assignedTasks.push_back(task);
    }

    // ����� ��� ��������� ������ �������
    void printAssignedTasks() const {
        cout << "Assigned Tasks: \n";
        for (const auto& task : assignedTasks) {
            cout << "- " << task << endl;
        }
    }

    void xxx() const override {
        cout << "xxx wow method" << endl;
    }

    void Printing() const {
        cout << "It's an employeer" << endl;
    }

    // ����������
    ~employeer() {
        cout << "Employeer destroyed\n";
    }

    void setTaskBudget(int amount) {
        taskBudget = amount;
    }

    void addResource(const string& resource) {
        assignedResources.push_back(resource);
    }

    double getTaskBudget() const {
        return taskBudget;
    }

    bool getIsActive() const {
        return isActive;
    }

    void deactivate() {
        isActive = false; // ��������� ��'��� �� "���������"
    }

    // ����� ������ ����� � ����
    void Write(const string& filename) const {
        ofstream outFile(filename, ios::out);
        if (!outFile) {
            throw runtime_error("Unable to open file for writing: " + filename);
        }
        outFile << name << "\n" << age << "\n" << ID << "\n"
            << address << "\n" << position << "\n" << experience << "\n" << taskBudget << "\n";
        if (outFile.fail()) {
            throw runtime_error("Error writing to file: " + filename);
        }
        outFile.close();
    }

    // ����� ������� ����� �� �����
    // ������� ����� � �����
    void Read(const string& filename) {
        ifstream inFile(filename, ios::in);
        if (!inFile) {
            throw runtime_error("Unable to open file for reading: " + filename);
        }

        // ������� ����� � �����
        getline(inFile, name);  // ������ ��'�
        if (inFile.fail()) throw runtime_error("Error reading name from file");

        inFile >> age;
        inFile.ignore(); // ���������� ������ ������ ����� ���� age

        getline(inFile, ID); // ������ ID
        getline(inFile, address); // ������ ������
        getline(inFile, position); // ������ ������
        inFile >> experience >> taskBudget; // ������ ����� � ������ ��������

        if (inFile.fail()) {
            throw runtime_error("Error reading data from file");
        }
        inFile.close();
    }

private:
    vector<string> assignedResources;
};
