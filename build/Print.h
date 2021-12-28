#include "Libraries.h"

void Print_Txt(const char* input_name)
{
    FILE* input = fopen(input_name , "r");

    char Sign;
    int data;


  printf("Input:");

    while(1)
    {

         data = fread(&Sign,sizeof(char),1,input);

      
        if( data == 0)
        {
            break;
        }

        printf("%c" , Sign);
    }

     printf("\n");

      if(!feof(input))
    {
        printf("Nepodarilo sa precitat cely subor !\n ");
        exit(1);

    }

    fclose(input);


    return;


}



void Print_Binary(const char* input_name)
{
    FILE* input = fopen(input_name , "rb");

  
    int data;
    char Sign ;



  printf("Input:");

   while((data=fread(&Sign,sizeof(char),1,input))!=0)
        {
           
                printf("%d " , Sign);
              
        }

    printf("\n");


    if(!feof(input))
    {
        printf("Nepodarilo sa precitat cely subor !\n ");
        exit(1);

    }

    fclose(input);


    return;


}
