/* write a program to apply grammer using english syntax rules.
*
/******************************************************************************
 *
 * @file    main.c
 * @author  Umesh Joshi,Dhrumil Mevada
 * @brief   Program to apply grammer using english syntax rules.
 * @date
 *          JUL/19/2018,Created
 *****************************************************************************/
 /*
###########################################
# Program to apply grammer to simple text #
###########################################

------------------------------------------
Input:
------------------------------------------
sample.txt:
    This is sample file Will this program
    work  Great it is working
------------------------------------------

------------------------------------------
Output:
------------------------------------------
result.txt:
    This is sample file. Wil this program
    work? Great! it is working.
------------------------------------------

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$               Pseudocode               $
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

1. Initialize File pointer
2. Initialize Flag Array
3. Initialize Buffer to hold data
4. Read data from file and hold that into Buffer
5. Initialize two dimensional char array to hold words
   - Extract words from buffer and get into words array
   - Free memory of Buffer
6.While(words[i] != NULL)
    - set flags for 3 elements
        [words[i],words[i+1],words[i+2]] = [-1,-1,-1]
        `Initially they all will be -1
    - check word[i] for case
        If capital then flag[0] will be 0
        If lower then flag[0] will be 1
    -check word[i+1] (middle element)
        - Use first and last word for refernece
            If any successive elements are capitals
                It is name
                    - check data set for possible match
                        - If found skip next step
                        - If not found It is name   
                            - Add : at end of that word
            else
                check dataset with middle elemet
                    - If found match apply logic
                Rotate letters
                    - Middle word -> First word
                    - Last word -> Middle word
                    - First word -> Last word
                set flag of last word -1
            goto step 6
    - move to next 3 elemets and perform loop
7. Write changed words into result file
8. Free memory

*********************************************
*                 Example                   *
*********************************************

words = { "Umesh", "This", "is", "sample", "file",
          "Dhrumil","Is","it","working"}
loop:
    words:flag -> {"Umesh":-1, "This":-1, "is":-1}
    `checking first element
    words:flag -> {"Umesh":0, "This":-1, "is":-1}
                      ^ Capital found
    'checking middle element
    words:flag -> {"Umesh":0, "This":1, "is":-1}
                                ^ keyword found
    `rotate elements
    words:flag -> {"Umesh":0, "is":-1, "This": 1}
                                ^ No change
    `rotate 2 times to get back data
    `Output
    words:flag -> {"Umesh : ":0, "This":-1, "is":-1}
                        ^ : Applied
    
    perform for all data

Output:
    words = { "Umesh : ", "This", "is", "sample", "file.",
          "Dhrumil : ","Is","it","working ?"}
*/


#include "main.h"
#include "correction.h"

/** Function    main
 * @date        JUL/19/2018
 * @brief       Main function of the program.
 * @param       int: argc: # of command line arguments
 *	        	char *: argv: the char array to hold each command line arg.
 * @return      int: the result of execution.
 *		        0: success
 *		        -ve: on various failures.
 *                  -1: if command line is incorrect.
 */

int main(int argc, char **argv){
    FILE *fptr;
    char *filename;
    char data[200]; // data read from
    short int i = 0;
    filename = argv[1];
    fptr = fopen(filename, "r");
    fgets(data, 200, fptr); //  get strings from file
    // fprintf(stdout, "%s", data);
    fclose(fptr);
    char *p = strtok(data, " ");
    char *words[10];
    while(p != NULL){
        words[i++] = p;
        p = strtok(NULL, " ");
    }
    printLine();
    for(i = 0;i < (int)(sizeof(words)/sizeof(words[0])); i++){
        fprintf(stdout, "word[%d]:\t%s\n",i,words[i]);
    }
    return 0;
}


/* function	put_question_mark
*  @date 	18/07/2018
*  @brief	to find out the end of sentence and put question mark
*  @param	char three_word_array : it contain set of three word from paragraph 		
*		flag_array[] : it contain detail of whether first letter of each word in 
*				three_word_array is capital or not 
*				0 :lowercase character
*				1: uppercase character
*		int pfinal_array : pointing the index from where we can add remaning sentence 
* @return 	null
*/
int put_question_mark(char three_word_array[][15],int flag_array[],char final_array[][15],int pfinal_array)
{
	while(flag_array[0]!=0 && flag_array[1]!=0 && flag_array[1]!=1)   //loop to check final array content
	{
		swap_three_word_array(int end_p_word_array,char three_word_array[][15],int flag_array[]);  //move to next word
		
		if(flag_array[0]==0 && flag_array[1]==0 && flag_array[1]==1) //satisfied when end of array fonud 
		{
			for(;start_p_word_array < (end_p_word_array-1);start_p_word_array++)
			{
				strcpy(final_array[pfinal_array++],word[start_p_word_array]); //copy all the word to final array
			}
			final_array[pfinal_array] = "?";
		}	
		start_p_word_array = end_p_word_array -1;
	}
return 0;
}


/* function	put_exclametion_mark
*  @date 	18/07/2018
*  @brief	to find out the exclametion word and put question mark
*  @param	char three_word_array : it contain set of three word from paragraph 		
*		flag_array[] : it contain detail of whether first letter of each word in 
*				three_word_array is capital or not 
*				0 :lowercase character
*				1: uppercase character
*		int pfinal_array : pointing the index from where we can add remaning sentence 
* @return 	null
*/
int put_exclametion_mark(char three_word_array[][15],int flag_array[],char final_array[][15],int pfinal_array)
{
	for(;start_p_word_array < (end_p_word_array-1);start_p_word_array++) //loop to add exclametion mark and to copy word final array 
	{
		if(start_p_word_array == end_p_word_array - 1)
		{
			final_array[pfinal_array++] = "!";  //put exclametion mark at proper location
			break; 			
		}
		strcpy(final_array[pfinal_array++],word[start_p_word_array]);  //copy the content to final array
	}
	swap_three_word_array(int end_p_word_array,char three_word_array[][15],int flag_array[]); //swap three word array
	start_p_word_array = end_p_word_array - 1 //set the start pointer of word array
}
