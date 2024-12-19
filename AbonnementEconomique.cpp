#include "AbonnementEconomique.h"

AbonnementEconomique::AbonnementEconomique(int id, double prixAnnuel) : Abonnement(id, prixAnnuel), niveau(NIVEAU1), parrains(0) {}

void AbonnementEconomique::passageNiveau() {
    if (statut == ACTIF) {
        if (niveau == NIVEAU1 && parrains >= 5) {
            niveau = NIVEAU2;
            prixAnnuel *= 0.98;
        } else if (niveau == NIVEAU2 && parrains >= 10) {
            niveau = NIVEAU3;
            prixAnnuel *= 0.96;
        }
    }
}

NiveauEconomique AbonnementEconomique::getNiveau() const {
    return niveau;
}

int AbonnementEconomique::getParrains() const {
    return parrains;
}

void AbonnementEconomique::setParrains(int parrains) {
    this->parrains = parrains;
}
