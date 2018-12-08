#pragma once

void multByConst(double* a, double coef, int size) {
	for (int i = 0; i < size; i++)
		a[i] = a[i] * coef;
}
void subVec(double* a, double* b, int size) {
	for (int i = 0; i < size; i++)
		a[i] = a[i] - b[i];
}
