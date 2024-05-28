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
 
struct TreeNode { 
    struct Student student; 
    struct TreeNode *left; 
    struct TreeNode *right; 
}; 
 
struct TreeNode* createTreeNode(struct Student student) { 
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    newNode->student = student; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
 
void addTreeNode(struct TreeNode **root, struct Student student) { 
    if (*root == NULL) { 
        *root = createTreeNode(student); 
    } else { 
        if (strcmp(student.group, (*root)->student.group) < 0) { 
            addTreeNode(&((*root)->left), student); 
        } else { 
            addTreeNode(&((*root)->right), student); 
        } 
    } 
} 
 
void printStudentInfo(struct Student *student) { 
    printf("Фамилия: %s\n", student->lastName); 
    printf("Имя: %s\n", student->firstName); 
    printf("Пол: %c\n", student->gender); 
    printf("Возраст: %d\n", student->age); 
    printf("Группа: %s\n", student->group); 
    printf("Оценка по математике: %d\n", student->mathGrade); 
    printf("Оценка по физике: %d\n", student->physicsGrade); 
    printf("Оценка по химии: %d\n", student->chemistryGrade); 
} 
 
int hasLowGrades(struct Student *student) { 
    return (student->mathGrade < 4 || student->physicsGrade < 4 || student->chemistryGrade < 4); 
} 
 
void printStudentsWithLowGrades(struct TreeNode *root) { 
    if (root == NULL) { 
        return; 
    } 
    printStudentsWithLowGrades(root->left); 
    if (hasLowGrades(&(root->student))) { 
        printStudentInfo(&(root->student)); 
        printf("\n"); 
    } 
    printStudentsWithLowGrades(root->right); 
} 
 
void freeTree(struct TreeNode *root) { 
    if (root != NULL) { 
        freeTree(root->left); 
        freeTree(root->right); 
        free(root); 
    } 
} 
 
int main() { 
    struct TreeNode *studentsTree = NULL; 
 
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
        student.physicsGrade = rand() % (5 - 2 + 1) + 2; 
        student.chemistryGrade = rand() % (5 - 2 + 1) + 2; 
 
        addTreeNode(&studentsTree, student); 
    } 
 
    printf("Студенты с хотя бы одной тройкой или двойкой:\n"); 
    printStudentsWithLowGrades(studentsTree); 
 
    freeTree(studentsTree); 
 
    return 0; 
}
