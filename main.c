#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5 // déclaration de la constante TAILLE qui donne les dimmension du tableau

typedef struct tJeton
{
	int nX;             //création d'un enregistrement et d'un pointeur d'enregistrement
	int nY;

} tJeton, *ptJeton;
// prototype

int caseVide(int tCarre[TAILLE][TAILLE], ptJeton position);
void avancerDroite(int tCarre[TAILLE][TAILLE], ptJeton position);
void avancerGauche(int tCarre[TAILLE][TAILLE], ptJeton position);
void corriger(int tCarre[TAILLE][TAILLE], ptJeton position);
void placer(int tCarre[TAILLE][TAILLE], ptJeton position, int nCpt);
void afficher(int tCarre[TAILLE][TAILLE]);
void initTab(int tCarre[TAILLE][TAILLE]);
void avancer(int tCarre[TAILLE][TAILLE],ptJeton postion, int nCpt);
// programme principale
int main()
{
    tJeton jeton; // création de la variable du type enregistrement tJeton
    int nCpt;   //
    int tCarre[TAILLE][TAILLE];
    jeton.nX = 1;
    jeton.nY = 2;
    ptJeton *position=&jeton;
    initTab(tCarre);
    tCarre[jeton.nX][jeton.nY] = 1;

    avancer(tCarre,position, nCpt);

    afficher(tCarre);
    return 0;
}
//*********************************************************
//Description:procédure qui initialise le tableau tCarre  a 0
//
//
//Sortie:tableau initialiser a 0
//
//Note:
//
//*******************************************************
void initTab(int tCarre[TAILLE][TAILLE])
{
	for (int nCpt = 0; nCpt < 5; nCpt++)
    {
        tCarre[nCpt][0]=0;
        tCarre[nCpt][1]=0;
        tCarre[nCpt][2]=0;
        tCarre[nCpt][3]=0;
        tCarre[nCpt][4]=0;
    }
}
//*********************************************************
//Description:Fonction qui indique si oui ou non la case du tableau est vide
//
//
//Sortie:elle retourne 1 si la casse est vide sinon retourne 0
//
//Note:
//
//*******************************************************
int caseVide(int tCarre[TAILLE][TAILLE], ptJeton position)
{

	if (tCarre[(*position).nX][(*position).nY] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//*********************************************************
//Description: Enclenche tout les autre procédure dans un boucle
//
//
//Sortie:Elle sort le carré magique complété
//
//Note:
//
//*******************************************************
void avancer(int tCarre[TAILLE][TAILLE],ptJeton position, int nCpt)
{
        for(nCpt = 2; nCpt < (TAILLE*TAILLE+1); nCpt++)
    {
        avancerDroite(tCarre,position);
        corriger(tCarre,position);

        if(caseVide(tCarre,position) == 1)
        {
            placer(tCarre,position, nCpt);
        }
        else
        {
            corriger(tCarre,position);
            avancerGauche(tCarre,position);
            corriger(tCarre,position);
            placer(tCarre,position, nCpt);
        }
    }
}
//*********************************************************
//Description:Procédure qui fais le déplacement nord est
//
//
//Sortie:Donne la position nord est
//
//Note:
//
//*******************************************************
void avancerDroite(int tCarre[TAILLE][TAILLE], ptJeton position)
{
	(*position).nX-=1;
	(*position).nY+=1;

}
//*********************************************************
//Description:Procédure qui fais le déplacement nord ouest
//
//
//Sortie:La position nord ouest
//
//Note:
//
//*******************************************************
void avancerGauche(int tCarre[TAILLE][TAILLE], ptJeton position)
{
	(*position).nX-=1;
	(*position).nY-=1;
}
//*********************************************************
//Description:Procédure qui vérifie si l'on se trouve toujours dans le tableau
//
//
//Sortie:la modification du jeton si hors du tableau
//
//Note:
//
//*******************************************************
void corriger(int tCarre[TAILLE][TAILLE], ptJeton position)
{
    if(((*position).nX) == 5)
    {
        (*position).nX = 0;
    }
    if(((*position).nY) == -1)
    {
        (*position).nY = 4;
    }
    if(((*position).nX) == -1)
    {
        (*position).nX = 4;
    }
    if(((*position).nY) == 5)
    {
        (*position).nY = 0;
    }
}
//*********************************************************
//Description:Procédure qui place la valeur de nCpt dans le tableau
//
//
//Sortie:le tableau est édité
//
//Note:
//
//*******************************************************
void placer(int tCarre[TAILLE][TAILLE], ptJeton position, int nCpt)
{
	tCarre[(*position).nX][(*position).nY] = nCpt;
}
//*********************************************************
//Description:Procédure qui affiche le carré magique
//
//
//Sortie:affichage du carré magique
//
//Note:
//
//*******************************************************
void afficher(int tCarre[TAILLE][TAILLE])
{
    int i, j = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf(" %02d", tCarre[i][j]);
        }
        printf("\n");
    }

}
