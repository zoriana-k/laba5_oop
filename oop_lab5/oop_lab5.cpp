#include <iostream>
#include <fstream>
#include <stdexcept>
#include "manager.h"
#include "project.h"
#include "customer.h"
#include "employeer.h"
#include "team.h"
#include "resourceManager.h"
#include "teamLeader.h"
#include "projectController.h"

using namespace std;

void processProject(const project& p) {
    cout << "Processing project: " << p.name << endl;
    cout << "Customer: " << p.customer << endl;
    cout << "Budget: " << p.budget << endl;
}

void processProject(const project* p) {
    if (p) {
        cout << "Processing project: " << p->name << endl;
        cout << "Customer: " << p->customer << endl;
        cout << "Budget: " << p->budget << endl;
    }
}

void processProjectPointer(const project* p) {
    cout << "Processing project by pointer: " << p->name << endl;
    cout << "Customer: " << p->customer << endl;
    cout << "Budget: " << p->budget << endl;
}

void Service_Static(employeer staticEmployeers[], size_t size, double taskBudgetThreshold) {
    cout << "\nRemoving employeers with task budget below " << taskBudgetThreshold << "..." << endl;
    for (size_t i = 0; i < size; ++i) {
        if (staticEmployeers[i].getTaskBudget() < taskBudgetThreshold) {
            cout << "Removing: ";
            staticEmployeers[i].printInfo();
            staticEmployeers[i].deactivate(); // Замінюємо на "пустий" об'єкт
        }
    }
}

void Service_Dinamic(vector<customer*>& dynamicCustomers, double budgetThreshold) {
    cout << "\nRemoving customers with budget above " << budgetThreshold << "..." << endl;
    for (auto it = dynamicCustomers.begin(); it != dynamicCustomers.end(); ) {
        if ((*it)->getBudget() > budgetThreshold) {
            cout << "Removing: ";
            (*it)->printInfo();
            delete* it; // Видаляємо об'єкт із пам'яті
            it = dynamicCustomers.erase(it); // Видаляємо з вектора
        }
        else {
            ++it;
        }
    }
}

void Service(employeer& emp, const string& filename) {
    try {
        cout << "Writing data to file: " << filename << endl;
        emp.Write(filename);

        cout << "Reading data from file: " << filename << endl;
        employeer newEmp("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000);
        newEmp.Read(filename);
        cout << "Data successfully read from file:" << endl;
        newEmp.printInfo();
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (const ifstream::failure& e) {
        cerr << "File stream error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "General exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error occurred!" << endl;
    }
}
void displayInfo(const person& person) {
    person.printInfo(); // Поліморфний виклик
}

void xxxx(person* p) {
    p->xxx(); // Поліморфний виклик
}

int main(int argc, char* argv[]) {
    cout << "virtual destructors" << endl;
    person* p1 = new customer("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", "New Website", 50000, 12);
    person* p2 = new manager("Zavgorodnya Valeria", 37, "SuperManager", "119 Office St", "Manager", 50000, "Main Resources");
    p1->printInfo();
    p2->printInfo();
    xxxx(p1);
    xxxx(p2);
    cout << "deleting persons" << endl;
    delete p1;
    delete p2;

    person* base = new customer("Kravchuk Anna", 32, "ModelingStudio", "337 Yugi St", "Customer", "Portfolio", 35000, 10);
    customer* derived = new customer("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", "New Website", 80000, 21);
    base->Printing();   // Раннє зв'язування: викликається person::nonVirtualInfo
    derived->Printing(); // Раннє зв'язування: викликається customer::nonVirtualInfo
    delete base;
    delete derived;

    customer cust("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", "New Website", 80000, 21);
    person& baseCust = cust;  // Заміна на посилання, а не на об'єкт
    cout << "Base class copy of customer:" << endl;
    baseCust.Printing(); // Викликається метод базового класу
    baseCust.printInfo(); // Викликається перевизначений метод

    cout << "non virtual destructors" << endl;
    employeer* em1 = new teamLeader("Andrii Solodyuk", 30, "Suslik", "456 Elm St", "Team Leader", 5, 10000, "Rows");
    employeer* em2 = new teamLeader("Potapskii Vladyslav", 34, "Potap", "789 Pine St", "Team Leader", 6, 13000, "Tales");
    em1->printInfo();
    em2->printInfo();
    cout << "deleting employeers" << endl;
    delete em1;
    delete em2;

    try {
        employeer staticEmployeers[5] = {
            employeer("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000),
            employeer("Lisovska Viktoria", 35, "Fairy", "202 Maple St", "Marketer", 5, 6000),
            employeer("Borishchuk Sophia", 29, "Borshch", "303 Birch St", "Tester", 2, 4000),
            employeer("Petruk Kateryna", 32, "Petryk", "404 Oak St", "Backend Developer", 4, 7000),
            employeer("Kolba Sergiy", 25, "Glass", "211 Pine St", "Frontend Developer", 2, 5000)
        };

        cout << "Static Employeers:" << endl;
        for (auto& e : staticEmployeers) {
            e.printInfo();
        }

        Service_Static(staticEmployeers, 5, 5500);

        vector<customer*> dynamicCustomers;
        try {
            dynamicCustomers.push_back(new customer("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", "New Website", 50000, 12));
            dynamicCustomers.push_back(new customer("Plutach Iryna", 25, "CatAndShrek", "12 Yugi St", "Customer", "Fixing Bugs", 70000, 5));
            dynamicCustomers.push_back(new customer("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", "New Website", 80000, 21));
            dynamicCustomers.push_back(new customer("Kravchuk Anna", 32, "ModelingStudio", "337 Yugi St", "Customer", "Portfolio", 35000, 10));
            dynamicCustomers.push_back(new customer("Mazuretz Khrystyna", 27, "SushiKushi", "112 Uk St", "Customer", "Creating a new section on the site", 40000, 7));
        }
        catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            throw;
        }

        cout << "\nDynamic Customers:" << endl;
        for (auto* c : dynamicCustomers) {
            c->printInfo();
        }

        Service_Dinamic(dynamicCustomers, 60000);

        customer* uninitPointer = nullptr;
        if (uninitPointer) {
            uninitPointer->printInfo();
        }
        else {
            cerr << "Attempted to access null pointer." << endl;
        }

        for (auto* c : dynamicCustomers) {
            delete c;
        }
        dynamicCustomers.clear();
    }
    catch (const exception& e) {
        cerr << "Unhandled exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unhandled unknown exception!" << endl;
    }

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    employeer emp("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000);
    cout << "Original employee data:" << endl;
    emp.printInfo();
    cout << "\nStarting Service function..." << endl;
    Service(emp, filename);

    employeer staticEmployeers[5] = {
            employeer("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000),
            employeer("Lisovska Viktoria", 35, "Fairy", "202 Maple St", "Marketer", 5, 6000),
            employeer("Borishchuk Sophia", 29, "Borshch", "303 Birch St", "Tester", 2, 4000),
            employeer("Petruk Kateryna", 32, "Petryk", "404 Oak St", "Backend Developer", 4, 7000),
            employeer("Kolba Sergiy", 25, "Glass", "211 Pine St", "Frontend Developer", 2, 5000)
    };
    vector<customer*> dynamicCustomers;
    {
        dynamicCustomers.push_back(new customer("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", "New Website", 50000, 12));
        dynamicCustomers.push_back(new customer("Plutach Iryna", 25, "CatAndShrek", "12 Yugi St", "Customer", "Fixing Bugs", 70000, 5));
        dynamicCustomers.push_back(new customer("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", "New Website", 80000, 21));
        dynamicCustomers.push_back(new customer("Kravchuk Anna", 32, "ModelingStudio", "337 Yugi St", "Customer", "Portfolio", 35000, 10));
        dynamicCustomers.push_back(new customer("Mazuretz Khrystyna", 27, "SushiKushi", "112 Uk St", "Customer", "Creating a new section on the site", 40000, 7));
    }
    // Меню
    while (true) {
        cout << "\n==== MENU ====" << endl;
        cout << "1. Display Static Employeers" << endl;
        cout << "2. Display Dynamic Customers" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            for (const auto& e : staticEmployeers) e.printInfo();
            break;
        case 2:
            for (const auto& c : dynamicCustomers) c->printInfo();
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }


    vector<person*> people;
    people.push_back(new customer("Kravchuk Anna", 32, "ModelingStudio", "337 Yugi St", "Customer", "Portfolio", 35000, 10));
    people.push_back(new manager("Pecheniuk Kateryna", 29, "Pechinka", "45 Yugi St", "Manager", 32000, "Commands"));

    for (auto person : people) {
        person->printInfo(); // Поліморфні виклики
    }

    for (auto person : people) {
        delete person; // Очищення пам'яті
    }


    customer c("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", "New Website", 80000, 21);
    manager m("Shapochuk Diana", 24, "Shpak", "2 Maple St", "Manager", 55000, "Budget");
    displayInfo(c); // Виклик перевизначеного методу Customer
    displayInfo(m);

    return 0;
}
