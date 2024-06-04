#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
 
struct Student { 
    char lastName[20]; 
    char firstName[20]; 
    char gender; 
    int age; 
    char group[20]; 
    int mathGrade; 
    int physicsGrade; 
    int chemistryGrade; 
}; 
 
struct Node { 
    struct Student student; 
    struct Node *next; 
}; 
 
void* createNode(void *student) { 
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    memcpy(&newNode->student, student, sizeof(struct Student)); 
    newNode->next = NULL; 
    return newNode; 
} 
 
void appendNode(void **head, void *student) { 
    struct Node *newNode = (struct Node*)createNode(student); 
    if (*head == NULL) { 
        *head = newNode; 
    } else { 
        struct Node *temp = *head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
void* printStudentInfo(void *student) { 
    struct Student *s = (struct Student*)student; 
    printf("Фамилия: %s\n", s->lastName); 
    printf("Имя: %s\n", s->firstName); 
    printf("Пол: %c\n", s->gender); 
    printf("Возраст: %d\n", s->age); 
    printf("Группа: %s\n", s->group); 
    printf("Оценка по математике: %d\n", s->mathGrade); 
    printf("Оценка по физике: %d\n", s->physicsGrade); 
    printf("Оценка по химии: %d\n", s->chemistryGrade); 
    return NULL; 
} 
 
int hasLowGrades(void *student) { 
    struct Student *s = (struct Student*)student; 
    return (s->mathGrade < 4 || s->physicsGrade < 4 || s->chemistryGrade < 4); 
} 
 
void* printStudentsWithLowGrades(void *head) { 
    struct Node *temp = (struct Node*)head; 
    while (temp != NULL) { 
        if (hasLowGrades(&temp->student)) { 
            printStudentInfo(&temp->student); 
            printf("\n"); 
        } 
        temp = temp->next; 
    } 
    return NULL; 
} 
 
void freeList(void *head) { 
    struct Node *temp; 
    while (head != NULL) { 
        temp = (struct Node*)head; 
        head = temp->next; 
        free(temp); 
    } 
} 
 
int main() { 
    struct Node *studentsList = NULL; 
 
    char lastNames[10][20] = { 
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов", 
        "Попов", "Соколов", "Лебедев", "Козлов", "Новиков" 
    }; 
    char firstNames[10][20] = { 
        "Алексей", "Иван", "Сергей", "Дмитрий", "Андрей", 
        "Павел", "Александр", "Евгений", "Николай", "Михаил" 
    }; 
    char groups[5][20] = { 
        "Группа A", "Группа B", "Группа C", "Группа D", "Группа E" 
    }; 
 
    srand(time(NULL)); 
 
    for (int i = 0; i < 20; i++) { 
        struct Student student; 
        strcpy(student.lastName, lastNames[rand() % 10]); 
        strcpy(student.firstName, firstNames[rand() % 10]); 
        student.gender = (rand() % 2) ? 'M' : 'F'; 
        student.age = rand() % 5 + 18; 
        strcpy(student.group, groups[rand() % 5]); 
        student.mathGrade = rand() % (5 - 2 + 1) + 2; 
        student.physicsGrade =  rand() % (5 - 2 + 1) + 2; 
        student.chemistryGrade =  rand() % (5 - 2 + 1) + 2; 
 
        appendNode((void**)&studentsList, &student); 
    } 
 
    printf("Студенты с хотя бы одной тройкой или двойкой:\n"); 
    printStudentsWithLowGrades(studentsList); 
 
    freeList(studentsList); 
 
    return 0; 
}
