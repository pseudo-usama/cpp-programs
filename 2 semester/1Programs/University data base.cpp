//Header Files
#include "stdafx.h"
#include "iostream"
#include "string"
#include "sstream"
#include "conio.h"
#include "fstream"
#include "direct.h"					//For Creating Folder
#include "windows.h"				//For Console Size
#include <tchar.h>					//For Title
#include <strsafe.h>				//For Title
#include "MMSystem.h"				//For Playing Audio
#include "thread"					//For multi Thread Programming
using namespace std;

#pragma comment(lib, "winmm.lib")	//For Playing Audio

string Activated[19];				//Store Data of current active Profile
string FileLocation = "E://";		//Saves Location of File Handling

//These Colors are use in outputs on screen
const int OptionColor = 603;
const int HeadingColor = 900;
const int InfoColor = 307;

void Music();								//This Function Play Audio Files
void Text(string, string, int, bool);		//Function cout Colored statments
void Cursor(bool showFlag = true);			//Cursor Hide/Show

string FileNamer(string);					//Combines Files Name and its Location
string IdMaker(string, string);				//Make ID when a user Register
void DirectoryMakerFn();					//Make Folders for Files

string GetPassword();						//Get Password as star(*)

void ProfileViewerFn();						//Show Data of Active Profile

//This Function Store Data of Profile when it is Login or Register
void ProfileSetter(string, string, string, string, string, string, string, string, string,
	string, string, string, string, string, string, string, string, string, string, string);

//All these Functions below makes Pages and control the usage of classes
void MainFn();

void OwnerLoginFn();
void OwnerFn();

void Administrator();

void LoginOrRegister(string Decider);

void LoginFn(string);
void RegisterFn(string);

void AdminFn();
void TeacherFn();
void WorkersFn();

void StudentFn();

/*
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
*/

/*
void centerstring(char*s)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize;
	NewSBSize = GetLargestConsoleWindowSize(hOut);
	int l = strlen(s);
	int pos = (int)((NewSBSize.X - l) / 2);
	for (int i = 0; i<pos; i++)
		cout << " ";
	cout << s;
}
*/

class University{
protected:
	string ProfileStatus;
	string Name;
	string FatherName;
	string Age;
	string Id;
	string Phone;
	string Email;
	string Address;
	string Password;

public:
	void PutUniversity(){
		Cursor();

		ProfileStatus = "1";

		Text("Enter the Name                 = ", "\0", InfoColor, false);
		getline(cin, Name);

		Text("Enter the Father Name          = ", "\0", InfoColor, false);
		getline(cin, FatherName);

		Text("Enter Age                      = ", "\0", InfoColor, false);
		getline(cin, Age);
		
		Text("Enter Phone number             = ", "\0", InfoColor, false);
		getline(cin, Phone);

		Text("Enter Email Address            = ", "\0", InfoColor, false);
		getline(cin, Email);

		Text("Enter Password                 = ", "\0", InfoColor, false);
		Password = GetPassword();

		Text("Enter Address                  = ", "\0", InfoColor, false);
		getline(cin, Address);
	}

	University() {
		ProfileStatus = "\0";
		Name = "\0";
		FatherName = "\0";
		Age = "\0";
		Id = "\0";
		Phone = "\0";
		Email = "\0";
		Password = "\0";
		Address = "\0";
	}
	~University(){
		ProfileStatus = "\0";
		Name = "\0";
		FatherName = "\0";
		Age = "\0";
		Id = "\0";
		Phone = "\0";
		Email = "\0";
		Password = "\0";
		Address = "\0";
	}
};

class Student :virtual protected University{
protected:
	string Program;
	string CGPA;
	string AdmissionYear;

public:
	void PutStudent(){
		PutUniversity();

		Text("Enter Program                  = ", "\0", InfoColor, false);
		getline(cin,Program);

		Text("Enter CGPA                     = ", "\0", InfoColor, false);
		getline(cin, CGPA);

		Text("Enter Admission year           = ", "\0", InfoColor, false);
		getline(cin, AdmissionYear);
	}

	Student(){
		Program = "\0";
		CGPA = "\0";
		AdmissionYear = "\0";
	}
	~Student(){
		Program = "\0";
		CGPA = "\0";
		AdmissionYear = "\0";
	}
};

class RecentStudent :virtual protected Student{
protected:
	string RecentSmester;

public:
	void PutRecentStudent(){
		PutStudent();

		Text("Enter Recent Semester          = ", "\0", InfoColor, false);
		getline(cin, RecentSmester);

		Id = IdMaker("DataBase//RecentStudents//IdSaver.txt", "Stu-");
		
		string FileName = FileNamer("DataBase//RecentStudents//RecentStudent.txt");
		ofstream ob;
		ob.open(FileName, ios::app);

		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;						//University class Variables
		ob << Age << endl;
		ob << Id << endl;
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Program << endl;							//Student class Variables
		ob << CGPA << endl;
		ob << AdmissionYear << endl;

		ob << RecentSmester << endl;					//RecentStudent class Variable

		ob.close();
		
		ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, Program, CGPA,
			AdmissionYear, RecentSmester, "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0");
	}
	bool GetRecentStudent() {
			string ID, PASSWORD;

			Text("Enter Id                       = ", "\0", InfoColor, false);
			getline(cin, ID);

			Text("Enter Password                 = ", "\0", InfoColor, false);
			PASSWORD = GetPassword();
			
			string FileName = FileNamer("DataBase//RecentStudents//RecentStudent.txt");
			ifstream ob;
			ob.open(FileName, ios::app);
			
			while (!ob.eof()) {
				getline(ob, ProfileStatus);
				getline(ob, Name);
				getline(ob, FatherName);
				getline(ob, Age);
				getline(ob, Id);
				getline(ob, Phone);
				getline(ob, Email);
				getline(ob, Address);
				ob >> Password;//getline(ob, Password);
				getline(ob, Program);
				getline(ob, CGPA);
				getline(ob, AdmissionYear);
				getline(ob, RecentSmester);

				if (Id == ID && Password == PASSWORD){				
						ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, Program, CGPA,
							AdmissionYear, RecentSmester, "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0");
							
					ob.close();
					return 1;
				}
			}
			ob.close();
			return 0;
		}
	
	RecentStudent(){
		RecentSmester = "\0";
	}
	~RecentStudent(){
		RecentSmester = "\0";
	}
};

class GraduatedStudents :virtual protected Student{
private:
	string FinalYear;

public:
	void PutGraduatedStudents(){
		PutStudent();

		Text("Enter your Final year          = ", "\0", InfoColor, false);
		getline(cin, FinalYear);

		ofstream ob, CounterOb;
		ob.open("E://Graduated Student.txt", ios::app);
		CounterOb.open("E://Counter Graduated Student.txt", ios::app);

		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;
		ob << Age << endl;
		ob << Id << endl;									//University class Variables
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Program << endl;								//Student class Variables
		ob << CGPA << endl;
		ob << AdmissionYear << endl;

		ob << FinalYear << endl;							//RecentStudent class Variable
	}
	char GetGraduatedStudents(){
		string ID, PASSWORD;

		Text("Enter Id                       = ", "\0", InfoColor, false);
		getline(cin, ID);

		Text("Enter Password                 = ", "\0", InfoColor, false);
		getline(cin, PASSWORD);

		ifstream ob;
		ob.open("E://Graduated Student.txt", ios::in);

		while (!ob.eof()) {
			getline(ob, ProfileStatus);
			getline(ob, Name);
			getline(ob, FatherName);
			getline(ob, Age);
			getline(ob, Id);
			getline(ob, Phone);
			getline(ob, Email);
			getline(ob, Address);
			getline(ob, Password);
			getline(ob, Program);
			getline(ob, AdmissionYear);
			getline(ob, FinalYear);

			if (Id.compare(ID) == 0 && Password.compare(PASSWORD) == 0){
				ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, Program, CGPA, AdmissionYear, "\0",
					FinalYear, "\0", "\0", "\0", "\0", "\0", "\0", "\0");
				return '9';
			}
		}
		return 'm';
	}

	GraduatedStudents(){
		FinalYear = "\0";
	}
	~GraduatedStudents(){
		FinalYear = "\0";
	}
};

class DropedStudents :virtual protected Student{
private:
	string DroppingSemester;
	string FailSubject;

public:
	void PutDropedStudents(){
		PutStudent();

		Text("Enter Dropping Semester        = ", "\0", InfoColor, false);
		getline(cin, DroppingSemester);

		Text("Enter Failed Subjects          = ", "\0", InfoColor, false);
		getline(cin, FailSubject);


		ofstream ob, CounterOb;
		ob.open("E://Droped Students.txt", ios::app);
		CounterOb.open("E://Counter Droped Student.txt", ios::app);

		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;
		ob << Age << endl;
		ob << Id << endl;								//University class Variables
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Program << endl;							//Student class Variables
		ob << CGPA << endl;
		ob << AdmissionYear << endl;

		ob << DroppingSemester << endl;					//RecentStudent class Variable
	}
	void GetDropedStudents(){
		//GetStudent();

		cout << "Dropping Semester              = " << DroppingSemester << endl;
		cout << "Failed Subjects                = " << FailSubject << endl;
	}

	DropedStudents(){
		DroppingSemester = "\0";
		FailSubject = "\0";
	}
	~DropedStudents(){
		DroppingSemester = "\0";
		FailSubject = "\0";
	}
};

class Employee :virtual protected University{
protected:
	string Experiance;
	string Education;

public:
	void PutEmployee(){
		PutUniversity();

		Text("Enter your Experiance          = ", "\0", InfoColor, false);
		getline(cin, Experiance);

		Text("Enter your Education           = ", "\0", InfoColor, false);
		getline(cin, Education);
	}

	Employee(){
		Experiance = "\0";
		Education = "\0";
	}
	~Employee(){
		Experiance = "\0";
		Education = "\0";
	}
};

class Administration :virtual protected Employee {
protected:
	string Field;

public:
	friend void SearchID();
	friend void ShowAllData(char Decider);

	void PutAdministration(){
		PutEmployee();

		Text("Enter Field you want to work   = ", "\0", InfoColor, false);
		getline(cin, Field);
		
		Id = IdMaker("DataBase//Admintration//IdSaver.txt", "Adm-");
		
		string FileName = FileNamer("DataBase//Admintration//Admin.txt");
		ofstream ob;
		ob.open(FileName, ios::app);

		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;
		ob << Age << endl;
		ob << Id << endl;				//University class Variables
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Experiance << endl;		//Employee class Variables
		ob << Education << endl;

		ob << Field << endl;			//Administration class Variable

		ob.close();

		ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, 
			"\0", "\0", "\0", "\0", "\0", "\0", "\0", Experiance, Education, Field, "\0", "\0");
	}
	bool GetAdministration() {
		string ID, PASSWORD;
		
		Text("Enter Id                       = ", "\0", InfoColor, false);
		getline(cin, ID);

		Text("Enter Password                 = ", "\0", InfoColor, false);
		PASSWORD = GetPassword();

		string FileName = FileNamer("DataBase//Admintration//Admin.txt");
		ifstream ob;
		ob.open(FileName, ios::app);
		
		while (!ob.eof()) {
			getline(ob, ProfileStatus);
			getline(ob, Name);
			getline(ob, FatherName);
			getline(ob, Age);
			getline(ob, Id);
			getline(ob, Phone);
			getline(ob, Email);
			getline(ob, Address);
			getline(ob, Password);
			getline(ob, Experiance);
			getline(ob, Education);
			getline(ob, Field);
			cout << "bar" << endl;
			if (Id == ID && Password == PASSWORD){
				cout << "indar" << endl;
				ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, "\0", "\0", 
					"\0", "\0", "\0", "\0", "\0", Experiance, Education, Field, "\0", "\0");
					
				ob.close();
				return 1;
			}
		}
		ob.close();
		return 0;
	}

	Administration()  { Field = "\0"; }
	~Administration() { Field = "\0"; }
};

class Teachers :virtual protected Employee{
protected:
	string TeacherProgram;

public:
	void PutTeachers(){
		PutEmployee();

		Text("Enter the Program you teach    = ", "\0", InfoColor, false);
		getline(cin, TeacherProgram);

		Id = IdMaker("DataBase//Teachers//IdSaver.txt", "Tec-");

		string FileName = FileNamer("DataBase//Teachers//Teachers.txt");
		ofstream ob;
		ob.open(FileName, ios::app);
		
		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;
		ob << Age << endl;
		ob << Id << endl;						//University class Variables
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Experiance << endl;				//Employee class Variables		
		ob << Education << endl;

		ob << TeacherProgram << endl;					//RecentStudent class Variable

		ob.close();

		ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, "\0", "\0", "\0"
			,"\0", "\0", "\0", "\0", Experiance, Education, "\0", TeacherProgram, "\0");
	}
	bool GetTeachers() {
		string FileName = FileNamer("DataBase//Teachers//Teachers.txt");
		ifstream ob;
		ob.open(FileName, ios::app);

		string ID, PASSWORD;

		Text("Enter Id                       = ", "\0", InfoColor, false);
		getline(cin, ID);

		Text("Enter Password                 = ", "\0", InfoColor, false);
		PASSWORD = GetPassword();
			
		while (!ob.eof()) {
			getline(ob, ProfileStatus);
			getline(ob, Name);
			getline(ob, FatherName);
			getline(ob, Age);
			getline(ob, Id);
			getline(ob, Phone);
			getline(ob, Email);
			getline(ob, Address);
			getline(ob, Password);
			getline(ob, Experiance);
			getline(ob, Education);
			getline(ob, TeacherProgram);

			if (Id == ID && Password == PASSWORD){
					
				ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address,
					"\0", "\0", "\0", "\0", "\0", "\0", "\0", Experiance, Education, "\0", TeacherProgram, "\0");
				ob.close();
				return 1;
			}
		}
		ob.close();
		return 0;
	}
	
	Teachers() { TeacherProgram = "\0"; }
	~Teachers(){ TeacherProgram = "\0"; }
};

class Workers :virtual protected Employee{
protected:
	string Work;

public:
	void PutWorkers(){
		PutEmployee();

		Text("Enter the Service              = ", "\0", InfoColor, false);
		getline(cin, Work);

		Id = IdMaker("DataBase//Workers//IdSaver.txt", "Wor-");

		string FileName = FileNamer("DataBase//Workers//Workers.txt");
		ofstream ob;
		ob.open(FileName, ios::app);
		
		ob << ProfileStatus << endl;
		ob << Name << endl;
		ob << FatherName << endl;
		ob << Age << endl;
		ob << Id << endl;						//University class Variables
		ob << Phone << endl;
		ob << Email << endl;
		ob << Address << endl;
		ob << Password << endl;

		ob << Experiance << endl;				//Employee class Variables		
		ob << Education << endl;

		ob << Work << endl;						//Employee class Variable

		ob.close();
		
		ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, "\0"
			, "\0", "\0", "\0", "\0", "\0", "\0", Experiance, Education, "\0", "\0", Work);
	}
	bool GetWorkers(){
		string ID, PASSWORD;

		Text("Enter Id                       = ", "\0", InfoColor, false);
		getline(cin, ID);

		Text("Enter Password                 = ", "\0", InfoColor, false);
		PASSWORD = GetPassword();

		string FileName = FileNamer("DataBase//Workers//Workers.txt");
		ifstream ob;
		ob.open(FileName, ios::app);

		while (!ob.eof()) {
			getline(ob, ProfileStatus);
			getline(ob, Name);
			getline(ob, FatherName);
			getline(ob, Age);
			getline(ob, Id);
			getline(ob, Phone);
			getline(ob, Email);
			getline(ob, Address);
			getline(ob, Password);
			getline(ob, Experiance);
			getline(ob, Education);
			getline(ob, Work);

			if (Id == ID && Password == PASSWORD){

				ProfileSetter(Name, FatherName, Age, Id, Phone, Email, Password, Address, "\0"
					, "\0", "\0", "\0", "\0", "\0", "\0", Experiance, Education, "\0", "\0", Work);
				ob.close();
				return 1;
			}
		}
		ob.close();
		return 0;
	}

	Workers()  { Work = "\0"; }
	~Workers() { Work = "\0"; }
};

class Owner : protected RecentStudent, protected GraduatedStudents, protected DropedStudents
	, protected Administration, protected Teachers, protected Workers {

public:
	friend void SearchID();
	friend void ShowAllData(string Decider);
};

void main(){
	{
		//Set exe File Name
		SetConsoleTitle(TEXT("UOG Managment System"));
		
		//Set the Font Size
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 15;							// Width of each character in the font
		cfi.dwFontSize.Y = 25;							// Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");			// Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	//Making thread
	thread t(Music);
		
	//This Function makes Folders
	DirectoryMakerFn();
	
	MainFn();

	t.join();
}

void MainFn(){
	char selector;

	system("CLS");
	Text("Welcome to UOG", "\0", HeadingColor, true);
	Text("Press the correspond number to select that option","\0", HeadingColor, true);
	
	Text("1. ", "Administrator", OptionColor, true);
	Text("2. ", "Student", OptionColor, true);
	Text("3. ", "Login as Owner", OptionColor, true);
	Text("4. ", "Exit", OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '4') { goto AGAIN; }

	if      (selector == '1') { Administrator();     }
	else if (selector == '2') { LoginOrRegister(""); }
	else if (selector == '3') { OwnerLoginFn();      }
	else                      { exit(0);             }
}

void OwnerLoginFn() {
	char selector;
	string Password;
	
	LONGINAGAIN:
	system("CLS");

	Text("Enter the Password             = ", "\0", InfoColor, false);
	Password = GetPassword();

	if (Password == "Owner") { OwnerFn(); }
	else {
		system("CLS");

		Text("Entered Password is Incorrect", "\0", HeadingColor, true);
		Text("1. ", "Try Again", OptionColor, true);
		Text("2. ", "Back"     , OptionColor, true);
		Text("3. ", "Exit"     , OptionColor, true);
		Cursor(false);

		AGAIN:
		selector = _getch();
		if (selector < '1' || selector > '3') { goto AGAIN; }

		if      (selector == '1') { goto LONGINAGAIN; }
		else if (selector == '2') { MainFn();         }
		else                      { exit(0);          }
	}
}

void OwnerFn() {
	OWNER:

	char selector;

	system("CLS");
		
	Text("1. ", "Search an Id"            , OptionColor, true);
	Text("2. ", "View Admin Whole Data"   , OptionColor, true);
	Text("3. ", "View Teachers Whole Data", OptionColor, true);
	Text("4. ", "View Workers Whole Data" , OptionColor, true);
	Text("5. ", "View Student Whole Data" , OptionColor, true);
	Text("6. ", "Back"                    , OptionColor, true);
	Text("7. ", "Exit"                    , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '8') { goto AGAIN; }
	
	system("CLS");
	
	if      (selector == '1') { SearchID();              }
	else if (selector == '2') { ShowAllData("Admin");    }
	else if (selector == '3') { ShowAllData("Teachers"); }
	else if (selector == '4') { ShowAllData("Workers");  }
	else if (selector == '5') { ShowAllData("Student");  }
	else if (selector == '6') { MainFn();                }
	else                      { exit(0);                 }

	if (selector != '6' || selector != '7') {
		cout << endl << endl;

		Text("1. ", "Back", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);

		again:
		selector = _getch();
		if (selector < '1' && selector > '2') { goto again; }
				
		else if (selector == '1') { goto OWNER; }
		else                      { exit(0);    }
	}
}

void Administrator(){
	system("CLS");

	char selector;

	Text("1. ", "Admin"  , OptionColor, true);
	Text("2. ", "Teacher", OptionColor, true);
	Text("3. ", "Worker" , OptionColor, true);
	Text("4. ", "Back"   , OptionColor, true);
	Text("5. ", "Exit"   , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '5') { goto AGAIN; }

	if      (selector == '1') { LoginOrRegister("Admin");   }
	else if (selector == '2') { LoginOrRegister("Teacher"); }
	else if (selector == '3') { LoginOrRegister("Worker");  }
	else if (selector == '4') { MainFn();                   }
	else                      { exit(0);                    }

}

void LoginOrRegister(string Decider) {
	system("CLS");

	char selector;

	Text("1. ", "Register"                  , OptionColor, true);
	Text("2. ", "Login! Alread have account", OptionColor, true);
	Text("3. ", "Back"                      , OptionColor, true);
	Text("4. ", "Exit"                      , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '4') { goto AGAIN; }

	if      (selector == '1') { RegisterFn(Decider); }
	else if (selector == '2') { LoginFn(Decider);    }
	else if (selector == '3') {
		if (Decider == "Admin" || Decider == "Teacher" || Decider == "Worker") { Administrator(); }
		else                                                                   { MainFn();        }
	}
	else                      { exit(0); }
}

void RegisterFn(string decider) {
	system("CLS");
	Cursor();

	if (decider == "Admin"){
		Text("        Enter Data to Register as ADMINISTRATER", "\0", HeadingColor, true);
		cout << endl;

		Administration ob;
		ob.PutAdministration();

		AdminFn();
	}
	else if (decider == "Teacher"){
		Text("        Enter Data to Register as TEACHER", "\0", HeadingColor, true);
		cout << endl;

		Teachers ob;
		ob.PutTeachers();

		TeacherFn();
	}
	else if (decider == "Worker"){
		Text("        Enter Data to Register as WORKER", "\0", HeadingColor, true);
		cout << endl;

		Workers ob;
		ob.PutWorkers();

		WorkersFn();
	}
	else {
		Text("        Enter Data to Register as STUDENT", "\0", HeadingColor, true);
		cout << endl;

		RecentStudent ob;
		ob.PutRecentStudent();

		StudentFn();
	}
}
void LoginFn(string decider) {
	system("CLS");
	Cursor();

	char selector;
	bool returnDecider;

	LOGINAGAIN:

	if (decider == "Admin"){
		Text("        Enter Data to Login as ADMIN", "\0", HeadingColor, true);
		cout << endl;

		Administration ob;
		returnDecider = ob.GetAdministration();		
	}
	else if (decider == "Teacher"){
		Text("        Enter Data to Login as TEACHER", "\0", HeadingColor, true);
		cout << endl;

		Teachers ob;
		returnDecider = ob.GetTeachers();
	}
	else if (decider == "Worker"){
		Text("        Enter Data to Login as WORKER", "\0", HeadingColor, true);
		cout << endl;

		Workers ob;
		returnDecider = ob.GetWorkers();
	}
	else {
		Text("        Enter Data to Login as STUDENT", "\0", HeadingColor, true);
		cout << endl;

		RecentStudent ob;
		returnDecider = ob.GetRecentStudent();
	}

	if (returnDecider) {
		if      (decider == "Admin")   { AdminFn();   }
		else if (decider == "Teacher") { TeacherFn(); }
		else if (decider == "Worker")  { WorkersFn(); }
		else                           { StudentFn(); }
	}
	else {
		system("CLS");

		Text("Your Entered Data is not Correct.", "\0", HeadingColor, true);
		Text("1. ", "Login Again!", OptionColor, true);
		Text("2. ", "Register", OptionColor, true);
		Text("3. ", "Back", OptionColor, true);
		Text("4. ", "Exit", OptionColor, true);
		Cursor(false);

		AGAIN:
		selector = _getch();
		if (selector < '1' || selector >'4') { goto AGAIN; }

		if      (selector == '1') { system("CLS"); goto LOGINAGAIN; }
		else if (selector == '2') { system("CLS"); RegisterFn(decider); }
		else if (selector == '3') { 
			if   (decider == "Admin" || decider == "Teacher" || decider == "Worker") { Administrator(); }
			else                                                                     { MainFn(); }
		}
		else                      { exit(0); }
	}
}

void AdminFn(){
	ADMIN:

	system("CLS");
	Cursor(false);

	char selector;

	Text("              Admin", "\0", HeadingColor, true);
	Text("1. ", "View your Profile"           , OptionColor, true);
	Text("2. ", "Search any Profile"          , OptionColor, true);
	Text("3. ", "View all Administration Data", OptionColor, true);
	Text("4. ", "View all Teachers Data"      , OptionColor, true);
	Text("5. ", "View all Workers Data"       , OptionColor, true);
	Text("6. ", "View all Students all Data"  , OptionColor, true);
	Text("7. ", "Back"                        , OptionColor, true);
	Text("8. ", "Exit"                        , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '8') { goto AGAIN; }

	system("CLS");
	
	if      (selector == '1') { ProfileViewerFn();       }
	else if (selector == '2') { SearchID();              }
	else if (selector == '3') { ShowAllData("Admin");    }
	else if (selector == '4') { ShowAllData("Teachers"); }
	else if (selector == '5') { ShowAllData("Workers");  }
	else if (selector == '6') { ShowAllData("Student");  }
	else if (selector == '7') { Administrator();         }
	else                      { exit(0);                 }

	if (selector != '6' || selector != '7') {
		cout << endl << endl;

		Text("1. ", "Back", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);

		again:
		selector = _getch();
		if (selector<'1' || selector>'2') { goto again; }

		if (selector == '1') { goto ADMIN; }
		else                 { exit(0); }
	}
}

void TeacherFn(){
	TEACHER:

	system("CLS");

	char selector;
	
	Text("                Teacher", "\0", HeadingColor, true);
	Text("1. ", "View your Profile", OptionColor, true);
	Text("2. ", "Back"             , OptionColor, true);
	Text("3. ", "Exit"             , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '3') { goto AGAIN; }

	if      (selector == '1') { ProfileViewerFn(); }
	else if (selector == '2') { Administrator();   }
	else                      { exit(0);           }

	if (selector == '1') {
		cout << endl << endl;

		Text("1. ", "Back", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);

		again:
		selector = _getch();
		if (selector != '1' && selector != '2') { goto again; }

		if (selector == '1') { goto TEACHER; }
		else                 { exit(0); }
	}
}

void WorkersFn(){
	WORKER:

	system("CLS");

	char selector;

	Text( "                Workers", "\0", HeadingColor, true);
	Text("1. ", "View your Profile", OptionColor, true);
	Text("2. ", "Back"             , OptionColor, true);
	Text("3. ", "Exit"             , OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '3') { goto AGAIN; }

	if      (selector == '1') { ProfileViewerFn(); }
	else if (selector == '2') { Administrator();   }
	else                      { exit(0);           }

	if (selector == '1') {
		cout << endl << endl;

		Text("1. ", "Back", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);

	again:
		selector = _getch();
		if (selector != '1' && selector != '2') { goto again; }

		if (selector == '1') { goto WORKER; }
		else                 { exit(0);     }
	}
}

void StudentFn(){
	STUDENT:

	system("CLS");

	char selector;

	Text("             Students", "\0", HeadingColor, true);
	Text("1. ", "View your Profile", OptionColor, true);
	Text("2. ", "Back", OptionColor, true);
	Text("3. ", "Exit", OptionColor, true);
	Cursor(false);

	AGAIN:
	selector = _getch();
	if (selector < '1' || selector > '4') { goto AGAIN; }

	if      (selector == '1') { ProfileViewerFn(); }
	else if (selector == '2') { MainFn(); }
	else                      { exit(0); }

	if (selector == '1') {
		cout << endl << endl;

		Text("1. ", "Back", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);

		again:
		selector = _getch();
		if (selector != '1' && selector != '2') { goto again; }

		if (selector == '1') { goto STUDENT; }
		else                 { exit(0); }
	}
}

//This Funtion Store all Data of a Profile when it is login or Registered
void ProfileSetter(string Name, string FatherName, string Age, string Id, string Phone, string Email, string Password,
	string Address, string Program, string CGPA, string AdmissionYear, string RecentSmester, string FinalYear,
	string Droppingsemester, string FailSubject, string Experiance, string Education, string Field,
	string ProgramTeacher, string Work){

	Activated[0] = Name;
	Activated[1] = FatherName;
	Activated[2] = Age;
	Activated[3] = Id;
	Activated[4] = Phone;
	Activated[5] = Email;
	Activated[6] = Password;
	Activated[7] = Address;
	Activated[8] = Program;
	Activated[9] = CGPA;
	Activated[10] = AdmissionYear;
	Activated[11] = RecentSmester;
	Activated[12] = FinalYear;
	Activated[13] = Droppingsemester;
	Activated[14] = FailSubject;
	Activated[15] = Experiance;
	Activated[16] = Education;
	Activated[17] = Field;
	Activated[18] = ProgramTeacher;
	Activated[19] = Work;
}

//This Function Show all Data of Active Profile
void ProfileViewerFn(){
	system("CLS");

	Text("Name is                        = ", Activated[0], InfoColor, true);
	Text("Father is                      = ", Activated[1], InfoColor, true);
	Text("Age                            = ", Activated[2], InfoColor, true);
	Text("Id is                          = ", Activated[3], InfoColor, true);
	Text("Phone Number is                = ", Activated[4], InfoColor, true);
	Text("Email                          = ", Activated[5], InfoColor, true);
	Text("Password                       = ", Activated[6], InfoColor, true);
	Text("Addreess is                    = ", Activated[7], InfoColor, true);

	if (Activated[8] != "\0") {
		Text("Program is                     = ", Activated[8], InfoColor, true);
		Text("CGPA                           = ", Activated[9], InfoColor, true);
		Text("Admission Year                 = ", Activated[10], InfoColor, true);
	}
	else if (Activated[11] != "\0"){
		Text("Recent Semester                = ", Activated[11], InfoColor, true);
	}
	else if (Activated[12] != "\0"){
		Text("Final Year                     = ", Activated[12], InfoColor, true);
	}
	else if (Activated[13] != "\0"){
		Text("Dropping Semester              = ", Activated[13], InfoColor, true);
		Text("Failing Subject                = ", Activated[14], InfoColor, true);
	}
	else if (Activated[15] != "\0"){
		Text("Experiance                     = ", Activated[15], InfoColor, true);
		Text("Education                      = ", Activated[16], InfoColor, true);
	}
	else if (Activated[17] != "\0"){
		Text("Field                          = ", Activated[17], InfoColor, true);
	}
	else if (Activated[18] != "\0") {
		Text("Program                        = ", Activated[18], InfoColor, true);
	}
	else{
		Text("Work                           = ", Activated[19], InfoColor, true);
	}
}

//This Function Combines the File Handling Location(Declares and initialize at start of program) and File Name
string FileNamer(string FileName) {
	stringstream SemiName;
	string Name;

	SemiName << FileLocation << FileName;
	SemiName >> Name;

	return(Name);
}

//In this Program ID is automatically generated this Function make ID when a user register
string IdMaker(string FileName, string IdFirstCharacter) {
	int Counter = 0;
	int Count = 0;
	char Character = 'A';

	stringstream SemiId;
	string Id;

	FileName = FileNamer(FileName);

	ifstream DataReader;
	DataReader.open(FileName, ios::in);

	DataReader >> Counter;
	DataReader >> Count;
	DataReader >> Character;

	if (Count < 9) { SemiId << IdFirstCharacter << Character << "0" << Count; }
	else           { SemiId << IdFirstCharacter << Character << Count; }
	SemiId >> Id;

	ofstream DataWriter;
	DataWriter.open(FileName);

	Counter++;
	if (Count == 99) { Count = 0; Character++; }
	else             { Count++; }

	DataWriter << Counter << endl;
	DataWriter << Count << endl;
	DataWriter << Character;

	DataReader.close();
	DataWriter.close();

	cout << endl << endl;
	Text("You are registered", "\0", HeadingColor, true);
	Text("Your Id is                     = ", Id, InfoColor, true);
	Text("Remember this unique Id to login next time.", "\0", HeadingColor, true);
	cout << endl;
	Text("Press ENTER to continue.", "\0", HeadingColor, true);

	Cursor(false);

	AGAIN:
	if (_getch() != '\r') { goto AGAIN; }

	return(Id);
}

//In the program password entered is shown by stars( * ) this Function gets the Password
string GetPassword() {
	char Password[50];
	char Get;

	Cursor();

	for (int i = 0;;) {
		Get = _getch();

		if ((Get >= 'a' && Get <= 'z') || (Get >= 'A' && Get <= 'Z') || (Get >= '0' && Get <= '9')) {
			Password[i] = Get;
			cout << "*";
			i++;
		}
		else if (Get == '\b' && i > 0) {
			cout << "\b \b";
			i--;
		}
		else if (Get == '\r') {
			Password[i] = '\0';
			break;
		}
	}
	cout << endl;

	return(string(Password));
}

//This Function is friend between Owner class and Administration class And This class Search ID
void SearchID() {
	Owner ClsObj;

	bool Decider = 1;
	string ID;

	TRYAGAIN:
	Cursor();

	Text("Enter an ID to Search          = ", "\0", InfoColor, false);
	cin >> ID;

	system("CLS");

	if (
		 (ID.length() < 7) ||
		 (
		  (
		   (ID[0] != 'S' && ID[1] != 't' && ID[2] != 'u') ||
		   (ID[0] != 'A' && ID[1] != 'd' && ID[2] != 'm') ||
		   (ID[0] != 'T' && ID[1] != 'e' && ID[2] != 'c') ||
		   (ID[0] != 'W' && ID[1] != 'o' && ID[2] != 'r')
		  ) &&	
		   (ID[3] != '-')
		  )
		)
	{
		Text("ID entered is Wrong.", "\0", HeadingColor, true);
		Text("1. ", "Try Again", OptionColor, true);
		Text("2. ", "Exit", OptionColor, true);
		Cursor(false);

		char Selector;

		AGAIN:
		Selector = _getch();
		if (Selector < '1' || Selector > '2') { goto AGAIN; }

		if      (Selector == '1') { system("CLS"); goto TRYAGAIN; }
		else if (Selector == '2') { exit(0); }
	}
	else {
		ifstream ob;
		string FileName;

		if      (ID[0] == 'S') { FileName = FileNamer("DataBase//RecentStudents//RecentStudent.txt"); }
		else if (ID[0] == 'A') { FileName = FileNamer("DataBase//Admintration//Admin.txt"); }
		else if (ID[0] == 'T') { FileName = FileNamer("DataBase//Teachers//Teachers.txt"); }
		else if (ID[0] == 'W') { FileName = FileNamer("DataBase//Workers//Workers.txt"); }

		ob.open(FileName, ios::app);

		while (!ob.eof()) {
			getline(ob, ClsObj.ProfileStatus);
			getline(ob, ClsObj.Name);
			getline(ob, ClsObj.FatherName);
			getline(ob, ClsObj.Age);
			getline(ob, ClsObj.Id);
			getline(ob, ClsObj.Phone);
			getline(ob, ClsObj.Email);
			getline(ob, ClsObj.Address);
			getline(ob, ClsObj.Password);

			ClsObj.RecentSmester = "\0";
			ClsObj.Field = "\0";
			ClsObj.TeacherProgram = "\0";

			if      (ID[0] == 'S') {
				getline(ob, ClsObj.Program);
				getline(ob, ClsObj.CGPA);
				getline(ob, ClsObj.AdmissionYear);
				getline(ob, ClsObj.RecentSmester);
			}
			else if (ID[0] == 'A') {
				getline(ob, ClsObj.Experiance);
				getline(ob, ClsObj.Education);
				getline(ob, ClsObj.Field);
			}
			else if (ID[0] == 'T') {
				getline(ob, ClsObj.Experiance);
				getline(ob, ClsObj.Education);
				getline(ob, ClsObj.TeacherProgram);
			}
			else if (ID[0] == 'W') {
				getline(ob, ClsObj.Experiance);
				getline(ob, ClsObj.Education);
				getline(ob, ClsObj.Work);
			}

			if (ID == ClsObj.Id) {
				if (ClsObj.ProfileStatus == "1") { Text("The ID is Active", "\0", HeadingColor, true); }
				else                             { Text("The ID is Deactivated", "\0", HeadingColor, true); }

				Text("Name                           = ", ClsObj.Name, InfoColor, true);
				Text("Father Name                    = ", ClsObj.FatherName, InfoColor, true);
				Text("Age                            = ", ClsObj.Age, InfoColor, true);
				Text("ID                             = ", ClsObj.Id, InfoColor, true);
				Text("Phone Number                   = ", ClsObj.Phone, InfoColor, true);
				Text("Email Address                  = ", ClsObj.Email, InfoColor, true);
				Text("Address                        = ", ClsObj.Address, InfoColor, true);
				Text("Password                       = ", ClsObj.Password, InfoColor, true);

				if      (ClsObj.RecentSmester != "\0")  {
					Text("Program                        = ", ClsObj.Program, InfoColor, true);
					Text("CGPA                           = ", ClsObj.CGPA, InfoColor, true);
					Text("Admission Year                 = ", ClsObj.AdmissionYear, InfoColor, true);
					Text("Recent Semester                = ", ClsObj.RecentSmester, InfoColor, true);
				}
				else if (ClsObj.Field != "\0")          {
					Text("Experiance                     = ", ClsObj.Experiance, InfoColor, true);
					Text("Education                      = ", ClsObj.Education, InfoColor, true);
					Text("Field                          = ", ClsObj.Field, InfoColor, true);
				}
				else if (ClsObj.TeacherProgram != "\0") {
					Text("Experiance                     = ", ClsObj.Experiance, InfoColor, true);
					Text("Education                      = ", ClsObj.Education, InfoColor, true);
					Text("Teaching Program               = ", ClsObj.TeacherProgram, InfoColor, true);
				}
				else                                    {
					Text("Experiance                     = ", ClsObj.Experiance, InfoColor, true);
					Text("Education                      = ", ClsObj.Education, InfoColor, true);
					Text("Working Field                  = ", ClsObj.Work, InfoColor, true);
				}

				Decider = 0;
				break;
			}
		}
		if (Decider) { Text("        Profile not Found.", "\0", HeadingColor, true); }
	}
}

//Friend between Admin and Owner class
void ShowAllData(string Decider) {
	string FileName;

	if      (Decider == "Admin") { FileName = FileNamer("DataBase//Admintration//Admin.txt"); }
	else if (Decider == "Student") { FileName = FileNamer("DataBase//RecentStudents//RecentStudent.txt"); }
	else if (Decider == "Teachers") { FileName = FileNamer("DataBase//Teachers//Teachers.txt"); }
	else if (Decider == "Workers") { FileName = FileNamer("DataBase//Workers//Workers.txt"); }

	ifstream ob;
	ob.open(FileName, ios::app);

	Owner ClsOb;

	int i = 1;
	while (!ob.eof()) {
		getline(ob, ClsOb.ProfileStatus);
		getline(ob, ClsOb.Name);
		getline(ob, ClsOb.FatherName);
		getline(ob, ClsOb.Age);
		getline(ob, ClsOb.Id);
		getline(ob, ClsOb.Phone);
		getline(ob, ClsOb.Email);
		getline(ob, ClsOb.Address);
		getline(ob, ClsOb.Password);

		Text("                                 Data of ", "\0", HeadingColor, false);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << i;
		Text("'s Person ID", "\0", HeadingColor, true);

		if (ClsOb.ProfileStatus == "1") { cout << "This Account is Active" << endl; }
		else                      { cout << "This Profile is Disabled" << endl; }

		Text("Name                           = ", ClsOb.Name, InfoColor, true);
		Text("Father Name                    = ", ClsOb.FatherName, InfoColor, true);
		Text("Age                            = ", ClsOb.Age, InfoColor, true);
		Text("Id                             = ", ClsOb.Id, InfoColor, true);
		Text("Phone Number                   = ", ClsOb.Phone, InfoColor, true);
		Text("Email                          = ", ClsOb.Email, InfoColor, true);
		Text("Address                        = ", ClsOb.Password, InfoColor, true);
		Text("Password                       = ", ClsOb.Password, InfoColor, true);

		if (Decider == "Admin")  {
			getline(ob, ClsOb.Experiance);
			getline(ob, ClsOb.Education);
			getline(ob, ClsOb.Field);

			Text("Experiance                     = ", ClsOb.Experiance, InfoColor, true);
			Text("Education                      = ", ClsOb.Education, InfoColor, true);
			Text("Field                          = ", ClsOb.Field, InfoColor, true);
		}
		else if (Decider == "Student") {
			getline(ob, ClsOb.Program);
			getline(ob, ClsOb.CGPA);
			getline(ob, ClsOb.AdmissionYear);
			getline(ob, ClsOb.RecentSmester);

			Text("Program                        = ", ClsOb.Program, InfoColor, true);
			Text("CGPA                           = ", ClsOb.CGPA, InfoColor, true);
			Text("Admission Year                 = ", ClsOb.AdmissionYear, InfoColor, true);
			Text("Recent Semester                = ", ClsOb.RecentSmester, InfoColor, true);
		}
		else if (Decider == "Teachers") {
			getline(ob, ClsOb.Experiance);
			getline(ob, ClsOb.Education);
			getline(ob, ClsOb.TeacherProgram);

			Text("Experiance                     = ", ClsOb.Experiance, InfoColor, true);
			Text("Education                      = ", ClsOb.Education, InfoColor, true);
			Text("Teaching Program               = ", ClsOb.TeacherProgram, InfoColor, true);
		}
		else if (Decider == "Workers") {
			getline(ob, ClsOb.Experiance);
			getline(ob, ClsOb.Education);
			getline(ob, ClsOb.Work);

			Text("Experiance                     = ", ClsOb.Experiance, InfoColor, true);
			Text("Education                      = ", ClsOb.Education, InfoColor, true);
			Text("Working Field                  = ", ClsOb.Work, InfoColor, true);
		}
		cout << endl << endl;
		i++;
	}
	ob.close();
}

//Functioncout Colored statments
void Text(string Text1, string Text2, int Color, bool Decider) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color / 100);
	cout << Text1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color % 100);

	if (Text2 != "\0") { cout << Text2; }

	if (Decider) { cout << endl; }
}

//Cursor Hide/Show
void Cursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Music() {				//Plays Audio Files
	AGAIN:

	PlaySound(TEXT("E:\\DataBase\\qwe.wav"), NULL, SND_FILENAME | SND_LOOP);
	/*PlaySound(TEXT("E:/DataBase/Sounds/Black Horse.wav"), NULL, SND_FILENAME | SND_LOOP);
	PlaySound(TEXT("E:/DataBase/Sounds/Magical path.wav"), NULL, SND_FILENAME | SND_LOOP);
	PlaySound(TEXT("E:/DataBase/Sounds/Relaxing.wav"), NULL, SND_FILENAME | SND_LOOP);
	PlaySound(TEXT("E:/DataBase/Sounds/River.wav"), NULL, SND_FILENAME | SND_LOOP);*/

	goto AGAIN;
}


//This Function make Folders
void DirectoryMakerFn() {
	string Folder;

	Folder = FileNamer("DataBase");
	_mkdir(Folder.c_str());

	Folder = FileNamer("DataBase//RecentStudents");
	_mkdir(Folder.c_str());

	Folder = FileNamer("DataBase//Teachers");
	_mkdir(Folder.c_str());

	Folder = FileNamer("DataBase//Admintration");
	_mkdir(Folder.c_str());

	Folder = FileNamer("DataBase//Workers");
	_mkdir(Folder.c_str());
}
