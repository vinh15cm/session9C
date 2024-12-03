#include <stdio.h>

#define MAX_SIZE 100

// Hàm nh?p m?ng 2 chi?u
void nhapMang(int arr[MAX_SIZE][MAX_SIZE], int *n) {
    printf("Nhap kich co cua ma tran (nxn, n <= %d): ", MAX_SIZE);
    scanf("%d", n);

    if (*n < 1 || *n > MAX_SIZE) {
        printf("Kich co khong hop le!\n");
        *n = 0;
        return;
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Hàm hi?n th? m?ng 2 chi?u d?ng ma tr?n
void hienThiMang(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Hàm in các ph?n t? l? và tính t?ng
void inVaTinhTongLe(int arr[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    printf("Cac phan tu le: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                tong += arr[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong);
}

// Hàm in các ph?n t? trên du?ng biên và tính tích
void inVaTinhTichDuongBien(int arr[MAX_SIZE][MAX_SIZE], int n) {
    long long tich = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("%d ", arr[i][j]);
                tich *= arr[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %lld\n", tich);
}

// Hàm in các ph?n t? trên du?ng chéo chính
void inDuongCheoChinh(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

// Hàm in các ph?n t? trên du?ng chéo ph?
void inDuongCheoPhu(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][n - i - 1]);
    }
    printf("\n");
}

// Hàm tìm dòng có t?ng l?n nh?t
void timDongTongLonNhat(int arr[MAX_SIZE][MAX_SIZE], int n) {
    int maxSum = 0, maxRow = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        if (i == 0 || sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }

    printf("Dong co tong lon nhat la dong %d voi tong %d\n", maxRow, maxSum);
}

// Hàm chính
int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("6. In ra cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu lon nhat\n");
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
                inVaTinhTongLe(arr, n);
                break;
            case 4:
                inVaTinhTichDuongBien(arr, n);
                break;
            case 5:
                inDuongCheoChinh(arr, n);
                break;
            case 6:
                inDuongCheoPhu(arr, n);
                break;
            case 7:
                timDongTongLonNhat(arr, n);
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

