#include <iostream> 
#include <string> 
using namespace std;
class Admin;
class User;
class Teacher;
class Student;
class Date;
class Grade;

void Main();

//date class starts

class Date
{
protected:
	int month, day, year;
public:
	Date();

	Date(int Month, int Day, int Year);

	void setDay(int d);

	void setMonth(int m);

	void setYear(int y);

	string Tostring();

	friend inline istream& operator>>(istream& in, Date& x);

};



//Grade class starts



class Grade
{
protected:
	double mid, mid_total, ses, ses_total, final, final_total;
	string sess, mids, finals, gra;
public:
	Grade();

	Grade(double m, double s, double f, string c, double mt, double st, double ft);

	double getMid();

	double getSessional();

	double getFinal();

	double getMid_total();

	double getSessional_total();

	double getFinal_total();

	string getGrade();

	string get_Mid();

	string get_Sessional();

	string get_Final();

	string get_Grade();

	friend inline istream& operator>>(istream &str, Grade &inp);

	string Calculate_Grade();

	void ToString();

};







//user class starts







class User
{
protected:
	string Username;
	string Password;
public:
	virtual string Attendance_show_update() = 0;
	virtual string Grades_show_update() = 0;
	virtual string Change_Password() = 0;
	virtual bool check() = 0;
	virtual void Show_Data() = 0;
};






//student class starts



class Student :public User
{
protected:
	string Roll_no;
public:
	Student();

	Student(string username, string password, string roll_no);

	void Show_Data();

	string Attendance_show_update();

	string Grades_show_update();

	string Change_Password();

	string get_username();

	string get_password();

	void set_username(string username);

	void set_password(string password);

	string get_Roll_no();
	
	void set_Roll_no(string Roll);
	
	bool check();

	friend inline istream& operator>>(istream &str, Student &inp);

};







//teacher class starts





class Teacher :public User
{
protected:
	string Subject;
public:
	Teacher();

	Teacher(string username, string password, string subject);

	void Show_Data();

	string Attendance_show_update();

	string Grades_show_update();

	bool check();

	string Change_Password();

	string get_username();

	string get_password();

	string get_subject();

	void set_subject(string subject);

	void set_username(string username);

	void set_password(string password);

	friend inline istream& operator>>(istream &str, Teacher &inp);

};







//admin class starts







class Admin
{
protected:
	string Username;
	string Password;

public:
	Admin();

	string Change_password();

	string get_username();

	string get_password();

	void set_username(string username);

	void set_password(string password);

	Admin(string username, string password);

	string Add_Teacher();

	string Remove_Teacher();

	string Add_Student();

	string  Remove_Student();
	
	friend inline istream& operator>>(istream &str, Admin &inp);
	
};