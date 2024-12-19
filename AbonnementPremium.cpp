#include "AbonnementPremium.h"

AbonnementPremium::AbonnementPremium(int id, double prixAnnuel) : Abonnement(id, prixAnnuel), niveau(BASIQUE), renouvellements(0) {}

void AbonnementPremium::passageNiveau() {
    if (statut == ACTIF) {
        if (niveau == BASIQUE && renouvellements >= 5) {
            niveau = ARGENT;
            prixAnnuel *= 0.90;
        } else if (niveau == ARGENT && renouvellements >= 10) {
            niveau = OR;
            prixAnnuel *= 0.85;
        } else if (niveau == OR && renouvellements >= 15) {
            niveau = PLATINE;
            prixAnnuel *= 0.85;
        }
    }
}

NiveauPremium AbonnementPremium::getNiveau() const {
    return niveau;
}

int AbonnementPremium::getRenouvellements() const {
    return renouvellements;
}

void AbonnementPremium::setRenouvellements(int renouvellements) {
    this->renouvellements = renouvellements;
}
