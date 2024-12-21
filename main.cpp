#include <iostream>
#include "Entreprise.h"
#include "AbonnementPremium.h"
#include "AbonnementEconomique.h"
#include "Abonne.h"

int main() {
    // Création de l'entreprise
    Entreprise entreprise("MaEntreprise");

    // Création des abonnements
    AbonnementPremium* premium1 = new AbonnementPremium(1, 1000.0);
    AbonnementEconomique* eco1 = new AbonnementEconomique(2, 500.0);

    // Ajout des abonnements à l'entreprise
    entreprise.ajouterAbonnement(premium1);
    entreprise.ajouterAbonnement(eco1);

    // Création des abonnés
    Abonne abonne1("Alice", 30);
    Abonne abonne2("Bob", 25);
    Abonne abonne3("mohamed", 25);

    // Ajout des abonnés à l'entreprise
    entreprise.ajouterAbonne(abonne1);
    entreprise.ajouterAbonne(abonne2);

    // Affectation des abonnements
    entreprise.affecterAbonnement(1, "Alice");
    entreprise.affecterAbonnement(2, "Bob");

    // Passage de niveau des abonnements
    premium1->setRenouvellements(6); // Simuler des renouvellements pour tester le passage de niveau
    entreprise.passageNiveauAbonnement(1);

    eco1->setParrains(6); // Simuler des parrainages pour tester le passage de niveau
    entreprise.passageNiveauAbonnement(2);

    // Affichage des abonnements par niveau
    std::cout << "Abonnements de niveau ARGENT:" << std::endl;
    entreprise.affichAbNiveau(ARGENT);

    std::cout << "Abonnements de niveau NIVEAU2:" << std::endl;
    entreprise.affichAbNiveau(NIVEAU2);

    // Enregistrement des abonnés dans un fichier
    entreprise.enregisterAbonne("abonnes.txt");

    //raslen changes

    return 0;
}
