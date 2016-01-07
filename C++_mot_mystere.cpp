#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string melangerLettres(string mot)
{
   string melange;
   int position(0);
   while (mot.size() != 0)
   {
      position = rand() % mot.size();
      melange += mot[position];
      mot.erase(position, 1);
    }

   return melange;
}
string piocherMotMystere() // Fonction pour piocher au hasard un mot dans le dico et qui renvoit le mot piocher.
{
    string motMystere;
    ifstream dico("dico.txt"); // Ouverture du flux pour lire le dico.
    dico.seekg(0,ios::end); // On se place à la fin du dico.

    int tailleDico, positionDico=0;
    tailleDico=dico.tellg(); // Le curseur est à la fin du dico, donc sa valeur nous indique la taille du dico.

    positionDico =rand() % tailleDico; // On prend une position au hasard dans le dico modulo la taille du dico pour ne pas être en dehors de celui-ci.
    dico.seekg(positionDico,ios::beg); // On se place à cette position calculée au hasard.
    getline(dico,motMystere); // On récupère la fin de la ligne à partir du curseur et celui-ci est alors en fin de ligne. On obtient un fragment de mot, mais cela nous permet de nous placer en début de ligne suivante.
    getline(dico,motMystere); // On récupère alors une deuxième fois la valeur de la ligne, mais cette fois-ci on est en début de ligne et on récupère toute la ligne donc un mot en entier.
    return motMystere; // On utilise getline() pour récupérer le mot mystère car le dico contient un mot par ligne. On doit s'adapter à la mise en forme du dico.
}

int main()
{
   string motMystere, motMelange, motUtilisateur;
   int continuer =1;
   srand(time(0));
   cout << "Bienvenue dans le jeu du mot mystere !"<<endl;

   while (continuer==1) // Boucle while permettant de relancer le programme autant de fois que le joueur veut rejouer.
   {
       int nombreEssaisMax=10; // Initialisation du nombre de coups maximum.
       motMystere=piocherMotMystere(); // On pioche au hasard un mot mystère dans le dico.
       motMelange = melangerLettres(motMystere); // On mélange ce mot mystère.

       do
       {
          cout << endl << "Quel est ce mot ? " << motMelange << endl;
          cin >> motUtilisateur;

          if (motUtilisateur == motMystere)
          {
             cout << "Bravo !" << endl;
             cout << "Voulez-vous refaire une partie ?" << endl;
             cout << "Taper 1 pour rejouer et 0 pour arreter: "; // On propose au joueur de rejouer.
             cin >> continuer; // On stocke la réponse du joueur dans la variable continuer qui est la condition de la boucle while précédente.
          }
          else
          {
             cout << "Ce n'est pas le mot !" << endl;
             --nombreEssaisMax;// Le joueur s'est trompé, on lui retire une vie.
             if (nombreEssaisMax==0) // Le joueur n'a plus de vie.
             {
                motUtilisateur = motMystere;// Egalité afin de sortir de la boucle do while et donc de pouvoir recommencer à jouer si le joueur le souhaite.
                cout <<"Vous avez perdu :( Le mot mystere etait: " <<motMystere<< " !" << endl;
                cout << "Voulez-vous refaire une partie ?" << endl;
                cout << "Taper 1 pour rejouer et 0 pour arreter: "; // On propose au joueur de rejouer.
                cin >> continuer;  // On stocke la réponse du joueur dans la variable continuer qui est la condition de la boucle while précédente.
             }
             else
                 cout <<"Il vous reste "<< nombreEssaisMax << " essais !" << endl; // S'il reste des vies au joueur, on affiche ses vies avant de le prochain tour.
          }
       }while (motUtilisateur != motMystere);
   }
    return 0;
}
