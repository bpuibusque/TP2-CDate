/*************************************************/
// Nom du projet: Surcharge d'operateur
// Nom du fichier: TU_CDate
// Version : 1.0
// Nom du programmeur: Baptiste Puibusque
// Date de création :22/03/2021
// Rôle du fichier: mTest utnitaire de la classe CDate
// Nom des composants utilises: iostream, CDate.h
// Historique du fichier:
/*************************************************/

#include <iostream>
#include "CDate.h"

#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, time, ctime */

using namespace std;

int main()
{
    CDate date1(12,04,2021,18,45,12);
    CDate date2(28,02,2021,22,45,12);

    if(date1==date2){
        cout<<"Date egales"<<endl;

    }else if(date1>date2){
        cout<<"date1 superieure"<<endl;

    }else{
        cout<<"date 2 superieure"<<endl;
    }

    int jour,mois,annee,heure,minute,seconde;

    date1.getDate(jour,mois,annee,heure,minute,seconde);

    cout<<"date 1 :"<<jour<<'/'<<mois<<'/'<<annee<<' '<<heure<<':'<<minute<<':'<<seconde<<endl;

    date2.getDate(jour,mois,annee,heure,minute,seconde);
    cout<<"date 2 :"<<jour<<'/'<<mois<<'/'<<annee<<' '<<heure<<':'<<minute<<':'<<seconde<<endl;

    date1.operator++();

    date1.getDate(jour,mois,annee,heure,minute,seconde);

    cout<<"date 1 :"<<jour<<'/'<<mois<<'/'<<annee<<' '<<heure<<':'<<minute<<':'<<seconde<<endl;



}
