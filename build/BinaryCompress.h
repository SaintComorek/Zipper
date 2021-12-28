#include "Libraries.h"

void Binary_Compress(const char* input_name ,const char* output_name)
{

    FILE* input = fopen(input_name , "r");
    FILE* output = fopen(output_name , "wb");

    uint8_t count = 1;

    char First_Sign;
    char Second_Sign;

    int data;
    int Integer_Sign;
   

    printf("Output:");

    fread(&First_Sign,sizeof(char),1,input);
    
    while(1)
    {
        
        data = fread(&Second_Sign,sizeof(char),1,input);

        if( data == 0)
        {
            break;
        }

        Integer_Sign = First_Sign;
        
        if(First_Sign==Second_Sign)
        {
            if(count==255)
            {
                
                fwrite(&count,sizeof(char),1,output);
                fwrite(&Integer_Sign,sizeof(char),1,output);

                printf("%d " , count);
                printf("%d " , Integer_Sign);

                count = 0;
                
            }


            count++;
            

        }
        if(First_Sign!=Second_Sign)
            {
                
                fwrite(&count,sizeof(char),1,output);
                fwrite(&Integer_Sign,sizeof(char),1,output);

                printf("%d " , count);
                printf("%d " , Integer_Sign);

                count =1;
                
                
            }


            First_Sign=Second_Sign;

    }
    
    fwrite(&count,sizeof(char),1,output);
    fwrite(&Integer_Sign,sizeof(char),1,output);

    printf("%d " , count);
    printf("%d \n" , Integer_Sign);

    



     if(!feof(input))
    {
        printf("Nepodarilo sa precitat cely subor !\n ");
        exit(1);

    }


 

    fclose(input);
    fclose(output);

   
    return;

}
