#include<stdio.h>

#include<conio.h>
#include<stdlib.h>
typedef struct cellule
{ 
int nbr;
 cellule * ps ;
} ;
 cellule* A ;

    cellule* creer ()
{ cellule*p ;
    p=(cellule*)malloc(sizeof (cellule));
    if (p== NULL)
    {printf("memoire pleine\n");
}
else
{
     printf("sasir le nbre \n");
     scanf("%d",&p->nbr);
     p->ps=NULL;
     
}
return p;
}
    void affiche (cellule*p)
{
    while (p)
    { 
  printf("le nbre est :%d\n",p->nbr);
  p=p->ps;
}}
  void  ajoutd()
    {
        cellule* nouveau;
nouveau=creer();
nouveau->ps=A;
A=nouveau;
}
 void ajouf ()
 { cellule* aux;
 aux=creer();
 aux->ps=NULL;
 cellule * i=A;
 while 
 (i->ps!=NULL)
 { 
              i=i->ps;}
              i->ps=aux;
   } 
  cellule * supprimer ( int x)
 
  { cellule * prec ,* p ;
  p = A;
  if (A->nbr==x)
  { //A->ps=NULL ;
   //free(A);
   A=A->ps ;
   return(A);
}
else {
   while ((A!= NULL)&&(A->nbr!=x))
   {
   prec=A ;
    A=A->ps;
    }
 
 
 
 
 if (A->nbr==x)
 { prec->ps=A->ps;
   free (A);
}
else
 { printf("lélement n'existe pas");
}
}
return p;
} 
  int main ()
   { cellule * aux;
    int x ;
    printf("entrer x\n");
    scanf("%d",&x);
  
    
    A= creer();
     ajoutd ();
     ajouf ();
     A=supprimer(x);
     affiche (A);
getch();
return 0 ;
}    

