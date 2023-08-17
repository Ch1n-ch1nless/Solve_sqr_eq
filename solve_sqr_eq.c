#include <stdio.h>
#include <math.h>

const int eps = 1e-9;

int solve(double a, double b, double c, double *x1, double *x2);

int main() {
    printf("Привет! Эта программа умеет решать квадратное уравнение типа: A*x^2+B*x+C=0\n");
    double a, b, c, x1, x2; //коэффиценты квадратного уравнения и его корни
    printf("Чтобы узнать корни этого уравнения с точностью до 6 знаков после запятой нужно ввести соотвествующие коэффиценты\n");
    printf("Введите старший коэффицент уравнения, то есть, чему равен A = ");
    a = 1.0; //scanf("%lf", &a);
    printf("\nВведите второй коэффицент уравнения, то есть B = ");
    b = -2.0; //scanf("%lf", &b);
    printf("\nВведите третий коэффицент уравнения, то есть C = ");
    c = 1.0; //scanf("%lf", &c);
    int count_of_roots = solve(a, b, c, &x1, &x2);
    switch(count_of_roots) {
        case 0:
            printf("\nДанное уравнение не имеет решений");
            break;
        case 1:
            printf("\nДанное уравнение имеет единственное решение %.6lf", x1);
            break;
        case 2:
            printf("\nДанное уравнение имеет 2 решения: %.6lf и %.6lf", x1, x2);
            break;
        case 10:
            printf("\nДанное \"квадратное уравнение\" имеет бесконечное количество корней:)");
            break;
    }
    return 0;
}

int solve(double a, double b, double c, double *x1, double *x2) {
    if (fabs(a - 0.0) < eps) { //проверка является ли старший коэффицент многочлена равным 0
    	if (fabs(b - 0.0) < eps) { //проверка на то является b = 0
    	    if (fabs(c - 0.0) < eps) { //проверка является ли это случай 0*x^2+0*x+0=0
    	    	return 10; 
    	    } else {
    	    	return 0;
    	    }
    	} else {
    	    *x1 = -1 * c / b;
    	    return 1;
    	}
    } else {
        double D = b*b - 4*a*c;
        if (fabs(D - 0.0) < eps) { //проверяем равен ли дискриминант 0
            *x1 = -b / (2*a);
            return 1;
        } else if (D - 0.0 > eps) { //проверка на то положительный он или нет
            *x1 = (-b - sqrt(D)) / (2*a);
            *x2 = (-b + sqrt(D)) / (2*a);
            return 2;
        } else {
            return 0;
        }
    }
}
