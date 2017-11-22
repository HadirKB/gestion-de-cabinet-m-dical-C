#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
                                  /*la déclaration des structure */
typedef struct patient{
char nometprenom[50];
char date[11];
int numfiche;
int cin;};


typedef struct cot {
char dr[100];
struct cot *suiv; };
                                /*la déclaration des fonctions:*/

void affichage(patient *k)
{ puts(k->nometprenom);
puts(k->date);
printf("%d",k->cin);
printf("%d",k->numfiche);
}

void  chercher(FILE *f){
char d[11];
patient *p=(patient*)malloc(sizeof(patient));
f=fopen("D:/PFE/liste.txt","rb");

printf("Date de naissance(jj.mm.aaaa):");
scanf("%s",d);
puts(d);
while((!feof(f))&&(strcmp(p->date,d)!=0))
{fread(p,1,sizeof(patient),f);
  affichage(p); }
if(!feof(f))
 affichage(p);


else printf("ce patient n'est pas enregistré oubien la date saisie n'est juste,reverifier encorefois,,,,");
fclose(f);
}


void creation(FILE *f,int n){
patient *p;
p=(patient*)malloc(sizeof(patient));
printf("nom & prénon = ");
scanf("%s",p->nometprenom);
printf("date de naissance (jj.mm.aaaa)= ");
scanf("%s",p->date);
printf("numéro de cin = ");
scanf("%d",&p->cin);
 p->numfiche=n;
printf("son numéro de fiche est %d",p->numfiche);
char cc='\n';
fwrite(p,sizeof(patient),1,f);
fwrite(&cc,sizeof(char),1,f);
}

void affichect(cot *mm){
cot *m=mm;
if(m==NULL) printf("rien à afficher");
else 
while (m!=NULL){
puts(m->dr);
m=m->suiv; }
}
void ajouter(cot *tt){
cot *m=tt;

cot *c=(cot*)malloc(sizeof(cot));
c->suiv=NULL;
 printf("donner le spécialité,le nom et l'adresse:");
scanf("%s",c->dr);
if(m!=NULL) {
while(m->suiv!=NULL)
m=m->suiv; 
m->suiv=c; }
else{ m=c;}

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
int nf(FILE *f,FILE *ff){
int *ji=NULL;
f=fopen("D:/PFE/liste.txt","rb");
patient *kkk=NULL;
kkk=(patient*)malloc(sizeof(patient));
fread(kkk,1,sizeof(patient),f);
if (kkk==NULL) 
{ ff=fopen("D:/PFE/ENTIER.txt","wb+");
int k=0; ji=&k;
fwrite(ji,1,sizeof(int),ff);
}
else{   ff=fopen("D:/PFE/ENTIER.txt","rb+");
  
fread(ji,1,sizeof(int),ff);
}
 ff=fopen("D:/PFE/ENTIER.txt","wb+");
*ji=*ji+1;
fwrite(ji,1,sizeof(int),ff);
fclose(ff);
fclose(f);
return(*ji);}


void main()
{ char d[10];FILE *f,*ff;
cot *tc;
int a,b,j=0;

f=fopen("D:/PFE/liste.txt","ab+");
 printf(" 1:Chercher un patient.\n 2:Enregistrer un nouveau patient.\n 3:Afficher les rendez-vous.\n 4:Enregistrer un nouveau rendez-vous.\n 5:Le payement.\n 6:Les contacts.\n 7:Statistiques.\n");
scanf("%d",&a);
tc=(cot*)malloc(sizeof(cot));
tc=NULL;

if(a==1)  chercher(f);
if(a==2){ int nn=nf(f,ff);
          creation(f,nn);
 }
if(a==3) { printf("donnez le jour,le mois et l'année (jj.mm.aaaa): ");
scanf("%s",d);






}
 if(a==4) printf("hfkf");
if (a==5)  payer();
 if(a==6) { printf("1:afficher / 2:ajouter \n");
scanf("%d",&b);
if (b==1) affichect(tc);
else ajouter(tc); }       
if (a==7)  printf("jfjfk");   
if((a!=1)&&(a!=2)&&(a!=3)&&(a!=4)&&(a!=5)&&(a!=6)&&(a!=7))  printf("erreur ! tapez de 1 à 7 !");

fclose(f);

						 printf("correct");
}
 
