// * Xây dựng hàm tạo ma trận 2 chiều có 2 tham số là số hàng và số cột, khi gọi hàm người dùng sẽ phải nhập vào từng giá trị trong ma trận. Hàm có kết quả trả về là một mảng 2 chiều với số hàng và số cột giống với giá trị truyền vào. Viết chương trình yêu cầu người dùng nhập vào số hàng và số cột và sử dụng hàm để tạo ma trận, in ma trận ra màn hình để kiểm tra kết quả.
#include <stdio.h>
#include <stdbool.h>

int Matrix(int row, int col){
    int a[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Phần tử [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int row, col;
    printf("Nhập vào số hàng: ");
    scanf("%d", &row);
    printf("Nhập vào số cột: ");
    scanf("%d", &col);
    printf("Nhập vào số phần tử trong mảng: \n");
    Matrix(row, col);
}