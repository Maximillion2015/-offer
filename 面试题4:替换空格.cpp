//
//  main.cpp
//  test
//
//  Created by 张艺峰 on 16/3/3.
//  Copyright © 2016年 张艺峰. All rights reserved.
//

#include<iostream>
using namespace std;

/**
 *  字符串装换
 *
 *  @param string 字符串
 *  @param length 整个字符串数组的总容量
 */
void ReplaceBlank(char string[], int length)
{
    if (string == NULL || length <= 0)
    {
        return;
    }
    
    int originCount = 0;
    int blankCount = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        originCount++;
        if (string[i] == ' ')
        {
            blankCount++;
        }
    }
    
    int resultLength = originCount + blankCount * 2;
    // 不能超过总容量
    if (resultLength > length)
    {
        return;
    }
    
    // i指向原字符串，j指向新字符串
    for (int i = resultLength, j = originCount; i != j; i--, j--)
    {
        if (string[j] == ' ')
        {
            string[i--] = '0';
            string[i--] = '2';
            string[i] = '%';
        }
        else
            string[i] = string[j];
    }
}

int main()
{
    char aaa[20] = "hello world !";
    ReplaceBlank(aaa, 20);
    
    return 0;
}