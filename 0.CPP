#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define xxx 12


                                  /*la déclaration des structure */

typedef struct patient{
char nometprenom[50];
char date[11];
int numfiche;
int cin;
struct patient *suiv;   };

typedef struct liste{
patient *tete;
patient *queue;
};
typedef struct cot {
char dr[50];
 };
typedef struct kl{
char rv[20];
int tp[2];};

typedef struct jour{
kl t[13];
};

typedef struct mois{
int nom;
jour j[31];
int nb;
};


                                /*la déclaration des fonctions:*/

void affichage(patient *k)
{printf("-------------Resultat de recherche---------------");
 printf("\nMdm/M: %s\n",k->nometprenom);
printf("date de naissance=%s\n",k->date);
printf("numéro de cin=%d\n",k->cin);
printf("-->numéro de fiche=%d\n",k->numfiche);

}

void  chercher(liste *l){
char d[11];
patient *p=l->tete;
printf("Date de naissance(jj/mm/aaaa):");
scanf("%s",d);
while (p!=NULL){
if (strcmp(p->date,d)==0) break;
p=p->suiv; }

if(p!=NULL){
 affichage(p);
}
else printf("ce patient n'est pas enregistré oubien la date saisie n'est juste,reverifier encorefois svp !");
}


void creation(liste *l){
patient *p;
p=(patient*)malloc(sizeof(patient));
p->suiv=NULL;
printf("nom & prénon = ");
scanf("%s",p->nometprenom);
printf("date de naissance (jj/mm/aaaa)= ");
scanf("%s",p->date);
printf("numéro de cin = ");
scanf("%d",&p->cin);
if(l->tete==NULL)  p->numfiche= 1;
else p->numfiche=l->queue->numfiche + 1;
printf("son numéro de fiche est %d",p->numfiche);

if(l->tete==NULL) {
l->tete=p;
l->queue=p;}
else{
l->queue->suiv=p;
l->queue=p;}
}

void payer(){
char pa[5]; int s=0;   int i=0;
printf("1=control;2=traitement;3=opération :");

scanf("%s",pa);
while ((i<5)&&(pa[i]!=NULL)){
if (pa[i]=='1' ) s=s+10;
if (pa[i]=='2') s=s+30;
if (pa[i]=='3') s=s+700;
i++;}

printf("-------->%d dinars",s);
}

void main()
{liste *l;
//mois mo[xxx];
int da;
cot tc[20];
int a,b,c,jo;

/*création manuelle d'agenda*/

 /*
 mo[0].nb=30;
 mo[1].nb=28; 
 mo[2].nb=30;
 mo[3].nb=29;
 mo[4].nb=30;
 mo[5].nb=29;
 mo[6].nb=30;
 mo[7].nb=30;
 mo[8].nb=29;
 mo[9].nb=30;
 mo[10].nb=29;
 mo[11].nb=30;   int dddd;
/* int lm;
for(int dddd=0;dddd<xxx;dddd++){
for(int g=0;g<mo[dddd].nb;g++){
lm=8;
for(int ss=0;ss<13;ss++)
{
mo[dddd].j[g].t[ss].tp[0]=lm;
lm++;
mo[dddd].j[g].t[ss].tp[1]=lm;
}

}
}
        
for(dddd=0;dddd<xxx;dddd++){
for(int g=0;g<mo[dddd].nb;g++){
for(int ss=0;ss<13;ss++)
{
mo[dddd].j[g].t[ss].rv[0]='-';
mo[dddd].j[g].t[ss].rv[1]='-';
mo[dddd].j[g].t[ss].rv[2]='-';
mo[dddd].j[g].t[ss].rv[3]='\0';
}

}
}
  */
int x=1;
 l=(liste*)malloc(sizeof(liste));
l->tete=NULL;
l->queue=NULL;
printf("\n\t******** Bonjour Monsieur/Madame,choisissez une tâche svp ********\n\n");
do {
 printf("_____________________________________________________________\n\n (1):Chercher un patient.\n (2):Enregistrer un nouveau patient.\n (3):Afficher les rendez-vous.\n (4):Enregistrer un nouveau rendez-vous.\n (5):Le payement.\n (6):Les contacts.\n");
 printf("_____________________________________________________________\n");
scanf("%d",&a);


if(a==1)  chercher(l);
if(a==2)  creation(l);
/*if(a==3) { printf("donnez le mois: ");
scanf("%d",&da);
do{
printf("donnez le jour: ");
scanf("%d",&jo);
}while ((jo<1)||(jo-1>mo->nb));
for(int gg=0;gg<13;gg++) 
printf(". %d->%d: %s",mo[da-1].j[jo-1].t[gg].tp[0],mo[da-1].j[jo-1].t[gg].tp[0],mo[da-1].j[jo-1].t[gg].rv);




}  */
 if(a==4) {
 int ka,kb,kc;
 char kd[15];

 printf("donnez le mois:");
 scanf("%d",&ka);
 printf("donnez le jour:");
 scanf("%d",&kb);
 printf("donnez l'heure:");
 scanf("%d",&kc);
 printf("Rendez-vous sous le nom de:");
 scanf("%s",kd);
// for(int af=0;af<strlen(kd);af++)
// mo[ka].j[kb].t[kc-8].rv[af]=kd[af];
 printf("\n-> ^_^ enregistré avec succés. Merci bien :)");





 }

if (a==5)  payer();
 if(a==6) { printf("1:afficher / 2:ajouter \n");
scanf("%d",&b);
if (b==1) {
if(x==1) printf("rien à afficher");
else 
for(int q=0;q<x-1;q++)
printf(". %s\n",tc[q].dr);


}
else { 
if (x<=20)
printf("donner le spécialité,le nom et l'adresse:");
scanf("%s",tc[x-1].dr);
printf("%s",tc[x-1].dr);
printf("le contenu est %s",tc[x-1].dr);  x++;
} }

if((a!=1)&&(a!=2)&&(a!=3)&&(a!=4)&&(a!=5)&&(a!=6))  printf("SVP tapez de 1 à 6 !");
 printf("\n_____________________________________________________________\n");
printf("\n (0):Menu :"); scanf("%d",&c);

}
while(c==0);


						
}
 
