#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<deque>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<time.h>



#define MAX_SIZE 100

using namespace std;

//vehicle menu variables
deque<int> vehicleID,driverID;
deque<float> rate;
deque<string> plateNumber, vehicleType, model;

//driver menu variables
deque<int> keyDriverID;
deque<string> fName, mName, lName, licNumber;

//rental men variables
deque<int> rVID, rDID, puMonth, puDay, puYear, puHour, puMin, doMonth, doDay, doYear, doHour, doMin;
deque<string> cFName, cMName, cLName, cNum, sAddress, city;

//general variables
int choice, tempint, tempID;
char tempstring[50];
float tempfloat;
bool menuLoop;

//functions
int inputInt();
void vehicleMenu();
void driverMenu();
void queueMenu();
template<typename T> void printTable(T type, int width);
template<typename T> void saveDeque(deque<T> mydeque, string filename);
deque<int> loadDequeInt(deque<int> mydeque, string filename);
deque<float> loadDequeFloat(deque<float> mydeque, string filename);
deque<string> loadDequeString(deque<string> mydeque, string filename);
void loadVehicleText();
void saveVehicleText();
void printVehicleTable();
void loadDriverText();
void saveDriverText();
void printDriverTable();
void loadRentalText();
void saveRentalText();
void printRentalTable();
int inputMonth(int month);
int inputDay(int day, int year, int month);
int inputMin(int min);
int inputHour(int hour);
void removeNewLine(char *s);
bool checkDate(int puMonth, int puDay, int puYear, int puHour, int puMin, int doMonth, int doDay, int doYear, int doHour, int doMin);
int datetoInt(int Month, int Day, int Year, int Hour, int Min);
void bubbleSortVehicle();
void bubbleSortDriver();
void bubbleSortRental();


int main() {

	cout << vehicleID.size();
	loadVehicleText();
	loadDriverText();
	loadRentalText();
	menuLoop = true;

	do {
		cout << "Main Menu: " << endl;
		cout << "1. Cab List Menu" << endl;
		cout << "2. Driver List Menu" << endl;
		cout << "3. Queue Menu" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			vehicleMenu();
			break;
		case 2:
			driverMenu();
			break;
		case 3:
			queueMenu();
			break;
		default:
			menuLoop = false;
			break;
		}
	} while (menuLoop == true);
	cout << "Program End...";
	getchar();

	return 0;

}

void vehicleMenu() 
{
	bool vMenuLoop = true, idstatus1 = false, idstatus2 = false,noAvailDriver = false;
	do {
		int tempVID, tempDID;
		float tempRate;
		char tempPNum[20], tempVType[20], tempModel[20];

		cout << "\nVehicle Menu Options:" << endl;
		cout << "1. View List" << endl << "2. Add to List" << endl << "3. Remove from List" << endl << "4. Modify" << endl << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			loadVehicleText();
			bubbleSortVehicle();
			printVehicleTable();
			break;
		case 2:
			loadVehicleText();
			cout << "Enter Vehicle ID: ";
			cin >> tempVID;
			do {
				idstatus1 = false;
				for (unsigned int x = 0; x < vehicleID.size(); x++)
				{
					if(tempVID == vehicleID.at(x))
						tempint = vehicleID.at(x);
				}
				if (tempint == tempVID)
				{
					cout << "Vehicle ID already exist please enter a new id: ";
					cin >> tempVID;
				}
				else
					idstatus1 = true;
			} while (idstatus1 == false);
			cin.ignore();

			cout << "Enter Plate number: ";
			cin.getline(tempPNum, 20);

			cout << "Enter Model: ";
			cin.getline(tempModel, 20);

			cout << "Enter Vehicle Type: " << endl;
			cout << "1. Small" << endl << "2.  Mid size" << endl << "3. Large" << endl;
			cout << "Enter you choice: ";
			do {
				menuLoop = true;
				cin >> tempint;
				switch (tempint)
				{
				case 1:
					strcpy(tempVType, "Small");
					menuLoop = false;
					break;
				case 2:
					strcpy(tempVType, "Mid-size");
					menuLoop = false;
					break;
				case 3:
					strcpy(tempVType, "Large");
					menuLoop = false;
					break;
				default:
					cout << "Invalid Input. Please pick from the choices: ";
					break;
				}
			} while (menuLoop == true);

			if (keyDriverID.size() == 0) 
			{
				cout << "Driver ID List is empty. Exiting add to list option. Please update driver list." << endl;
				break;
			}
			printDriverTable();
			cout << "Enter Driver ID: ";
			cin >> tempDID;
			do {
				idstatus1 = false;
				for (unsigned int x = 0; x < keyDriverID.size(); x++)
				{
					if (keyDriverID.size() == driverID.size())
					{
						idstatus1 = true;
					}
					else if (tempDID == keyDriverID.at(x))
					{
						idstatus1 = true;
					}
				}
				if (idstatus1 == false)
				{
					cout << "Driver ID does not exist please enter an existing id: ";
					cin >> tempDID;
				}
				do {
					idstatus2 = false;
					for (unsigned int x = 0; x < vehicleID.size(); x++)
					{
						if (tempDID == driverID.at(x))
							tempint = driverID.at(x);
					}
					if (keyDriverID.size() == driverID.size())
					{
						idstatus2 = true;
						cout << "No available driver";
						noAvailDriver = true;
					}
					else if (tempint == tempDID)
					{
						idstatus1 = false;
						cout << "Driver ID already assigned please enter another id: ";
						cin >> tempDID;
					}
					else
						idstatus2 = true;
				} while (idstatus2 == false);
			} while (idstatus1 == false || idstatus2 == false);
			if (noAvailDriver == true) 
			{
				break;
			}
			cin.ignore();

			cout << "Enter rate per hour: ";
			cin >> tempRate;

			//Adds items to deques
			vehicleID.push_back(tempVID);
			plateNumber.push_back(tempPNum);
			model.push_back(tempModel);
			vehicleType.push_back(tempVType);
			driverID.push_back(tempDID);
			rate.push_back(tempRate);

			bubbleSortVehicle();

			//Saves Deques to txtfile
			saveVehicleText();
			
			printVehicleTable();
			break;
		case 3:
			loadVehicleText();
			printVehicleTable();

			cout << "Enter Vehicle ID you wish to delete: ";
			tempID = 0;
			cin >> tempID;
			for (unsigned int x = 0; x < vehicleID.size(); x++)
			{
				if (vehicleID.at(x) == tempID)
				{
					vehicleID.erase(vehicleID.begin() + x);
					plateNumber.erase(plateNumber.begin() + x);
					model.erase(model.begin() + x);
					vehicleType.erase(vehicleType.begin() + x);
					driverID.erase(driverID.begin() + x);
					rate.erase(rate.begin() + x);
				}
			}

			bubbleSortVehicle();

			//Saves Deques to txtfile
			saveVehicleText();

			break;
		case 4:
			printVehicleTable();
			cout << "Enter Vehicle ID to modify: ";
			tempID = 0;
			cin >> tempID;
			for (unsigned int x = 0; x < vehicleID.size(); x++)
			{
				if (vehicleID.at(x) == tempID)
				{
					cout << "Choose field to modify: " << endl;
					cout << "1. Model" << endl << "2. Vehicle Type" << endl << "3. Driver ID" << endl << "4. Vehicle Type" << endl << "5. Rate" << endl;
					cout << "Enter your choice:";
					cin >> tempint;
					cin.ignore();
					switch (tempint)
					{
					case 1:
						cout << "Enter new Model:";
						cin.getline(tempstring, 20);
						model.at(x) = tempstring;
						break;
					case 2:
						cout << "Enter new Vehicle Type:";
						cin.getline(tempstring, 20);
						vehicleType.at(x) = tempstring;
						break;
					case 3:
						printDriverTable();
						cout << "Enter new Driver ID:";
						cin >> tempDID;
						do {
							idstatus1 = false;
							for (unsigned int x = 0; x < keyDriverID.size(); x++)
							{
								if (tempDID == keyDriverID.at(x))
								{
									idstatus1 = true;
								}
							}
							if (idstatus1 == false)
							{
								cout << "Driver ID does not exist please enter an existing id: ";
								cin >> tempDID;
							}
							do {
								idstatus2 = false;
								for (unsigned int x = 0; x < vehicleID.size(); x++)
								{
									if (tempDID == driverID.at(x))
										tempint = driverID.at(x);
								}
								if (tempID == tempDID)
								{
								idstatus1 = true;
								idstatus2 = true;
								cout << "Using current driver ID.";
								}
								else if (tempint == tempDID)
								{
									idstatus1 = false;
									cout << "Driver ID already assigned please enter another id: ";
									cin >> tempDID;
								}
								
								else
									idstatus2 = true;
							} while (idstatus2 == false);
						} while (idstatus1 == false || idstatus2 == false);
						driverID.at(x) = tempDID;
						break;
					case 4:
						cout << "Enter new Vehicle Type:";
						cin.getline(tempstring, 20);
						vehicleType.at(x) = tempstring;
						break;
					case 5:
						cout << "Enter new Rate per hour:";
						cin >> tempfloat;
						rate.at(x) = tempfloat;
						break;
					default:
						break;
					}
				}
			}

			bubbleSortVehicle();

			//Saves Deques to txtfile
			saveVehicleText();
			break;
		case 5:
			vMenuLoop = false;
			break;
		default:
			break;
		}
	}while (vMenuLoop == true);
	cout << endl;
}

void driverMenu(){
	bool dMenuLoop = true, idstatus = false;
	do {
		int tempDID;
		char tempFName[20], tempMName[20], tempLName[20], tempLicNum[20];

		cout << "\nDriver Menu Options:" << endl;
		cout << "1. View List" << endl << "2. Add to List" << endl << "3. Remove from List" << endl << "4. Modify" << endl << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			loadDriverText();
			bubbleSortDriver();
			printDriverTable();
			break;
		case 2:
			loadDriverText();
			cout << "Enter Driver ID: ";
			cin >> tempDID;
			do {
				idstatus = false;
				for (unsigned int x = 0; x < keyDriverID.size(); x++)
				{
					if (tempDID == keyDriverID.at(x))
						tempint = keyDriverID.at(x);
				}
				if (tempint == tempDID)
				{
					cout << "Driver ID already exist please enter a new id: ";
					cin >> tempDID;
				}
				else
					idstatus = true;
			} while (idstatus == false);
			cin.ignore();

			cout << "Enter First Name: ";
			cin.getline(tempFName, 20);

			cout << "Enter Middle Name: ";
			cin.getline(tempMName, 20);

			cout << "Enter Last Name: ";
			cin.getline(tempLName, 20);

			cout << "Enter License Number: ";
			cin.getline(tempLicNum, 20);

			keyDriverID.push_back(tempDID);
			fName.push_back(tempFName);
			mName.push_back(tempMName);
			lName.push_back(tempLName);
			licNumber.push_back(tempLicNum);
			
			bubbleSortDriver();

			//Saves Deques to txtfile
			saveDriverText();

			printDriverTable();

			break;
		case 3:
			loadDriverText();
			printDriverTable();

			cout << "Enter Driver ID you wish to delete: ";
			tempID = 0;
			cin >> tempID;
			for (unsigned int x = 0; x < keyDriverID.size(); x++)
			{
				if (keyDriverID.at(x) == tempID)
				{
					keyDriverID.erase(keyDriverID.begin() + x);
					fName.erase(fName.begin() + x);
					mName.erase(mName.begin() + x);
					lName.erase(lName.begin() + x);
					licNumber.erase(licNumber.begin() + x);
				}
			}

			bubbleSortDriver();

			//Saves Deques to txtfile
			saveDriverText();

			break;
		case 4:
			cout << "Enter Driver ID to modify: ";
			tempID = 0;
			cin >> tempID;
			for (unsigned int x = 0; x < keyDriverID.size(); x++)
			{
				if (keyDriverID.at(x) == tempID)
				{
					cout << "Choose field to modify: " << endl;
					cout << "1. First Name" << endl << "2. Middle Name" << endl << "3. Last Name" << endl << "4. License Number" << endl;
					cout << "Enter your choice:";
					cin >> tempint;
					cin.ignore();
					switch (tempint)
					{
					case 1:
						cout << "Enter First Name:";
						cin.getline(tempstring, 20);
						fName.at(x) = tempstring;
						break;
					case 2:
						cout << "Enter Middle Name";
						cin.getline(tempstring, 20);
						mName.at(x) = tempstring;
						break;
					case 3:
						cout << "Enter Last Name";
						cin.getline(tempstring, 20);
						lName.at(x) = tempstring;
						break;
					case 4:
						cout << "Enter License Number:";
						cin.getline(tempstring, 20);
						licNumber.at(x) = tempstring;
						break;
					default:
						break;
					}
				}
			}

			bubbleSortDriver();

			//Saves Deques to txtfile
			saveDriverText();
			break;
		case 5:
			dMenuLoop = false;
			break;
		default:
			break;
		}
	}while (dMenuLoop == true);
	cout << endl;
}

void queueMenu()
{
	bool rMenuLoop = true, idstatus;
	bool chkDate = false;

	int temprVID, temprDID;
	char tempcFName[20], tempcMName[20], tempcLName[20], tempcNum[20], tempsAddress[40], tempcity[20];
	int temppuMonth, temppuDay, temppuYear, temppuHour, temppuMin;
	int tempdoMonth, tempdoDay, tempdoYear, tempdoHour, tempdoMin;
	do 
	{
		cout << "\nRental Menu Options:" << endl;
		cout << "1. View Schedules" << endl << "2. Add Schedule" << endl << "3. Delete Schedule" << endl << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			loadRentalText();
			bubbleSortRental();
			printRentalTable();
			break;
		case 2:
			if (vehicleID.size() == 0)
			{
				cout << "Vehicle ID List is empty. Exiting add to schedule option. Please update vehicle list." << endl;
				break;
			}
			cout << "Enter Vehicle ID: ";
			cin >> temprVID;
			do {
				idstatus = false;
				for (unsigned int x = 0; x < vehicleID.size(); x++)
				{
					if (temprVID == vehicleID.at(x))
					{
						temprDID = driverID.at(x);
						idstatus = true;
					}
				}
				if (idstatus == false)
				{
					cout << "Vehicle ID does not exist please enter an existing id: ";
					cin >> temprVID;
				}
			} while (idstatus == false);


			cout << "Enter customer first name: ";
			cin >> tempcFName;

			cout << "Enter customer middle name: ";
			cin >> tempcMName;

			cout << "Enter customer last name: ";
			cin >> tempcLName;

			cout << "Enter customer contact number: ";
			cin >> tempcNum;
			cin.ignore();

			cout << "Enter pick-up location address: ";
			cin >> tempsAddress;

			cout << "Enter pick-up location city: ";
			cin >> tempcity;

			cout << "Enter pick-up time: " << endl << "Month: ";
			cin >> temppuMonth;
			temppuMonth = inputMonth(temppuMonth);

			cout << "Year: ";
			cin >> temppuYear;

			cout << "Day: ";
			cin >> temppuDay;
			temppuDay = inputDay(temppuDay, temppuYear, temppuMonth);

			cout << "Hour: ";
			cin >> temppuHour;
			temppuHour = inputHour(temppuHour);

			cout << "Min: ";
			cin >> temppuMin;
			temppuMin = inputMin(temppuMin);

			do {
				if (chkDate == false)
				{
					cout << "Enter drop-off time: " << endl << "Month: ";
					cin >> tempdoMonth;
					tempdoMonth = inputMonth(tempdoMonth);

					cout << "Year: ";
					cin >> tempdoYear;

					cout << "Day: ";
					cin >> tempdoDay;
					tempdoDay = inputDay(tempdoDay, tempdoYear, tempdoMonth);

					cout << "Hour: ";
					cin >> tempdoHour;
					tempdoHour = inputHour(tempdoHour);

					cout << "Min: ";
					cin >> tempdoMin;
					tempdoMin = inputMin(tempdoMin);

					chkDate = checkDate(temppuMonth, temppuDay, temppuYear, temppuHour, temppuMin, tempdoMonth, tempdoDay, tempdoYear, tempdoHour, tempdoMin);
					if (chkDate == false)
					{
						cout << "Drop-off date must be greater than pick-up date." << endl;
					}
				}
			} while (chkDate == false);

			//add items to deque
			rVID.push_back(temprVID);
			rDID.push_back(temprDID);
			cFName.push_back(tempcFName);
			cMName.push_back(tempcMName);
			cLName.push_back(tempcLName);
			cNum.push_back(tempcNum);
			sAddress.push_back(tempsAddress);
			city.push_back(tempcity);
			puMonth.push_back(temppuMonth);
			puDay.push_back(temppuDay);
			puYear.push_back(temppuYear);
			puHour.push_back(temppuHour);
			puMin.push_back(temppuMin);
			doMonth.push_back(tempdoMonth);
			doDay.push_back(tempdoDay);
			doYear.push_back(tempdoYear);
			doHour.push_back(tempdoHour);
			doMin.push_back(tempdoMin);

			bubbleSortRental();

			saveRentalText();

			break;
		case 3:
			loadRentalText();
			printRentalTable();

			cout << "Enter queue you wish to delete: ";
			tempint = 0;
			cin >> tempint;
			do {
				if (tempint >= 1 && tempint <= rVID.size())
				{
						rVID.erase(rVID.begin() + (tempint - 1));
						rDID.erase(rDID.begin() + (tempint - 1));
						puMonth.erase(puMonth.begin() + (tempint - 1));
						puDay.erase(puDay.begin() + (tempint - 1));
						puYear.erase(puYear.begin() + (tempint - 1));
						puHour.erase(puHour.begin() + (tempint - 1));
						puMin.erase(puMin.begin() + (tempint - 1));
						doMonth.erase(doMonth.begin() + (tempint - 1));
						doDay.erase(doDay.begin() + (tempint - 1));
						doYear.erase(doYear.begin() + (tempint - 1));
						doHour.erase(doHour.begin() + (tempint - 1));
						doMin.erase(doMin.begin() + (tempint - 1));
						cFName.erase(cFName.begin() + (tempint - 1));
						cMName.erase(cMName.begin() + (tempint - 1));
						cLName.erase(cLName.begin() + (tempint - 1));
						cNum.erase(cNum.begin() + (tempint - 1));
						sAddress.erase(sAddress.begin() + (tempint - 1));
						city.erase(city.begin() + (tempint - 1));
						menuLoop = true;
				}
				else
				{
					cout << " Please enter a valid number: ";
					cin >> tempint;
					menuLoop = false;
				}
			} while (menuLoop == false);
			bubbleSortRental();

			//Saves Deques to txtfile
			saveRentalText();

			break;
		case 4: 
			rMenuLoop = false;
			break;
		default:
			break;
		}
	} while (rMenuLoop == true);
}

template<typename T> void printTable(T type, int width) {
	cout << left << setw(width) << setfill(' ') << type;
}


template<typename T> void saveDeque(deque<T> mydeque,string filename) {
	ofstream outitem(filename,ios::out | ios::trunc);
	for (unsigned int x = 0; x < mydeque.size(); x++)
	{
		if (x < mydeque.size() - 1)
			outitem << mydeque.at(x) << endl;
		else
			outitem << mydeque.at(x);
	}
	outitem.close();
}

deque<int> loadDequeInt(deque<int> mydeque, string filename) {
	ifstream initem;
	initem.clear();
	initem.open(filename,ios::in);
	initem.seekg(0, ios::beg);
	int item;
		if(initem.is_open())
			while (initem.good())
			{
				if (!initem.eof())
				{
					initem >> item;
					mydeque.push_back(item);
				}
			}
		initem.close();
		
	return mydeque;
}



deque<float> loadDequeFloat(deque<float> mydeque, string filename) {
	ifstream initem;
	initem.clear();
	initem.open(filename,ios::in);
	initem.seekg(0, ios::beg);
	float item;
	if (initem.is_open())
		while (initem.good())
		{
			if (!initem.eof())
			{
				initem >> item;
				mydeque.push_back(item);
			}
		}
	initem.close();

	return mydeque;
}

deque<string> loadDequeString(deque<string> mydeque, string filename) {
	ifstream initem;
	initem.clear();
	initem.open(filename,ios::in);
	initem.seekg(0, ios::beg);
	string item;
	if (initem.is_open())
		while (initem.good())
		{
			if (!initem.eof())
			{
				initem >> item;
				mydeque.push_back(item);
			}
		}
	initem.close();

	return mydeque;
}


void loadVehicleText() {
	//empty deques
	vehicleID = deque<int>();
	driverID = deque<int>();
	rate = deque<float>();
	plateNumber = deque<string>();
	vehicleType = deque<string>();
	model = deque<string>();

	//Load deques from txtfile
	vehicleID = loadDequeInt(vehicleID, ".\\TextFiles\\vehicleID.txt");
	plateNumber = loadDequeString(plateNumber, ".\\TextFiles\\plateNumber.txt");
	model = loadDequeString(model, ".\\TextFiles\\model.txt");
	vehicleType = loadDequeString(vehicleType, ".\\TextFiles\\vehicleType.txt");
	driverID = loadDequeInt(driverID, ".\\TextFiles\\driverID.txt");
	rate = loadDequeFloat(rate, ".\\TextFiles\\rate.txt");
}

void saveVehicleText() {
	saveDeque(vehicleID, ".\\TextFiles\\vehicleID.txt");
	saveDeque(plateNumber, ".\\TextFiles\\plateNumber.txt");
	saveDeque(model, ".\\TextFiles\\model.txt");
	saveDeque(vehicleType, ".\\TextFiles\\vehicleType.txt");
	saveDeque(driverID, ".\\TextFiles\\driverID.txt");
	saveDeque(rate, ".\\TextFiles\\rate.txt");
}

void printVehicleTable() {
	printTable("Vehicle ID", 15);
	printTable("Plate Number", 15);
	printTable("Model", 15);
	printTable("Vehicle Type", 15);
	printTable("Driver ID", 15);
	printTable("Rate per Hour", 15);
	cout << endl;
	if (vehicleID.size() >= 1)
		for (unsigned int x = 0; x < vehicleID.size(); x++)
		{
			printTable(vehicleID.at(x), 15);
			printTable(plateNumber.at(x), 15);
			printTable(model.at(x), 15);
			printTable(vehicleType.at(x), 15);
			printTable(driverID.at(x), 15);
			printTable(rate.at(x),0); cout << " PHP";
			cout << endl;
		}
	else
	{
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		cout << endl << endl;
	}
}

void loadDriverText() {
	//empty deques
	keyDriverID = deque<int>();
	fName = deque<string>();
	mName = deque<string>();
	lName = deque<string>();
	licNumber = deque<string>();

	//Load deques from txtfile
	keyDriverID = loadDequeInt(keyDriverID, ".\\TextFiles\\keyDriverID.txt");
	fName = loadDequeString(fName, ".\\TextFiles\\firstName.txt");
	mName = loadDequeString(mName, ".\\TextFiles\\middleName.txt");
	lName = loadDequeString(lName, ".\\TextFiles\\lastName.txt");
	licNumber = loadDequeString(licNumber, ".\\TextFiles\\licNumber.txt");
}

void saveDriverText()
{
	saveDeque(keyDriverID, ".\\TextFiles\\keyDriverID.txt");
	saveDeque(fName, ".\\TextFiles\\firstName.txt");
	saveDeque(mName, ".\\TextFiles\\middleName.txt");
	saveDeque(lName, ".\\TextFiles\\lastName.txt");
	saveDeque(licNumber, ".\\TextFiles\\licNumber.txt");
}

void printDriverTable() 
{
	printTable("Driver ID", 15);
	printTable("First Name", 15);
	printTable("Middle Name", 15);
	printTable("Last Name", 15);
	printTable("Lic. Number", 15);
	cout << endl;
	if (keyDriverID.size() >= 1)
		for (unsigned int x = 0; x<keyDriverID.size(); x++)
		{
			printTable(keyDriverID.at(x), 15);
			printTable(fName.at(x), 15);
			printTable(mName.at(x), 15);
			printTable(lName.at(x), 15);
			printTable(licNumber.at(x), 15);
			cout << endl;
		}
	else
	{
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		printTable("Empty", 15);
		cout << endl << endl;
	}
}

void loadRentalText()
{
	//empty deques
	rVID = deque<int>();
	rDID = deque<int>();
	cFName = deque<string>();
	cMName = deque<string>();
	cLName = deque<string>();
	cNum = deque<string>();
	sAddress = deque<string>();
	city = deque<string>();
	puMonth = deque<int>();
	puDay = deque<int>();
	puYear = deque<int>();
	puHour = deque<int>();
	puMin = deque<int>();
	doMonth = deque<int>();
	doDay = deque<int>();
	doYear = deque<int>();
	doHour = deque<int>();
	doMin = deque<int>();

	//Load deques from txtFile
	rVID = loadDequeInt(rVID, ".\\TextFiles\\rentalVID.txt");
	rDID = loadDequeInt(rDID, ".\\TextFiles\\rentalDID.txt");
	cFName = loadDequeString(cFName, ".\\TextFiles\\cFName.txt");
	cMName = loadDequeString(cMName, ".\\TextFiles\\cMName.txt");
	cLName = loadDequeString(cLName, ".\\TextFiles\\cLName.txt");
	cNum = loadDequeString(cNum, ".\\TextFiles\\cNum.txt");
	sAddress = loadDequeString(sAddress, ".\\TextFiles\\sAddress.txt");
	city = loadDequeString(city, ".\\TextFiles\\city.txt");
	puMonth = loadDequeInt(puMonth, ".\\TextFiles\\PuMonth.txt");
	puDay = loadDequeInt(puDay, ".\\TextFiles\\PuDay.txt");
	puYear = loadDequeInt(puYear, ".\\TextFiles\\PuYear.txt");
	puHour = loadDequeInt(puHour, ".\\TextFiles\\PuHour.txt");
	puMin = loadDequeInt(puMin, ".\\TextFiles\\PuMin.txt");
	doMonth = loadDequeInt(doMonth, ".\\TextFiles\\DoMonth.txt");
	doDay = loadDequeInt(doDay, ".\\TextFiles\\DoDay.txt");
	doYear = loadDequeInt(doYear, ".\\TextFiles\\DoYear.txt");
	doHour = loadDequeInt(doHour, ".\\TextFiles\\DoHour.txt");
	doMin = loadDequeInt(doMin, ".\\TextFiles\\DoMin.txt");
}

void saveRentalText()
{
	saveDeque(rVID, ".\\TextFiles\\rentalVID.txt");
	saveDeque(rDID, ".\\TextFiles\\rentalDID.txt");
	saveDeque(cFName, ".\\TextFiles\\cFName.txt");
	saveDeque(cMName, ".\\TextFiles\\cMName.txt");
	saveDeque(cLName, ".\\TextFiles\\cLName.txt");
	saveDeque(cNum, ".\\TextFiles\\cNum.txt");
	saveDeque(sAddress, ".\\TextFiles\\sAddress.txt");
	saveDeque(city, ".\\TextFiles\\city.txt");
	saveDeque(puMonth, ".\\TextFiles\\PuMonth.txt");
	saveDeque(puDay, ".\\TextFiles\\PuDay.txt");
	saveDeque(puYear, ".\\TextFiles\\PuYear.txt");
	saveDeque(puHour, ".\\TextFiles\\PuHour.txt");
	saveDeque(puMin, ".\\TextFiles\\PuMin.txt");
	saveDeque(doMonth, ".\\TextFiles\\DoMonth.txt");
	saveDeque(doDay, ".\\TextFiles\\DoDay.txt");
	saveDeque(doYear, ".\\TextFiles\\DoYear.txt");
	saveDeque(doHour, ".\\TextFiles\\DoHour.txt");
	saveDeque(doMin, ".\\TextFiles\\DoMin.txt");
}

void printRentalTable()
{
	int space = 15;
	double difference;
	printTable("Queue Number", space);
	printTable("Vehicle ID", space);
	printTable("Driver ID", space);
	printTable("Customer", space*2);
	printTable("C. Contact", space);
	printTable("Pick-up Loc.", space+20);
	printTable("Pick-up Time", space+15);
	printTable("Drop-off Time", space+15);
	printTable("Total", space);
	cout << endl;
	if (rVID.size() >= 1)
		for (unsigned int x = 0; x<rVID.size(); x++)
		{
			printTable(x+1, space);
			printTable(rVID.at(x), space);
			printTable(rDID.at(x), space);
			printTable(cFName.at(x)+"_"+cMName.at(x)+"_" +cLName.at(x), space*2);
			printTable(cNum.at(x), space);
			printTable(sAddress.at(x)+"_"+city.at(x), space+20);
			struct tm PU = { 0,puMin.at(x),puHour.at(x),puDay.at(x),puMonth.at(x) - 1,puYear.at(x) - 1900 };
			struct tm DO = { 0,doMin.at(x),doHour.at(x),doDay.at(x),doMonth.at(x) - 1,doYear.at(x) - 1900 };
			time_t tPU = mktime(&PU);
			time_t tDO = mktime(&DO);
			if (tPU != (time_t)(-1) && tDO != (time_t)(-1))
			{
				difference = difftime(tDO, tPU) / (60 * 60 * 24);
				
				char str1[26],str2[26];
				strcpy(str1,ctime(&tPU));
				removeNewLine(str1);
				cout << left << setw(space + 15) << setfill(' ') << str1;
				strcpy(str2,ctime(&tDO));
				removeNewLine(str2);
				cout << left << setw(space + 15) << setfill(' ') << str2;

				for (unsigned int y = 0; y < vehicleID.size(); y++)
				{
					if (rVID.at(x) == vehicleID.at(y))
					{
						printTable(difference * 24 * rate.at(y), 0); cout << " PHP";
					}
				}
			}
			cout << endl;
		}
	else
	{
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		printTable("Empty", space);
		cout << endl << endl;
	}
}

int inputInt() {
	if (!(cin >> tempint))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << " Invalid input. Please Enter an Integer: ";
		inputInt();
	}
	return tempint;
}

int inputMonth(int month)
{
	if (month < 1 || month >12)
	{
		cout << "Invalid input. Month range 1~12" << endl;
		cout << "Enter valid month range: ";
		cin >> month;
		inputMonth(month);
	}
	else
	{
		return month;
	}
	return 0;
}

int inputDay(int day, int year, int month) {
	if (year % 4 != 0)//common year
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cout << "Invalid input. Day range 1~31" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cout << "Invalid input. Day range 1~30" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else
			if (day < 1 || day >28)
			{
				cout << "Invalid input. Day range 1~28" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
	}
	else if (year % 100 != 0)//leap year
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cout << "Invalid input. Day range 1~31" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cout << "Invalid input. Day range 1~30" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else
			if (day < 1 || day >29)
			{
				cout << "Invalid input. Day range 1~29" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
	}
	else if (year % 400 != 0)//common year
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cout << "Invalid input. Day range 1~31" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cout << "Invalid input. Day range 1~30" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else
			if (day < 1 || day >28)
			{
				cout << "Invalid input. Day range 1~28" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
	}
	else//leap year
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cout << "Invalid input. Day range 1~31" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cout << "Invalid input. Day range 1~30" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
		}
		else
			if (day < 1 || day >29)
			{
				cout << "Invalid input. Day range 1~29" << endl;
				cout << "Enter valid day range: ";
				cin >> day;
				inputDay(day, year, month);
			}
			else
			{
				return day;
			}
	}
	return 0;
}

int inputHour(int hour)
{
	if (hour < 1 || hour >24)
	{
		cout << "Invalid input. Hour range 1~24" << endl;
		cout << "Enter valid hour range: ";
		cin >> hour;
		inputMonth(hour);
	}
	else
	{
		return hour;
	}
	return 0;
}

int inputMin(int min)
{
	if (min < 0 || min > 59)
	{
		cout << "Invalid input. Minute range 0~59" << endl;
		cout << "Enter valid minute range: ";
		cin >> min;
		inputMonth(min);
	}
	else
	{
		return min;
	}
	return 0;
}

void removeNewLine(char* s)
{
	s[strcspn(s, "\n")] = '\0';
}

bool checkDate(int puMonth, int puDay, int puYear,int puHour,int puMin, int doMonth, int doDay, int doYear, int doHour, int doMin) 
{
	int puWeight, doWeight;
	puWeight = puYear * 1000000 + puMonth * 10000 + puDay * 100 + puHour*10 + puMin;
	doWeight = doYear * 1000000 + doMonth * 10000 + doDay * 100 + doHour*10 + doMin;

	return doWeight > puWeight;
}

int datetoInt(int Month, int Day, int Year, int Hour, int Min)
{
	int weight;
	weight = Year * 1000000 + Month * 10000 + Day * 100 + Hour * 10 + Min;
	return weight;
}

void bubbleSortVehicle()
{
	int tempVID, tempDID;
	float tempRate;
	string tempPN, tempVT, tempModel;

	for (unsigned int i = 1; i < vehicleID.size(); i++)
	{
		for (unsigned int j = 0; j < vehicleID.size()-1; j++)
		{
			if (vehicleID.at(j) > vehicleID.at(j + 1))
			{
				tempVID = vehicleID.at(j);
				vehicleID.at(j) = vehicleID.at(j + 1);
				vehicleID.at(j + 1) = tempVID;

				tempDID = driverID.at(j);
				driverID.at(j) = driverID.at(j + 1);
				driverID.at(j + 1) = tempDID;

				tempRate = rate.at(j);
				rate.at(j) = rate.at(j + 1);
				rate.at(j + 1) = tempRate;

				tempPN = plateNumber.at(j);
				plateNumber.at(j) = plateNumber.at(j + 1);
				plateNumber.at(j + 1) = tempPN;

				tempVT = vehicleType.at(j);
				vehicleType.at(j) = vehicleType.at(j + 1);
				vehicleType.at(j + 1) = tempVT;

				tempModel = model.at(j);
				model.at(j) = model.at(j + 1);
				model.at(j + 1) = tempModel;
			}
		}
	}
}

void bubbleSortDriver() 
{
	int tempDID;
	string tempFName, tempMName, tempLName, tempLNum;

	for (unsigned int i = 1; i < keyDriverID.size(); i++)
	{
		for (unsigned int j = 0; j < keyDriverID.size() - 1; j++)
		{
			if (keyDriverID.at(j) > keyDriverID.at(j + 1))
			{
				tempDID = keyDriverID.at(j);
				keyDriverID.at(j) = keyDriverID.at(j + 1);
				keyDriverID.at(j + 1) = tempDID;

				tempFName = fName.at(j);
				fName.at(j) = fName.at(j + 1);
				fName.at(j + 1) = tempFName;

				tempMName = mName.at(j);
				mName.at(j) = mName.at(j + 1);
				mName.at(j + 1) = tempMName;

				tempLName = lName.at(j);
				lName.at(j) = lName.at(j + 1);
				lName.at(j + 1) = tempLName;

				tempLNum = licNumber.at(j);
				licNumber.at(j) = licNumber.at(j + 1);
				licNumber.at(j + 1) = tempLNum;
			}
		}
	}
}

void bubbleSortRental() 
{
	int temprVID, temprDID;
	int temppuMonth, temppuDay, temppuYear, temppuHour, temppuMin;
	int tempdoMonth, tempdoDay, tempdoYear, tempdoHour, tempdoMin;
	string tempcFName, tempcMName, tempcLName, tempcNum, tempsAddress, tempcity;

	for (unsigned int i = 1; i < rVID.size(); i++)
	{
		for (unsigned int j = 0; j < rVID.size() - 1; j++)
		{
			if (datetoInt(puMonth.at(j), puDay.at(j), puYear.at(j), puHour.at(j), puMin.at(j)) > datetoInt(puMonth.at(j+1), puDay.at(j+1), puYear.at(j+1), puHour.at(j+1), puMin.at(j+1)))
			{
				temprVID = rVID.at(j);
				rVID.at(j) = rVID.at(j + 1);
				rVID.at(j + 1) = temprVID;

				temprDID = rDID.at(j);
				rDID.at(j) = rDID.at(j + 1);
				rDID.at(j + 1) = temprDID;

				temppuMonth = puMonth.at(j);
				puMonth.at(j) = puMonth.at(j + 1);
				puMonth.at(j + 1) = temppuMonth;

				temppuDay = puDay.at(j);
				puDay.at(j) = puDay.at(j + 1);
				puDay.at(j + 1) = temppuDay;

				temppuYear = puYear.at(j);
				puYear.at(j) = puYear.at(j + 1);
				puYear.at(j + 1) = temppuYear;

				temppuHour = puHour.at(j);
				puHour.at(j) = puHour.at(j + 1);
				puHour.at(j + 1) = temppuHour;

				temppuMin = puMin.at(j);
				puMin.at(j) = puMin.at(j + 1);
				puMin.at(j + 1) = temppuMin;

				tempdoMonth = doMonth.at(j);
				doMonth.at(j) = doMonth.at(j + 1);
				doMonth.at(j + 1) = tempdoMonth;

				tempdoDay = doDay.at(j);
				doDay.at(j) = doDay.at(j + 1);
				doDay.at(j + 1) = tempdoDay;

				tempdoYear = doYear.at(j);
				doYear.at(j) = doYear.at(j + 1);
				doYear.at(j + 1) = tempdoYear;

				tempdoHour= doHour.at(j);
				doHour.at(j) = doHour.at(j + 1);
				doHour.at(j + 1) = tempdoHour;

				tempdoMin = doMin.at(j);
				doMin.at(j) = doMin.at(j + 1);
				doMin.at(j + 1) = tempdoMin;

				tempcFName = cFName.at(j);
				cFName.at(j) = cFName.at(j + 1);
				cFName.at(j + 1) = tempcFName;

				tempcMName = cMName.at(j);
				cMName.at(j) = cMName.at(j + 1);
				cMName.at(j + 1) = tempcMName;

				tempcLName = cLName.at(j);
				cLName.at(j) = cLName.at(j + 1);
				cLName.at(j + 1) = tempcLName;

				tempcNum = cNum.at(j);
				cNum.at(j) = cNum.at(j + 1);
				cNum.at(j + 1) = tempcNum;

				tempsAddress = sAddress.at(j);
				sAddress.at(j) = sAddress.at(j + 1);
				sAddress.at(j + 1) = tempsAddress;

				tempcity = city.at(j);
				city.at(j) = city.at(j + 1);
				city.at(j + 1) = tempcity;
			}
		}
	}

}
