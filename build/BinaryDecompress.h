#include "Libraries.h"

void Binary_Decompress(const char* input_name ,const char* output_name)
{

    FILE* input = fopen(input_name , "rb");
    FILE* output = fopen(output_name , "w");

  
    char Sign;
    char Sign_Number;
    
    
    int data;

    printf("Output:");

    while((data=fread(&Sign_Number,sizeof(char),1,input))!=0)
        {
            fread(&Sign,sizeof(char),1,input);
           

            for(int i=0;i<Sign_Number;i++)
            {
                fputc(Sign,output);
                printf("%c" , Sign);
            }



        }
    printf("\n");


    if(!feof(input))
    {
        printf("Nepodarilo sa precitat cely subor !\n ");
        exit(1);

    }


    fclose(input);
    fclose(output);

    return;
 
}
