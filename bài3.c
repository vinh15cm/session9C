#include <stdio.h>

#define MAX_SIZE 100  // K�ch th�?c t?i �a c?a m?ng

int main() {
    int arr[MAX_SIZE];
    int numElements, position;
    int currentLength = 0;  // S? l�?ng ph?n t? hi?n c� trong m?ng

    // Nh?p s? l�?ng ph?n t? mu?n th�m v�o m?ng
    printf("Nhap so luong phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    // Ki?m tra t�nh h?p l? c?a s? l�?ng ph?n t?
    if (numElements < 1 || numElements > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nh?p c�c ph?n t? c?a m?ng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    currentLength = numElements;

    // Nh?p v? tr� c?n x�a
    printf("Nhap vi tri can xoa (0 - %d): ", currentLength - 1);
    scanf("%d", &position);

    // Ki?m tra t�nh h?p l? c?a v? tr� c?n x�a
    if (position < 0 || position >= currentLength) {
        printf("Vi tri xoa khong hop le!\n");
        return 1;
    }

    // X�a ph?n t? t?i v? tr� �? nh?p
    for (int i = position; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];  // D?ch c�c ph?n t? sau v? tr� x�a sang tr�i
    }

    currentLength--;  // Gi?m s? l�?ng ph?n t? sau khi x�a

    // In m?ng sau khi x�a ph?n t?
    printf("Mang sau khi xoa phan tu:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

