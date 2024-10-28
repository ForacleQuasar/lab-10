#include <stdio.h>
#include <locale.h>
double fa(double x) {
	double y;
	if (x <= 3)y = pow(x, 2) - 3 * x + 9;
	else y = 1 / ((x*x*x)+3);
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
void name(int number) {
	switch (number) {
	case 1:printf("Это круг"); break;
	case 2:printf("Ошибка"); break;
	case 3:printf("Это треугольник"); break;
	case 4:printf("Это четырёхугольник"); break;
	default:printf("Ошибка");
	}
}
void main() {
	setlocale(LC_CTYPE, "RUS");
	//1
	double x;
	puts("Введите х");
	scanf("%lf", &x);
	printf("fa(x)=%lf , fb(x)=%lf ", fa(x), fb(x));
	printf("произведение - %lf\n", fa(x) * fb(x));
	printf("разности квадратов - %d\n", pow(fa(x), 2) - pow(fb(x), 2));
	printf("удвоенная сумма - %lf\n", 2 * (fa(x) + fb(x)));
	//3
	int n;
	printf("Выберите операцию\n1) рассчитать площадь");
	printf("\n2) нарисовать фигуру\n3) вывести определение фигуры\n");
	scanf("%i", &n);
	switch (n) {
	case 1:
		printf("Введите сторону квадрата:");
		float side;
		scanf("%f", &side);
		printf("Площадь:%f", area_rectangle(side));
		break;
	case 2:
		puts("Введите сторону");
		int a;
		scanf("%i", &a);
		draw_rectangle(a);
		break;
	case 3:
		printf("Введите кол-во сторон фигуры");
		int number;
		scanf("%i", &number);
		name(number);
		break;
	default:printf("Ошибка");
	}
}