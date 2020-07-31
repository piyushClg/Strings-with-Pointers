#include <stdio.h>

int compareString(char*, char*);
void copystring(char*, char*);
void palindrome(char* string);
int stringlength(char*); 
void reverse(char*);
int getSubString(char *source, char *target,int from, int to);


int main()
{
    char str1[100], str2[100], result;
    int j, d, from, to;
    
    printf("\nEnter first string: ");
    gets(str1);
    
    do{
        printf("\nString Operations:\n");
        printf("1.Compare two strings\n");
        printf("2.Copy a string\n");
        printf("3.Reverse a string\n");
        printf("4.Palindrome\n");
        printf("5.Substring \n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&d);
        
        switch(d){
            case 1: //Compare two strings
                printf("Enter second string\n");
                scanf("%s", str2);
             
                result = compareString(str1, str2);
             
                if ( result == 0 )
                   printf("Both strings are same.\n");
                else
                   printf("Entered strings are not equal.\n");
                break;
            
            case 2: //Copy a string
                copystring(str2, str1);    
                printf("Copied string is \"%s\"\n", str2);
                break;
            
            case 3: //Reverse a string
                copystring(str2, str1);
                reverse(str2);
                printf("\nReverse of entered string is \"%s\".\n", str2);
                break;
                    
            case 4: //palindrome
                palindrome(str1);
                break;
            
            case 5: //Substring
                printf("Enter from index: ");
            	scanf("%d",&from);
            	printf("Enter to index: ");
            	scanf("%d",&to);	
            	
            	printf("String is: %s\n",str1);
            	
            	if(getSubString(str1,str2,from,to)==0)
            	    printf("Substring is: %s\n",str2);
                else
                    printf("Function execution failed!!!\n");
                break;
            
            case 6:
                printf("Thank you for using :)");
                exit(0);
            
            default:
                printf("Out of range");
                break;
        }
        
        printf("Do you want to enter more(1-yes, 2-no): ");
        scanf("%d", &j);
        
    }while(j == 1);
    
    return 0;
}

int compareString(char *str1, char *str2)
{
   while(*str1==*str2)
   {
      if ( *str1 == '\0' || *str2 == '\0' )
         break;
 
      str1++;
      str2++;
   }
   if( *str1 == '\0' && *str2 == '\0' )
      return 0;
   else
      return -1;
}

void copystring(char *str2, char *str1)
{
    while(*str1)
    {
        *str2 = *str1;        
        str1++;        
        str2++;
    }    
    *str2 = '\0';
}

void palindrome(char* string) 
{ 
    char *ptr, *rev; 
  
    ptr = string; 
  
    while (*ptr != '\0') { 
        ++ptr; 
    } 
    --ptr; 
  
    for (rev = string; ptr >= rev;) { 
        if (*ptr == *rev) { 
            --ptr; 
            rev++; 
        } 
        else
            break; 
    } 
  
    if (rev > ptr) 
        printf("'%s' is Palindrome\n", string); 
    else
        printf("'%s' is not a Palindrome\n", string); 
}

void reverse(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = stringlength(string);
   begin  = string;
   end    = string;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
 
int stringlength(char *pointer)
{
   int c = 0;
 
   while( *(pointer + c) != '\0' )
      c++;
 
   return c;
}

int  getSubString(char *source, char *target,int from, int to)
{
	int length=0;
	int i=0,j=0;
	
	while(source[i++]!='\0')
		length++;
	
	if(from<0 || from>length){
		printf("Invalid \'from\' index\n");
		return 1;
	}
	if(to>length){
		printf("Invalid \'to\' index\n");
		return 1;
	}	
	
	for(i=from,j=0;i<=to;i++,j++){
		target[j]=source[i];
	}
	
	target[j]='\0'; 
	
	return 0;	
}
