#pragma once
#include <iostream>
#include <vector>
using namespace std;

class resourceManager {
protected:
    vector<std::string> resources;

public:
    resourceManager() {
        cout << "ResourceManager created\n";
    }//конструктор

    // Метод для додавання ресурсу
    virtual void addResource(const string& resource) {
        resources.push_back(resource);
    }

    // Метод для виведення списку ресурсів
    void printResources() const {
        cout << "Resources: \n";
        for (const auto& resource : resources) {
            cout << "- " << resource << endl;
        }
    }

    ~resourceManager() {
        cout << "ResourceManager destroyed\n";
    }//деструктор
};