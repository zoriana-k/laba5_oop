#pragma once
#include "project.h"
#include "manager.h"
using namespace std;

class customer : public person {
private:
    project* associatedProject;
    manager* projectManager;  // ���������
    char projectName[128];
    double budget;
    int projectDuration;

public:
    customer(const char* name, int age, const char* ID, const string& address, const string& position, const char* projectName, double budget, int projectDuration)
        : person(name, age, ID, address, position), budget(budget), projectDuration(projectDuration) {
        strcpy_s(this->projectName, projectName);
    }// ����������� � �����������

    void printInfo() const override {
        person::printInfo();
        cout << "Project Name: " << projectName << "\nBudget: $" << budget << "\nProject Duration: " << projectDuration << " months" << endl;
    } // ����� ��� ��������� ���������� ��� ���������

    virtual void setBudget(double newBudget) {
        budget = newBudget;
    }// ����� ��� ���� �������

    ~customer() override{
        cout << "Customer destroyed\n";
    }//����������

    void xxx() const override {
        cout << "xxx!!!metod" << endl;
    }

    void Printing() const {
        cout << "It's a customer" << endl;
    }

    project* getProject() const {
        return associatedProject;
    }

    double getBudget() const {
        return budget;
    }

    
};