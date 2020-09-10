#ifndef INT4MMH_H
#define INT4MMH_H

#include <iostream>

class Int4MMH
{

    int m_data;

public:

    Int4MMH(int data): m_data(data)
    {

    }

    friend int compare(const Int4MMH& c1, const Int4MMH& c2);
    friend std::ostream& operator<<(std::ostream& os, const Int4MMH& obj);

    bool operator < (Int4MMH const &obj){
         
        if (compare(*this, obj) == -1)
        {
            return true;
        }
        else if (compare(*this, obj) == 1)
        {
            return false;
        }
        else
        {
            return false;
        }

    }
    bool operator > (Int4MMH const &obj){
         
        if (compare(*this, obj) == -1)
        {
            return false;
        }
        else if (compare(*this, obj) == 1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    int operator <= (Int4MMH const &obj){
         
        if (compare(*this, obj) == -1)
        {
            return true;
        }
        else if (compare(*this, obj) == 1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    int operator >= (Int4MMH const &obj){
         
        if (compare(*this, obj) == -1)
        {
            return false;
        }
        else if (compare(*this, obj) == 1)
        {
            return true;
        }
        else
        {
            return true;
        }

    }

};

int compare(const Int4MMH& c1, const Int4MMH& c2)
{
    if (c1.m_data < c2.m_data)
        return -1;
    if (c1.m_data > c2.m_data)
        return 1;
    return 0;
}

std::ostream& operator << (std::ostream& os, const Int4MMH& obj)
{
    os << obj.m_data;
    return os;
}


#endif