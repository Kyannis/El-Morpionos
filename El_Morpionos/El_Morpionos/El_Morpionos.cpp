// El_Morpionos.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>  
#include <algorithm>

using namespace std;

// Affiche la grille de jeu en fonction du tableau de position
void afficherGrilleDeJeu(string* tableauCoordonne)
{
	string a1, a2, a3, b1, b2, b3, c1, c2, c3;

	a1 = tableauCoordonne[0];
	a2 = tableauCoordonne[1];
	a3 = tableauCoordonne[2];
	b1 = tableauCoordonne[3];
	b2 = tableauCoordonne[4];
	b3 = tableauCoordonne[5];
	c1 = tableauCoordonne[6];
	c2 = tableauCoordonne[7];
	c3 = tableauCoordonne[8];
	
	cout << endl;

	cout << "      A     B     C   " << endl;
	cout << "   -------------------" << endl;
	cout << " 1 |  " << a1 <<"  |  " << b1 << "  |  " << c1 << "  |" << endl;
	cout << "   -------------------" << endl;
	cout << " 2 |  " << a2 <<"  |  " << b2 << "  |  " << c2 << "  |" << endl;
	cout << "   -------------------" << endl;
	cout << " 3 |  " << a3 <<"  |  " << b3 << "  |  " << c3 << "  |" << endl;
	cout << "   -------------------" << endl;

}

// Vérifie si la coordonné entrer na pas déja été entree dans le tableau contenant la position des pions. Retourne True si vide
bool coordoneChoisiLibre(string* tableauCoordonne, string coordonneConcatene)
{
	if (coordonneConcatene == "A1")
	{
		if (tableauCoordonne[0]=="X" || tableauCoordonne[0] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "A2")
	{
		if (tableauCoordonne[1] == "X" || tableauCoordonne[1] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "A3")
	{
		if (tableauCoordonne[2] == "X" || tableauCoordonne[2] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "B1")
	{
		if (tableauCoordonne[3] == "X" || tableauCoordonne[3] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "B2")
	{
		if (tableauCoordonne[4] == "X" || tableauCoordonne[4] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "B3")
	{
		if (tableauCoordonne[5] == "X" || tableauCoordonne[5] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "C1")
	{
		if (tableauCoordonne[6] == "X" || tableauCoordonne[6] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "C2")
	{
		if (tableauCoordonne[7] == "X" || tableauCoordonne[7] == "O")
		{
			return false;
		}
	}
	if (coordonneConcatene == "C3")
	{
		if (tableauCoordonne[8] == "X" || tableauCoordonne[8] == "O")
		{
			return false;
		}
	}

	return true;
}

// Demande et prend la saisie des Coordonnées Lettre puis Chiffre et retourne leurs concatenations en majuscule
string coordonneConcateneMajuscule()
{
	string coordoneeLettre, coordoneeChiffre;
	
	cout << "Entrez une Lettre, puis appuyer 2 fois sur la touche entrer :" << endl;
	getline(cin, coordoneeLettre);
	cin.ignore(1000000, '\n');
	
	cout << "Entrez un Chiffre, puis appuyer 1 fois sur la touche entrer :" << endl;
	cin >> coordoneeChiffre;
	cin.ignore(1000000, '\n');

	string concat = coordoneeLettre + coordoneeChiffre;
	std::transform(concat.begin(), concat.end(), concat.begin(), ::toupper);
	return concat;
}

// Vérifie si toute les cases du tableau de jeu sont remplie Retourne True si vide
bool tableauRemplie(string* tableauCoordonne)
{
	for (int i = 0; i < 9; i++)
	{
		if (tableauCoordonne[i] != "X" || tableauCoordonne[i] != "0")
		{
			// oui il est vide
			return true;
		}
	}

	// non il ne l'est pas
	return false;
}

// Minuteur permet d'afficher un minuteur avec un text
void minuteur(int seconde, string text = "")
{
	for (int i = seconde; i>-1; i--)
	{
		cout << '\r' << text <<" " << i << "s.";
		Sleep(1000);
	}
}

// Retourne l'indice du tableau de jeu vai les coordonné concaténe
int obtenirIndiceTableauViaCoordonneConcatene(string coordonneConcatene)
{
	if (coordonneConcatene == "A1")
	{
		return 0;		
	}
	if (coordonneConcatene == "A2")
	{
		return 1;
	}
	if (coordonneConcatene == "A3")
	{
		return 2;
	}
	if (coordonneConcatene == "B1")
	{
		return 3;
	}
	if (coordonneConcatene == "B2")
	{
		return 4;
	}
	if (coordonneConcatene == "B3")
	{
		return 5;
	}
	if (coordonneConcatene == "C1")
	{
		return 6;
	}
	if (coordonneConcatene == "C2")
	{
		return 7;
	}
	if (coordonneConcatene == "C3")
	{
		return 8;
	}
}

// Ajoute un pion au tableau de position
void ajoutePionAuTableau (string* tableauCoordonne, string joueur, string coordonneConcatene)
{
	// PVE / Hummain
	if (joueur == "H")
	{
		tableauCoordonne[obtenirIndiceTableauViaCoordonneConcatene(coordonneConcatene)] = "X";
	}

	// PVE / IA
	if (joueur == "IA")
	{
		tableauCoordonne[obtenirIndiceTableauViaCoordonneConcatene(coordonneConcatene)] = "O";
	}

	// PVP / Joueur 1
	if (joueur == "J1")
	{
		tableauCoordonne[obtenirIndiceTableauViaCoordonneConcatene(coordonneConcatene)] = "X";
	}

	// PVP / Joueur 2
	if (joueur == "J2")
	{
		tableauCoordonne[obtenirIndiceTableauViaCoordonneConcatene(coordonneConcatene)] = "O";
	}
}

// Attribut une variable a toute les cases du tableau
void attributionVariableTableauDeJeu(string* tableauCoordonne, string contenuCase) 
{
	for (int i = 0; i < 9; i++)
	{
		tableauCoordonne[i] = contenuCase;
	}
}

// Retourne true si il y a une victoire
bool victoire(string* tableauCoordonne, string joueur)
{
	string pion;

	if (joueur == "H" || joueur == "J1")
	{
		pion = "X";
	}

	if (joueur == "IA" || joueur == "J2")
	{
		pion = "O";
	}

	// Cas de Victoire possible

	// 1 -- si a1 a2 a3 sont validé
	if (tableauCoordonne[0] == pion && tableauCoordonne[1] == pion && tableauCoordonne[2] == pion)
	{
		return true;
	}
	// 2 -- si b1 b2 b3 sont validé
	if (tableauCoordonne[3] == pion && tableauCoordonne[4] == pion && tableauCoordonne[5] == pion)
	{
		return true;
	}
	// 3 -- si c1 c2 c3 sont validé
	if (tableauCoordonne[6] == pion && tableauCoordonne[7] == pion && tableauCoordonne[8] == pion)
	{
		return true;
	}
	// 4 -- si a1 b1 c1 sont validé
	if (tableauCoordonne[0] == pion && tableauCoordonne[3] == pion && tableauCoordonne[6] == pion)
	{
		return true;
	}
	// 5 -- si a2 b2 c2 sont validé
	if (tableauCoordonne[1] == pion && tableauCoordonne[4] == pion && tableauCoordonne[7] == pion)
	{
		return true;
	}
	// 6 -- si a3 c3 b3 sont validé
	if (tableauCoordonne[2] == pion && tableauCoordonne[5] == pion && tableauCoordonne[8] == pion)
	{
		return true;
	}
	// 7 -- si a1 b2 c3 sont validé
	if (tableauCoordonne[0] == pion && tableauCoordonne[4] == pion && tableauCoordonne[8] == pion)
	{
		return true;
	}
	// 8 -- si a3 b2 a1 sont validé
	if (tableauCoordonne[2] == pion && tableauCoordonne[4] == pion && tableauCoordonne[6] == pion)
	{
		return true;
	}

	return false;
}

// Génére une coordonné pour l'IA.
string coordonneIA(string* tableauCoordonne)
{


	string coordonneIA;

	// tant que la case n'est pas choisit , une autre valeur est généré
	do
	{
		srand(time(NULL));
		int randomInt = rand() % 9 + 1;

		if (randomInt == 1)
		{
			coordonneIA = "A1";
		}
		if (randomInt == 2)
		{
			coordonneIA = "A2";
		}
		if (randomInt == 3)
		{
			coordonneIA = "A3";
		}
		if (randomInt == 4)
		{
			coordonneIA = "B1";
		}
		if (randomInt == 5)
		{
			coordonneIA = "B2";
		}
		if (randomInt == 6)
		{
			coordonneIA = "B3";
		}
		if (randomInt == 7)
		{
			coordonneIA = "C1";
		}
		if (randomInt == 8)
		{
			coordonneIA = "C2";
		}
		if (randomInt == 9)
		{
			coordonneIA = "C3";
		}

	} while (!coordoneChoisiLibre(tableauCoordonne, coordonneIA));
	
	return coordonneIA;
}

void pve(string* tableauCoordonne)
{
	
#pragma region Nom du joueur
	cout << "Vous avez choisit de m'affronter moi une IA.. currieux choix.." << endl;
	cout << "" << endl;
	cout << "" << endl;
	// Demande du nom du joueur
	cout << "Entrez votre nom : " << endl;
	// On efface toutes les saisies antérieures contenus dans le chariot
	cin.ignore(1000000, '\n');
	string cinUserName;
	getline(cin, cinUserName);
	cout << endl;
	cout << "Bonne chance " << cinUserName << " !" << endl;
#pragma endregion

#pragma region Chargement fictif
	// Chargement fictif / Préparation de l'utilisateur
	for (int i = 5; i>-1; i--)
	{
		cout << '\r' << "Preparez vous, la partie va commencer dans " << i << "s.";
		Sleep(1000);
	}
	cout << endl;
	cout << endl;
#pragma endregion

#pragma region Choix du premier joueur
	// Choix aléatoire du premier joueur.
	srand(time(NULL));
	int choixTour = rand() % 2 + 1;

	if (choixTour == 1)
	{
		afficherGrilleDeJeu(tableauCoordonne);
	}
#pragma endregion

	int tour = 1;

	while (tour != 9)
	{
#pragma region Tour Hummain
		// Tour de l'humain
		if (choixTour == 1)
		{
			cout << "C'est a vous de commencer. Entrez la position : " << endl;

			// Récupère la saisie utilisateur des coordonnées et les concatene.
			string coordonneConcatene = coordonneConcateneMajuscule();

			// Tant que les coordonné entrées ne sont pas dispo, on redemande une saisie.
			while (!coordoneChoisiLibre(tableauCoordonne, coordonneConcatene))
			{
				// Ce n'est pas bon donc on reprend de nouvelle coordonné
				cout << "Les coordonnées que vous avez entré corresponde à une case déjà remplie, merci de resaisir des nouvelles coordonnées :" << endl;
				coordonneConcatene = coordonneConcateneMajuscule();
			}

			//Ajoute le pion au tableau de jeu de disposion. Et affiche la grille
			ajoutePionAuTableau(tableauCoordonne, "H", coordonneConcatene);
			afficherGrilleDeJeu(tableauCoordonne);

			
			// Victoire de l'hummain
			if (victoire(tableauCoordonne, "H"))
			{
				cout << "Vous avez gagne !" << endl;
				minuteur(10, "Une nouvelle partie va etre lancer dans");
				pve(tableauCoordonne);
			}

			// Match null 
			// si pas de victoire et tableau plein
			if( !victoire(tableauCoordonne, "H") && !tableauRemplie(tableauCoordonne) )
			{				
				cout << "Il y a match null. Retour au menu principal" << endl;
				minuteur(10, "Une nouvelle partie va etre lancer dans");
				pve(tableauCoordonne);
			}
			

			//Toutes les cases ne sont pas encore remplie, le jeu continue
			else
			{
				minuteur(3, "Good, ca va etre a mon tour");
			}

			choixTour = 2;
			tour++;
		}
#pragma endregion

#pragma region Tour Ordinateur
		// Tour de l'ordinateur
		if (choixTour == 2)
		{
			cout << "C'est a moi Jouer." << endl;
			

			//IA joue
			ajoutePionAuTableau(tableauCoordonne, "IA", coordonneIA(tableauCoordonne));
			afficherGrilleDeJeu(tableauCoordonne);

			// Victoire de l'IA
			if (victoire(tableauCoordonne, "IA"))
			{
				cout << "J'ai gagner !" << endl;
				minuteur(10, "Une nouvelle partie va etre lancer dans");
				pve(tableauCoordonne);
			}

			// Match null 
			// si pas de victoire et tableau plein
			if (!victoire(tableauCoordonne, "IA") && !tableauRemplie(tableauCoordonne))
			{
				cout << "Il y a match null. Retour au menu principal" << endl;
				minuteur(10, "Une nouvelle partie va etre lancer dans");
				pve(tableauCoordonne);
			}


			//// Vérifie si toutes les cases sont remplies
			//if (!tableauRemplie(tableauCoordonne))
			//{
			//	// Victoire de l'hummain
			//	if (victoire(tableauCoordonne, "IA"))
			//	{
			//		afficherGrilleDeJeu(tableauCoordonne);
			//		cout << "Vous avez perdu !" << endl;
			//		minuteur(10, "Une nouvelle partie va etre lancer dans");
			//		pve(tableauCoordonne);
			//	}

			//	// Match null 
			//	else
			//	{
			//		afficherGrilleDeJeu(tableauCoordonne);
			//		cout << "Il y a match null. Retour au menu principal" << endl;
			//		minuteur(10, "Une nouvelle partie va etre lancer dans");
			//		pve(tableauCoordonne);
			//	}
			//}
			

			choixTour = 1;
			tour++;
		}
#pragma endregion

	}


}

void pvp()
{
	cout << "Vous avez choisit d'affronter votre camarade. Vous allez maintenant pouvoir entrer vos pseudos." << endl;
	cout << "" << endl;
	cout << "" << endl;

	string cinUser1Name, cinUser2Name;

	cout << "Entrez le pseudo du joueur n°1 : " << endl;
	getline(cin, cinUser1Name);

	cout << "Entrez le pseudo du joueur n°2 : " << endl;
	getline(cin, cinUser2Name);


	
}

int main()
{
#pragma region Region affichage Start 

	cout << "_  _ ____ ____ ___  _ ____ _  _ ____ ____    ____ ____ _  _ _ _  _ ____ " << endl;
	cout << "|\\/| |  | |__/ |__] | |  | |\\ | |  | [__     | __ |__| |\\/| | |\\ | | __ " << endl;
	cout << "|  | |__| |  \\ |    | |__| | \\| |__| ___]    |__] |  | |  | | | \\| |__] " << endl;
	cout << "                                                                        " << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Mode de Jeux : " << endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "Veuillez taper : " << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "| |     __       | | | |    _____     | |" << endl;
	cout << "| |    /  |      | | | |   / ___ `.   | |" << endl;
	cout << "| |    `| |      | | | |  |_/___) |   | |" << endl;
	cout << "| |     | |      | | | |   .'____.'   | |" << endl;
	cout << "| |    _| |_     | | | |  / /____     | |" << endl;
	cout << "| |   |_____|    | | | |  |_______|   | |" << endl;
	cout << "| |              | | | |              | |" << endl;
	cout << "	PVE		     PVP" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
#pragma endregion


	// Création du tableau contenant les coordonnées
	string tableauCoordonne[9];
	attributionVariableTableauDeJeu(tableauCoordonne, " ");

	// FAIRE UN TRY CATCH POUR LA SAISIE UTILISATEUR

	int cinUser = 0;

	// Choix du mode de JEU
	while (cinUser != 1 && cinUser != 2)
	{
		cin >> cinUser;
		
		// PVE
		if (cinUser == 1)
		{
			pve(tableauCoordonne);
		}

		// PVP
		if (cinUser == 2)
		{
			pvp();
		}
	}


	// empeche la console de se fermer
	int a;
	cin >> a;
    return 0;
}

