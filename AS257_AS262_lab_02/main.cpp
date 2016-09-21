// Sammy Roberts
//Lab 2: Shop Keeper

#include <iostream>
#include "Shirt.h"
#include <vector>
#include <random>
#include<sstream>


vector<string> handleInput(string inputType) {
    int input = 0;
    //sizes
    do {
        cout << "How many "+ inputType + " are there today (max 10 limit 3): ";
        try {
            cin >> input;
            if(input >10 || input < 3) {
                throw invalid_argument("Invalid input. Enter a number between 3 and 10.");
            }
        }
        catch(invalid_argument e) {
            cout << e.what() << endl;
        }
    }while(input >10 || input < 3);
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> v;
    for(int i = 0; i < input; i++) {
        cout << "Enter an item (No Spaces): ";
        string temp;
        getline(cin, temp);
        v.push_back(temp);
    }
    return v;
}
bool findOne(string searchKey, vector<string> toSearch) {
    auto i = find(toSearch.begin(), toSearch.end(), searchKey);
    if (i != toSearch.end()) {
        return true;
    }
    else {
        return false;
    }
}
bool isInInventory(vector<string> sizes, vector<string> colors, vector<string> styles, vector<string> query) {
    if(findOne(query.at(0), sizes)) {
        if(findOne(query.at(1), colors)) {
            if(findOne(query.at(2), styles)) {
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void outputRandomChoices (vector<string> c,vector<string> si,vector<string> s) {
    //this is far too hardcore for this
    //TODO refactor to use any number of random choices

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,c.size()-1);
    
    int color1 = uni(rng);
    int color2 = uni(rng);
    int color3 = uni(rng);
    
    std::uniform_int_distribution<int> uni2(0,si.size()-1);
    
    int size1 = uni2(rng);
    int size2 = uni2(rng);
    int size3 = uni2(rng);
    
    std::uniform_int_distribution<int> uni3(0,s.size()-1);
    
    int style1 = uni3(rng);
    int style2 = uni3(rng);
    int style3 = uni3(rng);
    cout << endl << "Possible choices in format (Size, Color, Style)" << endl;
    cout << si.at(size1) << ", " << c.at(color1) << ", " << s.at(style1) << endl;
    
    cout << si.at(size2) << ", " << c.at(color2) << ", " << s.at(style2) << endl;

    
    cout << si.at(size3) << ", " << c.at(color3) << ", " << s.at(style3) << endl << endl;

}
int main(int argc, const char * argv[]) {
    // title
    cout << "Title: Lab 2: Shop Keeper - Shirts R US" << endl;
    // description
    cout << "Description: This Program is an interface for you to buy a shirt, first you will say what items are in inventory, then you will be given the option to enter 3 options, a size, color, and style. If the options are in inventory your order will be processed. Otherwise it will tell you to try again." << endl << endl;
    
    string searchString = "";
    vector<string> sizes = handleInput("sizes");

    vector<string> colors = handleInput("colors");

    vector<string> styles = handleInput("styles");

    outputRandomChoices(colors, sizes, styles);
    
    cout << "Enter your order all on the same line, separated by spaces in format size color style or quit to quit (CASE SENSITIVE): ";
    getline(cin,searchString);
    
    vector <string> seperatedQuery;
    stringstream s (searchString);
    string temp;
    while(s >> temp){
        seperatedQuery.push_back(temp);
    }
    bool done = false;
    while(!done) {
        try{
            if(seperatedQuery.at(0).compare("quit") == 0) {
                done = true;
            }
            else if(seperatedQuery.size() != 3) {
                throw invalid_argument("Sorry, your order is invalid");
            }
            else {
                if(isInInventory(sizes,colors,styles,seperatedQuery)) {
                    done = true;
                    cout << endl << "Your order is now being processed. Here is your complete order: " << endl;
                    cout << "Size: " << seperatedQuery[0] << endl;
                    cout << "Color: " << seperatedQuery[1] << endl;
                    cout << "Style: " << seperatedQuery[2] << endl;
                }
                else {
                    throw invalid_argument("Sorry, your order is invalid, item not found.");
                }
            }
        }
        catch(invalid_argument e) {
            cout << e.what() << endl;
            cout << endl << "Enter your order all on the same line, separated by spaces in format size color style or quit to quit (CASE SENSITIVE): ";
            getline(cin,searchString);
            seperatedQuery.clear();
            stringstream s (searchString);
            string temp;
            
            while(s >> temp){
                seperatedQuery.push_back(temp);
            }
            
        }
        
    }
    

}
