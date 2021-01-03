#include <stdio.h>
#include <stdlib.h>

#define N 4
#define OBJECTIF 32

void initGrille(int grille[N][N])
{
	int i,j;
	
	for (i=0 ; i<N ; i++)
		for (j=0 ; j<N ; j++)
			grille[i][j] = 0;
}

void afficheGrilleProvisoire(int grille[N][N])
{
	int i,j;
	
	printf("\n");	
	for (i=0 ; i<N ; i++)
	{
		for (j=0 ; j<N ; j++)
			if (grille[i][j] != 0)
				printf("%d\t",grille[i][j]);
			else
				printf(".\t");	
		printf("\n");	
	}
}

void metUn2DansLaGrille(int grille[N][N])
{
	int i,j; 
	//il faut choisir une case vide de façon aléatoire
	//on calcule i et j tant que que grille[i][j] n'est pas vide 
	do 
	{
		i = rand()%N ;
		j = rand()%N ; 
	} while (grille[i][j] != 0);
	grille[i][j] = 2; 
}

 
char saisieDirection(void)
{
	char c;
	
	do
	{
		scanf("%c",&c);
	} while (c!='4' &&  c!='2' && c!='6' && c!='8');
	
	// je sors de la boucle quand c=='4' ou c=='8' .... 	
	
	return c;
}

void copieGrille(int grille[N][N], int copie[N][N])
{
	int i,j;
	
	for (i=0 ; i<N ; i++)
		for (j=0 ; j<N ; j++)
			copie[i][j] = grille[i][j];
}

void retasseAgauche(int grille[N][N])
{
	int i,j,k;
	int tmp[N][N];
	
	initGrille(tmp);
	
	for (i=0 ; i<N ; i++)
	{
		k = 0;
		for (j=0 ; j<N ; j++)
		{	
			if (grille[i][j] != 0)
			{
				tmp[i][k] = grille[i][j];
				k++;
			}
		}
	}
	
	copieGrille(tmp,grille);
}


void retasseAdroite(int grille[N][N])
{
	int i,j,k;
	int tmp[N][N];
	
	initGrille(tmp);
	for (i=0 ; i<N ; i++)
	{
		k = N-1;
		for (j=N-1 ; j>=0 ; j--)
		{
			if (grille[i][j] != 0)
			{
				tmp[i][k] = grille[i][j];
				k--;
			}	
		}
	}
	copieGrille(tmp,grille);
}

void retasseEnHaut(int grille[N][N])
{
	int i,j,k;
	int tmp[N][N];
	
	initGrille(tmp);
    for (j=0 ; j<N ; j++)
    {
		k=0;
		for (i=0 ; i<N ; i++)
		{
			if (grille[i][j] != 0)
			{
				tmp[k][j] = grille[i][j];
				k++;
			}	
		}
	}

	copieGrille(tmp,grille);
}

void retasseEnBas(int grille[N][N])
{
	int i,j,k;
	int tmp[N][N];
	
	initGrille(tmp);
	
	for (j=0 ; j<N ; j++)
    {
		k=N-1;
		for (i=N-1 ; i>=0 ; i--)
		{
			if (grille[i][j] != 0)
			{
				tmp[k][j] = grille[i][j];
				k--;
			}	
		}
	}
	copieGrille(tmp,grille);
}

void additionAgauche(int grille[N][N])
{
	int i,j;
	
	for (i=0 ; i<N ; i++)
	{
		for (j=0 ; j<N-1 ; j++)
		{
			if (grille[i][j]==grille[i][j+1])
			{
				grille[i][j] = grille[i][j]+grille[i][j+1];
				grille[i][j+1] = 0;
			}
		}
	}
}
void additionAdroite(int grille[N][N])
{
	int i,j;
	
	for (i=0 ; i<N ; i++)
	{
		for (j=N-1 ; j>0 ; j--)
		{
			if (grille[i][j]==grille[i][j-1])
			{
				grille[i][j] = grille[i][j]+grille[i][j-1];
				grille[i][j-1] = 0;
			}
		}
	}
}

void additionEnHaut(int grille[N][N])
{
	int i,j;
	
	for (j=0 ; j<N ; j++)
	{
		for (i=0 ; i<N-1 ; i++)
		{
			if (grille[i][j]==grille[i+1][j])
			{
				grille[i][j] = grille[i][j]+grille[i+1][j];
				grille[i+1][j] = 0;
			}
		}
	}
}

void additionEnBas(int grille[N][N])
{
	int i,j;
	
	for (j=0 ; j<N ; j++)
	{
		for (i=N-1 ; i>0 ; i--)
		{
			if (grille[i][j]==grille[i-1][j])
			{
				grille[i][j] = grille[i][j]+grille[i-1][j];
				grille[i-1][j] = 0;
			}
		}
	}
}


int finJeu(int grille[N][N])
{
	//retourne 1 si gagné 
	//retourne -1 si on peut continuer
	//retourne 0 si perdu 
	int i,j,nbVides=0;
	
	for (i=0 ; i<N ; i++)
		for (j=0 ; j<N ; j++)
		{
			if (grille[i][j]==OBJECTIF)
				return 1; 
			if (grille[i][j]==0)
					nbVides++; 
		}
	printf("nbVides %d \n",nbVides);	
	if (nbVides != 0)
		return -1;
	else
		return 0 ;  // faux 		
	
}

int main(void)
{
	int grille[N][N],finDeJeu;
	char direction;

	finDeJeu = -1; //le jeu n'est pas fini
	initGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	
	//while (finJeu(grille) == -1)
	
	while (finDeJeu == -1)
	{
		//pour la version finale 
		system("clear");
		afficheGrilleProvisoire(grille);
		direction = saisieDirection();
		switch (direction)
		{
			case '8' : retasseEnHaut(grille);
					   additionEnHaut(grille);
					   retasseEnHaut(grille);
					   break;
			case '2' : retasseEnBas(grille);
					   additionEnBas(grille);
					   retasseEnBas(grille);
					   break;
			case '4' : retasseAgauche(grille);
					   additionAgauche(grille);
					   retasseAgauche(grille);
					   break;
		    case '6' : retasseAdroite(grille);
					   additionAdroite(grille);
					   retasseAdroite(grille);
					   break;			   		   		   
		}
		metUn2DansLaGrille(grille);
		finDeJeu = finJeu(grille);
	}
	if (finDeJeu==1)
	{
		afficheGrilleProvisoire(grille);
		printf("Gagne ! \n");
	}
	else
	{
		afficheGrilleProvisoire(grille);
		printf("Perdu ! \n");
	}
}	                                                                                

/*
int main(void)
{
	int grille[N][N];
	//int copie[N][N];
	//int i;
	//char ch;
	initGrille(grille);
	
	//afficheGrilleProvisoire(grille);
	
	for (i=1 ; i<=15 ; i++)
	{
		metUn2DansLaGrille(grille);
		afficheGrilleProvisoire(grille);
    }
	
	
	//ch = saisieDirection(); 
	//printf("caractere saisi : %c\n",ch);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	metUn2DansLaGrille(grille);
	afficheGrilleProvisoire(grille);
	//copieGrille(grille,copie);
	//afficheGrilleProvisoire(copie);
	//retasseAgauche(grille);
	//retasseAdroite(grille);
	//retasseEnHaut(grille);
	retasseEnBas(grille);
	afficheGrilleProvisoire(grille);
	additionEnBas(grille);
	afficheGrilleProvisoire(grille);
	retasseEnBas(grille);
	afficheGrilleProvisoire(grille);
	printf("fin jeu %d\n",finJeu(grille));
}

*/
