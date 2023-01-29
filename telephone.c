#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Telephone {
    char name[30];
    char phone[15];
};

void add_record(FILE *fp) {
    struct Telephone t;

    printf("Enter name: ");
    scanf("%s", t.name);
    printf("Enter phone number: ");
    scanf("%s", t.phone);

    fseek(fp, 0, SEEK_END);
    fwrite(&t, sizeof(struct Telephone), 1, fp);
    printf("Record added successfully!\n");
}

void delete_record(FILE *fp) {
    char name[30];
    struct Telephone t;
    int flag = 0;

    printf("Enter name to delete: ");
    scanf("%s", name);

    FILE *temp = fopen("temp.dat", "w+b");
    rewind(fp);
    while (fread(&t, sizeof(struct Telephone), 1, fp) == 1) {
        if (strcmp(t.name, name) != 0) {
            fwrite(&t, sizeof(struct Telephone), 1, temp);
        } else {
            flag = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("telephone.dat");
    rename("temp.dat", "telephone.dat");
    fp = fopen("telephone.dat", "r+b");

    if (flag) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void display_records(FILE *fp) {
    struct Telephone t;

    rewind(fp);
    while (fread(&t, sizeof(struct Telephone), 1, fp) == 1) {
        printf("Name: %s\n", t.name);
        printf("Phone: %s\n\n", t.phone);
    }
}

void search_record(FILE *fp) {
    char name[30];
    struct Telephone t;
    int flag = 0;

    printf("Enter name to search: ");
    scanf("%s", name);

    rewind(fp);
    while (fread(&t, sizeof(struct Telephone), 1, fp) == 1) {
        if (strcmp(t.name, name) == 0) {
            printf("Name: %s\n", t.name);
            printf("Phone: %s\n", t.phone);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Record not found!\n");
    }
}

int main() {
    int choice;
    FILE *fp = fopen("telephone.dat", "r+b");

    if (fp == NULL) {
        fp = fopen("telephone.dat", "w+b");
        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }
    }

    while (1) {
        printf("1. Add Record\n");
        printf("2. Delete\n3. Display\n4. Search\n");
        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            add_record(fp);
            break;
        case 2:
            delete_record(fp);
            break;
        case 3:
            display_records(fp);
            break;
        case 4:
            search_record(fp);
            break;        
        default:
            break;
        }
    }
    return 0;
}