#include<iostream>

// C++ has the ability to provide the operators with a special meaning for a data type,
// this ability is known as operator overloading.
class ComplexNumber {
private:
	int real, imag;
public:
	ComplexNumber(int r = 0, int i = 0) {real = r; imag = i;}
	ComplexNumber operator + (ComplexNumber const &obj) {
		ComplexNumber res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
    void PrintValue() { std::cout << real << " + i" << imag << std::endl; }
};
int main()
{
	ComplexNumber cNumber1(10, 5), cNumber2(2, 4);
    ComplexNumber cNumber3 = cNumber1 + cNumber2;
	cNumber3.PrintValue();
}
