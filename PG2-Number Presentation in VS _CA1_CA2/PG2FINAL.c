#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// fonction prend un entier signee et donne sa representation en VS
void VS(int nb, int n) {
    char nbrchar[16]; // tableau de caractères ou on va stocker le nombre en binaire
    int i = 0, j = 0;
    int signe = 0;// indicateur de signe 
	int y,u,k;
    if (nb < 0) {
        nb = nb * (-1);// rendre le nombre négatif vers positif
        signe++;//incrémentation de l'indicateur pour rappeler que le nombre était négatif
    }
    //conversion du b10 au b2 et stocker le resultat dans un tableau de caractères
    for(i=0; i<8; i++) {
        nbrchar[i] = nb % 2 + '0'; // Convertir en caractères '0' ou '1'
        nb = nb / 2;
    }
    //conversion de int vers char
    char verschar[2] = {'0', '1'};

    for ( y = 0; y < i; y++) {
        nbrchar[y] = verschar[nbrchar[y] - '0'];//la chaine est inversée
    }

    for (j = 0; j < n; j++) {
        if (j >= i) { //remplie le reste à gauche par 00000 car le nombre est positif
            nbrchar[j] = '0';
        }
    }

    if (signe == 1) {
    	//le  nombre est négatif donc le premier digit sera 1 
        nbrchar[n - 1] = '1';//(n-1) car la chaine est inversée
    }
//on inverse la chaine vers la forme normale
    for ( u = n - 1; u >= 0; u--) {
        printf("%c", nbrchar[u]);
    }
    printf("\n");
}
//fonction qui permet de faire une représentation par complément à 1
void CA1(long int nb, int n) {
    char nbrchar[16];//tableau de caractères ou on va stocker le nombre en binaire
    int i = 0, j = 0;// indicateur de signe
    int signe = 0;
	int y,u,k;
	//verification de signe
    if (nb < 0) {
        nb = (pow(2, n) - 1) + nb;
        signe++;//incrémentation de l'indicateur pour rappeler que le nombre était négatif
    }
//conversion du b10 au b2 et stocker le resultat dans un tableau de caractères
    for (i = 0; nb > 0; i++) {
        nbrchar[i] = nb % 2 + '0'; // Convertir en caractères '0' ou '1'
        nb = nb / 2;
    }
  //i=7 ou i=15//i stocke le nombre d iteration 
	
	//conversion de int vers char
    char verschar[2] = {'0', '1'};

    for ( y = 0; y < i; y++) {
        nbrchar[y] = verschar[nbrchar[y] - '0'];
    }
    //la chaine est inversée
	//
	//remplie le reste à gauche par 00000 car le nombre est positif
    for (j = 0; j < n; j++) {
        if (j >= i && signe == 0) {
            nbrchar[j] = '0';
        }
    }
//on inverse la chaine vers la forme normale
    for ( u = j - 1; u >= 0; u--) {
        printf("%c", nbrchar[u]);
    }
    printf("\n");
}
//fonction qui permet de faire une représentation par complément à 2
void CA2(long int nb, int n) {
    char nbrchar[16];//tableau de caractères ou on va stocker le nombre en binaire
    int i = 0, j = 0;
    int signe = 0;// indicateur de signe
	int y,u,k;
	//verification de signe
    if (nb < 0) {
        nb = pow(2, n) + nb;
        signe++;//incrémentation de l'indicateur pour rappeler que le nombre était négatif
    }
//conversion du b10 au b2 et stocker le resultat dans un tableau de caractères
    for (i = 0; nb > 0; i++) {
        nbrchar[i] = nb % 2 + '0'; // Convertir en caractères '0' ou '1'
        nb = nb / 2;
    }
//conversion de int vers char
    char verschar[2] = {'0', '1'};

    for ( y = 0; y < i; y++) {
        nbrchar[y] = verschar[nbrchar[y] - '0'];
    }
//la chaine est inversée
	//remplie le reste à gauche par 00000 car le nombre est positif
    for (j = 0; j < n; j++) {
        if (j >= i && signe == 0) {
            nbrchar[j] = '0';
        }
    }
//on inverse la chaine vers la forme normale
    for ( u = j - 1; u >= 0; u--) {
        printf("%c", nbrchar[u]);
    }
    printf("\n");
}
// fonction pour verifier que la longeur du nombre entrée est de 8 bits et que 
int checkB(int num) {
    int j, l;
    char nbrchar[160];
    sprintf(nbrchar, "%d", num);
    l = strlen(nbrchar);

    while (num > 0) {
        j = num % 10;

        if ((j != 0 && j != 1) || l != 8) {
            return 2; // Erreur détectée
        }
        num = num / 10;
        if (num == 0 || l == 8) {
            return 3; // Succès
        }
    }
    return 3; // Cas par défaut
}
// Fonction qui fait le traitement de representation d'un nombre SIGNEE en CA2 a un decimal
int CA2_D(char binary[], int SB) {
    int power = pow(2, SB - 1);
    int sum = 0;
int i;
    for ( i = 0; i < SB; ++i) {
        if (i == 0 && binary[i] != '0') {
            sum = power * -1;
        } else {
            sum += (binary[i] - '0') * power;
        }
        power /= 2;
    }

    return sum;
}
// Fonction qui fait le traitement de representation d'un nombre SIGNEE en CA1 a un decimal
int CA1_D(char binary[], int SB) {
    int power = pow(2, SB - 1);
    int sum = 0;
int i;
    for ( i = 0; i < SB; i++) {
        if (i == 0 && binary[i] != '0') {
            sum = power * -1 + 1;
        } else {
            sum += (binary[i] - '0') * power;
        }
        power /= 2;
    }

    return sum;
}
// Fonction qui fait le traitement de representation d'un nombre SIGNEE en VS a un decimal
int VS_D(char binary[], int SB) {
    int power = pow(2, SB - 1);
    int sum = 0;
    int s = 1;
int i;
    for ( i = 0; i < SB; i++) {
        if (i == 0 && binary[i] != '0') {
            sum = 0;
            s = -1;
        } else {
            sum += (binary[i] - '0') * power;
        }
        power /= 2;
    }
    return sum * s;
}

int main() {
    int nbr, q = 1, p, t, v;
    char binaire[8];
    char s;
    int num;

    D: printf("Entrez le type de representation :\n ( 1 ) pour VS\n ( 2 ) pour CA1\n ( 3 ) pour CA2\n ( 4 ) pour Decimal\n");
    scanf("%d", &v);

    if (v == 4) {
        goto B;
    } else if (v == 1 || v == 2 || v == 3){
        Z: printf("Entrez un nombre en binaire (compose de 8 BITS) :\n");
        scanf("%d", &nbr);
        t = checkB(nbr);
        if (t == 2) {
        	printf("Nobmre n'est pas Valide\n");
            goto Z;
        } else {
        	num=nbr;
            snprintf(binaire, sizeof(binaire), "%d", nbr); // Convertir en binaire sous forme de chaîne
            switch (v) {
                case 1:
                    nbr = VS_D(binaire, 8);
                    break;
                case 2:
                    nbr = CA1_D(binaire, 8);
                    break;
                case 3:
                    nbr = CA2_D(binaire, 8);
                    break;
                default:
                    goto D;
                    break;
            }
        }
        goto E;
    } else goto D;

    B: printf("Entrer un nombre entre -128 et 127 :\n");
    scanf("%d", &nbr);
    num=nbr;
    if (nbr < -pow(2, 7) || nbr > (pow(2, 7) - 1)) {
        printf("Le nombre n'est pas valide\n");
        goto B;
    }
    E: printf("Entrez le type de representation souhaite :\n (1) pour VS\n (2) pour CA1\n (3) pour CA2\n (4) pour Decimal\n (5) pour Tous\n");
    scanf("%d", &p);
    switch (p) {
        case 1:
            printf("La representation de %d en VS est : ", num);
            VS(nbr, 8);
            break;
        case 2:
            printf("La representation de %d en CA1 est : ", num);
            CA1(nbr, 8);
            break;
        case 3:
            printf("La representation de %d en CA2 est : ", num);
            CA2(nbr, 8);
            break;
        case 4:
            printf("La representation de %d en Decimal est : %d\n", num, nbr);
            break;
        case 5:
        	printf("La representation de %d en Decimal est : %d \n", num,nbr);
            printf("La representation de %d en VS est : ", num);
            VS(nbr, 8);
            printf("La representation de %d en CA1 est : ", num);
            CA1(nbr, 8);
            printf("La representation de %d en CA2 est : ", num);
            CA2(nbr, 8);
            break;
        default:
            goto E;
            break;
    }

    printf("\n");
    while (q != 0) {
        S: printf("Pour Une Autre Representation tapez C !, Pour RESSAYER tapez R !, Pour QUITTER tapez Q !\n");
        scanf(" %c", &q);
        if (q == 'Q' || q == 'q') {
            printf("FIN DU PROGRAMME\n");
            return 0;
        } else if (q == 'C' || q == 'c') {
            goto E;
        } else if (q == 'R' || q == 'r') {
            goto D;
        } else {
            goto S;
        }
    }
}
