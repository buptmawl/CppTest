#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <string>
#include <stdio.h>
using namespace std;

// clang++ -std=c++11 -stdlib=libc++ median_nums_two_sorted.cc && ./a.out


void incomment(std::fstream& fs) {
	char t ; 
	fs.get(t);
	char d ; 
	fs.get(d);
	while(t != '*'  || d != '/') {
			t=d;
			fs.get(d);
	}
}

void echoquotes(char c, std::fstream& fs) {
	putchar(c);
	char d;

	fs.get(d);
	while( d != c) {
		putchar(d);
		if ( d == '\\') {
			char tmp;
			fs.get(tmp);
			putchar(tmp);
		}
		fs.get(d);
	}
	putchar(d);
}

void rcomment(char c, std::fstream& fs) {
	char d;
	if (c == '/') {
		fs.get(d);
		if ( d == '*') {
			incomment(fs);
		} else if(d == '/') {
			//putchar(c);
			//rcomment(d, fs);
			char tmp;
			fs.get(tmp);
			while(tmp != '\n') {
				fs.get(tmp);
			}
		} else {
			putchar(c);
			putchar(d);
		}
	} else if (c == '\'' || c == '"') {
		echoquotes(c, fs);
	} else {
		putchar(c);
	}
}

int main() {
	char str[256];
	std::cout << "input the test file:" << std::endl;
	std::cin.get(str, 256);
	std::fstream  fs(str);

	char c;
	while(fs.get(c)) {
		rcomment(c, fs);
		//putchar(c);
	}
	fs.close();
	return 0;
}
