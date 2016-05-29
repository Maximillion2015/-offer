//
//  main.cpp
//  test
//
//  Created by 张艺峰 on 16/3/3.
//  Copyright © 2016年 张艺峰. All rights reserved.
//

#include<iostream>
using namespace std;

bool Find(int* martrix, int rows, int columns, int number)
{
    bool isFind = false;
    
    int row = 0;
    int column = columns - 1;
    
    // 判断传过来的参数是否合法
    if (martrix != NULL && rows > 0 && columns > 0)\
    {
        while(row < rows && column >= 0)
        {
            if (number == martrix[row * column + column])
            {
                isFind = true;
            }
            else if(number < martrix[row * column + column])
            {
                column--;
            }
            else
                row++;
        }
    }
    
    
    return isFind;
}