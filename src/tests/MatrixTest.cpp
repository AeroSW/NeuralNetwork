#include "Matrix.h"
#include <iostream>
#include <string>

using namespace std;
using namespace AeroSW;

int main(){
	matrix a(2,3);
	matrix b(3,2);
	
	for(uint i = 0; i < 6; i++){
		a.set_elem(i, 3);
		b.set_elem(i, 2);
	}
	
	cout << "<<<< MATRIX TO_STRING TESTS >>>>" << endl;
	string a_str = a.to_string();
	string b_str = b.to_string();
	cout << "Matrix A:\n" << a_str << endl;
	cout << "Matrix B:\n" << b_str << endl;
	
	cout << '\n';
	cout << "<<<< MATRIX DOT PRODUCT TESTS >>>>" << endl;
	matrix c = a.dot(b);
	matrix d = b.dot(a);
	cout << "A.B\n" << c.to_string() << endl;
	cout << "B.A\n" << d.to_string() << endl;
	
	cout << '\n';
	cout << "<<<< MATRIX ADDITION TESTS >>>>" << endl;
	c = a.add(b);
	d = b.add(a);
	cout << "A+B\n" << c.to_string() << endl;
	cout << "B+A\n" << d.to_string() << endl;
	
	cout << '\n';
	cout << "<<<< MATRIX SUBTRACTION TESTS >>>>" << endl;
	c = a.sub(b);
	d = b.sub(a);
	cout << "A-B\n" << c.to_string() << endl;
	cout << "B-A\n" << d.to_string() << endl;
	
	cout << '\n';
	cout << "<<<< MATRIX TRANSPOSE TEST >>>>" << endl;
	c = a.transpose();
	cout << "Transpose of A\n" << c.to_string() << endl;
	cout << endl;
	return 0;
}