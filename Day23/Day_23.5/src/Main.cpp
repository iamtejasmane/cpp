#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;	//24 bytes
	int age;		//4 bytes
public:
	Person( void )
	{
		this->name = "";
		this->age = 0;
	}
	Person( string name, int age )
	{
		this->name = name;
		this->age = age;
	}
	void printRecord( void )
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Age	:	"<<this->age<<endl;
	}
};
class Employee : public Person
{
private:
	int empid;		//4 bytes
	float salary;   //4 bytes
public:
	Employee( void )
	{
		this->empid = 0;
		this->salary = 0;
	}
	Employee( string name, int age, int empid, float salary ) : Person(name, age)
	{
		this->empid = empid;
		this->salary = salary;
	}
	void printRecord( void )
	{
		Person::printRecord();
		cout<<"Empid	:	"<<this->empid<<endl;
		cout<<"Salary	:	"<<this->salary<<endl;
	}
};
int main( void )
{
	Employee emp("Sandeep", 36, 42,23456);
	emp.printRecord();
	//emp.Person::printRecord();
	//emp.Employee::printRecord();
	return 0;
}
