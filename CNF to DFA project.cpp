// for Project
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <limits>
#include <list>
#include <functional>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <ctime>
#include <ctype.h>

using namespace std;
typedef long long ll;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz size()
#define sqr(x) ((x)*(x))
#define INF numeric_limits<int>::max()

int lenOfInputString, len = 0;
string input[100], inputString;

void checkForEqual()
{
	bool onlyZero = true, onlyOne = true;
	int cnt0 = 0, cnt1 = 0;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] == '0') {
				cnt0++;
			} else {
				cnt1++;
			}
		}
		if (cnt0 != cnt1) {
			return;
		}
	}	
	
	for (int i = 0; i < len; i++) {
		if (input[i][0] != '0') {
			onlyZero = false;
		}
		if (input[i][0] != '1') {
			onlyOne = false;			
		}
	}
	cout<<"When 0's and 1's is equal:\n";
	if (onlyZero) {
		cout<<"S -> 0S1\nS -> e\n\n\n";
	} else if (onlyOne) {
		cout<<"S -> 1S0\nS -> e\n\n\n";	
	} else {
		cout<<"S -> AB\nA -> 0A1\nA -> e\nB -> 1B0\nB -> e\n\n\n";
	}
}

void checkForPolindrome()
{
	bool polindrome = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < input[i].length() / 2; j++) {
			if (input[i][j] != input[i][input[i].length() - j - 1]) {
				polindrome = false;
			}
		}                                      
		if (!polindrome) {
			return;
		}
	}
	cout<<"When string is Polindrome:\n";
	cout<<"S -> 0S0\nS -> 1S1\nS -> 0\nS -> 1\nS -> e\n\n\n";
}

void checkForAllEqual()
{
	bool good = true, onlyZero = true, onlyOne = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < input[i].length() - 1; j++) {
			if (input[i][j] != input[i][j + 1]) {
				good = false;
			}
		}
		if (!good) {
			return;
		}
	}
	for (int i = 0; i < len; i++) {
		if (input[i][0] != '0') {
			onlyZero = false;
		} else {
			onlyOne = false;
		}
	}
	cout<<"When all string is equal to 0 or 1:\n";
	if (onlyZero) {
		cout<<"S -> 0S\nS -> e\n\n\n";
	} else if (onlyOne) {
		cout<<"S -> 1S\nS -> e\n\n\n";
	} else {
		cout<<"S -> 0S\nS -> 1S\nS -> e\n\n\n";
	}
}

void checkForLength()
{
	bool even = true, odd = true;

	 for (int i = 0; i < len; i++) {
	 	if (input[i].length() % 2 != 0) {
			even = false;	 		
	 	} else {
	 		odd = false;
	 	}
	 }
	 if (odd) {
	 	bool middleOne = true, middleZero = true;
	 	for (int i = 0; i < len; i++) {
	 		if (input[i][input[i].length() / 2] != '0') {
	 			middleZero = false;
	 		} else {
	 			middleOne = false;
	 		}
	 	}
	 	cout<<"When lenght of string is odd and has middle 0 or 1:\n";
	 	if (middleZero) {
	 		cout<<"S -> 0S0\nS -> 0S1\nS -> 1S0\nS -> 1S1\nS -> 0\n\n\n";
	 	} else if (middleOne) {
	 		cout<<"S -> 0S0\nS -> 0S1\nS -> 1S0\nS -> 1S1\nS -> 1\n\n\n";
	 	} else {
	 		cout<<"S -> 0S0\nS -> 0S1\nS -> 1S0\nS -> 1S1\nS -> 0\nS -> 1\n\n\n";
	 	}
	 }
	 if (even) {
	 	cout<<"When lenght of string is even:\n";
	 	cout<<"S -> 0S0\nS -> 0S1\nS -> 1S0\nS -> 1S1\nS -> e\n\n\n";
	 }
}

void checkForAtLeast()
{
	string res = "";
	int minZero = INF, minOne = INF;
	for (int i = 0; i < len; i++) {
		int cnt0 = 0, cnt1 = 0;
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] == '0') {
				cnt0++;
			} else {
				cnt1++;
			}
		}
		minZero = min(minZero, cnt0);
		minOne = min(minOne, cnt1);
	}
	for (int i = 0; i < minOne; i++) {
		res += "X1";
	}
	res += "X";
	cout<<"For at least number of 1's:\n";
	cout<<"S -> "<<res<<"\nX -> 0X\nX -> 1X\nX -> e\n\n\n";
}

void checkForEven()
{
	bool zero = true, one = true;

	for (int i = 0; i < len; i++) {
		int cnt0 = 0, cnt1 = 0;

		for (int j = 0; j < input[i].length(); i++) {
			if (input[i][j] == '0') {
				cnt0++;
			} else {
				cnt1++;	
			}
		}
		if (cnt0 % 2 != 0) {
			zero = false;			
		}
		if (cnt1 % 2 != 0) {
			one = false;
		}
	}
	if (zero) {
		cout<<"When 0's is even:\n";
		cout<<"S -> 1S\nS -> 0A0S\nA -> 1A\nA -> e\nS -> e\n\n\n";
	}
	if (one) {
		cout<<"When 1's is even:\n";
		cout<<"S -> 0S\nS -> 1A1S\nA -> 0A\nA -> e\nS -> e\n\n\n";
	}
}

void checkForOdd()
{
	bool zero = true, one = true;

	for (int i = 0; i < len; i++) {
		int cnt0 = 0, cnt1 = 0;

		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] == '0') {
				cnt0++;
			} else {
				cnt1++;	
			}
		}
		if (cnt0 % 2 == 0) {
			zero = false;			
		}
		if (cnt1 % 2 == 0) {
			one = false;
		}
	}

	if (zero) {
		cout<<"When 0's is odd:\n";
		cout<<"S -> 1S\nS -> 0T\nT -> 1T\nT -> 0S\nS -> e\n\n\n";	
	} 
	if (one) {
		cout<<"When 1's is odd:\n";
		cout<<"S -> 0S\nS -> 1T\nT -> 0T\nT -> 1S\nS -> e\n\n\n";		
	}
}

void checkForEvenPosition()
{
	bool good = true;
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < input[i].length(); j += 2) {
			if (input[i][j] != '1') {
				good = false;				
			}
		}
		if (!good) {
			return;
		}
	}
	cout<<"When 1's is in even position:\n";
	cout<<"S -> 01S\nS -> 11S\nS -> e\n\n\n";
}
void check(){
	
}

void checkForRandom()
{
	cout<<"For other cases:\n";
	cout<<"S ->0S\nS -> 1S\nS -> 0\nS ->1\n\n\n";
} 

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","rt",stdin);
		freopen("output.txt","wt",stdout);
	#endif
	getline(cin, inputString);
	lenOfInputString = inputString.length();
	for (int i = 0; i < lenOfInputString; i++) {
		if (inputString[i] == '0' || inputString[i] == '1' || inputString[i] == ' ' || inputString[i] == ',') {
			continue;
		} else {
			cerr<<inputString[i]<<' '<<i;
			cout<<"Error: You should use only numbers: 0 & 1";
			exit(0);
		}
	}
	string t = "";
	for (int i = 0; i < lenOfInputString; i++) {
		if (inputString[i] == ' ')
			continue;
		if (inputString[i] == ',' || i == lenOfInputString - 1) {
			if (i == lenOfInputString - 1) {
				t += inputString[i];
			}
			input[len++] = t;			
			t = "";
			continue;
		}
		t += inputString[i];
	}

	checkForEqual();
	checkForPolindrome();
	checkForAllEqual();
	checkForLength();
	checkForAtLeast();
	checkForEven();
	checkForOdd();
	checkForEvenPosition();
	checkForRandom();
	check();

















	
	return 0;
}
