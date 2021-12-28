#include "Libraries.h"

void allocate_Array(char** count_char )
{
    *count_char = (char*)malloc(sizeof(char) * 2);



    return;
}
void deallocae_array(char** count_char)
{
    free(*count_char);
    *count_char = NULL;

    return;
}

void Txt_Compress(const char* input_name ,const char* output_name)
{

    FILE* input = fopen(input_name , "r");
    FILE* output = fopen(output_name , "w");

    char* count_char = NULL;

    int count = 1;
    int data;

    char First_Sign;
    char Second_Sign;


    allocate_Array(&count_char);

    fread(&First_Sign,sizeof(char),1,input);

    printf("Output:");

    while(1)
    {
        
        data = fread(&Second_Sign,sizeof(char),1,input);

        if( data == 0)
        {
            break;
        }



     
        if(First_Sign==Second_Sign)
        {
            if(count==9)
            {
                sprintf(count_char,"%d",count);

                fwrite(count_char, 1 , sizeof(char) , output );
                fwrite(&First_Sign , 1 , sizeof(char) , output );

                printf("%d" , count);
                printf("%c" , First_Sign);
                
                count = 0;
               
            }


            count++;
            

        }

        if(First_Sign != Second_Sign)
            {
                
                sprintf(count_char,"%d",count);

                fwrite(count_char , 1 , sizeof(char) , output );
                fwrite(&First_Sign , 1 , sizeof(char) , output );

                printf("%d" , count);
                printf("%c" , First_Sign);
                

                count =1;
              
                
            }


            First_Sign=Second_Sign;


    }


    sprintf(count_char,"%d",count);

    fwrite(count_char , 1 , sizeof(char) , output );
    fwrite(&First_Sign , 1 , sizeof(char) , output );

    printf("%d" , count);
    printf("%c\n" , First_Sign);
             


    if(!feof(input))
    {
        printf("Nepodarilo sa precitat cely subor !\n ");
        exit(1);

    }


    fclose(input);
    fclose(output);
    
    deallocae_array(&count_char);

    return;

}


   


    




