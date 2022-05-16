//FCAI - Programming 1 - 2022 - Assignment 4
//Programm name: TextEditor.cpp
//Author 1 ana id : martina maazouz sabry 20210309
//Author 2 and id : karin amir gendy 20210562
//Author 3 and id : youssef mohamed ahmed 20210482



#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;


ostream& operator << (ostream &out, vector <string> words){
    string vector_word;
    for (string word:words) {
        vector_word += word;
        vector_word += "";

    }
    out << vector_word;
    return out;
}

string if_file(){
    string filename, response;

    cout << "please enter the file name (ADD .txt) : ";
    cin >> filename;
    ifstream file(filename);

    if(! (file.is_open()) ){
        cout << "you enter invalid name for file, if you want to create a file with this name press 1, if you want to return to enter file name enter 2." << endl;

        while(true) {
            cout << "what's your response : ";
            cin >> response;
            if (response == "1") {

                if (filename.find(".txt") != string::npos) {
                    ofstream file;
                    file.open(filename, ios::app);
                    file.close();
                }
                else{
                    filename += ".txt";
                    ofstream file;
                    file.open(filename, ios::app);
                    file.close();
                }
                cout << "file is created" << endl;
                return filename;
            } else if (response == "2") {

                if_file();
                break;
            } else {
                cout << "please enter 1 or 2 only" << endl;
            }
        }
    } else{
        return filename;
    }
}

vector <string> make_file_vector(string filename){
    vector <string> file_words;
    string line, word;
    ifstream file;

    file.open(filename, ios::in | ios ::out);
    if (file.is_open()){
        int j = 0;
        while (file.good()){

            getline(file,line);
            for (int i = 0; i < line.length(); ++i) {
                word += line[i];
                if (line[i] == ' ') {
                    file_words.push_back(word);
                    j += 1;
                    word = "";
                }
            }
            file_words.push_back(word);
            file_words.push_back("\n");
            word = "";

        }

        file_words.pop_back();
        file.close();
    }
    else{
        cout << "it make an error while opening the file " << endl;
    }
    return file_words;
}

void make_vector_file(vector <string> file_words ,string filename){
    string response;

    cout << "if you want to save in the same file enter 1, if you want to save in another file enter 2" << endl;
    while(true) {
        cout << "what is your response : ";
        cin >> response;
        if (response == "1"){
            break;
        }
        else if(response == "2"){
            cout << "please enter filename: \n";
            cin  >> filename;
            if (filename.find(".txt") != string::npos) {
                ofstream file;
                file.open(filename, ios::app);
                file.close();
            }
            else{
                filename += ".txt";
                ofstream file;
                file.open(filename, ios::app);
                file.close();
            }
        }
        else{
            cout << "please enter valid response" << endl;
        }
    }
    ofstream file(filename);

    if(file.is_open()){
        for (string word:file_words) {

            file << word;
        }

        file.close();
        cout << "file saved " << endl;
    }else{
        cout << "happen problem while saving the file" << endl;
    }
}

void encryptData(vector<string>& text){
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].size(); ++j) {
            text[i][j] += 1;

        }

    }
}

void decryptData(vector<string>& text) {
    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < text[i].size(); ++j) {
            text[i][j] -= 1;

        }

    }
}

void emptyText(vector<string> &(text)) {
    text.clear();
}

void convertToLowercase(vector<string> &(text)) {
    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < text[i].size(); j++)
            text[i][j] = tolower(text[i][j]);
}

void convertToUppercase(vector<string> &(text)) {
    for (int i = 0; i < text.size(); i++)
        for (int j = 0; j < text[i].size(); j++)
            text[i][j] = toupper(text[i][j]);

}

void wordCounter(ifstream& file){
    int word=1;
    char ch;
    file.seekg(0,ios::beg);
    while(file)
    {
        file.get(ch);
        if(ch==' '||ch=='\n')
            word++;
    }

    cout<<"\nWords="<<word<<"\n";
    file.close();

}

void characterCounter(ifstream& file){
    int counter = 0;
    char ch;

    while(file >> ch){
        counter++;}

    cout<<"\n Number of Characters ="<< counter <<"\n";
    file.close();
}

void wordSearch(ifstream& file) {

    size_t pos;
    string line,word;

    if(file.is_open())
    {
        while(getline(file,line))
        { cout << "please enter the word: ";
            cin >> word;
            pos = line.find(word);
            if(pos!=string::npos)
            {
                cout <<"Word Found! in line: ";
                cout << line;
                break;
            }else{
                cout << "Not Found!" << endl;
            }
        }
    }
}

void wordCount(ifstream& file) {

    size_t pos;
    string line,word;
    int wordCounter = 0;

    if(file.is_open())
    {
        while(getline(file,line))
        { cout << "please enter the word: ";
            cin >> word;
            pos = line.find(word);
            if(pos!=string::npos)
            {
                wordCounter += 1;
                break;
            }else{
                cout << "Not Found!" << endl;
            }
        }
    }
}

void merge(vector<string>& file1){
    string file2;
    cout << "Enter 2nd Filename: ";
    cin >> file2;

    vector<string> file2_words = make_file_vector(file2);
    for (vector<string>::iterator t=file2_words.begin(); t!=file2_words.end(); ++t)
    {
        file1.push_back(*t);
    }

    make_vector_file(file1,file2);
}

void lineCounter(ifstream& file){
    int  number_of_lines = 0;
    string line;


    while (getline(file, line))
        ++number_of_lines;
    cout << "Number of lines in text file: " << number_of_lines;

}

void addnewtexttoend(string filename)
{
    fstream file;
    string textadd;
    cout << "Enter what you want to add to the txt file: ";
    getline(cin, textadd);

    file.open(filename, ios::out|ios::app);

    while (file.is_open()) {
        file.write(textadd.data(), textadd.size());
        file.close();
    }

    cout << "Text Added Successfully!" << endl;

}

int displayMenu() {
    int choice;

    cout << "\nPlease choose one of these options.\n";
    cout << "1- Add new text to the end of the file.\n";
    cout << "2- Display the content of the file.\n";
    cout << "3- Empty the File.\n";
    cout << "4- Encrypt the file content.\n";
    cout << "5- Decrypt the file content\n";
    cout << "6- Merge another file.\n";
    cout << "7- Count the number of words in file.\n";
    cout << "8- Count the number of characters in file.\n";
    cout << "9- Count the number of lines in file.\n";
    cout << "10- Search for a word in the file.\n";
    cout << "11- Count number of times a word exists in the file.\n";
    cout << "12- Turn the file content to upper case.\n";
    cout << "13- Turn the file content to lower case.\n";
    cout << "14- Turn file content to 1st Caps.\n";
    cout << "15- Save.\n";
    cout << "16- Exit.\n";
    cout << "your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    string filename = if_file();
    vector<string> file_words = make_file_vector(filename);
    ifstream make_file_vector(filename);
    make_vector_file(file_words, filename);

    int choice;
    choice = displayMenu();
    while (make_file_vector) {
        switch (choice) {

            case 1:
                addnewtexttoend(filename);
                break;

            case 2:
                cout << file_words << endl;
                return choice;


            case 3:
                emptyText(file_words);
                cout << file_words << endl;

                return choice;

            case 4:
                encryptData(file_words);
                cout << file_words << endl;

                return choice;
            case 5:
                decryptData(file_words);
                cout << file_words << endl;

                return choice;

            case 6:

                merge(file_words);
                return choice;
            case 7:

                wordCounter(make_file_vector);
                return choice;
            case 8:

                characterCounter(make_file_vector);
                return choice;
            case 9:

                lineCounter(make_file_vector);
                return choice;
            case 10:

                wordSearch(make_file_vector);
                return choice;
            case 11:
                wordCounter(make_file_vector);
                return choice;
            case 12:
                convertToUppercase(file_words);
                cout << file_words << endl;

                return choice;
            case 13:
                convertToLowercase(file_words);
                cout << file_words << endl;

                return choice;

            case 14:

            case 15:
                make_vector_file(file_words, filename);
                return choice;
            case 16:
                return 0;
        }
    }
}