#include <stdio.h>
#define MAX 100

 int main() {
    int arr[MAX]; 
    int n = 0;   
    int choice;  

    while (1) { // Vong lap vo han
        printf("\nMENU\n");
        printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan li\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu(nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Moi ban lua chon: ");
        scanf("%d", &choice);

        if (choice == 1) { // Nhap mang
            printf("Moi ban nhap so phan tu: ");
            scanf("%d", &n);
            if (n > MAX) {
                printf("So luong vuot qua gioi han!\n");
                n = MAX;
            }
            for (int i = 0; i < n; i++) {
            	printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
        } 
        else if (choice == 2) { //In mang
         	printf("Cac phan tu trong mang: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (choice == 3) { // Gia tri lon nhat
        	 if (n == 0) {
                printf("Mang trong.\n");
            } else {
                int max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        max = arr[i];
                    }
                }
                printf("Gia tri lon nhat trong mang: %d\n", max);
            }
        } 
        else if (choice == 4) { // Cac so nguyen to
            printf("Cac so nguyen to trong mang: ");
            for (int i = 0; i < n; i++) {
                int isPrime = 1;
                if (arr[i] < 2) isPrime = 0;
                for (int j = 2; j * j <= arr[i]; j++) {
                    if (arr[i] % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
                if (isPrime) printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (choice == 5) { // Them phan tu
            if (n < MAX) {
                int newElement;
                printf("Moi ban nhap phan tu muon them: ");
                scanf("%d", &newElement);
                arr[n++] = newElement;
                printf("Da them .\n");
            } else {
                printf("Mang da day.\n");
            }
        } 
    else if (choice == 6) { // Xoa phan tu
            int index;
            printf("Nhap vi tri ban muon xoa (0 - %d): ", n - 1);
            scanf("%d", &index);
            if (index < 0 || index >= n) {
                printf("Vi tri khong hop le.\n");
            } else {
                for (int i = index; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Da xoa phan tu o vi tri %d.\n", index);
            }
       }
    else if (choice == 7) { // Sap xep tang dan
    for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Mang da duoc sap xep tang dan.\n");
		}   
		else if (choice == 8) { // Tim kiem phan tu
			int key, found = 0;
			printf("Moi ban nhap gia tri can tim: ");
            scanf("%d", &key);
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    printf("Tim thay gia tri tai vi tri: %d\n", i);
                    found = 1;
                }
            }
            if (!found) {
                printf("Khong tim thay gia tri trong mang.\n");
            }
		}
		 else if (choice == 9) { // Thoat
            printf("Thoat.\n");
            break;
        } 
        else {
            printf("Ban chon khong hop le, hay thu lai.\n");
        }
}
    return 0;
}
