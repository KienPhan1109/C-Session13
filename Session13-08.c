// * Xây dựng hàm tìm ước chung lớn nhất có 2 tham số, kết quả trả về là ước chung lớn nhất của 2 đối số truyền vào. Viết chương trình khai báo và gán giá trị cho 2 số nguyên bất kỳ, sử dụng hàm đã xây dựng để tìm ước chung lớn nhất của chúng.
#include <stdio.h>

int UCLN(int a, int b) {
    if(a == 0 || b == 0){
        return a + b;
    }
    int min = a < b ? a : b;
    for(int i = min; i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}
int main(){
    int a, b;
    printf("Nhập số a: ");
    scanf("%d", &a);
    printf("Nhập số b: ");
    scanf("%d", &b);
    printf("Ước chung lớn nhất của %d và %d là: %d\n", a, b, UCLN(a, b));
}
