#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *Buff;
    char *nombre[5];
    

   for (int i = 0; i < 5; i++)
   {
      printf("Ingrese un nombre: "); 
      Buff= (char *) malloc(100*sizeof(char));   
      gets(Buff);
      nombre[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
      strcpy(nombre[i],Buff);
   }

   for (int i = 0; i < 5; i++)
   {
      puts(nombre[i]);
      free(nombre[i]);   
   }
   
   free(Buff);
   
   
    return 0;
}
