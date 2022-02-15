#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int t = 0;              //simulacija vremena (trenutno vrijeme)
int brojDretviSada = 0; //pokazivat će indeks slobodnog mjesta u P

typedef struct dretva
{
   int id;   //1, 2, 3,
   int p;    //preostalo vrijeme rada
   int prio; //prioritet
   int rasp; //način raspoređivanja (za opcionalni zadatak)
   struct dretva *next;
} dretva;

dretva *head = NULL;

dretva *stvori_dretvu(int id, int p, int prio, int rasp)
{
   /* allocate node */
   dretva *nova_dretva = (dretva *)malloc(sizeof(dretva));

   /* put in the data  */
   nova_dretva->id = id;
   nova_dretva->p = p;
   nova_dretva->prio = prio;
   nova_dretva->rasp = rasp;
   nova_dretva->next = NULL;

   return nova_dretva;
}
void umetni_dretvu(dretva **head_p, dretva *nova_dretva)
{
   dretva *trenutna;
   //ako je prazno
   if (*head_p == NULL || (*head_p)->prio < nova_dretva->prio)
   {
      nova_dretva->next = *head_p;
      *head_p = nova_dretva;
   }
   else
   {
      //pronadi
      trenutna = *head_p;
      while (trenutna->next != NULL && trenutna->next->prio >= nova_dretva->prio)
      {
         trenutna = trenutna->next;
      }
      nova_dretva->next = trenutna->next;
      trenutna->next = nova_dretva;
   }
}
void printList(dretva *head)
{
   dretva *temp = head;
   while (temp != NULL)
   {
      printf("%d/%d/%d  ", temp->id, temp->prio, temp->p);
      temp = temp->next;
   }
}

dretva *makni_prvi_iz_liste(dretva *head)
{
   if (head == NULL)
      return NULL;

   dretva *temp = head;
   head = head->next;
   free(temp);
   return head;
}
#define MAX_DRETVI 5
#define DRETVI 6
int nove[DRETVI][5] =
    {
        /* trenutak dolaska, id, p, prio, rasp (prio i rasp se koriste ovisno o rasporedivacu) */
        {1, 3, 5, 3, 0}, /* rasp = 0 => PRIO+FIFO; 1 => PRIO+RR */
        {3, 5, 6, 5, 0},
        {7, 2, 3, 5, 0},
        {12, 1, 5, 3, 0},
        {20, 6, 3, 6, 0},
        {20, 7, 4, 7, 0}};

void ispis_stanja(int ispisi_zaglavlje)
{
   int i;
   if (ispisi_zaglavlje)
   {
      printf("  t    AKT");
      for (i = 1; i < MAX_DRETVI; i++)
         printf("     PR%d", i);
      printf("\n");
   }

   printf("%3d ", t);
   dretva *tren = head;
   for (i = 0; i < MAX_DRETVI; i++)
   {
      if (tren != NULL)
      {
         printf("  %d/%d/%d ", tren->id, tren->prio, tren->p);
         tren = tren->next;
      }
      else
         printf("  -/-/- ");
   }
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
         if (brojDretviSada < MAX_DRETVI)
         {
            dretva *new_node = stvori_dretvu(nove[i][1], nove[i][2], nove[i][3], nove[i][4]);
            umetni_dretvu(&head, new_node);
            brojDretviSada++;
         }
         else
         {
            printf("nema mjesta u redu\n");
         }
      }
   }
}

void obradi()
{
   if (head != NULL)
   {
      if (head->p == 0)
      {
         printf("Dretva %d je zavrsila.\n", head->id);
         brojDretviSada--;
         head = makni_prvi_iz_liste(head);
         ispis_stanja(0);
         if (head != NULL)
         {
            head->p = (head->p) - 1;
         }
      }
      else
      {
         ispis_stanja(0);
         if (head->rasp == 0) //FIFO
         {
            head->p = (head->p) - 1;
         }
         else
         {
            //printf("ovaj je RR\n");
            head->p = (head->p) - 1;
            dretva *um = stvori_dretvu(head->id, head->p, head->prio, head->rasp);
            head = makni_prvi_iz_liste(head);
            if (um->p > 0)
            {
               umetni_dretvu(&head, um);
            }
            else
            {
               printf("Dretva %d je zavrsila.\n", um->id);
            }
         }
      }
   }
   else
   {
      ispis_stanja(0);
   }
}
int main()
{
   ispis_stanja(1);
   sleep(1);
   t++;
   while (1)
   {
      ispitajImaLiDolaznih();
      obradi();
      sleep(1);
      t++;
   }
}

//shvatio sam da je pogreška u dodavanju dretve u linked listu, neće se uvijek dodati na kraj svoga prioriteta, ali sam kasno shvatio..