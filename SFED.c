#include <stdio.h>

void simpleFileEncryption()
{
    char userFileLocation[100];
    printf("\n----------------------------------\n");
    printf("Simple file Encrytion Mode (SFE)");
    printf("\n----------------------------------\n");
    printf("Please enter your .txt file location to encrypt it: ");
    scanf("%s", userFileLocation);

    FILE *userFile = fopen(userFileLocation, "r");

    if (userFile == NULL)
    {
        printf("\nthere is no file in the location you specified.\n");
        return;
    }
    else
    {
        printf("Please enter where you want to store your encrypted file: ");
        char userEncryptedFileLocation[100];
        scanf("%s", userEncryptedFileLocation);
        FILE *userEncryptedFile = fopen(userEncryptedFileLocation, "w");

        int currentFileCharecter;
        while ((currentFileCharecter = fgetc(userFile)) != EOF)
        {
            fputc(currentFileCharecter + 1, userEncryptedFile);
        }
        printf("File encrypted! check the file : %s\n", userEncryptedFileLocation);
    }
}
void simpleFileDecryption()
{
    char userFileLocation[100];
    printf("\n----------------------------------\n");
    printf("Simple file Decryption Mode (SFD)");
    printf("\n----------------------------------\n");
    printf("Please enter your .txt file location to Decrypt it: ");
    scanf("%s", userFileLocation);
    FILE *userFile = fopen(userFileLocation, "r");

    if (userFile == NULL)
    {
        printf("\nthere is no file in the location you specified.\n");
        return;
    }
    else
    {
        printf("Please enter where you want to store your encrypted file: ");
        char userDecryptedFileLocation[100];
        scanf("%s", userDecryptedFileLocation);
        FILE *userDecryptedFile = fopen(userDecryptedFileLocation, "w");

        int currentFileCharecter;
        while ((currentFileCharecter = fgetc(userFile)) != EOF)
        {
            fputc(currentFileCharecter - 1, userDecryptedFile);
        }
        printf("File decrypted! check the file : %s\n", userDecryptedFileLocation);
    }
}

int main()
{
    int option;
    printf("\n-------------------------------------------------------------------\n");
    printf("Welcome to Simple file Encrytion and Decryption cli utility (SFED)");
    printf("\n-------------------------------------------------------------------\n");
    while (option != 3)
    {
        printf("\nPlease select the given option : \n");
        printf("1) Encrypt a file using SFE\n");
        printf("2) Decrypt a file using SFD\n");
        printf("3) Exit program\n");
        printf("\nEnter [1/2/3]: ");
        scanf("%d", &option);
        if (option == 1)
        {
            simpleFileEncryption();
        }
        else if (option == 2)
        {
            simpleFileDecryption();
        }
        else if (option == 3)
        {
            printf("\nExiting the Program...\n");
        }
        else
            printf("\nPlease enter a valid option (only 1/2/3)\n");
        return 0;
    }
}