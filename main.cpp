#include <iostream>
#include <cstring>

using namespace std;

void print(char * table_size);
bool premise(bool, bool, bool);
bool conclusion(bool, bool, bool);
const int SIZE = 200;

int main()
{
	char table [SIZE]; //table to print
	print(table); //fills table, calls premise and conclusion, prints if valid
	return 0;
}


void print(char * table)
{
	bool P = true, Q = true, R = true; //logic variables
	int j = 0; //int to flip R between true and false
	char digits [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //an array to capture row number
	char space[10] = "	"; //space to pass into table
	char row_num [3] = "0 "; //to give the table row numbers
	char new_line[3] = "\n"; //to give the table a new line
	char T [10] = "T	"; //to signify in the logic table if a variable is true
	char F [10] = "F	"; // to signify in the logic table if a variable is false
	int valid = 0; //holds on to the information if a statement is invalid, if remains 0, statement is valid
	char arg[32] = "The argument is invalid in row "; //statement if argument is invalid

	strncat(table,"Row	P	Q	R	Prem	Concl\n", SIZE); //table head

	for(int i = 0; i < 8; i++)
	{	
		bool A, B; //logic variables to hold if the premise and conclusion are true or false
		
		j = ++j;	//increment j
		row_num[0] = digits[i]; //transfers row number to the array, so it can be passed into strncat
		strncat(table, row_num, SIZE);	//row number added to table
		strncat(table, space, SIZE);	//space into table
		if(i < 4)
		{	//sets first four rows of P to T
			strncat(table, T, SIZE);
			P = true;
		}
		else
		{	//sets last four rows of P to F
			strncat(table, F, SIZE);
			P = false;
		}

		if(j < 3)		
		{	//sets Q rows 0,1,4&5 to T
			strncat(table, T, SIZE);
			Q = true;
		}
		else
		{	//sets Q rows 2,3,6&7 to F
			strncat(table, F, SIZE);
			Q = false;
		}

		if(i % 2)
		{	//sets R odd number rows to F
			strncat(table, F, SIZE);
			R = false;
		}
		else
		{	//sets R even number rows to T
			strncat(table, T, SIZE);
			R = true;
		}
		A = premise(P, Q, R);	//premise function sets A to T or F, depending on the premise statement
		B = conclusion(P, Q, R); //conclusion function sets B to T or F, depending on conclusion statement

		if(A)
		{	//loads T into table as premise is true
			strncat(table, T, SIZE);
		}
		else
		{	//loads F into table as premise is false
			strncat(table, F, SIZE);
		}

		if(B)
		{	//loads T into table as conclusion is True
			strncat(table, T, SIZE);
		}
		else
		{	//loads F into table as conclusion is False
			strncat(table, F, SIZE);
		}

		if(A && !B) 
		{	//if premise is true, but conclusion is false, print the argument is invalid because of row #
			cout << arg << digits[i] << endl;
			valid = valid + 1; //argument is not valid, this int records the fact
		} 

		if(j == 4)
		{	//reset j
			j = 0;
		}
		strncat(table, new_line, SIZE);	//loads into table a new_line
	}

	if(!valid)
	{	//if no invalid rows found, print statement is valid
		cout << "The argument is valid." << endl;
	}

	cout << table; //print table
}

bool premise(bool P, bool Q, bool R)
{		//change this for changing premise, just comment out
		//return line, and return alternative premise
	return (((P || Q) && (!Q || R)) != ((P && Q) == (R && Q)));
}

bool conclusion(bool P, bool Q, bool R)
{	//change this for changing conclusion, just comment out
	//return line and return alternative conclusion
	return (P || R);
}
