#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


#define DEBUG
#undef DEBUG


char toChar(int x) {
	return x + '0';
}

int toInt(char ch) {
	return ch - '0';
}

// substraction operation for Unsigned number
string subUnsigned(string a, string b) {
	string ret = "";

	// Boundary
	if (a == b) return "0";

	int sign = 1;
	// Make a is bigger
	if (a.size() < b.size() ||
		(a.size() == b.size() && a < b)){
		sign = -1;
		swap(a, b);
	}

	// Reverse them
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	int len = a.size();
	for (int i = 0; i < len; i++) {
		int x = toInt(a[i]);
		int y = (i < b.size()) ? toInt(b[i]) : 0;

		x = x - carry - y;
		if (x < 0) {
			carry = 1;
			ret += toChar(x + 10);
		}
		else {
			carry = 0;
			ret += toChar(x);
		}
	}

	// Check carry
	if (carry == 1) {
		cout << "Carry error in subtraction unsigned" << endl;
	}

	// Remove 0s
	// 124-123 = 001
	// 000-000 = 000, keep at least one zero
	while (ret.size() > 1 && ret.back() == '0') {
#ifdef DEBUG
		cout << "@ remove 0 in subtraction" << endl;
#endif
		ret.pop_back();
	}

	// Check sign
	if (sign == -1) {
		ret += '-';
	}

	// Reverse ret
	reverse(ret.begin(), ret.end());
	return ret;
}

// addUnsigned for Unsigned number
string addUnsigned(string a, string b) {
	string ret = "";
	// add two positive number a and b
	// Reverse them
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	int len = max(a.size(), b.size());
	for (int i = 0; i < len; i++) {
		int x = (i < a.size()) ? a[i] - '0' : 0;
		int y = (i < b.size()) ? b[i] - '0' : 0;

		x += y + carry;
		if (x > 9) {
			ret += (x - 10) + '0';
			carry = 1;
		}
		else {
			ret += x + '0';
			carry = 0;
		}
	}

	// Final carry
	if (carry) {
		ret += carry + '0';
	}

	// Reverse result
	reverse(ret.begin(), ret.end());

	// Boundary
	// 0000 + 0000 = 0
	if (ret[0] == 0) return "0";
	return ret;
}

// add for signed number, so subtraction is also included
string add(string a, string b) {
	if (a.empty()) return b;
	if (b.empty()) return a;

	int signa = 1, signb = 1;
	if (a[0] == '-') {
		signa = -1;
		a = a.substr(1);
	}
	if (b[0] == '-') {
		signb = -1;
		b = b.substr(1);
	}

	if (signa == signb) {
		// Same sign
		string ret;
		if (signa == -1) ret = "-";
		// Call addUnsigned 
		ret += addUnsigned(a, b);
		return ret;
	}
	else {
		// Call subtractionUnsigned
		if (signa == -1) {
			return subUnsigned(b, a); // b - a
		}
		else {
			return subUnsigned(a, b); // a - b
		}
	}
	return "false"; // Error
}



void testAdd(string a, string b, string ret) {
	string fakeRet = add(a, b);
	if (ret != fakeRet) {
		cout << a << "+" << endl << b << endl;
		cout << "true = " << ret << endl;
		cout << "false = " << fakeRet << endl;
	}
}

int main()
{
	// Positive
	testAdd("1", "2", "3");
	testAdd("12", "9", "21");	// carry
	testAdd("99", "2", "101");	// final carry
	testAdd("9", "12", "21");	// swap a, b order
	// Big number
	testAdd("10012343400", "239384230883", "249396574283");
	testAdd("995678201923", "193739499999", "1189417701922");

	// Negtive
	testAdd("3", "-2", "1");		// Normal test
	testAdd("123", "-122", "1");	// Remove 0
	testAdd("123", "-124", "-1");	// Remove 0
	testAdd("9", "-1000", "-991");	// Both direction test
	testAdd("-1000", "9", "-991");	// Both direction test
	testAdd("-1", "-1", "-2");		// final carry
	testAdd("-99", "-10", "-109");	// final carry
	// Big number
	testAdd("995678201923", "-193739499999", "801938701924");
	testAdd("-995678201923", "193739499999", "-801938701924");

	// Abnormal input
	testAdd("000", "-000", "0");
	testAdd("000123", "0000000000000000000000000000001", "124");
	testAdd("000123", "-0000000000000000000000000000001", "122");
}
