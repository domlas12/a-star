// a_star.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main()
{
	int wsp1 = 20;
	int wsp2 = 20;
	int wsp_p_x, wsp_p_y, wsp_k_x, wsp_k_y;
	int m, n, l, ost1, ost2, r, t;
	float k;
	int rzedy = wsp1 + 1;
	double **P;
	P = new double*[rzedy];
	while (rzedy--) P[rzedy] = new double[wsp2 + 1];
	ifstream plik("grid.txt", ios::in);
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			plik >> P[i][j];
		}
	}
	plik.close();
	r = 1;
	cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
	cin >> wsp_p_x;
	if (wsp_p_x < 1 || wsp_p_x > 20)
	{
		cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
		do {
			cin >> wsp_p_x;
		} while (wsp_p_x < 1 || wsp_p_x > 20);
	}
	cin >> wsp_p_y;
	if (wsp_p_y < 1 || wsp_p_y > 20)
	{
		cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
		do {
			cin >> wsp_p_y;
		} while (wsp_p_y < 1 || wsp_p_y > 20);
	}
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
			{
				cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
				r = 0;
			}
		}
	}
	if (r == 0)
	{
		while (r != 1)
		{
			r = 2;
			cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
			cin >> wsp_p_x;
			if (wsp_p_x < 1 || wsp_p_x > 20)
			{
				cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_p_x;
				} while (wsp_p_x < 1 || wsp_p_x > 20);
			}
			cin >> wsp_p_y;
			if (wsp_p_y < 1 || wsp_p_y > 20)
			{
				cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_p_y;
				} while (wsp_p_y < 1 || wsp_p_y > 20);
			}
			for (int i = 1; i < wsp1 + 1; i++)
			{
				for (int j = 1; j < wsp2 + 1; j++)
				{
					if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
					{
						cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
						r = 0;
					}
				}
			}
			if (r == 2)
			{
				r = 1;
			}
		}
	}
	cout << "poczatek(" << wsp_p_x << "," << wsp_p_y << ") \n \n";
	cout << "Podaj wspolrzedne koncowe X,Y. \n";
	cin >> wsp_k_x;
	if (wsp_k_x < 1 || wsp_k_x > 20)
	{
		cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
		do {
			cin >> wsp_k_x;
		} while (wsp_k_x < 1 || wsp_k_x > 20);
	}
	cin >> wsp_k_y;
	if (wsp_k_y < 1 || wsp_k_y > 20)
	{
		cout << "Wartoœæ wspó³rzêdnej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
		do {
			cin >> wsp_k_y;
		} while (wsp_k_y < 1 || wsp_k_y > 20);
	}
	if (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
	{
		cout << "Punkt koncowy musi byc inny od punktu poczatkowego. Podaj jeszcze raz wspolrzedne. \n \n";
		while (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
		{
			r = 1;
			cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
			cin >> wsp_p_x;
			if (wsp_p_x < 1 || wsp_p_x > 20)
			{
				cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_p_x;
				} while (wsp_p_x < 1 || wsp_p_x > 20);
			}
			cin >> wsp_p_y;
			if (wsp_p_y < 1 || wsp_p_y > 20)
			{
				cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_p_y;
				} while (wsp_p_y < 1 || wsp_p_y > 20);
			}
			for (int i = 1; i < wsp1 + 1; i++)
			{
				for (int j = 1; j < wsp2 + 1; j++)
				{
					if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
					{
						cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
						r = 0;
					}
				}
			}
			if (r == 0)
			{
				while (r != 1)
				{
					r = 2;
					cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
					cin >> wsp_p_x;
					if (wsp_p_x < 1 || wsp_p_x > 20)
					{
						cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_p_x;
						} while (wsp_p_x < 1 || wsp_p_x > 20);
					}
					cin >> wsp_p_y;
					if (wsp_p_y < 1 || wsp_p_y > 20)
					{
						cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_p_y;
						} while (wsp_p_y < 1 || wsp_p_y > 20);
					}
					for (int i = 1; i < wsp1 + 1; i++)
					{
						for (int j = 1; j < wsp2 + 1; j++)
						{
							if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
							{
								cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
								r = 0;
							}
						}
					}
					if (r == 2)
					{
						r = 1;
					}
				}
			}
			cout << "poczatek(" << wsp_p_x << "," << wsp_p_y << ") \n \n";
			cout << "Podaj wspolrzedne koncowe X,Y. \n";
			cin >> wsp_k_x;
			if (wsp_k_x < 1 || wsp_k_x > 20)
			{
				cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_k_x;
				} while (wsp_k_x < 1 || wsp_k_x > 20);
			}
			cin >> wsp_k_y;
			if (wsp_k_y < 1 || wsp_k_y > 20)
			{
				cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_k_y;
				} while (wsp_k_y < 1 || wsp_k_y > 20);
			}
			if (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
			{
				cout << "Punkt koncowy musi byc inny od punktu poczatkowego. Podaj jeszcze raz wspolrzedne. \n \n";
			}
		}
	}
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			if ((P[i][j] == 5) && (i == wsp_k_x) && (j == wsp_k_y))
			{
				cout << "Punkt koncowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
				r = 0;
			}
		}
	}
	if (r == 0)
	{
		while (r != 1)
		{
			r = 2;
			cout << "Podaj wspolrzedne koncowe X,Y. \n";
			cin >> wsp_k_x;
			if (wsp_k_x < 1 || wsp_k_x > 20)
			{
				cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_k_x;
				} while (wsp_k_x < 1 || wsp_k_x > 20);
			}
			cin >> wsp_k_y;
			if (wsp_k_y < 1 || wsp_k_y > 20)
			{
				cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
				do {
					cin >> wsp_k_y;
				} while (wsp_k_y < 1 || wsp_k_y > 20);
			}
			if (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
			{
				cout << "Punkt koncowy musi byc inny od punktu poczatkowego. Podaj jeszcze raz wspolrzedne. \n \n";
				while (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
				{
					r = 1;
					cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
					cin >> wsp_p_x;
					if (wsp_p_x < 1 || wsp_p_x > 20)
					{
						cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_p_x;
						} while (wsp_p_x < 1 || wsp_p_x > 20);
					}
					cin >> wsp_p_y;
					if (wsp_p_y < 1 || wsp_p_y > 20)
					{
						cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_p_y;
						} while (wsp_p_y < 1 || wsp_p_y > 20);
					}
					for (int i = 1; i < wsp1 + 1; i++)
					{
						for (int j = 1; j < wsp2 + 1; j++)
						{
							if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
							{
								cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
								r = 0;
							}
						}
					}
					if (r == 0)
					{
						while (r != 1)
						{
							r = 2;
							cout << "Podaj wspolrzedne poczatkowe X,Y. \n";
							cin >> wsp_p_x;
							if (wsp_p_x < 1 || wsp_p_x > 20)
							{
								cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
								do {
									cin >> wsp_p_x;
								} while (wsp_p_x < 1 || wsp_p_x > 20);
							}
							cin >> wsp_p_y;
							if (wsp_p_y < 1 || wsp_p_y > 20)
							{
								cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
								do {
									cin >> wsp_p_y;
								} while (wsp_p_y < 1 || wsp_p_y > 20);
							}
							for (int i = 1; i < wsp1 + 1; i++)
							{
								for (int j = 1; j < wsp2 + 1; j++)
								{
									if ((P[i][j] == 5) && (i == wsp_p_x) && (j == wsp_p_y))
									{
										cout << "Punkt poczatkowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
										r = 0;
									}
								}
							}
							if (r == 2)
							{
								r = 1;
							}
						}
					}
					cout << "poczatek(" << wsp_p_x << "," << wsp_p_y << ") \n \n";
					cout << "Podaj wspolrzedne koncowe X,Y. \n";
					cin >> wsp_k_x;
					if (wsp_k_x < 1 || wsp_k_x > 20)
					{
						cout << "Wartosc wspolrzednej X musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_k_x;
						} while (wsp_k_x < 1 || wsp_k_x > 20);
					}
					cin >> wsp_k_y;
					if (wsp_k_y < 1 || wsp_k_y > 20)
					{
						cout << "Wartosc wspolrzednej Y musi miescic sie w zakresie 1-20. Podaj wspolrzedna ponownie. \n";
						do {
							cin >> wsp_k_y;
						} while (wsp_k_y < 1 || wsp_k_y > 20);
					}
					if (wsp_p_x == wsp_k_x && wsp_p_y == wsp_k_y)
					{
						cout << "Punkt koncowy musi byc inny od punktu poczatkowego. Podaj jeszcze raz wspolrzedne. \n \n";
					}
				}
			}
			for (int i = 1; i < wsp1 + 1; i++)
			{
				for (int j = 1; j < wsp2 + 1; j++)
				{
					if ((P[i][j] == 5) && (i == wsp_k_x) && (j == wsp_k_y))
					{
						cout << "Punkt koncowy musi byc inny od przeszkody. Podaj jeszcze raz wspolrzedne. \n";
						r = 0;
					}
				}
			}
			if (r == 2)
			{
				r = 1;
			}
		}
	}
	cout << "koniec(" << wsp_k_x << "," << wsp_k_y << ") \n \n \n";
	P[wsp_p_x][wsp_p_y] = 6;
	P[wsp_k_x][wsp_k_y] = 7;
	m = wsp_p_x;
	n = wsp_p_y;
	rzedy = wsp1 + 1;
	int **G;
	G = new int*[rzedy];
	while (rzedy--) G[rzedy] = new int[wsp2 + 1];
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			G[i][j] = 999;
		}
	}
	rzedy = wsp1 + 1;
	float **H;
	H = new float*[rzedy];
	while (rzedy--) H[rzedy] = new float[wsp2 + 1];
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			H[i][j] = P[i][j];
			if (P[i][j] == 0)
			{
				H[i][j] = sqrt((i - wsp_k_x)*(i - wsp_k_x) + (j - wsp_k_y)*(j - wsp_k_y));
			}
		}
	}
	rzedy = wsp1 + 1;
	float **F;
	F = new float*[rzedy];
	while (rzedy--) F[rzedy] = new float[wsp2 + 1];
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			F[i][j] = 0;
		}
	}
	rzedy = wsp1 + 1;
	short **pola_typ;
	pola_typ = new short*[rzedy];
	while (rzedy--) pola_typ[rzedy] = new short[wsp2 + 1];
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			pola_typ[i][j] = P[i][j];
			if (P[i][j] == 6)
			{
				pola_typ[i][j] = 0;
			}
			if (P[i][j] == 7)
			{
				pola_typ[i][j] = 0;
			}
		}
	}
	rzedy = wsp1 + 1;
	short **rodzic;
	rodzic = new short*[rzedy];
	while (rzedy--) rodzic[rzedy] = new short[wsp2 + 1];
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			rodzic[i][j] = P[i][j];
		}
	}
	l = 0;
	if (n == 1)
	{
		l = 1;
		if (m == 1)
		{
			l = 2;
		}
	}
	if ((m == 1) && (n != 1))
	{
		l = 3;
		if (n == 20)
		{
			l = 4;
		}
	}
	if ((n == 20) && (m != 1))
	{
		l = 5;
		if (m == 20)
		{
			l = 6;
		}
	}
	if ((m == 20) && (n != 20))
	{
		l = 7;
		if (n == 1)
		{
			l = 8;
		}
	}
	if (l == 0)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	if (l == 1)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	if (l == 2)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	if (l == 3)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	if (l == 4)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
	}
	if (l == 5)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m + 1][n] == 0)
		{
			pola_typ[m + 1][n] = 1;
			rodzic[m + 1][n] = 1;
			G[m + 1][n] = G[m][n] + 1;
			F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
			k = F[m + 1][n];
		}
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
	}
	if (l == 6)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
	}
	if (l == 7)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m][n - 1] == 0)
		{
			pola_typ[m][n - 1] = 1;
			rodzic[m][n - 1] = 2;
			G[m][n - 1] = G[m][n] + 1;
			F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
			k = F[m][n - 1];
		}
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	if (l == 8)
	{
		pola_typ[m][n] = 2;
		G[m][n] = 0;
		ost1 = m;
		ost2 = n;
		if (pola_typ[m - 1][n] == 0)
		{
			pola_typ[m - 1][n] = 1;
			rodzic[m - 1][n] = 3;
			G[m - 1][n] = G[m][n] + 1;
			F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
			k = F[m - 1][n];
		}
		if (pola_typ[m][n + 1] == 0)
		{
			pola_typ[m][n + 1] = 1;
			rodzic[m][n + 1] = 4;
			G[m][n + 1] = G[m][n] + 1;
			F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
			k = F[m][n + 1];
		}
	}
	while (pola_typ[wsp_k_x][wsp_k_y] != 2)
	{
		t = 0;
		k = 430;
		for (int i = 1; i < wsp1 + 1; i++)
		{
			for (int j = 1; j < wsp2 + 1; j++)
			{
				if (pola_typ[i][j] == 1)
				{
					if (F[i][j] < k)
					{
						k = F[i][j];
					}
				}
			}
		}
		r = 0;
		for (int i = 1; i < wsp1 + 1; i++)
		{
			for (int j = 1; j < wsp2 + 1; j++)
			{
				if (pola_typ[i][j] == 1)
				{
					if (F[i][j] == k)
					{
						m = i;
						n = j;
						r++;
					}
				}
			}
		}
		for (int i = 1; i < wsp1 + 1; i++)
		{
			for (int j = 1; j < wsp2 + 1; j++)
			{
				if (pola_typ[i][j] == 1)
				{
					if (r > 1)
					{
						l = 0;
						if (j == 1)
						{
							l = 1;
							if (i == 1)
							{
								l = 2;
							}
						}
						if ((i == 1) && (j != 1))
						{
							l = 3;
							if (j == 20)
							{
								l = 4;
							}
						}
						if ((j == 20) && (i != 1))
						{
							l = 5;
							if (i == 20)
							{
								l = 6;
							}
						}
						if ((i == 20) && (j != 20))
						{
							l = 7;
							if (j == 1)
							{
								l = 8;
							}
						}
						if ((F[i][j] == k) && (l == 0) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1][ost2 - 1])
							|| (F[i][j] == F[ost1 - 1][ost2])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 1) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1][ost2 - 1])
							|| (F[i][j] == F[ost1 - 1][ost2])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 2) && ((F[i][j] == F[ost1][ost2 - 1])
							|| (F[i][j] == F[ost1 - 1][ost2])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 3) && ((F[i][j] == F[ost1][ost2 - 1])
							|| (F[i][j] == F[ost1 - 1][ost2])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 4) && ((F[i][j] == F[ost1 - 1][ost2])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 5) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1 - 1][ost2])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 6) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 7) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1][ost2 - 1])
							|| (F[i][j] == F[ost1][ost2 + 1])))
						{
							m = i;
							n = j;
						}
						if ((F[i][j] == k) && (l == 8) && ((F[i][j] == F[ost1 + 1][ost2])
							|| (F[i][j] == F[ost1][ost2 - 1])))
						{
							m = i;
							n = j;
						}
					}
				}
			}
		}
		r = 0;
		l = 0;
		if (n == 1)
		{
			l = 1;
			if (m == 1)
			{
				l = 2;
			}
		}
		if ((m == 1) && (n != 1))
		{
			l = 3;
			if (n == 20)
			{
				l = 4;
			}
		}
		if ((n == 20) && (m != 1))
		{
			l = 5;
			if (m == 20)
			{
				l = 6;
			}
		}
		if ((m == 20) && (n != 20))
		{
			l = 7;
			if (n == 1)
			{
				l = 8;
			}
		}
		if (l == 0)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		if (l == 1)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		if (l == 2)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		if (l == 3)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		if (l == 4)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
		}
		if (l == 5)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m + 1][n] == 0)
			{
				pola_typ[m + 1][n] = 1;
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m + 1][n] == 1) && (G[m + 1][n] > G[m][n] + 1))
			{
				rodzic[m + 1][n] = 1;
				G[m + 1][n] = G[m][n] + 1;
				F[m + 1][n] = G[m + 1][n] + H[m + 1][n];
				k = F[m + 1][n];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
		}
		if (l == 6)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
		}
		if (l == 7)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m][n - 1] == 0)
			{
				pola_typ[m][n - 1] = 1;
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m][n - 1] == 1) && (G[m][n - 1] > G[m][n] + 1))
			{
				rodzic[m][n - 1] = 2;
				G[m][n - 1] = G[m][n] + 1;
				F[m][n - 1] = G[m][n - 1] + H[m][n - 1];
				k = F[m][n - 1];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		if (l == 8)
		{
			pola_typ[m][n] = 2;
			ost1 = m;
			ost2 = n;
			if (pola_typ[m - 1][n] == 0)
			{
				pola_typ[m - 1][n] = 1;
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if (pola_typ[m][n + 1] == 0)
			{
				pola_typ[m][n + 1] = 1;
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
			if ((pola_typ[m - 1][n] == 1) && (G[m - 1][n] > G[m][n] + 1))
			{
				rodzic[m - 1][n] = 3;
				G[m - 1][n] = G[m][n] + 1;
				F[m - 1][n] = G[m - 1][n] + H[m - 1][n];
				k = F[m - 1][n];
			}
			if ((pola_typ[m][n + 1] == 1) && (G[m][n + 1] > G[m][n] + 1))
			{
				rodzic[m][n + 1] = 4;
				G[m][n + 1] = G[m][n] + 1;
				F[m][n + 1] = G[m][n + 1] + H[m][n + 1];
				k = F[m][n + 1];
			}
		}
		for (int i = 1; i < wsp1 + 1; i++)
		{
			for (int j = 1; j < wsp2 + 1; j++)
			{
				if (pola_typ[i][j] == 1)
				{
					if ((i == wsp_k_x) && (j == wsp_k_y))
					{
						pola_typ[i][j] = 2;
					}
				}
			}
		}
		for (int i = 1; i < wsp1 + 1; i++)
		{
			for (int j = 1; j < wsp2 + 1; j++)
			{
				if (pola_typ[i][j] == 1)
				{
					t++;
				}
			}
		}
		if (t == 0)
		{
			cout << "U¿ywaj¹c podanych wspó³rzêdnych nie da rady dotrzeæ do koñca. \n \n";
			pola_typ[wsp_p_x][wsp_p_y] = 6;
			pola_typ[wsp_k_x][wsp_k_y] = 7;
			for (int i = 1; i < wsp1 + 1; i++)
			{
				for (int j = 1; j < wsp2 + 1; j++)
				{
					cout << " " << pola_typ[i][j];
				}
				cout << endl;
			}
			cout << endl;
			return 0;
		}
	}
	m = wsp_k_x;
	n = wsp_k_y;
	pola_typ[m][n] = 7;
	while (pola_typ[wsp_p_x][wsp_p_y] != 6)
	{
		if (rodzic[m][n] == 1)
		{
			m = m - 1;
			pola_typ[m][n] = 3;
		}
		else if (rodzic[m][n] == 2)
		{
			n = n + 1;
			pola_typ[m][n] = 3;
		}
		else if (rodzic[m][n] == 3)
		{
			m = m + 1;
			pola_typ[m][n] = 3;
		}
		else if (rodzic[m][n] == 4)
		{
			n = n - 1;
			pola_typ[m][n] = 3;
		}
		if (pola_typ[wsp_p_x][wsp_p_y] == 3)
		{
			pola_typ[wsp_p_x][wsp_p_y] = 6;
		}
	}
	/*
	for(int i = 1; i < wsp1+1; i++)
	{
	for(int j = 1; j < wsp2+1; j++)
	{
	if(pola_typ[i][j] == 3)
	{
	if( (j-2) != 1 )
	{
	if(i != 1)
	{

	}
	}
	}
	}
	}
	*/
	cout << "Droga: \n";
	cout << endl;
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			cout << " " << pola_typ[i][j];
		}
		cout << "\n";
	}
	cout << endl;
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			if (pola_typ[i][j] == 3)
			{
				P[i][j] = 3;
			}
		}
	}
	cout << endl;
	for (int i = 1; i < wsp1 + 1; i++)
	{
		for (int j = 1; j < wsp2 + 1; j++)
		{
			cout << " " << P[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i < wsp1 + 1; i++)
	{
		delete[] P[i];
	}
	delete[] P;
	system("PAUSE");
}

