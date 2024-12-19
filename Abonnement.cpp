#include "Abonnement.h"

Abonnement::Abonnement(int id, double prixAnnuel) : id(id), prixAnnuel(prixAnnuel), statut(EN_ATTENTE) {}

Abonnement::~Abonnement() {}

int Abonnement::getId() const {
    return id;
}

double Abonnement::getPrixAnnuel() const {
    return prixAnnuel;
}

Statut Abonnement::getStatut() const {
    return statut;
}

void Abonnement::setStatut(Statut statut) {
    this->statut = statut;
}
