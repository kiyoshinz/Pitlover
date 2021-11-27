#include <iostream>
using namespace std;

int main () {
	// Shared (no need to copy)
	string mal_company="Pitlover Corporation Group",
		mal_hotel="Pitlover Hotel",
		mal_airport="Pitlover Airport Terminal",
		mal_bus="Pitlover Bus Terminal";
	char m1;
	short i1;
	// Hotel Variables (Copy to 00_Menu.cpp)
	const short hot_tot=4;
	short hot_nor[hot_tot]={10,8,5,0},hot_nod,m2,m3,m4,hot_tod,m5,mtemp,m6,
		hot_res2[hot_tot]={0,0,0,0},
		i3;
	string hot_size[hot_tot]={"Small Room","Medium Room","Large Room","VIP Room"};
	char hot_res='0'; // Don't change values
	// Hotel Code (Copy to 00_Menu.cpp)
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
