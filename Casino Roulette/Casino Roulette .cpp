#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	//Variables
	std::string alias, Y_N;
	int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 21, 23, 25, 27, 28, 30, 32, 34, 36};
	int black [18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 20, 22, 24, 26, 29, 31, 33, 35};
	int zeroes [2] = {0, 00};
	int total = 0, pot_all_black = 0, pot_all_red = 0, pot_even = 0, pot_odd = 0, pot_1to18 = 0, pot_19to36 = 0, pot_first12 = 0, pot_second12 = 0, pot_third12 = 0, pot_column[3] = {0}, pot_sixnum[11] = {0}, pot_fivenum = 0, pot_fournum[22] = {0}, pot_threenum[12] = {0}, pot_doublenum[57] = {0}, pot_singlenum[38] = {0};
	bool bet_confirmed = false, all_black = false, all_red = false, even = false, odd = false, _1to18 = false, _19to36 = false, first12 = false, second12 = false, third12 = false, column[3] = {false}, sixnum[11] = {false}, fivenum = false, fournum[22] = {false}, threenum[12] = {false}, doublenum[57] = {false}, singlenum[38] = {false};
	int balance, bet, choices, choices2, roulette;
	int wins = 0, losses = 0;
	int roulette_limit = 38;
	srand(time(0));
	
	//Menu
	cout << "Welcome to Casino Roulette" << '\n';
	cout << endl;
	
	cout << "Project for DCIT 22." << '\n';
	cout << "Teacher: Barbuco, Danel Dave" << '\n';
	cout << endl;
	
	cout << "Created by:" << '\n';
	cout << "Andrade, Earl Jan" << '\n';
	cout << "Brady, Jeffrey" << '\n';
	cout << "Galorio, Wyn wyn" << '\n';
	cout << endl;
	
	cout << "Please enter your alias: ";
	getline(cin, alias);
	cout << endl;
	
	cout << "Welcome " << alias << ". ";
	
	//Deposit
	while (true){
		//Resets Invalid inputs.
		while (!cin.fail()) {
		cout << "How much would you like to deposit?: ";
		cin >> balance;
			if (cin.fail()){
			cin.clear();
			cin.ignore(10000000, '\n');
			cout << "Invalid input. Please try again." << '\n'<< '\n';
			continue;
			}
			else{
				break;
			}	
		}
		
			if (balance > 10000000){
				cout << "You exceed the maximum deposit." << '\n' << '\n';
				cout << "Please try again." << '\n';
				cout << endl;
				continue;
			}
			else if (balance >= 5) {
			}
			else {
				cout << "Not enough deposit. The amount must be 5 or above." << '\n' << '\n';
				continue;
			}
			
		cout << "You deposited: " << balance << '\n';
		//Resets Invalid Inputs.
		while (!cin.fail()) {
		cout << "Are you sure with this deposit? (Y/N): ";
		cin >> Y_N;
			if (cin.fail()){
			cin.clear();
			cin.ignore(10000000, '\n');
			cout << "Invalid input. Please try again." << '\n'<< '\n';
			continue;
			}
			else{
				break;
			}
		}
		
			if (Y_N == "Y" || Y_N == "y"){
				cout << endl;
				cout << "Alright. Let's play." << '\n';
				cout << endl;
				break; 
			}
			else if (Y_N == "N" || Y_N == "n"){
				continue; 
			}
			else {
				cout << "Invalid input. Please try again." << '\n';
				continue;
			}
	}
	
	//Actual Game
	while (true){
		while (true){
		//Resets Invalid inputs.
		while (!cin.fail()) {
		cout << "      **************************************************************************************************************" << '\n';
		cout << "     *     *       *       *       *       *       *       *       *       *       *       *       *       *   2   *" << '\n';
		cout << "    *      *  R-3  *  B-6  *  R-9  * R-12  * B-15  * R-18  * R-21  * B-24  * R-27  * R-30  * B-33  * R-36  *   to  *" << '\n';
		cout << "   *   0   *       *       *       *       *       *       *       *       *       *       *       *       *   1   *" << '\n';
		cout << "  *        *********************************************************************************************************" << '\n';
		cout << " *         *       *       *       *       *       *       *       *       *       *       *       *       *   2   *" << '\n';	
		cout << "************  B-2  *  R-5  *  B-8  * B-11  * R-14  * B-17  * B-20  * R-23  * B-26  * B-29  * R-32  * B-35  *   to  *" << '\n';	
		cout << " *         *       *       *       *       *       *       *       *       *       *       *       *       *   1   *" << '\n';
		cout << "  *        *********************************************************************************************************" << '\n';
		cout << "   *   00  *       *       *       *       *       *       *       *       *       *       *       *       *   2   *" << '\n';
		cout << "    *      *  R-1  *  B-4  *  R-7  * B-10  * B-13  * R-16  * B-19  * B-22  * R-25  * R-28  * B-31  * R-34  *   to  *" << '\n';
		cout << "     *     *       *       *       *       *       *       *       *       *       *       *       *       *   1   *" << '\n';
		cout << "      **************************************************************************************************************" << '\n';
		cout << "           *                               *                               *                               *        " << '\n';
		cout << "           *            1st 12             *            2nd 12             *            3rd 12             *        " << '\n';
		cout << "           *                               *                               *                               *        " << '\n';
		cout << "           *************************************************************************************************        " << '\n';
		cout << "           *               *               *               *               *               *               *        " << '\n';
		cout << "           *    1 to 18    *     Even      *      Red      *     Black     *      Odd      *   19 to 36    *        " << '\n';
		cout << "           *               *               *               *               *               *               *        " << '\n';
		cout << "           *************************************************************************************************        " << '\n';
		cout << endl;
	
		cout << "Note: R = Red and B = Black" << '\n';
		cout << "Betting: " << '\n';
		cout << "[1] All Black		[7] 1st 12		[13] Four Number" << '\n';
		cout << "[2] All Red		[8] 2nd 12		[14] Three Number" << '\n';
		cout << "[3] Even		[9] 3rd 12		[15] Double Number" << '\n';
		cout << "[4] Odd			[10] Column		[16] Single Number" << '\n';
		cout << "[5] 1 to 18		[11] Six Number		[17] Exit" << '\n';
		cout << "[6] 19 to 36		[12] Five Number" << '\n';
		cout << endl;
	
	//Status of Player
		cout << "Current balance: " << balance << '\n';
		cout << "Wins: " << wins << " || Losses: " << losses << '\n'; 
		cout << "Choose a bet: ";
		cin >> choices;
		if (cin.fail()){
			cin.clear();
			cin.ignore(10000000, '\n');
			cout << "Invalid input. Please try again." << '\n'<< '\n';
			continue;
		}
		else{
			break;
			}
		}
		
		if (choices > 17){
				cout << endl;
				cout << "Invalid input. Please try again." << '\n';
					continue;
			}
			
		while(!bet_confirmed){
			switch (choices){
				case 1:
					cout << endl;
					cout << "All Black" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
						if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						else if (bet >= 5){	
						}	
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					while(!cin.fail()){
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_all_black = bet + pot_all_black;
						all_black = true;
						bet_confirmed = true;
					}
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
	
	
				case 2:
					cout << endl;
					cout << "All Red" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
						
					//Resets invalid inputs.
					while(!cin.fail()){
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_all_red = bet + pot_all_red;
						all_red = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 3:
					cout << endl;
					cout << "Even" << '\n';
					
					//Resets invalid inputs.
					while(!cin.fail()){
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
						
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_even = bet + pot_even;
						even = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 4:
					cout << endl;
					cout << "Odd" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_odd = bet + pot_odd;
						odd = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 5:
					cout << endl;
					cout << "1 to 18" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
						
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_1to18 = bet + pot_1to18;
						_1to18 = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 6:
					cout << endl;
					cout << "19 to 36" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_19to36 = bet + pot_19to36;
						_19to36 = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 7:
					cout << endl;
					cout << "1st 12" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_first12 = bet + pot_first12;
						first12 = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 8:
					cout << endl;
					cout << "2nd 12" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_second12 = bet + pot_second12;
						second12 = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 9:
					cout << endl;
					cout << "3rd 12" << '\n';
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						pot_third12 = bet + pot_third12;
						third12 = false;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 10:
					cout << endl;
					cout << "Column" << '\n';
					cout <<endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Column Bets:" << '\n';
					cout << "[1] R-3, B-6, R-9, R-12, B-15, R-18, R-21, B-24, R-27, R-30, B-33, R-36" << '\n';
					cout << "[2] B-2, R-5, B-8, B-11, R-14, B-17, B-20, R-23, B-26, B-29, R-32, B-35" << '\n';
					cout << "[3] R-1, B-4, R-7, B-10, B-13, R-16, B-19, B-22, R-25, R-28, B-31, R-34" << '\n';
					cout << endl;
					
					cout << "Which Column would you like to bet?: ";
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 >= 4){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
						
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices2){
							case 1:
								pot_column[0] = bet + pot_column[0];
								column [0] = true;
								break;
								
							case 2:
								pot_column[1] = bet + pot_column[1];
								column [1] = true;
								break;
							
							case 3:
								pot_column[2] = bet + pot_column[2];
								column [2] = true;
								break;
						}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 11:
					cout << endl;
					cout << "Six Number" << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Six Number Bets:" << '\n';
					cout << "[1] R-1, B-2, R-3, B-4, R-5, B-6		[7] B-19, B-20, R-21, B-22, R-23, B-24" << '\n';
					cout << "[2] B-4, R-5, B-6, R-7, B-8, R-9		[8] B-22, R-23, B-24, R-25, B-26, R-27" << '\n';
					cout << "[3] R-7, B-8, R-9, B-10, B-11, R-12		[9] R-25, B-26, R-27, R-28, B-29, R-30" << '\n';
					cout << "[4] B-10, B-11, R-12, B-13, R-14, B-15 		[10] R-28, B-29, R-30, B-31, R-32, B-33" << '\n';
					cout << "[5] B-13, R-14, B-15, R-16, B-17, R-18		[11] B-31, R-32, B-33, R-34, B-35, R-36" << '\n';
					cout << "[6] R-16, B-17, R-18, B-19, B-20, R-21 " << '\n';
					cout << endl;
					
					cout << "Which Six Number bets would you like to bet?: ";
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 > 11){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
					
					
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices2){
								case 1:
									pot_sixnum[0] = bet + pot_sixnum[0];
									sixnum[0] = true;
									break;
								
								case 2:
									pot_sixnum[1] = bet + pot_sixnum[1];
									sixnum[1] = true;
									break;
								
								case 3:
									pot_sixnum[2] = bet + pot_sixnum[2];
									sixnum[2] = true;
									break;
								
								case 4:
									pot_sixnum[3] = bet + pot_sixnum[3];
									sixnum[3] = true;
									break;
									
								case 5:
									pot_sixnum[4] = bet + pot_sixnum[4];
									sixnum[4] = true;
									break;
									
								case 6:
									pot_sixnum[5] = bet + pot_sixnum[5];
									sixnum[5] = true;
									break;
									
								case 7:
									pot_sixnum[6] = bet + pot_sixnum[6];
									sixnum[6] = true;
									break;
									
								case 8:
									pot_sixnum[7] = bet + pot_sixnum[7];
									sixnum[7] = true;
									break;
									
								case 9:
									pot_sixnum[8] = bet + pot_sixnum[8];
									sixnum[8] = true;
									break;
									
								case 10:
									pot_sixnum[9] = bet + pot_sixnum[9];
									sixnum[9] = true;
									break;
									
								case 11:
									pot_sixnum[10] = bet + pot_sixnum[10];
									sixnum[10] = true;
									break;	
							}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
			
				case 12:
					cout << endl;
					cout << "Five Number" << '\n';
					cout << "Note: This bet only contains: 0, 00, R-1, B-2, R-3." << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						fivenum = true;
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
			
				case 13:
					cout << endl;
					cout << "Four Number" << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Four Number Bets:" << '\n';
					cout << "[1] R-1, B-2, B-4, R-5		[12] B-2, R-3, R-5, B-6" << '\n';
					cout << "[2] B-4, R-5, R-7, B-8		[13] R-5, B-6, B-8, R-9" << '\n';
					cout << "[3] R-7, B-8, B-10, B-11	[14] B-8, R-9, B-11, R-12" << '\n';
					cout << "[4] B-10, B11, B-13, R-14	[15] B-11, R-12, R-14, B-15" << '\n';
					cout << "[5] B-13, R-14, R-16, B-17	[16] R-14, B-15, B-17, R-18" << '\n';
					cout << "[6] R-16, B-17, B-19, B-20	[17] B-17, R-18, B-20, R-21" << '\n';
					cout << "[7] B-19, B-20, B-22, R-23 	[18] B-20, R-21, R-23, B-24" << '\n';
					cout << "[8] B-22, R-23, R-25, B-26	[19] R-23, B-24, B-26, R-27" << '\n';
					cout << "[9] R-25, B-26, R-28, B-29	[20] B-26, R-27, B-29, R-30" << '\n';
					cout << "[10] R-28, B-29, B-31, R-32	[21] B-29, R-30, R-32, B-33" << '\n';
					cout << "[11] B-31, R-32, R-34, B-35	[22] R-32, B-33, B-35, R-36" << '\n';
					cout << endl;
					
					cout << "Which Four Number bets would you like to bet?: " << '\n';
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 > 22){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
						
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices){
							case 1:
								fournum[0] = true;
								break;
								
							case 2:
								fournum[1] = true;
								break;
								
							case 3:
								fournum[2] = true;
								break;
								
							case 4:
								fournum[3] = true;
								break;
								
							case 5:
								fournum[4] = true;
								break;
								
							case 6:
								fournum[5] = true;
								break;
								
							case 7:
								fournum[6] = true;
								break;
								
							case 8:
								fournum[7] = true;
								break;
								
							case 9:
								fournum[8] = true;
								break;
								
							case 10:
								fournum[9] = true;
								break;
								
							case 11:
								fournum[10] = true;
								break;
								
							case 12:
								fournum[11] = true;
								break;
								
							case 13:
								fournum[12] = true;
								break;
								
							case 14:
								fournum[13] = true;
								break;
								
							case 15:
								fournum[14] = true;
								break;
								
							case 16:
								fournum[15] = true;
								break;
								
							case 17:
								fournum[16] = true;
								break;
								
							case 18:
								fournum[17] = true;
								break;
								
							case 19:
								fournum[18] = true;
								break;
								
							case 20:
								fournum[19] = true;
								break;
								
							case 21:
								fournum[20] = true;
								break;
								
							case 22:
								fournum[21] = true;
								break;
						}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
			
				case 14:
					cout << endl;
					cout << "Three Number" << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Three Number Bets:" << '\n';
					cout << "[1] R-1, B-2, R-3		[7] B-19, B-20, R-21" << '\n';
					cout << "[2] B-4, R-5, B-6		[8] B-22, R-23, B-24" << '\n';
					cout << "[3] R-7, B-8, R-9		[9] R-25, B-26, R-27" << '\n';
					cout << "[4] B-10, B11, R-12		[10] R-28, B-29, R-30" << '\n';
					cout << "[5] B-13, R-14, B-15		[11] B-31, R-32, B-33" << '\n';
					cout << "[6] R-16, B-17, R-18		[12] R-34, B-35, R-36" << '\n';
					cout << endl;
					
					cout << "Which Three Number bets would you like to bet?: " << '\n';
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 > 12){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
						
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices2){
							case 1:
								threenum [0] = true;
								break;
								
							case 2:
								threenum [1] = true;
								break;
								
							case 3:
								threenum [2] = true;
								break;
								
							case 4:
								threenum [3] = true;
								break;
								
							case 5:
								threenum [4] = true;
								break;
								
							case 6:
								threenum [5] = true;
								break;
								
							case 7:
								threenum [6] = true;
								break;
								
							case 8:
								threenum [7] = true;
								break;
								
							case 9:
								threenum [8] = true;
								break;
								
							case 10:
								threenum [9] = true;
								break;
								
							case 11:
								threenum [10] = true;
								break;
								
							case 12:
								threenum [11] = true;
								break;
						}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
			
				case 15:
					cout << endl;
					cout << "Double Number" << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Double Number Bets:" << '\n';
					cout << "Vertical:" << '\n';
					cout << "[1] R-1, B-2		[10] R-28, B-29		[19] B-20, R-21" << '\n';
					cout << "[2] B-4, R-5		[11] B-31, R-32		[20] R-23, B-24" << '\n';
					cout << "[3] R-7, B-8		[12] R-34, B-35		[21] B-26, R-27" << '\n';
					cout << "[4] B-10, B11		[13] B-2, R-3		[22] B-29, R-30" << '\n';
					cout << "[5] B-13, R-14		[14] R-5, B-6		[23] R-32, B-33" << '\n';
					cout << "[6] R-16, B-17		[15] B-8, R-9		[24] B-35, R-36" << '\n';
					cout << "[7] B-19, B-20		[16] B-11, R-12" << '\n';
					cout << "[8] B-22, R-23		[17] R-14, B-15" << '\n';
					cout << "[9] R-25, B-26		[18] B-17, R-18" << '\n';
					cout << endl;
					
					cout << "Horizontal:" << '\n';
					cout << "[25] R-1, B-4		[34] B-10, B-13		[43] B-19, B-22		[52] R-28, B-31" << '\n';
					cout << "[26] B-2, R-5		[35] B-11, R-14		[44] B-20, R-23		[53] B-29, R-32" << '\n';
					cout << "[27] R-3, B-6		[36] R-12, B-15		[45] R-21, B-24		[54] R-30, B-33" << '\n';
					cout << "[28] B-4, R-7		[37] B-13, R-16		[46] B-22, R-25		[55] B-31, R-34" << '\n';
					cout << "[29] R-5, B-8		[38] R-14, B-17		[47] R-23, B-26		[56] R-32, B-35" << '\n';
					cout << "[30] B-6, R-9		[39] B-15, R-18		[48] B-24, R-27		[57] B-33, R-36" << '\n';
					cout << "[31] R-7, B-10		[40] R-16, B-19		[49] R-25, R-28" << '\n';
					cout << "[32] B-8, B-11		[41] B-17, B-20		[50] B-26, B-29" << '\n';
					cout << "[33] R-9, R-12		[42] R-18, R-21		[51] R-27, R-30" << '\n';
					cout << endl;
					
					cout << "Which Double Number bets would you like to bet?: " << '\n';
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 > 57){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
						
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
						
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices2){
							case 1:
								pot_doublenum [0] = bet + pot_doublenum[0];
								doublenum [0] = true;
								break;
								
							case 2:
								pot_doublenum [1] = bet + pot_doublenum[1];
								doublenum [1] = true;
								break;
								
							case 3:
								pot_doublenum [2] = bet + pot_doublenum[2];
								doublenum [2] = true;
								break;
								
							case 4:
								pot_doublenum [3] = bet + pot_doublenum[3];
								doublenum [3] = true;
								break;
								
							case 5:
								pot_doublenum [4] = bet + pot_doublenum[4];
								doublenum [4] = true;
								break;
								
							case 6:
								pot_doublenum [5] = bet + pot_doublenum[5];
								doublenum [5] = true;
								break;
								
							case 7:
								pot_doublenum [6] = bet + pot_doublenum[6];
								doublenum [6] = true;
								break;
								
							case 8:
								pot_doublenum [7] = bet + pot_doublenum[7];
								doublenum [7] = true;
								break;
								
							case 9:
								pot_doublenum [8] = bet + pot_doublenum[8];
								doublenum [8] = true;
								break;
								
							case 10:
								pot_doublenum [9] = bet + pot_doublenum[9];
								doublenum [9] = true;
								break;
								
							case 11:
								pot_doublenum [10] = bet + pot_doublenum[10];
								doublenum [10] = true;
								break;
								
							case 12:
								pot_doublenum [11] = bet + pot_doublenum[11];
								doublenum [11] = true;
								break;
								
							case 13:
								pot_doublenum [12] = bet + pot_doublenum[12];
								doublenum [12] = true;
								break;
								
							case 14:
								pot_doublenum [13] = bet + pot_doublenum[13];
								doublenum [13] = true;
								break;
								
							case 15:
								pot_doublenum [14] = bet + pot_doublenum[14];
								doublenum [14] = true;
								break;
								
							case 16:
								pot_doublenum [15] = bet + pot_doublenum[15];
								doublenum [15] = true;
								break;
								
							case 17:
								pot_doublenum [16] = bet + pot_doublenum[16];
								doublenum [16] = true;
								break;
								
							case 18:
								pot_doublenum [17] = bet + pot_doublenum[17];
								doublenum [17] = true;
								break;
								
							case 19:
								pot_doublenum [18] = bet + pot_doublenum[18];
								doublenum [18] = true;
								break;
								
							case 20:
								pot_doublenum [19] = bet + pot_doublenum[19];
								doublenum [19] = true;
								break;
								
							case 21:
								pot_doublenum [20] = bet + pot_doublenum[20];
								doublenum [20] = true;
								break;
								
							case 22:
								pot_doublenum [21] = bet + pot_doublenum[21];
								doublenum [21] = true;
								break;
								
							case 23:
								pot_doublenum [22] = bet + pot_doublenum[22];
								doublenum [22] = true;
								break;
								
							case 24:
								pot_doublenum [23] = bet + pot_doublenum[23];
								doublenum [23] = true;
								break;
								
							case 25:
								pot_doublenum [24] = bet + pot_doublenum[24];
								doublenum [24] = true;
								break;
								
							case 26:
								pot_doublenum [25] = bet + pot_doublenum[25];
								doublenum [25] = true;
								break;
								
							case 27:
								pot_doublenum [26] = bet + pot_doublenum[26];
								doublenum [26] = true;
								break;
								
							case 28:
								pot_doublenum [27] = bet + pot_doublenum[27];
								doublenum [27] = true;
								break;
								
							case 29:
								pot_doublenum [28] = bet + pot_doublenum[28];
								doublenum [28] = true;
								break;
								
							case 30:
								pot_doublenum [29] = bet + pot_doublenum[29];
								doublenum [29] = true;
								break;
								
							case 31:
								pot_doublenum [30] = bet + pot_doublenum[30];
								doublenum [30] = true;
								break;
								
							case 32:
								pot_doublenum [31] = bet + pot_doublenum[31];
								doublenum [31] = true;
								break;
								
							case 33:
								pot_doublenum [32] = bet + pot_doublenum[32];
								doublenum [32] = true;
								break;
								
							case 34:
								pot_doublenum [33] = bet + pot_doublenum[33];
								doublenum [33] = true;
								break;
								
							case 35:
								pot_doublenum [34] = bet + pot_doublenum[34];
								doublenum [34] = true;
								break;
								
							case 36:
								pot_doublenum [35] = bet + pot_doublenum[35];
								doublenum [35] = true;
								break;
								
							case 37:
								pot_doublenum [36] = bet + pot_doublenum[36];
								doublenum [36] = true;
								break;
								
							case 38:
								pot_doublenum [37] = bet + pot_doublenum[37];
								doublenum [37] = true;
								break;
								
							case 39:
								pot_doublenum [38] = bet + pot_doublenum[38];
								doublenum [38] = true;
								break;
								
							case 40:
								pot_doublenum [39] = bet + pot_doublenum[39];
								doublenum [39] = true;
								break;
								
							case 41:
								pot_doublenum [40] = bet + pot_doublenum[40];
								doublenum [40] = true;
								break;
								
							case 42:
								pot_doublenum [41] = bet + pot_doublenum[41];
								doublenum [41] = true;
								break;
								
							case 43:
								pot_doublenum [42] = bet + pot_doublenum[42];
								doublenum [42] = true;
								break;
								
							case 44:
								pot_doublenum [43] = bet + pot_doublenum[43];
								doublenum [43] = true;
								break;
								
							case 45:
								pot_doublenum [44] = bet + pot_doublenum[44];
								doublenum [44] = true;
								break;
								
							case 46:
								pot_doublenum [45] = bet + pot_doublenum[45];
								doublenum [45] = true;
								break;
								
							case 47:
								pot_doublenum [46] = bet + pot_doublenum[46];
								doublenum [46] = true;
								break;
								
							case 48:
								pot_doublenum [47] = bet + pot_doublenum[47];
								doublenum [47] = true;
								break;
								
							case 49:
								pot_doublenum [48] = bet + pot_doublenum[48];
								doublenum [48] = true;
								break;
								
							case 50:
								pot_doublenum [49] = bet + pot_doublenum[49];
								doublenum [49] = true;
								break;
								
							case 51:
								pot_doublenum [50] = bet + pot_doublenum[50];
								doublenum [50] = true;
								break;
								
							case 52:
								pot_doublenum [51] = bet + pot_doublenum[51];
								doublenum [51] = true;
								break;
								
							case 53:
								pot_doublenum [52] = bet + pot_doublenum[52];
								doublenum [52] = true;
								break;
								
							case 54:
								pot_doublenum [53] = bet + pot_doublenum[53];
								doublenum [53] = true;
								break;
								
							case 55:
								pot_doublenum [54] = bet + pot_doublenum[54];
								doublenum [54] = true;
								break;
								
							case 56:
								pot_doublenum [55] = bet + pot_doublenum[55];
								doublenum [55] = true;
								break;
								
							case 57:
								pot_doublenum [56] = bet + pot_doublenum[56];
								doublenum [56] = true;
								break;
						}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
		
				case 16:
					cout << endl;
					cout << "Single Number" << '\n';
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Single Number Bets:" << '\n';
					cout << "[1] 0		[10] B-8	[19] B-17	[28] B-26	[37] B-35" << '\n';
					cout << "[2] 00		[11] R-9	[20] R-18	[29] R-27	[38] R-36" << '\n';
					cout << "[3] R-1		[12] B-10	[21] B-19	[30] R-28" << '\n';
					cout << "[4] B-2		[13] B-11	[22] B-20	[31] B-29" << '\n';
					cout << "[5] R-3		[14] R-12	[23] R-21	[32] R-30" << '\n';
					cout << "[6] B-4		[15] B-13	[24] B-22	[33] B-31" << '\n';
					cout << "[7] R-5		[16] R-14	[25] R-23	[34] R-32" << '\n';
					cout << "[8] B-6		[17] B-15	[26] B-24	[35] B-33" << '\n';
					cout << "[9] R-7		[18] R-16	[27] R-25	[36] R-34" << '\n';
					cout << endl;
					
					cout << "Which Three Number bets would you like to bet?: " << '\n';
					cin >> choices2;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (choices2 > 38){
							cout << endl;
							cout << "Invalid input. Please try again." << '\n';
							continue;
						}
						
					cout << endl;
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "How much would you like to bet?: ";
					cin >> bet;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
						if (bet > balance){
							cout << "Insufficient balance." << '\n';
							continue;
						}
						
						else if (bet >= 5){	
						}	
						
						else {
							cout << "Your bet is not enough. The amount must be 5 or above." << '\n';
							continue;
						}
					
					//Resets invalid inputs.
					while (!cin.fail()) {
					cout << "Are you sure with this bet? (Y/N): ";
					cin >> Y_N;
					if (cin.fail()){
						cin.clear();
						cin.ignore(10000000, '\n');
						cout << "Invalid input. Please try again." << '\n'<< '\n';
						continue;
						}
						else{
						break;
						}
					}
					
					if (Y_N == "Y" || Y_N == "y"){
						balance = balance - bet;
						switch(choices2){
							case 1:
								pot_singlenum[0] = bet + pot_singlenum[0];
								singlenum [0] = true;
								break;
								
							case 2:
								pot_singlenum[1] = bet + pot_singlenum[1];
								singlenum [1] = true;
								break;
								
							case 3:
								pot_singlenum[2] = bet + pot_singlenum[2];
								singlenum [2] = true;
								break;
								
							case 4:
								pot_singlenum[3] = bet + pot_singlenum[3];
								singlenum [3] = true;
								break;
								
							case 5:
								pot_singlenum[4] = bet + pot_singlenum[4];
								singlenum [4] = true;
								break;
								
							case 6:
								pot_singlenum[5] = bet + pot_singlenum[5];
								singlenum [5] = true;
								break;
								
							case 7:
								pot_singlenum[6] = bet + pot_singlenum[6];
								singlenum [6] = true;
								break;
								
							case 8:
								pot_singlenum[7] = bet + pot_singlenum[7];
								singlenum [7] = true;
								break;
								
							case 9:
								pot_singlenum[8] = bet + pot_singlenum[8];
								singlenum [8] = true;
								break;
								
							case 10:
								pot_singlenum[9] = bet + pot_singlenum[9];
								singlenum [9] = true;
								break;
								
							case 11:
								pot_singlenum[10] = bet + pot_singlenum[10];
								singlenum [10] = true;
								break;
								
							case 12:
								pot_singlenum[11] = bet + pot_singlenum[11];
								singlenum [11] = true;
								break;
								
							case 13:
								pot_singlenum[12] = bet + pot_singlenum[12];
								singlenum [12] = true;
								break;
								
							case 14:
								pot_singlenum[13] = bet + pot_singlenum[13];
								singlenum [13] = true;
								break;
								
							case 15:
								pot_singlenum[14] = bet + pot_singlenum[14];
								singlenum [14] = true;
								break;
								
							case 16:
								pot_singlenum[15] = bet + pot_singlenum[15];
								singlenum [15] = true;
								break;
								
							case 17:
								pot_singlenum[16] = bet + pot_singlenum[16];
								singlenum [16] = true;
								break;
								
							case 18:
								pot_singlenum[17] = bet + pot_singlenum[17];
								singlenum [17] = true;
								break;
								
							case 19:
								pot_singlenum[18] = bet + pot_singlenum[18];
								singlenum [18] = true;
								break;
								
							case 20:
								pot_singlenum[19] = bet + pot_singlenum[19];
								singlenum [19] = true;
								break;
								
							case 21:
								pot_singlenum[20] = bet + pot_singlenum[20];
								singlenum [20] = true;
								break;
								
							case 22:
								pot_singlenum[21] = bet + pot_singlenum[21];
								singlenum [21] = true;
								break;
								
							case 23:
								pot_singlenum[22] = bet + pot_singlenum[22];
								singlenum [22] = true;
								break;
								
							case 24:
								pot_singlenum[23] = bet + pot_singlenum[23];
								singlenum [23] = true;
								break;
								
							case 25:
								pot_singlenum[24] = bet + pot_singlenum[24];
								singlenum [24] = true;
								break;
								
							case 26:
								pot_singlenum[25] = bet + pot_singlenum[25];
								singlenum [25] = true;
								break;
								
							case 27:
								pot_singlenum[26] = bet + pot_singlenum[26];
								singlenum [26] = true;
								break;
								
							case 28:
								pot_singlenum[27] = bet + pot_singlenum[27];
								singlenum [27] = true;
								break;
								
							case 29:
								pot_singlenum[28] = bet + pot_singlenum[28];
								singlenum [28] = true;
								break;
								
							case 30:
								pot_singlenum[29] = bet + pot_singlenum[29];
								singlenum [29] = true;
								break;
								
							case 31:
								pot_singlenum[30] = bet + pot_singlenum[30];
								singlenum [30] = true;
								break;
								
							case 32:
								pot_singlenum[31] = bet + pot_singlenum[31];
								singlenum [31] = true;
								break;
								
							case 33:
								pot_singlenum[32] = bet + pot_singlenum[32];
								singlenum [32] = true;
								break;
								
							case 34:
								pot_singlenum[33] = bet + pot_singlenum[33];
								singlenum [33] = true;
								break;
								
							case 35:
								pot_singlenum[34] = bet + pot_singlenum[34];
								singlenum [34] = true;
								break;
								
							case 36:
								pot_singlenum[35] = bet + pot_singlenum[35];
								singlenum [35] = true;
								break;
								
							case 37:
								pot_singlenum[36] = bet + pot_singlenum[36];
								singlenum [36] = true;
								break;
								
							case 38:
								pot_singlenum[37] = bet + pot_singlenum[37];
								singlenum [37] = true;
								break;							
						}
						bet_confirmed = true;
					}
			
					else if (Y_N == "N" || Y_N == "n"){
						continue;
					}
			
					else {
						cout << "Invalid input. Please try again." << '\n';
						continue;
					}
					break;
			
				case 17:
					cout << endl;
					cout << "Aww. Done already?" << '\n';
					cout << "Thanks for trying.";
					return 0;
			} 
		}
		
		//Resets bet_confirmed, choices and choices2.
		bet_confirmed = false;	
		choices = 0;
		choices2 = 0;
		//If balance is less the 5.
			if (balance < 5){
				break;
			}
			
		cout << endl;
		cout << "Are you going to add a bet? (Y/N): ";
		cin >> Y_N;
	
			if (Y_N == "Y" || Y_N == "y"){
				continue;
			}
	
			else if (Y_N == "N" || Y_N == "n"){
				break;
			}
	
			else {
				cout << "Invalid input. Please try again." << '\n';
				continue;
			}
	}
	
	//Roulette
		cout << endl;
		cout << "The roulette is spinning..." << '\n';
		cout << endl;
		roulette = (rand() % roulette_limit) + 1;
		
		if (roulette == 37){
			roulette = zeroes[0];
		}
		
		else if (roulette == 38){
			roulette = zeroes[1];
		}
		
		cout << "The roulette landed on number: " << roulette;
		cout << endl;
		
	//Payouts
		//All Black
		if ((all_black == true) && (roulette == 2 || roulette == 4 || roulette == 6 || roulette == 8 || roulette == 10 || roulette == 11 || roulette == 13 || roulette == 15 || roulette == 17 || roulette == 19 || roulette == 20 || roulette == 22 || roulette == 24 || roulette == 26 || roulette == 29 || roulette == 31 || roulette == 33 || roulette == 35 )){
			pot_all_black = pot_all_black * 2;
			total = total + pot_all_black;
		}
		
		//All Red
		else if ((all_red == true) && (roulette == 1 || roulette == 3 || roulette == 5 || roulette == 7 || roulette == 9 || roulette == 12 || roulette == 14 || roulette == 16 || roulette == 18 || roulette == 21 || roulette == 23 || roulette == 25 || roulette == 27 || roulette == 28 || roulette == 30 || roulette == 32 || roulette == 34 || roulette == 36)){
			pot_all_red = pot_all_red * 2;
			total = total + pot_all_red;
		}
		
		//Even
		else if ((even == true) && (roulette == 2 || roulette == 4 || roulette == 6 || roulette == 8 || roulette == 10 || roulette == 12 || roulette == 14 || roulette == 16 || roulette == 18 || roulette == 20 || roulette == 22 || roulette == 24 || roulette == 26 || roulette == 28 || roulette == 30 || roulette == 32 || roulette == 34 || roulette == 36)){
			pot_even = pot_even * 2;
			total = total + pot_even;
		}
		
		//Odd
		else if ((odd == true ) && (roulette == 1 || roulette == 3 || roulette == 5 || roulette == 7 || roulette == 9 || roulette == 11 || roulette == 13 || roulette == 15 || roulette == 17 || roulette == 19 || roulette == 21 || roulette == 23 || roulette == 25 || roulette == 27 || roulette == 29 || roulette == 31 || roulette == 33 || roulette == 35)){
			pot_odd = pot_odd * 2;
			total = total + pot_odd;
		}
		
		//1 to 18
		else if ((_1to18 == true) && (roulette == 1 || roulette == 2 || roulette == 3 || roulette == 4 || roulette == 5 || roulette == 6 || roulette == 7 || roulette == 8 || roulette == 9 || roulette == 10 || roulette == 11 || roulette == 12 || roulette == 13 || roulette == 14 || roulette == 15 || roulette == 16 || roulette == 17 || roulette == 18)){
			pot_1to18 = pot_1to18 * 2;
			total = total + pot_1to18;
		}
		
		//19 to 36
		else if ((_19to36 == true) && (roulette == 19 || roulette == 20 || roulette == 21 || roulette == 22 || roulette == 23 || roulette == 24 || roulette == 25 || roulette == 26 || roulette == 27 || roulette == 28 || roulette == 29 || roulette == 30 || roulette == 31 || roulette == 32 || roulette == 33 || roulette == 34 || roulette == 35 || roulette == 36)){
			pot_19to36 = pot_19to36 * 2;
			total = total + pot_19to36;
		}
		
		//First 12
		else if ((first12 == true) && (roulette == roulette == 1 || roulette == 2 || roulette == 3 || roulette == 4 || roulette == 5 || roulette == 6 || roulette == 7 || roulette == 8 || roulette == 9 || roulette == 10 || roulette == 11 || roulette == 12)){
			pot_first12 = pot_first12 * 3;
			total = total + pot_first12;
		}
		
		//Second 12
		else if ((second12 == true) && (roulette == 13 || roulette == 14 || roulette == 15 || roulette == 16 || roulette == 17 || roulette == 18 || roulette == 19 || roulette == 20 || roulette == 21 || roulette == 22 || roulette == 23 || roulette == 24)){
			pot_second12 = pot_second12 * 3;
			total = total + pot_second12;
		}
		
		//Third 12
		else if ((third12 == true) && (roulette == 25 || roulette == 26 || roulette == 27 || roulette == 28 || roulette == 29 || roulette == 30 || roulette == 31 || roulette == 32 || roulette == 33 || roulette == 34 || roulette == 35 || roulette == 36)){
			pot_third12 = pot_third12 * 3;
			total = total + pot_third12;
		}
		
		//Column Bets
		else if ((column [0] == true) && (roulette == 3 || roulette == 6 || roulette == 9 || roulette == 12 || roulette == 15 || roulette == 18 || roulette == 21 || roulette == 24 || roulette == 27 || roulette == 30 || roulette == 33 || roulette == 36)){
			pot_column[0] = pot_column[0] * 3;
			total = total + pot_column[0];
		}
		
		else if ((column [1] == true) && (roulette == 2 || roulette == 5 || roulette == 8 || roulette == 11 || roulette == 14 || roulette == 17 || roulette == 20 || roulette == 23 || roulette == 26 || roulette == 29 || roulette == 32 || roulette == 35)){
			pot_column[1] = pot_column[1] * 3;
			total = total + pot_column[1];
		}
		
		else if ((column [2] == true) && (roulette == 1 || roulette == 4 || roulette == 7 || roulette == 10 || roulette == 13 || roulette == 16 || roulette == 19 || roulette == 22 || roulette == 25 || roulette == 28 || roulette == 31 || roulette == 34)){
			pot_column[2] = pot_column[2] * 3;
			total = total + pot_column[1];
		}
		
		//Six Number Bets
		else if ((sixnum[0] == true) && (roulette == 1 || roulette == 2 || roulette == 3 || roulette == 4 || roulette == 5 || roulette == 6)){
			pot_sixnum[0] = pot_sixnum[0] * 6;
			total = total + pot_sixnum[0];
		}
		
		else if ((sixnum[1] == true) && (roulette == 4 || roulette == 5 || roulette == 6 || roulette == 7 || roulette == 8 || roulette == 9)){
			pot_sixnum[1] = pot_sixnum[1] * 6;
			total = total + pot_sixnum[1];
		}
		
		else if ((sixnum[2] == true) && (roulette == 7 || roulette == 8 || roulette == 9 || roulette == 10 || roulette == 11 || roulette == 12)){
			pot_sixnum[2] = pot_sixnum[2] * 6;
			total = total + pot_sixnum[2];
		}
		
		else if ((sixnum[3] == true) && (roulette == roulette == 10 || roulette == 11 || roulette == 12 || roulette == 13 || roulette == 14 || roulette == 15)){
			pot_sixnum[3] = pot_sixnum[3] * 6;
			total = total + pot_sixnum[3];
		}
		
		else if ((sixnum[4] == true) && (roulette == 13 || roulette == 14 || roulette == 15 || roulette == 16 || roulette == 17 || roulette == 18)){
			pot_sixnum[4] = pot_sixnum[4] * 6;
			total = total + pot_sixnum[4];
		}
		
		else if ((sixnum[5] == true) && (roulette == 16 || roulette == 17 || roulette == 18 || roulette == 19 || roulette == 20 || roulette == 21)){
			pot_sixnum[5] = pot_sixnum[5] * 6;
			total = total + pot_sixnum[5];
		}
		
		else if ((sixnum[6] == true) && (roulette == 19 || roulette == 20 || roulette == 21 || roulette == 22 || roulette == 23 || roulette == 24)){
			pot_sixnum[6] = pot_sixnum[6] * 6;
			total = total + pot_sixnum[6];
		}
		
		else if ((sixnum[7] == true) && (roulette == 22 || roulette == 23 || roulette == 24 || roulette == 25 || roulette == 26 || roulette == 27)){
			pot_sixnum[7] = pot_sixnum[7] * 6;
			total = total + pot_sixnum[7];
		}
		
		else if ((sixnum[8] == true) && (roulette == 25 || roulette == 26 || roulette == 27 || roulette == 28 || roulette == 29 || roulette == 30)){
			pot_sixnum[8] = pot_sixnum[8] * 6;
			total = total + pot_sixnum[8];
		}
		
		else if ((sixnum[9] == true) && (roulette == 28 || roulette == 29 || roulette == 30 || roulette == 31 || roulette == 32 || roulette == 33)){
			pot_sixnum[9] = pot_sixnum[9] * 6;
			total = total + pot_sixnum[9];
		}
		
		else if ((sixnum[10] == true) && (roulette == 31 || roulette == 32 || roulette == 33 || roulette == 34 || roulette == 35 || roulette == 36)){
			pot_sixnum[10] = pot_sixnum[10] * 6;
			total = total + pot_sixnum[10];
		}
		
		//Five Number Bet
		else if ((fivenum == true) && (roulette == 0 || roulette == 00 || roulette == 1 || roulette == 2 || roulette == 3)){
			pot_fivenum = pot_fivenum * 7;
			total = total + pot_fivenum;
		}
		
		//Four Number Bets
		else if ((fournum[0] == true) && (roulette == 1 || roulette == 2 || roulette == 4 || roulette == 5)){
			pot_fournum[0] = pot_fournum[0] * 9;
			total = total + pot_fournum[0];
		}
		
		else if ((fournum[1] == true) && (roulette == 4 || roulette == 5 || roulette == 7 || roulette == 8)){
			pot_fournum[1] = pot_fournum[1] * 9;
			total = total + pot_fournum[1];
		}
		
		else if ((fournum[2] == true) && (roulette == 7 || roulette == 8 || roulette == 10 || roulette == 11)){
			pot_fournum[2] = pot_fournum[2] * 9;
			total = total + pot_fournum[2];
		}
		
		else if ((fournum[3] == true) && (roulette == 13 || roulette == 14 || roulette == 16 || roulette == 17)){
			pot_fournum[3] = pot_fournum[3] * 9;
			total = total + pot_fournum[3];
		}
		
		else if ((fournum[4] == true) && (roulette == 16 || roulette == 17 || roulette == 19 || roulette == 20)){
			pot_fournum[4] = pot_fournum[4] * 9;
			total = total + pot_fournum[4];
		}
		
		else if ((fournum[5] == true) && (roulette == 16 || roulette == 17 || roulette == 19 || roulette == 20)){
			pot_fournum[5] = pot_fournum[5] * 9;
			total = total + pot_fournum[5];
		}
		
		else if ((fournum[6] == true) && (roulette == 19 || roulette == 20 || roulette == 22 || roulette == 23)){
			pot_fournum[6] = pot_fournum[6] * 9;
			total = total + pot_fournum[6];
		}
		
		else if ((fournum[7] == true) && (roulette == 22 || roulette == 23 || roulette == 25 || roulette == 26)){
			pot_fournum[7] = pot_fournum[7] * 9;
			total = total + pot_fournum[7];
		}
		
		else if ((fournum[8] == true) && (roulette == 25 || roulette == 26 || roulette == 28 || roulette == 29)){
			pot_fournum[8] = pot_fournum[8] * 9;
			total = total + pot_fournum[8];
		}
		
		else if ((fournum[9] == true) && (roulette == 28 || roulette == 29 || roulette == 31 || roulette == 32)){
			pot_fournum[9] = pot_fournum[9] * 9;
			total = total + pot_fournum[9];
		}
		
		else if ((fournum[10] == true) && (roulette == 31 || roulette == 32 || roulette == 34 || roulette == 35)){
			pot_fournum[10] = pot_fournum[10] * 9;
			total = total + pot_fournum[10];
		}
		
		else if ((fournum[11] == true) && (roulette == 2 || roulette == 3 || roulette == 5 || roulette == 6)){
			pot_fournum[11] = pot_fournum[11] * 9;
			total = total + pot_fournum[11];
		}
		
		else if ((fournum[12] == true) && (roulette == 5 || roulette == 6 || roulette == 8 || roulette == 9)){
			pot_fournum[12] = pot_fournum[12] * 9;
			total = total + pot_fournum[12];
		}
		
		else if ((fournum[13] == true) && (roulette == roulette == 8 || roulette == 9 || roulette == 11 || roulette == 12)){
			pot_fournum[13] = pot_fournum[13] * 9;
			total = total + pot_fournum[13];
		}
		
		else if ((fournum[14] == true) && (roulette == 11 || roulette == 12 || roulette == 14 || roulette == 15)){
			pot_fournum[14] = pot_fournum[14] * 9;
			total = total + pot_fournum[14];
		}
		
		else if ((fournum[15] == true) && (roulette == 14 || roulette == 15 || roulette == 17 || roulette == 18)){
			pot_fournum[15] = pot_fournum[15] * 9;
			total = total + pot_fournum[15];
		}
		
		else if ((fournum[16] == true) && (roulette == 17 || roulette == 18 || roulette == 20 || roulette == 21)){
			pot_fournum[16] = pot_fournum[16] * 9;
			total = total + pot_fournum[16];
		}
		
		else if ((fournum[17] == true) && (roulette == 20 || roulette == 21 || roulette == 23 || roulette == 24)){
			pot_fournum[17] = pot_fournum[17] * 9;
			total = total + pot_fournum[17];
		}
		
		else if ((fournum[18] == true) && (roulette == 23 || roulette == 24 || roulette == 26 || roulette == 27)){
			pot_fournum[18] = pot_fournum[18] * 9;
			total = total + pot_fournum[18];
		}
		
		else if ((fournum[19] == true) && (roulette == 26 || roulette == 27 || roulette == 29 || roulette == 30)){
			pot_fournum[19] = pot_fournum[19] * 9;
			total = total + pot_fournum[19];
		}
		
		else if ((fournum[20] == true) && (roulette == 29 || roulette == 30 || roulette == 32 || roulette == 33)){
			pot_fournum[20] = pot_fournum[20] * 9;
			total = total + pot_fournum[20];
		}
		
		else if ((fournum[21] == true) && (roulette == 32 || roulette == 33 || roulette == 35 || roulette == 36)){
			pot_fournum[21] = pot_fournum[21] * 9;
			total = total + pot_fournum[21];
		}
		
		//Three Number Bets
		else if ((threenum[0] == true) && (roulette == 1 || roulette == 2 || roulette == 3)){
			pot_threenum[0] = pot_threenum[0] * 12;
			total = total + pot_threenum[0];
		}
		
		else if ((threenum[1] == true) && (roulette == 4 || roulette == 5 || roulette == 6)){
			pot_threenum[1] = pot_threenum[1] * 12;
			total = total + pot_threenum[1];
		}
		
		else if ((threenum[2] == true) && (roulette == 7 || roulette == 8 || roulette == 9)){
			pot_threenum[2] = pot_threenum[2] * 12;
			total = total + pot_threenum[2];
		}
		
		else if ((threenum[3] == true) && (roulette == 10 || roulette == 11 || roulette == 12)){
			pot_threenum[3] = pot_threenum[3] * 12;
			total = total + pot_threenum[3];
		}
		
		else if ((threenum[4] == true) && (roulette == 13 || roulette == 14 || roulette == 15)){
			pot_threenum[4] = pot_threenum[4] * 12;
			total = total + pot_threenum[4];
		}
		
		else if ((threenum[5] == true) && (roulette == 16 || roulette == 17 || roulette == 18)){
			pot_threenum[5] = pot_threenum[5] * 12;
			total = total + pot_threenum[5];
		}
		
		else if ((threenum[6] == true) && (roulette == 19 || roulette == 20 || roulette == 21)){
			pot_threenum[6] = pot_threenum[6] * 12;
			total = total + pot_threenum[6];
		}
		
		else if ((threenum[7] == true) && (roulette == 22 || roulette == 23 || roulette == 24)){
			pot_threenum[7] = pot_threenum[7] * 12;
			total = total + pot_threenum[7];
		}
		
		else if ((threenum[8] == true) && (roulette == 25 || roulette == 26 || roulette == 27)){
			pot_threenum[8] = pot_threenum[8] * 12;
			total = total + pot_threenum[8];
		}
		
		else if ((threenum[9] == true) && (roulette == 28 || roulette == 29 || roulette == 30)){
			pot_threenum[9] = pot_threenum[9] * 12;
			total = total + pot_threenum[9];
		}
		
		else if ((threenum[10] == true) && (roulette == 31 || roulette == 32 || roulette == 33)){
			pot_threenum[10] = pot_threenum[10] * 12;
			total = total + pot_threenum[10];
		}
		
		else if ((threenum[11] == true) && (roulette == 34 || roulette == 35 || roulette == 36)){
			pot_threenum[11] = pot_threenum[11] * 12;
			total = total + pot_threenum[11];
		}
		
		 //Double Number Bets
		else if ((doublenum[0] == true) && (roulette == 1 || roulette == 2)){
			pot_doublenum[0] = pot_doublenum[0] * 18;
			total = total + pot_doublenum[0];
		}
		
		else if ((doublenum[1] == true) && (roulette == 4 || roulette == 5)){
			pot_doublenum[1] = pot_doublenum[1] * 18;
			total = total + pot_doublenum[1];
		}
		
		else if ((doublenum[2] == true) && (roulette == 7 || roulette == 8)){
			pot_doublenum[2] = pot_doublenum[2] * 18;
			total = total + pot_doublenum[2];
		}
		
		else if ((doublenum[3] == true) && (roulette == 10 || roulette == 11)){
			pot_doublenum[3] = pot_doublenum[3] * 18;
			total = total + pot_doublenum[3];
		}
		
		else if ((doublenum[4] == true) && (roulette == 13 || roulette == 14)){
			pot_doublenum[4] = pot_doublenum[4] * 18;
			total = total + pot_doublenum[4];
		}
		
		else if ((doublenum[5] == true) && (roulette == 16 || roulette == 17)){
			pot_doublenum[5] = pot_doublenum[5] * 18;
			total = total + pot_doublenum[5];
		}
		
		else if ((doublenum[6] == true) && (roulette == 19 || roulette == 20)){
			pot_doublenum[6] = pot_doublenum[6] * 18;
			total = total + pot_doublenum[6];
		}
		
		else if ((doublenum[7] == true) && (roulette == 22 || roulette == 23)){
			pot_doublenum[7] = pot_doublenum[7] * 18;
			total = total + pot_doublenum[7];
		}
		
		else if ((doublenum[8] == true) && (roulette == 25 || roulette == 26)){
			pot_doublenum[8] = pot_doublenum[8] * 18;
			total = total + pot_doublenum[8];
		}
		
		else if ((doublenum[9] == true) && (roulette == 28 || roulette == 29)){
			pot_doublenum[9] = pot_doublenum[9] * 18;
			total = total + pot_doublenum[9];
		}
		
		else if ((doublenum[10] == true) && (roulette == 31 || roulette == 32)){
			pot_doublenum[10] = pot_doublenum[10] * 18;
			total = total + pot_doublenum[10];
		}
		
		else if ((doublenum[11] == true) && (roulette == 34 || roulette == 35)){
			pot_doublenum[11] = pot_doublenum[11] * 18;
			total = total + pot_doublenum[11];
		}
		
		else if ((doublenum[12] == true) && (roulette == 2 || roulette == 3)){
			pot_doublenum[12] = pot_doublenum[12] * 18;
			total = total + pot_doublenum[12];
		}
		
		else if ((doublenum[13] == true) && (roulette == 5 || roulette == 6)){
			pot_doublenum[13] = pot_doublenum[13] * 18;
			total = total + pot_doublenum[13];
		}
		
		else if ((doublenum[14] == true) && (roulette == 8 || roulette == 9)){
			pot_doublenum[14] = pot_doublenum[14] * 18;
			total = total + pot_doublenum[14];
		}
		
		else if ((doublenum[15] == true) && (roulette == 11 || roulette == 12)){
			pot_doublenum[15] = pot_doublenum[15] * 18;
			total = total + pot_doublenum[15];
		}
		
		else if ((doublenum[16] == true) && (roulette == 14 || roulette == 15)){
			pot_doublenum[16] = pot_doublenum[16] * 18;
			total = total + pot_doublenum[16];
		}
		
		else if ((doublenum[17] == true) && (roulette == 17 || roulette == 18)){
			pot_doublenum[17] = pot_doublenum[17] * 18;
			total = total + pot_doublenum[17];
		}
		
		else if ((doublenum[18] == true) && (roulette == 20 || roulette == 21)){
			pot_doublenum[18] = pot_doublenum[18] * 18;
			total = total + pot_doublenum[18];
		}
		
		else if ((doublenum[19] == true) && (roulette == 23 || roulette == 24)){
			pot_doublenum[19] = pot_doublenum[19] * 18;
			total = total + pot_doublenum[19];
		}
		
		else if ((doublenum[20] == true) && (roulette == 26 || roulette == 27)){
			pot_doublenum[20] = pot_doublenum[20] * 18;
			total = total + pot_doublenum[20];
		}
		
		else if ((doublenum[21] == true) && (roulette == 29 || roulette == 30)){
			pot_doublenum[21] = pot_doublenum[21] * 18;
			total = total + pot_doublenum[21];
		}
		
		else if ((doublenum[22] == true) && (roulette == 32 || roulette == 33)){
			pot_doublenum[22] = pot_doublenum[22] * 18;
			total = total + pot_doublenum[22];
		}
		
		else if ((doublenum[23] == true) && (roulette == 35 || roulette == 36)){
			pot_doublenum[23] = pot_doublenum[23] * 18;
			total = total + pot_doublenum[23];
		}
		
		else if ((doublenum[24] == true) && (roulette == 1 || roulette == 4)){
			pot_doublenum[24] = pot_doublenum[24] * 18;
			total = total + pot_doublenum[24];
		}
		
		else if ((doublenum[25] == true) && (roulette == 2 || roulette == 5)){
			pot_doublenum[25] = pot_doublenum[25] * 18;
			total = total + pot_doublenum[25];
		}
		
		else if ((doublenum[26] == true) && (roulette == 3 || roulette == 6)){
			pot_doublenum[26] = pot_doublenum[26] * 18;
			total = total + pot_doublenum[26];
		}
		
		else if ((doublenum[27] == true) && (roulette == 4 || roulette == 7)){
			pot_doublenum[27] = pot_doublenum[27] * 18;
			total = total + pot_doublenum[27];
		}
		
		else if ((doublenum[28] == true) && (roulette == 5 || roulette == 8)){
			pot_doublenum[28] = pot_doublenum[28] * 18;
			total = total + pot_doublenum[28];
		}
		
		else if ((doublenum[29] == true) && (roulette == 6 || roulette == 9)){
			pot_doublenum[29] = pot_doublenum[29] * 18;
			total = total + pot_doublenum[30];
		}
		
		else if ((doublenum[30] == true) && (roulette == 7 || roulette == 10)){
			pot_doublenum[30] = pot_doublenum[30] * 18;
			total = total + pot_doublenum[30];
		}
		
		else if ((doublenum[31] == true) && (roulette == 8 || roulette == 11)){
			pot_doublenum[31] = pot_doublenum[31] * 18;
			total = total + pot_doublenum[31];
		}
		
		else if ((doublenum[32] == true) && (roulette == 9 || roulette == 12)){
			pot_doublenum[32] = pot_doublenum[32] * 18;
			total = total + pot_doublenum[32];
		}
		
		else if ((doublenum[33] == true) && (roulette == 10 || roulette == 13)){
			pot_doublenum[33] = pot_doublenum[33] * 18;
			total = total + pot_doublenum[33];
		}
		
		else if ((doublenum[34] == true) && (roulette == 11 || roulette == 14)){
			pot_doublenum[34] = pot_doublenum[34] * 18;
			total = total + pot_doublenum[34];
		}
		
		else if ((doublenum[35] == true) && (roulette == 12 || roulette == 15)){
			pot_doublenum[35] = pot_doublenum[35] * 18;
			total = total + pot_doublenum[35];
		}
		
		else if ((doublenum[36] == true) && (roulette == 13 || roulette == 16)){
			pot_doublenum[36] = pot_doublenum[36] * 18;
			total = total + pot_doublenum[36];
		}
		
		else if ((doublenum[37] == true) && (roulette == 14 || roulette == 17)){
			pot_doublenum[37] = pot_doublenum[37] * 18;
			total = total + pot_doublenum[37];
		}
		
		else if ((doublenum[38] == true) && (roulette == 15 || roulette == 18)){
			pot_doublenum[38] = pot_doublenum[38] * 18;
			total = total + pot_doublenum[38];
		}
		
		else if ((doublenum[39] == true) && (roulette == 16 || roulette == 19)){
			pot_doublenum[39] = pot_doublenum[39] * 18;
			total = total + pot_doublenum[39];
		}
		
		else if ((doublenum[40] == true) && (roulette == 17 || roulette == 20)){
			pot_doublenum[40] = pot_doublenum[40] * 18;
			total = total + pot_doublenum[40];
		}
		
		else if ((doublenum[41] == true) && (roulette == 18 || roulette == 21)){
			pot_doublenum[41] = pot_doublenum[41] * 18;
			total = total + pot_doublenum[41];
		}
		
		else if ((doublenum[42] == true) && (roulette == 19 || roulette == 22)){
			pot_doublenum[42] = pot_doublenum[42] * 18;
			total = total + pot_doublenum[42];
		}
		
		else if ((doublenum[43] == true) && (roulette == 20 || roulette == 23)){
			pot_doublenum[43] = pot_doublenum[43] * 18;
			total = total + pot_doublenum[43];
		}
		
		else if ((doublenum[44] == true) && (roulette == 21 || roulette == 24)){
			pot_doublenum[44] = pot_doublenum[44] * 18;
			total = total + pot_doublenum[44];
		}
		
		else if ((doublenum[45] == true) && (roulette == 22 || roulette == 25)){
			pot_doublenum[45] = pot_doublenum[45] * 18;
			total = total + pot_doublenum[45];
		}
		
		else if ((doublenum[46] == true) && (roulette == 23 || roulette == 26)){
			pot_doublenum[46] = pot_doublenum[46] * 18;
			total = total + pot_doublenum[46];
		}
		
		else if ((doublenum[47] == true) && (roulette == 24 || roulette == 27)){
			pot_doublenum[47] = pot_doublenum[47] * 18;
			total = total + pot_doublenum[47];
		}
		
		else if ((doublenum[48] == true) && (roulette == 25 || roulette == 28)){
			pot_doublenum[48] = pot_doublenum[48] * 18;
			total = total + pot_doublenum[48];
		}
		
		else if ((doublenum[49] == true) && (roulette == 26 || roulette == 29)){
			pot_doublenum[49] = pot_doublenum[49] * 18;
			total = total + pot_doublenum[49];
		}
		
		else if ((doublenum[50] == true) && (roulette == 27 || roulette == 30)){
			pot_doublenum[50] = pot_doublenum[50] * 18;
			total = total + pot_doublenum[50];
		}
		
		else if ((doublenum[51] == true) && (roulette == 28 || roulette == 31)){
			pot_doublenum[51] = pot_doublenum[51] * 18;
			total = total + pot_doublenum[51];
		}
		
		else if ((doublenum[52] == true) && (roulette == 29 || roulette == 32)){
			pot_doublenum[52] = pot_doublenum[52] * 18;
			total = total + pot_doublenum[52];
		}
		
		else if ((doublenum[53] == true) && (roulette == 30 || roulette == 33)){
			pot_doublenum[53] = pot_doublenum[53] * 18;
			total = total + pot_doublenum[53];
		}
		
		else if ((doublenum[54] == true) && (roulette == 31 || roulette == 34)){
			pot_doublenum[54] = pot_doublenum[54] * 18;
			total = total + pot_doublenum[54];
		}
		
		else if ((doublenum[55] == true) && (roulette == 32 || roulette == 35)){
			pot_doublenum[55] = pot_doublenum[55] * 18;
			total = total + pot_doublenum[55];
		}
		
		else if ((doublenum[56] == true) && (roulette == 33 || roulette == 36)){
			pot_doublenum[56] = pot_doublenum[56] * 18;
			total = total + pot_doublenum[56];
		}
	
		//Single Number Bets
		else if ((singlenum[0] == true) && (roulette == 0)){
			pot_singlenum[0] = pot_singlenum[0] * 36;
			total = total = pot_singlenum[0];
		}
		
		else if ((singlenum[1] == true) && (roulette == 00)){
			pot_singlenum[1] = pot_singlenum[1] * 36;
			total = total = pot_singlenum[1];
		}
		
		else if ((singlenum[2] == true) && (roulette == 1)){
			pot_singlenum[2] = pot_singlenum[2] * 36;
			total = total = pot_singlenum[2];
		}
		
		else if ((singlenum[3] == true) && (roulette == 2)){
			pot_singlenum[3] = pot_singlenum[3] * 36;
			total = total = pot_singlenum[3];
		}
		
		else if ((singlenum[4] == true) && (roulette == 3)){
			pot_singlenum[4] = pot_singlenum[4] * 36;
			total = total = pot_singlenum[4];
		}
		
		else if ((singlenum[5] == true) && (roulette == 4)){
			pot_singlenum[5] = pot_singlenum[5] * 36;
			total = total = pot_singlenum[5];
		}
		
		else if ((singlenum[6] == true) && (roulette == 5)){
			pot_singlenum[6] = pot_singlenum[6] * 36;
			total = total = pot_singlenum[6];
		}
		
		else if ((singlenum[7] == true) && (roulette == 6)){
			pot_singlenum[7] = pot_singlenum[7] * 36;
			total = total = pot_singlenum[7];
		}
		
		else if ((singlenum[8] == true) && (roulette == 7)){
			pot_singlenum[8] = pot_singlenum[8] * 36;
			total = total = pot_singlenum[8];
		}
		
		else if ((singlenum[9] == true) && (roulette == 8)){
			pot_singlenum[9] = pot_singlenum[9] * 36;
			total = total = pot_singlenum[9];
		}
		
		else if ((singlenum[10] == true) && (roulette == 9)){
			pot_singlenum[10] = pot_singlenum[10] * 36;
			total = total = pot_singlenum[10];
		}
		
		else if ((singlenum[11] == true) && (roulette == 10)){
			pot_singlenum[11] = pot_singlenum[11] * 36;
			total = total = pot_singlenum[11];
		}
		
		else if ((singlenum[12] == true) && (roulette == 11)){
			pot_singlenum[12] = pot_singlenum[12] * 36;
			total = total = pot_singlenum[12];
		}
		
		else if ((singlenum[13] == true) && (roulette == 12)){
			pot_singlenum[13] = pot_singlenum[13] * 36;
			total = total = pot_singlenum[13];
		}
		
		else if ((singlenum[14] == true) && (roulette == 13)){
			pot_singlenum[14] = pot_singlenum[14] * 36;
			total = total = pot_singlenum[14];
		}
		
		else if ((singlenum[15] == true) && (roulette == 14)){
			pot_singlenum[15] = pot_singlenum[15] * 36;
			total = total = pot_singlenum[15];
		}
		
		else if ((singlenum[16] == true) && (roulette == 15)){
			pot_singlenum[16] = pot_singlenum[16] * 36;
			total = total = pot_singlenum[16];
		}
		
		else if ((singlenum[17] == true) && (roulette == 16)){
			pot_singlenum[17] = pot_singlenum[17] * 36;
			total = total = pot_singlenum[17];
		}
		
		else if ((singlenum[18] == true) && (roulette == 17)){
			pot_singlenum[18] = pot_singlenum[18] * 36;
			total = total = pot_singlenum[18];
		}
		
		else if ((singlenum[19] == true) && (roulette == 18)){
			pot_singlenum[19] = pot_singlenum[19] * 36;
			total = total = pot_singlenum[19];
		}
		
		else if ((singlenum[20] == true) && (roulette == 19)){
			pot_singlenum[20] = pot_singlenum[20] * 36;
			total = total = pot_singlenum[20];
		}
		
		else if ((singlenum[21] == true) && (roulette == 20)){
			pot_singlenum[21] = pot_singlenum[21] * 36;
			total = total = pot_singlenum[21];
		}
		
		else if ((singlenum[22] == true) && (roulette == 21)){
			pot_singlenum[22] = pot_singlenum[22] * 36;
			total = total = pot_singlenum[22];
		}
		
		else if ((singlenum[23] == true) && (roulette == 22)){
			pot_singlenum[23] = pot_singlenum[23] * 36;
			total = total = pot_singlenum[23];
		}
		
		else if ((singlenum[24] == true) && (roulette == 23)){
			pot_singlenum[24] = pot_singlenum[24] * 36;
			total = total = pot_singlenum[24];
		}
		
		else if ((singlenum[25] == true) && (roulette == 24)){
			pot_singlenum[25] = pot_singlenum[25] * 36;
			total = total = pot_singlenum[25];
		}
		
		else if ((singlenum[26] == true) && (roulette == 25)){
			pot_singlenum[26] = pot_singlenum[26] * 36;
			total = total = pot_singlenum[26];
		}
		
		else if ((singlenum[27] == true) && (roulette == 26)){
			pot_singlenum[27] = pot_singlenum[27] * 36;
			total = total = pot_singlenum[27];
		}
		
		else if ((singlenum[28] == true) && (roulette == 27)){
			pot_singlenum[28] = pot_singlenum[28] * 36;
			total = total = pot_singlenum[28];
		}
		
		else if ((singlenum[29] == true) && (roulette == 28)){
			pot_singlenum[29] = pot_singlenum[29] * 36;
			total = total = pot_singlenum[29];
		}
		
		else if ((singlenum[30] == true) && (roulette == 29)){
			pot_singlenum[30] = pot_singlenum[30] * 36;
			total = total = pot_singlenum[30];
		}
		
		else if ((singlenum[31] == true) && (roulette == 30)){
			pot_singlenum[31] = pot_singlenum[31] * 36;
			total = total = pot_singlenum[31];
		}
		
		else if ((singlenum[32] == true) && (roulette == 31)){
			pot_singlenum[32] = pot_singlenum[32] * 36;
			total = total = pot_singlenum[32];
		}
		
		else if ((singlenum[33] == true) && (roulette == 32)){
			pot_singlenum[33] = pot_singlenum[33] * 36;
			total = total = pot_singlenum[33];
		}
		
		else if ((singlenum[34] == true) && (roulette == 33)){
			pot_singlenum[34] = pot_singlenum[34] * 36;
			total = total = pot_singlenum[34];
		}
		
		else if ((singlenum[35] == true) && (roulette == 34)){
			pot_singlenum[35] = pot_singlenum[35] * 36;
			total = total = pot_singlenum[35];
		}
		
		else if ((singlenum[36] == true) && (roulette == 35)){
			pot_singlenum[36] = pot_singlenum[36] * 36;
			total = total = pot_singlenum[36];
		}
		
		else if ((singlenum[37] == true) && (roulette == 36)){
			pot_singlenum[37] = pot_singlenum[37] * 36;
			total = total = pot_singlenum[37];
		}
		
		cout << "You won: " << total << '\n';
		
		//Adds the winning.
		balance = total + balance;
		
		//Wins and loss Counter.
		if (total > 0){
			wins+=1;
		}
		else {
			losses+=1;
		}
		
		if (balance < 5){
			cout << endl;
			cout << "Unfortunately your balance is not enough to continue playing." << '\n';
			cout << "Thanks for playing. Please come again." << '\n';
			return 0;
		}
	//Replay	
		cout << endl;
		
		//Resets invalid inputs.
		while (!cin.fail()) {
		cout << "Would you like to play again? (Y/N): ";
		cin >> Y_N;
		if (cin.fail()){
			cin.clear();
			cin.ignore(10000000, '\n');
			cout << "Invalid input. Please try again." << '\n'<< '\n';
			continue;
			}
		else{
			break;
		}	
		}
			if (Y_N == "Y" || Y_N == "y"){
				//Resets everything.
				total = 0;
				pot_all_black = 0; 
				pot_all_red = 0;
				pot_even = 0;
				pot_odd = 0; 
				pot_1to18 = 0; 
				pot_19to36 = 0; 
				pot_first12 = 0; 
				pot_second12 = 0; 
				pot_third12 = 0;
				pot_fivenum = 0;
				
				//Column
				for (int c = 0; c < 3; c++){
					pot_column[c] *= 0;
				}
				
				//Sixnum
				for (int s = 0; s < 11; s++){
					pot_sixnum[s] *= 0;
				}
				
				//Fournum
				for (int f = 0; f < 22; f++){
					pot_fournum[f] *= 0;
				}
				
				//Threenum
				for (int t = 0; t < 12; t++){
					pot_threenum[t] *= 0;
				}
				
				//Doublenum
				for (int d = 0; d < 57; d++){
					pot_doublenum[d] *= 0;
				}
				
				//Singlenum
				for (int s = 0; s < 38; s++){
					pot_singlenum[s] *= 0;
				}
				
				all_black = false;
				all_red = false; 
				even = false; 
				odd = false; 
				_1to18 = false;
				_19to36 = false; 
				first12 = false;
				second12 = false;
				third12 = false;
				fivenum = false;
				//Column
				for (int c = 0; c < 3; c++){
					column[c] = false;
				}
				
				//Sixnum
				for (int s = 0; s < 11; s++){
					sixnum[s] = false;
				}
				
				//Fournum
				for (int f = 0; f < 22; f++){
					fournum[f] = false;
				}
				
				//Threenum
				for (int t = 0; t < 12; t++){
					threenum[t] = 0;
				}
				
				//Doublenum
				for (int d = 0; d < 57; d++){
					doublenum[d] = false;
				}
				
				//Singlenum
				for (int s = 0; s < 38; s++){
					singlenum[s] = false;
				}
				continue;
			}
	
			else if (Y_N == "N" || Y_N == "n"){
				cout << "Aww. Done already?" << '\n';
				cout << "Thanks for trying.";
				return 0;	
				break;
			}
			
			else {
				cout << "Invalid input. Please try again." << '\n';
				continue;
				}
	}
}
