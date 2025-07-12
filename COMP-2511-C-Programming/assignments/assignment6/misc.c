#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct record record;
struct record {
    char id[10];  // 'a' + 8 digits + null terminator
    int score;
};

// Improved command parsing
int GetCommand() {
    char input[20];
    printf("Enter command (-4 to quit, -3 to sort by score, -2 to sort by ID, -1 to append, 0 to display, n to modify): ");
    
    if (scanf("%s", input) != 1) {
        return -4;  // EOF encountered
    }
    
    // Check for valid integer input
    char *endptr;
    long cmd = strtol(input, &endptr, 10);
    if (*endptr != '\0') {
        return -5;  // Invalid command (not a number)
    }
    
    return (int)cmd;
}

// Improved ID validation
int IsValidStudentId(const char *id) {
    // Check length is exactly 9 (a + 8 digits)
    if (strlen(id) != 9) {
        return 0;
    }
    
    // First character must be 'a' (case sensitive per requirements)
    if (id[0] != 'a') {
        return 0;
    }
    
    // Next 8 characters must be digits
    for (int i = 1; i < 9; i++) {
        if (!isdigit(id[i])) {
            return 0;
        }
    }
    
    return 1;
}

// Improved score validation
int IsValidScore(const char *score_str) {
    char *endptr;
    long score = strtol(score_str, &endptr, 10);
    
    // Check if entire string was converted and score is in range
    return (*endptr == '\0' && score >= 0 && score <= 100);
}

// Get student ID with validation and abort option
int GetStudentId(char *id) {
    while (1) {
        printf("Enter student ID (a followed by 8 digits, -1 to abort): ");
        if (scanf("%s", id) != 1) {
            return 0;  // EOF encountered
        }
        
        if (strcmp(id, "-1") == 0) {
            return 0;  // User aborted
        }
        
        if (IsValidStudentId(id)) {
            return 1;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
    }
}

// Get score with validation and abort option
int GetScore(int *score) {
    char input[20];
    while (1) {
        printf("Enter student score (0-100, -1 to abort): ");
        if (scanf("%s", input) != 1) {
            return 0;  // EOF encountered
        }
        
        if (strcmp(input, "-1") == 0) {
            return 0;  // User aborted
        }
        
        if (IsValidScore(input)) {
            *score = atoi(input);
            return 1;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
    }
}

// Count actual records in array
int CountRecords(const record *records, int max_records) {
    for (int i = 0; i < max_records; i++) {
        if (records[i].id[0] == '\0') {
            return i;
        }
    }
    return max_records;
}

// Append a new record
void AppendRecord(record *records, int max_records) {
    int count = CountRecords(records, max_records);
    if (count >= max_records) {
        return;  // Array is full
    }
    
    char id[10];
    int score;
    
    if (GetStudentId(id) && GetScore(&score)) {
        strcpy(records[count].id, id);
        records[count].score = score;
    }
}

// Modify an existing record
void ModifyRecord(record *records, int max_records) {
    int count = CountRecords(records, max_records);
    if (count == 0) {
        return;  // No records to modify
    }
    
    int record_num;
    printf("Enter record number to modify (1-%d): ", count);
    if (scanf("%d", &record_num) != 1) {
        return;  // EOF encountered
    }
    
    if (record_num < 1 || record_num > count) {
        return;  // Invalid record number
    }
    
    // Display the record to be modified (to stderr)
    fprintf(stderr, "%d %s %d\n", record_num, records[record_num-1].id, records[record_num-1].score);
    
    char id[10];
    int score;
    
    if (GetStudentId(id) && GetScore(&score)) {
        strcpy(records[record_num-1].id, id);
        records[record_num-1].score = score;
    }
}

// Comparison functions for qsort
int CompareById(const void *a, const void *b) {
    const record *ra = (const record *)a;
    const record *rb = (const record *)b;
    return strcmp(ra->id, rb->id);
}

int CompareByScore(const void *a, const void *b) {
    const record *ra = (const record *)a;
    const record *rb = (const record *)b;
    return rb->score - ra->score;  // Descending order
}

// Display all records (to stderr)
void DisplayRecords(const record *records, int max_records) {
    int count = CountRecords(records, max_records);
    for (int i = 0; i < count; i++) {
        fprintf(stderr, "%d %s %d\n", i+1, records[i].id, records[i].score);
    }
}

int main() {
    record records[1000] = {0};  // Initialize all to zero
    const int max_records = sizeof(records)/sizeof(records[0]);
    
    while (1) {
        int command = GetCommand();
        
        switch (command) {
            case -4:  // Quit
                return 0;
                
            case -3:  // Sort by score
                qsort(records, CountRecords(records, max_records), sizeof(record), CompareByScore);
                break;
                
            case -2:  // Sort by ID
                qsort(records, CountRecords(records, max_records), sizeof(record), CompareById);
                break;
                
            case -1:  // Append
                AppendRecord(records, max_records);
                break;
                
            case 0:  // Display
                DisplayRecords(records, max_records);
                break;
                
            default:  // Positive number (modify)
                if (command > 0) {
                    ModifyRecord(records, max_records);
                }
                // Ignore invalid commands
                break;
        }
    }
    
    return 0;
}