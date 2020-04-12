//
//  Task7.h
//  week3
//
//  Created by Самир Новрузов on 12.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#ifndef Task7_h
#define Task7_h

bool GreaterOrEqual(string& one, string& two) {
    return(two + one > one + two);
}
string MaxSalary(vector<string> numbers, int n) {
    
    for (size_t i = 1; i < n; i++)
        for (size_t j = 0; j < n - i; j++)
            if (GreaterOrEqual(numbers[j], numbers[j + 1]))
                swap(numbers[j], numbers[j + 1]);

    stringstream Salary;
    for (size_t i = 0; i < n; i++) {
        Salary << numbers[i];
    }
    return Salary.str();
}

#endif /* Task7_h */
