#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int a[MAX];
int n = 0;
int pos, value;
int choice;

// Hàm để hiển thị MENU
void menu() {
    printf("\nMENU\n");
    printf("\n1. Nhập số phần tử cần nhập và giá trị các phần tử\n");
    printf("\n2. In ra giá trị các phần tử đang quản lý\n");
    printf("\n3. Thêm một phần từ vào vị trí chỉ định\n");
    printf("\n4. Sửa một phần từ ở vị trí chỉ định\n");
    printf("\n5. Xóa một phần từ ở vị trí chỉ định\n");
    printf("\n6. Sắp xếp các phần tử\n");
    printf("\n7. Tìm kiếm phần tử nhập vào\n");
    printf("\n8. Thoát\n");
}

// Hàm tạo menu sắp xếp
char menuSapXep() {
    printf("\na. Giảm dần\n");
    printf("\nb. Tăng dần\n");
    printf("\nLựa chọn của bạn: ");
    char subChoice;
    getchar();
    scanf("%c", &subChoice);
    if (subChoice == 'a')
    {
        sortArrayDesc();
    }
    else if (subChoice == 'b')
    {
        sortArray();
    }
    else
    {
        printf("Lựa chọn không hợp lệ.");
    }
}

// Hàm tạo Menu tìm kiếm
char menuTimKiem() {
    printf("\na. Tìm kiếm tuyến tính\n");
    printf("\nb. Tìm kiếm nhị phân\n");
    printf("\nLựa chọn của bạn: \n");
    char subChoice;
    getchar();
    scanf("%c", &subChoice);
    if (subChoice == 'a')
    {
        linearSearch();
    }
    if (subChoice == 'b')
    {
        binarySearch();
    }
    else
    {
        printf("Lựa chọn không hợp lệ.");
    }
}

// Hàm để thực hiện các chức năng
void choices() {
    while (true){
        menu();
        printf("\nLựa chọn của bạn: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                intputArray();
                break;

            case 2:
            
                printArray();
                break;

            case 3:
                addElement(pos, value);
                break;

            case 4:
                editElement(pos, value);
                break;

            case 5:
                deleteElement(pos);
                break;

            case 6:
                menuSapXep();
                break;
            
            case 7:
                menuTimKiem();
                break;

            case 8:
                exitProgram();
                break;
            default:
                printf("\nLựa chọn không hợp lệ.\n");
                break;
        }
    }
}

// Hàm hiển thị mảng ban đầu
void display1() {
    printf("Mảng ban đầu: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

// Hàm hiển thị mảng sau khi thay đổi
void display2() {
    printf("Mảng sau khi thay đổi: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

// Hàm nhập vào số phần tử và giá trị các phần tử
void intputArray()
{
    printf("Nhập vào số phần tử trong mảng: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Nhập phần tử thứ  %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Hàm in ra các phần tử trong mảng
void printArray()
{
    printf("Các phần tử trong mảng: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

// Hàm thêm phần tử vào vị trí chỉ định
void addElement(int pos, int value)
{
    display1();
    printf("\nNhập giá trị muốn thêm: ");
    scanf("%d", &value);
    printf("\nNhập vị trí muốn thêm: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("\nVị trí nhập vào không hợp lệ.\n");
        return 0;
    }
    for (int i = n ; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = value;
    n++;
    display2();
}

// Hàm sửa phần tử ở vị trí chỉ định
void editElement(int pos, int value)
{
    display1();
    printf("\nNhập giá trị muốn sửa: ");
    scanf("%d", &value);
    printf("\nNhập vị trí muốn sửa: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("\nVị trí nhập vào không hợp lệ.\n");
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        if (i == pos)
        {
            a[i] = value;
        }
    }
    display2();
}

// Hàm xóa phần tử ở vị trí chỉ định
void deleteElement(int pos)
{
    display1();
    printf("\nNhập vị trí muốn xóa: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("\nVị trí nhập vào không hợp lệ\n");
        return 1;
    }
    for (int i = pos ; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    display2();
}

// Hàm sắp xếp mảng theo thứ tự tăng dần
void sortArray()
{
    display1();
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n");
    display2();
}

// Hàm sắp xếp mảng theo thứ tự giảm dần
void sortArrayDesc()
{
    display1();
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n");
    display2();
}

// Hàm tìm kiếm tuyến tính
void linearSearch()
{
    display1();
    int pos = -1;
    int x, i;
    printf("\nNhập số cần tìm: \n");
    scanf("%d", &x);
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            pos = i;
            printf("\nSố %d tìm thấy ở vị trí %d\n", x, pos );
        }
    }
    if (i > n)
    {
        printf("\nSố %d không tìm thấy trong mảng\n", x);
    }
}

// Hàm tìm kiếm nhị phân
void binarySearch()
{
    int x;
    int left = 0, right = n - 1, kiemtra = 0;
    display1();
    printf("\nNhập vào số cần tìm: \n");
    scanf("%d", &x);

    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            printf("\nPhần tử %d được tìm thấy ở vị trí: %d.\n", x, mid);
            kiemtra = 1;
            break;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!kiemtra)
    {
        printf("\nSố %d không tìm thấy trong mảng\n", x);
    }
}

// Hàm để thoát chương trình
void exitProgram()
{
    printf("\nChương trình kết thúc.\n");
    return 0;
}

int main(){
    choices();
}    