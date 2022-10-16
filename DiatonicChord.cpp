#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> pianoScale();
void MajorScale();
void MinorScale();
void printTable(vector<string>, vector<string>, vector<string>, int arr1[], int arr2[]);

int main() {
    int enterNum;

    cout << endl << "Zoey's Diatonic Chord 專案" << endl;
    cout << "***  If your chord is major, please enter 1  ***" << endl;
    cout << "***  If your chord is minor, please enter 2  ***" << endl;
    cout << "***  If you want to exit the program, please eenter -1  ***" << endl;
    cout << "Please enter your number: ";

    while(cin >> enterNum) {
        if (enterNum == -1) {
            cout << "Exit the program!!!" << endl;
            break;
        }
        else if (enterNum == 1)
            MajorScale();
        else if (enterNum == 2)
            MinorScale();
        cout << endl << endl << "***  If your chord is major, please enter 1  ***" << endl;
        cout << "***  If your chord is minor, please enter 2  ***" << endl;
        cout << "***  If you want to exit the program, please enter -1  ***" << endl;
        cout << "Please enter your number: ";
    }
    return 0;
}

void MajorScale()
{
    string pianoScale[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    string scale, mainScale;
    int tierceInterval[7] = {-1}, diapenteInterval[7] = {-1};
    int intervalArr[7] = {1, 1, 0, 1, 1, 1, 0};
    int scaleIndex = -1;
    vector<string> inputScale;
    vector<string> tierce;
    vector<string> diapente;

    cout << "Please enter your main chords: ";
    cin >> mainScale;

    // 找出大調音階
    for (int index = 0; index < 12; ++index) {
        if (pianoScale[index] == mainScale) {
            inputScale.push_back(mainScale);
            scaleIndex = index;
        }
    }
    for (int index = 1; index < 7; ++index) {
        if (intervalArr[index-1] == 1) {
            inputScale.push_back(pianoScale[(scaleIndex+2)%12]);
            scaleIndex = (scaleIndex+2)%12;
        } else {
            inputScale.push_back(pianoScale[(scaleIndex+1)%12]);
            scaleIndex = (scaleIndex+1)%12;
        }
    }
    cout << "Your input chord is ";
    for (int i = 0; i < 7; ++i)
        cout << inputScale[i] << "  ";
    cout << endl << "_______________________________________________________________________________";
   
    // 找出各音階三度音、五度音以及三度音和五度音的音階
    for (int index = 0; index < 7; ++index) {
        tierce.push_back(inputScale[(index+2)%7]);
        diapente.push_back(inputScale[(index+4)%7]);
        tierceInterval[index] = intervalArr[(index%7)]+intervalArr[(index+1)%7];
        diapenteInterval[index] = intervalArr[(index+2)%7]+intervalArr[(index+3)%7];
    }
    printTable(inputScale, tierce, diapente, tierceInterval, diapenteInterval);
}

void MinorScale()
{
    string pianoScale[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    string scale, mainScale;
    int tierceInterval[7] = {-1}, diapenteInterval[7] = {-1};
    int intervalArr[7] = {1, 0, 1, 1, 0, 1, 1};
    int scaleIndex = -1;
    vector<string> inputScale;
    vector<string> tierce;
    vector<string> diapente;

    cout << "Please enter your main chords: ";
    cin >> mainScale;

    // 找出小調音階
    for (int index = 0; index < 12; ++index) {
        if (pianoScale[index] == mainScale) {
            inputScale.push_back(mainScale);
            scaleIndex = index;
        }
    }
    for (int index = 1; index < 7; ++index) {
        if (intervalArr[index-1] == 1) {
            inputScale.push_back(pianoScale[(scaleIndex+2)%12]);
            scaleIndex = (scaleIndex+2)%12;
        } else {
            inputScale.push_back(pianoScale[(scaleIndex+1)%12]);
            scaleIndex = (scaleIndex+1)%12;
        }
    }
    cout << "Your input chord is ";
    for (int i = 0; i < 7; ++i)
        cout << inputScale[i] << "  ";
    cout << endl << "_______________________________________________________________________________";

    // 找出各音階三度音、五度音以及三度音和五度音的音階
    for (int index = 0; index < 7; ++index) {
        tierce.push_back(inputScale[(index+2)%7]);
        diapente.push_back(inputScale[(index+4)%7]);
        tierceInterval[index] = intervalArr[(index%7)]+intervalArr[(index+1)%7];
        diapenteInterval[index] = intervalArr[(index+2)%7]+intervalArr[(index+3)%7];
    }
    printTable(inputScale, tierce, diapente, tierceInterval, diapenteInterval);
}

void printTable(vector<string> inputScale, vector<string> tierce, vector<string> diapente, int tierceInterval[], int diapenteInterval[])
{
    // 輸出Diatonic Chords表格
    cout << endl << setw(16) << "scale tonic" << setw(4) << "| ";
    for (int printIndex = 0; printIndex < 7; ++printIndex)
        cout << setw(8) << inputScale[printIndex];
    cout << endl << setw(16) << "tierce" << setw(4) << "| ";
    for (int printIndex = 0; printIndex < 7; ++printIndex)
        cout << setw(8) << tierce[printIndex];
    cout << endl << setw(16) << "diapente" << setw(4) << "| ";
    for (int printIndex = 0; printIndex < 7; ++printIndex)
        cout << setw(8) << diapente[printIndex];
    cout << endl << setw(16) << "chord" << setw(4) << "| ";

    for (int printIndex = 0; printIndex < 7; ++printIndex) {
        if (tierceInterval[printIndex] == 2 && diapenteInterval[printIndex] == 1) {
            cout << setw(8) << inputScale[printIndex];
        }else if (tierceInterval[printIndex] == 1 && diapenteInterval[printIndex] == 2) {
            cout << setw(7) << inputScale[printIndex] << "m";
        }else if (tierceInterval[printIndex] == 1 && diapenteInterval[printIndex] == 1) {
            cout << setw(5) << inputScale[printIndex] << "dim";
        }else if (tierceInterval[printIndex] == 2 && diapenteInterval[printIndex] == 2) {
            cout << setw(8) << inputScale[printIndex] << "aug";
        }else {
            cout << "The interval hava problems!!!" << endl;
        }
    }
    cout << endl << setw(16) << "chord progression" << setw(3) << "| ";
    for (int printIndex = 0; printIndex < 7; ++printIndex) {
        if (tierceInterval[printIndex] == 2 && diapenteInterval[printIndex] == 1) {
            cout << setw(8) << printIndex+1;
        }else if (tierceInterval[printIndex] == 1 && diapenteInterval[printIndex] == 2) {
            cout << setw(7) << printIndex+1 << "m";
        }else if (tierceInterval[printIndex] == 1 && diapenteInterval[printIndex] == 1) {
            cout << setw(5) << printIndex+1 << "dim";
        }else if (tierceInterval[printIndex] == 2 && diapenteInterval[printIndex] == 2) {
            cout << setw(8) << printIndex+1 << "aug";
        }else {
            cout << "The interval hava problems!!!" << endl;
        }
    }
    cout << endl << "_______________________________________________________________________________";
    cout << endl;
}
