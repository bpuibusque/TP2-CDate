/*************************************************/
// Nom du projet: Surcharge d'operateur
// Nom du fichier: tp surcharge d'operateur
// Version : 1.0
// Nom du programmeur: Baptiste Puibusque
// Date de création :22/03/2021
// Rôle du fichier: code des fonctions de la classe CDate
// Nom des composants utilises: CDate.h
// Historique du fichier:
/*************************************************/

#include "../include/CDate.h"


// Nom : CDate
// Rôle : Constructeur de la classe
// Paramètres d'entrée : jour, mois, annee, heure, minutes, seconde
CDate::CDate(int jour, int mois, int annee, int heure, int minutes, int secondes)
{
    this->m_jour = jour;
    this->m_mois = mois;
    this->m_annee = annee;
    this->m_heure = heure;
    this ->m_minutes = minutes;
    this->m_secondes = secondes;

}

// Nom : ==
// Rôle : operateur qui verifie si deux dates sont egales ou non
// Paramètres d'entrée/sortie : Une date constante passe par reference
// Valeur de retour : booleen (true ou false)
bool CDate::operator == (const CDate & Date){
    bool condition = false;

    if((this->m_annee == Date.m_annee) && (this->m_mois == Date.m_mois)
       && (this->m_jour == Date.m_jour)&& (this->m_heure == Date.m_heure)
       && (this->m_minutes == Date.m_minutes) && (this->m_secondes == Date.m_secondes)){
            condition= true;
    }

    return condition;

}


//Nom : >
//Rôle : Compare deux dates(infériorité)
//Paramètres entree/sortie : date constante par ref
//Retour : booleen
bool CDate::operator>(const CDate & Date){
    bool condition = true;

    if((this->m_annee < Date.m_annee)
       || (this->m_annee == Date.m_annee && this->m_mois < Date.m_mois)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour < Date.m_jour)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure < Date.m_heure)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure == Date.m_heure
           && this->m_minutes < Date.m_minutes)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure == Date.m_heure
           && this->m_minutes == Date.m_minutes && this->m_secondes < Date.m_secondes)){

            return condition;
                        }
}

//Nom : <
//Rôle : Compare deux dates(infériorité)
//Paramètres entree/sortie : date constante par ref
//Retour : booleen

bool CDate::operator<(const CDate & Date){
    bool condition = true;

    if((this->m_annee < Date.m_annee)
       || (this->m_annee == Date.m_annee && this->m_mois > Date.m_mois)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour > Date.m_jour)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure > Date.m_heure)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure == Date.m_heure && this->m_minutes > Date.m_minutes)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heure == Date.m_heure && this->m_minutes == Date.m_minutes && this->m_secondes > Date.m_secondes)){
        condition = false;

    return condition;

    }
}

// Nom : getDate
// Rôle : attribue a des valeurs par reference les attributs de la date courante
// Paramètres de sortie : jour, mois, annee, heure, minute, seconde
void CDate::getDate(int &jour, int &mois, int &annee, int &heure, int &minute, int &seconde){
    jour = this->m_jour;
    mois = this->m_mois;
    annee = this->m_annee;
    heure = this->m_heure;
    minute = this ->m_minutes;
    seconde = this->m_secondes;
}

// Nom : anneeBisextile
// Rôle : renvoie true si l'annee de la date courante est bisextile et false sinon
// Valeur de retour : booleen (true ou false)
void CDate::operator++(){
    if(this->m_secondes !=59){
        this->m_secondes= (this->m_secondes)+1;
    }else if(this->m_mois == 12 && this->m_jour == 31 && this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_annee)++;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
        this->m_mois=1;
        this->m_jour=1;
    }else if(this->m_jour==31 && this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
    }else if(this->jourDansLeMois()==30 && this->m_jour==30 && this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
    }else if(this->anneeBisextile()==false && this->m_mois==2 && this->m_jour==28 && this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
    }else if(this->m_mois==2 && this->m_jour==29 && this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
    }else if(this->m_heure==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_jour)++;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heure=0;
    }else if(this->m_minutes==59 && this->m_secondes==59){
        this->m_secondes=0;
        this->m_minutes=0;
        (this->m_heure)++;
    }else{
        this->m_secondes=0;
        (this->m_minutes)++;
    }
}


// Nom : jourDansLeMois
// Rôle : renvoie le nombre de jour dans le mois de la date courante
// Valeur de retour : entier qui represente le nombre de jours
bool CDate::anneeBisextile(){
    if((this->m_annee/4)*4 == this->m_annee)
    {
        if((this->m_annee/100)*100 == this->m_annee)
        {
            if((this->m_annee/400)*400 == this->m_annee)
                {
                    return true;
                }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }

}


// Nom : ++
// Rôle : operateur qui ajoute 1 seconde a la date courante
int CDate::jourDansLeMois(){
    switch(this->m_mois)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        return 31;
        break;
    case 4:case 6:case 9: case 11 :
        return 30;
        break;
    case 2:
        {
            if(this->anneeBisextile()== false)
            {
                return 28;
            }
            else
            {
                return 29;
            }
            break;
        }
    }
}
