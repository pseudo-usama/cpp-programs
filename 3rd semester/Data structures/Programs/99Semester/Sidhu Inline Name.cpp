for (int i = 0; i < 7; i++)
	{
		/* Character A */
		for (int j = 0; j < 7; j++)
		{
			if (i == 0 || j == 0 || j == 6 || i == 3)
				if (i == 0 && j % 6 == 0)
					cout << " ";
				else
					cout << "*";
			else
				cout << " ";
		}

		/*Character U*/
		cout << "\t";
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || j == 6 || i == 6)
				if (i == 6 && j % 6 == 0)
					cout << " ";
				else
					cout << "*";
			else
				cout << " ";
		}

		cout << "\t";
		/* Character B */
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || j == 6 || i == 0 || i == 6 || i == 3)
			{
				if (j == 6 && (i % 3 == 0))
					cout << " ";
				else
					cout << "*";
			}
			else
				cout << " ";
		}

		cout << "\t";
		/*Character L*/
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || i == 6)
				cout << "*";
			else
				cout << " ";
		}

		cout << "\t";
		/* Character I*/
		for (int j = 0; j < 7; j++)
		{
			if (i == 0 || i == 6 || j == 3)
				cout << "*";
			else
				cout << " ";
		}

		cout << "\t";
		/* Character N */
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || j == 6 || i == j)
				cout << "*";
			else
				cout << " ";
		}


		cout << "\t";
		/* Character A */
		for (int j = 0; j < 7; j++)
		{
			if (i == 0 || j == 0 || j == 6 || i == 3)
				if (i == 0 && j % 6 == 0)
					cout << " ";
				else
					cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}