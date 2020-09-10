#ifndef QHEAP_H
#define QHEAP_H

#include "MMHeap.h"
#include <vector>

template <typename T>
class QHeap
{

    MMHeap<T>** heaps;
    size_t QHLength = 0;

public:

    QHeap(): heaps(nullptr)
    {

    }

    QHeap(const int& initialSize)
    {
        heaps = new MMHeap<T> *[4];
        
        for (int i = 0; i < 4; i++)
        {
            heaps[i] = new MMHeap<T>(initialSize);
        }
    }

    //Finds heap in QHeap thats size is different by 2 of first heap
    int findHeapOffBy2()
    {
        int heapOffBy2 = -1;
        if (heaps[0]->size() > heaps[1]->size() + 1)
        {
            heapOffBy2 = 1;
        }
        else if (heaps[0]->size() > heaps[2]->size() + 1)
        {
            heapOffBy2 = 2;
        }
        else if (heaps[0]->size() > heaps[3]->size() + 1)
        {
            heapOffBy2 = 3;
        }
        else
        {
            heapOffBy2 = -1;
        }

        return heapOffBy2;

    }

    //Finds errors in the size of heaps in QHeap
    int checkForError()
    {

        int heapWithError = -1;

        //This finds the heap with error
        //Error in 4th heap
        if (heaps[3]->size() > heaps[2]->size())
        {
            heapWithError = 3;
        }
        //Error in 3th heap
        else if (heaps[2]->size() > heaps[1]->size())
        {
            heapWithError = 2;
        }
        //Error in 2th heap
        else if (heaps[1]->size() > heaps[0]->size())
        {
            heapWithError = 1;
        }
        //Error in 1th heap
        else if (heaps[0]->size() > heaps[1]->size() + 1)
        {
            heapWithError = 0;
        }
        else if (findHeapOffBy2() != -1)
        {   
            //Special case when (not error in one heap)
            return 4;
        }
        
        return heapWithError;
        
    }

    //Returns integer representation of heap with greatest size
    int findGreatestHeap()
    {
        int greatestHeap = -1;

        if (heaps[3]->size() >= heaps[1]->size() 
            && heaps[3]->size() >= heaps[2]->size() 
            && heaps[3]->size() >= heaps[0]->size())
        {
            greatestHeap = 3;
        }
        else if (heaps[2]->size() >= heaps[0]->size() 
            && heaps[2]->size() >= heaps[1]->size() 
            && heaps[2]->size() >= heaps[3]->size())
        {
            greatestHeap = 2;
        }
        else if (heaps[1]->size() >= heaps[0]->size() 
            && heaps[1]->size() >= heaps[2]->size() 
            && heaps[1]->size() >= heaps[3]->size())
        {
            greatestHeap = 1;
        }
        else if (heaps[0]->size() >= heaps[3]->size() 
            && heaps[0]->size() >= heaps[1]->size() 
            && heaps[0]->size() >= heaps[2]->size())
        {
            greatestHeap = 0;
        }
        else
        {
            //This should never run
            greatestHeap = -1;
        }

        return greatestHeap;

    }

    //Inserts element into QHeap in the correct location
    void insert(T* px)
    {
        bool allHeapsFull = false;

        //If First heap empty
        if (heaps[0]->size() == 0)
        {
            heaps[0]->insert(px);
        }
        //Second heap empty
        else if (heaps[1]->size() == 0)
        {
            //If px should go in first heap
            if (*heaps[0]->getMax() > *px)
            {
                heaps[0]->insert(px);
                heaps[1]->insert(heaps[0]->getMax());
                heaps[0]->deleteMax();
            }
            //If px should go in secound heap
            else
            {
                heaps[1]->insert(px);
            }
        }
        //Third heap empty
        else if (heaps[2]->size() == 0)
        {
            //If px should go in first heap
            if (*heaps[0]->getMax() > *px)
            {
                heaps[0]->insert(px);

                heaps[1]->insert(heaps[0]->getMax());
                heaps[0]->deleteMax();
                heaps[2]->insert(heaps[1]->getMax());
                heaps[1]->deleteMax();
                
            }
            //If px should go in second heap
            else if (*heaps[1]->getMax() > *px)
            {
                heaps[1]->insert(px);
                
                heaps[2]->insert(heaps[1]->getMax());
                heaps[1]->deleteMax();

            }
            //If px should go in third heap
            else
            {
                heaps[2]->insert(px);
            }
        }
        //Forth heap empty
        else if (heaps[3]->size() == 0)
        {
            //If px should go in first heap
            if (*heaps[0]->getMax() > *px)
            {
                heaps[0]->insert(px);

                heaps[1]->insert(heaps[0]->getMax());
                heaps[0]->deleteMax();
                heaps[2]->insert(heaps[1]->getMax());
                heaps[1]->deleteMax();
                heaps[3]->insert(heaps[2]->getMax());
                heaps[2]->deleteMax();
                
            }
            //If px should go in second heap
            else if (*heaps[1]->getMax() > *px)
            {
                heaps[1]->insert(px);
                
                heaps[2]->insert(heaps[1]->getMax());
                heaps[1]->deleteMax();
                heaps[3]->insert(heaps[2]->getMax());
                heaps[2]->deleteMax();

            }
            //If px should go in third heap
            else if (*heaps[2]->getMax() > *px)
            {
                heaps[2]->insert(px);

                heaps[3]->insert(heaps[2]->getMax());
                heaps[2]->deleteMax();
            }
            //If px should go in forth heap
            else
            {
                heaps[3]->insert(px);
            }
        }
        //All heaps full
        else
        {

            allHeapsFull = true;

            //If px should go in first heap
            if (*heaps[0]->getMax() > *px)
            {
                heaps[0]->insert(px);
            }
            //If px should go in second heap
            else if (*heaps[1]->getMax() > *px)
            {
                heaps[1]->insert(px);
            }
            //If px should go in third heap
            else if (*heaps[2]->getMax() > *px)
            {
                heaps[2]->insert(px);
            }
            //If px should go in forth heap
            else
            {
                heaps[3]->insert(px);
            }
        }

        //If all heaps were full before insertion, fix QHeap
        if (allHeapsFull == true)
        {
            int heapWithError = checkForError();
            while (heapWithError != -1)
            {

                int greatestHeap = findGreatestHeap();

                //If greatestHeap is not 0
                //We want to push elements to 1st heap
                if (greatestHeap != 0)
                {
                    for (int i = 0; i < greatestHeap; i++)
                    {
                        heaps[greatestHeap - i - 1]->insert(heaps[greatestHeap - i]->getMin());
                        if (heaps[greatestHeap - i]->size() > 0)
                        {
                            heaps[greatestHeap - i]->deleteMin();
                        }
                    }
                }

                //Check greatest heap again
                greatestHeap = findGreatestHeap();

                //If greatest heap is 0, then move to heap that is off by size 2
                if (greatestHeap == 0)
                {

                    //Find the heap thats off by size 2
                    int heapOffBy2 = 0;
                    if (heaps[0]->size() > heaps[1]->size() + 1)
                    {
                        heapOffBy2 = 1;
                    }
                    else if (heaps[0]->size() > heaps[2]->size() + 1)
                    {
                        heapOffBy2 = 2;
                    }
                    else if (heaps[0]->size() > heaps[3]->size() + 1)
                    {
                        heapOffBy2 = 3;
                    }

                    //Move over from 1st heap to first heap off by 2
                    for (int i = 0; i < heapOffBy2; i++)
                    {
                        heaps[i + 1]->insert(heaps[i]->getMax());
                        heaps[i]->deleteMax();
                    }

                }

                heapWithError = checkForError();

            }

        }

        QHLength++;
        
    }

    //Returns the min value of QHeap
    T* getMin()
    {
        if (QHLength != 0)
        {
            return heaps[0]->getMin();
        }
        else
        {
            std::cout << "Error: the QHeap is empty. No min found." << std::endl;
            return nullptr;
        }
    }

    //Retruns the max value of QHeap
    T* getMax()
    {
        if (QHLength == 1)
        {
            return heaps[0]->getMax();
        }
        else if (QHLength == 2)
        {
            return heaps[1]->getMax();
        }
        else if (QHLength == 3)
        {
            return heaps[2]->getMax();
        }
        else if (QHLength > 3)
        {
            return heaps[3]->getMax();
        }
        else
        {
            std::cout << "Error: the QHeap is empty. No max found." << std::endl;
            return nullptr;
        }
    }

    //Returns max value of first heap in QHeap
    T* get25()
    {
        if (QHLength > 0)
        {
            return heaps[0]->getMax();
        }
        else
        {
            std::cout << "Error: the QHeap is empty. First"
                << " heap not found to determine 25th %." << std::endl;
            return nullptr;
        }
    }

    //Returns max value of second heap in QHeap
    T* get50()
    {
        if (QHLength > 1)
        {
            return heaps[1]->getMax();
        }
        else
        {
            std::cout << "Error: the QHeap is to small. Second"
                << " heap not found to determine 50th %." << std::endl;
            return nullptr;
        }
    }

    //Returns max value of third heap in QHeap
    T* get75()
    {
        if (QHLength > 2)
        {
            return heaps[2]->getMax();
        }
        else
        {
            std::cout << "Error: the QHeap is to small. Third"
                << " heap not found to determine 75th %." << std::endl;
            return nullptr;
        }
    }

    //Prints out QHeap data
    void dump()
    {
        std::cout << "***********************************" << std::endl;
        std::cout << "***** Quartile heap statistics ..." << std::endl;

        if (QHLength != 0)
        {
            std::cout << "  Mininum: " << *getMin() << std::endl;
            std::cout << "  25th Percentile = " << *get25() << std::endl;

            if (QHLength > 1)
            {
                std::cout << "  Median = " << *get50() << std::endl;
            }
            else
            {
                std::cout << "  Median = Second heap does not exist." << std::endl;
            }

            if (QHLength > 2)
            {
                std::cout << "  75th Percentile = " << *get75() << std::endl;
            }
            else
            {
                std::cout << "  75th Percentile = Third heap does not exist." << std::endl;
            }
            
            std::cout << "  Maximum = " << *getMax() << std::endl;
        }
        else
        {
            std::cout << "  Mininum: QHeap is empty" << std::endl;
            std::cout << "  25th Percentile = QHeap is empty" << std::endl;
            std::cout << "  Median = QHeap is empty" << std::endl;
            std::cout << "  75th Percentile = QHeap is empty" << std::endl;
            std::cout << "  Maximum = QHeap is empty" << std::endl;
        }
        
        std::cout << "***** First Quartile heap dump ..." << std::endl;
        heaps[0]->dump();
        std::cout << "***** Second Quartile heap dump ..." << std::endl;
        heaps[1]->dump();
        std::cout << "***** Third Quartile heap dump ..." << std::endl;
        heaps[2]->dump();
        std::cout << "***** Fourth Quartile heap dump ..." << std::endl;
        heaps[3]->dump();

        std::cout << "***** End of Quartile heap dump" << std::endl;
        std::cout << "***********************************" << std::endl;

    }

};

#endif