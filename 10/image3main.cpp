#include "image3.hpp"
#include <iostream>
#include <stdint.h> // for uint8_t
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(void){
	int i,j,num;
	Image a;
	a.resize(10,10,0);
	/*a.save("t2.txt");
	num = a.resize(10,10,5);
	cout << "resize return value: " << num << endl;
	num = a.set_pixel(3,1,1);
	num = a.set_pixel(3,2,2);
	num = a.set_pixel(3,3,3);
	num = a.set_pixel(3,4,4);
	num = a.set_pixel(3,5,5);
	//num = a.set_pixel(3,6,6);
	//num = a.set_pixel(3,7,7);
	//num = a.set_pixel(3,8,8);
	//num = a.set_pixel(3,9,9);
	num = a.set_pixel(4,0,10);
	num = a.set_pixel(4,1,11);
	num = a.set_pixel(4,2,12);
	num = a.set_pixel(4,3,13);
	//cout << (int)a.pixels[7] << endl;
	cout << (int)a.pixels[3][3] << endl;
	cout << a.cols << endl;
	cout << a.rows << endl;
	
	cout << "set return value: " << num << endl;
	cout << "resize return value: " << num << endl;

	num =  a.save("t1.txt");
	cout << "save return value: " << num << endl;

	// a.resize(15,15,25);
	// a.save("t2.txt");
	// a.resize(10,10,5);

	cout << "@" << a.cols <<endl;                        //load!
	cout << "@" << a.rows <<endl;
	num = a.load("t1.txt");
	cout << a.cols << endl;
	cout << a.rows << endl;
	cout << "load return value: " << num << endl;

	//cout << "resize return value: " << num << endl;*/
	/*for (i=0; i<a.rows; i++){
		for (j=0; j<a.cols; j++){
			cout << (int)a.pixels[i*a.cols+j] << " ";
		}
		cout << endl;
	}*/
	int total = 0;
	for (i=0; i<a.rows; i++){
		for (j=0; j<a.cols; j++){
			cout << (int)a.pixels[i][j] << " ";
			total++;
		}
		cout << endl;
	}
	cout << total << endl;

	a.load("t1.txt");
	for (i=0; i<a.rows; i++){
		for (j=0; j<a.cols; j++){
			cout << (int)a.pixels[i][j] << " ";
			total++;
		}
		cout << endl;
	}
	cout << total << endl;
	cout << "@" << a.cols <<endl;                        //load!
	cout << "@" << a.rows <<endl;
	return 0;
}