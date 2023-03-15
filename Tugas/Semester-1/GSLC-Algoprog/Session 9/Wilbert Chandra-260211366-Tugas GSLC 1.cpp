#include <stdio.h>
#include <ctype.h>
#include <string.h>


// Function to Check if Name is in the desired form
int nama(char* name) {
    int checker = 0;
    if (isupper(name[0]) && strlen(name) >= 5)
    {
        checker = 1;
    } 

    return checker;
}

// Function to check if the last character in password is a consonant
int consonantCheck(char* pass) {
    int checker = 0;
    char c = pass[strlen(pass)-1];
    c = toupper(c);
    char consonant[] = {'B', 'C', 'D', 'F', 'G', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'S', 'T', 'V', 'X', 'Z', 'H', 'R', 'W', 'Y'};

    for (int i = 0; i < strlen(consonant); i++)
    {
        if ( c == consonant[i])
        {
            checker = 1;
        }
        
    }

    return checker;
    
}

// Function to check if Password is in the desired form
int passCheck(char* pass) {
    int checker = 0;
    int lenght = 0;
    
    for (int i = 0; i < strlen(pass); i++ ) {
        if (isalnum(pass[i])) {
            lenght++;
        }
    }
    
    if (strlen(pass) >= 8 && strlen(pass) == lenght)
    {
        checker = 1;
    } 

    return checker;
    
}

// Check if Password Confirmation is the same as Password
int confirmPass(char* conPass, char* Pass) {
    int checker = 0;

    if (strcmp(conPass, Pass) == 0)
    {
        checker = 1;
    }
    
    return checker;
}

// Main Function
int main(int argc, char const *argv[])
{
    char name[100];
    char pass[1000];
    char conPass[1000];
    int a = 0;

    printf("Register\n");
    printf("-----------\n");

    puts("\n");

    do
    {
        printf("nama [5-100 karakter depannya harus huruf besar]: ");
        scanf("%s", &name);
    } while (nama(name) != 1);

    do
    {
        do
        {
            printf("Password: ");
            scanf("%s", &pass);
            consonantCheck(pass);
        } while (passCheck(pass) != 1);
    } while (consonantCheck(pass) != 1);
    
    do
    {
        printf("Confirm Password: ");
        scanf("%s", conPass);
        confirmPass(conPass, pass);
    } while (confirmPass(conPass, pass) != 1);

    puts("\n");
    
    printf("register berhasil.... :)\n");
    
    return 0;
}
