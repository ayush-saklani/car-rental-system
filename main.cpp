#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <time.h>
using namespace std;
//	I have defined all the funtion at the top because some functions call each other at the time of execution :)	//
void fullscreen();				//	It makes the terminal full screen for better expeirence 		(design assistive function)
void Date();					//	It display the date and time 									(design assistive function)
void loading_screen();			//	It diplays the loading screen									(design assistive function)
void welcome();					//	It display welcome when you open the program					(design assistive function)
void art();						//	It displays the company name art at the top of the page 		(design assistive function)
void exit_art();				//	It displays the thankyou art when you exit the portal 			(design assistive function)

void menu();					//	It opens the menu page 											(main control page)
void user();					//	It opens the user portal 										(menu control)
void add_new_customer();		//	It adds new customer and opens the car selecting menu					(user exclusive control)
void existing_customer();  		//	It ask for id and opens the car selecting menu 							(user exclusive control) 
void display_Available_Car();	//	It display all the available cars in the inventory							(user exclusive assistive function) 
void password();				//	It reads and checks the admin password and opens admin portal	(menu control)
void admin();					//	It opens the admin portal 										(menu control)
void showcarData();				//	It display all the cars (available and rented out ) 					(admin exclusive control)
void add_new_admin();			//	It adds new admins to the system										(admin exclusive control)
void add_new_car();				//	It add the new cars to the inventory 									(admin exclusive control) 
void reset_available_car();		//	It resets the available cars in the inventory							(admin exclusive control)
void delete_car();				//	It deletes the car information from the inventory 						(admin exclusive control)
void display_car();				//	It display all the cars (available and rented out )							(admin exclusive assistive function)
void terms_and_conditons();		//	It diplays the terms and condition to the user 					(menu control) 

int customer_Count();			//	It count the no of customers saved in the system 				(assistive working function)
int car_count();				//	It count the no of cars in the inventory						(assistive working function)
int user_count();				//	It count the number of users present in the files 				(assistive working function)
int available_car_count();		//	It count the number of available cars 							(assistive working function)
int rate(int, int);				//	It calculate and return the total rent price 					(assistive working function)

void cardata ();				//	It reads and stores data from files to the local variable		(essential working function)
void readUserPass();			//	It reads and stores data from files to the local variable		(essential working function)
void readavailCar();			//	It reads and stores data from files to the local variable		(essential working function)
void readcustomerData();  		//	It reads and stores data from files to the local variable		(essential working function)

struct car{
	char plate_num[10];
	char brand[20];
	char model[20];
	float capacity;
	char colour[20];
	float rate_per_hour;
	float rate_per_half;
	float rate_per_day;
	char transmission[6];
};
struct customer{
	int id;
	char name[100];
	char phone[15];
	char address[1500];
};
struct pass{
	int ID;
	char password[20];
};
	pass userPass[1000];
	car rent[1000];
	car avail[1000];
	customer cust[1000];
void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void Date(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "\n\t  \t\t\t\t\t\tDATE: %d/%m/%Y TIME: %X", &tstruct);
    cout<< buf<<endl;
}
void welcome(){
	ifstream ifs ("welcome.txt");    
	system("cls");
	while (ifs.good()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	cout<<"\n\t  \t\t\t\t\t\t\t";
	ifs.close ();
	Sleep(3000);
}
void exit_art(){
	ifstream ifs ("exit art.txt");    
	system("cls");
	while (ifs.good ()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
    cout<<"\n\t  \t\t\t\t\t\t\t";
    ifs.close ();
    Sleep(3000);
    exit(0);
}
void art(){	
	ifstream ifs ("art.txt");    
	system("cls");
	while (ifs.good ()){
		string TempLine;
		getline (ifs , TempLine);
		cout<<TempLine<<endl;
	}
	Date();
    ifs.close ();
}
void loading_screen(){
	for(int i=0;i<101;i++){
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n       \t\t\t\t\t\t\t\t\t loading ........"<<i<<"%";
        Sleep(40);
    }
    cout<<"\n\t\t\t\t\tpress any key to continue........"<<endl;
    cout<<"\t\t\t\t\t";
    getch();	
}
void menu(){
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. ADMIN";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. USER";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. T%C";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. EXIT"<<endl<<"\n";
	cout<<"\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		password();
	}
	else if(x==2){
		user();
	}
	else if(x==3){
		terms_and_conditons();
		getch();
	}
	else if(x==4){
		cout << "\n\n\n\n";
		exit_art();
		Sleep(1000);
		exit(0);
	}
	else if(x==5){	//easter egg (; <3
	string timee=	"\n\n\n\n\n\n\n\t  \t\t\t\t\t\t    ______ ____ __  ___ ______\n\t  \t\t\t\t\t\t   /_  __//  _//  |/  // ____/\n\t  \t\t\t\t\t\t    / /   / / / /|_/ // __/\n\t  \t\t\t\t\t\t   / /  _/ / / /  / // /___\n\t \t\t\t\t\t\t  /_/  /___//_/  /_//_____/\n\t  \t\t\t\t\t\t     ";
	for(int z=0;z<=5;z++){
		system("cls");
		cout<<timee;
		Date();
		Sleep(1000);
	}
		system("cls");
		menu();
	}
	else{
		system("cls");
		art();
		cout<<"\n\n\n\n";
		cout<<"\n\t  \t\t\t\t\t\t\t  Invalid Choice.......";
		cout<<"\n\t  \t\t\t\t\t\t\t  Try Again.....";
		Sleep(1000);
		system("cls");
		menu();
	}
	
}
void user(){
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. NEW";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. EXISTING";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. MAIN MENU"<<endl;
	cout<<"\n\n\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		add_new_customer();
	}	
	else if (x==2){
		system("cls");
		existing_customer();
	}	
	else if (x==3){
		menu();
	}	
}
void existing_customer(){
	int tempCust, hour, userID;
	char carSelect[10];
	tempCust = customer_Count() - 1;
	ofstream ofs;
	ofs.open("temp.txt");
	ofstream bill;
	bill.open("bill.txt");
	cout<<"\n\n\n\n";
	cout << endl;
	
	cout<<"\n\n";
	art();
	cout << endl;
	
	cout << "\n\t  \t\t\t\tPlease enter user ID : ";
	cin >> userID;
	int coutoo=0;
	for (int i = 0 ; i < customer_Count() ; i++){
		if (userID == cust[i].id){
			cout<<"\n\t  \t\t\t\t\tWELCOME ";
			cout << cust[i].name;
			cout<<"\t  \tID ";
			cout << cust[i].id;
			cout << "\n\n";
			coutoo++;
			bill <<"\n\n\t  \t\t\t\t\t\t\t\t\t Car Rental System :: INVOICE ";
			bill <<"\n\t  \t\t\t\t\tcustomer name - ";
			bill << cust[i].name;
			bill <<"\t  \tcustomer registered ID - ";
			bill << cust[i].id;
			bill << "\n\n";
		}
	}
	if(coutoo==0){
			cout<<endl;
    		cout<<"\t  \t\t\tUser not found ......"<<endl;
			Sleep(500);
    		cout<<"\t  \t\t\tReturning to user portal.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
    		user();
	}
	else{
		display_Available_Car();
		int tempprice=0;
		cout<<"\n\n\t  \t\t\t\t\tPlease select car";
		cout<<"\n\t  \t\t\t\t\tPlate Number : ";
		cin >> ws;
		cin.getline(carSelect,10);
		int x=available_car_count();
		cout << "\t  \t\t\t\t\tHours of rent : ";
		cin >> hour;
		int op=0;
		for(int i = 0; i < available_car_count(); i++){
			if (strcmp(carSelect,avail[i].plate_num) != 0){
				ofs << avail[i].plate_num;
				ofs << " ";
				ofs << avail[i].brand;
				ofs << " ";
				ofs << avail[i].model;
				ofs << " ";
				ofs << avail[i].capacity;
				ofs << " ";
				ofs << avail[i].colour;
				ofs << " ";
				ofs << avail[i].rate_per_hour;
				ofs << " ";
				ofs << avail[i].rate_per_half;
				ofs << " ";
				ofs << avail[i].rate_per_day;
				ofs << " ";
				ofs << avail[i].transmission;
				if(i != available_car_count()){
					ofs<<endl;
				}
			}
			else{
				tempprice=rate(hour,i);
				op++;
				bill << "\t    Plate Number\t\tBrand \t\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
				bill << "\t    ========================================================================================================================================" << endl;
				bill << "\t     " << avail[i].plate_num << "\t\t" << avail[i].brand   << "\t\t " << avail[i].model << "\t   " << avail[i].capacity << "\t     "
					 << avail[i].colour << "\t  " <<avail[i].rate_per_hour << "\t\t    " << avail[i].rate_per_half << "\t\t    " << avail[i].rate_per_day 
					 << "\t\t       " << avail[i].transmission << endl;
				bill << "\t    ========================================================================================================================================" << endl;
				bill <<"\n\t  \t\t\t\t\tHours of rent : "<<hour<<endl;
				bill <<"\t  \t\t\t\t\tPrice for " << hour << " hours of rent : USD ";
				bill << tempprice<<endl;
				bill <<"\n\t  \t\t\t\t\tThankyou for shopping\n\t  \t\t\t\t\tBE SAFE RIDE SAFE :)  "<<endl;
				bill << "\t    ========================================================================================================================================" << endl;
			}
		}
		ofs.close();
		bill.close();
		remove("available.txt");
		rename("temp.txt","available.txt");
		cardata();
		readavailCar();
		if(op==0){
			cout<<endl;
    		cout<<"\t  \t\t\tCar not found ..... "<<endl;
    		cout<<"\t  \t\t\tReturning to user portal.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
			readavailCar();
    		user();
		}
		else{
		cout << "\t  \t\t\t\tPrice for " << hour << " hours of rent : USD ";
		cout << tempprice;
		cout<<"\n\t  \t\t\t\tDont forget to collect your bill .............";
		Sleep(5000); 
		system("cls");
		menu();
	}
}
}
void add_new_customer (){
	cout<<"\n\n";
	art();
	cout << endl;
	
	readavailCar();
	ofstream ofs;
	ofs.open("Customer.txt", fstream::app);
	ofstream bill;
	bill.open("bill.txt");
	ofs << endl;
	ofstream availTemp;
	availTemp.open("availtemp.txt");
	cout<<"\n\n\n\n";
	cout << endl;
	  
	cust[customer_Count()].id = customer_Count() + 1001;
	ofs << cust[customer_Count()].id;
	ofs << ";";
		
	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the data below : " << endl;
	
	cout << "\n\t  \t\t\t\t\t  Name : ";
	cin >> ws;
	cin.getline(cust[customer_Count()].name,100);
	ofs << cust[customer_Count()].name<<";";
	
	cout << "\t  \t\t\t\t\t  Phone Number : ";
	cin.getline(cust[customer_Count()].phone,15);
	ofs << cust[customer_Count()].phone;
	ofs << ";";

	cout << "\t  \t\t\t\t\t  Address : ";
	cin.getline(cust[customer_Count()].address,1500);
	ofs << cust[customer_Count()].address;
	
	ofs.close();
	
	system("cls");
	
	int tempCust, hour;
	char carSelect[10];
	tempCust = customer_Count() - 1;
	
	cout<<"\n\n\n\n";
	art();
	cout << endl;
	
	cout<<"\n\t  \t\t\tWELCOME ";
	cout << cust[tempCust].name;
	cout<<"\t  \tID ";
	cout << cust[tempCust].id;
	cout << "\n\n";
			bill <<"\n\n\t  \t\t\t\t\t\t\t\t\t Car Rental System :: INVOICE ";
			bill <<"\n\t  \t\t\t\t\tcustomer name - ";
			bill << cust[tempCust].name;
			bill <<"\t  \tcustomer registered ID - ";
			bill << cust[tempCust].id;
			bill << "\n\n";
	display_Available_Car();
	
	cout<<"\n\n\t  \tPlease select car";
	cout<<"\n\t  \tPlate Number : ";
	cin >> ws;
	cin.getline(carSelect,10);
	
	int x=available_car_count();
	int op=0;
	for(int i = 0; i < available_car_count(); i++){
		if (strcmp(carSelect,avail[i].plate_num) != 0){
			availTemp << avail[i].plate_num;
			availTemp << " ";
			availTemp << avail[i].brand;
			availTemp << " ";
			availTemp << avail[i].model;
			availTemp << " ";
			availTemp << avail[i].capacity;
			availTemp << " ";
			availTemp << avail[i].colour;
			availTemp << " ";
			availTemp << avail[i].rate_per_hour;
			availTemp << " ";
			availTemp << avail[i].rate_per_half;
			availTemp << " ";
			availTemp << avail[i].rate_per_day;
			availTemp << " ";
			availTemp << avail[i].transmission;
			if(i != available_car_count()){
				availTemp<<endl;
			}		
		}
		else {
			op++;
			}
	}
	
	availTemp.close();
	remove("available.txt");
	rename("availtemp.txt","available.txt");
	if(op==0){
			cout<<endl;
    		cout<<"\t  \t\t\tCar not found ..... "<<endl;
    		cout<<"\t  \t\t\tReturning to user portal.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
			readavailCar();
    		user();
	}
	else{
		cout << "\t  \tHours of rent : ";
		cin >> hour;
		int j;
		for(int i = 0; i < car_count(); i++){
			if (strcmp(carSelect,avail[i].plate_num) == 0){
				j = i;
				rate(hour,j);		
				
			}
		}			
		cout << "\n\t  \tPrice for " << hour << " hours of rent : USD ";
		cout << rate(hour,j);
				bill << "\t    Plate Number\t\tBrand \t\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
				bill << "\t    ========================================================================================================================================" << endl;
				bill << "\t     " << avail[j].plate_num << "\t\t" << avail[j].brand   << "\t\t " << avail[j].model << "\t   " << avail[j].capacity << "\t     "
					 << avail[j].colour << "\t  " <<avail[j].rate_per_hour << "\t\t    " << avail[j].rate_per_half << "\t\t    " << avail[j].rate_per_day 
					 << "\t\t       " << avail[j].transmission << endl;
				bill << "\t    ========================================================================================================================================" << endl;
				bill <<"\n\t  \t\t\t\t\tHours of rent : "<<hour<<endl;
				bill <<"\t  \t\t\t\t\tPrice for " << hour << " hours of rent : USD ";
				bill << rate(hour,j)<<endl;
				bill <<"\n\t  \t\t\t\t\tThankyou for shopping\n\t  \t\t\t\t\tBE SAFE RIDE SAFE :)  "<<endl;
				bill << "\t    ========================================================================================================================================" << endl;	



			
	bill.close();
	readavailCar();
	cout<<"\n\t  \tDont forget to collect your bill .............";
	Sleep(5000);
	system("cls");
	menu();
	}
}
void display_Available_Car(){
	cout << "\t    Plate Number\tBrand \t\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < available_car_count(); i++){
		cout << "\t     " << avail[i].plate_num << "\t\t" << avail[i].brand   << "\t\t " << avail[i].model << "\t   " << avail[i].capacity << "\t     "
			 << avail[i].colour << "\t  " <<avail[i].rate_per_hour << "\t\t    " << avail[i].rate_per_half << "\t\t    " << avail[i].rate_per_day 
			 << "\t\t       " << avail[i].transmission << endl;
	}
}
void password(){
	art();
   	string password;
   	char c;
   	cout << "\n\n\n\n\t  \t\t\tpassword: ";
		while(c != '\r'){ 
        	c = getch();
        	if(c == '\b'){   //If the Backspace is pressed then we have to erase 1 '*' 
        	    if(password.size() != 0){  //If the password string contains data, erase last character
        	       cout << "\b \b";
        	       password.erase(password.size() - 1, 1);
        	    }
        	    continue;
        	}
        	else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){  //If user enters 1-9, a-z, or A-Z, add it to the password and display an '*'
        	    password += c;
        	    cout << "*";
        	}
        	else{
        	    continue;
			}
        }
        for(int i=0; i<user_count();i++){
         	if(password.compare(userPass[i].password)==0){
         		system("cls");
		 		admin();
			}
		}
        if(password == "a"){ //masterkey ;)
        	system("cls");
        	admin();
      	}	
		else{
			cout<<endl;
    		cout<<"\t  \t\t\tWrong password.. Call Administrator"<<endl;
    		cout<<"\t  \t\t\tReturning to Main Menu.."<<endl<<endl;
    		cout<<"\t  \t\t\t"<<endl;
			Sleep(1000);
    		cout<<"\t  \t\t\tPress Enter to Continue."<<endl;
    		cout<<"\t  \t\t\t";
    		getch();
			system("cls");
    		menu();
		}
}
void admin(){
	int x;
	art();
	cout << endl;
	cout<<"\n\t  \t\t\t\t\t\t\t  1. ADD ADMIN";
	cout<<"\n\t  \t\t\t\t\t\t\t  2. SHOW DATA";
	cout<<"\n\t  \t\t\t\t\t\t\t  3. ADD CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  4. DELETE CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  5. RESET AVAILABLE CAR";
	cout<<"\n\t  \t\t\t\t\t\t\t  6. LOG OFF"<<endl<<"\n";
	cout<<"\t  \t\t\t\t\t\t\tINPUT :";
	cin>>x;
	system("cls");
	if (x==1){
		add_new_admin();
	}	
	else if (x==2){
		showcarData();
	}
	else if (x==3){
		add_new_car();
	}
	else if (x==4){
		delete_car();
	}
	else if(x==5){
		system("cls");
		reset_available_car();
	}
	else if (x==6){
		menu();
	}
}
void add_new_car(){
	cout<<"\n\n";
	art();
	cout << endl;
	
	ofstream ofs;
	ofs.open("car rental.txt" , fstream::app);
	ofs<<endl;
	
	int newCar = car_count() + 1;
	cout << "\n\n";
	cout << "\n\t  \t\t\t\t\t  Please enter the car data below : " << endl;
	
	cout << "\n\t  \t\t\t\t\t  Plate Number : ";
	cin >> ws;
	cin.getline(rent[newCar].plate_num,10);
	ofs << rent[newCar].plate_num;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Brand : ";
	cin.getline(rent[newCar].brand,20);
	ofs << rent[newCar].brand;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Model : ";
	cin.getline(rent[newCar].model,20);
	ofs << rent[newCar].model;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Capacity : ";
	cin >> rent[newCar].capacity;
	ofs << rent[newCar].capacity;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Colour : ";
	cin >> ws;
	cin.getline(rent[newCar].colour,20);
	ofs << rent[newCar].colour;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per Hour : ";
	cin >> rent[newCar].rate_per_hour;
	ofs << rent[newCar].rate_per_hour;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per 12 Hour : ";
	cin >> rent[newCar].rate_per_half;
	ofs << rent[newCar].rate_per_half;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Rate Per 24 Hour : ";
	cin >> rent[newCar].rate_per_day;
	ofs << rent[newCar].rate_per_day;
	ofs << " ";
	
	cout << "\t  \t\t\t\t\t  Tranmission (A/M) : ";
	cin >> ws;
	cin.getline(rent[newCar].transmission,6);
	ofs << rent[newCar].transmission;
	
	ofs.close();
	system("cls");
	cardata();
	admin();
}
void reset_available_car(){
	fstream f1;
    fstream f2;
    string ch;
    f1.open("car rental.txt", ios::in);
    f2.open("available.txt", ios::out);
	
    while (!f1.eof()) {
        getline(f1, ch);
        f2 << ch << endl;
    }
    f1.close();
    f2.close();
	readavailCar();
	admin();
}
void add_new_admin(){
	ofstream ofs;
	ofs.open("UserPass.txt", fstream::app);
	userPass[user_count()].ID = user_count()+1;
	string password;
	char c;

	cout << "\n\n\n\n\t  \t\t\tID(DEFAULT): "<<userPass[user_count()].ID;
	cout << "\n\t  \t\t\tADD password: ";

	while(c != '\r'){
        c = getch();
        if(c == '\b'){
            if(password.size() != 0){
            	cout << "\b \b";
            	password.erase(password.size() - 1, 1);
            }
            continue;
        }
        else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            password += c;
            cout << "*";
        }
        else
            continue;
    }
	strcpy(userPass[user_count()].password,password.c_str());
	ofs<<userPass[user_count()].ID;
	ofs<<";";
	ofs<<userPass[user_count()].password;
	ofs<<endl;
	system("cls");
	admin();
}
void showcarData(){
	int x;
	cout<<"\n\n";
	art();
	cout << endl;
	
	cout << "\t    Plate Number\tBrand\t\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < car_count(); i++){
		cout << "\t    " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			<< rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day 
			<< "\t\t       " << rent[i].transmission << endl;
	}
	cout << "\n\n";
	cout<<"\n\t  \t\t\t\t\t  1. BACK";
	cout<<"\n\t  \t\t\t\t\t  2. MAIN MENU"<<endl<<"\n\n";
	cout<<"\t  \t\t\t\t\tINPUT :";
	cin >> x;
	system("cls");

	if (x==1){
		admin();
	}
	if (x==2){
		menu();
	}
}
void delete_car(){
	char plate[10];
	ofstream ofs;
	ofs.open("temp.txt");
	cout<<"\n\n\n\n";
	art();
	cout << endl;
	display_car();
	cout << "\n\n";
	cout << "\t   \t\tEnter the car plate number that are going to be deleted (CAPITAL LETTER W/OUT SPACE): "<<endl;
	cout << "\t    \t\t\t\t\t\t\t";
	cin >> ws;
	cin.getline(plate,10);
	int x=car_count();
	for(int i = 0; i < car_count(); i++){
		if (strcmp(plate,rent[i].plate_num) != 0){
			ofs << rent[i].plate_num;
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if(i != car_count()){
				ofs<<endl;
			}
		}
	}
	ofs.close();
	remove("car rental.txt");
	rename("temp.txt","car rental.txt");
	system("cls");
	cardata();
	admin();
}
void display_car(){
	cout << "\t    Plate Number\tBrand\t\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t    ==============================================================================================================================" << endl;
	for (int i = 0; i < car_count(); i++){
		cout << "\t    " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			 << rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day 
			 << "\t\t       " << rent[i].transmission << endl;
	}
}
void terms_and_conditons(){
	art();
	cout<<endl;
	cout<<"\n\t  \t\t\t1. ANY SORT OF MODIFICATIONS ON THE CAR IS NOT ALLOWED";
	cout<<"\n\t  \t\t\t2. TAKE CARE OF YOUR STUFF ON YOUR OWN";
	cout<<"\n\t  \t\t\t3. IN CASE OF ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
	cout<<"\n\t  \t\t\t4. PREPARE ITEM AS BELOW";
	cout<<"\n\t  \t\t\t     =>COPY OF IC, LICENSE";
	cout<<"\n\t  \t\t\t     =>ADVANCE DEPOSIT (APPLICABLE DIFFRENTLY FOR DIFFRENT CARS)";
	cout<<"\n\t  \t\t\t5. ADDITIONAL CHARGE APPLICABLE IN CASE OF LATE RETURNS";
	cout<<"\n\t  \t\t\t6. SAFE DRIVE!";
	cout<<"\n\n\n";
	cout<<"\n\t  \t\t\t                             PRESS ANY KEY TO CONTINUE.........\n\t\t\t\t ";	
	getch();
	system("cls");
	menu();
}

int rate(int hour, int j){
	int hour_24, hour_12, hour_1;
	int total, total_24, total_12, total_1;

	hour_24=hour/24;
	hour_12=(hour - hour_24*24)/12;
	hour_1=(hour - hour_24*24 - hour_12*12)/1;
	
	total_24 = hour_24 * avail[j].rate_per_day;
	total_12 = hour_12 * avail[j].rate_per_half;
	total_1  = hour_1  * avail[j].rate_per_hour;
	total = total_24 + total_12 + total_1;
	return total;
}
int car_count(){
	int numOfCar = 0;
	ifstream ifs("car rental.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	numOfCar++;
	}
	ifs.close();
	return numOfCar;
}
int customer_Count(){
	int numOfCust = 0;
	ifstream ifs("Customer.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	numOfCust++;
	}
	ifs.close();
	return numOfCust;
}
int user_count(){
	int numOfCust = 0;
	ifstream ifs("UserPass.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	numOfCust++;
	}
	ifs.close();
	return numOfCust;
}
int available_car_count(){
	int numOfCust = 0;
	ifstream ifs("available.txt"); 
	string word;
	while (getline(ifs, word)){
    	if (!word.empty())
        	numOfCust++;
	}
	ifs.close();
	return numOfCust;
}

void readUserPass(){
	ifstream ifs;
	ifs.open("UserPass.txt");
	int i;
	while(!ifs.eof()){
		ifs>>userPass[i].ID;
		ifs.ignore();
		ifs.getline(userPass[i].password,20);
		i++;
	}
	cout<<"works";
	ifs.close();
}
void readavailCar (){
	ifstream ifs;
	ifs.open("available.txt");
	int carNum = 0;
	while(!ifs.eof()){
		ifs.getline(avail[carNum].plate_num,10,' ');
		ifs.getline(avail[carNum].brand,20,' ');
		ifs.getline(avail[carNum].model,20,' ');
		ifs >> avail[carNum].capacity;
		ifs.ignore();
		ifs.getline(avail[carNum].colour,20,' ');
		ifs >> avail[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_half;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(avail[carNum].transmission,6);
		carNum++;
		ifs>>ws;
	}
	ifs.close();
}
void readcustomerData(){
	ifstream ifs;
	ifs.open("Customer.txt");
	int custNum = 0;
	while (!ifs.eof()){
		ifs >> cust[custNum].id;
		ifs.ignore();
		ifs.getline(cust[custNum].name,100,';');
		ifs.getline(cust[custNum].phone,15,';');
		ifs.getline(cust[custNum].address,1500);
		custNum++;
	} 
	ifs.close();
}
void cardata (){
	ifstream ifs;
	ifs.open("car rental.txt");
	int carNum = 0;
	while(!ifs.eof()){
		ifs.getline(rent[carNum].plate_num,10,' ');
		ifs.getline(rent[carNum].brand,20,' ');
		ifs.getline(rent[carNum].model,20,' ');
		ifs >> rent[carNum].capacity;
		ifs.ignore();
		ifs.getline(rent[carNum].colour,20,' ');
		ifs >> rent[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_half;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(rent[carNum].transmission,6);
		carNum++;
		ifs>>ws;
	}
	ifs.close();
}
int main(){
	fullscreen();
	Sleep(1000);
    system("COLOR F0");
	Sleep(500);
    //loading_screen();
	welcome();
	system("cls");
	readUserPass();
	readavailCar();
	readcustomerData();
	cardata();
	menu();
	return 0;
}
