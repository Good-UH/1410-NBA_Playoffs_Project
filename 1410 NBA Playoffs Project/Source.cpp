/*
Try to do a program to play game 5 in NBA playoffs using struct
YOU ARE FREE TO PUT ANY RULES AND COMPLETE IT AS YOU LIKE
Write a function game5 which updates the playoffs : example of updates
1- Which teams? 
2- Spurs vs Pelicans may play in San Antonio ground instead of New Orleans(read the city names from a file called City.txt cities are in order)
3- Score1 and score2 needs to be updated
*/
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct NBA
{
	char team1[20];
	char team2[20];
	char ground[18];
	int score1;
	int score2;
};

void updateGame5(const char x[],const char x1[], const char g[], int y, int z, string s);

void main() 
{
	srand(time(0));

	NBA Playoffs[4] = { 
	{"Spurs","Pelicans","New Orleans",1,3}, 
	{"Grizzlies", "Thunder", "Oklahoma City",3,1},
	{"Warriors", "Rockets", "Houston", 3,3}, 
	{"Heat", "Lakers", "Los Angeles",3,2} };

	fstream grounds;
	string line = " ";
	grounds.open("city.txt", ios::in);

	if (grounds.fail()) {
		cerr << "Error opening file...\t Please try again!";
		system("pause");
		exit(0);
	}

	getline(grounds, line);
	updateGame5("Spurs", "Pelicans", "New Orleans", 1, 3, line);
	getline(grounds, line);
	updateGame5("Grizzlies", "Thunder", "Oklahoma City", 3, 1, line);
	getline(grounds, line);
	updateGame5("Warriors", "Rockets", "Houston", 3, 3, line);
	getline(grounds, line);
	updateGame5("Heat", "Lakers", "Los Angeles", 3, 2, line);

	grounds.close();
	system("pause");
}

void updateGame5(const char team1[], const char team2[], const char ground[], int score1, int score2, string s)
{
	int homeScore;
	int visitorScore;
	homeScore = 70 + (rand() % (120 - 70 + 1));
	visitorScore = 70 + (rand() % (120 - 70 + 1));

	cout << team1 << " vs. " << team2 << " at " << s << endl;
	cout << "Current Series: " << team2 << " " << score2 << "\t-\t" << team1 << " " << score1 << endl;
	cout << team1 << " " << visitorScore << "\t-\t" << team2 << " " << homeScore << endl;

	if (score1 < 4 && score2 < 4) {

		if (homeScore > visitorScore) {
			score2 = score2 + 1;
			cout << team2 << " " << score2 << "\t-\t" << team1 << " " << score1 << "\n\n";
		}
		else if (visitorScore > homeScore) {
			score1 = score1 + 1;
			cout << team2 << " " << score2 << "\t-\t" << team1 << " " << score1 << "\n\n";
		}


	}
	if (score1 > 3 || score2 > 3) {

		cout << team1 << " " << score1 << " - " << team2 << " " << score2 << "\t\t";
		if (score1 > 3)
			cout << team1 << " have won the series!!" << "\n\n";
		else if (score2 > 3)
			cout << team2 << " have won the series!!" << "\n\n";
	}
}
