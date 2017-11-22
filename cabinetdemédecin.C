#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//**********************************la déclaration des nouveaux types**********************************

typedef struct date
{
  int annee;
  int moit;
  int jour;
  int heurs;
  int minute;
} date;
typedef struct patient
{
    int idt;
    char nom[30];
    char prenom[30];
    date date_de_naissance;
    char traitement[100];
    char medicament[100];
    date date_de_consultation;
    date rendez_vous_prochain;
}   patient;
typedef struct listpatient
{
    patient pa;
    listpatient* nxt ;
}   listpatient;
listpatient* ajout_patient(listpatient* h,patient pat)
{ listpatient* nouv=(listpatient*)malloc(sizeof(listpatient));
     nouv->pa=pat;
     nouv->nxt=NULL;
       if(h==NULL)   h=nouv;
       else
     {
       listpatient* p;
       p= h;
       while(p -> nxt!=NULL)
         {p=p->nxt;}
       p->nxt=nouv;
     }
       return(h);
}

//**********************************fonction verifier le code cin**********************************

int verif(int in)
{    int i=0,nb=0;
     int aux=in;
     while(aux!=0)
        {
           aux=aux/10;
           nb++ ;
        }
     if((nb==8)||(nb==7))      
        return(1);
     else
        return(0);
}
//**********************************fonction saisir l'année**********************************

 int saisir_annee(int j)
 {  int n=0;
    do
      {
        printf("donnez l'annee.\n");
        scanf("%d",&n); }
        while(n<j);
           return(n);
 }

//**********************************fonction saisir le moit**********************************

 int saisir_moit()
 {  int n1=0;
    do
      {
        printf("donnez le moit.\n");
        scanf("%d",&n1); }
        while((n1<=0)||(n1>12));
           return(n1);
 }

//**********************************fonction saisir le jours**********************************

 int saisir_jour()
 {  int n2=0;
    do
      {
        printf("donnez le jour.\n");
        scanf("%d",&n2); }
        while((n2<=0)||(n2>31));
           return(n2);
 }

//**********************************fonction saisir l'heurs**********************************

 int saisir_heurs()
 {  int n3=0;
    do
      {
        printf("donnez l'heurs.\n");
        scanf("%d",&n3); }
        while((n3<=8)||(n3>15));
           return(n3);
 }

//**********************************fonction saisir les minutes**********************************

 int saisir_minute()
 {  int n4=0;
    do
      {
        printf("donnez les minutes.\n");
        scanf("%d",&n4); }
        while((n4<=0)||(n4>59));
        return(n4);
 }

//**********************************procedure affiche liste**********************************

void afficheliste(listpatient* h)
{   listpatient* m;
    m=h;
    while (m!= NULL)
     {
        printf("**_______________________________________________________**\n");
        printf("Cin:%d\n",m->pa.idt);
        printf("Nom:%s\n",m->pa.nom);
        printf("Prenom:%s\n",m->pa.prenom);
        printf("Date de naissance:%d/%d/%d\n",m->pa.date_de_naissance.jour,m->pa.date_de_naissance.moit,m->pa.date_de_naissance.annee);
        printf("Traitement:%s\n",m->pa.traitement);
        printf("Medicament:%s\n",m->pa.medicament);
        printf("Date de consultation: %d-%d-%d ******** %d:%d\n",m->pa.date_de_consultation.jour,m->pa.date_de_consultation.moit,m->pa.date_de_consultation.annee,m->pa.date_de_consultation.heurs,m->pa.date_de_consultation.minute);
        printf("Date du prochain rendez-vous : %d-%d-%d ******** %d:%d\n",m->pa.rendez_vous_prochain.annee,m->pa.rendez_vous_prochain.moit,m->pa.rendez_vous_prochain.jour,m->pa.rendez_vous_prochain.heurs,m->pa.rendez_vous_prochain.minute);
        printf("**_______________________________________________________**\n");
        printf("\n\n");
        m=m->nxt;
     }
}

//**********************************procedure saisir patient**********************************

 void saisirpatient(patient* w)
 {     int idt;
       char nom[30];
       char prenom[30];
       int age;
       char traitement[100];
       char medicament[100];
       w->idt=0;
       while(verif(w->idt)==0)
        {
          printf("Donnez le numero de carte d'identite du nouveau patient.\n");
          flushall();
          scanf("%d",&w->idt);
        }
      printf("Donnez le nom du patient.\n");
      flushall();
      gets(w->nom);
      printf("Donnez le prenom du patient.\n");
      flushall();
      gets(w->prenom);
      printf("donnez la date de naissance du patient:Annee,moit et jour:\n");
      flushall();
      w->date_de_naissance.jour=saisir_annee(0);
      w->date_de_naissance.moit=saisir_moit();
      w->date_de_naissance.jour=saisir_jour();
      printf("Donnez le traitement qui va prendre le patient.\n");
      flushall();
      gets(w->traitement);
      printf("Donnez les medicaments qui va prendre le patient.\n");
      flushall();
      gets(w->medicament);
      SYSTEMTIME t;
      GetSystemTime(&t);
      w->date_de_consultation.annee=t.wYear;
      w->date_de_consultation.moit=t.wMonth ;
      w->date_de_consultation.jour=t.wDay;
      w->date_de_consultation.heurs= t.wHour;
      w->date_de_consultation.minute= t.wMinute;
      w->rendez_vous_prochain.annee=0;
      w->rendez_vous_prochain.moit=0;
      w->rendez_vous_prochain.jour=0;
      w->rendez_vous_prochain.heurs=0;
      w->rendez_vous_prochain.minute=0;
 }

 //**********************************fonction ajouter fin**********************************

 listpatient* ajouterfin(listpatient* tete)
 {   listpatient* nouveau=(listpatient*)malloc(sizeof(listpatient));
     saisirpatient(&nouveau->pa);
     nouveau->nxt=NULL;
     if(tete==NULL)
        tete=nouveau;
     else
       {
          listpatient* p;
          p= tete;
          while(p -> nxt!=NULL)
             {p=p->nxt;}
          p->nxt=nouveau;
       }
     return(tete);
 }

//**********************************fonction chercher un patient**********************************

 listpatient* chercherpatient(listpatient* h,int i)
 {   listpatient* d;
     d=h;
     while((d->pa.idt!=i)&&(d!=NULL))
        {d=d->nxt;}
     return(d);
 }

//**********************************procedure modifier medicament**********************************

 void modifiermedicament(listpatient* z)
 {   char ch[100];
     printf("Donnez le medicament à ajouter.\n");
     scanf("%s",ch);
     strcat(z->pa.medicament,ch);
 }

 //**********************************procedure modifier traitement**********************************

 void modifiertraitement(listpatient* z)
 {  char ch[100];
    printf("Donnez le traitement à ajouter.\n");
    scanf("%s",ch);
    strcat(z->pa.traitement,ch);
 }

 //**********************************procedure modifier les informations d'un patient**********************************

 void modifierpatient(listpatient* h)
{   int i=0;
    while(verif(i)==0)
      {
        printf("Donnez le numero de carte d'identité du patient");
        scanf("%d",&i);
      }
    listpatient* z;
    z= chercherpatient(h,i) ;
    int a=0;
    printf("Donnez:/  n1- Pour modifier le champ traitement./  n2- Pour modifier le champ medicament.\n");
    scanf("%d",&a);
    if (a==1)
        modifiertraitement(z);
    if (a==2)
        modifiermedicament(z);
 }

//**********************************fonction supprimer patient**********************************

 listpatient * supprimer_patient(listpatient* h)
{   int e=0;
    if(h==NULL)
       printf("La liste est vide.\n");
    else
      {
         while(verif(e)==0)
            {
               printf("Donner le numero de carte d'identite du patient a supprimer.\n");
               scanf("%d",&e);
            }
         listpatient* t;
         listpatient* q;
         t=h;
         if(h->pa.idt==e)
            h=h->nxt;
         else
            {
                while((t->nxt!=NULL)&&(t->nxt->pa.idt!=e))
                   t=t->nxt;
                if(t->nxt==NULL)
                   printf("Ce patient n'est pas dans la liste.\n");
                else
                 {
                   q=t->nxt;
                   t->nxt=q->nxt;
                 }
                free(q);

            }
      }
    return h;
}

//**********************************procedure affiche les informations d'un patient**********************************

 void affiche_patient(listpatient* k)
{   int i=0;
    while(verif(i)==0)
       {
          printf("Donnez le numero de carte d'identite du patient a afficher.\n");
          scanf("%d",&i);
       }
    listpatient* f;
    f= chercherpatient(k,i) ;
    clrscr();
    printf("\n\n\n\n");
    printf("**_______________________________________________________**\n") ;
    printf("Cin:%d\n",f->pa.idt);
    printf("Nom:%s\n",f->pa.nom);
    printf("Prenom:%s\n",f->pa.prenom);
    printf("Date de naissance:%d/%d/%d\n",f->pa.date_de_naissance.jour,f->pa.date_de_naissance.moit,f->pa.date_de_naissance.annee);
    printf("Traitement:%s\n",f->pa.traitement);
    printf("Medicament:%s\n",f->pa.medicament);
    printf("Date de consultation: %d-%d-%d ******** %d:%d\n",f->pa.date_de_consultation.jour,f->pa.date_de_consultation.moit,f->pa.date_de_consultation.annee,f->pa.date_de_consultation.heurs,f->pa.date_de_consultation.minute);
    printf("Date de prochain rendez-vous : %d-%d-%d ******** %d:%d\n",f->pa.rendez_vous_prochain.annee,f->pa.rendez_vous_prochain.moit,f->pa.rendez_vous_prochain.annee,f->pa.rendez_vous_prochain.heurs,f->pa.rendez_vous_prochain.minute);
    printf("**_______________________________________________________**\n");
    printf("\n\n\n\n");
}



//**********************************procedure creer ou modifier un rendez-vous**********************************

 void creer_ou_modifier_un_rendez_vous(listpatient* n)
{   int cin1=0;
    while(verif(cin1)==0)
       {
          printf("donnez le numero de carte d'identité du patient pour lui donnez un rendez-vous.\n");
          scanf("%d",&cin1);
       }

    listpatient* v;
    v= chercherpatient(n,cin1) ;
    printf("Donnez la date du prochain rendez-vous.\n");
    v->pa.rendez_vous_prochain.annee=saisir_annee(v->pa.date_de_consultation.annee);
    v->pa.rendez_vous_prochain.moit=saisir_moit();
    v->pa.rendez_vous_prochain.jour=saisir_jour();
    v->pa.rendez_vous_prochain.heurs=saisir_heurs();
    v->pa.rendez_vous_prochain.minute=saisir_minute();
 }

//**********************************procedure afficfer les rendez-vous d'un jour**********************************

 void affiche_les_rendez_vous_d_un_jours(listpatient* h)
 {  listpatient* o;
    o=h;
    printf("donner la date du jour que vous voulez savoir vos rendez-vous:jour,moit et annee: \n");
    int jo=saisir_jour();
    int mo=saisir_moit();
    int an=saisir_annee(o->pa.date_de_consultation.annee);
    clrscr() ;
    printf("Pour la date %d/%d/%d vous avez des rendez-vous a les heurs suivantes:\n",jo,mo,an);
    while(o!=NULL)
        {
          if((jo==o->pa.rendez_vous_prochain.jour)&&(mo==o->pa.rendez_vous_prochain.moit)&&(an==o->pa.rendez_vous_prochain.annee))
             printf("*_____ %d;%d _____*\n",o->pa.rendez_vous_prochain.heurs,o->pa.rendez_vous_prochain.minute ) ;
          o=o->nxt;
        }
 }

//**********************************procedure supprimer un rendez-vous**********************************

 void supprimer_un_rendez_vous(listpatient* h)
 {  listpatient* ji;
    ji=h;
    int cin=0;
    while(verif(cin)==0)
       {
          printf("Donnez le numero de cin du patient pour supprimer son rendez-vous.\n");
          scanf("%d",&cin);
       }
    while(cin!=ji->pa.idt)
        ji=ji->nxt;
    ji->pa.rendez_vous_prochain.annee=0;
    ji->pa.rendez_vous_prochain.moit=0;
    ji->pa.rendez_vous_prochain.jour=0;
    ji->pa.rendez_vous_prochain.heurs=0;
    ji->pa.rendez_vous_prochain.minute=0;
 }

//**********************************le programme principale**********************************

 void main()
 {   listpatient* h;
     patient pat;
     FILE *fich = NULL;
     fich = fopen("liste_des_patients.txt", "rb+");
          while (fread(&pat, sizeof(patient), 1, fich) != 0)
          {
             h = ajout_patient(h, pat);
          }
     fclose(fich);
     int x=1;
     menu:
     printf( "\n\nTapez le numero de tache que vous voulez faire selon le menu suivant:\n  1-Ajouter un nouveau patient.\n  2-Afficher la liste des patients.\n  3-Modifier un patient.\n  4-Supprimer un patient.\n  5-Aficher un patient.\n  6-Creer ou modifier un rendez-vous.\n  7-Afficher les rendez-vous d'un jours.\n  8-Supprimer_un_rendez-vous.\n  9-Fin des taches.\n");
     scanf("%d",&x) ;
     switch(x)
        {
          case 1:  h=ajouterfin(h); clrscr(); goto menu;
            break;
          case 2: afficheliste(h);  goto menu;
            break;
          case 3:  modifierpatient(h); clrscr(); goto menu;
            break;
          case 4: h=supprimer_patient(h); clrscr(); goto menu;
            break;
          case 5: affiche_patient(h); goto menu;
            break;
          case 6: creer_ou_modifier_un_rendez_vous(h); clrscr(); goto menu;
            break;
          case 7: affiche_les_rendez_vous_d_un_jours(h); goto menu;
            break;
          case 8: supprimer_un_rendez_vous(h); clrscr(); goto menu;
            break;
          case 9: clrscr();  printf("\n\n\n  Vous avez termine vos taches.\n");
            break;
          default: clrscr(); printf("\n\n vous avez tapez un faut numero tapez de nouveau.\n");  goto menu;
       }
    listpatient* i;
    i = h;
    fich = fopen("liste_des_patients.txt", "wb+");
    while (h != NULL)
       {
          fwrite(&(h->pa), sizeof(patient), 1, fich);
          h = h->nxt;
       }
 printf("  Votre travail a ete sauvegarde avec succe.\n" );
 getch();
 }
