#include "Libraries.h"
#include "Headers.h"


void Argv_Check(int vstup , int vystup)
{
    if(vstup == -1)
    {
        printf("Chyba vstupny subor ! Program nemoze pokracovat... \n");
        exit(1);


    }
     if(vystup == -1)
    {
        printf("Chyba vystupny subor ! Program nemoze pokracovat... \n");
        exit(1);
        

    }

     if(vstup == -1 && vystup == -1 )
   {
       printf("Chyba vstupny a vystupny subor ! Program nemoze pokracovat... \n");
       exit(1);

   }

    return;
}


int main(int argc , char* argv[])
{

    int result;

    int vstup = -1;
    int vystup = -1;
    int decompress = -1;
    int binary_decompress = -1;



    if(argc > 7  )
    {
        printf("Bol zadany zly pocet vstupnych argumentov\n");
        exit(1);
    } 

    
    for (int i = 0; i < argc ; i++)
    {
        if((result = strcmp (argv[i] , "-i")) == 0 )
        {
            vstup = i+1;



        }
        if((result = strcmp (argv[i] , "-o")) == 0 )
        {

            vystup = i+1;

        }
        if((result = strcmp (argv[i] , "-d")) == 0 )
        {

            decompress++ ;


        }
        if((result = strcmp (argv[i] , "-b")) == 0 )
        {

            binary_decompress++;


        }
        
    }

  
   Argv_Check(vstup , vystup);
   

   if(decompress == -1 && binary_decompress == -1)
   {
       Txt_Test(argv[vstup]);
       Print_Txt(argv[vstup]);
       Txt_Compress(argv[vstup] , argv[vystup]);
       Txt_Compare_Compress(argv[vstup] , argv[vystup]);


   }

    if(decompress == 0 && binary_decompress == -1)
   {
       Txt_Test(argv[vstup]);
       Print_Txt(argv[vstup]);
       Txt_Decompress(argv[vstup] , argv[vystup]);
       Txt_Compare_Decompress(argv[vstup] , argv[vystup]);


   }
     if(decompress == -1 && binary_decompress == 0)
   {
       Txt_Test(argv[vstup]);
       Print_Txt(argv[vstup]);
       Binary_Compress(argv[vstup] , argv[vystup]);
       Binary_Compare_Compress(argv[vstup] , argv[vystup]);


   }

    if(decompress == 0 && binary_decompress == 0)
   {
       Binary_Test(argv[vstup]);
       Print_Binary(argv[vstup]);
       Binary_Decompress(argv[vstup] , argv[vystup]);
       Binary_Compare_Decompress(argv[vstup] , argv[vystup]);


   }



    return 0 ;
}