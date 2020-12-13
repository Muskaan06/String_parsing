#define MEMORY_ALLOCATION_FAILED 0
#define MAX_INPUT_STRING_BYTES 500
#define MAX_SUBSTRING_BYTES 150

//function prototypes
int string_parsing(const char *,const char *);
int length_of_input_string(const char *);
char * allocating_memory(int);
char * array_to_null(char *);
char * add_space_at_end(char *,int);

//to take input from user
void input_main()
{
    
    char * input_string;char * sub_string;
    int length;
    
    input_string=allocating_memory(MAX_INPUT_STRING_BYTES);
    sub_string=allocating_memory(MAX_SUBSTRING_BYTES);
    
    if(input_string==0 || sub_string==0)
        printf("\nMemory allocation failed");
    
    printf("\nenter the string of not more than 500 bytes: ");
    scanf("%[^\n]s",input_string);
    printf("\nenter the substring of less than 150 bytes: ");
    scanf("%s",sub_string);
    
    length=length_of_input_string(input_string);
    add_space_at_end(input_string, length);
    
    string_parsing(input_string,sub_string);
    
    free(input_string);
    free(sub_string);
    
}

//to perform string parsing
int string_parsing(const char * input_string_ptr,
                   const char * sub_string_ptr)
{
    
    int received_length_input_string;int recieved_length_substring;
    int counter=0;int i=0;int occurr=0;int j=0;int position[5];int k=0;
    char * temp_variable;char * temp_variable2;
    
    received_length_input_string=length_of_input_string(input_string_ptr);
    printf("\n\nstring length: %d\n",received_length_input_string);
    recieved_length_substring=length_of_input_string(sub_string_ptr);
    printf("\n\nsubstring length: %d\n",recieved_length_substring);
    
    temp_variable=allocating_memory(20);
    if(temp_variable==0)
        printf("\nMemory allocation error");
    
    temp_variable2=allocating_memory(recieved_length_substring);
    if(temp_variable2==0)
        printf("\nMemory allocation error");
    
    while(1)
    {
        
            if(received_length_input_string>MAX_INPUT_STRING_BYTES ||
               recieved_length_substring>MAX_SUBSTRING_BYTES )
            {
                printf("\n\ninput string exceeded the number of bytes");
                break;
            }
            else
            {
                while(counter!=received_length_input_string)                                                                          //will run till the end of input user string
                {
                    array_to_null(temp_variable);i=0;
                    while(input_string_ptr[counter]!= ' ' )                                                                         //this while loop will extract each word from the string
                    {
                            while(temp_variable[i]!='\0')
                                i++;
                            temp_variable[i]=input_string_ptr[counter];
                            counter++;
                    }
                    add_space_at_end(temp_variable, length_of_input_string(temp_variable));
                    i=0;
                    while(temp_variable[i]!=' ')                                                                              //this loop will extract the word of length similiar to the substring length
                    {
                        array_to_null(temp_variable2);j=0;
                        while (j<recieved_length_substring)
                        {
                            temp_variable2[j]=temp_variable[i];
                            j++;
                            i++;
                        }
                        i=i-(recieved_length_substring-1);
                        if((strcmp(temp_variable2,sub_string_ptr))==0)
                        {
                            occurr++;
                            position[k]=counter-length_of_input_string(temp_variable)+i;
                            k++;
                        }
                    }
                    counter++;
                }
            }
            break;
        
    }
    
    if(occurr==0)
        printf("\ndoes not occurr");
    else
    {
        printf("\n\noccurrence: %d at positions: ",occurr);
        for(k=0;k<occurr;k++)
            printf("%d, ",position[k]);
    }
    
    printf("\n");
    free(temp_variable);
    free(temp_variable2);
    return 0;
    
}

//to calculate length of a string
int length_of_input_string(const char * argument_string)
{
    
    int count=0;
    while(argument_string[count]!='\0')
    {
        printf("%c",argument_string[count]);
        count++;
    }
    return count;
    
}

//allocating memory to the strings
char * allocating_memory(int max_size)
{
    
    char * argument_string=(char *)malloc(max_size*(sizeof(char)));
    if(argument_string==NULL)
        return MEMORY_ALLOCATION_FAILED;
    else
        return argument_string;

}

char * array_to_null(char * temp_variable)
{
    
    int i;
    for(i=0;i<=sizeof(temp_variable);i++)
        temp_variable[i]='\0';
    return temp_variable;

}

//adding space at the end of the string
char * add_space_at_end(char * dummy_string,int size_of_string)
{
    int count;
    for(count=0;count<size_of_string;count++);
    dummy_string[count]=' ';
    return dummy_string;
}


//counter++;
//if((strcmp(temp_variable,sub_string_ptr))==0)
//occurr++;
