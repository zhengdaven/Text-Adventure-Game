#pragma once
#include "Player.h"
#include "Scoreboard.h"
#include "ScoreRank.h"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;

class FileOperations
{
private:
	string sbrank = "scoreboardrank.txt";//holds the name of the scoreboardrank file
	fstream sbrankfile;//file stream for sbrank
	//vector<string> rankname;//to store all the names in scoreboardrank.txt
	//vector<int> rankscore;//to store all the scores in scoreboardrank.txt
	/*list<string> rankname;
	list<int> rankscore;*/
	list<Srank> rank;
	string SB_file_name; //holds the name of the scoreboard file
	fstream SB_myFile; //file stream for the scoreboard file
	string P_file_name; //holds the name of the player file
	fstream P_myFile; //file stream for the player file
public:
	void Save2File(player in); //Function Saves player progress into a file
	void Save2File1(scoreboard in); //Function Saves scoreboard progress into a file
	void Save2File2(scoreboard s); //funtion saves the score from the scoreboard to the scoreboardrank file
	void ChooseFile(scoreboard& s, player& p); //Function that asks the user to select the file to use
	void ChooseFile1(); //function that reads and store the data in teh scoreboardrank.txt file
	void CloseFile(); //Function to close the files
	//void ScoreRank(); //Function to output and sort the scores in scoreboardrank.txt
	void ScoreSearch();
	void AverageScore();
	void sortname();
	void sortscore();
	void savesort();
	void clear();
	friend ostream& operator<<(ostream& os, FileOperations& f);
};