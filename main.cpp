#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

int nombreDeLigneC(string cas) // entrez ville ou pays ou villeEncod ou paysEncod en fonction du fichiers a utiliser
{
    ifstream ville("dat/capitales/ville.dat" ,ios::app);
    ifstream pays("dat/capitales/pays.dat" ,ios::app);
    ifstream villeEncod("dat/capitales/villeEncod.dat",ios::app);
    ifstream paysEncod ("dat/capitales/paysEncod.dat",ios::app);
    int nbrl (0);
    double position (0),taille(0);
    string ligne;
    if(ville&&pays&&villeEncod&&paysEncod)
    {
        nbrl=0;
        if (cas=="ville")
        {
            ville.seekg(0,ios::end);
            taille=ville.tellg();
            ville.seekg(0, ios::beg);
            do
            {
                getline (ville, ligne);
                position=ville.tellg();
                nbrl++;
            }
            while(position<taille);

        }
        else if(cas=="pays")
        {

            pays.seekg(0,ios::end);
            taille=pays.tellg();
            pays.seekg(0, ios::beg);
            do
            {
                getline (pays, ligne);
                position=pays.tellg();
                nbrl++;
            }
            while(position<taille);

        }
        else if(cas=="villeEncod")
        {
            villeEncod.seekg(0,ios::end);
            taille=villeEncod.tellg();
            villeEncod.seekg(0, ios::beg);
            if(taille<2)
                {
                    cout<<"Il n'y a aucune capitale encodee ! Pour un bon fonctionnement du programme\nveuillez encoder des capitales."<<endl;
                    return -1;
                }
            else
                do
                {
                    getline (villeEncod, ligne);
                    position=villeEncod.tellg();
                    nbrl++;
                }
                while(position<taille);
        }
        else if(cas=="paysEncod")
        {
            paysEncod.seekg(0,ios::end);
            taille=paysEncod.tellg();
            paysEncod.seekg(0, ios::beg);
            do
            {
                getline (paysEncod, ligne);
                position=paysEncod.tellg();
                nbrl++;
            }
            while(position<taille);
        }
        else
            nbrl=-1;

    }
    else
        cout<<"ERREUR. Contactez le programeur."<<endl<<endl;
    return nbrl;
}

int nombreDeLigneV(string cas) // entrez francais ou langue ou francaisEncod ou langueEncod
{
    ifstream langue("dat/verbes/langue.dat" ,ios::app);
    ifstream francais("dat/verbes/francais.dat" ,ios::app);
    ifstream langueEncod("dat/verbes/langueEncod.dat",ios::app);
    ifstream francaisEncod ("dat/verbes/francaisEncod.dat",ios::app);
    int nbrl (0);
    double position (0),taille(0);
    string ligne;
    if(langue&&francais&&langueEncod&&francaisEncod)
    {
        nbrl=0;
        if (cas=="langue")
        {
            langue.seekg(0,ios::end);
            taille=langue.tellg();
            langue.seekg(0, ios::beg);
            do
            {
                getline (langue, ligne);
                position=langue.tellg();
                nbrl++;
            }
            while(position<taille);

        }
        else if(cas=="francais")
        {

            francais.seekg(0,ios::end);
            taille=francais.tellg();
            francais.seekg(0, ios::beg);
            do
            {
                getline (francais, ligne);
                position=francais.tellg();
                nbrl++;
            }
            while(position<taille);

        }
        else if(cas=="langueEncod")
        {
            langueEncod.seekg(0,ios::end);
            taille=langueEncod.tellg();
            langueEncod.seekg(0, ios::beg);
            if(taille<2)
                cout<<"Il n'y a aucune capitale encodee ! Pour un bon fonctionnement du programme\nveuillez encoder des verbes."<<endl;
            else
                do
                {
                    getline (langueEncod, ligne);
                    position=langueEncod.tellg();
                    nbrl++;
                }
                while(position<taille);
        }
        else if(cas=="francaisEncod")
        {
            francaisEncod.seekg(0,ios::end);
            taille=francaisEncod.tellg();
            francaisEncod.seekg(0, ios::beg);
            do
            {
                getline (francaisEncod, ligne);
                position=francaisEncod.tellg();
                nbrl++;
            }
            while(position<taille);
        }
        else
            nbrl=-1;

    }
    else
        cout<<"ERREUR. Contactez le programeur."<<endl<<endl;
    return nbrl;
}

int nombreDeLigneF(int cas) //2=> titres
{

        ifstream liste("dat/films/liste.dat" ,ios::app);

    int nbrl (0);
    double position (0),taille(0);
    string ligne;
    if(liste)
    {
        nbrl=0;

            liste.seekg(0,ios::end);
            taille=liste.tellg();
            liste.seekg(0,ios::beg);
            do
            {
                getline (liste, ligne);
                if(liste.tellg()!=-1)
                    position=liste.tellg();
                nbrl++;
            }
            while(position<taille-4);

    }
    else
        cout<<endl<<"error no dat/films/liste.dat found"<<endl;
    if (cas == 2)
    {
        nbrl=0;position=0;taille=0;
        ifstream titres("dat/films/titres.dat" ,ios::app);
        titres.seekg(0,ios::end);
            taille=titres.tellg();
            titres.seekg(0, ios::beg);
            do
            {
                getline (titres, ligne);
                position=titres.tellg();
                nbrl++;
            }
            while(position<taille);
            titres.close();

    }

        liste.close();
    return nbrl;
}


void copierLesFichiersC() //Routine qui va copier le contenu des dossiers encodés dans ceux du jeu (pour le jeu des capitales capitales).
{
    ifstream villeEncod ("dat/capitales/villeEncod.dat", ios::app);
    ifstream paysEncod ("dat/capitales/paysEncod.dat", ios::app);
    ofstream ville("dat/capitales/ville.dat");
    ofstream pays("dat/capitales/pays.dat");
    string ligne;
    int cptr(nombreDeLigneC("villeEncod"));
    if(ville&&villeEncod&&pays&&paysEncod)
    {
        villeEncod.seekg(0,ios::beg);
        paysEncod.seekg(0,ios::beg);
        do
        {

            getline(villeEncod,ligne);
            ville<<ligne<<endl;
            getline(paysEncod,ligne);
            pays<<ligne<<endl;
            cptr--;

        }while(cptr>=1);
    }
    else
        cout<<"ERREUR. Contactez le programeur."<<endl;

}

void copierLesFichiersV() // routine copie pour le jeu des verbes
{
    ifstream langueEncod (" dat/verbes/langueEncod.dat", ios::app);
    ifstream francaisEncod (" dat/verbes/francaisEncod.dat", ios::app);
    ofstream langue("dat/verbes/langue.dat");
    ofstream francais("dat/verbes/francais.dat");
    string ligne;
    int cptr(nombreDeLigneV("langueEncod"));
    if(langue&&langueEncod&&francais&&francaisEncod)
    {
        langueEncod.seekg(0,ios::beg);
        francaisEncod.seekg(0,ios::beg);
        do
        {

            getline(langueEncod,ligne);
            langue<<ligne<<endl;
            getline(francaisEncod,ligne);
            francais<<ligne<<endl;
            cptr--;

        }while(cptr>=1);
    }
    else
        cout<<"ERREUR. Contactez le programeur."<<endl;

}

void copierLesFichiersF()// "  "  "   jeu des films
{
    ifstream liste ("dat/films/liste.dat", ios::app);

    ofstream titres("dat/films/titres.dat");
    ofstream dates("dat/films/dates.dat");
    ofstream reals("dat/films/reals.dat");
    string ligne;
    int cptr=nombreDeLigneF(0)/3;
    if(liste&&titres&&dates&&reals)
    {
        liste.seekg(0,ios::beg);

        do
        {

            getline(liste,ligne);
            titres<<ligne<<endl;
            getline(liste,ligne);
            reals<<ligne<<endl;
            getline(liste,ligne);
            dates<<ligne<<endl;


            cptr--;

        }while(cptr>=1);
    }
    else
        cout<<"ERREUR. Contactez le programeur."<<endl;
    liste.close();titres.close();reals.close();dates.close();

}

void Erase_Line(char* File, int Line_to_Erase)
{
    std::string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile( File);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while ( std::getline( ReadFile, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if(Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile( File ); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}

void effacerListe(char* File) //entrez le "chemin relatif du fichier a nettoyer"
{
    ofstream flux(File);
    flux<<"";
}

int  SetDifficulty(bool Hard)
{
    ofstream flux ("dat/filmsDiff.dat",ios::trunc);
    if(flux)
    {
        flux.put(Hard);
        flux.close();
        return 0;
    }
    else
    {
        cout<<"Woops ... il semblerait qu'il y ait un probleme."<<endl;
        flux.close();
        return -1;
    }
}


bool getDifficulty()
    {
        bool diff=0;
        ifstream flux ("dat/filmsDiff.dat");
        if(flux)
        {
            flux >> diff;
            flux.close();
            return diff;
        }
        else
        {
            cout<<"Woops ... il semblerait qu'il y ait un probleme. Difficultee desactivee par defaut."<<endl;
            flux.close();
            return 0;
        }
    }

/*Ajout pour la version2 : menu princ encodages en un cas ; option difficulté films(Besoin et précision de la date); Bug : cin espace;*/
int main ( int argc, char** argv )
{
    //printf( "Monkey Studio Rocks!!!" );

    cout << "......................................................" << endl;
    cout << "______________________________________________________" << endl;
    cout << "-Bienvenue dans le programme d'aide a la memorisation-" << endl;
    cout << "______________________________________________________" << endl;
    cout << "......................................................" << endl;

    string replay("encore");
    srand(time(NULL));
    int mode(0);
    do
    {
        cout<<endl<<endl<<endl<<" Entre 1 pour jouer aux capitales."<<endl;
                            cout<<" Entre 2 pour jouer aux verbes irreguliers." <<endl;
                            cout<<" Entre 3 pour encoder des verbes irreguliers."<<endl;
                            cout<< " Entre 4 pour encoder des capitales."<<endl;
                            cout<<" Entre 5 pour jouer aux films"<<endl;
                            cout<<" Entre 6 pour acceder aux options."<<endl;
                            cout<<" Entre 9 pour quiter."<<endl;
        cin>>mode;

        switch(mode)
        {
        case 1: //mode capitales          V
        {

            cout <<"-----------------------"<<endl;
            cout <<"---JEU DES CAPITALES---"<<endl;
            cout <<"-----------------------"<<endl<<endl<<endl;
            cout <<"Attention a la synthaxe ! (Les capitales commencent par une majuscule et ne se \nterminent pas par un espace ! )"<<endl<<endl;
            ifstream ville("dat/capitales/ville.dat",ios::app );
            ifstream pays("dat/capitales/pays.dat",ios::app );
            if(ville&&pays&&nombreDeLigneC("villeEncod")>2)
            {

                string capdev("xxx"),cap,pa;//la proposition du joueur, la capitale de la ligne, le pays de la ligne
                int ligne(1),cptr(0);
                char r('r');
                copierLesFichiersC();
                if(nombreDeLigneC("ville")!=-1)
                {
                    cout<<ligne;
                    do//boucle de jeu
                    {

                        ligne=1+rand()%nombreDeLigneC("ville");//donne une ligne au hazard
                        int ligneAEffacer=ligne;
                        ville.seekg(0,ios::beg);
                        pays.seekg(0,ios::beg);
                        while(ligne>1)//boucle de positionement a la ligne selectionnée
                        {
                            getline (ville, cap);
                            getline (pays,cap);

                            ligne--;
                        }

                        getline (ville, cap);
                        getline (pays, pa );
                        cout<<"Quelle est la capitale de (du) la (l') "<<pa<<"?"<<endl;
                        cin>>capdev;
                        if(capdev==cap)
                        {
                            cout<<"Bravo ! Bonne reponse !"<<endl<<endl;
                            Erase_Line("dat/capitales/ville.dat",ligneAEffacer);
                            Erase_Line("dat/capitales/pays.dat",ligneAEffacer);
                            cptr++;

                        }

                        else
                        {
                            cout<<"\aDommage ... Veux tu voir la reponse ? Entre oui ou non."<<endl;
                            string reponse("oui");
                            cin>>reponse;
                            if(reponse=="oui")
                                cout<<"La reponse etait "<<cap<<"."<<endl<<endl;
                            else
                            cout<<endl<<endl;
                        }
                        cout<<"Tape \" r \" pour continuer la partie."<<endl;
                        cin>>r;

                    }
                    while(r=='r'&&cptr!=nombreDeLigneC("villeEncod"));
                }

                else if(nombreDeLigneC("ville")==-1)
                    cout<<"ERREUR. La fonction nombreDeLigneC renvois -1. Contactez Le Programeur."<<endl<<endl;

                if(cptr==nombreDeLigneC("villeEncod"))
                {
                    cout<<"Bravo !!! tu as gagne !!!"<<endl<<endl<<endl;
                    cout<<"          ."<<endl;
                    cout<<"         /|"<<endl;
                    cout<<"        (.)"<<endl;
                    cout<<"        |!|"<<endl;
                    cout<<"        |!|"<<endl;
                    cout<<" ------------------ "<<endl;
                    cout<<"|..................|"<<endl;
                    cout<<"|~~~~~~~~~~~~~~~~~~|"<<endl;
                    cout<<"|..................|"<<endl;
                    cout<<"|__________________|"<<endl;
                }


            }
            else
                cout<<"ERREUR. Fichier inutilisable. Contacter le programeur."<<endl;

            break;
        }
        case 2: //mode verbes irréguliers X
        {
            cout<<"Mode en construction ... Disponible dans une prochaine version !"<<endl;

            break;
        }
        case 3: //mode encod'verbes      ~V~
        {
            ofstream langueEncod ("dat/verbes/langueEncod.dat", ios::app);
            ofstream francaisEncod ("dat/verbes/francaisEncod.dat", ios::app);
            if(langueEncod&&francaisEncod)
            {
                cout <<"_______________________"<<endl;
                cout <<"__ENCODAGE DE VERRBES__"<<endl;
                cout <<"_______________________"<<endl<<endl;
                cout <<"Exemple d'encodage :\nEntrez le verbe en francais\ndire\nEntrez les formes dans la langue etrangere (Attention a la synthaxe: il faut \nseparer chaque mot par un \"-\" et remplacer les espaces par ce meme caractere).\ntell-told-told"<<endl<<endl;
                char r('r');
                string french,other;
                do
                {
                    cout<<"Entrez le verbe en francais"<<endl;
                    cin>> french ;
                    francaisEncod <<french<<endl;
                    cout<<"Entrez les formes dans la langue etrangere (Attention a la synthaxe: il faut \nseparer chaque mot par un \"-\" et remplacer les espaces par ce meme caractere)."<<endl;
                    cin>> other;
                    langueEncod <<other<<endl;
                    cout<<"Entrez \"r\" pour encoder une nouvelle capitale."<<endl;
                    cin>>r;
                    cout<<endl<<endl;
                }
                while(r=='r');
            }
            else
                cout<<"ERREUR. Contacter le programeur."<<endl;

            break;
        }
        case 4: //mode encod'capitales    V
        {
            ofstream villeEncod ("dat/capitales/villeEncod.dat", ios::app);
            ofstream paysEncod ("dat/capitales/paysEncod.dat", ios::app);
            if(villeEncod&&paysEncod)
            {
                cout <<"_______________________"<<endl;
                cout <<"_ENCODAGE DE CAPITALES_"<<endl;
                cout <<"_______________________"<<endl;
                char r('r');
                string city,country;
                do
                {
                    cout<<"Entrez le nom de la capitale. (Attention a la synthaxe: Majuscule au debut, pas d'espace a la fin)."<<endl;
                    cin>> city ;
                    villeEncod <<city<<endl;
                    cout<<"Entrez le nom du pays. (Attention a la synthaxe: Majuscule au debut, pas\n d'espace a la fin)."<<endl;
                    cin>> country;
                    paysEncod <<country<<endl;
                    cout<<"Entrez \"r\" pour encoder une nouvelle capitale."<<endl;
                    cin>>r;
                    cout<<endl<<endl;
                }
                while(r=='r');
            }
            else
                cout<<"ERREUR. Contacter le programeur."<<endl;
            break;

        }
        case 5: //mode films               V
        {
             cout <<"-----------------------"<<endl;
            cout <<"-----JEU DES FILMS-----"<<endl;
            cout <<"-----------------------"<<endl<<endl<<endl;



                bool difficult = getDifficulty();
                if (difficult==1)
                    cout<<"La difficulté supérieure est activée."<<endl;
                else
                    cout<<"La difficulté supérieure est désactivée."<<endl;
                string real,titre,realPropose;

                int ligne(1),cptr(0);
                string date,datePropose;
                char r('r');
                copierLesFichiersF();
                ifstream titres("dat/films/titres.dat",ios::app );
                ifstream dates("dat/films/dates.dat",ios::app );
                ifstream reals("dat/films/reals.dat",ios::app );
                if(nombreDeLigneF(2) < 2 )
                {
                    cout<<"Aucun films trouvable ... "<<endl;
                }
                else if(nombreDeLigneF(2)!=-1 && titres && dates && reals)
                {
                    //cout<<ligne;
                    do//boucle de jeu
                    {

                        ligne=1+rand()%nombreDeLigneF(2);//donne une ligne au hazard
                        int ligneAEffacer=ligne;
                        titres.seekg(0,ios::beg);
                        reals.seekg(0,ios::beg);
                        dates.seekg(0,ios::beg);
                        while(ligne>1)//boucle de positionement a la ligne selectionnée
                        {
                            getline (titres, titre);
                            getline (reals,real);
                            getline (dates,date);

                            ligne--;
                        }

                        getline (titres, titre);
                        getline (reals,real);
                        getline (dates,date);
                        cout<<"Qui a realise "<<titre<<"?"<<endl;
                        //cin>>realPropose;
                        getline(cin >> ws, realPropose);//Cette méthode permet de lire l'entrée au clavier sans s'arreter à l'espace
                        if(difficult==1)
                        {
                            cout<<endl<<"Et en Quelle année ?"<<endl;
                            cin>>datePropose;
                        }

                        if((real==realPropose && date==datePropose && difficult==1)||(real==realPropose && difficult==0))
                        {
                            cout<<"Bravo ! Bonne reponse !"<<endl<<endl;
                            Erase_Line("dat/films/titres.dat",ligneAEffacer);
                            Erase_Line("dat/films/reals.dat",ligneAEffacer);
                            Erase_Line("dat/films/dates.dat",ligneAEffacer);
                            cptr++;

                        }

                        else
                        {
                            cout<<"\aDommage ... "<<endl;

                                cout<<"La reponse etait "<<real<<","<<date<<endl<<endl;

                        }
                        cout<<"Tape \" r \" pour continuer la partie."<<endl;
                        cin>>r;

                    }
                    while(r=='r'&&cptr<nombreDeLigneF(1));
                }


                else
                    cout<<"ERREUR MILLE"<<endl<<endl;

                if(cptr==nombreDeLigneF(0)/3)
                {
                    cout<<"Bravo !!! tu as gagne !!!"<<endl<<endl<<endl;
                    cout<<"          ."<<endl;
                    cout<<"         /|"<<endl;
                    cout<<"        (.)"<<endl;
                    cout<<"        |!|"<<endl;
                    cout<<"        |!|"<<endl;
                    cout<<" ------------------ "<<endl;
                    cout<<"|..................|"<<endl;
                    cout<<"|~~~~~~~~~~~~~~~~~~|"<<endl;
                    cout<<"|..................|"<<endl;
                    cout<<"|__________________|"<<endl;
                }



            titres.close();reals.close();dates.close();

            break;
        }
         case 6: // options                V
        {
            int selection;
            cout<<"|.......................|"<<endl;
            cout<<"|........OPTIONS........|"<<endl;
            cout<<"|.......................|"<<endl<<endl<<endl;
            do
            {
              cout<<"\t"<<"1 : Effacer la liste de capitales encodees."<<endl;
              cout<<"\t"<<"2 : Effacer la liste de verbes encodes."<<endl;
              cout<<"\t"<<"3 : Choisir difficultée du mode films."<<endl;
              cout<<"\t"<<"4 : Quiter le menu option."<<endl<<endl;
              cin>>selection;
              switch(selection)
              {
              case 1:
                {
                    effacerListe("dat/capitales/villeEncod.dat");
                    effacerListe("dat/capitales/paysEncod.dat");
                    cout<<"Fichiers nettoyes."<<endl<<endl;
                    break;
                }
              case 2:
                {
                    effacerListe("dat/verbes/langueEncod.dat");
                    effacerListe("dat/verbes/francaisEncod.dat");
                    cout<<"Fichiers nettoyes."<<endl<<endl;
                    break;
                }
              case 3:
                {
                    bool difficile=0;
                    string answ;
                    cout<<"Voulez vous activer la difficulté supérieure (Cela consiste en restituer la date)? oui ou non"<<endl;
                    cin >>answ;
                    if(answ=="oui")
                        difficile=1;
                    else
                        difficile=0;
                    SetDifficulty(difficile);
                }
                case 4:
                {
                    cout<<"___________________"<<endl<<endl<<endl;
                    //break;
                    main(argc,argv);
                }
                default:
                    cout<<"ERREUR. Mode inconnu."<<endl;


              }

            }while(selection!=3);

            break;
        }
        case 9: // quiter                 V
            cout<<endl;
            break;
        default: // erreur
            cout<<"Mode de jeu inconnu."<<endl;
            break;
        }

        if (mode==6)
            cout<<endl;
        else
        {
            cout<<endl<<endl<<endl<<endl<<"Encore envie de jouer ? Tape \" encore \" pour rejouer !"<<endl;
            cin>>replay;
        }
    }
    while(replay=="encore"&&mode!=6);



    return 0;
}
