#pragma once

#include <math.h>
#include <iostream> 
#include <stdio.h>
#include <string>
#include "Calculate.h"

class Polynom{
public: 
	double a, b, c, d, x;
	double lb, rb;

	std::string polynom;

	Polynom() {
		a = b = c = d = x = NULL;
		polynom = "";
	}

	double CreatePolynom(double Xi) {
			
		double tmp = a + b * (Xi - x) + c * pow((Xi - x), 2.0) + d * pow((Xi - x),3.0);
		return tmp;
	}
};

class CubSpline {
public:
	int n; // ���-�� �����
	Polynom *spline; //������ ��������� ��� ���������� ������

	double *X, *Y; //������� ��������� �����
	

	CubSpline() {
		n = 0;
		spline = NULL;
		X = NULL;
		Y = NULL;
	}

	CubSpline(int _n) {
		n = _n;
		spline = new Polynom[n - 1];
		X = new double[n + 2]; //+1
		Y = new double[n + 2]; //+1
	}

	~CubSpline() {
		delete[] spline;
		spline = NULL;
	}

	void CreateSpline(double *_x, double *_y) {

		double *A = new double[n + 2];  
		double *B = new double[n + 2];
		double *C = new double[n + 2];
		double *D = new double[n + 2];

		double *F = new double[n + 1];  //������ ����� ��������� ��� ���������� �i  
		double *H = new double[n + 1];  
		double **matr = new double*[n + 2];
		for (int i = 0; i < n + 2; i++)
			matr[i] = new double[n + 2];
		double *Cvec = new double[n + 2];


		for (int i = 1; i <= n; i++) {
			X[i] = _x[i];
			Y[i] = _y[i];
		}

		for (int i = 0; i < n + 2; i++)
			for (int j = 0; j < n + 2; j++)
				matr[i][j] = 0;

		for (int i = 2; i <= n; i++) {
			A[i] = Y[i - 1];
			H[i] = X[i] - X[i - 1];
		}

	// ������� ������ ����� ������� ��������� ��� ���������� �i
		for (int i = 2; i <= n - 1; i++)
			F[i] = 3 * ((Y[i + 1] - Y[i]) / H[i + 1] - (Y[i] - Y[i - 1]) / H[i]);

	// �������� ������� ��� �������� ������� ��������� ��� ���������� �i
		for (int i = 0; i < n + 2; i++) {	
			B[i] = 0;
			C[i] = 0;
			D[i] = 0;
			Cvec[i] = 1;
		}
		
		// �������� ������ � ��������� ������������
		Cvec[2] = 0;
		Cvec[n + 1] = 0;
	
		for (int i = 2; i <= n - 1; i++) {              // matr[������][�������]
			matr[i][i] = H[i] * Cvec[i];
			matr[i][i + 1] = 2 * (H[i] + H[i + 1]) * Cvec[i + 1];
			matr[i][i + 2] = H[i + 1] * Cvec[i + 2];
		}

	// ������ ���������� ������� ������� ������

		for (int i = 2; i < n - 1; i++) {
			// �������� ����������� ��� ������ � ��������
			double coef = matr[i + 1][i + 1] / matr[i][i + 1];
			multByConst(matr[i], coef, n + 2);
			F[i] = F[i] * coef;
			// ������ ������ ����������� �� �����������
			subVec(matr[i + 1], matr[i], n + 2);
			F[i + 1] = F[i + 1] - F[i];
		}
	//�������� ���
		for (int i = n - 1; i > 2; i--) {
			double coef = matr[i - 1][i + 1] / matr[i][i + 1];
			multByConst(matr[i], coef, n + 2);
			F[i] = F[i] * coef;
			subVec(matr[i - 1], matr[i], n + 2);
			F[i - 1] = F[i - 1] - F[i];
		}

		for (int i = 2; i <= n - 1; i++) {
			F[i] = F[i] / matr[i][i + 1];
		}

		for (int i = 3; i <= n; i++)
			C[i] = F[i - 1];

		for (int i = 2; i <= n; i++) {
		/*	B[i] = ((Y[i] - Y[i - 1]) / H[i]) - (H[i] * (C[i + 1] + 2 * C[i]) / 3);	*/		/////////////////////////////////////!!!!!!!!!!!!!!!!
			B[i] = ((Y[i] - Y[i - 1]) / H[i]) - (C[i] * H[i] + (C[i + 1] - C[i]) * H[i] / 3);
			D[i] = (C[i + 1] - C[i]) / (3 * H[i]);
			
		}

		for (int i = 2; i <= n; i++)
		{
			spline[i - 2].x = X[i - 1];
			spline[i - 2].a = A[i];
			spline[i - 2].b = B[i];
			spline[i - 2].c = C[i];
			spline[i - 2].d = D[i];
			
			spline[i - 2].polynom += "(" + std::to_string(A[i]) + ") + " + "(" + std::to_string(B[i]) + ") * (x - (" + std::to_string(X[i - 1]) + ")) + "
				+ "(" + std::to_string(C[i]) + ") * (x - (" + std::to_string(X[i - 1]) + "))^2 + " 
				+ "(" + std::to_string(D[i]) + ") * (x - (" + std::to_string(X[i - 1]) + "))^3";;
		}
	}
};

