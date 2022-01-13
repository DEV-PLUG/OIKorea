#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int K, h; // K와 처음 구멍을 뚫는 위치 h 정의.

	int location[512][512] = { 0 }; // 구멍 뚫린 위치를 기록할 2차원 배열.
	int final_hole[256][256] = { 0 }; // 최종적으로 출력할 구멍 위치 2차원 배열.
	char fold[17] = { 0 }; // 접는 순서를 기록할 배열.

	scanf("%d", &K); // K 입력받음.

	// 제곱으로 종이 길이 구하기
	int paper_length = 1;
	for (int x = 0; x < K; x++) {
		paper_length = paper_length * 2;
	}

	int x[2] = { 0, (paper_length * 2 - 1) }, y[2] = { 0, (paper_length * 2 - 1) }; // 현재 접힌 부분이 차지하는 위치를 나타낼 x, y 좌표 정의.

	for (int i = 0; i < (K * 2); i++) {
		scanf("%s", &fold[i]); // 접는 방법 입력받음.
	}

	scanf("%d", &h); // h 입력받음.

	// 접힌 위치 기록
	for (int j = 0; j < (K * 2); j++) {
		if (fold[j] == 'U') {
			y[1] = y[1] - ((y[1] - y[0] + 1) / 2);
		}
		if (fold[j] == 'D') {
			y[0] = y[0] + ((y[1] - y[0] + 1) / 2);
		}
		if (fold[j] == 'L') {
			x[1] = x[1] - ((x[1] - x[0] + 1) / 2);
		}
		if (fold[j] == 'R') {
			x[0] = x[0] + ((x[1] - x[0] + 1) / 2);
		}
	}

	// 처음 구멍 뚫는 위치 기록
	if (h == 0) {
		location[y[0]][x[0]] = 1;
	}
	if (h == 1) {
		location[y[0]][x[1]] = 1;
	}
	if (h == 2) {
		location[y[1]][x[0]] = 1;
	}
	if (h == 3) {
		location[y[1]][x[1]] = 1;
	}

	// 종이 펼치기.
	for (int s = 0; s < (K * 2); s++) {
		if (fold[(K * 2) - 1 - s] == 'U') {

			// 코드 해설 2 - 1 참고.
			for (int o = x[0]; o < x[1] + 1; o++) {
				for (int a = y[0]; a < y[1] + 1; a++) {
					location[y[1] + (y[1] - y[0] + 1) - (a - y[0])][o] = location[a][o];
				}
			}

			y[1] = y[1] + (y[1] - y[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'D') {

			// 코드 해설 2 - 2 참고.
			for (int o = x[0]; o < x[1] + 1; o++) {
				for (int a = y[0]; a < y[1] + 1; a++) {
					location[y[0] - (a - y[0] + 1)][o] = location[a][o];
				}
			}

			y[0] = y[0] - (y[1] - y[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'L') {

			// 코드 해설 2 - 3 참고.
			for (int o = y[0]; o < y[1] + 1; o++) {
				for (int a = x[0]; a < x[1] + 1; a++) {
					location[o][(x[1] + (x[1] - x[0] + 1)) - (a - x[0])] = location[o][a];
				}
			}

			x[1] = x[1] + (x[1] - x[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'R') {

			// 코드 해설 2 - 4 참고.
			for (int o = y[0]; o < y[1] + 1; o++) {
				for (int a = x[0]; a < x[1] + 1; a++) {
					location[o][(x[0] - (a - x[0] + 1))] = location[o][a];
				}
			}

			x[0] = x[0] - (x[1] - x[0] + 1);
		}

	}

	// 구멍 위치 출력
	for (int q = 0; q < (paper_length * 2); q++) {
		for (int p = 0; p < (paper_length * 2); p++) {
			if (q == 0 || q % 2 == 0) {
				if (p == 0 || p % 2 == 0) {
					if(location[q][p] == 1) final_hole[q / 2][p / 2] = 0;
				}
				else {
					if(location[q][p] == 1) final_hole[q / 2][p / 2] = 1;
				}
			}
			else {
				if (p == 0 || p % 2 == 0) {
					if(location[q][p] == 1) final_hole[q / 2][p / 2] = 2;
				}
				else {
					if(location[q][p] == 1) final_hole[q / 2][p / 2] = 3;
				}
			}
		}
		if (q % 2 != 0) {
			for (int p = 0; p < (paper_length); p++) {
				printf("%d ", final_hole[q / 2][p]);
			}
			if(q != (paper_length * 2 - 1)) printf("\n");
		}
	}

	return 0;

}
