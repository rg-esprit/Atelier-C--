#include "Abonne.h"

Abonne::Abonne(const std::string& pseudo, int age) : pseudo(pseudo), age(age), idAbonnement(0) {}

std::string Abonne::getPseudo() const {
    return pseudo;
}

int Abonne::getAge() const {
    return age;
}

int Abonne::getIdAbonnement() const {
    return idAbonnement;
}

void Abonne::setIdAbonnement(int idAbonnement) {
    this->idAbonnement = idAbonnement;
}
