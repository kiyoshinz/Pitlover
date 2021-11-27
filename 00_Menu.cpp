#include <iostream>
using namespace std;

int main ()
{
	// Shared (no need to copy)
	string mal_company="Pitlover Corporation Group",
		mal_hotel="Pitlover Hotel",
		mal_airport="Pitlover Airport Terminal",
		mal_bus="Pitlover Bus Terminal";
	char m1;
	short i1;
	// Airpot Terminal Variables (paste 01_Airpot.cpp here)
	// Hotel Variables (paste 02_Hotel.cpp here)
	do
	{
		// Start of Menu
		cout<<"Welcome to "<<mal_company<<". It's our duty to serve you.\n"
			<<"\n[Choose an option]"
			<<"\n1. "<<mal_airport
			<<"\n2. "<<mal_hotel
			<<"\n3. "<<mal_bus
			<<"\n4. Exit"
			<<"\n\nChoice: ";
		cin>>m1;
		cout<<endl;	
		system("cls");
		if (m1=='1') 
		{	
			i1=1;
			// Airpot Terminal Code (paste 01_Airpot.cpp here)
		}	
		else if (m1=='2') 
		{	
			i1=1;	
			// Hotel Terminal Code (paste with 02_Hotel.cpp here)
		}
		else if (m1=='3') 
		{	
			i1=1;	
			// Bus Terminal Code (paste with your group's code here)
		}
		else if (m1=='4')
		{	
			i1=1;	
			cout<<"Thank you for choosing "<<mal_company<<", Goodbye. ";
		}
		else
		{
			cout<<"Invalid. ";
			system ("pause");
			system("cls");
		}
	}
	while (i1!=1);
}
