#ifndef ABONNEMENTECONOMIQUE_H
#define ABONNEMENTECONOMIQUE_H

#include "Abonnement.h"

enum NiveauEconomique { NIVEAU1, NIVEAU2, NIVEAU3 };

class AbonnementEconomique : public Abonnement {
private:
    NiveauEconomique niveau;
    int parrains;

public:
    AbonnementEconomique(int id, double prixAnnuel);
    void passageNiveau() override;

    NiveauEconomique getNiveau() const;
    int getParrains() const;
    void setParrains(int parrains);
};

#endif // ABONNEMENTECONOMIQUE_H
