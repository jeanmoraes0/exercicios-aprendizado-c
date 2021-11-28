#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main(){

	double x1, x2, y1, y2;

	printf("Digite o primeiro ponto:\n");
	printf("x: ");
	scanf("%lf", &x1);
	printf("y: ");
	scanf("%lf", &y1);
	printf("Digite o segundo ponto:\n");
	printf("x: ");
	scanf("%lf", &x2);
	printf("y: ");
	scanf("%lf", &y2);

	printf("A distancia entre os pontos (%.0lf, %.0lf) e (%.0lf, %.0lf) é: %lf", x1, y1, x2, y2, distance(x1, y1, x2, y2));
	return 0;
}

double distance(double x1, double y1, double x2, double y2){

	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	
}
