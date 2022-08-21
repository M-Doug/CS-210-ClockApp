//includes packages
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>

using namespace std;

int currentHour = 0;
int currentMinute = 0;
int currentSecond = 0;

//creats the two digit string that is used for seconds, minutes, and hours.
string twoDigitString(unsigned int n) {
    string fullString;
    fullString = to_string(n);
    if (fullString.length() == 1) {
        fullString = "0" + fullString;
    }
    return fullString;
}

//Creats a string of characters at the length of n
string nCharString(size_t n, char c) {
    string charString(n, c);
    return charString;
}

//Formats the time to a 24 hour clock based on user input
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string time;
    time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

    return time;
}

//Changes time to a 12 hour clock and returns it
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string amOrPm;
    string time12;
    if (h >= 12) {
        h = h - 12;
        amOrPm = "P M";
    }
    else {
        amOrPm = "A M";
    }
    if (h == 0) {
        h = h + 12;
    }
    time12 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + amOrPm;

    return time12;
}

//prints menu for selection
void printMenu(char* strings[4], unsigned int numStrings, unsigned char width) {
    cout << nCharString(width, '*') << endl;
    for (int i = 0; i < numStrings; i++) {
        int spacing = width - (6 + strlen(strings[i])) - 1;
        cout << "*" << " " << i + 1 << " - " << strings[i] << nCharString(spacing, ' ') << "*" << endl;
        if (i == numStrings - 1) {
            break;
        }
        cout << endl;
    }
}

// gets menuchoice 
unsigned int getMenuChoice(unsigned int maxChoice) {
    int menuChoice;
    cin >> menuChoice;
    while (menuChoice > maxChoice || menuChoice < 1) {
        cin >> menuChoice;
    }
    return menuChoice;
}

//Displays the clocks on the screen
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ') << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ') << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}


int getMinute() {
    return currentMinute;
}

int getHour() {
    return currentHour;
}

int getSecond() {
    return currentSecond;
}

void setMinute(int min) {
    currentMinute = min;
}

void setHour(int cHour) {
    currentHour = cHour;
}

void setSecond(int sec) {
    currentSecond = sec;
}

// adds one hour
void addOneHour() {
    int hour = getHour();
    if (hour >= 0 && hour <= 22) {
        hour++;
        setHour(hour);
    }

    else if (hour == 23) {
        hour = 0;
        setHour(hour);
    }
}

// adds one minute
void addOneMinute() {
    int minute = getMinute();
    if (minute >= 0 && minute <= 58) {
        minute++;
        setMinute(minute);
    }
    else if (minute == 59) {
        minute = 0;
        setMinute(minute);
        addOneHour();
    }
}


void addOneSecond() {
    int second = getSecond();
    if (second >= 0 && second <= 58) {
        second++;
        setSecond(second);
    }
    else if (second == 59) {
        second = 0;
        setSecond(second);
        addOneMinute();
    }
}


void mainMenu() {
    char *strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    printMenu(strings[4], 4, 26);
    int choice = getMenuChoice(4);
    while (choice != 4) {
        if (choice == 1) {
            addOneHour();
            displayClocks(currentHour, currentMinute, currentSecond);
        }
        else if (choice == 2) {
            addOneMinute();
            displayClocks(currentHour, currentMinute, currentSecond);
        }
        else if (choice == 3) {
            addOneSecond();
            displayClocks(currentHour, currentMinute, currentSecond);
        }
     choice = getMenuChoice(4);
    }
}



int main() {
    displayClocks(currentHour, currentMinute, currentSecond);
    mainMenu();
}


