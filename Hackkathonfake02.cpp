#include <stdio.h>

int main() {
    int arr[10][10];
    int n, m; 
    int choice, x;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu tren duong cheo chinh\n");
        printf("5. In ra cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban la:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:// Nhap kich thuoc va gia tri cac phan tu cua mang
                printf("Nhap kich thuoc mang (n m): ");
                scanf("%d %d", &n, &m);
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("arr[%d][%d] = ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            case 2://In gia tri cac phan tu cua mang theo ma tran
                printf("Gia tri mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:// In ra cac phan tu tren duong bien va tinh tich
                {
                    int product = 1;
                    printf("Cac phan tu tren duong bien:\n");

                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i][0]);
                        product *= arr[i][0];
                        if (m > 1) {
                            printf("%d ", arr[i][m-1]);
                            product *= arr[i][m-1];
                        }
                    }

                    for (int j = 1; j < m - 1; j++) {
                        printf("%d ", arr[0][j]); 
                        product *= arr[0][j];
                        if (n > 1) {
                            printf("%d ", arr[n-1][j]); 
                            product *= arr[n-1][j];
                        }
                    }

                    printf("\nTich cac phan tu tren duong bien: %d\n", product);
                }
                break;
            case 4:// In ra cac phan tu tren duong cheo chinh
                printf("Cac phan tu tren duong cheo chinh:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            case 5:// In ra cac phan tu tren duong cheo phu
                printf("Cac phan tu tren duong cheo phu:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][m-i-1]);
                }
                printf("\n");
                break;
            case 6:// Sap xep duong cheo chinh theo thu tu tang dan
                {
                    int temp;
                    for (int i = 0; i < n && i < m; i++) {
                        for (int j = i + 1; j < n && j < m; j++) {
                            if (arr[i][i] > arr[j][j]) {
                                temp = arr[i][i];
                                arr[i][i] = arr[j][j];
                                arr[j][j] = temp;
                            }
                        }
                    }

                    printf("Duong cheo chinh sau khi sap xep:\n");
                    for (int i = 0; i < n && i < m; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                }
                break;
            case 7:// Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                {
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (arr[i][j] == x) {
                                printf("Phan tu %d duoc tim thay tai vi tri arr[%d][%d]\n", x, i, j);
                                found = 1;
                            }
                        }
                    }
                    if (!found) {
                        printf("Phan tu %d khong co trong mang.\n", x);
                    }
                }
                break;
            case 8:// Thoat
                printf("Thoat.\n");
                return 0;
            default:
                printf("Ban chon khong hop le, hay thu lai.\n");
        }
    }

    return 0;
}



