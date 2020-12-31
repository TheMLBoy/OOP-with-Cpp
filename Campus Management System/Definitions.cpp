#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "database.h"
#include "PHeader.h"

void Main()
{
RE:
	system("COLOR 48");		//Color to change background
	int menu;
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\t\t||\t1. Admin                                ||\n";
	cout << "\t\t||\t2. Teacher                              ||\n";
	cout << "\t\t||\t3. Student                              ||\n";
	cout << "\t\t||\t4. Exit                                 ||\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\n\t\tMake Your choice: ";
	char des;
	des = _getche();
	User *base;
	if (des == '1')
	{
	admin:
		Admin obj;
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cin >> obj;
		if (obj.get_username() == "Admin" && obj.get_password() == "Admin")
		{
		adminm:
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\t\t||\t1. To add Teacher                        ||\n";
			cout << "\t\t||\t2. To remove Teacher                     ||\n";
			cout << "\t\t||\t3. To add Student                        ||\n";
			cout << "\t\t||\t4. To remove Student                     ||\n";
			cout << "\t\t||\t5. To change password                    ||\n";
			cout << "\t\t||\t6. Exit                                  ||\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tMake Your choice: ";
			char opt;
		Re:
			opt = _getche();
			switch (opt)
			{
			case '1':
				cout << obj.Add_Teacher();
				break;
			case '2':
				cout << obj.Remove_Teacher();
				break;
			case '3':
				cout << obj.Add_Student();
				break;
			case '4':
				cout << obj.Remove_Student();
				break;
			case '5':
				cout << obj.Change_password();
				break;
			case '6':
				goto EXIT;
				break;
			default:
				system("cls");
				cout << "\t\t\t    College Management System \n";
				cout << "\t\t==================================================\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\n\n\t\tWrong Input!!!.";
				cout << "\n\n\t\t--------------------------------------------------\n\t\t";
				Sleep(1200);
				goto Re;

			}
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tPress '1' to Return To Main menu .";
			cout << "\n\n\n\t\t--------------------------------------------------\n";
			char ret;
			ret = _getche();
			if (ret == '1')
			{
				goto adminm;
			}
		}
		else
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tAdmin not found.";
			cout << "\n\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			goto admin;
		}
	}
	else if (des == '2')
	{
	prof:
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		base = new Teacher();
		Teacher *pDerived = dynamic_cast<Teacher*>(base);
		cout << "\n\n\t\tEnter Username: ";
		string temp;
		cin >> temp;
		pDerived->set_username(temp);
		cout << "\n\n\t\tEnter Password: ";
		temp = "";
		char enter, ch;
		enter = 13;
		ch = _getch();
		while (ch != enter)
		{
			if (ch == enter)
			{
				break;
			}
			temp.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		pDerived->set_password(temp);
		cout << "\n\n\t\tEnter Subject: ";
		cin >> temp;
		pDerived->set_subject(temp);
		if (base->check() == 1)
		{
		profin:
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\t\t||\t1. Attendance      \t\t\t||\n";
			cout << "\t\t||\t2. Grades          \t\t\t||\n";
			cout << "\t\t||\t3. Change Password \t\t\t||\n";
			cout << "\t\t||\t4. Show Data       \t\t\t||\n";
			cout << "\t\t||\t5. Exit            \t\t\t||\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tMake Your choice: ";
			char cho;
			cho = _getche();
			switch (cho)
			{
			case '1':
				cout << base->Attendance_show_update();
				break;
			case'2':
				cout << base->Grades_show_update();
				break;
			case'3':
				cout << base->Change_Password();
				break;
			case'4':
				base->Show_Data();
				break;
			case'5':
				goto EXIT;
				break;
			default:
				system("cls");
				cout << "\t\t\t    College Management System \n";
				cout << "\t\t==================================================\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\n\n\t\tWrong Input!!!.";
				cout << "\n\n\t\t--------------------------------------------------\n\t\t";
				Sleep(1200);
				goto profin;
			}
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tPress '1' to Return To Main menu .";
			cout << "\n\n\n\t\t--------------------------------------------------\n";
			char ret;
			ret = _getche();
			if (ret == '1')
			{
				goto profin;
			}
		}
		else
		{
			system("cls");
			goto prof;
		}
	}
	else if (des == '3')
	{
	stu:
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		base = new Student();
		string temp;
		Student *pDerived = dynamic_cast<Student*>(base);
		cout << "\n\n\t\tEnter Username: ";
		cin >> temp;
		pDerived->set_username(temp);
		cout << "\n\n\t\tEnter Password: ";
		temp = "";
		char enter, ch;
		enter = 13;
		ch = _getch();
		while (ch != enter)
		{
			if (ch == enter)
			{
				break;
			}
			temp.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		pDerived->set_password(temp);
		cout << "\n\n\n\t\tEnter Roll_no: ";
		cin >> temp;
		pDerived->set_Roll_no(temp);
		if (base->check() == 1)
		{
		stuin:
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\t\t||\t1. Attendance      \t\t\t ||\n";
			cout << "\t\t||\t2. Grades          \t\t\t ||\n";
			cout << "\t\t||\t3. Change Password \t\t\t ||\n";
			cout << "\t\t||\t4. Show Data       \t\t\t ||\n";
			cout << "\t\t||\t5. Exit            \t\t\t ||\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tMake Your choice: ";
			char cho1;
			cho1 = _getche();
			switch (cho1)
			{
			case '1':
				cout << base->Attendance_show_update();
				break;
			case'2':
				cout << base->Grades_show_update();
				break;
			case'3':
				cout << base->Change_Password();
				break;
			case'4':
				base->Show_Data();
				break;
			case'5':
				goto EXIT;
				break;
			default:
				system("cls");
				cout << "\t\t\t    College Management System \n";
				cout << "\t\t==================================================\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\n\n\t\tWrong Input!!!.";
				cout << "\n\n\t\t--------------------------------------------------\n\t\t";
				Sleep(1200);
				goto stuin;
			}
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tPress '1' to Return To Main menu .";
			cout << "\n\n\n\t\t--------------------------------------------------\n";
			char ret;
			ret = _getche();
			if (ret == '1')
			{
				goto stuin;
			}
		}
		else
		{
			system("cls");
			goto stu;
		}
	}
	else if (des == '4')
	{
		goto EXIT;
	}
	else
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tWrong Input!!!.";
		cout << "\n\n\t\t--------------------------------------------------\n\t\t";
		Sleep(1200);
		goto RE;
	}
EXIT:
	cout << "\n\n\t\t";
}

Date::Date()
{
	month = 0, day = 0, year = 0;
}

Date::Date(int Month, int Day, int Year)
{
	month = Month;
	day = Day;
	year = Year;
}

void Date::setDay(int d)
{
	if (d < 1 && d > 31)
		cout << "The day is invalid" << endl;
	else
		day = d;
}

void Date::setMonth(int m)
{
	if (m < 1 && m > 12)
		cout << "The month is invalid" << endl;
	else
		month = m;

}

void Date::setYear(int y)
{
	if (y <2018 && y> 2019)
		cout << "The year is invalid" << endl;
	else
		year = y;
}

string Date::Tostring()
{
	stringstream ss;
	ss << year << "-" << month << "-" << day;
	string ret;
	ss >> ret;
	return ret;
}

Grade::Grade()
{
	mid = 0;
	ses = 0;
	final = 0;
	mid_total = 0;
	ses_total = 0;
	final_total = 0;
	gra = "F";
}
Grade::Grade(double m, double s, double f, string c, double mt, double st, double ft)
{
	mid = (m / mt) * 35;
	ses = (s / st) * 25;
	final = (f / ft) * 40;
	gra = c;
}
double Grade::getMid()
{
	return mid;
}
double Grade::getSessional()
{
	return ses;

}
double Grade::getFinal()
{
	return final;

}
double Grade::getMid_total()
{
	return mid;
}
double Grade::getSessional_total()
{
	return ses;

}
double Grade::getFinal_total()
{
	return final;

}
string Grade::getGrade()
{
	return gra;
}
string Grade::get_Mid()
{
	return mids;
}
string Grade::get_Sessional()
{
	return sess;
}
string Grade::get_Final()
{
	return finals;
}
string Grade::get_Grade()
{
	return gra;
}

string Grade::Calculate_Grade()
{
	double total = mid + ses + final;
	if (total >= 85)
	{
		gra = "A";
	}
	else if (total >= 80 && total <85)
	{
		gra = "A-";
	}
	else if (total >= 75 && total <80)
	{
		gra = "B+";
	}
	else if (total >= 70 && total <75)
	{
		gra = "B";
	}
	else if (total >= 65 && total <70)
	{
		gra = "B-";
	}
	else if (total >= 61 && total <65)
	{
		gra = "C+";
	}
	else if (total >= 58 && total <61)
	{
		gra = "C";
	}
	else if (total >= 55 && total <58)
	{
		gra = "C-";
	}
	else if (total >= 50 && total <55)
	{
		gra = "D";
	}
	else
	{
		gra = "F";
	}
	return gra;
}
void Grade::ToString()
{
	stringstream ss;
	ss << ses;
	ss >> sess;
	stringstream s1, s2;
	s1 << mid;
	s1 >> mids;
	s2 << final;
	s2 >> finals;
}


Student::Student()
{
	Roll_no = "";
	Username = "";
	Password = "";
}
Student::Student(string username, string password, string roll_no)
{
	Username = username;
	Password = password;
	Roll_no = roll_no;
}

void Student::Show_Data()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	string c;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	c = "select * from Student Where Username=\"" + Username + "\" ;";
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	while (rslt->next())
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\t\t||\tName:     \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(1) << "||\n";
		cout << "\t\t||\tPassword: \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(2) << "||\n";
		cout << "\t\t||\tSubject:  \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(3) << "||\n";
		cout << "\t\t--------------------------------------------------\n";
	}
	cout << "\n\t\tPress any key to exit from this page.\n";
	char a;
	a = _getch();
	conn.close();
}

string Student::Attendance_show_update()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\n\t\tSelect from following subjects: \n";
	Connection conn;
	string c, c1, c2, sub;
	int i = 0;
	char a;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	stmt->execute(c.c_str());
	c = "select Subject from " + Username + ";";
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	while (rslt->next())
	{
		i++;
		stringstream ss;
		ss << i;
		string opt, dis;
		ss >> opt;
		dis = "\n\n\t\t" + opt + "-  " + rslt->getString(1);
		cout << endl << dis;
	}
	cout << "\n\n\t\t--------------------------------------------------\n";
	int option;
	cout << endl << "\n\t\t";
	cin >> option;
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	c = "select Subject from " + Username + ";";
	rslt = stmt->executeQuery(c.c_str());
	r_mtdt = rslt->getMetaData();
	i = 0;
	while (rslt->next())
	{
		i++;
		if (i == option)
		{
			c2 = rslt->getString(1);
			break;
		}
	}
	c1 = Username + "_" + c2;
	c = "select * from " + c1 + ";";
	rslt = stmt->executeQuery(c.c_str());
	r_mtdt = rslt->getMetaData();
	cout << "\n\n\t\t\t" << left << setw(25) << "Date" << left << setw(10) << "Attendance\n\n";
	while (rslt->next())
	{
		cout << "\n\t\t\t" << left << setw(25) << rslt->getString(1) << left << setw(10) << rslt->getString(2);
	}
	cout << "\n\t\t--------------------------------------------------\n";
	cout << "\n\t\tPress any key to exit from this page.\n";
	a = _getch();
	conn.close();
	return " ";
}

string Student::Grades_show_update()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Connection conn;
	string c;
	char a;
	c = "select * from " + Username + " ;";
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	cout << endl;
	cout << "\t\tSubjects      " << "Sessionals    " << "Mids    " << "Finals    " << "Grade    " << endl;
	while (rslt->next())
	{
		cout << "\n\t\t" << left << setw(14) << rslt->getString(1);
		cout << left << setw(14) << rslt->getString(2);
		cout << left << setw(8) << rslt->getString(3);
		cout << left << setw(10) << rslt->getString(4);
		cout << left << setw(9) << rslt->getString(5);
		cout << endl;
	}
	conn.close();
	cout << "\n\t\t--------------------------------------------------\n";
	cout << "\n\t\tPress any key to exit from this page.\n";
	a = _getch();
	return " ";
}

string Student::Change_Password()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	string c, new_password, old_password;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	cout << "\n\n\t\tEnter old Password: ";
	cin >> old_password;
	cout << "\n\n\t\tEnter new Password: ";
	cin >> new_password;
	c = "UPDATE Student SET Password =\"" + new_password + "\" WHERE Username=\"" + Username + "\" and Password=\"" + old_password + "\" ;";
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) >= 1)
			throw 0;
		else
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tPassword Successfully Changed.";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
	}
	catch (int x)
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tSomething went wrong. Please Try again..!!";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return " ";
	}
	conn.close();
}
string Student::get_username()
{
	return Username;
}
string Student::get_password()
{
	return Password;
}
void Student::set_username(string username)
{
	this->Username = username;
}
void Student::set_password(string password)
{
	Password = password;
}
string Student::get_Roll_no()
{
	return Roll_no;
}
void Student::set_Roll_no(string Roll)
{
	this->Username = Roll;
}

bool Student::check()
{
	system("cls");
	string c;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	c = "UPDATE Student SET Password =\"" + Password + "\" WHERE Username=\"" + Username + "\" and Password=\"" + Password + "\" ;";
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) != 1)
			throw 0;
		else
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tSuccessfully Loged in.";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return 1;
		}
	}
	catch (int x)
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tUser not found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return 0;
	}
	conn.close();
}

Teacher::Teacher()
{
	Subject = "";
	Username = "";
	Password = "";
}
Teacher::Teacher(string username, string password, string subject)
{
	Username = username;
	Password = password;
	Subject = subject;
}

void Teacher::Show_Data()
{
	system("cls");
	string c;
	char a;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	c = "select * from Teacher Where Username=\"" + Username + "\" ;";
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	while (rslt->next())
	{
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\t\t||\tName:     \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(1) << "||\n";
		cout << "\t\t||\tPassword: \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(2) << "||\n";
		cout << "\t\t||\tSubject:  \t\t\t        ||\n";
		cout << "\t\t||\t\t\t" << left << setw(24) << rslt->getString(3) << "||\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\t\tPress any key to exit this page.\n";
		a = _getch();
	}
	conn.close();
}

string Teacher::Attendance_show_update()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Connection conn;
	Statement* stmt;
	ResultSet* rslt;
	ResultSetMetaData* r_mtdt;
	string c, c1, c2;
	int i = 0;
	cout << "\n\n\t\t1- To Mark Attendance.";
	cout << "\n\n\t\t2- To Show Attendance.\n\n";
	cout << "\n\n\t\t--------------------------------------------------\n";
	char opt, a;
	string sub, n, at;
	Date d;
Re:
	a = _getche();
	switch (a)
	{
	case '1':
		cin >> d;
		conn.open("CMS.db"); // the argument is the database name.
		stmt = conn.createStatement();
		c = "select Username from Student;";
		rslt = stmt->executeQuery(c.c_str());
		r_mtdt = rslt->getMetaData();
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << endl << "\n\t\tMark Attendance of ('1' for Present and '0' for absent.)";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		while (rslt->next())
		{
			cout << endl << "\n\t\tMark Attendance of ' " << rslt->getString(1) << " '\t\t" << endl << "\t\t";
			cin >> at;
			c1 = rslt->getString(1) + "_" + Subject;
			c = "insert into " + c1 + " values (\"" + d.Tostring() + "\"," + at + ")";
			stmt->execute(c.c_str());
		}
		cout << "\n\t\t--------------------------------------------------\n";
		break;
	case '2':
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tEnter Student Name of which Attendance You want to see: ";
		cin >> n;
		cout << "\n\t\t--------------------------------------------------\n";
		c1 = n + "_" + Subject;
		c = "select * from " + c1 + " ;";
		conn.open("CMS.db"); // the argument is the database name.
		stmt = conn.createStatement();
		rslt = stmt->executeQuery(c.c_str());
		r_mtdt = rslt->getMetaData();
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\t\t" << left << setw(25) << "Date" << left << setw(10) << "Attendance\n\n";
		while (rslt->next())
		{
			cout << "\n\t\t\t" << left << setw(25) << rslt->getString(1) << left << setw(10) << rslt->getString(2);
		}
		cout << "\n\t\t--------------------------------------------------\n";
		break;
	default:
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tUser not found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		goto Re;
	}
	conn.close();
	cout << "\n\n\t\tPress ant key to exit this page.";
	char a1;
	a1 = _getch();
	return " ";
}

string Teacher::Grades_show_update()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Connection conn;
	Statement* stmt;
	ResultSet* rslt;
	ResultSetMetaData* r_mtdt;
	string c, c1, c2;
	int i = 0;
	cout << "\n\n\t\t1- To Mark Grades.";
	cout << "\n\n\t\t2- To Show Grades.";
	cout << "\n\t\t--------------------------------------------------\n\t\t";
	char opt, a;
	string sub, n, at;
	Grade g;
Re:
	a = _getche();
	switch (a)
	{
	case '1':
		conn.open("CMS.db"); // the argument is the database name.
		stmt = conn.createStatement();
		c = "select Username from Student;";
		rslt = stmt->executeQuery(c.c_str());
		r_mtdt = rslt->getMetaData();
		while (rslt->next())
		{
			c1 = rslt->getString(1);
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << endl << "\n\n\t\tMark Grades of " << rslt->getString(1) << "\n\t\t";
			cin >> g;
			g.ToString();
			c = "update " + c1 + " set Sessional=" + g.get_Sessional() + ", Mid=" + g.get_Mid() + " , Final=" + g.get_Final() + " ,Grade=\"" + g.Calculate_Grade() + "\" where Subject=\"" + Subject + "\";";
			stmt->execute(c.c_str());
		}
		break;
	case '2':
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tEnter Student Name of which Grades You want to see: ";
		cin >> n;
		c = "select Sessional, Mid, Final, Grade from " + n + " where Subject=\"" + Subject + "\";";
		conn.open("CMS.db"); // the argument is the database name.
		stmt = conn.createStatement();
		rslt = stmt->executeQuery(c.c_str());
		r_mtdt = rslt->getMetaData();
		while (rslt->next())
		{
			cout << "\n\n\t\tSessionals: \n\t\t\t\t" << rslt->getString(1);
			cout << "\n\t\tMids:   \n\t\t\t\t" << rslt->getString(2);
			cout << "\n\t\tFinals: \n\t\t\t\t" << rslt->getString(3);
			cout << "\n\t\tGrade:  \n\t\t\t\t" << rslt->getString(4);
			cout << endl;
		}
		cout << "\n\t\t--------------------------------------------------\n";
		break;
	default:
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tStudent not found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		goto Re;
	}
	conn.close();
	cout << "\n\n\t\tPress ant key to exit this page.";
	char a1;
	a1 = _getch();
	return " ";

}
bool Teacher::check()
{
	string c;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	c = "UPDATE Teacher SET Password =\"" + Password + "\" WHERE Username=\"" + Username + "\" and Password=\"" + Password + "\" and Subject=\"" + Subject + "\" ;";
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) != 1)
			throw 0;
		else
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tSuccessfully Loged in.";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return 1;
		}
	}
	catch (int x)
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tUser not found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return 0;
	}
}
string Teacher::Change_Password()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	string c, new_password, old_password;
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	cout << "\n\n\t\tEnter old Password: ";
	cin >> old_password;
	cout << "\n\n\t\tEnter new Password: ";
	cin >> new_password;
	cout << "\n\t\t--------------------------------------------------\n";
	c = "UPDATE Teacher SET Password =\"" + new_password + "\" WHERE Username=\"" + Username + "\" and Password=\"" + old_password + "\" ;";
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) != 1)
			throw 0;
		else
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tPassword Successfully Changed.";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
	}
	catch (int x)
	{
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tSomething went wrong. Please Try again..!!";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return " ";
	}
}
string Teacher::get_username()
{
	return Username;
}
string Teacher::get_password()
{
	return Password;
}
string Teacher::get_subject()
{
	return Subject;
}
void Teacher::set_subject(string subject)
{
	this->Subject = subject;
}
void Teacher::set_username(string username)
{
	this->Username = username;
}
void Teacher::set_password(string password)
{
	Password = password;
}


Admin::Admin()
{
	this->Username = "";
	this->Password = "";
}

string Admin::Change_password()
{
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\n\t\t1-Teacher. ";
	cout << "\n\n\t\t2-Student. ";
	cout << "\n\n\t\t--------------------------------------------------\n";
	char opt;
	string c, name, new_password;
R:
	opt = _getche();
	Connection conn;
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	switch (opt)
	{
	case '1':
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tEnter Teacher's Name: ";
		cin >> name;
		cout << "\n\n\t\tEnter New Password: ";
		cin >> new_password;
		c = "UPDATE Teacher SET Password =\"" + new_password + "\" WHERE Username=(\"" + name + "\");";

		//stmt->execute(c.c_str());
		try
		{
			if (stmt->execute(c.c_str()) != 1)
				throw 0;
			else
			{
				system("cls");
				cout << "\t\t\t    College Management System \n";
				cout << "\t\t==================================================\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\n\n\t\tPassword Changed Successfully.";
				cout << "\n\t\t--------------------------------------------------\n";
				Sleep(1200);
				return " ";
			}
		}
		catch (int x)
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tSomething went wrong. Please Try again..!!";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
		break;
	case '2':
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\tEnter Student's Name:  ";
		cin >> name;
		cout << "\n\n\t\tEnter New Password:  ";
		cin >> new_password;
		cout << "\t\t--------------------------------------------------\n";
		c = "UPDATE Student SET Password =\"" + new_password + "\" WHERE Username=(\"" + name + "\");";
		//stmt->execute(c.c_str());
		try
		{
			if (stmt->execute(c.c_str()) != 1)
				throw 0;
			else
			{
				system("cls");
				cout << "\t\t\t    College Management System \n";
				cout << "\t\t==================================================\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\n\n\t\tPassword Changed Successfully.";
				cout << "\n\t\t--------------------------------------------------\n";
				Sleep(1200);
				return " ";
			}
		}
		catch (int x)
		{
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\n\t\tSomething went wrong. Please Try again..!!";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
		break;
	default:
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\n\t\t Wrong input!!";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		goto R;
	}
}

string Admin::get_username()
{
	return Username;
}
string Admin::get_password()
{
	return Password;
}
void Admin::set_username(string username)
{
	this->Username = username;
}
void Admin::set_password(string password)
{
	Password = password;
}


Admin::Admin(string username, string password)
{
	this->Username = username;
	this->Password = password;
}

string Admin::Add_Teacher()
{
	Connection conn;
	system("cls");
	string c;
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Teacher add;
	cin >> add;
	c = "insert into Teacher values(\"" + add.get_username() + "\",\"" + add.get_password() +
		"\",\"" + add.get_subject() + "\");";
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	stmt->execute(c.c_str());
	c = "select Username from Student;";
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	while (rslt->next())
	{
		string a = rslt->getString(1);
		c = "INSERT INTO " + a + " (Subject) VALUES(\"" + add.get_subject() + "\")";
		stmt->execute(c.c_str());
		string a1 = a + "_" + add.get_subject();
		c = "create table " + a1 + " (Date DATE, " + add.get_subject() + " BOOLEAN);";
		stmt->execute(c.c_str());
	}
	conn.close();
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\n\t\tTeacher Successfully added. ";
	cout << "\n\t\t--------------------------------------------------\n";
	Sleep(1200);
	return " ";
}

string Admin::Remove_Teacher()
{

	Connection conn;
	system("cls");
	string c;
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Teacher remove;
	cin >> remove;
	c = "DELETE FROM Teacher WHERE Username=(\"" + remove.get_username() + "\");";
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) != 1)
			throw 0;
		else
		{
			c = "select Username from Student;";
			ResultSet* rslt = stmt->executeQuery(c.c_str());
			ResultSetMetaData* r_mtdt = rslt->getMetaData();
			while (rslt->next())
			{
				string a = rslt->getString(1);
				c = "delete from " + a + " where Subject=\"" + remove.get_subject() + "\" ;";
				stmt->execute(c.c_str());
				string a1 = a + "_" + remove.get_subject();
				c = "DROP TABLE " + a1 + " ;";
				cout << c;
				stmt->execute(c.c_str());
			}
			conn.close();
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\t\tSuccessfuly Removed Teacher.";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
	}
	catch (int x)
	{
		conn.close();
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\t\tNo such Teacher found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return " ";
	}
}

string Admin::Add_Student()
{
	Connection conn;
	system("cls");
	string c, c1;
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	Student add;
	cin >> add;
	c = "insert into Student values(\"" + add.get_username() + "\",\"" + add.get_password() +
		"\",\"" + add.get_Roll_no() + "\");";
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	stmt->execute(c.c_str());
	c = "create table " + add.get_username() + "(Subject TEXT, Sessional INT, Mid INT ,Final INT,Grade TEXT); ";
	stmt->execute(c.c_str());
	c = "select Subject from Teacher;";
	ResultSet* rslt = stmt->executeQuery(c.c_str());
	ResultSetMetaData* r_mtdt = rslt->getMetaData();
	while (rslt->next())
	{
		string a = rslt->getString(1);
		c = "insert into " + add.get_username() + "(Subject) values(\"" + a + "\"); ";
		stmt->execute(c.c_str());
		c1 = add.get_username() + "_" + a;
		c = "create table " + c1 + " (Date DATE , " + a + " BOOLEAN);";
		stmt->execute(c.c_str());
	}
	conn.close();
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\t\tStudent Successfully added. ";
	cout << "\n\t\t--------------------------------------------------\n";
	Sleep(1200);
	return " ";
}

string  Admin::Remove_Student()
{
	Connection conn;
	system("cls");
	string c, c1;
	Student remove;
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cin >> remove;
	c = "DELETE FROM Student WHERE Roll_no=(\"" + remove.get_Roll_no() + "\");";
	conn.open("CMS.db"); // the argument is the database name.
	Statement* stmt = conn.createStatement();
	//stmt->execute(c.c_str());
	try
	{
		if (stmt->execute(c.c_str()) != 1)
			throw 0;
		else
		{
			c = "select Subject from Teacher ;";
			ResultSet* rslt = stmt->executeQuery(c.c_str());
			ResultSetMetaData* r_mtdt = rslt->getMetaData();
			while (rslt->next())
			{
				string a = rslt->getString(1);
				c1 = remove.get_username() + "_" + a;
				c = "DROP TABLE " + c1 + " ;";
				cout << stmt->execute(c.c_str());
			}
			c = "DROP TABLE " + remove.get_username() + " ; ";
			stmt->execute(c.c_str());
			conn.close();
			system("cls");
			cout << "\t\t\t    College Management System \n";
			cout << "\t\t==================================================\n\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "\n\t\tStudent Successfully removed. ";
			cout << "\n\t\t--------------------------------------------------\n";
			Sleep(1200);
			return " ";
		}
	}
	catch (int x)
	{
		conn.close();
		system("cls");
		cout << "\t\t\t    College Management System \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\n\t\tNo such Student found.";
		cout << "\n\t\t--------------------------------------------------\n";
		Sleep(1200);
		return " ";
	}
}

inline istream& operator>>(istream& in, Date& x)
{
d:
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\n\t\tPlease Enter Date: ";
	cout << "\n\n\t\tEnter Day: ";
	in >> x.day;
	if (x.day<0 || x.day>31)
	{
		cout << "\nInvalid day!!!\n";
		Sleep(1000);
		goto d;
	}
m:
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\t\tEnter Month: ";
	in >> x.month;
	if (x.month<0 || x.month>12)
	{
		cout << "\nInvalid month!!!\n";
		Sleep(1000);
		goto m;
	}
y:
	system("cls");
	cout << "\t\t\t    College Management System \n";
	cout << "\t\t==================================================\n\n";
	cout << "\t\t--------------------------------------------------\n";
	cout << "\n\t\tEnter Year: ";
	in >> x.year;
	if (x.year<2018 || x.year>2019)
	{
		cout << "\n\n\t\tInvalid year!!!\n";
		Sleep(1000);
		goto y;
	}
	return in;
}

inline istream& operator>>(istream &str, Grade &inp)
{
	cout << "\n\n\t\tEnter Midterm Marks: ";
	str >> inp.mid;
	cout << "\n\n\t\tEnter Midterm Total Marks: ";
	str >> inp.mid_total;
	cout << "\n\n\t\tEnter Sessionals: ";
	str >> inp.ses;
	cout << "\n\n\t\tEnter Sessionals Total Marks: ";
	str >> inp.ses_total;
	cout << "\n\n\t\tEnter Final Marks: ";
	str >> inp.final;
	cout << "\n\n\t\tEnter Final Marks: ";
	str >> inp.final_total;
	inp.mid = (inp.mid / inp.mid_total) * 35;
	inp.ses = (inp.ses / inp.ses_total) * 25;
	inp.final = (inp.final / inp.final_total) * 40;
	return str;
}

inline istream& operator>>(istream &str, Student &inp)
{
	cout << "\n\t\tEnter Username:  ";
	str >> inp.Username;
	cout << "\n\t\tEnter Password:  ";
	str >> inp.Password;
	cout << "\n\t\tEnter Roll_no:  ";
	str >> inp.Roll_no;
	return str;
}

inline istream& operator>>(istream &str, Teacher &inp)
{
	cout << "\n\t\tEnter Username: ";
	str >> inp.Username;
	cout << "\n\t\tEnter Password: ";
	str >> inp.Password;
	cout << "\n\t\tEnter Subject: ";
	str >> inp.Subject;
	return str;
}

inline istream& operator>>(istream &str, Admin &inp)
{
	cout << "\n\n\t\tEnter Username: ";
	str >> inp.Username;
	cout << "\n\n\t\tEnter Password: ";
	inp.Password = "";
	char enter, ch;
	enter = 13;
	ch = _getch();
	while (ch != enter)
	{
		if (ch == enter)
		{
			break;
		}
		inp.Password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	return str;
}
