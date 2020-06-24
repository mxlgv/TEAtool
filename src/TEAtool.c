#include <stdio.h>
#include "tea.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define ENCRYPT 1
#define DECRYPT 2

typedef unsigned char flag; 
uint32_t key[4];

long size_file(FILE* file)
{
    fseek(file, 0, SEEK_END); 
    long size = ftell(file); 
    fseek(file, 0, SEEK_SET);
    if(size%8==0)
    {
        return size;
    }
    else 
    {
        return (size/8+1)*8;
    }


}

void xxcrypt_file(char *in_file, char* out_file, char arg)
{
    int i=1;
    uint32_t temp_block[2];
    FILE *input, *output;
    output = fopen(out_file,"wb");
    if((input = fopen(in_file,"rb"))==NULL) 
    {
        printf("File '%s' not found\n!", in_file);
        exit(1);
    }
    else
    {  
        long size_f=size_file(input);
        if(arg==ENCRYPT){
            while(ftell(output)!=size_f){   
                if(!fread(&temp_block, sizeof(uint32_t), 2, input))
                {
                    temp_block[0]=0x00000000;
                    temp_block[1]=0x00000000;
                }
                TEA_encrypt(temp_block,key);
                fwrite(temp_block, sizeof(uint32_t), 2, output);
            }
            fclose(input);
            fclose(output);
            printf("Data from file: %s successfully ENCRYPTED to file: %s\n",in_file,out_file);
            exit(0);

          }
          else if(arg==DECRYPT){
            while(ftell(output)!=size_f){   
                if(!fread(&temp_block, sizeof(uint32_t), 2, input))
                {
                    temp_block[0]=0x00000000;
                    temp_block[1]=0x00000000;
                }
                TEA_decrypt(temp_block,key);
                fwrite(temp_block, sizeof(uint32_t), 2, output);
               }
            }
            fclose(input);
            fclose(output);
            printf("Data from file: %s successfully DECRYPTED to file: %s\n",in_file,out_file);
            exit(0);   
        }
}
    
    



void str_to_strkey(char *str, char str_key[4][9])
{
    int count=0;
    for(int i=0; i<4; i++)
    {
        int j=0;
        while (j<8)
        {
            str_key[i][j]=str[count];
            count++;
            j++;
        }
    }
}

int valid_key(char *str)
{
    int count=0;
    char hex[]={"abcdefABCDEF0123456789"};
    int *p;
    for(int i=0; i<32; i++)
    { 
        if(strchr(hex,str[i])!=NULL)
        {
            count++;
        }       
     }
     if(count==32){return 1;}
     else{ return 0;}
}


void key_con_read(char *str)
{
    char str_key[4][9];
    if(valid_key(str) && (32==strlen(str)))
    {
        for(int i=0; i<4; i++)
        {
            str_to_strkey(str, str_key);
            key[i]=(uint32_t)strtol(str_key[i],NULL,16);
        }
    }

    else 
    {
        printf("Invalid key format!\n");
        exit(-1);
    }   
}


void key_file_read(char *key_file)
{
    char temp_key[32];
    FILE *keyfile;
    if((keyfile = fopen(key_file,"r"))==NULL) 
    {
        printf("File '%s' not found!\n", key_file);
        exit(1);
    }
    for(int i=0; i<32; i++)
    {
        temp_key[i]=fgetc(keyfile);
    }

    key_con_read(temp_key);
}



void findopt(int argc, char *argv[],char *in_file, char *out_file)
{
    char found=0;
    for(int j=3; j<argc; j++)
    {
        if(!strcmp(argv[j],"-k"))
        {
            found=1;
            key_con_read(argv[j+1]);
            break;
        }
        else if(!strcmp(argv[j],"-K"))
        {
            found=1;
            key_file_read(argv[j+1]);
            break;
        }    
    }

    if(!found)
    {
        printf("No key or key file!\n");
        exit(-1);
    }
    
    
    for(int i=3;i<argc; i++){
        if(!strcmp(argv[i],"-e"))
        {
           xxcrypt_file(in_file, out_file, ENCRYPT);
        }
        if(!strcmp(argv[i],"-d"))
        {
            xxcrypt_file(in_file, out_file, DECRYPT);   
        }
        
    }
    printf("Invalid arguments! Use the help: -h\n");
    exit(0);   
}




int main(int argc, char **argv)
{
   if(argc==6)
   {
         findopt(argc,argv, argv[1],argv[2]);
   }
   else if(argc==2 && !strcmp(argv[1],"-a"))
   {
    puts("\n");
    printf("      )  (         TEAtool     \n");
    printf("     (   ) )                   \n");
    printf("      ) ( (        Version:    \n");    
    printf("    _______)_     1.0-stable   \n");
    printf(" .-'---------|                 \n");
    printf("( C|/////////|      Author:    \n");
    printf(" '-./////////|   turbocat2001  \n");
    printf("   '_________'                 \n");
    printf("   '-------''   License: GPLv3 \n");
    printf("          Powered by:           \n");
    printf("  Tiny Encryption Algorithm.  \n\n");
       exit(0);
   }
   
   else if(argc==2 && !strcmp(argv[1],"-h"))
   {
       printf("Usage: \nTEAtool [infile] [outfile] [arguments]\n\nArguments: \n-e  Encrypt file\n-d  Decrypt file\n-k  [128bit-key in hex format]\n-K  [File key]\n-h  This reference\n-a  About the program \n");
       exit(0);
   }
   
   
   else
   {
       printf("Invalid arguments! Use the help: -h!\n");
       exit(0);
   }
   
 return 0;
   
}

