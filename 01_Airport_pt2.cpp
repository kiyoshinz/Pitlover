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
	// Airpot Terminal Variables (Copy to 00_Menu.cpp)
	const short atot=4;
	char a1,a4;
	short i2=0,temp=0,a2,a3,a5,a6;
	short aid[atot]={1001,1002,1003,1004},
		asl[atot]={5,3,6,9}, // Slot Left
		aul[atot]={0,0,0,0}, //  Booking
		are[atot]={0,0,0,0}; // Reservation
	string an[atot]={"Nein-11 Airlines","Mountain Airlines","Trupa Squid Airlines","Awdohnis Airlines"},
		atd[atot]={"07:00AM","09:00AM","11:00AM","01:00PM"},
		ata[atot]={"10:00AM","11:00AM","02:00PM","04:00PM"},
		ad[atot]={"Osama Von Ladon","Kobe Bryant","Ganbu II Nam","Wally Bayola"},
		ald[atot]={"Pasig City","Manila City","Cebu City","Baguio City"},
		ala[atot]={"Quezon City","Davao City","Pasay City","Paradis City"};
	short atemp0,atemp1,atemp2,atemp3;	
			// Airport Show Code
			a4=0;	
			do
			{
				for (short i2b=0;i2b<atot;i2b++)
				{
					cout<<"Airplane #"<<i2b+1
						<<"\nID: "<<aid[i2b]
						<<"\nReservations: "<<are[i2b]
						<<"\nSlot Used: "<<aul[i2b]
						
						<<endl<<endl;
				}
				cout<<"\n[Choose an Option]"
					<<"\n1. Cancel Reservation"
					<<"\n2. Cancel Booked Slot"
					<<"\n3. Exit"
					<<"\n\nChoice: ";
				cin>>a4;
				a5=0;
				if (a4=='1'||a4=='2') 
				{

					do 
					{
						atemp0=aid[0];
						for (short i2b=0;i2b<atot;i2b++) 
							{atemp1=aid[i2b];}
						cout<<"Input the ID no: ";
						cin>>a5;
						if (a5<=atemp0-1||a5>=atemp1+1)
						{
							cout<<"Invalid ID no. ";
							system ("pause");
							system("cls");
						}
					} while (a5<=atemp0-1||a5>=atemp1+1);

					for (short i2b=0;i2b<atot;i2b++)
					if (a5==aid[i2b])
					{
						a5=i2b;
						if (a4=='1')
						{
							a6=1;
							if (are[a5]==0)
							{
								cout<<"You have no reservations. ";
							}
							else
							{
								asl[a5]=asl[a5]+are[a5];
								are[a5]=0;
								cout<<"Reservation Cancelled. ";
							}
						}
						else if (a4=='2')
						{	
							a6=1;
							if (aul[a5]==0)
							{	
								cout<<"You have no booking. ";
							}
							else
							{
								asl[a5]=asl[a5]+aul[a5];
								aul[a5]=0;
								cout<<"Booked Slot Cancelled. ";
							}
						}
					}
				}
				else if (a4=='3') {a6=1;}
				else
				{
					cout<<"Invalid. ";
					system ("pause");
					system("cls");
				}
			}
			while (a6!=1);
}
	
