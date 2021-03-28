/*************************************************/
// Nom du projet: Surcharge d'operateur
// Nom du fichier: tp surcharge d'operateur
// Version : 1.0
// Nom du programmeur: Baptiste Puibusque
// Date de cr�ation :22/03/2021
// R�le du fichier: declaration des fonctions de la classe CDate
// Nom des composants utilises:
// Historique du fichier:
/*************************************************/

#ifndef CDATE_H
#define CDATE_H


class CDate
{
    public:

        // Nom : CDate
        // R�le : Constructeur de la classe
        // Param�tres d'entr�e : jour, mois, annee, heure, minutes, seconde
        CDate(int jour, int mois, int annee, int heure, int minutes, int secondes);

        // Nom : ==
        // R�le : operateur qui verifie si deux dates sont egales ou non
        // Param�tres d'entr�e/sortie : Une date constante passe par reference
        // Valeur de retour : booleen (true ou false)
        bool operator == (const CDate & Date);

        // Nom : >
        // R�le : operateur qui verifie si une date est superieure a une autre ou pas
        // Param�tres d'entr�e/sortie : Une date constante passe par reference
        // Valeur de retour : booleen (true ou false)
        bool operator > (const CDate & Date);

        // Nom : <
        // R�le : operateur qui verifie si une date est inferieure a une autre ou pas
        // Param�tres d'entr�e/sortie : Une date constante passe par reference
        // Valeur de retour : booleen (true ou false)
        bool operator < (const CDate & Date);

        // Nom : getDate
        // R�le : attribue a des valeurs par reference les attributs de la date courante
        // Param�tres de sortie : jour, mois, annee, heure, minute, seconde
        void getDate(int &jour, int &mois, int &annee, int &heure, int &minute, int &seconde);

        // Nom : anneeBisextile
        // R�le : renvoie true si l'annee de la date courante est bisextile et false sinon
        // Valeur de retour : booleen (true ou false)
        bool anneeBisextile();

        // Nom : jourDansLeMois
        // R�le : renvoie le nombre de jour dans le mois de la date courante
        // Valeur de retour : entier qui represente le nombre de jours
        int jourDansLeMois();

        // Nom : ++
        // R�le : operateur qui ajoute 1 seconde a la date courante
        void operator++();

    private:
        int m_jour, m_mois, m_annee, m_heure, m_minutes, m_secondes; //jour, mois, annee, heure, minutes, seconde, de la date courante
};

#endif // CDATE_H
