#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include <string>

enum Statut { EN_ATTENTE, ACTIF };

class Abonnement {
protected:
    int id;
    double prixAnnuel;
    Statut statut;

public:
    Abonnement(int id, double prixAnnuel);
    virtual ~Abonnement();

    int getId() const;
    double getPrixAnnuel() const;
    Statut getStatut() const;
    void setStatut(Statut statut);

    virtual void passageNiveau() = 0;
};

#endif // ABONNEMENT_H
