#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
#define MAX_SIZE 100
#define SU 3

struct student_info {
    char name[10];
    int id; int gender;
    int c; int java; int kotlin;
    int total; double avr; char grade;
};
int total_number = 0;
typedef struct student_info STU;
void input_info(STU* student);
char get_grade(double avr);
void output_info(STU* student);
void search_info(STU* student);
void sort_info(STU* student);
void insert_info(STU* student);
int range_check(char title[], int min, int max);
void delete_info(STU* student);
void update_info(STU* student);

int main()
{
    printf("�л� ���� �Է��ϼ��� : ");
    scanf("%d", &total_number);
    printf("\n");
    STU student[MAX_SIZE];
    while (1) {
        int menu = 0;
        printf("----------MENU--------- \n");
        printf("1. ���� �Է�(�ڵ�) \n");
        printf("2. ���� ��� \n");
        printf("3. ���� �˻� \n");
        printf("4. ���� ���� \n");
        printf("5. ���� ���� \n");
        printf("6. ���� ���� \n");
        printf("7. ���� ���� \n");
        printf("8. ������ \n");
        printf("----------------------- \n");
        printf("���Ͻô� ��ȣ�� �������� : ");
        scanf("%d", &menu);
        switch (menu) {
        case 1: input_info(student); getchar(); getchar(); system("cls"); break;
        case 2: output_info(student); getchar(); getchar(); system("cls"); break;
        case 3: search_info(student); getchar(); getchar(); system("cls"); break;
        case 4: sort_info(student); getchar(); getchar(); system("cls"); break;
        case 5: insert_info(student); getchar(); getchar(); system("cls"); break;
        case 6: delete_info(student); getchar(); getchar(); system("cls"); break;
        case 7: update_info(student); getchar(); getchar(); system("cls"); break;
        case 8: printf("\n���α׷��� ����Ǿ����ϴ�. "); return;
        default: printf("�ùٸ� ��ȣ�� �Է��ϼ���."); break;
        }
    }
    return 0;
}
//���� �Է� (�ڵ�)
void input_info(STU* student) {
    int i = 0;
    for (i = 0; i < total_number; i++) {
        student[i].name[0] = rand() % 26 + 'A';
        student[i].name[1] = rand() % 26 + 'A';
        student[i].name[2] = rand() % 26 + 'A';
        student[i].name[3] = NULL;
        student[i].id = rand() % (9999 - 1000 + 1) + 1000;
        student[i].gender = rand() % 2;

        student[i].c = rand() % 101;
        student[i].java = rand() % 101;
        student[i].kotlin = rand() % 101;

        student[i].total = student[i].c + student[i].java + student[i].kotlin;
        student[i].avr = student[i].total / (double)SU;
        student[i].grade = get_grade(student[i].avr);
    }
    printf("�Է� �Ϸ��Ͽ����ϴ�. \n");

    return;
}
//��� ���ϱ�
char get_grade(double avr) {
    char grade = 0;
    if (avr >= 90.0) {
        grade = 'A';
    }
    else if (avr >= 80.0 && avr < 90.0) {
        grade = 'B';
    }
    else if (avr >= 70.0 && avr < 80.0) {
        grade = 'C';
    }
    else if (avr >= 60.0 && avr < 70.0) {
        grade = 'D';
    }
    else {
        grade = 'F';
    }
    return grade;
}
//���� ���
void output_info(STU* student) {
    int i = 0;
    for (i = 0; i < total_number; i++) {
        printf("%2d) %5s %5d %5s %3d %3d %3d %d %7.2lf %5c \n",
            i + 1, student[i].name, student[i].id, (student[i].gender == 1) ? "��" : "��", student[i].c, student[i].java, student[i].kotlin, student[i].total, student[i].avr, student[i].grade);
    }

    return;
}
//���� �˻�
void search_info(STU* student) {
    char name[10] = "";
    printf("�˻��� �̸��� �Է��ϼ��� : ");
    scanf("%s", name);
    int i = 0; int find_flag = 0;
    for (i = 0; i < total_number; i++) {
        if (!strnicmp(&student[i].name[0], &name[0], 3)) {
            printf("%d) %5s %5d %5s : %3d %3d %3d -> %d %7.2lf %5c \n",
                i + 1, student[i].name, student[i].id, (student[i].gender == 1) ? "��" : "��",
                student[i].c, student[i].java, student[i].kotlin, student[i].total, student[i].avr, student[i].grade);
            find_flag = 1;
            return;
        }
    }
    printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ��� \n");
    return;
}
//���� ����
void sort_info(STU* student) {
    STU copy_student[MAX_SIZE];
    STU buffer_student;
    int i, j = 0;
    for (i = 0; i < total_number; i++) {
        memcpy(&copy_student[i], &student[i], sizeof student[i]);
    }
    int count = 0;
    printf("�������� : 1, �������� : 2  \n��ȣ : ");
    scanf("%d", &count);
    if (count == 1) {
        for (i = 0; i < total_number - 1; i++) {
            for (j = i + 1; j < total_number; j++) {
                if (copy_student[i].total > copy_student[j].total) {
                    memcpy(&buffer_student, &copy_student[i], sizeof copy_student[i]);
                    memcpy(&copy_student[i], &copy_student[j], sizeof copy_student[i]);
                    memcpy(&copy_student[j], &buffer_student, sizeof copy_student[i]);
                }
            }
        }
        output_info(copy_student);
        return;
    }
    else if (count == 2) {
        for (i = 0; i < total_number - 1; i++) {
            for (j = i + 1; j < total_number; j++) {
                if (copy_student[i].total < copy_student[j].total) {
                    memcpy(&buffer_student, &copy_student[i], sizeof copy_student[i]);
                    memcpy(&copy_student[i], &copy_student[j], sizeof copy_student[i]);
                    memcpy(&copy_student[j], &buffer_student, sizeof copy_student[i]);
                }
            }
        }
        output_info(copy_student);
        return;
    }
    else {
        printf("�߸� �Է��ϼ̽��ϴ�. \n");
    }
    return;
}
//��������
void insert_info(STU* student) {
    char name[10] = "";
    if (total_number > MAX_SIZE) {
        printf("�л� �� �ʰ��� �Է��� �� �����ϴ�. ");
        return;
    }

    int flag = 0;
    while (1) {
        printf("�Է��� �л� �̸� : ");
        scanf("%s", name);
        for (int i = 0; i < total_number; i++) {
            if (!strnicmp(name, student[i].name, 3)) {
                printf("�ߺ��� �̸��� �ֽ��ϴ�.\n");
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            flag = 0;
            continue;
        }
        else {
            break;
        }
    }
    total_number++;
    student[total_number - 1].id = range_check("��ȣ", 1000, 9999);
    student[total_number - 1].gender = range_check("����", 0, 1);
    student[total_number - 1].c = range_check("C ����", 0, 100);
    student[total_number - 1].java = range_check("java ����", 0, 100);
    student[total_number - 1].kotlin = range_check("kotlin ����", 0, 100);
    student[total_number - 1].total = student[total_number - 1].c + student[total_number - 1].java + student[total_number - 1].kotlin;
    student[total_number - 1].avr = student[total_number - 1].total / (double)SU;
    student[total_number - 1].grade = get_grade(student[total_number - 1].avr);

    printf("���� �Ϸ��Ͽ����ϴ�.");

    return;
}
//���Խ� ���� ����
int range_check(char title[], int min, int max) {
    int input_number = 0;
    int flag = 0;
    while (!flag) {
        printf("�Է��� �л� %s (%d~%d) : ", title, min, max);
        scanf("%d", &input_number);
        if (input_number >= min && input_number <= max) {
            return input_number;
        }
        else { printf("�ٽ� �Է��ϼ��� \n"); }
    }
    return input_number;
}
//���� ����
void delete_info(STU* student) {
    char name[10] = "";
    printf("������ �̸��� �Է��ϼ��� : ");
    scanf("%s", name);
    int i = 0; int find_flag = 0;
    for (i = 0; i < total_number; i++) {
        if (!strnicmp(&student[i].name[0], &name[0], 3)) {
            student[i].name[0] = "";
            student[i].name[1] = "";
            student[i].name[2] = "";

            student[i].id = 0;
            student[i].gender = 0;
            student[i].c = 0;
            student[i].java = 0;
            student[i].kotlin = 0;
            student[i].total = 0;
            student[i].avr = 0.0;
            student[i].grade = 0;

            find_flag = 1;
            printf("���� �Ϸ��Ͽ����ϴ�.");
            return;
        }
    }
    printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ��� \n");

    return;
}
//���� ����
void update_info(STU* student) {
    char name[10] = "";
    printf("������ �̸��� �Է��ϼ��� : ");
    scanf("%s", name);
    int i = 0; int find_flag = 0;
    for (i = 0; i < total_number; i++) {
        if (!strnicmp(&student[i].name[0], &name[0], 3)) {
            printf("������ C����(���� %d) : ", student[i].c);
            scanf("%d", &student[i].c);
            printf("������ java����(���� %d) : ", student[i].java);
            scanf("%d", &student[i].java);
            printf("������ C����(���� %d) : ", student[i].kotlin);
            scanf("%d", &student[i].kotlin);
            student[i].total = student[i].c + student[i].java + student[i].kotlin;
            student[i].avr = student[i].total / (double)SU;
            student[i].grade = get_grade(student[i].avr);
            printf("���� �Ϸ��Ͽ����ϴ� \n");
        }
    }
    output_info(student);
    return;
}