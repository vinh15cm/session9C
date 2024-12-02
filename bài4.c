#include <stdio.h>

#define MAX_SIZE 100  // Kích thý?c t?i ða c?a m?ng

void nhapMang(int arr[], int *currentLength) {
    printf("Nhap so luong phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", currentLength);

    if (*currentLength < 1 || *currentLength > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        *currentLength = 0;  // Ð?t l?i s? ph?n t? ð? tránh l?i
        return;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *currentLength; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong.\n");
        return;
    }

    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int *currentLength) {
    if (*currentLength >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu moi.\n");
        return;
    }

    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    printf("Nhap vi tri muon them (0 - %d): ", *currentLength);
    scanf("%d", &position);

    if (position < 0 || position > *currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *currentLength; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*currentLength)++;
}

void suaPhanTu(int arr[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang rong, khong co phan tu de sua.\n");
        return;
    }

    int position, newValue;
    printf("Nhap vi tri can sua (0 - %d): ", currentLength - 1);
    scanf("%d", &position);

    if (position < 0 || position >= currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[position] = newValue;
}

void xoaPhanTu(int arr[], int *currentLength) {
    if (*currentLength == 0) {
        printf("Mang rong, khong co phan tu de xoa.\n");
        return;
    }

    int position;
    printf("Nhap vi tri can xoa (0 - %d): ", *currentLength - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *currentLength) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = position; i < *currentLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*currentLength)--;
}

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &currentLength);
                break;
            case 2:
                hienThiMang(arr, currentLength);
                break;
            case 3:
                themPhanTu(arr, &currentLength);
                break;
            case 4:
                suaPhanTu(arr, currentLength);
                break;
            case 5:
                xoaPhanTu(arr, &currentLength);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}

