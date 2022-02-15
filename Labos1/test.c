#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int t = 0;      //simulacija vremena (trenutno vrijeme)
int indeks = 0; //pokazivat će indeks slobodnog mjesta u P

typedef struct dretva
{
   int id;   //1, 2, 3,
   int p;    //preostalo vrijeme rada
   int prio; //prioritet
   int rasp; //način raspoređivanja (za opcionalni zadatak)
   struct dretva *next;
} dretva;

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
int main()
{
   dretva *head = NULL;
   dretva *new_node = stvori_dretvu(3, 1, 3, 1);
   umetni_dretvu(&head, new_node);
   new_node = stvori_dretvu(1, 1, 3, 1);
   umetni_dretvu(&head, new_node);
   printList(head);

   printf("\n");
   system("pause");
   return 0;
}