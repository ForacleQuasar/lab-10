#include <stdio.h>
#include <locale.h>
#include <math.h>
double fa(double x) {
	double y;
	if (x <= 3)y = pow(x, 2) - 3 * x + 9;
	else y = 1 / ((x * x * x) + 3);
	return y;
}
double fb(double x) {
	double y1;
	y1 = x * exp(sin(pow(x, 2)));
	return y1;
}
float area_rectangle(float side) {
	return side * side;
}
void draw_rectangle(int a) {
	int count = 0;
	int count1 = 1;
	while (count < a) {
		printf("\n*");
		count += 1;
		count1 = 1;
		while (count1 < a) {
			printf("*");
			count1 += 1;
		}
	}
}
double sin_n(double x1, int N) {
	double result = 0, factor = 1;
	for (int k = 1; k<=N; k++) {
		factor *= (k == 1 ? 1 : (k * 2 - 2)) * (2 * k - 1);
		result += pow(-1, k - 1) * pow(x1, 2 * k - 1) / factor;
	}
	return result;
}
void name(int number) {
	switch (number) {
	case 1:printf("��� ����"); break;
	case 2:printf("������"); break;
	case 3:printf("��� �����������"); break;
	case 4:printf("��� ��������������"); break;
	default:printf("������");
	}
}
double sin_eps(double x1, double eps) {
	double result = 0, factor = 1;
	for (int k = 1; k <= 100; k++) {
		factor *= (k == 1 ? 1 : (k * 2 - 2)) * (2 * k - 1);
		result += pow(-1, k - 1) * pow(x1, 2 * k - 1) / factor;
	}
	return round(result * pow(10, eps)) / pow(10, eps);
}
void main() {
	setlocale(LC_CTYPE, "RUS");
	//1
	double x;
	puts("������� �");
	scanf("%lf", &x);
	printf("fa(x)=%lf , fb(x)=%lf ", fa(x), fb(x));
	printf("������������ - %lf\n", fa(x) * fb(x));
	printf("�������� ��������� - %lf\n", pow(fa(x), 2) - pow(fb(x), 2));
	printf("��������� ����� - %lf\n", 2 * (fa(x) + fb(x)));
	//2
	double x1;
	int N;
	printf("������� x1:");
	scanf("%lf", &x1);
	printf("������� N:");
	scanf("%i", &N);
	printf("\n������� sin(x):%lf\n������� sin_n(x, N):%lf\n������� sin_eps:%lf", sin(x1), sin_n(x1, N), sin_eps(x1, 4));
	//3
	int n;
	printf("\n�������� ��������\n1) ���������� �������");
	printf("\n2) ���������� ������\n3) ������� ����������� ������\n");
	scanf("%i", &n);
	switch (n) {
	case 1:
		printf("������� ������� ��������:");
		float side;
		scanf("%f", &side);
		printf("�������:%f", area_rectangle(side));
		break;
	case 2:
		puts("������� �������");
		int a;
		scanf("%i", &a);
		draw_rectangle(a);
		break;
	case 3:
		printf("������� ���-�� ������ ������: ");
		int number;
		scanf("%i", &number);
		name(number);
		break;
	default:printf("������");
	}
}