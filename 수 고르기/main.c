#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int arr[], int count) { // ��ǰ ������ ���.

    int temp;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (arr[j] > arr[j + 1])  {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;  

            }
        }
    }

}

int main(void) {

    int N, K; // N, K ����.
    int Score; // ���� ���� ����.
    int Arr[5001] = { 0 }; // N�� �ִ� ������ �迭 ����.

    scanf("%d%d", &N, &K); // N�� K�� �Է¹���.

    for (int i = 0; i < N; i++) { // ������ �Է¹���.
        scanf("%d", &Arr[i]);
    }

    sort(Arr, N); // ��ǰ ������ ���� �� ����.

    int temp = 0; // �ӽ� ���� ����(������ ��).
    for (int j = 0; j < K; j++) {
        temp = temp + Arr[N - 1 - j];
    }

    Score = temp - K * (K - 1) / 2; // ���� ���� ���.

    printf("%d", Score); // ���� ���.

    return 0;

};