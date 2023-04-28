#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string name, date_of_birth, countryside;
public:
	void set_info(string name, string date_of_birth, string countryside) {
		this->name = name;
		this->date_of_birth = date_of_birth;
		this->countryside = countryside;
	}
	string getname() {
		return name;
	}
	string getdate_of_birth() {
		return date_of_birth;
	}
	string getcountryside() {
		return countryside;
	}
};

class Engineer:public Person {
private:
	string uni;
	int graduate_year;
public:
	friend istream& operator >> (istream&, Engineer&);
	friend ostream& operator << (ostream&, Engineer);
};



istream& operator >> (istream& is, Engineer& A) {
	string name, date_of_birth, countryside;
	cout << "Nhap ho va ten: ";
	getline(is, name);
	cout << "Nhap ngay thang nam sinh: ";
	is >> date_of_birth;
	cout << "Nhap que quan: ";
	cin.ignore();
	getline(is, countryside);
	A.set_info(name, date_of_birth, countryside);
	cout << "Nhap truong dai hoc: ";
	is >> A.uni;
	cout << "Nhap nam tot nghiep: ";
	is >> A.graduate_year;
	return is;
}


ostream& operator << (ostream& os, Engineer A) {
	os << "Ho va ten: " << A.getname() << endl;
	os << "Ngay thang nam sinh: " << A.getdate_of_birth() << endl;
	os << "Que quan: " << A.getcountryside() << endl;
	os << "Tot nghiep truong dai hoc: " << A.uni << endl;
	os << "Nam tot nghiep: " << A.graduate_year << endl;
	return os;
}

int main() {
	Engineer A;
	cin >> A;
	cout << A;
	cout << "ditmegithub";
}