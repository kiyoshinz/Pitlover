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
	// Hotel Variables (paste 02_Hotel.cpp here)
	const short hot_tot=4;
	short hot_nor[hot_tot]={10,8,5,0},hot_nod,m2,m3,m4,hot_tod,m5,mtemp,m6,
		hot_res2[hot_tot]={0,0,0,0},
		i3;
	string hot_size[hot_tot]={"Small Room","Medium Room","Large Room","VIP Room"};
	char hot_res='0'; // Don't change values
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
			do
	{
		// Start of Menu Airport
		cout<<mal_airport<<endl
			<<"\n[Choose an Option]"
			<<"\n1. Slot Booking"
			<<"\n2. Reservation"
			<<"\n3. Show / Cancellation"
			<<"\n4. View Airplanes Available"
			<<"\n5. Exit"
			<<"\n\nChoice: ";
		cin>> a1;
		cout<<endl;
		system("cls");
		if (a1=='1')
		{	
			// Airpot Booking Code
			short atemp0=atot;
			do 
			{
				atemp0=aid[0];
				for (short i2b=0;i2b<atot;i2b++) 
					{atemp1=aid[i2b];}
				cout<<"Input the ID no: ";
				cin>>a2;
				if (a2<=atemp0-1||a2>=atemp1+1)
				{
					cout<<"Invalid ID no. ";
					system ("pause");
					system("cls");
				}
			}
			while (a2<=atemp0-1||a2>=atemp1+1);
			for (short i2b=0;i2b<atot;i2b++)
			if (a2==aid[i2b])
				{a2=i2b;}
			do 
			{
				atemp2=0;
				system("cls");
				cout<<"Airplane #"<<a2+1
					<<"\nID: "<<aid[a2]
					<<"\nAirplane: "<<an[a2]
					<<"\nPilot: "<<ad[a2]
					<<"\nTime Departure: "<<atd[a2]
					<<"\nTime Arrival: "<<ata[a2]
					<<"\nComing From: "<<ald[a2]
					<<"\nDestination: "<<ala[a2]
					<<"\nAvailable Slot: "<<asl[a2]
					<<endl<<endl;
				if (asl[a2]==0)
				{
					cout<<"No more available tickets. ";
					system("pause");
					system("cls");
					atemp2=1;
				}
				else
				{
					cout<<"Input the number of slot: ";
					cin>>a3;
					if (a3>=asl[a2]+1||a3<=0)
					{
						cout<<"Please enter a valid amount. ";
						system("pause");
					}
					else 
					{
						atemp2=1;
						aul[a2]=aul[a2]+a3;
						asl[a2]=asl[a2]-a3;
						cout<<"Booking Successful. ";
						system("pause");
					}
				}
			}
			while (atemp2!=1);
			system("cls");
		}	
		else if (a1=='2') 
		{		
			// Airport Reservation Code
			atemp0=atot;
			do 
			{
				atemp0=aid[0];
				for (short i2b=0;i2b<atot;i2b++) 
					{atemp1=aid[i2b];}
				cout<<"Input the ID no: ";
				cin>>a2;
				if (a2<=atemp0-1||a2>=atemp1+1)
				{
					cout<<"Invalid ID no. ";
					system ("pause");
					system("cls");
				}
			}
			while (a2<=atemp0-1||a2>=atemp1+1);
			for (short i2b=0;i2b<atot;i2b++)
			if (a2==aid[i2b])
				{a2=i2b;}
			do 
			{
				atemp2=0;
				system("cls");
				cout<<"Airplane #"<<a2+1
					<<"\nID: "<<aid[a2]
					<<"\nAirplane: "<<an[a2]
					<<"\nPilot: "<<ad[a2]
					<<"\nTime Departure: "<<atd[a2]
					<<"\nTime Arrival: "<<ata[a2]
					<<"\nComing From: "<<ald[a2]
					<<"\nDestination: "<<ala[a2]
					<<"\nAvailable Slot: "<<asl[a2]
					<<endl<<endl;
				if (asl[a2]==0)
				{
					cout<<"No more available tickets. ";
					system("pause");
					system("cls");
					atemp2=1;
				}
				else
				{
					cout<<"Input the number of slot: ";
					cin>>a3;
					if (a3>=asl[a2]+1||a3<=0)
					{
						cout<<"Please enter a valid amount. ";
						system("pause");
					}
					else 
					{
						atemp2=1;
						are[a2]=are[a2]+a3;
						asl[a2]=asl[a2]-a3;
						cout<<"Reservation Successful. ";
						system("pause");
					}		
				}
			}
			while (atemp2!=1);
			system("cls");
		}	
		else if (a1=='3') 
		{	
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
			system("pause");
			system("cls");
		}
		else if (a1=='4') 
		{	
			// Airplanes available code	
			for (short i2b=0;i2b<atot;i2b++)
			{
				cout<<"Airplane #"<<i2b+1
					<<"\nID: "<<aid[i2b]
					<<"\nAirplane: "<<an[i2b]
					<<"\nPilot: "<<ad[i2b]
					<<"\nTime Departure: "<<atd[i2b]
					<<"\nTime Arrival: "<<ata[i2b]
					<<"\nComing From: "<<ald[i2b]
					<<"\nDestination: "<<ala[i2b]
					<<"\nAvailable Slot: "<<asl[i2b]
					<<endl<<endl;
			}
			system("pause");
			system("cls");
		}
		else if (a1=='5')
		{	
			i2=1;	
			cout<<"Thank you for choosing "<<mal_company<<"'s Airport Services, Goodbye.";
		}
		else
		{
			cout<<"Invalid. ";
			system ("pause");
			system("cls");
		}
	}
	while (i2!=1);
		}	
		else if (m1=='2') 
		{	
			i1=1;	
			do {
		// Start of Menu Hotel
		cout<<mal_hotel<<endl
			<<endl<<"[Choose an Option]"
			<<endl<<"1. Slot Booking"
			<<endl<<"2. Reservation"
			<<endl<<"3. Show / Cancellation"
			<<endl<<"4. View Rooms Available"
			<<endl<<"5. Exit"
			<<endl<<endl<<"Choice: ";
		cin>> m1;
		cout<<endl;
		system("cls");
		if (m1=='1') {	
			if (hot_res=='1') {
				cout<<"You're already booked/reserved. ";
			}
			else {
				do {
					cout<<"[Choose an option]";
					for (int i=0;i<hot_tot;i++) {
						cout<<endl<<i+1<<". "<<hot_size[i];
						m2=i;
					}
					cout<<endl<<m2+2<<". Exit"
						<<endl<<endl<<"Room Size: ";
					cin>>m3;
					if (hot_nor[m3-1]!=0) {
						if (m3<=m2+1&&m3>=1) {
							system("cls");
							do {
								cout<<"[Choose an option]"
									<<endl<<"Room Size: "<<hot_size[m3-1]
									<<endl<<"Number of Days: ";
								cin>>hot_nod;
								cout<<endl<<"1. Morning"
									<<endl<<"2. Evening"
									<<endl<<"3. Afternoon"
									<<endl<<endl<<"Time of Day: ";
								cin>>hot_tod;
								if (hot_tod<=3&&hot_tod>=1) {
									cout<<"Success. ";
									hot_nor[m3-1]=hot_nor[m3-1]-1;
									hot_res='1';
									hot_res2[m3-1]=1;
									m4=1;
									m5=1;
								}
								else if (m3==4) {
									m5=1;
									system("cls");
								}
								else {
									cout<<"Invalid. ";
									system ("pause");
									system("cls");
								}
							} while (m5!=1);
						}
						else if (m3==m2+2) {
							m4=1;
						}
						else {
							cout<<"Invalid. ";
							system ("pause");
							system("cls");
						}
					}
					else {
						cout<<"Sorry all slots are full. Choose a different room. ";
						system("pause");
						system("cls");
					}
				} while (m4!=1);
			}	
		}	
		else if (m1=='2') {
				if (hot_res=='1') {
				cout<<"You're already booked/reserved. ";
			}
			else {
				do {
					cout<<"[Choose an option]";
					for (int i=0;i<hot_tot;i++) {
						cout<<endl<<i+1<<". "<<hot_size[i];
						m2=i;
					}
					cout<<endl<<m2+2<<". Exit"
						<<endl<<endl<<"Room Size: ";
					cin>>m3;
					if (hot_nor[m3-1]!=0) {
						if (m3<=m2+1&&m3>=1) {
							system("cls");
							do {
								cout<<"[Choose an option]"
									<<endl<<"Room Size: "<<hot_size[m3-1]
									<<endl<<"Number of Days: ";
								cin>>hot_nod;
								cout<<endl<<"1. Morning"
									<<endl<<"2. Evening"
									<<endl<<"3. Afternoon"
									<<endl<<endl<<"Time of Day: ";
								cin>>hot_tod;
								if (hot_tod<=3&&hot_tod>=1) {
									cout<<"Success. ";
									hot_nor[m3-1]=hot_nor[m3-1]-1;
									hot_res='1';
									hot_res2[m3-1]=1;
									m4=1;
									m5=1;
								}
								else if (m3==4) {
									m5=1;
									system("cls");
								}
								else {
									cout<<"Invalid. ";
									system ("pause");
									system("cls");
								}
							} while (m5!=1);
						}
						else if (m3==m2+2) {
							m4=1;
						}
						else {
							cout<<"Invalid. ";
							system ("pause");
							system("cls");
						}
					}
					else {
						cout<<"Sorry all slots are full. Choose a different room. ";
						system("pause");
						system("cls");
					}
				} while (m4!=1);
			}	
		}	
		else if (m1=='3') {
			if (hot_res=='0') {
				cout<<"No active booking/reservation. ";
			}
			else {
				for (int i=0;i<hot_tot;i++) {
					if (hot_res2[i]==1) m3=i;
				}
				do {
					cout<<"Room Size: "<<hot_size[m3]
						<<endl<<"Number of Days: "<<hot_nod
						<<endl<<"Time of Day: ";
					
					if (hot_tod==1) {
						cout<<"Morning";
					}
					else if (hot_tod==2) {
						cout<<"Evening";
					}
					else if (hot_tod==3) {
						cout<<"Afternoon";
					}
					cout<<endl<<endl<<"Cancel Booking/Reservation?"
						<<endl<<"1. Yes"
						<<endl<<"2. No"
						<<endl<<endl<<"Choice: ";
					cin>>hot_res;
					if (hot_res=='1') {
						cout<<endl<<"Booking/Reservation Cancelled. ";
						hot_res='0';
						hot_nor[m3]=hot_nor[m3]+1;
						hot_res2[m3]=0;
						m6=1;
					}
					else if (hot_res=='2') {
						cout<<endl<<"Transaction Cancelled. ";
						m6=1;
					}
					else 
						{cout<<"Invalid. ";}
				} while (m6!=1);
			}
		}
		else if (m1=='4') {	
		for (int i=0;i<hot_tot;i++) {
			cout<<"Room Size: "<<hot_size[i]
				<<endl<<"Slot Left: "<<hot_nor[i]<<endl;
			}
		}
		else if (m1=='5') {	
			i3=1;	
			cout<<"Thank you for choosing "<<mal_company<<"'s Hotel Services, Goodbye.";
		}
		else {
			cout<<"Invalid. ";
		}
		system ("pause");
		system("cls");
	}
	while (i3!=1);
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
