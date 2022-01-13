#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int K, h; // K�� ó�� ������ �մ� ��ġ h ����.

	int location[512][512] = { 0 }; // ���� �ո� ��ġ�� ����� 2���� �迭.
	int final_hole[256][256] = { 0 }; // ���������� ����� ���� ��ġ 2���� �迭.
	char fold[17] = { 0 }; // ���� ������ ����� �迭.

	scanf("%d", &K); // K �Է¹���.

	// �������� ���� ���� ���ϱ�
	int paper_length = 1;
	for (int x = 0; x < K; x++) {
		paper_length = paper_length * 2;
	}

	int x[2] = { 0, (paper_length * 2 - 1) }, y[2] = { 0, (paper_length * 2 - 1) }; // ���� ���� �κ��� �����ϴ� ��ġ�� ��Ÿ�� x, y ��ǥ ����.

	for (int i = 0; i < (K * 2); i++) {
		scanf("%s", &fold[i]); // ���� ��� �Է¹���.
	}

	scanf("%d", &h); // h �Է¹���.

	// ���� ��ġ ���
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

	// ó�� ���� �մ� ��ġ ���
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

	// ���� ��ġ��.
	for (int s = 0; s < (K * 2); s++) {
		if (fold[(K * 2) - 1 - s] == 'U') {

			// �ڵ� �ؼ� 2 - 1 ����.
			for (int o = x[0]; o < x[1] + 1; o++) {
				for (int a = y[0]; a < y[1] + 1; a++) {
					location[y[1] + (y[1] - y[0] + 1) - (a - y[0])][o] = location[a][o];
				}
			}

			y[1] = y[1] + (y[1] - y[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'D') {

			// �ڵ� �ؼ� 2 - 2 ����.
			for (int o = x[0]; o < x[1] + 1; o++) {
				for (int a = y[0]; a < y[1] + 1; a++) {
					location[y[0] - (a - y[0] + 1)][o] = location[a][o];
				}
			}

			y[0] = y[0] - (y[1] - y[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'L') {

			// �ڵ� �ؼ� 2 - 3 ����.
			for (int o = y[0]; o < y[1] + 1; o++) {
				for (int a = x[0]; a < x[1] + 1; a++) {
					location[o][(x[1] + (x[1] - x[0] + 1)) - (a - x[0])] = location[o][a];
				}
			}

			x[1] = x[1] + (x[1] - x[0] + 1);
		}
		if (fold[(K * 2) - 1 - s] == 'R') {

			// �ڵ� �ؼ� 2 - 4 ����.
			for (int o = y[0]; o < y[1] + 1; o++) {
				for (int a = x[0]; a < x[1] + 1; a++) {
					location[o][(x[0] - (a - x[0] + 1))] = location[o][a];
				}
			}

			x[0] = x[0] - (x[1] - x[0] + 1);
		}

		// ���� ��ġ�� X, Y ���� ���(����� �ڵ�).
		//for (int q = 0; q < (paper_length * 2); q++) {
		//	for (int p = 0; p < (paper_length * 2); p++) {
		//		printf("%d ", location[q][p]);
		//	}
		//	printf("\n");
		//}
		//printf("X: %d %d, Y: %d %d, xchange: %d, ychange: %d\n\n", x[0], x[1], y[0], y[1], xChange, yChange);
		//printf("\n");

	}

	// ���� ���� ��ġ ���(����� �ڵ�).
	//for (int q = 0; q < (paper_length * 2); q++) {
	//	for (int p = 0; p < (paper_length * 2); p++) {
	//		printf("%d ", location[q][p]);
	//	}
	// 	printf("\n");
	//}


	// ���� ��ġ ���
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