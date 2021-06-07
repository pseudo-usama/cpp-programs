// Ibrahim PASSWORD Breaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "thread"
#include "string"
using namespace std;

string n;
string Finded;


double total_time;
clock_t start, end;
//
//void Fn0(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[0] == i) {
//			Finded[0] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[0] == i) {
//			Finded[0] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[0] == i) {
//			Finded[0] = i;
//
//			return;
//		}
//	}
//	Finded[0] = '*';
//
//	return;
//}
//
//
//void Fn1(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[1] == i) {
//			Finded[1] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[1] == i) {
//			Finded[1] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[1] == i) {
//			Finded[1] = i;
//
//			return;
//		}
//	}
//	Finded[1] = '*';
//
//	return;
//}
//
//void Fn2(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[2] == i) {
//			Finded[2] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[2] == i) {
//			Finded[2] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[2] == i) {
//			Finded[2] = i;
//
//			return;
//		}
//	}
//	Finded[2] = '*';
//
//	return;
//}
//
//void Fn3(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[3] == i) {
//			Finded[3] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[3] == i) {
//			Finded[3] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[3] == i) {
//			Finded[3] = i;
//
//			return;
//		}
//	}
//	Finded[3] = '*';
//
//	return;
//}
//
//void Fn4(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[4] == i) {
//			Finded[4] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[4] == i) {
//			Finded[4] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[4] == i) {
//			Finded[4] = i;
//
//			return;
//		}
//	}
//	Finded[4] = '*';
//
//	return;
//}
//
//void Fn5(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[5] == i) {
//			Finded[5] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[5] == i) {
//			Finded[5] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[5] == i) {
//			Finded[5] = i;
//
//			return;
//		}
//	}
//	Finded[5] = '*';
//
//	return;
//}
//
//void Fn6(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[6] == i) {
//			Finded[6] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[6] == i) {
//			Finded[6] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[6] == i) {
//			Finded[6] = i;
//
//			return;
//		}
//	}
//	Finded[6] = '*';
//
//	return;
//}
//
//void Fn7(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[7] == i) {
//			Finded[7] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[7] == i) {
//			Finded[7] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[7] == i) {
//			Finded[7] = i;
//
//			return;
//		}
//	}
//	Finded[7] = '*';
//
//	return;
//}
//
//void Fn8(){
//	for (char i = '0'; i < 10; i++) {
//		if (n[8] == i) {
//			Finded[8] = i;
//
//			return;
//		}
//	}
//	for (char i = 65; i < 91; i++) {
//		if (n[8] == i) {
//			Finded[8] = i;
//
//			return;
//		}
//	}
//	for (char i = 97; i < 123; i++) {
//		if (n[8] == i) {
//			Finded[8] = i;
//
//			return;
//		}
//	}
//	Finded[8] = '*';
//
//	return;
//}

void main() {



	//start = clock();//time count starts 


	//AGAIN:

	//cout << "Enter a word of length 8  = ";
	//cin >> n;

	//if (n.length() != 8) { goto AGAIN; }
	//
	//thread a0(Fn0);
	//thread a1(Fn1);
	//thread a2(Fn2);
	//thread a3(Fn3);
	//thread a4(Fn4);
	//thread a5(Fn5);
	//thread a6(Fn6);
	//thread a7(Fn7);
	//thread a8(Fn8);

	//a0.join();
	//a1.join();
	//a2.join();
	//a3.join();
	//a4.join();
	//a5.join();
	//a6.join();
	//a7.join();
	//a8.join();


	cout << char(-78);

	
	//cout << "You entered   = " << Finded << endl;
}
	


