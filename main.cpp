#include <iostream>
using namespace std;
#include "clock.hpp"


int main()
{
	cout << "----------   PART 1  (3p)  -------------------------" << endl << endl;
	const int N = 10;
	Clock clocks[N]   { Clock(),				// default AM: 01:00:00am
						Clock(7),				// 07:00:00am , default minutes and seconds: 00:00am
						Clock(2,8),				// 02:08:00am , default seconds: 00am
						Clock(11,59,45),		// 11:59:45am
						Clock(11, 15, 0, "pm"),
						Clock(12, 15, 0, "am"),
						Clock(12, 15, 0, "pm"),
						Clock(1, 30, 0, "am"),
						Clock(1, 30, 0, "pm"),
			//text input
						Clock("22:04:47pm"),	
					};

	
	for(int i=0; i < N; i++)
		cout << "z=" << clocks[i] << endl;


	Clock z;
	cout << "Input time (AM/PM format 12h)" << endl;
	cin >> z;
	cout << "Your time:" << endl;
	cout << z << endl;

	cout << "----------   PART 2 (2p)  -------------------------" << endl << endl;

	z.SetFormat() = false;	//ustawia format-24h TYLKO do wyœwietlania
	cout << z << endl;

	
	for (int i = 0; i < N; i++)
	{
		cout << "format(12h): " << clocks[i];
		clocks[i].SetFormat() = false;	//ustawia format-24h TYLKO do wyœwietlania
		cout << "    format(24h): " << clocks[i] << endl;
	}
		

	cout << "----------   PART 3  (1p)  -------------------------" << endl << endl;

	z = Clock(11,59,55,"pm" );
	cout << "z=" << z << endl;

	if (z == (Clock(11, 59, 55, "pm"))) cout << "Time in PM period" << endl;
	if (z == (Clock(11, 59, 55, "am"))) cout << "Time in AM periods" << endl;

	//---------------------------------------------------------
	for (int i = 0; i <= 4; i++)
	{
		for(int j=0;j<900;j++) 	//every 15 minuts
			z=z+1;	
		cout << "z=" << z << endl;
	}
	
	//---------------------------------------------------------
	z = Clock(11,59,55,"am");
	cout <<"once again..."<<endl<< "z=" << z << endl;

	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j<900; j++) 	//every 15 minuts
			z=z+1;
		cout << "z=" << z << endl;
	}

	cout << "----------   PART 4  (1p)  -------------------------" << endl << endl;
/*
	const int N1 = 6;
	int breaks1[N1]{ 15,15,15,15,15,15 };	//breakes in minutes
	int class_time = 45;					//classes in minutes
	Clock class1_start[N1];
	Clock start1{ 8, 15, 0 };
	start1.Plan(class_time, breaks1, N1, class1_start);	

	cout << "Classes Nr1 starts at : " ;
	cout<<start1<<endl;

	for (int i = 0; i < N1; i++)	cout << class1_start[i]<<endl ;
	
	//------------------------------------------------------------------
	const int N2 = 6;
	int breaks2[N2]{ 15,15,20,15,25,15 };	//czas przerw w minutach
	Clock class2_start[N2];
	Clock start2{ 9, 0, 0 };
	start2.Plan(class_time, breaks2, N2, class2_start);

	cout << "Classes Nr2 starts at : " ;
	cout << start2 << endl;

	for (int i = 0; i < N2; i++)	cout << class2_start[i]<<endl;
*/	

	cout << "----------   PART 5 (1p)   -------------------------" << endl << endl;
/*	
	int offset1 = TimeOffset(start1, start2);
	int offset2 = TimeOffset(start2, start1);
	cout << "Number of seconds between: " << start1 << " - " << start2 << " is: " << offset1 << endl;
	cout << "Number of seconds between: " << start2 << " - " << start1 << " is: " << offset2 << endl;
	cout << "offset1+offset2=" << offset1 + offset2 << " (86400)" << endl;
*/
}
