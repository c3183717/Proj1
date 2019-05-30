// Name: Jackson Paul	
// Student Number: C3183717
// Date: 13/05/2019 
// Extension Granted: 13/05.2019
// Laboratory Time: Thursday 5-8pm
// Program Description: The following program has been designed to adhere to tasks 1-5 outlined in programming Assignment 1
//       				Throughout the code variables and function have been given obvious names this is intended as it will reduce 
//						the need for copius amounts of commenting. I will be providing adequate commenting but nothing over the top
//						as if someone who is interested in reading the code must have some knowledge on what the code is intended 
//						to do.

#include <stdio.h>
#include <string.h>


void RotEnrypt(char *message, int key);                               //Funtion Declaration for Task 1 (1 Mark)
void RotDecrypt(char *message, int key);						      //Funtion Declaration for Task 2 (1 Mark)	
void SubEncrypt(char *message, char *encryptKey);		              //Funtion Declaration for Task 3 (1 Mark)
void SubDecrypt(char *message, char *encryptKey);			          //Funtion Declaration for Task 4 (1 Mark)
void RotDecrypt_Without_Key(char *message, int key);				  //Funtion Declaration for Unseen Rotation Cipher Task (0.5 Marks) 


int main()
{
//_________________________________________________________________________________________________________________________________________________
//Declaration of variable used throughout the main function 

char encryptKey[27];
char message[100];    /* variable that will store the string of text entered by the user */
int key;			  /* Rotation amount */
int option;			  /* variable to store users option for what happens to entered text */
int c;				  /* Temporary Variable for storing user input */
char letter;

//_________________________________________________________________________________________________________________________________________________
// Intial Welcome message followed by the user input


printf("Welcome to Jackson's Fantastic Encryption/Decryption Tool: \n");
printf("Please Enter the The Text You Wish to Encrypt/Decrypt: \n");
scanf("%[^\n]%*c",message);

//_________________________________________________________________________________________________________________________________________________
// User option choice menu

printf("Select option to be completed\n");
printf("1. Encrypt the entered message with a rotation cipher with a given key\n");
printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only \n");

//_________________________________________________________________________________________________________________________________________________
// Reading user's choice and storing to "option"

scanf("%d", &option);
//_________________________________________________________________________________________________________________________________________________
// While Loop that will continually ask user input if the user enters incorrect choice

while(option>5||option<1){
	printf("Incorrect Option Chosen Please Choose again -->");
	scanf("%d", &option);
}

printf("You Have Chosen Option %d\n", option);

//_________________________________________________________________________________________________________________________________________________
   // Switch case statements containing:
   // Case 1: Task 1 
   // Case 2: Task 2 
   // Case 3: Task 3
   // Case 4: Task 4
   // Case 5: Task 5 

switch (option) {
    case 1:
                   RotEnrypt(message, key);
                    break;
  
    case 2:
                    RotDecrypt(message, key);
                        break;
  
    case 3:
                    SubEncrypt(message, encryptKey);
                        break;
  
    case 4:
                    SubDecrypt(message, encryptKey);
                        break;
  
    case 5:         RotDecrypt_Without_Key(message, key);
                        break;
  
    default:
    printf("Please enter an integer between 1 and 5");
    break;
      
} // end switch case
//_________________________________________________________________________________________________________________________________________________
return 0;
} 

// End Of Main Function

//_________________________________________________________________________________________________________________________________________________
// The following section cointains all code for the function declarations seen at the begining of the program

//_________________________________________________________________________________________________________________________________________________
// Funtion for rotation cipher encryption (Task 1)

void RotEnrypt(char *message, int key) {                                                       //RotEnrypt function with parameters message(pointer) and key
    printf("Enter plaintext to be encypted: ");
                   printf("%s\n", message);
                   printf("Enter key:\n ");                                                    
                   scanf("%d",&key);														   //Taking user's input for key
                   printf("Read %d\n", key);
                   int iteration;															   //Declaring "iteration" integer
                   char letter;
                  
                   for(iteration = 0; message[iteration] != '\0'; ++iteration){                //Iterating through each character in message
                       letter = message[iteration];                                            //letter is the character of message
                      
                       if(letter >= 'A' && letter <= 'Z'){
                           letter = letter + key;
                          
                           if(letter > 'Z'){                                                   //Nested if ... if letter is greater than Z than
                               letter = letter - 'Z' + 'A' - 1;								   //Example: letter = Z+4 ==> letter= Z+4 -Z + A -1==> letter= D
                           }
                          
                           message[iteration] = letter;										   //Replacing new character in place of old character in message
                       }
                      
                      
                       else if(letter >= 'a' && letter <= 'z'){								   //If letter is lower case letter
                           letter = letter + key;											   //Then adding key & letter together 
                          
                           if(letter > 'z'){												   //If letter is greater than 
                               letter = letter - 'z' + 'a' - 1;								   //
                           }
                          
                           message[iteration] = letter;										   //replacing new character in place of old character in message
                          
                           }
                          
                           }
                  
                  
                   printf("Ciphertext message: %s", message);								    //Printing the cipher text
                  
                              
         
} 

// End of Function Void RotEnrypt
//_________________________________________________________________________________________________________________________________________________

// Funtion for rotation cipher decryption (Task 2)

void RotDecrypt(char *message, int key) {														//RotDecrypt function with parameters message and key
    printf("Enter ciphertext to decrypt: \n");
                   printf("%s\n", message);														//printing message
                   printf("Enter key: \n");
                   scanf("%d", &key);                                                           //Taking user input for key
                   int iteration;																//Declaring Variables
                   char letter;
                  
                        for(iteration = 0; message[iteration] != '\0'; ++iteration){			//Iterating through each character in message
                       letter = message[iteration];												//Storing character from message to letter
                      
                      
                           if(letter >= 'A' && letter <= 'Z'){                                  //If letter is Capital
                           letter = letter - key;												//Removing the key from letter
                          
                           if(letter < 'A'){													//If letter is less than 'A' then
                               letter = letter + 'Z' - 'A' + 1;									//Example: letter=A-4 ==> letter= A-4 + Z - A +1 ==> letter=W
                           }
                          
                           message[iteration] = letter;											//Replacing new letter in place of old letter
                       }
                      
                      
                       else if(letter >= 'a' && letter <= 'z'){									//If letter is lower case
                           letter = letter - key;
                          
                           if(letter < 'a'){
                               letter = letter + 'z' - 'a' + 1;
                           }
                          
                           message[iteration] = letter;
                       }
                      
                      
                   }
                  
                   printf("Plaintext message: %s", message);									//Printing the plain text
                  
                   }
				   
// End Function Void RotDecrypt
//_________________________________________________________________________________________________________________________________________________                 
				 
// Function used for substitution encryption  (Task 3)
				 
void SubEncrypt(char *message, char *encryptKey) {
    int iteration = 0;
    printf("Enter Aphabet Encryption Key: \n");													//Display the message to input Alphabet Encryption key
    scanf("%s", encryptKey);																	//Read the encryption key
   
    
       for (iteration = 0; iteration < strlen(message); iteration++)							//Loop will continue from 0 to the end of message
        {
            char letter = message[iteration];													//Assign the character at message[iteration] to letter
            if (letter >= 'A' && letter <= 'Z')													//Check for uppercase character
                {
          
                letter = encryptKey[letter - 'A'];												//update the value of letter by assigning the chracter at encryptKey[letter-'A']
                }

                    message[iteration] = letter;												//store the letter to message[iteration]
        }
                        printf("CipherText message: %s\n", message);							//Display the cipher text
}

//_________________________________________________________________________________________________________________________________________________
// Function used for substitution decryption (Task 4)


void SubDecrypt(char *message, char *encryptKey) {
    int iteration;
    int iteration_Num_Two = 0;
    int letter;
    printf("Enter Encryption Key: \n");															//Display the message to enter encryption key
    scanf("%s", encryptKey);																	//Input the Encryption key
        for (iteration = 0; message[iteration] != '0'; iteration++)								//loop will continue till message reaches to end
            {
               letter = message[iteration];														//Assign the first character of message to letter
                    if (letter >= 'A' && letter <= 'Z')											//Check the letter is between 'A' to 'Z' i.e/ upper case character or not
                        {
                            letter = letter - 32;												//Move the letter to 32 characters back
                        }
                            if (letter >= 65 && letter <= 90) {									//After subtraction if the letter lies in the range 65 to 90(inclusive)
                              
                                for (iteration_Num_Two = 0; iteration_Num_Two < 27; iteration_Num_Two++)      //loop will continue from 0 to 26
                                {
                                   if (message[iteration] == encryptKey[iteration_Num_Two])		//Check if the message[iteration] and encryptKey[iteration_Num_Two] will equal then terminate the loop
                                        {
                                          break;
                                        }
                                }
                        message[iteration] = 'A' + iteration_Num_Two;							//Set the message[iteration] to the value of iteration_Num_Two+'A'(uppercase) i.e/ 65+iteration_Num_Two
						printf("%s\n", message);
                      
                    }
              //printf("%s\n", message);															//Display the message
         
            }
           ;
   printf("CipherText message: %s\n", message);													//Display the cipher text
   printf("%s\n", encryptKey);																	//Display the encryptKey
} 

// End Function Void SubDecrypt
//_________________________________________________________________________________________________________________________________________________

// Function used for rotation decryption without using a key (Task 5)

void RotDecrypt_Without_Key(char *message, int key) {
printf("Enter ciphertext to decrypt: \n");
                  
                   int iteration;
                   char letter;
                   int count = 1;
                  
                   for (count = 1; count <26; count++)                                         //Loop runs from 1 to 25
                  
                        for(iteration = 0; message[iteration] != '\0'; ++iteration){		   //Loop will continue till message reaches to end
                       letter = message[iteration];											   //Assign each character of message to letter
                            key = 1;
                      
                           if(letter >= 'A' && letter <= 'Z'){								   //Check whether the letter is between A to Z (UPPERCASE CHARACTER)
                           letter = letter - key;											   //Shift the letter one step back
                          
                           if(letter < 'A'){												   //after subtracting the key from letter if it goes beyond A (cyclic process)

                               letter = letter + 'Z' - 'A' + 1;                                //then it will assgn the letter to Z
                           }
                          
                           message[iteration] = letter;                                        //REASSIGN THE changed letter to message[iteration]
                       }
                      
                      
                       else if(letter >= 'a' && letter <= 'z'){								    //check whether the letter is between A to Z (UPPERCASE CHARACTER)
                           letter = letter - key;
                          
                           if(letter < 'a'){                                                    //after subtracting the key from letter if it goes beyond a
                               letter = letter + 'z' - 'a' + 1;                                 //then it will assgn the letter to z (cyclic process)
                           }
                          
                           message[iteration] = letter;                                         //REASSIGN THE changed letter to message[iteration]
                       }
                      
                       key = key++;
                   }
                  
                   printf("Plaintext message: %s\n", message);                                  //Display the plain text
                  
                   }
                  
} 

// End Function Void RotDecrypt_Without_Key
//_________________________________________________________________________________________________________________________________________________
