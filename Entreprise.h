#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <vector>
#include <string>
#include "Abonnement.h"
#include "Abonne.h"

class Entreprise {
private:
    std::string nom;
    std::vector<Abonnement*> abonnements;
    std::vector<Abonne> abonnes;

public:
    Entreprise(const std::string& nom);
    ~Entreprise();

    void ajouterAbonnement(Abonnement* abonnement);
    void ajouterAbonne(const Abonne& abonne);
    void affecterAbonnement(int idAbonnement, const std::string& pseudo);
    void passageNiveauAbonnement(int idAbonnement);
    void affichAbNiveau(int niveau);
    void enregisterAbonne(const std::string& filename);
};

#endif // ENTREPRISE_H
