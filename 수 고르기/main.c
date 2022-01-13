#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int arr[], int count) { // 거품 정렬을 사용.

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

    int N, K; // N, K 정의.
    int Score; // 최종 점수 정의.
    int Arr[5001] = { 0 }; // N의 최댓값 길이의 배열 정의.

    scanf("%d%d", &N, &K); // N과 K를 입력받음.

    for (int i = 0; i < N; i++) { // 수들을 입력받음.
        scanf("%d", &Arr[i]);
    }

    sort(Arr, N); // 거품 정렬을 통해 수 정렬.

    int temp = 0; // 임시 변수 정의(빼지는 수).
    for (int j = 0; j < K; j++) {
        temp = temp + Arr[N - 1 - j];
    }

    Score = temp - K * (K - 1) / 2; // 최종 점수 계산.

    printf("%d", Score); // 점수 출력.

    return 0;

};