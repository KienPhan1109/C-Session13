#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Hàm nhập giá trị các phần tử vào mảng
void inputArray(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Phần tử thứ [%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm in giá trị các phần tử của mảng theo ma trận
void printArray(int a[MAX][MAX], int n, int m) {
    printf("Ma trận:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm in ra các phần tử ở góc theo ma trận
void printCorners(int a[MAX][MAX], int n, int m) {
    printf("Ma trận ban đầu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nCác phần tử ở góc:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0 || i == 0 && j == m - 1 || i == n - 1 && j == 0 || i == n - 1 && j == m - 1)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}

// Hàm in ra các phần tử nằm trên đường biên theo ma trận
void printBorder(int a[MAX][MAX], int n, int m) {
    printf("Ma trận ban đầu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nCác phần tử nằm trên đường biên:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", a[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Hàm in ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận
void printDiagonals(int a[MAX][MAX], int n, int m) {
    printf("Ma trận ban đầu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nCác phần tử nằm trên đường chéo chính và đường chéo phụ:\n");
    int dem = 0;
    int dem2 = m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == dem && j == dem) // chéo chính
            {
                printf("%d ", a[i][j]);
            }
            if (i == dem && j == dem) // bỏ qua phần tử ở giữa
            {
                continue;
            }
            if (j == dem2) // chéo phụ
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        dem ++;
        dem2 --;
        printf("\n");
    }
}


// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm in ra các phần tử là số nguyên tố theo ma trận
void printPrimes(int a[MAX][MAX], int n, int m) {
    printf("Ma trận ban đầu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nCác phần tử là số nguyên tố:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(a[i][j])) {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int a[MAX][MAX];
    int n, m;
    int choice;
    printf("Nhập số hàng: ");
    scanf("%d", &n);
    printf("Nhập số cột: ");
    scanf("%d", &m);
    while (true){
        printf("\nMENU\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(a, n, m);
                break;
            case 2:
                printArray(a, n, m);
                break;
            case 3:
                printCorners(a, n, m);
                break;
            case 4:
                printBorder(a, n, m);
                break;
            case 5:
                printDiagonals(a, n, m);
                break;
            case 6:
                printPrimes(a, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lựa chọn không hợp lệ.\n");
                break;
        }
    }
    system("pause");
    return 0;
}
