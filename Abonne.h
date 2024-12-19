#ifndef ABONNE_H
#define ABONNE_H

#include <string>

class Abonne {
private:
    std::string pseudo;
    int age;
    int idAbonnement;

public:
    Abonne(const std::string& pseudo, int age);
    std::string getPseudo() const;
    int getAge() const;
    int getIdAbonnement() const;
    void setIdAbonnement(int idAbonnement);
};

#endif // ABONNE_H
