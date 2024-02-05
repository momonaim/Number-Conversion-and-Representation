#include <stdio.h>
#include <stdio.h>
#include <string.h>
// Fonction pour verifier si le nombre entre est exacte
int check(char *num,int base){
	int temp=atoi(num);
	int v=1;
	while (temp>0){
		int c=temp%10;
		if (c>=base){
			v=0;
			break;
		}
		temp=temp/10;
	}
	return v;
}
// Fonction pour convertir un chiffre en caractère hexadécimal
char int_to_charbit(int nu) {
    if (nu >= 0 && nu <= 9) {
        return (char)('0' + nu); // ici on a met '0' pour ajouter a num le code ASCII 
								 //et le transformer en caractère
								 
    } else {
        return (char)('A' + nu - 10); // meme pour qu'ici ;avec en hexadecimal 
									  //les chiffres devient caractères donc on ajoute 
									  //le num au code ASCII en commencent de A
    }
}

// Fonction pour convertir un caractère hexadécimal en chiffre
int charbit_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return (int)(c - '0');
    } else {
        return (int)(c - 'A' + 10);
    }
}

// Fonction pour convertir un nombre de base A en base 10
int convert10(char *num, int A) {
    int resultat = 0;
    int i;
    int len = strlen(num);
    
    for ( i = 0; i < len; i++) {
        resultat = resultat * A + charbit_to_int(num[i]);
    }
    
    return resultat;
}

// Fonction pour convertir un nombre de base 10 en base B
void conversionB(int num, int B) {
    char resultat[50]; // Tableau pour stocker le résultat
    int i = 0;
	int j;
    while (num > 0) {
        int reste = num % B;
        resultat[i++] = int_to_charbit(reste);
        num = num / B;
    }

    // Afficher le résultat à l'envers
    for ( j = i - 1; j >= 0; j--) {
        printf("%c", resultat[j]);
    }
    printf("\n");
}

int main() {
    char nbr[100];
    int A, B;
    char q;
    int v;

    e: printf("Entrez un nombre : ");
    scanf("%s", nbr);

    printf("Entrez la base du nombre (entre 2 et 16) : ");
    scanf("%d", &A);

    printf("Entrez la base de conversion (entre 2 et 16) : ");
    scanf("%d", &B);

		
    if ((A < 2 || A > 16) || (B < 2 || B > 16)) {
        printf("Les bases doivent être comprises entre 2 et 16.\n");
    } else {
    	//verification de saisie
		v=check(nbr,A);
		if(!v){
			printf("saisie incorrecte!!! le nobmre doit etre dans la base %d\n",A);
			goto e;
		}
        int valeurdecimal = convert10(nbr, A);
        printf("Le nombre converti en base %d : ", B);
        conversionB(valeurdecimal, B);
    }
    
   
    	printf("\n\t pour QUITTER tappez Q ! \n");
		printf(" \t pour CONTINUER tappez une touche differente de Q ! \n");
    	scanf("%s",&q);
    	if (q=='Q'||q=='q') {printf("\t FIN PROGRAMME \n");
    	return 0;
		}else
    	goto e;
	 
	

    return 0;
}
