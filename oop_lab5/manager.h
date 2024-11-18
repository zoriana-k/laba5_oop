#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "person.h"
#include "project.h"
#include "team.h"
#include "employeer.h"

class manager : public person {
private:
    int totalBudget;
    vector<string> teams;
    string projectResources;

public:
    // Конструктор з параметрами
    manager(const char* name, int age, const char* ID, const string& address, const string& position, int totalBudget, const string& resources)
        : person(name, age, ID, address, position), totalBudget(totalBudget), projectResources(resources) {}

    // Метод для виведення інформації про менеджера
    void printInfo() const override {
        person::printInfo();
        cout << "Total Budget: $" << totalBudget << "\nResources: " << projectResources << endl;
    }

    void xxx() const override{
        cout << "xxx super metod" << endl;
    }

    void Printing() const {
        cout << "It's a manager" << endl;
    }

    // Метод для додавання нової команди
    void addTeam(const string& teamName) {
        teams.push_back(teamName);
    }

    // Метод для виведення списку команд
    void printTeams() const {
        cout << "Teams managed: \n";
        for (const auto& team : teams) {
            cout << "- " << team << endl;
        }
    }

    //Деструктор
    ~manager() {
        cout << "Manager destroyed\n";
    }

    // Метод для призначення проекту менеджеру
    void assignProject(project* proj) {
        managedProjects.push_back(proj);
    }

    // Метод для розподілу проекту між командами
    void distributeProjectToTeam(team& teamObj) {
        assignedTeams.push_back(&teamObj);
    }

    // Метод для розподілу бюджету між робітниками
    virtual void assignBudget(employeer& emp, int amount) {
        emp.setTaskBudget(amount);
    }

    // Метод для розподілу ресурсів між робітниками
    void assignResources(employeer& emp, const string& resource) {
        emp.addResource(resource);
    }

    // Список керованих проектів
private:
    vector<project*> managedProjects;
    vector<team*> assignedTeams;

};