#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct utilisateur {
    char nompre[50];  
    char cin[9];      
    int age;
    char adresse[50];
	int numtel; 
	int point; 
};
struct voiture
{ int numvoit;
char marque[10];
char couleur[10];
float prixlocsanschoff;
float prixlocavecchoff;
};
struct noued 
{ struct voiture val;
struct noued *suiv;
};
struct location
{ struct voiture v;
  int jour;
  int mois;
  int annee;
 float duree;
 float prix;
};
struct Noued {
    struct location a;
    struct Noued *b;
};

typedef struct Noued *Listelocation;

void ajout_tete_location(struct location e, Listelocation *L) {
    struct Noued *p = malloc(sizeof(struct Noued));
    if (p == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    exit(EXIT_FAILURE);
    }
    p->b = *L;
    p->a = e;
    *L = p;
}


void afficher_historique_location(Listelocation L) {
    int i = 0;
    Listelocation Q = L;
    while (Q) {
    i++;
    printf("Vous avez louer la voiture de numero %d de marque %s pour la date %d/%d/%d pour une duree %f heures et un prix de location de %f dt\n", Q->a.v.numvoit, Q->a.v.marque, Q->a.jour, Q->a.mois, Q->a.annee, Q->a.duree, Q->a.prix);
    Q = Q->b;
    }
}


typedef struct File {
    struct location loc;
    struct File* suivant;
} File;

File* tete = NULL;
File* queue = NULL;

void louer(struct location l) {
    File* nouveau = (File*)malloc(sizeof(File));
    if (nouveau == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    nouveau->loc = l;
    nouveau->suivant = NULL;

    if (tete == NULL && queue == NULL) {
        tete = nouveau;
        queue = nouveau;
    } else {
        queue->suivant = nouveau;
        queue = nouveau;
    }
}

struct location retourner() {
    File* temp;
    struct location data;

    if (tete == NULL || queue == NULL) {
        printf("!\n");
        exit(EXIT_FAILURE);
    }

    temp = tete;
    data = temp->loc;

    if (tete == queue) {
        tete = queue = NULL;
    } else {
        tete = tete->suivant;
    }

    free(temp);
    return data;
}
typedef struct noued *Liste;
void ajout_tete(struct voiture e, Liste *L){
Liste p;
p = malloc(sizeof(struct noued));
p->suiv=*L;
p->val=e;
*L=p;
}
void afficher_Liste( Liste L){
int i=0;
Liste Q=L;
while(Q){
i++;
printf("\033[1;34m");
printf("voiture numero %d ,marque %s  , prix de location sans chauffeur %f dt par heurs , prix de location avec chauffeur %f dt par heurs \n",Q->val.numvoit,Q->val.marque,Q->val.prixlocsanschoff,Q->val.prixlocavecchoff);
printf("\033[0m");
Q=Q->suiv;
}}
struct voiture supprimer_voiture(int numvoit, Liste *L) {
    Liste p = NULL;
    Liste q = *L;
    struct voiture v;

    while (q != NULL && q->val.numvoit != numvoit) {
        p = q;
        q = q->suiv;
    }

    if (q == NULL) {
        printf("Voiture avec le numero %d non trouvee dans la liste.\n", numvoit);
        v.numvoit = -1;
        return v;
    }

    v = q->val;

    if (p == NULL) {
        *L = q->suiv;
    } else {
        p->suiv = q->suiv;
    }

    free(q);

    return v;
}
int creer_fichier_Utilisateur() {
    FILE *fp;
    if ((fp = fopen("./utilisateur.txt", "a")) == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}
int creer_fichier_Location() {
    FILE *fp;
    if ((fp = fopen("./Historique de location.txt", "a")) == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}
int creer_fichier_Voiture_en_panne() {
    FILE *fp;
    if ((fp = fopen("./Voiture en panne.txt", "a")) == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}
int creer_fichier_Avis_Utilisateur() {
    FILE *fp;
    if ((fp = fopen("./Avis Utilisateur.txt", "a")) == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}
int main() {
	Listelocation e=NULL;
	struct location L;
	struct voiture V,W;
	int s,h;
	int N=0;
	char ch[50];
	struct location T[100];
	Liste l = NULL; 
    struct voiture v,k;
    v.numvoit = 10;
    strcpy(v.marque, "FiatPanda "); 
    strcpy(v.couleur, " blanc");
    v.prixlocsanschoff =30;
    v.prixlocavecchoff=50;
    ajout_tete(v, &l);
    v.numvoit = 11;
    strcpy(v.marque, "SkodaFabia "); 
    strcpy(v.couleur, " noir");
    v.prixlocsanschoff =50;
    v.prixlocavecchoff=70;
    ajout_tete(v, &l);
    v.numvoit = 12;
    strcpy(v.marque, "SuzukiSwift "); 
    strcpy(v.couleur, " gris");
    v.prixlocsanschoff =50;
    v.prixlocavecchoff=70;
    ajout_tete(v, &l); 
    v.numvoit = 13;
    strcpy(v.marque, "VolkswagenVirtus "); 
    strcpy(v.couleur, " noir");
    v.prixlocsanschoff =60;
    v.prixlocavecchoff=80;
    ajout_tete(v, &l);
    v.numvoit = 14;
    strcpy(v.marque, "Hyundaii10BVA"); 
    strcpy(v.couleur, " blanc");
    v.prixlocsanschoff =60;
    v.prixlocavecchoff=80;
    ajout_tete(v, &l);
    v.numvoit = 15;
    strcpy(v.marque, "MercedesclassE "); 
    strcpy(v.couleur, " gris");
    v.prixlocsanschoff =100;
    v.prixlocavecchoff=120;
    ajout_tete(v, &l);
    printf("\033[1;31m");
    printf("Bienvenue sur E-Cars,votre destination pour une experience de location de voiture moderne et pratique,votre partenaire  de confiance ."
	"Pret a explorer le monde avec style <3\n");
	printf("\033[0m");
	printf("\033[1;33m");
	printf("Se connecter\n");
	printf("\033[0m");
    struct utilisateur p;
    int r;
    printf("Nom et prenom :\n");
    fgets(p.nompre, 50, stdin);
    printf("Numero de cin :\n");
    fgets(p.cin, 9, stdin);
    printf("Age :\n");
    scanf("%d", &p.age);
    getchar();
    printf("Adresse :\n");
    fgets(p.adresse, 50, stdin);
    printf("numero de telephone\n ");
    scanf("%d",&p.numtel);
    p.point=0;
    r = creer_fichier_Utilisateur();
    FILE *fp;
    fp = fopen("./utilisateur.txt", "a");
    fprintf(fp, "* L'utilisateur %s de numero de cin %s d'age %d d'adresse %s et de numero de telephone%d \n", p.nompre, p.cin, p.age, p.adresse,p.numtel);
    fclose(fp);
    int a;
    do
   {
	int m;
	printf("\033[1;33m");
    printf("Pour voir les voitures a louer tapez 1 \n");  
    printf("\033[0m");
    scanf("%d",&m);
    if(m==1)
    {  afficher_Liste(l);
	}
	printf("\033[1;33m");
	printf("Pour louer une voiture tapez 1\n");
	printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{int x;
	printf("donnez le numero de voiture que vous voulez louer\n");
    scanf("%d",&x);
    V=supprimer_voiture(x,&l);
    L.v=V;
    printf("donnez la date de location jour,moins,annee et la duree par heurs\n");
    scanf("%d",&L.jour);
    scanf("%d",&L.mois);
    scanf("%d",&L.annee);
    scanf("%f",&L.duree);
    printf( "\033[1;32m");
    printf("Si avec chauffeur tapez 1\n");
    printf("\033[0m");
    scanf("%d",&m);
    if(m==1)
    {L.prix=L.duree*V.prixlocavecchoff;
    ajout_tete_location(L,&e);
    louer(L);
    p.point+=100;
    s= creer_fichier_Location();
    FILE *fq;
    fq= fopen("./Historique de location.txt", "a");
    fprintf(fq, "* L'utilisateur %s de numero de cin %s qui a %d points de fidelite a louer la voiture numero %d de nom %s a la date %d/%d/%d et de prix de location avec chauffeur %f dt \n", p.nompre, p.cin,p.point, L.v.numvoit, L.v.marque, L.jour, L.mois, L.annee,L.prix);
    fclose(fq);}
    else
    {L.prix=L.duree*V.prixlocsanschoff;
    ajout_tete_location(L,&e);
    louer(L);
    p.point+=100;
    s= creer_fichier_Location();
    FILE *fq;
    fq= fopen("./Historique de location.txt", "a");
    fprintf(fq, "* L'utilisateur %s de numero de cin %s qui a %d points de fidilite a louer la voiture numero %d de nom %s a la date %d/%d/%d et de prix de location avec chauffeur %f dt \n", p.nompre, p.cin,p.point, L.v.numvoit, L.v.marque, L.jour, L.mois, L.annee,L.prix);
    fclose(fq);}
	}
	printf("\033[1;33m");
    printf("Pour restituer la voiture, veuillez appuyer sur la touche 1\n");
    printf("\033[0m");
    scanf("%d",&m);
    if(m==1)
    {if (queue == NULL) {
    printf("Vous n'avez pas de voiture à retourner.\n");
    }
	else {
    W = retourner().v;
    ajout_tete(W, &l);
    printf("Voiture restituee avec succes.\n");}
	}
	printf("\033[1;33m");
	printf("Si la voiture que vous avez louer est en panne tapez 1\n");
	printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{if (queue == NULL) {
    printf("Vous n'avez pas de voiture a signaler en panne.\n");
    }
	else {
    W = retourner().v;
    r = creer_fichier_Voiture_en_panne();
    FILE *fs;
    fs = fopen("./Voiture en panne.txt", "a");
    fprintf(fs, "* La voiture en panne est de numero %d ,marque %s, couleur %s \n", W.numvoit, W.marque, W.couleur);
    fclose(fs);
    printf("Voiture signalee en panne avec succes.\n");
    }
	}
	printf("\033[1;33m");
	printf("Pour voir votre historique de location tapez 1\n");
	printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{if(e==NULL)
	{ printf("Vous n'avez pas encore louer des voiture \n");
	}
	else
	{afficher_historique_location(e);
	}
	}
	printf("\033[1;33m");
	printf("Pour consulter les offres de conversion de points de fidelite, veuillez appuyer sur la touche 1\n");
	printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{printf("\033[1;35m");
	printf("10 000 points de fidelite peuvent se convertir en une heure gratuite de location de voiture pour un tarif de location inferieur ou egal a 50 DT.\n 20 000 points de fidelite peuvent se convertir en une heure gratuite de location de voiture pour un tarif de location superieur a 50 DT, ou en deux heures gratuites pour un tarif de location inferieur ou egal a 50 DT.\n 100 000 points de fidelite peuvent se convertir en une journee gratuite de location pour une voiture de votre choix.\n");
	printf("\033[0m");
	}
	printf("\033[1;33m");
	printf("Pour consulter votre solde de points de fidelite, veuillez appuyer sur la touche 1\n ");
	printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{printf("\033[1;35m");
    printf("Vous avez %d points de fidelite\n",p.point);
    printf("\033[0m");
	} 
	printf("\033[1;33m");
	printf("Pour contribuer a l'amelioration de notre application, partagez votre avis et indiquez ce que vous souhaiteriez corriger ou ajouter.\n En echange, gagnez 200 points de fidelite.tapez 1\n");
    printf("\033[0m");
	scanf("%d",&m);
	if(m==1)
	{printf("donnez votre avis\n");
	getchar(); 
	fgets(ch, sizeof(ch), stdin);
    s=creer_fichier_Avis_Utilisateur() ;
    FILE *fm;
    fm= fopen("./Avis Utilisateur.txt", "a");
    fprintf(fm, "* Avis d'utilisateur %s de numero de cin %s :%s \n", p.nompre, p.cin,ch);
    fclose(fm);
	p.point+=200;}
	 printf("\033[1;31m");
	printf("Vous voulez quiter l'application , tapez 0\n");
	scanf("%d",&a);
	printf("\033[0m");
	}
	while(a!=0);
}
	
	

