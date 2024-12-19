#ifndef ABONNEMENTPREMIUM_H
#define ABONNEMENTPREMIUM_H

#include "Abonnement.h"

enum NiveauPremium { BASIQUE, ARGENT, OR, PLATINE };

class AbonnementPremium : public Abonnement {
private:
    NiveauPremium niveau;
    int renouvellements;

public:
    AbonnementPremium(int id, double prixAnnuel);
    void passageNiveau() override;

    NiveauPremium getNiveau() const;
    int getRenouvellements() const;
    void setRenouvellements(int renouvellements);
};

#endif // ABONNEMENTPREMIUM_H
