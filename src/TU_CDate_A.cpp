//********************************************************
// Auteur : MP Pinaud
// date : 19/03/2021
// fichier: TU_CDate.cpp
// Programme de test unitaire de la classe CDate
// Difficulté A
//********************************************************
#include <iostream>
using namespace std;
#include "../include/CDate.h"



void test_constructeur();
void test_egal();
void test_constructeurSansParametre();
void test_sup();
void test_inf();
void test_incrementerSec();
void saisirDate(int &j, int &m, int &a, int &s, int &mn, int &h);
void afficherDate(CDate &d);

int main ()
{

	int rep;
	do{
        cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Test Constructeur"<<endl;
        cout<<"2. Test Egal"<<endl;
        cout<<"3. Test Constructeur Sans Parametre"<<endl;
        cout<<"4. Test Superieur"<<endl;
        cout<<"5. Test Inferieur"<<endl;
        cout<<"6. Test Incrementer une seconde"<<endl;
        cout<<"0. Quitter"<<endl;
        cout<<"Choix : ";
        cin>>rep;
        cout<<endl;

        system("cls");

        switch(rep){
            case 1: test_constructeur();
                break;
            case 2: test_egal();
                break;
            case 3: test_constructeurSansParametre();
                break;
            case 4: test_sup();
                break;
            case 5: test_inf();
                break;
            case 6: test_incrementerSec();
                break;
            default: cout<<endl<<"Entrez un choix correct : "<<endl;
                break;
        }

        cout<<endl<<endl;

	}while(rep!=0);


	// Coder un menu pour que l'utilisateur choisisse la méthode qu'il veut tester
	// L'utilisateur pourra lancer plusieurs tests à la suite.
	// L'utilisateur saisira 0 pour sortir.

	return 0;
}

//**************************************************************
// Fonction:saisirDate
// Rôle :	permet de saisir les informations d'une date
// Paramètres de sortie : le jour, mois, année, secondes, minutes, heures saisies
//***************************************************************
void saisirDate(int &j, int &m, int &a, int &s, int &mn, int &h)
{
    int boucle = 0;

    while(boucle == 0)
    {
        cout<<"Saisir Jour, Mois, Annee : "<<endl;
        cin>>j>>m>>a;
        cout<<"Saisir Heure, Minute, Seconde: "<<endl;
        cin>>h>>mn>>s;

        CDate date (j,m,a,h,mn,s);

        if(j < 1 || j > 31 || m < 1 || m > 12)
        {
            cout<<"Date invalide veillez entrer une nouvelle date"<<endl;
        }
        else if(j > date.jourDansLeMois())
        {
            cout<<"Date invalide veillez entrer une nouvelle date"<<endl;
        }
        else if( h<1 || h>23 || mn<1 || mn>59 || s<1 || s>59 ){
            cout<<"Date invalide veillez entrer une nouvelle date"<<endl;
        }
        else
        {
            boucle = 1;
        }
    }


}
//**************************************************************
// Fonction:afficherDate
// Rôle :	affiche la date passée en paramètre
// Paramètre d'entrée : la date à afficher
//***************************************************************
void afficherDate (CDate &d)
{
    int jour, mois, annee, heure, minute, seconde;
    d.getDate(jour, mois, annee, heure, minute, seconde);
    cout<<jour<<'/'<<mois<<'/'<<annee<<' '<<heure<<':'<<minute<<':'<<seconde<<endl;

}


//**************************************************************
// Fonction:test_constructeur
// Rôle :	teste le constructeur et affiche la date  à l'aide des méthodes d'accès
//***************************************************************

void test_constructeur()
{
    cout<<endl<<" ----------------------- TEST CONSTRUCTEUR -----------------------"<<endl;
    int jour, mois, annee, heure, minute, seconde;
	saisirDate(jour, mois, annee, seconde, minute, heure);
	CDate date (jour,mois,annee,heure,minute,seconde);
	afficherDate(date);
}

//**************************************************************
// Fonction:test_constructeur
// Rôle :	teste le constructeur sans paramètre de la classe CDate
//***************************************************************

void test_constructeurSansParametre()
{
    cout<<endl<<" ----------------------- TEST CONSTRUCTEUR SANS PARAMETRES -----------------------"<<endl;
	CDate date;
	afficherDate(date);
}

//**************************************************************
// Fonction:test_egal
// Rôle :	teste de l'opérateur == de la classe CDate
//***************************************************************
void test_egal()
{
    cout<<endl<<" ----------------------- TEST EGAL -----------------------"<<endl;
	cout<<"Saisir premiere date :"<<endl;
    int jour, mois, annee, heure, minute, seconde;
	saisirDate(jour, mois, annee, seconde, minute, heure);
	CDate date1 (jour,mois,annee,heure,minute,seconde);


	cout<<"Saisir seconde date :"<<endl;
    int jour2, mois2, annee2, heure2, minute2, seconde2;
	saisirDate(jour2, mois2, annee2, heure2, minute2, seconde2);
	CDate date2 (jour2, mois2, annee2, heure2, minute2, seconde2);

    cout<<"Date 1 : ";
    afficherDate(date1);
    cout<<"Date 2 : ";
    afficherDate(date2);

    if(date1 == date2){
        cout<<"Les dates sont egales"<<endl;
    }else{
        cout<<"Les dates sont differentes"<<endl;
    }

}

//**************************************************************
// Fonction:test_sup
// Rôle :	teste de l'opérateur >  de la classe CDate
//***************************************************************

void test_sup()
{
	cout<<endl<<" ----------------------- TEST SUPERIEUR -----------------------"<<endl;
	cout<<"Saisir premiere date :"<<endl<<endl;
    int jour, mois, annee, heure, minute, seconde;
	saisirDate(jour, mois, annee, seconde, minute, heure);
	CDate date1 (jour,mois,annee,heure,minute,seconde);


	cout<<"Saisir seconde date :"<<endl;
    int jour2, mois2, annee2, heure2, minute2, seconde2;
	saisirDate(jour2, mois2, annee2, heure2, minute2, seconde2);
	CDate date2 (jour2, mois2, annee2, heure2, minute2, seconde2);

    cout<<"Date 1 : ";
    afficherDate(date1);
    cout<<"Date 2 : ";
    afficherDate(date2);

    if(date1 > date2){
        cout<<"Date 1 superieure a Date 2"<<endl;
    }else{
        cout<<"Date 1 n'est pas superieure a Date 2"<<endl;
    }
}


//**************************************************************
// Fonction:test_inf
// Rôle :	teste l'opérateur < de la classe CDate
//***************************************************************

void test_inf()
{
	cout<<endl<<" ----------------------- TEST INFERIEUR -----------------------"<<endl;
	cout<<"Saisir premiere date :"<<endl<<endl;
    int jour, mois, annee, heure, minute, seconde;
	saisirDate(jour, mois, annee, seconde, minute, heure);
	CDate date1 (jour,mois,annee,heure,minute,seconde);


	cout<<endl<<"Saisir seconde date :"<<endl<<endl;
    int jour2, mois2, annee2, heure2, minute2, seconde2;
	saisirDate(jour2, mois2, annee2, heure2, minute2, seconde2);
	CDate date2 (jour2, mois2, annee2, heure2, minute2, seconde2);

    cout<<"Date 1 : ";
    afficherDate(date1);
    cout<<"Date 2 : ";
    afficherDate(date2);

    if(date1 < date2){
        cout<<"Date 1 inferieure a Date 2"<<endl;
    }else{
        cout<<"Date 1 n'est pas inferieure a Date 2"<<endl;
    }
}

//**************************************************************
// Fonction:test_incrementerSec
// Rôle :	teste la  méthode incrémenterSec de la classe CDate
//***************************************************************
void test_incrementerSec()
{
    cout<<endl<<" ----------------------- TEST INCREMENTATION -----------------------"<<endl;
	int compteur;

    int jour, mois, annee, heure, minute, seconde;
	saisirDate(jour, mois, annee, seconde, minute, heure);
	CDate date (jour,mois,annee,heure,minute,seconde);

	cout<<"Combien de seconde a ajouter a cette date ?"<<endl;
	afficherDate(date);
	cin>>compteur;

    for(int i=0; i<compteur; i++){
        date.operator++();
        afficherDate(date);

    }

}

