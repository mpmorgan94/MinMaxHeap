#ifndef MMHEAP_H
#define MMHEAP_H

#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

template <typename T>
class MMHeap
{

    std::vector<T*> pData;
    size_t length;
    bool lastLevelOdd = true;
    size_t currIndex;

public:

    MMHeap() :length(0), currIndex(length + 1)
    {
        
    }

    MMHeap(const int& initialSize) :length(0), currIndex(length + 1)
    {
        pData.resize(initialSize);
    }

    //Returns the length of the heap
    size_t size()
    {
        return length;
    }

    //Finds if the current index is at an odd level
    bool isLevelOdd()
    {
        int level = floor(log2(currIndex));
        level = level + 1;

        if (level % 2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    //Inserts element to heap in correct location
    void insert(T* px)
    {

        bool isFinished = false;

        //If the heap is empty
        if(length == 0)
        {
            pData.at(0) = px;
        }
        else
        {
        
            while (currIndex > 1 && isFinished == false)
            {

                //If the next element makes last layer odd
                if (isLevelOdd() == true)
                {
                    if (*px >= *pData.at(currIndex / 2 - 1))
                    {
                        pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                        pData.at(currIndex / 2 - 1) = px;
                        currIndex = currIndex / 2;
                    }
                    else if( currIndex > 3 && (*px < *pData.at( (currIndex / 2) / 2 - 1) ))
                    {
                        pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1 );
                        pData.at( ((currIndex / 2) / 2) - 1 ) = px;
                        currIndex = (currIndex / 2) / 2;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = px;
                        isFinished = true;
                    }
                }
                

                //If the next element makes last layer even
                else if (isLevelOdd() == false)
                {
                    if (*px <= *pData.at(currIndex / 2 - 1))
                    {
                        pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                        pData.at(currIndex / 2 - 1) = px;
                        currIndex = currIndex / 2;
                    }
                    else if( currIndex > 3 && (*px > *pData.at( ((currIndex / 2) / 2) - 1 ) ) )
                    {
                        pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1 );
                        pData.at( ((currIndex / 2) / 2) - 1 ) = px;
                        currIndex = (currIndex / 2) / 2;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = px;
                        isFinished = true;
                    }
                    
                }
            }
        }

        length = length + 1;
        currIndex = length + 1;

    }

    //Prints data of heap
    void dump()
    {

        std::cout << "---------------------------------------" << std::endl;
        std::cout << "--- min-max heap dump ---" << std::endl;
        std::cout << "Size: " << length << std::endl;
        if (length > 0)
        {
            std::cout << "Minimum = " << *getMin() << std::endl;
            std::cout << "Maximum = " << *getMax() << std::endl;
        }
        else
        {
            std::cout << "Minimum = N/A" << std::endl;
            std::cout << "Maximum = N/A" << std::endl;
        }
        

        if (isLevelOdd() == true)
        {
            std::cout << "Last level is even" << std::endl;
        }
        else
        {
            std::cout << "Last level is odd" << std::endl;
        }
        
        std::cout << "--- heap data items ---" << std::endl;
        for (size_t i = 0; i < length; i++)
        {
            std::cout << "H[" << (i + 1) << "] = " << *pData.at(i) << std::endl;
        }
        std::cout << "---------------------------------------" << std::endl;

    }

    //Retruns min value of the heap
    T* getMin()
    {
        if (length != 0)
        {
            return pData.at(0);
        }
        else
        {
            std::cout << "The min value could not be retrieved due to empty MMHeap." << std::endl;
            return nullptr;
        }
    }

    //Returns max value of the heap
    T* getMax()
    {
        if (length > 2)
        {
            if(*pData.at(1) >= *pData.at(2))
            {
                return pData.at(1);
            }
            else
            {
                return pData.at(2);
            }
            
        }
        else if (length == 2)
        {
            return pData.at(1);
        }
        else if (length == 1)
        {
            return pData.at(0);
        }
        else
        {
            std::cout << "The max value could not be retrieved due to empty MMHeap." << std::endl;
            return nullptr;
        }
    }

    //Deletes min value of heap and returns deleted value
    T deleteMin()
    {
        currIndex = 1;
        bool replaced = false;
        bool isDoneTricklingDown = false;

        if (length == 0)
        {
            throw std::runtime_error("Could not delete min, Empty MMHeap.");
        }
        T dataToReturn = *getMin();

        length = length - 1;
        
        //Trickles down
        while (isDoneTricklingDown == false)
        {
            if (currIndex * 2 * 2 <= length)
            {
                //If there are 4 grandchildren
                if (length >= currIndex * 2 * 2 + 3)
                {
                    T* minData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMinData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        if (*minData > *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            minData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMinData = indexAtMinData + numToAddToMinIndex;

                    if (*minData <= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = minData;
                        currIndex = indexAtMinData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 3 grandchildren
                else if (length >= currIndex * 2 * 2 + 2)
                {
                    T* minData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMinData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        if (*minData > *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            minData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMinData = indexAtMinData + numToAddToMinIndex;

                    if (*minData <= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = minData;
                        currIndex = indexAtMinData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 2 grandchildren
                else if (length >= currIndex * 2 * 2 + 1)
                {
                    T* minData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMinData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        if (*minData > *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            minData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMinData = indexAtMinData + numToAddToMinIndex;

                    if (*minData <= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = minData;
                        currIndex = indexAtMinData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 1 grandchildren
                else if (length >= currIndex * 2 * 2)
                {
                    T* minData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMinData = currIndex * 2 * 2;

                    if (*minData <= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = minData;
                        currIndex = indexAtMinData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }

            }
            // If there is no grandchildren
            else
            {
                pData.at(currIndex - 1) = pData.at(length);
                replaced = true;
                isDoneTricklingDown = true;
            }
            

            //If tickleDown is done but nothing has been replaced
            if (replaced == false && isDoneTricklingDown == true)
            {
                pData.at(currIndex - 1) = pData.at(length);
                replaced = true;
            }

        }

        //Trickle down is complete now
        //Swap with next layer element if necessary
        if (currIndex * 2 + 1 <= length && currIndex != 0)
        {
            if (*pData.at(currIndex * 2 - 1) < *pData.at(currIndex - 1) ||
                *pData.at(currIndex * 2) < *pData.at(currIndex - 1))
            {
                if (*pData.at(currIndex * 2 - 1) < *pData.at(currIndex * 2))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex * 2 - 1);
                    pData.at(currIndex * 2 - 1) = temp;
                    currIndex = currIndex * 2;
                }
                else
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex * 2);
                    pData.at(currIndex * 2) = temp;
                    currIndex = currIndex * 2 + 1;
                }
            }
        }
        else if (currIndex * 2 <= length && currIndex != 0)
        {
            if (*pData.at(currIndex * 2 - 1) < *pData.at(currIndex - 1))
            {
                T* temp = pData.at(currIndex - 1);
                pData.at(currIndex - 1) = pData.at(currIndex * 2 - 1);
                pData.at(currIndex * 2 - 1) = temp;
                currIndex = currIndex * 2;
            }
        }

        //Percolate up the max levels as needed
        bool isFinished = false;
        while (isFinished == false && currIndex > 1)
        {

            if (isLevelOdd() == false)
            {

                if (*pData.at(currIndex - 1) <= *pData.at(currIndex / 2 - 1))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                    pData.at(currIndex / 2 - 1) = temp;
                    currIndex = currIndex / 2;
                }
                else if( currIndex > 3 && (*pData.at(currIndex - 1) > *pData.at( ((currIndex / 2) / 2) - 1 ) ) )
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1);
                    pData.at( ((currIndex / 2) / 2) - 1 ) = temp;
                    currIndex = (currIndex / 2) / 2;
                }
                else
                {
                    isFinished = true;
                }
                
            }
            if (isLevelOdd() == true)
            {
                if (*pData.at(currIndex - 1) >= *pData.at(currIndex / 2 - 1))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                    pData.at(currIndex / 2 - 1) = temp;
                    currIndex = currIndex / 2;
                }
                else if( currIndex > 3 && (*pData.at(currIndex - 1) < *pData.at( (currIndex / 2) / 2 - 1) ))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1);
                    pData.at( ((currIndex / 2) / 2) - 1 ) = temp;
                    currIndex = (currIndex / 2) / 2;
                }
                else
                {
                    isFinished = true;
                }
                
            }

        }

        currIndex = length + 1;
        return dataToReturn;

    }

    //Deletes max value of heap and returns deleted value
    T deleteMax()
    {
        
        bool replaced = false;
        bool isDoneTricklingDown = false;

        //Account for special cases
        if (length == 0)
        {
            throw std::runtime_error("Could not delete max, Empty MMHeap.");
        }
        else if (length == 1)
        {
            length = 0;
            currIndex = 1;
            return *pData.at(0);
        }
        else if (length == 2)
        {
            length = 1;
            currIndex = 2;
            return *pData.at(1);
        }

        //Set current index to where max element is located
        if (*pData.at(1) >= *pData.at(2))
        {
            currIndex = 2;
        }
        else
        {
            currIndex = 3;
        }

        //Value to return after deletion occurs
        T dataToReturn = *getMax();

        length = length - 1;
        
        //Trickles down
        while (isDoneTricklingDown == false)
        {
            if (currIndex * 2 * 2 <= length)
            {

                //If there are 4 grandchildren
                if (length >= currIndex * 2 * 2 + 3)
                {
                    T* maxData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMaxData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        if (*maxData < *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            maxData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMaxData = indexAtMaxData + numToAddToMinIndex;

                    if (*maxData >= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = maxData;
                        currIndex = indexAtMaxData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 3 grandchildren
                else if (length >= currIndex * 2 * 2 + 2)
                {
                    T* maxData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMaxData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        if (*maxData < *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            maxData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMaxData = indexAtMaxData + numToAddToMinIndex;

                    if (*maxData >= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = maxData;
                        currIndex = indexAtMaxData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 2 grandchildren
                else if (length >= currIndex * 2 * 2 + 1)
                {
                    T* maxData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMaxData = currIndex * 2 * 2;
                    int numToAddToMinIndex = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        if (*maxData < *pData.at(currIndex * 2 * 2 + i - 1))
                        {
                            maxData = pData.at(currIndex * 2 * 2 + i - 1);
                            numToAddToMinIndex = i;
                        }
                    }
                    indexAtMaxData = indexAtMaxData + numToAddToMinIndex;

                    if (*maxData >= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = maxData;
                        currIndex = indexAtMaxData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }
                //If there are 1 grandchildren
                else if (length >= currIndex * 2 * 2)
                {
                    T* maxData = pData.at(currIndex * 2 * 2 - 1);
                    int indexAtMaxData = currIndex * 2 * 2;

                    if (*maxData >= *pData.at(length))
                    {
                        pData.at(currIndex - 1) = maxData;
                        currIndex = indexAtMaxData;
                    }
                    else
                    {
                        pData.at(currIndex - 1) = pData.at(length);
                        replaced = true;
                        isDoneTricklingDown = true;
                    }
                }

            }
            // If there is no grandchildren
            else
            {
                pData.at(currIndex - 1) = pData.at(length);
                replaced = true;
                isDoneTricklingDown = true;
            }
            

            //If tickleDown is done but nothing has been replaced
            if (replaced == false && isDoneTricklingDown == true)
            {
                pData.at(currIndex - 1) = pData.at(length);
                length = length - 1;
                replaced = true;
            }

        }
    
        //Trickle down is complete now
        //Swap with next layer element if necessary
        if (currIndex * 2 + 1 <= length && currIndex != 0)
        {
            //std::cout << "31" << std::endl;//---------------------------------DELETE//---------------------------------DELETE
            if (*pData.at(currIndex * 2 - 1) > *pData.at(currIndex - 1) ||
                *pData.at(currIndex * 2) > *pData.at(currIndex - 1))
            {
                //std::cout << "32" << std::endl;//---------------------------------DELETE//---------------------------------DELETE
                if (*pData.at(currIndex * 2 - 1) > *pData.at(currIndex * 2))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex * 2 - 1);
                    pData.at(currIndex * 2 - 1) = temp;
                    currIndex = currIndex * 2;
                }
                else
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex * 2);
                    pData.at(currIndex * 2) = temp;
                    currIndex = currIndex * 2 + 1;
                }
            }
        }
        else if (currIndex * 2 <= length && currIndex != 0)
        {
            if (*pData.at(currIndex * 2 - 1) > *pData.at(currIndex - 1))
            {
                T* temp = pData.at(currIndex - 1);
                pData.at(currIndex - 1) = pData.at(currIndex * 2 - 1);
                pData.at(currIndex * 2 - 1) = temp;
                currIndex = currIndex * 2;
            }
        }

        //Percolate up the max levels as needed
        bool isFinished = false;
        while (isFinished == false && currIndex > 1)
        {

            if (isLevelOdd() == false)
            {

                if (*pData.at(currIndex - 1) <= *pData.at(currIndex / 2 - 1))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                    pData.at(currIndex / 2 - 1) = temp;
                    currIndex = currIndex / 2;
                }
                else if( currIndex > 3 && (*pData.at(currIndex - 1) > *pData.at( ((currIndex / 2) / 2) - 1 ) ) )
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1);
                    pData.at( ((currIndex / 2) / 2) - 1 ) = temp;
                    currIndex = (currIndex / 2) / 2;
                }
                else
                {
                    isFinished = true;
                }
                
            }
            if (isLevelOdd() == true)
            {
                if (*pData.at(currIndex - 1) >= *pData.at(currIndex / 2 - 1))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at(currIndex / 2 - 1);
                    pData.at(currIndex / 2 - 1) = temp;
                    currIndex = currIndex / 2;
                }
                else if( currIndex > 3 && (*pData.at(currIndex - 1) < *pData.at( (currIndex / 2) / 2 - 1) ))
                {
                    T* temp = pData.at(currIndex - 1);
                    pData.at(currIndex - 1) = pData.at( ((currIndex / 2) / 2) - 1);
                    pData.at( ((currIndex / 2) / 2) - 1 ) = temp;
                    currIndex = (currIndex / 2) / 2;
                }
                else
                {
                    isFinished = true;
                }
                
            }

        }

        currIndex = length + 1;
        return dataToReturn;

    }


};

#endif