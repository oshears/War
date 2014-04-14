//War! Version 1.5 Alpha by Osaze Shears
//Cards are added to the bottom of the deck of the winning player in this verison...

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;


void p1suitgen();
void p2suitgen();
void game();
void guide();


 int number (0), card(0);
    int stackofcards[52]{102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
                         202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214,
                         302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314,
                         402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414};
    int player1cards[26]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int player2cards[26]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int roundnum(0);
    int a1,b1;
    int a2,b2;
    int p1choice, p2choice;
    int userinput;
    string p1cardoutput,p2cardoutput;
    stringstream tempss, tempss2;
    stack<int> tablecards, tempstack1, tempstack2;
    bool gameon(true), active(true);
    size_t found;

    char heart= (char)3;
    char diamond= (char)4;
    char club= (char)5;
    char spade= (char)6;

int main()
{
    HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,11);
    cout<<"War! Version 1.5 Alpha by Osaze Shears\n\n";

    for (int i=0;i<10;i++){
    SetConsoleTextAttribute(hConsole,13);cout<<heart;
    SetConsoleTextAttribute(hConsole,11);cout<<diamond;
    SetConsoleTextAttribute(hConsole,10);cout<<club;
    SetConsoleTextAttribute(hConsole,14);cout<<spade;
    }
    cout<<endl;
    SetConsoleTextAttribute(hConsole,7);

    SetConsoleTextAttribute(hConsole,12);
    cout<<"Welcome to War!\n";
    SetConsoleTextAttribute(hConsole,7);
    while (active==true){
    cout<<"Guide<0>\nPlay<1>\nQuit<2>\n";
    cin>>userinput;

    if (userinput==0){
    guide();
    }
    else if (userinput==1){
    cout<<endl;
    game();
    }
    else if (userinput==2){
    active=false;
    }
    }
return 0;

}

void p1suitgen(){
    HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
tempss.str(string());
tempss<<a1;
p1cardoutput=tempss.str();
//cout<<p1cardoutput<<" ";
tempss.str(string());

switch (p1cardoutput[0]){
    case '1':
        p1cardoutput.replace(0,1,"");
        p1cardoutput.insert(0, 1, diamond);
        SetConsoleTextAttribute(hConsole,11);cout<<p1cardoutput[0];SetConsoleTextAttribute(hConsole,3);cout<<p1cardoutput[1];cout<<p1cardoutput[2];cout<<endl;
        break;
    case '2':
        p1cardoutput.replace(0,1,"");
        p1cardoutput.insert(0, 1, club);
       SetConsoleTextAttribute(hConsole,10);cout<<p1cardoutput[0];SetConsoleTextAttribute(hConsole,3);cout<<p1cardoutput[1];cout<<p1cardoutput[2];cout<<endl;
        break;
    case '3':
        p1cardoutput.replace(0,1,"");
        p1cardoutput.insert(0, 1, heart);
       SetConsoleTextAttribute(hConsole,13);cout<<p1cardoutput[0];SetConsoleTextAttribute(hConsole,3);cout<<p1cardoutput[1];cout<<p1cardoutput[2];cout<<endl;
        break;
    case '4':
        p1cardoutput.replace(0,1,"");
        p1cardoutput.insert(0, 1, spade);
       SetConsoleTextAttribute(hConsole,14);cout<<p1cardoutput[0];SetConsoleTextAttribute(hConsole,3);cout<<p1cardoutput[1];cout<<p1cardoutput[2];cout<<endl;
        break;
}
}

void p2suitgen(){
    HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
tempss2.str(string());
tempss2<<a2;
p2cardoutput=tempss2.str();
tempss2.str(string());


switch (p2cardoutput[0]){
    case '1':
        p2cardoutput.replace(0,1,"");
        p2cardoutput.insert(0, 1, diamond);
        SetConsoleTextAttribute(hConsole,11);cout<<p2cardoutput[0];SetConsoleTextAttribute(hConsole,2);cout<<p2cardoutput[1];cout<<p2cardoutput[2];cout<<endl;
        break;
    case '2':
        p2cardoutput.replace(0,1,"");
        p2cardoutput.insert(0, 1, club);
        SetConsoleTextAttribute(hConsole,10);cout<<p2cardoutput[0];SetConsoleTextAttribute(hConsole,2);cout<<p2cardoutput[1];cout<<p2cardoutput[2];cout<<endl;
        break;
    case '3':
        p2cardoutput.replace(0,1,"");
        p2cardoutput.insert(0, 1, heart);
        SetConsoleTextAttribute(hConsole,13);cout<<p2cardoutput[0];SetConsoleTextAttribute(hConsole,2);cout<<p2cardoutput[1];cout<<p2cardoutput[2];cout<<endl;
        break;
    case '4':
        p2cardoutput.replace(0,1,"");
        p2cardoutput.insert(0, 1, spade);
        SetConsoleTextAttribute(hConsole,14);cout<<p2cardoutput[0];SetConsoleTextAttribute(hConsole,2);cout<<p2cardoutput[1];cout<<p2cardoutput[2];cout<<endl;
        break;
}
}

void guide(){
    HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,6);cout<<"Guide:\n Numbers starting with 1 are of the Diamond suit.\n Numbers starting with 2 are of the Club suit.\n Numbers starting with 3 are of the Heart suit.\n Numbers starting with 4 are of the Spade suit.\n The higher value of the last two digits wins.\n";
    SetConsoleTextAttribute(hConsole,7);
    cout<<endl;
}

void game(){
    srand(time(0)); // initialize seed "randomly"
    HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

    cout<<"Shuffling cards... \n";
     for (int card=0; card<52; card++){
        int randNum, temp;
        randNum=rand()%52;
        temp=stackofcards[card];
        stackofcards[card]=stackofcards[randNum];
        stackofcards[randNum]=temp;
    }

    for (int i=0;i<52;i++){
    string masterstring;
    stringstream mastertempss;
    cout<<i+1<<" ";
    mastertempss.str(string());
    mastertempss<<stackofcards[i];
    masterstring=mastertempss.str();
    mastertempss.str(string());
    switch (masterstring[0]){
        case '1':
        masterstring.replace(0,1,"");
        masterstring.insert(0, 1, diamond);
        SetConsoleTextAttribute(hConsole,11);cout<<masterstring[0];SetConsoleTextAttribute(hConsole,7);cout<<masterstring[1];cout<<masterstring[2];cout<<endl;
        break;
    case '2':
        masterstring.replace(0,1,"");
        masterstring.insert(0, 1, club);
        SetConsoleTextAttribute(hConsole,10);cout<<masterstring[0];SetConsoleTextAttribute(hConsole,7);cout<<masterstring[1];cout<<masterstring[2];cout<<endl;
        break;
    case '3':
        masterstring.replace(0,1,"");
        masterstring.insert(0, 1, heart);
        SetConsoleTextAttribute(hConsole,13);cout<<masterstring[0];SetConsoleTextAttribute(hConsole,7);cout<<masterstring[1];cout<<masterstring[2];cout<<endl;
        break;
    case '4':
        masterstring.replace(0,1,"");
        masterstring.insert(0, 1, spade);
        SetConsoleTextAttribute(hConsole,14);cout<<masterstring[0];SetConsoleTextAttribute(hConsole,7);cout<<masterstring[1];cout<<masterstring[2];cout<<endl;
        break;
    }
    }
    cout<<"Cards Have Been Shuffled...\n";
    system("pause");

    SetConsoleTextAttribute(hConsole,3);
    for (int p1cards=0;p1cards<26;p1cards++){
    player1cards[p1cards]=stackofcards[p1cards];
    }

    SetConsoleTextAttribute(hConsole,2);
	int counter(0);
    for (int p2cards=26;p2cards<52;p2cards++){
    player2cards[counter]=stackofcards[p2cards];
    counter=counter+1;
    }

	stack<int> player1stack;
	for (int i=0;i<26;i++){
	player1stack.push(player1cards[i]);
	}


	stack<int> player2stack;
	for (int i=0;i<26;i++){
	player2stack.push(player2cards[i]);
	}

	SetConsoleTextAttribute(hConsole,7);

    gameon=true;

while (gameon==true){
//GAME START!!
if (!player1stack.empty() && !player2stack.empty()){
roundnum++;
}
else if (player1stack.empty()==true){
    gameon=false;
    SetConsoleTextAttribute(hConsole,2);
    cout<<"Player 1 has no cards left. Player 2 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
    }
else if (player2stack.empty()==true){
    gameon=false;
    SetConsoleTextAttribute(hConsole,3);
    cout<<"Player 2 has no cards left. Player 1 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
    }
cout<<"Round #"<<roundnum<<endl;

SetConsoleTextAttribute(hConsole,3);
//cout<<player1stack.top()<<endl;
a1=player1stack.top();
p1suitgen();
tablecards.push(a1);
b1=a1%100;
player1stack.pop();


SetConsoleTextAttribute(hConsole,2);
//cout<<player2stack.top()<<endl;
a2=player2stack.top();
p2suitgen();
tablecards.push(a2);
b2=a2%100;
player2stack.pop();


SetConsoleTextAttribute(hConsole,7);


//comparison
bool comparemaster(true);
while (comparemaster==true){
if (b1 > b2){
	SetConsoleTextAttribute(hConsole,3);
	comparemaster=false;
    cout<<"Player 1 wins Round "; cout<<roundnum; cout<<"\n";
    SetConsoleTextAttribute(hConsole,7);

    while(!player1stack.empty()){
    tempstack1.push(player1stack.top());
    player1stack.pop();
    }
    while(!tablecards.empty()){
    player1stack.push(tablecards.top());
    tablecards.pop();
    }
    while(!tempstack1.empty()){
    player1stack.push(tempstack1.top());
    tempstack1.pop();
    }
}
else if (b1 < b2){
    SetConsoleTextAttribute(hConsole,2);
    comparemaster=false;
    cout<<"Player 2 wins Round "; cout<<roundnum; cout<<"\n";
	SetConsoleTextAttribute(hConsole,7);

    while(!player2stack.empty()){
    tempstack2.push(player2stack.top());
    player2stack.pop();
    }
    while(!tablecards.empty()){
    player2stack.push(tablecards.top());
    tablecards.pop();
    }
    while(!tempstack2.empty()){
    player2stack.push(tempstack2.top());
    tempstack2.pop();
    }

}
else if (b1 = b2){
    cout<<"Value of the cards is equal. Begining War...\n";

	int temp1arr[3];
	int temp2arr[3];

	//check if player 1 has enough cards
	if (!player1stack.empty()){
	temp1arr[0]=player1stack.top();
	player1stack.pop();}
	else{
	gameon=false;
	SetConsoleTextAttribute(hConsole,2);
    cout<<"Player 1 has no cards left. Player 2 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player1stack.empty()){
	temp1arr[1]=player1stack.top();
	player1stack.pop();}
	else{
	gameon=false;
	SetConsoleTextAttribute(hConsole,2);
    cout<<"Player 1 has no cards left. Player 2 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player1stack.empty()){
	temp1arr[2]=player1stack.top();
	player1stack.pop();}
	else{
	gameon=false;
	SetConsoleTextAttribute(hConsole,2);
    cout<<"Player 1 has no cards left. Player 2 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player1stack.empty()){
	temp1arr[3]=player1stack.top();
	player1stack.pop();}
	else{
	gameon=false;
	SetConsoleTextAttribute(hConsole,2);
    cout<<"Player 1 has no cards left. Player 2 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}

	//check if player 2 has enough cards
	if (!player2stack.empty()){
	temp2arr[0]=player2stack.top();
	player2stack.pop();}
	else{
	gameon=false;
	SetConsoleTextAttribute(hConsole,3);
    cout<<"Player 2 has no cards left. Player 1 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player2stack.empty()){
	temp2arr[1]=player2stack.top();
	player2stack.pop();}
	else{
	gameon=false;
    SetConsoleTextAttribute(hConsole,3);
    cout<<"Player 2 has no cards left. Player 1 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player2stack.empty()){
	temp2arr[2]=player2stack.top();
	player2stack.pop();}
	else{
	gameon=false;
    SetConsoleTextAttribute(hConsole,3);
    cout<<"Player 2 has no cards left. Player 1 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}
	if (!player2stack.empty()){
	temp2arr[3]=player2stack.top();
	player2stack.pop();}
	else{
	gameon=false;
    SetConsoleTextAttribute(hConsole,3);
    cout<<"Player 2 has no cards left. Player 1 wins.\n";
	SetConsoleTextAttribute(hConsole,7);
    break;
	}

	for (int i=0;i<4;i++){
    tablecards.push(temp1arr[i]);
    tablecards.push(temp2arr[i]);
	}

	SetConsoleTextAttribute(hConsole,3);
	//cout<<temp1arr[3]<<endl;
	a1=temp1arr[3];
    p1suitgen();
	b1=a1%100;

	SetConsoleTextAttribute(hConsole,2);
	//cout<<temp2arr[3]<<endl;
	a2=temp2arr[3];
    p2suitgen();
	b2=a2%100;

	SetConsoleTextAttribute(hConsole,7);
}

SetConsoleTextAttribute(hConsole,7);
}
SetConsoleTextAttribute(hConsole,7);

}
SetConsoleTextAttribute(hConsole,7);
cout<<endl;
}
