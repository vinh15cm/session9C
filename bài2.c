#include <stdio.h>

#define MAX_SIZE 100  // Kich thuoc toi da cua mang

int main() {
    int arr[MAX_SIZE];
    int numElements, position, newValue;

    // Nhap so luong phan tu muon nhap
    printf("Nhap so luong phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    // Kiem tra tinh hop le cua so luong phan tu
    if (numElements < 1 || numElements > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nhap cac phan tu cua mang
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Nhap vi tri can sua va gia tri moi
    printf("Nhap vi tri can sua (0 - %d): ", numElements - 1);
    scanf("%d", &position);

    // Kiem tra tinh hop le cua vi tri can sua
    if (position < 0 || position >= numElements) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    // Nhap gia tri moi
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    // Ghi de gia tri cu bang gia tri moi
    arr[position] = newValue;

    // In mang sau khi sua
    printf("Mang sau khi sua la:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

