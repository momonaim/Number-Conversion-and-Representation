#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Fonction qui permet de convertir un nombre reel vers un nombre binaire
void Vfixe (double N){
	//verification de signe
	 if(N<0){
	N=(-1)*N; printf("1 ");} 
	else printf("0 ");
	int A=floor(N);//stocker la partie entiere
	double B=N-A;	//stocker la partie fractinnaire
	double BA=B;
int Z;int *T=malloc(sizeof(int));
int *C=malloc(sizeof(int));
int i=0, j, k = 0;
	while(A != 0) {
		
T=(int*)realloc(T, (i+1)* sizeof(int)); //reallocation de tableau
		//conversion vers binaire
			T[i] =(A%2);
			i++;
			A = A/2;
	}
	while(B!=0) {
	//0.375=?
	// 0.375 x 2 = 0.75
	// 0.75  x 2 = 1.5
	// 0.5   x 2 = 1.0
		C = (int*)realloc(C, (k+1)* sizeof(int));
		C[k]=floor(B);
		Z=floor(B);
		k++;
		if(k==(16)+1) break;
		B=(B-Z)*2;
	}
	//Affichage
		for(j=i-1;j>=0; j--) { 
			printf("%d",T[j]);
		}
printf(".");
	if(BA==0) printf("0");
		for(j=1;j<k; j++) {
		printf("%d",C[j]);
		}
printf("\n");
}
//Fonction qui permet de convertir un nombre binaire vers un nombre reel
void bin_to_fixe(char* num){
	int i,k,s=0;
	long long  int resultat1=0,resultat2=0;
	//l'emplacement de la virgule
	while(num[s]!='.') {
		s++;
	}
	k=s-1;
	//conversion de binaire vers decimal
	for (i=0; i<s; i++) {
		resultat1=resultat1+(num[i]-'0')*pow(2,k);
		k--;
	}
	
	k=-1;//puissance partie fractionnaire
	//conversion de binaire vers decimal
	for (i=s+1; i<strlen(num); i++) {
	resultat2=resultat2+((num[i]-'0')*pow(2,k)*pow(10,strlen(num)-s-1));
	k--;
	}
	//Affichage
	printf("La Coversion  de ");
	for(i=0; i<strlen(num); i++)
		printf("%c",num[i]);
	printf(" est : %lld",resultat1);
	printf(".");
	printf("%lld",resultat2);
    printf("\n");
}
//Fonction pour convertir un nombre decimal en virgule fixe
void V_flottant32 (double N){
	//verification de signe
	 if (N<0) {
	N=N*(-1);
	printf("1 ");
	
	} else printf("0 ");
		
	int A=floor(N),N1=floor(N);//stocker la partie entiere
	double B=N-A, D = N-A;//stocker la partie fractinnaire
	int Z;
	int *T= malloc(sizeof(int));//declaration de tableau
	int *C= malloc(sizeof(int));
	int i = 0, j, k = 0;
		while (A != 0) {
		T = (int*) realloc (T, (i+1) * sizeof (int)); //reallocation de tableau
		//conversion vers binaire
		T[i]=(A%2);
		i++;
		A = A/2;
		}
	while (B != 0) {
	C = (int*) realloc (C, (k+1) * sizeof(int)); floor (B);
	C[k]=floor(B);
	Z=floor(B);
	k++;
	if (k==25) break;
	B = (B-Z)*2;
	}if (N1!=0) {int a =i+126,v=0;//Exposant
	int *P=malloc (8* sizeof (int));
	int *S=malloc (23* sizeof (int));//Exposant to binaire
	while (a != 0) {
	P[v]=(a % 2);
	v++;
	a = a/2;
}
	//Affichage
	for(j=v-1;j>=0;j--) printf("%d", P[j]);
	printf("  ");
for(j=0;j<23;j++) S[j]=0;
for(j=0;j<i-1;j++) S[j]=T[i-j-2];
for(j=1;j<k;j++) S[j+i-2]=C[j];
	for(j=0;j<23;j++) printf("%d",S[j]);
}else {
	if (D ==0){for(j=0;j<=7; j++) printf("0"); 
	printf(" "); for(j=0;j<23; j++) printf("0");
}else{
	 int u;
	for(j=1;j<k; j++) { 
		if (C[j]==1) {u=j; break; }
	}
	int a=-u+127,v=0;
	int *P=malloc (8 *sizeof (int));
	int *S=malloc (23* sizeof (int));
 	for(j=0;j<8;j++) P[j]=0;
	while (a != 0) {
	P[v]=(a % 2);
	v++;
	a = a/2;
	}
for(j=7;j>=0;j--) printf("%d", P[j]);
printf(" ");
for(j=0;j<23;j++) S[j]=0;
for(j=u+1;j<k;j++) S[j- (u+1)]=C[j];
}
}
}
void V_flottant64 (double N){
		//verification de signe
		 if (N<0) {
		N=N*(-1);
		printf("1 ");
		
		} else printf("0 ");
	//stocker la partie entiere
	int A=floor(N),N1=floor(N);
	//stocker la partie fractinnaire
	double B=N-A, D = N-A;int Z;
	int *T= malloc(sizeof(int));
	int *C= malloc(sizeof(int));
	int i = 0, j, k = 0;while (A != 0) {
	T = (int*) realloc (T, (i+1) * sizeof (int)); //reallocation de tableau
T[i]=(A%2);
i++;
A = A/2;
}while (B != 0) {
	//0.375=?
	// 0.375 x 2 = 0.75
	// 0.75  x 2 = 1.5
	// 0.5   x 2 = 1.0
C = (int*) realloc (C, (k+1) * sizeof(int)); floor (B);
C[k]=floor(B);
Z=floor(B);
k++;
if (k==52) break;
B = (B-Z)*2;
}
if (N1!=0) {int a =i+1022,v=0;
	int *P=malloc (11 *sizeof (int));
	int *S=malloc (52 *sizeof (int));
		//conversion d'Exposant vers binaire
		while (a != 0) {
		P[v]=(a % 2);
		v++;
		a = a/2;
		}
	//Affichage
for(j=v-1;j>=0;j--) printf("%d", P[j]);
printf("  ");
for(j=0;j<52;j++) S[j]=0;
for(j=0;j<i-1;j++) S[j]=T[i-j-2];
for(j=1;j<k;j++) S[j+i-2]=C[j];
for(j=0;j<52;j++) printf("%d",S[j]);
	}
	else {
		if (D ==0){
		for(j=0;j<=10; j++) printf("0"); 
		printf(" "); 
		for(j=0;j<52; j++) printf("0");
		}	else {
			 int u;
			for(j=1;j<k; j++) { if (C[j]==1) {u=j; break; }}
			int a=-u+1022,v=0;
			int *P=malloc (11 *sizeof (int));
			int *S=malloc (52 *sizeof (int));
		 for(j=0;j<11;j++) P[j]=0;
				while (a != 0) {
				P[v]=(a % 2);
				v++;
				a = a/2;
				}
		
		for(j=11;j>=0;j--) printf("%d", P[j]);
		printf(" ");
		for(j=0;j<52;j++) S[j]=0;
		for(j=u+1;j<k;j++) S[j- (u+1)]=C[j];
		}
	}
}

int main(){
	int i,v,q = 1;
	char n[10000];
	char bit[10];
	char nbr[64];
	char choix[1];
A:
    printf("Selectionnez l'operation:\n");
    printf("1. decimal To virgule fixe\n");
    printf("2. vergule fixe to decimal\n");
    printf("3. Conversion reel vers virgule flottante\n");
    scanf("%s", &choix);
    int ll=strlen(choix);
    if (choix[0]=='1'&&ll==1){//CHOIX 1
    	printf("Entrer un nombre reel:\n");
    scanf("%s", &n);
    double num;
    sscanf(n, "%lf", &num);// sscanf convertit char en double

    
    if (num < -pow(2, 16)|| num >(pow(2, 15)) ){
        printf("Le nombre n'est pas valide\n");
        goto A;
    }
    printf("La representation de %s en virgule fixe est : ",n);
	Vfixe(num);
	}
	else if (choix[0] == '2'&&ll==1){//CHOIX 2
	  AA: printf("Donner un nombre en virgule fixe representer en BINAIRE\n");
    scanf("%s",&nbr);
    v=0;
    for(i=0;i<65;i++){
    	if(nbr[i]=='.') v++;
	}
	if(v!=1){
		printf("le nombre doit etre contient une Virgule\n");
		goto AA;
	}
	
    bin_to_fixe(nbr);
	}
    else if (choix[0] == '3'&&ll==1){//CHOIX 3
    B: printf("Entrer un nombre REEL :\n");
    scanf("%s", &n);
    float num=atof(n);
    bit1:	  printf("Donnez le nombre de bits (32 ou 64): ");
        scanf("%s", &bit);
		  if (atoi(bit) != 32 && atoi(bit) != 64) {
		        printf("Nombre de bits invalide (doit etre 32 ou 64).\n");
		        goto bit1 ;
		    }
    
  
    // CHOIXXX
    if(atoi(bit)==32){
    	// Virgule Flottante sur 32 bits
    	if (num < -pow(2, 16)|| num >(pow(2, 16 ))){
        printf("Le nombre ne peut pas etre presenter en simple precision\n");
        goto B;
    }
    	    printf("La representation de %s en virgule flottante (simple precision) est :\n",n);
    		V_flottant32(num);
			printf("\n");
	} else {
		// Virgule Flottante sur 64 bits
		if (num < -pow(2, 32)|| num >(pow(2, 32 ))){
        printf("Le nombre ne peut pas etre presenter en double precision\n");
        goto B;
    }
		    printf("La representation de %s en virgule flottante (double precision) est :\n",n);
    		V_flottant64(num);
			printf("\n");
	} 

    } else {printf("le choix n'est pas valide\n");
    goto A;
	}
	//Quitter ou Ressayer
 while (q != 0) {
        S: printf("Pour RESSAYER tapez R !, Pour QUITTER tapez Q !\n");
        scanf(" %c", &q);
        if (q == 'Q' || q == 'q') {
            printf("FIN DU PROGRAMME\n");
            return 0;
        } else if (q == 'R' || q == 'r') {
            goto A;
        } else {
            goto S;
        }
    }

    return 0;
}

