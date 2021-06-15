// 1Tool Plaza Passing asan tarika.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	char army, licience, idCard, nationality, a;

	cout << "Do you belong to army?(Y/N)";
	cin >> army;
	switch (army)
	{
	case 'y':
	case 'Y':
	{
				cout << "Do you have licence?(Y/N)";
				cin >> licience;
				switch (licience)
				{
				case 'y':
				case 'Y':
				{
							cout << "Welcom...!!!You can pass througt the tool plaza.";
							a = 0;
							break;
				}
				case 'n':
				case 'N':
				{
							a = 1;
							break;
				}
				default:
				{
						   cout << "You enter an invalid key.";
						   a = 0;
						   break;
				}
				}
				break;
	}
	case 'n':
	case 'N':
	{
				a = 1;
				break;
	}
	default:
	{
			   cout << "You enter an invalid key.";
			   a = 0;
			   break;
	}
	}

	
	switch (a)
	{
	case 1:
	{
			  cout << "Do you have PAKISTANI nationality?(Y/N)";
			  cin >> nationality;
			  switch (nationality)
			  {
			  case 'y':
			  case 'Y':
			  {
						  a = 1;
						  break;
			  }
			  case 'n':
			  case 'N':
			  {
						  cout << "Sorry...!!!You cannot pass through the tool plaza.";
						  a = 0;
						  break;
			  }
			  default:
			  {
						 cout << "You enter an invalid key.";
						 a = 0;
						 break;
			  }
			  }
	}
		break;
	}


	switch (a)
	{
	case 1:
	{
			  cout << "Do you have offical id card?(Y/N)";
			  cin >> idCard;
			  switch (idCard)
			  {
			  case 'y':
			  case 'Y':
			  {
						  cout << "Welcom...!!!You can pass througt the tool plaza.";
						  break;
			  }
			  case 'n':
			  case 'N':
			  {
						  cout << "Sorry...!!!You cannot pass through the tool plaza."; 
						  break;
			  }
			  default:
			  {
						 cout << "You enter an invalid key.";
						 break;
			  }
			  }
	}
	}

	return 0;
}

