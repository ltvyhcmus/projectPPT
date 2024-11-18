/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 50
#define MAX_NAME 20
#define MAX_ID 8

struct data {
    char employee_id[MAX_ID];
    char name[MAX_NAME];
    char family;
    int children;
    char education[2];
    float salary;
};

struct work {
    int yes_off;
    int no_off;
    int extra;
    char result[2];
    float re_salary;
};

bool edu(char education[]) {
    if (strcmp(education, "C1") == 0 || strcmp(education, "C2") == 0 || strcmp(education, "C3") == 0 ||
        strcmp(education, "DH") == 0 || strcmp(education, "CH") == 0) {
        return true;
    }
    return false;
}

bool fami(char status) {
    if (status == 'M' || status == 'S') {
        return true;
    }
    return false;
}

bool re(char result[]) {
    if (strcmp(result, "T") == 0 || strcmp(result, "TB") == 0 || strcmp(result, "K") == 0) {
        return true;
    }
    return false;
}

void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void tinh(struct data employees[], struct work att[], int* num) {
    for (int i = 0; i < *num; i++) {
        float ex = 0;
        if (employees[i].children > 2) {
            ex += 0.05 * employees[i].salary;
        }
        if (strcmp(employees[i].education, "CH") == 0) {
            ex += 0.10 * employees[i].salary;
        }
        ex += 0.04 * att[i].yes_off;
        ex -= 0.05 * att[i].no_off;
        float re_salary = employees[i].salary + ex;
        att[i].re_salary = re_salary;
    }
}

void add(struct data employees[], struct work att[], int* num);
void edit(struct data employees[], int* num);
void delete(struct data employees[], struct work att[], int* num);
void update(struct data employees[], struct work att[], int* num);
//void view_sa(struct data employee, struct work att);
void find(struct data employees[], struct work att[]);
void calcu(struct data employees[], struct work att[]);
void arr(struct data employees[], struct work att[], int* num);
void SelectionSort(struct data employees[], struct work att[], int* num);
void InterchangeSort(struct data employees[], struct work att[], int* num);
void InsertionSort(struct data employees[], struct work att[], int* num);
void BubbleSort(struct data employees[], struct work att[], int* num);

int main() {
    struct data employees[MAX_EMPLOYEES];
    struct work att[MAX_EMPLOYEES];
    int num = 0;
    int x;
    do {
        printf("\n\t\t ----- MENU ----- \t\n");
        printf("\t\t1.Them thong tin nhan vien\n");
        printf("\t\t2.Sua thong tin nhan vien\n");
        printf("\t\t3.Xoa thong tin nhan vien khoi he thong\n");
        printf("\t\t4.Cap nhat bang cham cong nhan vien\n");
        printf("\t\t5.Xem bang luong nhan vien\n");
        printf("\t\t6.Tim kiem nhan vien\n");
        printf("\t\t7.Sap xep bang luong nhan vien (tang dan)\n");
        printf("\t\tNhan 0 de thoat\n");
        printf("\t\tVui long chon chuc nang:"); scanf("%d", &x);
        switch (x) {
        case 1: add(employees, att, &num); break;
        case 2: edit(employees, &num); break;
        case 3: delete(employees, att, &num); break;
        case 4: update(employees, att, &num); break;
        case 5: calcu(employees, att); break;
        case 6: find(employees, att); break;
        case 7: arr(employees, att, &num); break;
        case 0: break;
        default:
            printf("Khong co chuc nang trong menu");
            break;
        }
    } while (x);
    return 0;
}

void add(struct data employees[], struct work att[], int* num) {
    if (*num < MAX_EMPLOYEES) {
        printf("\tTHONG TIN LY LICH\n");
        printf("1.Ma so ID: "); scanf("%s", employees[*num].employee_id);
        printf("2.Ho & Ten: "); scanf("%s", employees[*num].name);
        do {
            printf("3.Tinh trang hon nhan (M/S): "); scanf(" %c", &employees[*num].family);
            if (!fami(employees[*num].family)) {
                printf("Tinh trang hon nhan khong hop le. Vui long nhap lai.\n");
            }
        } while (!fami(employees[*num].family));
        do {
            printf("4.So luong con cai: "); scanf("%d", &employees[*num].children);
            if (employees[*num].children < 0 || employees[*num].children > 20) {
                printf("Qua luong so luong con cho phep. Vui long nhap lai.\n");
            }
        } while (employees[*num].children < 0 || employees[*num].children > 20);
        do {
            printf("5.Trinh do hoc van (C1/C2/C3/DH/CH): "); scanf("%s", employees[*num].education);
            if (!edu(employees[*num].education)) {
                printf("Trinh do hoc van khong hop le. Vui long nhap lai.\n");
            }
        } while (!edu(employees[*num].education));
        do {
            printf("6.Luong co ban: "); scanf("%f", &employees[*num].salary);
            if (employees[*num].salary > 1000000) {
                printf("Luong co ban phai be hon 1000000. Vui long nhap lai.\n");
            }
        } while (employees[*num].salary > 1000000);
        printf("\tTHONG TIN CHAM CONG\n");
        do {
            printf("1.So ngay nghi co phep trong thang (<=28): "); scanf("%d", &att[*num].yes_off);
            if (att[*num].yes_off > 28) {
                printf("Qua so luong cho phep. Vui long nhap lai.\n");
            }
        } while (att[*num].yes_off > 28);
        do {
            printf("2.So ngay nghi khong phep trong thang (<=28): "); scanf("%d", &att[*num].no_off);
            if (att[*num].no_off > 28) {
                printf("Qua so luong cho phep. Vui long nhap lai.\n");
            }
        } while (att[*num].no_off > 28);
        do {
            printf("3.So ngay lam them trong thang (<=28): "); scanf("%d", &att[*num].extra);
            if (att[*num].extra > 28) {
                printf("Qua so luong cho phep. Vui long nhap lai.\n");
            }
        } while (att[*num].extra > 28);
        do {
            printf("4.Ket qua cong viec (T/TB/K): "); scanf("%s", att[*num].result);
            if (!re(att[*num].result)) {
                printf("Khong hop le. Vui long nhap lai.\n");
            }
        } while (!re(att[*num].result));
        (*num)++;
        printf("Them thong tin nhan vien thanh cong.\n");
    }
    else {
        printf("So luong nhan vien da dat toi da.\n");
    }
}

void edit(struct data employees[], int* num) {
    char id[MAX_ID];
    printf("\nNhap ID nhan vien can chinh sua: "); scanf("%s", id);
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (strcmp(employees[i].employee_id, id) == 0) {
            int x;
            do {
                printf("\n\t ----- EDIT ----- \t\n");
                printf("\t1. Ho & Ten\n");
                printf("\t2. Tinh trang hon nhan\n");
                printf("\t3. So luong con cai\n");
                printf("\t4. Trinh do hoc van\n");
                printf("\t5. Luong co ban\n");
                printf("\tNhan 0 de thoat\n");
                printf("\tVui long chon thong tin muon chinh sua:"); scanf("%d", &x);
                switch (x) {
                case 1:
                    printf("Ho & Ten cu: %s\n", employees[i].name);
                    printf("Ho & Ten moi: "); scanf("%s", employees[i].name);
                    break;
                case 2:
                    printf("Tinh trang hon nhan cu: %c\n", employees[i].family);
                    printf("Tinh trang hon nhan moi (M/S): "); scanf(" %c", &employees[i].family);
                    break;
                case 3:
                    printf("So luong con cai cu: %d\n", employees[i].children);
                    printf("So luong con cai moi: "); scanf("%d", &employees[i].children);
                    break;
                case 4:
                    printf("Trinh do hoc van cu: %s\n", employees[i].education);
                    printf("Trinh do hoc van moi (C1/C2/C3/DH/CD): "); scanf("%s", employees[i].education);
                    break;
                case 5:
                    printf("Luong co ban cu: %.3f\n", employees[i].salary);
                    printf("Luong co ban moi: "); scanf("%f", &employees[i].salary);
                    break;
                case 0:
                    break;
                default:
                    printf("Khong co chuc nang de chinh sua");
                    break;
                }
            } while (x);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ID %s.\n", id);
}

void update(struct data employees[], struct work att[], int* num) {
    char id[MAX_ID];
    printf("\nNhap ID nhan vien can cap nhat bang cham cong: "); scanf("%s", id);
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (strcmp(employees[i].employee_id, id) == 0) {
            int x;
            do {
                printf("\n\tCAP NHAT THONG TIN CHAM CONG CHO NHAN VIEN %s (%s) \t\n", employees[i].name, employees[i].employee_id);
                printf("\t   1.So ngay nghi co phep trong thang\n");
                printf("\t   2.So ngay nghi khong phep trong thang\n");
                printf("\t   3.So ngay lam them trong thang\n");
                printf("\t   4.Ket qua cong viec\n");
                printf("\t   Nhan 0 de thoat\n");
                printf("\t   Vui long chon thong tin muon chinh sua:"); scanf("%d", &x);
                switch (x) {
                case 1:
                    printf("So ngay nghi co phep trong thang cu: %d\n", att[i].yes_off);
                    printf("So ngay nghi co phep trong thang moi: "); scanf("%d", &att[i].yes_off);
                    break;
                case 2:
                    printf("So ngay nghi khong phep trong thang cu: %d\n", att[i].no_off);
                    printf("So ngay nghi khong phep trong thang moi: "); scanf("%d", &att[i].no_off);
                    break;
                case 3:
                    printf("So ngay lam them trong thang cu: %d\n", att[i].extra);
                    printf("So ngay lam them trong thang moi: "); scanf("%d", &att[i].extra);
                    break;
                case 4:
                    printf("Ket qua cong viec cu: %s\n", att[i].result);
                    printf("Ket qua cong viec moi: "); scanf("%s", att[i].result);
                    break;
                case 0:
                    break;
                default:
                    printf("Khong co chuc nang de chinh sua\n");
                    break;
                }
            } while (x);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ID %s.\n", id);
}

void delete(struct data employees[], struct work att[], int* num) {
    char id[MAX_ID];
    printf("Nhap ID nhan vien can xoa: "); scanf("%s", id);
    for (int i = 0; i < *num; i++) {
        if (strcmp(employees[i].employee_id, id) == 0) {
            for (int j = i; j < *num; j++) {
                strcpy(employees[j].employee_id, employees[j + 1].employee_id);
                strcpy(employees[j].name, employees[j + 1].name);
                employees[j].family = employees[j + 1].family;
                employees[j].children = employees[j + 1].children;
                strcpy(employees[j].education, employees[j + 1].education);
                employees[j].salary = employees[j + 1].salary;
                att[j] = att[j + 1];
            }
            (*num)--;
            printf("Nhan vien co ID %s da duoc xoa thanh cong.\n", id);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ID %s.\n", id);
}

void calcu(struct data employees[], struct work att[]) {
    char id[MAX_ID];
    printf("Nhap ID nhan vien can xem bang luong: "); scanf("%s", id);
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (strcmp(employees[i].employee_id, id) == 0) {
            float ex = 0;
            if (employees[i].children > 2) {
                ex += 0.05 * employees[i].salary;
            }
            if (strcmp(employees[i].education, "CH") == 0) {
                ex += 0.10 * employees[i].salary;
            }
            ex += 0.04 * att[i].yes_off;
            ex -= 0.05 * att[i].no_off;
            float re_salary = employees[i].salary + ex;
            att[i].re_salary = re_salary;
            printf("Luong nhan cua nhan vien %s (%s) la : %.3f\n", employees[i].name, employees[i].employee_id, re_salary);
        }
    }
}

void find(struct data employees[], struct work att[]) {
    char id[MAX_ID];
    printf("Nhap ID nhan vien can tim: "); scanf("%s", id);
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (strcmp(employees[i].employee_id, id) == 0) {
            printf("Thong tin ly lich nhan vien:\n");
            printf("ID: %s\nName: %s\nFamily: %c\nChildren: %d\nEducation: %s\nSalary: %.2f\n", employees[i].employee_id, employees[i].name, employees[i].family, employees[i].children, employees[i].education, employees[i].salary);
            printf("Thong tin cham cong nhan vien:\n");
            printf("So ngay nghi co phep: %d\nSo ngay nghi khong phep: %d\nSo ngay lam them: %d\nKet qua lam viec: %s\n", att[i].yes_off, att[i].no_off, att[i].extra, att[i].result);
            return;
        }
    }
    printf("Khong tim thay nhan vien voi ID %s.\n", id);
}

void arr(struct data employees[], struct work att[], int* num) {
    int t;
    do {
        printf("\n\t  CHON CACH SAP XEP MONG MUON (TANG DAN):\n");
        printf("\t1.Phuong phap Selection Sort (Chon truc tiep)\n");
        printf("\t2.Phuong phap Interchange Sort (Chen truc tiep)\n");
        printf("\t3.Phuong phap Insertion Sort (Doi cho truc tiep)\n");
        printf("\t4.Phuong phap Bubble Sort (Noi bot)\n");
        printf("\tNhan 0 de thoat\n");
        printf("\tVui long chon cach sap xep:"); scanf("%d", &t);
        switch (t) {
        case 1: SelectionSort(employees, att, num); break;
        case 2: InterchangeSort(employees, att, num); break;
        case 3: InsertionSort(employees, att, num); break;
        case 4: BubbleSort(employees, att, num); break;
        case 0: break;
        default: printf("\tKhong co chuc nang trong menu\n"); break;
        }
    } while (t);
}

void SelectionSort(struct data employees[], struct work att[], int* num) {
    int i, j, min;
    tinh(employees, att, num);
    for (i = 0; i < *num - 1; i++) {
        min = i;
        for (j = i + 1; j < *num; j++) {
            if (att[j].re_salary < att[min].re_salary)
                min = j;
            if (att[min].re_salary != att[i].re_salary)
                swap(&att[min].re_salary, &att[i].re_salary);
        }
    }
    printf("\n\t ----- SAP XEP THEO SELECTION SORT ----- \t\n");
    for (i = 0; i < *num; i++) {
        printf("   %d: Luong nhan cua nhan vien %s (%s) la : %.2f\n", i + 1, employees[i].name, employees[i].employee_id, att[i].re_salary);
    }
}

void InterchangeSort(struct data employees[], struct work att[], int* num) {
    int i, j;
    tinh(employees, att, num);
    for (i = 0; i < *num - 1; i++) {
        for (j = i + 1; j < *num; j++) {
            if (att[j].re_salary < att[i].re_salary)
                swap(&att[i].re_salary, &att[j].re_salary);
        }
    }
    printf("\n\t ----- SAP XEP THEO INTERCHANGE SORT ----- \t\n");
    for (i = 0; i < *num; i++) {
        printf("   %d: Luong nhan cua nhan vien %s (%s) la : %.2f\n", i + 1, employees[i].name, employees[i].employee_id, att[i].re_salary);
    }
}

void InsertionSort(struct data employees[], struct work att[], int* num) {
    int i, x, pos;
    tinh(employees, att, num);
    for (i = 1; i < *num; i++) {
        x = att[i].re_salary;
        pos = i - 1;
        while (pos >= 0 && att[pos].re_salary > x) {
            att[pos + 1].re_salary = att[pos].re_salary;
            pos--;
        }
        att[pos + 1].re_salary = x;
    }
    printf("\n\t ----- SAP XEP THEO INSERTION SORT ----- \t\n");
    for (i = 0; i < *num; i++) {
        printf("   %d: Luong nhan cua nhan vien %s (%s) la : %.2f\n", i + 1, employees[i].name, employees[i].employee_id, att[i].re_salary);
    }
}

void BubbleSort(struct data employees[], struct work att[], int* num) {
    int i, j;
    tinh(employees, att, num);
    for (i = 0; i < *num - 1; i++) {
        for (j = *num - 1; j > i; j--) {
            if (att[j].re_salary < att[j - 1].re_salary)
                swap(&att[j].re_salary, &att[j - 1].re_salary);
        }
    }
    printf("\n\t ----- SAP XEP THEO BUBBLE SORT ----- \t\n");
    for (i = 0; i < *num; i++) {
        printf("   %d: Luong nhan cua nhan vien %s (%s) la : %.2f\n", i + 1, employees[i].name, employees[i].employee_id, att[i].re_salary);
    }
}
//this is check line
