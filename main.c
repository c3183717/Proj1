/*
 * Name:Jackson Paul
 * Subject: ENGG1003
 * Assessment: Project 1
 * Description:
 * 1. Encryption of a message with a rotation cipher given the message text and rotation amount
 * 2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
 * 3. Encryption of a message with a substitution cipher given message text and alphabet substitution
 * 4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
 * 5. Decryption of a message encrypted with a rotation cipher given cipher text only
 * 6. Decryption of a message encrypted with a substitution cipher given cipher text only
 * Please take note of commenting throughout the code for ongoing explanation.
 */


#include<stdio.h>
 
int main()
{
    int choice;
 
    do
    {
        printf("Welcome To Jackson's Encryption/Decryption Tool\n");
        printf("Please Choose From the Following Options\n");
        printf("1.Rotation Cypher Encryption\n");
        printf("2.Rotation Cypher Decryption\n");
        printf("3.Substitution Cypher Encryption\n");
        printf("4.Substitution Cypher Decryption\n");
        scanf ("%d", choice);
 
        switch (choice)
        {
        case1:
            printf("Rotation Cypher Encryption Chosen");
            break;
        case2:
            printf("Rotation Cypher Decryption Chosen");
            break;
        case3:
            printf("3.Substitution Cypher Encryption Chosen");
            break;
        case4:
            printf("4.Substitution Cypher Decryption Chosen");
            break;
        default:
            printf("wrong choice.Enter Again");
            break;
        }
 
    } while(choice != 4);
}