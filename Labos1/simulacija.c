#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int t = 0;      //simulacija vremena (trenutno vrijeme)
int indeks = 0; //pokazivat će indeks slobodnog mjesta u P

struct dretva
{
   int id;   //1, 2, 3,
   int p;    //preostalo vrijeme rada
   int prio; //prioritet
   int rasp; //način raspoređivanja (za opcionalni zadatak)
};

#define MAX_DRETVI 5
struct dretva *P[MAX_DRETVI];
/* podaci o događajima pojave novih poslova - dretvi */
#define DRETVI 6
int nove[DRETVI][5] =
    {
        /* trenutak dolaska, id, p, prio, rasp (prio i rasp se koriste ovisno o rasporedivacu) */
        {1, 3, 5, 3, 1}, /* rasp = 0 => PRIO+FIFO; 1 => PRIO+RR */
        {3, 5, 6, 5, 1},
        {7, 2, 3, 5, 0},
        {12, 1, 5, 3, 0},
        {20, 6, 3, 6, 1},
        {20, 7, 4, 7, 1},
};

void ispis_stanja(int ispisi_zaglavlje)
{
   int ii;
   if (ispisi_zaglavlje)
   {
      printf("  t    AKT");
      for (ii = 1; ii < MAX_DRETVI; ii++)
         printf("     PR%d", ii);
      printf("\n");
   }

   printf("%3d ", t);
   for (ii = 0; ii < MAX_DRETVI; ii++)
      if (P[ii] != NULL)
         printf("  %d/%d/%d ",
                P[ii]->id, P[ii]->prio, P[ii]->p);
      else
         printf("  -/-/- ");
   printf("\n");
}

void ispitajImaLiDolaznih()
{
   int i;
   for (i = 0; i < DRETVI; i++)
   {
      if (t == nove[i][0])
      {
         printf("%3d ", t);
         printf("-- nova dretva id=%d p=%d prio=%d\n",
                nove[i][1], nove[i][2], nove[i][3]);
         struct dretva *d = (struct dretva *)malloc(sizeof(struct dretva));
         //d = {.id = nove[i][1], .p = nove[i][2], .prio = nove[i][3], .rasp = nove[i][4]};
         d->id = nove[i][1];
         d->p = nove[i][2];
         d->prio = nove[i][3];
         d->rasp = nove[i][4];
         if (indeks < MAX_DRETVI)
         {
            P[indeks] = d;
            indeks++;
         }
         else
         {
            printf("nema mjesta u redu");
         }
      }
   }
}

void pomakniDretve()
{
   free(P[0]);
   int i;
   for (i = 1; i < MAX_DRETVI; i++)
   {
      P[i - 1] = P[i];
   }
   indeks--;
   P[MAX_DRETVI - 1] = NULL;
}

void obradi()
{
   if (P[0] != NULL)
   {
      if (P[0]->p == 0)
      {
         printf("Dretva %d je zavrsila.\n", P[0]->id);
         pomakniDretve();
         ispis_stanja(0);
         if (P[0] != NULL)
            P[0]->p = (P[0]->p) - 1;
      }
      else
      {
         ispis_stanja(0);
         if (P[0] != NULL)
            P[0]->p = (P[0]->p) - 1;
         //printf("sada je %d\n", P[0]->p);
      }
   }
   else
   {
      ispis_stanja(0);
   }
}

int main()
{
   ispis_stanja(1); // ova implementacija odbija dretve koje dođu u t=0, mislim da je to prirodno
   sleep(1);
   t++;
   while (1)
   {
      //printf("TESTIRANJE: %d %d %d %d\n", P[0]->id, P[0]->p, P[0]->prio, P[0]->rasp);
      ispitajImaLiDolaznih();
      obradi();
      sleep(1);
      t++;
   }
}