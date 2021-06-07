// 16Sary Progrms Secnd Asingment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int PriOpraSelector = 2, SecOpraSelector = 20;

	do{
		if (SecOpraSelector == 20)
		{
			cout << "                          List of Programs"                                    << endl;
			cout << "                   To exit whole program enter    '0'."                        << endl << endl;
			cout << "               Or enter any number to rum that program"                        << endl;
			cout << "1) Fill Triangle         2) Empty Box               3) Empty Triangle"         << endl;
			cout << "4) Empty Right Triangle  5) Fill Dimond             6) Bottom Half Dimond"     << endl;
			cout << "7) Empty Dimond          8) 1/1! + 1/2! + 1/3! Sum  9) 1/2 - 3/4 + 5/6 Sum"    << endl;
			cout << "10) 1 + 1/11 + 1/21 Sum  11) 2 6 11 10 15 21 Series 12) Box having Numbers"  << endl;
			cout << "         13) Plinomial Series Sum  14) 1 + (1+2) + (1+2+3) Sum"                << endl;
			cout << "               15) Sum, Product and Average of 1 to 50"                        << endl << endl;
		}

		if (SecOpraSelector != 1)
		{
			cout << endl << endl;

			cout << "    Enter here the number     =  ";
			cin >> PriOpraSelector;

			while (PriOpraSelector < 0 || PriOpraSelector > 15)
			{
				cout << endl << "Enter a number from '0' to '15'" << endl;
				cout << "    Enter here the number     =  ";
				cin >> PriOpraSelector;
			}
		}

		if (PriOpraSelector == 1)																	// Main Opration Selector
		{
			
			int length, i = 0, j = 0, spacer, SpacerHelper, stars, StarsHelper;					//Fill Triangle

			cout << "Enter the length        =   ";
			cin >> length;

			for (; length < 0;)
			{
				cout << "Length never be -ve. Enter a Positive number." << endl;
				cout << "Enter the length        =   ";
				cin >> length;
			}

			while (j <= length)
			{
				SpacerHelper = 0;
				StarsHelper = 0;
				spacer = (length - j) * 2;
				stars = 2 * (j - 1) + j;

				while (SpacerHelper < spacer)
				{
					cout << "  ";
					SpacerHelper++;
				}
				while (StarsHelper < stars)
				{
					cout << "* ";
					StarsHelper++;
				}
				cout << endl;
				j++;
			}

			cout << endl;
			cout << "Remember that the entered length is the height of the triangle.";


		}
		else if (PriOpraSelector == 2)																// Main Opration Selector
		{

			int length, width, a = 1, b;												//Empty Box

			do{
				cout << "Enter the length of the box(+ve number)         =   ";
				cin >> length;
			} while (length < 0);

			do{
				cout << "Enter the width of the box(+ve number)          =   ";
				cin >> width;
			} while (width < 0);

			while (a <= width)
			{
				b = 1;
				while (b <= length)
				{
					if (a == 1 || a == width || b == 1 || b == length)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
					b++;
				}
				a++;
				cout << endl;
			}

		}
		else if (PriOpraSelector == 3)																// Main Opration Selector
		{

			int length, j = 1, spacer1, spacer2, SpacerHelper1, SpacerHelper2;					//Empty Triangle
			do{
				cout << "Enter the length of the the triangle                  =   ";
				cin >> length;

				if (length % 2 == 0)
				{
					cout << "Enter an odd number." << endl;
				}
				if (length < 0)
				{
					cout << "Length can never -ve.Enter an +ve number." << endl;
				}

			} while (!(length % 2 == 1) || length < 0);

			while (j <= length - 1)
			{
				spacer1 = length - j;
				spacer2 = j * 2 - 3;
				SpacerHelper1 = 1;
				SpacerHelper2 = 1;
				if (j % 2 != 0)
				{

					while (SpacerHelper1 <= spacer1)
					{
						cout << "  ";
						SpacerHelper1++;
					}

					if (j != 1)
					{
						cout << "* ";
					}

					while (SpacerHelper2 <= spacer2)
					{
						cout << "  ";
						SpacerHelper2++;
					}

					cout << "* ";

				}
				cout << endl;
				j++;
			}

			length = length + length - 1;
			j = 1;
			while (j <= length)
			{
				cout << "* ";
				j++;
			}

			cout << endl << "Remember that the length entered is the height of that triangle.";
			cout << " 3              ";

		}
		else if (PriOpraSelector == 4)																// Main Opration Selector
		{

			int length, i, j = 1;																//Empty Right Triangle

			cout << "Enter the length" << endl;
			cout << "(Note that base and perpendicular have same length).       =  ";
			cin >> length;

			for (; length < 0;)
			{
				cout << "Enter the length. Enter a positive number.  = " << endl;
				cin >> length;
			}

			for (; j <= length;)
			{
				i = 1;
				for (; i <= length;)
				{
					if (j == length || i == 1 || i == j)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
					i++;
				}
				cout << endl;
				j++;
			}

		}
		else if (PriOpraSelector == 5)																// Main Opration Selector
		{

			int length, spacer, stars;														//Fill Domond

			do{
				cout << "Enter the length of the dimond.             =    ";
				cin >> length;

				if (length < 0)
				{
					cout << "Length can never be zero." << endl;
				}
			} while (length < 0);

			for (int j = 1; j <= length; j++)
			{
				spacer = length - j;
				stars = 2 * j - 1;

				for (int a = 1; a <= spacer; a++)
				{
					cout << "  ";
				}
				for (int a = 1; a <= stars; a++)
				{
					cout << "* ";
				}
				cout << endl;
			}

			length = length - 1;

			for (int j = 1; j <= length; j++)
			{
				spacer = j;
				stars = (length - j) * 2 + 1;

				for (int a = 1; a <= spacer; a++)
				{
					cout << "  ";
				}
				for (int a = 1; a <= stars; a++)
				{
					cout << "* ";
				}
				cout << endl;
			}

			cout << endl << "Remember that the length entered is the length of dimond  from its center to its any corner.";

		}
		else if (PriOpraSelector == 6)																// Main Opration Selector
		{

			int input, spacer, j = 0, stars, SpacerHelper, StarsHelper;

			do{
				cout << "Enter the length       =   ";
				cin >> input;

				if (input < 0)
				{
					cout << "Length can never be zero." << endl;
				}
			} while (input < 0);

			input = input - 1;

			do{
				spacer = j - 1;
				stars = (input - j) * 2;
				StarsHelper = 0;
				SpacerHelper = 0;
				while (SpacerHelper <= spacer)
				{
					cout << "  ";
					SpacerHelper++;
				}
				while (StarsHelper <= stars)
				{
					cout << "* ";
					StarsHelper++;
				}
				cout << endl;
				j++;
			} while (j <= input);

			cout << endl;
			cout << "Note that the entered length is the height of the triangle.";

		}
		else if (PriOpraSelector == 7)																// Main Opration Selector
		{

			int length, j = 1, spacer1, spacer2, SpacerHelper1, SpacerHelper2;					//Empty Dimond
			do{
				cout << "Enter the length.           =   ";
				cin >> length;

				if (length < 0)
				{
					cout << "Length can never be zero." << endl;
				}
			} while (length < 0);
			if (length != 0)
			{

				do{
					spacer1 = length - j;
					spacer2 = j * 2 - 3;
					SpacerHelper1 = 1;
					SpacerHelper2 = 1;
					if (j != length)
					{
						do
						{

							cout << "  ";
							SpacerHelper1++;
						} while (SpacerHelper1 <= spacer1);
					}
					cout << "* ";

					if (j != 1)
					{

						do{

							cout << "  ";
							SpacerHelper2++;
						} while (SpacerHelper2 <= spacer2);

						cout << "* ";
					}

					cout << endl;

					j++;

				} while (j <= length);

				if (length != 1)
				{

					j = 1;
					length = length - 1;

					do{
						spacer1 = j;
						spacer2 = (length - j) * 2 - 1;
						SpacerHelper1 = 1;
						SpacerHelper2 = 1;

						do
						{

							cout << "  ";
							SpacerHelper1++;
						} while (SpacerHelper1 <= spacer1);
						cout << "* ";

						if (j != length)
						{

							do{

								cout << "  ";
								SpacerHelper2++;
							} while (SpacerHelper2 <= spacer2);

							cout << "* ";
						}

						cout << endl;

						j++;

					} while (j <= length);

				}
				cout << "Remember that the length entered is length of dimond from its center to its any corner.";

			}
		}
		else if (PriOpraSelector == 8)																// Main Opration Selector
		{

			int limit, a = 1, FactorialDecriser;												//1/1! + 1/2! +1/3! sum
			double factorial;
			float sum = 0;

			do{
				cout << "Enter the limit of the series        =   ";
				cin >> limit;

				if (limit < 0)
				{
					cout << "Enter a positive number." << endl;
				}
			} while (limit < 0);

			cout << endl;

			cout << "The sum of series " << endl;

			while (a < limit)
			{
				cout << "1/" << a << "!" << " + ";
				FactorialDecriser = a;
				factorial = 1;
				while (FactorialDecriser != 1)
				{
					factorial = factorial * FactorialDecriser;
					FactorialDecriser = FactorialDecriser - 1;
				}
				sum = sum + (1 / factorial);
				a++;
			}

			cout << "1/" << a << "!";
			FactorialDecriser = a;
			factorial = 1;
			while (FactorialDecriser != 1)
			{
				factorial = factorial * FactorialDecriser;
				FactorialDecriser = FactorialDecriser - 1;
			}
			sum = sum + (1 / factorial);

			cout << " = " << sum;

		}
		else if (PriOpraSelector == 9)																// Main Opration Selector
		{

			int range;																	//1/2 - 3/4 + 5/6 Sum
			float a = -1, b = 0, sum = 0;

			do{
				cout << "Enter the range .                       =   ";
				cin >> range;

				if (range != 0)
				{
					cout << "Enter an even number number" << endl;
				}
				if (range < 0)
				{
					cout << "Enter a positive number." << endl;
				}
			} while (range % 2 != 0 || range < 0);

			cout << endl << "    The sum of the series" << endl << "          ";

			while (b < range)
			{
				a = a + 2;
				b = b + 2;
				if (b <= range)
				{
					cout << a << "/" << b;
					sum = sum + a / b;
				}

				a = a + 2;
				b = b + 2;
				if (b <= range)
				{
					cout << " - " << a << "/" << b << " + ";
					sum = sum - a / b;
				}
			}

			cout << "     is   = ";
			cout << sum;

		}
		else if (PriOpraSelector == 10)																// Main Opration Selector
		{

			int range;																		//1 + 1/11 + 1/21 Sum
			float sum = 0.0, a = 1.0;
			do{
				cout << "Enter the range(enter number of 1, 11, 21, 31 type).       =   ";
				cin >> range;
			} while ((range - 1) % 10 != 0 && range != 0);

			cout << endl << "      The sum of the following series" << endl << "          ";

			if (range > 0)
			{

				while (a < range)
				{
					cout << "1/" << a << "+";
					sum = sum + 1 / a;
					a = a + 10.0;
				}
				cout << "1/" << a;
				sum = sum + 1 / a;
			}

			cout << endl << "                        is    =  " << sum;

		}
		else if (PriOpraSelector == 11)																// Main Opration Selector
		{

			int range, a = 1, n1 = 8, n2 = 9, n3 = 10;											//2 6 11 10 15 21 18 Series

			do{
				cout << "Enter the range of the series.          =  ";
				cin >> range;
				if (range < 0)
				{
					cout << "Enter a positive number" << endl;
				}
			} while (range < 0);

			cout << endl << "      The series is" << endl << "          ";

			while (a < range)
			{
				if (n1 <= range)
				{
					cout << n1 << " ";
				}
				if (n2 <= range)
				{
					cout << n2 << " ";
				}
				if (n3 <= range)
				{
					cout << n3 << " ";
				}
				n1 = n1 + 8;
				n2 = n2 + 9;
				n3 = n3 + 10;
				a = a + 11;
			}

		}
		else if (PriOpraSelector == 12)																// Main Opration Selector
		{

			int number, length, width, a = 1, b, MidPoint;										//Box having numbers

			do{
				cout << "Enter the length(enter a odd number)         =   ";
				cin >> length;
			} while (length % 2 == 0);

			cout << "Enter the width                              =   ";
			cin >> width;

			MidPoint = length / 2 + 1;

			while (a <= width)
			{
				b = 1;
				number = a * 10 - 10;
				while (b <= length)
				{
					if (b / MidPoint != 0 && b % MidPoint != 0)
					{
						number = number - 10;
					}
					else
					{
						number = number + 10;
					}
					cout << number << " ";
					b++;
				}
				cout << endl;
				a++;
			}

		}
		else if (PriOpraSelector == 13)																// Main Opration Selector
		{

			int base, power, coefficient, a = 1;												//Polinomial Series Sum
			double sum = 0;

			cout << "Enter the value of base.                 =    ";
			cin >> base;

			cout << "Enter the value of maximum power         =    ";
			cin >> power;

			cout << "Enter the value of coefficient.          =    ";
			cin >> coefficient;

			cout << endl << "The sum of the series " << endl << "        ";

			while (a < power)
			{
				cout << coefficient << "(" << base << ")^" << a;
				if (a % 2 != 0)
				{
					cout << " - ";
					sum = sum + coefficient * pow(base, a);
				}
				else
				{
					cout << " + ";
					sum = sum - coefficient * pow(base, a);
				}
				a++;
			}

			cout << coefficient << "*" << "(" << base << ")^" << a;
			if (a % 2 != 0)
			{
				sum = sum + coefficient * pow(base, a);
			}
			else
			{
				sum = sum - coefficient * pow(base, a);
			}
			cout << endl << endl;
			cout << "              is     =  " << sum;

		}
		else if (PriOpraSelector == 14)																// Main Opration Selector
		{

			int range, sum = 0, a = 1, b;														//1 + (1+2) + (1+2+3) Sum	

			cout << "Enter the maximum point.            =   ";
			cin >> range;

			cout << endl << "   The sum of series  " << endl << "          ";

			while (a <= range)
			{
				cout << "(";
				b = 1;
				while (b < a)
				{
					cout << b << "+";
					sum = sum + b;
					b++;
				}

				cout << b;
				sum = sum + b;

				cout << ") + ";
				a++;
			}

			cout << endl << "            is  = " << sum;

		}
		else if (PriOpraSelector == 15)																// Main Opration Selector
		{

			int sum = 0;																	//Sum Average and Product of 1 to 50
			double product = 1, a = 5.0;

			cout << "The sum of series " << endl << endl;

			while (a < 50)
			{
				cout << a << "+";
				sum = sum + a;
				a = a + 3;
			}

			cout << "50" << endl;

			cout << " is equal to      =   " << sum + 50 << endl << endl;

			cout << "And the average is " << (sum + 50.0) / 50.0 << endl << endl;

			cout << "The product of the series " << endl << endl;

			a = 5;

			while (a < 50)
			{
				cout << a << "*";
				product = product * a;
				a = a + 3;
			}
			cout << "50";

			cout << endl << " is equal to      =   " << product * 50;

		}

		cout << endl;

		if (PriOpraSelector != 0)
		{
			cout << "To start this program again enter '1'." << endl;
			cout << "To see list again enter           '20'." << endl;
			cout << "Or to close whole program enter   '0'." << endl;
			cout << "    Enter here the number     =  ";
			cin >> SecOpraSelector;


			while (SecOpraSelector != 0 && SecOpraSelector != 1 && SecOpraSelector != 20)
			{
				cout << endl << "Enter 1, 0 or 20." << endl;
				cout << "    Enter here the number     =  ";
				cin >> SecOpraSelector;
			}
			if (SecOpraSelector == 0)
			{
				PriOpraSelector = 0;
			}
		}

		cout << endl << endl;

	} while (PriOpraSelector != 0 && SecOpraSelector != 0);

	return 0;
}

