// 1Tool plaza passing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	char army, licence, nationality, idCard;

	cout << "Do you belong to army?(Y/N)                =   ";
	cin >> army;
	switch (army)
	{
	case 'y':
	case 'Y':
	{
				cout << "Do you have licience?(Y/N)                 =   ";
				cin >> licence;
				switch (licence)
				{
				case 'y':
				case 'Y':
				{
							cout << "Wellcom...!!! You Can pass througt tool plaza.";
							break;
				}
				case 'n':
				case 'N':
				{
							cout << "Do you have PAKISTANI nationality?(Y/N)    =   ";
							cin >> nationality;
							switch (nationality)
							{
							case 'y':
							case 'Y':
							{
										cout << "Do you have official id card?(Y/N)         =   ";
										cin >> idCard;
										switch (idCard)
										{
										case 'y':
										case 'Y':
										{
													cout << "Wellcom...!!! You Can pass througt tool plaza.";
													break;
										}
										case 'n':
										case 'N':
										{
													cout << "SORRY. You cannot pass through the tool plaza.";
													break;
										}
										default:
										{
												   cout << "You enter an invalid key";
												   break;
										}
										}
										break;
							}
							case 'n':
							case 'N':
							{
										cout << "SORRY. You cannot pass through the tool plaza.";
										break;
							}
							default:
							{
									   cout << "You enter an invalid key.";
									   break;
							}
							}
							break;
				}
				default:
				{
						   cout << "You enter an invalid key.";
						   break;
				}
				}
				break;
	}

	case 'n':
	case 'N':
	{
				cout << "Do you have PAKISTANI nationality?(Y/N)    =   ";
				cin >> nationality;
				switch (nationality)
				{
				case 'y':
				case 'Y':
				{
							cout << "Do you have official id card?(Y/N)";
							cin >> idCard;
							switch (idCard)
							{
							case 'y':
							case 'Y':
							{
										cout << "Wellcom...!!! You Can pass througt tool plaza.";
										break;
							}
							case 'n':
							case 'N':
							{
										cout << "SORRY. You cannot pass through the tool plaza.";
										break;
							}
							default:
								{
									   cout << "You enter an invalid key.(Y/N)";
									   break;
								}
							}
				case 'n':
				case 'N':
				{
							cout << "SORRY. You cannot pass through the tool plaza.";
							break;
				}
				default:
				{
						   cout << "You enter an invalid key.";
						   break;
				}
				break;
			    }
				}
						default:
			{
					cout << "You enter an invalid key.";
					break;
		    }
		}
	}
	return 0;
}

