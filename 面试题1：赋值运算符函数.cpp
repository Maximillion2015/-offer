//
//  main.cpp
//  test
//
//  Created by 张艺峰 on 16/3/3.
//  Copyright © 2016年 张艺峰. All rights reserved.
//

#include<iostream>
using namespace std;

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    
    CMyString& operator=(const CMyString &);
    
private:
    char* m_pData;
};

/**
 *  1. 返回值类型声明为该类型的引用，并且在函数结束前返回实例自身的引用。
 *  2. 是否把传入的参数的类型声明为常量引用，如果传入的参数不是常量引用而是实例，那么从形参到实参会调用一次复制构造函数。
 *  3. 是否释放实例自身已有的内存。
 *  4. 是否判断传入的参数和当前实例（*this）是不是同一个实例。
 */
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this == &str)
    {
        return *this;
    }
    
    delete []m_pData;
    m_pData = NULL;
    
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    
    return *this;
};