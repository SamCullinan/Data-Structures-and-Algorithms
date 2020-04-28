//
//  main.cpp
//  dataalgo
//
//  Created by Самир Новрузов on 28.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
    
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            struct Bracket tmp = Bracket(next, position);
            opening_brackets_stack.push(tmp);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
                cout << position+1 << "\n";
                return 0;
            }
            
            if(opening_brackets_stack.top().Matchc(next))
                       opening_brackets_stack.pop();
                   else{
                       cout << position+1 << "\n";
                       return 0;
                   }
        }
    }
    
    if(opening_brackets_stack.empty())
        cout<< "Success" << "\n";
    else
        cout<<(opening_brackets_stack.top().position+1) << "\n";
        

    return 0;
}
