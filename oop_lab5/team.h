#pragma once
#include "employeer.h"
#include <vector>
#include <iostream>

class team {
private:
    employeer teamLeader;            // Лідер команди
    std::vector<employeer> members;   // Список учасників команди

public:
    team(const employeer& leader) : teamLeader(leader) {}

    // Метод для додавання працівника в команду
    void addEmployeer(const employeer& emp) {
        members.push_back(emp);
    }

    // Метод для виведення інформації про лідера команди і всіх учасників команди
    void printTeam() const {
        std::cout << "Team Leader: ";
        teamLeader.printInfo();
        std::cout << "\nTeam Members:\n";
        for (const auto& member : members) {
            member.printInfo();
            std::cout << "------------------\n";
        }
    }
};
