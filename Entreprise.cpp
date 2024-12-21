#include "Entreprise.h"
#include "AbonnementPremium.h"
#include "AbonnementEconomique.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

Entreprise::Entreprise(const std::string& nom) : nom(nom) {}

Entreprise::~Entreprise() {
    for (Abonnement* abonnement : abonnements) {
        delete abonnement;
    }
}

void Entreprise::ajouterAbonnement(Abonnement* abonnement) {
    abonnements.push_back(abonnement);
}

void Entreprise::ajouterAbonne(const Abonne& abonne) {
    abonnes.push_back(abonne);
}

void Entreprise::affecterAbonnement(int idAbonnement, const std::string& pseudo) {
    for (Abonnement* abonnement : abonnements) {
        if (abonnement->getId() == idAbonnement && abonnement->getStatut() == EN_ATTENTE) {
            for (Abonne& abonne : abonnes) {
                if (abonne.getPseudo() == pseudo) {
                    abonnement->setStatut(ACTIF);
                    abonne.setIdAbonnement(idAbonnement);
                    return;
                }
            }
            throw std::runtime_error("Abonne non trouve");
        }
    }
    throw std::runtime_error("Abonnement non trouve ou non en attente svp");
    // chedy new message
}

void Entreprise::passageNiveauAbonnement(int idAbonnement) {
    for (Abonnement* abonnement : abonnements) {
        if (abonnement->getId() == idAbonnement && abonnement->getStatut() == ACTIF) {
            abonnement->passageNiveau();
            return;
        }
    }
    throw std::runtime_error("Abonnement non trouve ou non actif");
}

void Entreprise::affichAbNiveau(int niveau) {
    for (Abonnement* abonnement : abonnements) {
        AbonnementPremium* premium = dynamic_cast<AbonnementPremium*>(abonnement);
        if (premium && premium->getNiveau() == niveau) {
            std::cout << "Abonnement ID: " << premium->getId() << ", Prix: " << premium->getPrixAnnuel() << std::endl;
        }
        AbonnementEconomique* economique = dynamic_cast<AbonnementEconomique*>(abonnement);
        if (economique && economique->getNiveau() == niveau) {
            std::cout << "Abonnement ID: " << economique->getId() << ", Prix: " << economique->getPrixAnnuel() << std::endl;
        }
    }
}

void Entreprise::enregisterAbonne(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier");
    }
    for (const Abonne& abonne : abonnes) {
        if (abonne.getIdAbonnement() != 0) {
            file << abonne.getPseudo() << ", " << abonne.getIdAbonnement() << ", ";
            for (Abonnement* abonnement : abonnements) {
                if (abonnement->getId() == abonne.getIdAbonnement()) {
                    AbonnementPremium* premium = dynamic_cast<AbonnementPremium*>(abonnement);
                    if (premium) {
                        file << premium->getNiveau() << ", " << premium->getPrixAnnuel() << std::endl;
                    }
                    AbonnementEconomique* economique = dynamic_cast<AbonnementEconomique*>(abonnement);
                    if (economique) {
                        file << economique->getNiveau() << ", " << economique->getPrixAnnuel() << std::endl;
                    }
                }
            }
        }
    }
    file.close();
}
