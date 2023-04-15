#include<stdarg.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
// To convert integers values to they string representation ex: 3 to '3', 12 to "12"
char* interger_to_string_convertor(int int_to_converte,char* str_representation_of_int){
   int is_negative=0;
    if(int_to_converte==0){
        str_representation_of_int[0]='0';
        str_representation_of_int[1]='\0';
    }
    if(int_to_converte<0){
        is_negative=1;
        int_to_converte =-1*int_to_converte;
    }
    if(int_to_converte>0){
        int index_to_store_each_char=0;
        while(int_to_converte>0){
            str_representation_of_int[index_to_store_each_char]=int_to_converte %10 + '0';
            int_to_converte=int_to_converte/10;
            index_to_store_each_char++;
        }
        if(is_negative){
            str_representation_of_int[index_to_store_each_char]='-';
            index_to_store_each_char++;
        }
        //reverse
        str_representation_of_int[index_to_store_each_char]='\0';
        int len =strlen(str_representation_of_int);
        char temp;
        for(int i=0,j=len-1;i < j;i++,j--){
            temp=str_representation_of_int[i];
            str_representation_of_int[i]= str_representation_of_int[j];
            str_representation_of_int[j]=temp;
        }
    }
    return str_representation_of_int;
}
//Take a decimal integer and return octal integer
int decimal_to_octal(int int_to_converte){
    int octal_integer=0;
    int place=1;
    if(int_to_converte==0){
        return octal_integer;
    }else{
       while(int_to_converte!=0){
        octal_integer +=(int_to_converte %8)*place;
        int_to_converte /=8;
        place *=10;
       }
       return octal_integer;
    }
     
}
//decimal to hexa
char* decimal_to_hexadecimal(int int_to_converte){
    char* hexadecimal_nb=(char*)malloc(sizeof(char*));
    char hexadecimal_digits[16]="0123456789ABCDEF";
    int index=0;
    if(int_to_converte==0){
       hexadecimal_nb[index]='0';
       hexadecimal_nb[index+1]='\0';
    }else{
     while(int_to_converte!=0){
        hexadecimal_nb[index]=hexadecimal_digits[int_to_converte %16];
        int_to_converte /= 16;
        index++;
    }
    int len =strlen(hexadecimal_nb);

    //reverse
    char temp;
    for(int i=0,j=len-1;i<j;i++,j--){
        temp=hexadecimal_nb[i];
        hexadecimal_nb[i]=hexadecimal_digits[j];
        hexadecimal_nb[j]=temp;
    }
    hexadecimal_nb[index]='\0';

    }
    return hexadecimal_nb;
  
}

char* decimal_to_hexadecimal_for_adrs(unsigned long long int int_to_converte){
    char* hexadecimal_nb=(char*)malloc(sizeof(char*));
    char hexadecimal_digits[16]="0123456789abcdef";
    int index=0;
    if(int_to_converte==0){
       hexadecimal_nb[index]='0';
       hexadecimal_nb[index+1]='\0';
    }else{
     while(int_to_converte!=0){
        hexadecimal_nb[index]=hexadecimal_digits[int_to_converte %16];
        int_to_converte /= 16;
        index++;
    }
    int len =strlen(hexadecimal_nb);

    //reverse
    char temp;
    for(int i=0,j=len-1;i<j;i++,j--){
        temp=hexadecimal_nb[i];
        hexadecimal_nb[i]=hexadecimal_nb[j];
        hexadecimal_nb[j]=temp;
    }
    hexadecimal_nb[index]='\0';

    }
    return hexadecimal_nb;
  
}
// The main function of the My printf project  
int my_printf(char* principal_string,...){
    va_list additional_arguments;
    int nub_of_bit_to_ret=0;
    va_start(additional_arguments, principal_string);

    while (*principal_string!='\0') {
     if(*principal_string=='%'){
         principal_string++;
         switch(*principal_string) {   
         case 'd':
         {
          int integer_to_print_out=va_arg(additional_arguments,int);
          char* str_representation_of_int = (char*)malloc(sizeof(integer_to_print_out));
          str_representation_of_int =interger_to_string_convertor(integer_to_print_out,str_representation_of_int);
          nub_of_bit_to_ret += write(1,str_representation_of_int,strlen(str_representation_of_int));
         }
         break;
         case 'o':
         {
          int integer_to_print_out=va_arg(additional_arguments,int);   //retrieve the decimal value gave as argument 
          integer_to_print_out=decimal_to_octal(integer_to_print_out); //convert it to octal integer
          char* str_representation_of_int = (char*)malloc(sizeof(integer_to_print_out));
          str_representation_of_int =interger_to_string_convertor(integer_to_print_out,str_representation_of_int);
          nub_of_bit_to_ret += write(1,str_representation_of_int,strlen(str_representation_of_int));
         }
         break;
         case 'u':
         {
         
          int integer_to_print_out=va_arg(additional_arguments,int);
          char* str_representation_of_int = (char*)malloc(sizeof(integer_to_print_out));
          str_representation_of_int =interger_to_string_convertor(integer_to_print_out,str_representation_of_int);
          nub_of_bit_to_ret += write(1,str_representation_of_int,strlen(str_representation_of_int));
         }
         break;
          case 'x':
         {
             
          int integer_to_print_out=va_arg(additional_arguments,int);   //retrieve the decimal value gave as argument 
          char* str_representation_of_int = (char*)malloc(sizeof(integer_to_print_out));
          str_representation_of_int= decimal_to_hexadecimal(integer_to_print_out);
          nub_of_bit_to_ret += write(1,str_representation_of_int,strlen(str_representation_of_int));
         }
         break;
         case 'c':
         {
             char character_to_print_out = va_arg(additional_arguments,int);
             nub_of_bit_to_ret += write(1,&character_to_print_out,1);
         }
         break;
         case 's':
         {
             char* chain_of_char_to_print_out = va_arg(additional_arguments,char*);
             if(chain_of_char_to_print_out!=NULL){
             int len=strlen(chain_of_char_to_print_out);
             nub_of_bit_to_ret += write(1,chain_of_char_to_print_out,len);
             }else{
                 char* chain_of_char_to_print_out="(null)";
                 int len=strlen(chain_of_char_to_print_out);
                 nub_of_bit_to_ret += write(1,chain_of_char_to_print_out,len);
             }
             
         }
         break;
         case 'p':
         {
             char prefix[2]="0x";
             void* address_to_print_out = va_arg(additional_arguments,void*);
             unsigned long long int address_in_int =(unsigned long long int)address_to_print_out;
             char* str_representation_of_address_int = (char*)malloc(sizeof(char*)); 
             str_representation_of_address_int =decimal_to_hexadecimal_for_adrs(address_in_int);
             strcat(prefix,str_representation_of_address_int);//concatenate the str representation of the hexadecimal to the prefix
             strcpy(str_representation_of_address_int,prefix);// coping the entire chain concatened from prefix variable to main variable "str_representation_of_address_int"
             nub_of_bit_to_ret += write(1,str_representation_of_address_int,strlen(str_representation_of_address_int));

         }
         
     }
    }else{
     nub_of_bit_to_ret += write(1,principal_string,1);
    }
  principal_string++;
}

va_end(additional_arguments);
return nub_of_bit_to_ret ;
 }
int main(){

   int ret_v = my_printf("%p!\n",0x7fe2d8c0e79e);
   printf("%x",ret_v);
    return 0;
}
