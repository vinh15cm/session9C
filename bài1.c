#include <stdio.h>

#define MAX_SIZE 100  // Kich thuoc toi da cua mang

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;  // So luong phan tu hien co trong mang
    int numElements, value, addIndex;

    // Nhap so phan tu muon nhap
    printf("Nhap so luong phan tu muon nhap (toi da %d): ", MAX_SIZE);
    scanf("%d", &numElements);

    // Kiem tra dieu kien so luong phan tu
    if (numElements > MAX_SIZE || numElements < 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nhap cac phan tu cua mang
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }

    currentLength = numElements;

    // Nhap gia tri va vi tri muon them vao mang
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    printf("Nhap vi tri muon them (0 - %d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);

    // Kiem tra tinh hop le cua vi tri
    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    // Them phan tu vao vi tri addIndex
    if (addIndex >= currentLength) {
        // Neu vi tri them lon hon hoac bang currentLength
        arr[addIndex] = value;
        currentLength = addIndex + 1;
    } else {
        // Doi cac phan tu sang phai de tao cho trong
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[addIndex] = value;
        currentLength++;
    }

    // In mang sau khi them phan tu
    printf("Mang sau khi them phan tu:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

