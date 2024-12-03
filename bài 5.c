#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm ki?m tra s? nguyên t?
bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm nh?p m?ng
void nhapMang(int arr[], int *n) {
    printf("Nhap so luong phan tu (toi da %d): ", MAX_SIZE);
    scanf("%d", n);

    if (*n < 1 || *n > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        *n = 0;
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Hàm hi?n th? m?ng
void hienThiMang(int arr[], int n) {
    if (n == 0) {
        printf("Mang rong.\n");
        return;
    }

    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm in các ph?n t? ch?n và tính t?ng
void inVaTinhTongChan(int arr[], int n) {
    int tong = 0;
    printf("Cac phan tu chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cac phan tu chan: %d\n", tong);
}

// Hàm t?m giá tr? l?n nh?t và nh? nh?t
void timGiaTriLonNhatVaNhoNhat(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

// Hàm in s? nguyên t? và tính t?ng
void inVaTinhTongNguyenTo(int arr[], int n) {
    int tong = 0;
    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", tong);
}

// Hàm th?ng kê s? l?n xu?t hi?n c?a m?t s?
void thongKeSoLanXuatHien(int arr[], int n) {
    int x, count = 0;
    printf("Nhap so can thong ke: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    printf("So %d xuat hien %d lan.\n", x, count);
}

// Hàm thêm ph?n t? vào v? trí ch? ð?nh
void themPhanTu(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }

    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    printf("Nhap vi tri muon them (0 - %d): ", *n);
    scanf("%d", &position);

    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*n)++;
}

// Hàm chính
int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                inVaTinhTongChan(arr, n);
                break;
            case 4:
                timGiaTriLonNhatVaNhoNhat(arr, n);
                break;
            case 5:
                inVaTinhTongNguyenTo(arr, n);
                break;
            case 6:
                thongKeSoLanXuatHien(arr, n);
                break;
            case 7:
                themPhanTu(arr, &n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 8);

    return 0;
}

