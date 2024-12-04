#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 20
#define DATE_LENGTH 10

// Define the Student struct
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char birthday[DATE_LENGTH];
} Student;

// Function to check if a student has been processed
int isProcessed(int *processed, int studentIndex) {
    return processed[studentIndex];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read student data
    Student students[MAX_STUDENTS];
    int processed[MAX_STUDENTS] = {0}; // Flags for processing
    int count = 0;

    while (count < MAX_STUDENTS && 
           fscanf(file, "%d %s %s", &students[count].id, students[count].name, students[count].birthday) == 3) {
        count++;
    }
    fclose(file);

    // Process students by their birthdays
    for (int i = 0; i < count; i++) {
        if (!processed[i]) {
            printf("%s: ", students[i].birthday);
            for (int j = 0; j < count; j++) {
                if (strcmp(students[i].birthday, students[j].birthday) == 0) {
                    printf("%s(%d)", students[j].name, students[j].id);
                    processed[j] = 1; // Mark as processed
                    if (j < count - 1) {
                        printf(", ");
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}
