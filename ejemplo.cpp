#include <iostream>
#include <vector>
#include <string>
class Ticket {
public:
    std::string description;
    bool assigned;
    Ticket(std::string desc) : description(desc), assigned(false) {}
};
class TeamMember {
public:
    std::string name;
    std::vector<Ticket*> tickets;
    TeamMember(std::string n) : name(n) {}
    void assignTicket(Ticket* t) {
        tickets.push_back(t);
        t->assigned = true;
    }
};
class ScrumMaster {
public:
    std::vector<TeamMember*> team;
    std::vector<Ticket*> backlog;
    ScrumMaster(std::vector<TeamMember*> t, std::vector<Ticket*> b) : team(t), backlog(b) {}
    void assignTickets() {
        for (Ticket* t : backlog) {
            if (!t->assigned) {
                TeamMember* tm = findTeamMember();
                tm->assignTicket(t);
            }
        }
    }
private:
    TeamMember* findTeamMember() {
        // Implementar lógica para encontrar el miembro del equipo adecuado para asignar el ticket
        return team[0];
    }
};
int main() {
    // Crear tickets
    Ticket t1("Arreglar bug en la página de inicio");
    Ticket t2("Implementar nueva funcionalidad en el carrito de compras");
    std::vector<Ticket*> tickets = {&t1, &t2};

    // Crear miembros del equipo
    TeamMember m1("Juan");
    TeamMember m2("Ana");
    std::vector<TeamMember*> team = {&m1, &m2};

    // Crear Scrum Master
    ScrumMaster sm(team, tickets);

    // Asignar tickets
    sm.assignTickets();

    // Verificar asignación de tickets
    for (TeamMember* tm : team) {
        std::cout << tm->name << " tiene los siguientes tickets asignados:" << std::endl;
        for (Ticket* t : tm->tickets) {
            std::cout << "- " << t->description << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
