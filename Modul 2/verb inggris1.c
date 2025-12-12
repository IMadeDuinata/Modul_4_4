#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void displayHeader() {
    system("cls");
    printf("=============================================================\n");
    printf("|              GROUP 4 PROGRAMMING ALGORITHM                |\n");
    printf("=============================================================\n");
    printf("| [1] Dhika Pradana                   2505551054            |\n");
    printf("| [2] I Made Duinata                  2505551143            |\n");
    printf("| [3] Reva Majesty Sentanu Karang     2505551171            |\n");
    printf("| [4] Ni Putu Niniek Anjaswari        2505551170            |\n");
    printf("| [5] Ni Ketut Deswita Krismayanti    2505551125            |\n");
    printf("| [6] Muhammad Izzanurdin Hasan       2505551075            |\n");
    printf("| [7] I Gusti Ayu Dwi Kencana Putri   2505551058            |\n");
    printf("=============================================================\n");
    printf("\nPress any key to continue to the main menu...\n");
    system("pause");
}

int getDaysInMonth(int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 29;
        default:
            return 0;
    }
}

const char* getMonthName(int month) {
    const char *names[] = {
        "Invalid", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (month >= 1 && month <= 12)
        return names[month];
    else
        return names[0];
}

void determineZodiac(int day, int month) {
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
        printf("Aries\n");
    else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
        printf("Taurus\n");
    else if ((month == 5 && day >= 21) || (month == 6 && day <= 20))
        printf("Gemini\n");
    else if ((month == 6 && day >= 21) || (month == 7 && day <= 22))
        printf("Cancer\n");
    else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
        printf("Leo\n");
    else if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
        printf("Virgo\n");
    else if ((month == 9 && day >= 23) || (month == 10 && day <= 22))
        printf("Libra\n");
    else if ((month == 10 && day >= 23) || (month == 11 && day <= 21))
        printf("Scorpio\n");
    else if ((month == 11 && day >= 22) || (month == 12 && day <= 21))
        printf("Sagittarius\n");
    else if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
        printf("Capricorn\n");
    else if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
        printf("Aquarius\n");
    else if ((month == 2 && day >= 19) || (month == 3 && day <= 20))
        printf("Pisces\n");
}

int getValidNumber(const char *message, int min, int max) {
    char buffer[100];
    int value;
    int i;

    while (1) {
        printf("%s", message);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf(" Input cannot be empty!\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf(" Input cannot be empty!\n");
            continue;
        }

        int valid = 1;
        for (i = 0; i < (int)strlen(buffer); i++) {
            if (!isdigit((unsigned char)buffer[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf(" Input must be numeric only!\n");
            continue;
        }

        value = atoi(buffer);
        if (value < min || value > max) {
            printf("Value must be between %d and %d!\n", min, max);
            continue;
        }

        return value;
    }
}

int main() {
    int day, month, choice, maxDays;

    displayHeader();

    while (1) {
        system("cls");
        printf("=====================================\n");
        printf("            ASTRO NAVIGATOR          \n");
        printf("=====================================\n");
        printf("1. Determine Zodiac\n");
        printf("2. Exit Program\n");
        printf("-------------------------------------\n");

        choice = getValidNumber("Enter your choice (1-2): ", 1, 2);

        if (choice == 1) {
            system("cls");
            printf("==============================\n");
            printf("        SELECT BIRTH MONTH     \n");
            printf("==============================\n");
            for (int i = 1; i <= 12; i++) {
                printf("%2d. %s\n", i, getMonthName(i));
            }

            month = getValidNumber("\nEnter month (1-12): ", 1, 12);
            maxDays = getDaysInMonth(month);

            char dayMessage[50];
            sprintf(dayMessage, "Enter birth day (1-%d): ", maxDays);
            day = getValidNumber(dayMessage, 1, maxDays);

            printf("\n==============================\n");
            printf("Birth Date: %d %s\n", day, getMonthName(month));
            printf("Your Zodiac Sign: ");
            determineZodiac(day, month);
            printf("==============================\n");

            printf("\nPress ENTER to return to the menu...");
            getchar();
        } 
        else if (choice == 2) {
            printf("\nThank you for using this program!\n");
            exit(0);
        }
    }

   return 0;
}
