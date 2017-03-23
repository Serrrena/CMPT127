#include "image.hpp"
#include <iostream>
#include <stdint.h> // for uint8_t
//#include <stdlib.h>
//#include <stdio.h>
using namespace std;
int main(){
	
	Image img;
	img.resize( 3, 2, 255);
	img.set_pixel( 1, 1, 12 );

	uint8_t cp = 210;
	img.get_pixel( 2 , 1 , &cp );
	int k=1; 
	/*for (k=0;k<3*2;k++){
		//cout<<"at location "<<k<<"color is"<<img.pixel[k]<<endl;
		printf("at location %d color is %d\n",k,img.pixels[k]);
	}*/
	cout << "at location " << k << endl;
    cout << "color is" << img.pixels[1] << endl;
	//printf("1\n");
	//printf("%d\n",img.pixels[1]);
	return 0;

}
