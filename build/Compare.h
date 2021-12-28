#include "Libraries.h"

void Txt_Test(const char* input_name)
{
    FILE* input = fopen(input_name , "r");
   
    fseek(input,0L , SEEK_END);

    long int res = ftell(input);
   

    if(res == 0)
    {
        printf("Vstupny subor je prazdny nie je mozne pokracovat...\n");
        exit(1);
    }


    fclose(input);
    
}

void Binary_Test(const char* input_name)
{
    FILE* input = fopen(input_name , "rb");
   
    fseek(input,0L , SEEK_END);

    long int res = ftell(input);
   

    if(res == 0)
    {
        printf("Vstupny subor je prazdny nie je mozne pokracovat...\n");
        exit(1);
    }


    fclose(input);
    
}

void Txt_Compare_Decompress(const char* input_name ,const char* output_name)
{
    FILE* input = fopen(input_name , "r");
    FILE* output = fopen(output_name , "r");


    fseek(input,0L , SEEK_END);
    fseek(output,0L , SEEK_END);

    long int res = ftell(input);
    long int res2 = ftell(output);

    float vys = (100.0 * res2 ) / (res * 1.0) ;

    printf("Velkost vstupneho suboru je %ld bajtov a Velkost vystupneho suboru je %ld bajtov\n" , res , res2 );
    printf("Pri Textovej Dekomprimacii bolo vyplitvanych %ld bajtov\n" , res2 - res );
    printf("Subor je o  %.2f %% vacsi po Dekomprimovani \n" , vys);

    fclose(input);
    fclose(output);


    
}

void Txt_Compare_Compress(const char* input_name ,const char* output_name)
{
    FILE* input = fopen(input_name , "r");
    FILE* output = fopen(output_name , "r");


    fseek(input,0L , SEEK_END);
    fseek(output,0L , SEEK_END);

    long int res = ftell(input);
    long int res2 = ftell(output);


    printf("Velkost vstupneho suboru je %ld bajtov a Velkost vystupneho suboru je %ld bajtov\n" , res , res2 );
    printf("Pri Textovej Komprimacii bolo usetrenych %ld bajtov\n" , res - res2 );

    res2 = res - res2;
    float vys = (100.0 * res2 ) / (res * 1.0); 

    printf("Subor je o  %.2f %% mensi po Komprimovani \n" , vys);

    fclose(input);
    fclose(output);



    
}

void Binary_Compare_Decompress(const char* input_name ,const char* output_name)
{
    FILE* input = fopen(input_name , "rb");
    FILE* output = fopen(output_name , "rb");


    fseek(input,0L , SEEK_END);
    fseek(output,0L , SEEK_END);

    long int res = ftell(input);
    long int res2 = ftell(output);

    

    printf("Velkost vstupneho suboru je %ld bajtov a Velkost vystupneho suboru je %ld bajtov \n" , res , res2 );
    printf("Pri Binarnej Dekomprimacii bolo vyplitvanych %ld bajtov\n" , res2 - res );

    float vys = (100.0 * res2 ) / (res * 1.0); 

    printf("Subor je o  %.2f %% vacsi po Dekomprimovani \n" , vys);

    fclose(input);
    fclose(output);


    
}

void Binary_Compare_Compress(const char* input_name ,const char* output_name)
{
    FILE* input = fopen(input_name , "rb");
    FILE* output = fopen(output_name , "rb");


    fseek(input,0L , SEEK_END);
    fseek(output,0L , SEEK_END);

    long int res = ftell(input);
    long int res2 = ftell(output);

    printf("Velkost vstupneho suboru je %ld bajtov a Velkost vystupneho suboru je %ld bajtov\n" , res , res2 );
    printf("Pri Binarnej Komprimacii bolo usetrenych %ld bajtov\n" , res - res2 );

    res2 = res - res2;
    float vys = (100.0 * res2 ) / (res * 1.0); 

    printf("Subor je o  %.2f %% mensi po Komprimovani \n" , vys);

    fclose(input);
    fclose(output);



    
}