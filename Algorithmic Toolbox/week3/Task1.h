//
//  Task1.h
//  week3
//
//  Created by Самир Новрузов on 12.04.2020.
//  Copyright © 2020 Самир Новрузов. All rights reserved.
//

#pragma once

int money_change(int money){
    int count = 0;
    int coin[] ={1 , 5, 10};
    while(money > 0){
        if(money >= 10){
            money = money - coin[2];
        }
        else if(money >= 5 ){
            money = money - coin[1];
        }
            else
                money = money - coin[0];
        count++;
    }
    return count;
}

