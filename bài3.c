#include <stdio.h>

#define MAX_SIZE 100  // Kích thý?c t?i ða c?a m?ng

int main() {
    int arr[MAX_SIZE];
    int numElements, position;
    int currentLength = 0;  // S? lý?ng ph?n t? hi?n có trong m?ng

    // Nh?p s? lý?ng ph?n t? mu?n thêm vào m?ng
    printf("Nhap so luong phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    // Ki?m tra tính h?p l? c?a s? lý?ng ph?n t?
    if (numElements < 1 || numElements > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nh?p các ph?n t? c?a m?ng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    currentLength = numElements;

    // Nh?p v? trí c?n xóa
    printf("Nhap vi tri can xoa (0 - %d): ", currentLength - 1);
    scanf("%d", &position);

    // Ki?m tra tính h?p l? c?a v? trí c?n xóa
    if (position < 0 || position >= currentLength) {
        printf("Vi tri xoa khong hop le!\n");
        return 1;
    }

    // Xóa ph?n t? t?i v? trí ð? nh?p
    for (int i = position; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];  // D?ch các ph?n t? sau v? trí xóa sang trái
    }

    currentLength--;  // Gi?m s? lý?ng ph?n t? sau khi xóa

    // In m?ng sau khi xóa ph?n t?
    printf("Mang sau khi xoa phan tu:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

