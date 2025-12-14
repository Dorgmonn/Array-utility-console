#include<iostream>
#include<vector>
#include<windows.h>
#include<ctime>
using namespace std;
int main() {

	srand(time(NULL));
	// All confirmations accept both 'Y' and 'y'
	double min_num, max_num, average, sum, range, CINf;    // Variables of type CIN are used for writing by the user to -MAIN SWITH-
	int n, barrier1, barrier2, ind, itm, CloneDivider, positive, negative, zero, even, odd, reverseFlag, sort, CIN, CIN2, counter, j;
	char CCIN;
	do {
		do {
			cout << " -- First you need to create an array -- " << endl << "1. Create manually" << endl << "2. Create automatically (!generates values in the limit of +32767 from the minimum barrier!)" << endl << endl << "Choose a method: ";
			cin >> itm;
			if (itm != 1 && itm != 2)
				system("cls");
		} while (itm != 1 && itm != 2);
		do {
			cout << "Enter the number of values in your array (max: 50k): ";
			cin >> n;
		} while (n <= 0 || n > 50000);
		
		vector<double> arr(n);    // ! The main array !
		vector<int> GENERAL(n);    // Creating the required array, it is mainly used to store indexes
		vector<double> clonearr(n);    // This is a clone of the main array, it only changes when a new array is created, otherwise it remains unchanged
		vector<double> GeneralClone(n);    // Backup array

		if (itm == 1) {
			for (int i = 0; i < n; i++) { //Manual array filling
				cout << "Enter value (" << (i + 1) << " of " << n << "): ";
				cin >> arr[i];
			}
		}
		else {
			cout << "! Enter 2 numbers that will limit the random array !" << endl << "First barrier: ";
			cin >> barrier1;
			cout << "Second barrier: ";
			cin >> barrier2;

			min_num = min(barrier1, barrier2); //Determining which of the boundaries is minimal and which is maximal
			max_num = max(barrier1, barrier2);

			for (int i = 0; i < n; i++) { //Automatic array filling
				arr[i] = min_num + rand() % ((int)max_num - (int)min_num + 1);
			}
		}
		system("cls");
		for (int i = 0; i < n; i++) { //Filling a clone of the main array
			clonearr[i] = arr[i];
		}
		reverseFlag = 2;
		CloneDivider = 0;

		//   !End of array creation block!

		do {
			cout << endl << " === Working with a dynamic array === " << endl << endl;
			//  Function/action selection menu
			cout << "  1. Print array" << endl << "  2. Array statistics" << endl << "  3. Sort main array" << endl << "  4. Find an element by position" << endl << "  5. Find the position of the element(s)" << endl;
			cout << "  6. Replacing an element by position" << endl << "  7. Count of elements in the array" << endl << "  8. Reverse array" << endl << "  9. Swap elements by positions" << endl << " 10. Replace all negative with zero" << endl;
			cout << " 11. Replace all positive with zero" << endl << " 12. Print the original form of the array" << endl << " 13. Revert the array to its original form" << endl << " 14. Replace element(s)" << endl << " 15. Save array (clone)" << endl;
			cout << " 16. Print clone array" << endl << " 17. Sort clone of array" << endl << " 18. Compare current with clone" << endl << " 19. Make the latest clone the primary/active array" << endl << " 20. Create a new array" << endl << "  0. EXIT" << endl;
			cout << "Select item number: ";
			cin >> itm;
			cout << endl;

			switch (itm) {      // =MAIN SWICH-CASE=

			case 0: //end
				cout << "Are you sure you want to stop the program, all arrays will not be saved (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					cout << "  #END PROGRAM#" << endl;
					return 0;
				}
				else
					cout << "Canceled" << endl;
				break;

			case 1: //  !Print array!
				cout << "  Values in an array (" << n << "): " << endl << "[";
				for (int i = 0; i < n; i++) { //Normal array output with a for loop
					cout << " " << arr[i];
				} cout << " ]" << endl;
				break;

			case 2: //  !Array statistics!
				min_num = max_num = arr[0];
				sum = positive = negative = zero = even = odd = 0;
				for (int i = 0; i < n; i++) {
					min_num = min(min_num, arr[i]); //Determining the minimum value
					max_num = max(max_num, arr[i]); //Determining the maximum value
					sum += arr[i];
					if (arr[i] == 0) //Definition, zero, positive or negative value, up to line 96
						zero++;
					else
						if (arr[i] > 0)
							positive++;
						else
							negative++;
					if ((int)arr[i] % 2 == 0) //Determining whether a value is even or odd by temporarily converting the array to integer values
						even++;               //Fractional part is ignored when checking even/odd
					else
						odd++;
				}
				average = sum / n;
				range = max_num - min_num;
				cout << " ==Array statistics==" << endl;
				cout << "MINIMUM - " << min_num << endl << "MAXIMUM - " << max_num << endl << "RANGE - " << range << endl << "AVERAGE - " << average << endl;
				cout << "POSITIVE - " << positive << endl << "NEGATIVE - " << negative << endl << "ZERO - " << zero << endl << "SUM - " << sum << endl << "EVEN - " << even << endl << "ODD - " << odd << endl;
				break;

			case 3: //  !Sort array!
				cout << " = Now choose a sorting method = " << endl << " 1. From smallest to largest" << endl << " 2. From largest to smallest" << endl << " 3. Exit" << endl << "Select item number: ";
				cin >> sort;
				switch (sort) {        // Switch for bubble sort
				case 1:
					for (int i = 0; i < n; i++) { //sort from smallest to largest
						for (int j = 0; j < (n - 1 - i); j++) {
							if (arr[j] > arr[j + 1]) {
								swap(arr[j], arr[j + 1]);
							}
						}
					} cout << "Array was sorted" << endl;
					break;
				case 2:
					for (int i = 0; i < n; i++) { //sort from largest to smallest
						for (int j = 0; j < (n - 1 - i); j++) {
							if (arr[j] < arr[j + 1]) {
								swap(arr[j], arr[j + 1]);
							}
						}
					} cout << "Array was sorted" << endl;
					break;
				default:
					cout << endl;
				} 
				break;

			case 4: //  !Find an element by index!
				cout << "Enter the position of the element: ";
				cin >> CIN;
				if (CIN > n || CIN <= 0) //Checking if such index exists in an array 
					cout << "! Error - There is no such position in the array, available positions are from 1 to " << n << endl;
				else cout << endl << "Element with position " << CIN << " is: " << arr[(CIN - 1)] << endl;
				break;

			case 5: //  !Find the index of the element(s)!
				ind = 0;
				cout << "Enter element you want to find: ";
				cin >> CIN; //Entering the desired value, and then searching for such values ​​in the array and writing their positions in GENERAL
				for (int i = 0; i < n; i++) {
					if (arr[i] == CIN) {
						GENERAL[ind] = (i + 1); //Recording indexes, but for the user in the form of positions, that is, +1
						ind++;
					}
				}
				switch (ind) { //Switch-case to find out how many values ​​were found (0, 1, or more)
				case 0:
					cout << "There is no such number in the array" << endl;
					break;

				case 1:
					cout << "Here are position for the value " << CIN << ": " << GENERAL[0] << endl;
					break;

				default:
					cout << "Here are positions for the value " << CIN << ": [ ";
					for (int i = 0; i < ind; i++) {  //Display all found positions
						cout << GENERAL[i] << " ";
					} cout << "]" << endl;
				}
				break;

			case 6: //  !Replacing an element by index!
				do {
					do {
						cout << "Enter position of the element you want to change: ";
						cin >> CIN;
						if (CIN <= 0 || CIN > n) //Checking if such an index exists
							cout << "! Error: invalid position !" << endl;

					} while (CIN <= 0 || CIN > n); //Return to input if such index does not exist in the array
					cout << "Do you want to change element " << arr[(CIN - 1)] << " at position " << CIN << " (Y - yes, N - no): ";
					cin >> CCIN;
					if (CCIN == 'Y' || CCIN == 'y') {
						cout << "Enter the new value for this position: ";
						cin >> CIN2;
						arr[CIN - 1] = CIN2;
						cout << "Element has been modified" << endl;
					}
					cout << "Do you want to change any other element (Y - yes, N - no): ";
					cin >> CCIN;
					if (CCIN != 'Y' && CCIN != 'y') {
						cout << "Canceled" << endl;
					}
				} while (CCIN == 'Y' || CCIN == 'y');
				break;

			case 7: //  !Count of elements in the array!
				do {
					counter = 0; //needed to count the number of matches
					cout << "Enter the item whose quantity you want to find: ";
					cin >> CINf;
					for (int i = 0; i < n; i++) { //Checking if such a value exists in an array
						if (arr[i] == CINf)
							counter++;
					}
					switch (counter) {
					case 0:
						cout << "! There is no such element in the array" << endl;
						break;

					case 1:
						cout << "! Only one element was found in the array" << endl;
						break;

					default:
						cout << "! <" << counter << "> elements were found in the array" << endl;
					}
					cout << "Do you want to repeat the search (Y - yes, N - no): ";
					cin >> CCIN;
				} while (CCIN == 'Y' || CCIN == 'y');
				break;

			case 8: //  !Reverse array!
				if ((reverseFlag % 2) == 0) {    // The variable 'reverse' is used to determine whether the array has already been reversed
					for (int i = 0; i < (n / 2); i++) {
						swap(arr[i], arr[n - 1 - i]); //Array flip
					}
				}
				else {
					for (int i = 0; i < n; i++) {
						arr[i] = clonearr[i]; //Return to original state
					}
				}
				reverseFlag++;
				cout << "Array been reversed" << endl;
				break;

			case 9: //  !Swap elements by indices!
				do {
					cout << " =Write two positions that need to be swapped=" << endl << "FIRST pos: ";
					cin >> CIN;
					cout << "SECOND pos: ";
					cin >> CIN2;
					if (CIN <= 0 || CIN > n || CIN2 <= 0 || CIN2 > n) //Checking if such indices exist in an array
						cout << "! Error: invalid position !" << endl;

				} while (CIN <= 0 || CIN > n || CIN2 <= 0 || CIN2 > n); //Return if such indices not exist in an array

				cout << "So you want to swap " << arr[(CIN - 1)] << " and " << arr[(CIN2 - 1)] << " (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					cout << "Elements (" << arr[(CIN - 1)] << " " << arr[(CIN2 - 1)] << ") was swapped" << endl;
					swap(arr[(CIN - 1)], arr[(CIN2 - 1)]);
				}
				else
					cout << "Canceled" << endl;
				break;

			case 10: //  !Replace all negative with zero!
				cout << "Are you sure you want to replace all negative values ​​with zeros (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					for (int i = 0; i < n; i++) {
						if (arr[i] < 0) {
							arr[i] = 0;
						}
					}
					cout << "Negative values replaced with zero" << endl;
				}
				else
					cout << "Canceled" << endl;
				break;

			case 11: //  !Replace all positive with zero!
				cout << "Are you sure you want to replace all positive values ​​with zeros (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					for (int i = 0; i < n; i++) {
						if (arr[i] > 0) {
							arr[i] = 0;
						}
					}
					cout << "Positive values replaced with zero" << endl;
				}
				else
					cout << "Canceled" << endl;
				break;

			case 12: //  !Print the original form of the array!
				cout << "  Values in the original the array (" << n << "): " << endl << "[";
				for (int i = 0; i < n; i++) { //Outputting an array clone
					cout << " " << clonearr[i];
				} cout << " ]" << endl;
				break;

			case 13: //  !Revert the array to its original form!
				cout << "Are you sure you want to return the array to its original state, all changes will be lost (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					for (int i = 0; i < n; i++) { //Restoring an array from a clone
						arr[i] = clonearr[i];
					} cout << "The array has been restored to its original form." << endl;
				}
				else {
					cout << "Canceled" << endl;
				}
				break;

			case 14:  //  !Replace element(s)!
				j = 0;
				cout << "Enter the element you want to change: ";
				cin >> CINf;
				for (int i = 0; i < n; i++) {
					if (arr[i] == CINf) {
						GENERAL[j] = i;
						j++;
					}
				}
				switch (j) {

				case 0:
					cout << "This element was not found" << endl;
					break;

				case 1:
					cout << "Element " << CINf << " was found at position " << (GENERAL[0] + 1) << " - do you want to change it (Y - yes, N - no): ";
					cin >> CCIN;
					if (CCIN == 'Y' || CCIN == 'y') {
						cout << "Enter a new value for this element: ";
						cin >> CINf;
						arr[(GENERAL[0])] = CINf;
						cout << "Element has been modified" << endl;
						break;
					}
					else
						cout << "Canceled" << endl;
					break;

				default:
					cout << "Element " << CINf << " was found at positions [ ";
					for (int i = 0; i < j; i++) {
						cout << (GENERAL[i] + 1) << " ";
					}
					cout << "] - want to change one or more elements (Y - yes, N - no): ";
					cin >> CCIN;
					if (CCIN == 'Y' || CCIN == 'y') {
						do {
							counter = 0;
							cout << "Enter the position at which you want to change this element: ";
							cin >> CIN;
							for (int i = 0; i < j; i++) {
								if (GENERAL[i] == (CIN - 1)) {
									counter++;
								}
							}
							if (counter == 0) {
								cout << "! Error: this item is not available at this position, try again" << endl;
							}
						} while (counter == 0);
						cout << "Write the new value of this element: ";
						cin >> CINf;
						arr[(CIN - 1)] = CINf;
						cout << "Element has been modified" << endl;
					}
					break;
				}
				break;

			case 15:  //  !Save array!
				cout << "Are you sure you want to create a clone of the current array state (Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					for (int i = 0; i < n; i++) {
						GeneralClone[i] = arr[i];
					}
					CloneDivider++; //Needed to know if the array was cloned
					cout << "Array clone has been created" << endl;
				}
				else
					cout << "Canceled" << endl;
				break;

			case 16:  //  !Print clone array!
				if (CloneDivider == 0) { //Checking if an array clone exists
					cout << "You haven't created a clone of the array yet," << endl << "so create one first so this feature becomes available..." << endl;
				}
				else {
					cout << "Here is the last clone of the array:" << endl << "[ ";
					for (int i = 0; i < n; i++) {
						cout << GeneralClone[i] << " ";
					}
					cout << "]" << endl;
				}
				break;

			case 17: //  !Sort clone of array!
				if (CloneDivider == 0) { //Checking if an array clone exists
					cout << "You haven't created a clone of the array yet," << endl << "so create one first so this feature becomes available..." << endl;
				}
				else {
					cout << " = Now choose a sorting method = " << endl << " 1. From smallest to largest" << endl << " 2. From largest to smallest" << endl << " 3. Exit" << endl << "Select item number: ";
					cin >> sort;
					switch (sort) {        // Switch for bubble sort
					case 1:
						for (int i = 0; i < n; i++) { //sort from smallest to largest
							for (int j = 0; j < (n - 1 - i); j++) {
								if (GeneralClone[j] > GeneralClone[j + 1]) {
									swap(GeneralClone[j], GeneralClone[j + 1]);
								}
							}
						} cout << "Clone array was sorted" << endl;
						break;
					case 2:
						for (int i = 0; i < n; i++) { //sort from largest to smallest
							for (int j = 0; j < (n - 1 - i); j++) {
								if (GeneralClone[j] < GeneralClone[j + 1]) {
									swap(GeneralClone[j], GeneralClone[j + 1]);
								}
							}
						} cout << "Clone array was sorted" << endl;
						break;
					default:
						cout << endl;
						break;
					} 
				}
				break;

			case 18:  //  !Compare current with clone!
				if (CloneDivider == 0) { //Checking if an array clone exists
					cout << "You haven't created a clone of the array yet," << endl << "so create one first so this feature becomes available..." << endl;
				}
				else {
					counter = 0;
					j = 0;
					for (int i = 0; i < n; i++) {
						if (arr[i] != GeneralClone[i]) {
							counter++;
							GENERAL[j] = (i + 1);
							j++;
						}
					}
				}
				switch (counter) {
				case 0:
					cout << "! The current array is not different from its clone" << endl;
					break;

				case 1:
					cout << "! Only one difference was found between the current array and its clone, and it is at position " << GENERAL[0] << endl;
					break;

				default:
					cout << "! <" << counter << "> differences between the current array and the clone were found, and here are the positions:" << endl << "[ ";
					for (int i = 0; i < j; i++) {
						cout << GENERAL[i] << " ";
					}
					cout << "]" << endl;
				}
				break;

			case 19:  //  !Make the latest clone the primary/active array!
				if (CloneDivider == 0) { //Checking if an array clone exists
					cout << "You haven't created a clone of the array yet," << endl << "so create one first so this feature becomes available..." << endl;
				}
				else {
					cout << "Do you really want to replace the current array with its latest clone, the current array will be lost" << endl << "(Y - yes, N - no): ";
					cin >> CCIN;
					if (CCIN == 'Y' || CCIN == 'y') {
						for (int i = 0; i < n; i++) {
							arr[i] = GeneralClone[i];
						}
						cout << "Now you are working with the last clone of the array" << endl;
					}
					else
						cout << "Canceled" << endl;
				}
				break;
			} //  =END OF MAIN SWITCH-CASE=

			if (itm == 20) {  //  !Create a new array!
				cout << "! Are you sure you want to create a new array? The current array will be lost," << endl << "! but you can save it in point 15 so that later you can return to the current array" << endl;
				cout << "(Y - yes, N - no): ";
				cin >> CCIN;
				if (CCIN == 'Y' || CCIN == 'y') {
					n = -1;
					cout << "Press Enter to proceed to creating the array...";
					cin.ignore();
					cin.get();
					system("cls");
				}
				else
					cout << "Canceled" << endl;
			}

			if (itm != 0 && n > 0) {
				cout << "Press Enter to return to the menu...";
				cin.ignore();    // Waiting for user action, and then returning to the menu
				cin.get();
				system("cls");
			}
		} while (itm != 0 && n > 0); //Returns to the list of functions
	} while (n == -1);
}