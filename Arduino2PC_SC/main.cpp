//Rules:
/*
1. Check if connection with Arduino is made
2. If Arduino is connected then take input from user in a String
3. Make a char array of the size of string + 1
4. Copy the whole string into the char array
5. Add escape sequence \n because this represents the end of a line in Serial Comm port
6. Write the whole char array into the buffer (a buffer takes the info forward to the Serial Comm Port)
7. Read from the Arduino if data is received successfully or if the action is taken as per needed
*/

//Connect with me:
/*	Twitter: http://www.twitter.com/ZainsOfficial/
	Facebook: http://www.facebook.com/ZainsOfficial/
	Github: http://github.com/ZainUlMustafa/
*/

/* This software is allowed for any user to copy, modify, merge, and distribute in any of his/her project.
Complete repository for this project is available on github. If you find this project anywhere except github, it
is to be noted that it is not made by me and not distributed by me. 
Please follow this link to get to the original repository of github for this project
Github shortened link (no spam and no ads): http://bit.ly/2vGkinQ
*/

/* PC 2 Arduino */
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
char *port = "\\\\.\\COM4";
int tripl[3] = { };
int x = 0;

int main()
{
	SerialPort arduino(port);
	if(arduino.isConnected()){
		cout<<"Connection made"<<endl<<endl;
		
	}
	else{
		cout<<"Error in port name"<<endl<<endl;
	}
	while(arduino.isConnected())
	{
		/*cout << "Enter your command: " << endl;
		string data;
		cin>>data;

		char *charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);*/
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		//cout<<">> "<<output<<endl;
		/*
		for (int i = 0; i < MAX_DATA_LENGTH; i++)
		{
			printf("%c", output[i]);
		}*/

		/*
		printf("%c num 1 \n", output[0]); 
		printf("%c num 2\n", output[1]);	//bit giusti
		printf("%c num 3\n", output[2]);*/
		
		
		tripl[0] = (output[0] - 48) * 100;
		tripl[1] = (output[1] - 48)* 10;
		tripl[2] = output[2] - 48;
		x = tripl[0] + tripl[1] + tripl[2];

		printf("%d \n", x);

		printf("%d \n", x);

		//printf("%d \n", tripl[i-1]);
		//printf("%d \n", i);
		
		/*printf("&c \n", output[3]); //bit conferma
		printf("%c \n", output[4]);
		printf("%c \n", output[5]);*/
		
		//printf("%d", MAX_DATA_LENGTH);
		//printf("\n");
		Sleep(100);
		//x = output - "0";
		SetCursorPos(x, 100);
		//output[] = "0";

		//delete [] charArray;
	}
	return 0;
}
