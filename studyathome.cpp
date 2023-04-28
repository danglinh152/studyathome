#include<iostream>
using namespace std;

class PS {
private:
	int ts, ms;
	static int dem;
public:
	PS(int a, int b) {
		ts = a;
		ms = b;
		cout << "Phan so thu " << ++dem << endl;
	}
	PS() {
		ts = 0;
		ms = 0;
		cout << "Phan so thu " << ++dem << endl;
	} 
	void nhap();
	void xuat();
	void rutgon();
	void setts(int);
	int getts();
	int getdem() {
		return dem;
	}
	void setms(int);
	int getms();
	PS operator+(PS);
	PS operator-(PS);
	PS operator*(PS);
	PS operator/(PS);
	PS operator++() //cong truoc
	{
		ts += ms;
		return *this;
	}
	PS operator++(int) //cong sau
	{
		PS tmp(ts, ms);
		ts += ms;
		return tmp;
	}
	friend istream& operator >> (istream&, PS&);
	friend ostream& operator << (ostream&, PS);
	operator double();
	friend bool operator>(PS, PS);
	friend bool operator<(PS, PS);
	friend bool operator>=(PS, PS);
	friend bool operator<=(PS, PS);
	friend bool operator==(PS, PS);
};

int PS::dem = 0;

PS::operator double() {
	return (double)ts / ms;
}
istream& operator >> (istream& is, PS& a) {
	cout << "Nhap tu so: ";
	is >> a.ts;
	cout << "Nhap mau so: ";
	is >> a.ms;
	return is;
}
ostream& operator << (ostream& os, PS a) {
	a.rutgon();
	if (a.ms == 0) {
		os << "Math Error!";
	}
	else if (a.ts == 0) {
		os << "0";
	}
	else if (a.ts == a.ms) {
		os << "1";
	}
	else if (a.ts == a.ms * -1)
	{
		os << "-1";
	}
	else if (a.ms < -1) {
		os << -a.ts << "/" << -a.ms;
	}
	else {
		os << a.ts << "/" << a.ms;
	}
	return os;
}


PS PS::operator+(PS a) {
	return PS(ts * a.ms + ms * a.ts, ms*a.ms);
}
PS PS::operator-(PS a) {
	return PS(ts * a.ms - ms * a.ts, ms * a.ms);
}
PS PS::operator*(PS a) {
	return PS(ts * a.ts, ms * a.ms);
}
PS PS::operator/(PS a) {
	return PS(ts * a.ms, ms * a.ts);
}
void PS::nhap() {
	cout << "Nhap tu so: ";
	cin >> ts;
	cout << "Nhap mau so: ";
	cin >> ms;
}
void PS::xuat() {
	cout << ts << "/" << ms << endl;
}
void PS::rutgon() {
	int ucln;
	int a = abs(ts);
	int b = abs(ms);
	if (a == 0 or b == 0) {
		ucln = a + b;
	}
	else {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		ucln = a;
	}
	ts /= ucln;
	ms /= ucln;
}
void PS::setts(int a) {
	this->ts = a;
}
void PS::setms(int a) {
	ms = a;
}
int PS::getts() {
	return ts;
}
int PS::getms() {
	return ms;
}

PS int_sang_ps(int a) {
	return PS(a, 1);
}

bool operator>(PS a, PS b) {
	return ((double)a > (double)b);
}
bool operator<(PS a, PS b) {
	return (double)a < (double)b;
}
bool operator==(PS a, PS b) {
	return (double)a == (double)b;
}
bool operator>=(PS a, PS b) {
	return ((double)a >= (double)b);
}
bool operator<=(PS a, PS b) {
	return ((double)a <= (double)b);
}


int main() {
	PS x;
	cin >> x;
	PS y;
	cin >> y;
	cout << "tong hai phan so la: " << x+y << endl;
	cout << "hieu hai phan so la: " << x-y << endl;
	cout << "tich hai phan so la: " << x*y << endl;
	cout << "thuong hai phan so la: " << x/y << endl;
	cout << x << endl;
	cout << x++ << endl;
	cout << x << endl;
	cout << ++x << endl;
	cout << "Gia tri hien tai cua phan so y la: " << y << endl;
	double c = (double)y;
	cout << c << endl;
	int a = 5;
	PS d = int_sang_ps(a);
	cout << "Gia tri cua d: " << d << endl;
	cout << "Gia tri cua x: " << x << endl;
	cout << d << " + " << x << " = " << d + x << endl;
	cin >> x >> y;
	cout << "gia tri cua x: " << x << endl << "gia tri cua y: " << y << endl;
	if (x > y) {
		cout << "x > y";
	}
	else if (x < y) {
		cout << "x < y";
	}
	else {
		cout << "x = y";
	}
	cout << "nhin xem lan sau cuoi, la bao dieu tiec nuoi" << endl;
}