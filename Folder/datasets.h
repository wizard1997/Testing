#pragma once

#include <vector>
#include <random>
#include <fstream>

/**
 * @brief The DataSets class holds the 16 data sets required by this lab to sort through
 *
 * When Load is called this class will create whichever data set is to be loaded and write
 * it to the output file "Data_Set.txt"
 */
template<typename T>
class DataSets{

    public:
        std::vector<std::vector<T>> masterVect; //vector that holds every data set
        bool alreadyWritten = false; //Variable to control whether the output file should be written to or not
        int pushedToMasterVect = 0; //Variable to control what gets added to master vect

        std::vector<T> tenRandom;
        std::vector<T> tenReversedSortedOrder;
        std::vector<T> ten20Unique;
        std::vector<T> ten30Randomized;

        std::vector<T> thouRandom;
        std::vector<T> thouReversedSortedOrder;
        std::vector<T> thou20Unique;
        std::vector<T> thou30Randomized;

        std::vector<T> tenThouRandom;
        std::vector<T> tenThouReversedSortedOrder;
        std::vector<T> tenThou20Unique;
        std::vector<T> tenThou30Randomized;

        std::vector<T> hunThouRandom;
        std::vector<T> hunThouReversedSortedOrder;
        std::vector<T> hunThou20Unique;
        std::vector<T> hunThou30Randomized;

        void generateSets();

        void createTenRandom();
        void createTenReversedSortedOrder();
        void createTen20Unique();
        void createTen30Randomized();

        void createThouRandom();
        void createThouReversedSortedOrder();
        void createThou20Unique();
        void createThou30Randomized();

        void createTenThouRandom();
        void createTenThouReversedSortedOrder();
        void createTenThou20Unique();
        void createTenThou30Randomized();

        void createHunThouRandom();
        void createHunThouReversedSortedOrder();
        void createHunThou20Unique();
        void createHunThou30Randomized();

        std::ofstream outputFile;

};

template<typename T>
void DataSets<T>::generateSets()
{
    createTenRandom();
    createTenReversedSortedOrder();
    createTen20Unique();
    createTen30Randomized();

    createThouRandom();
    createThouReversedSortedOrder();
    createThou20Unique();
    createThou30Randomized();

    createTenThouRandom();
    createTenThouReversedSortedOrder();
    createTenThou20Unique();
    createTenThou30Randomized();

    createHunThouRandom();
    createHunThouReversedSortedOrder();
    createHunThou20Unique();
    createHunThou30Randomized();
}

template<typename T>
void DataSets<T>::createTenRandom()
{
    int randNum;
    for (int i = 0; i < 10; i++) {

        tenRandom.push_back(randNum = std::rand() % 10 + 1); //adds a random number 1-10 to the data set
    }

    //Decides whether or not to add the new data set to the output file
    if (alreadyWritten == false) {
        outputFile.open("Data_Set.txt");
        outputFile << "Ten Numbers -- Random Order" << std::endl;

        for (auto v: tenRandom) {
            outputFile << v << ", ";
        }
        outputFile << std::endl;
        alreadyWritten = true;
    }

    //Controls whether or not to add the new data set vector to the vector that holds all data sets
    if (pushedToMasterVect < 1) {
        masterVect.push_back(tenRandom);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTenReversedSortedOrder()
{
    //Controls whether or not to write the newly loaded data set to the file
    if (pushedToMasterVect == 1)
        alreadyWritten = false;

    //Enters numbers into the vector for this dataset
    for (int i = 10; i > 0; i--)
        tenReversedSortedOrder.push_back(i);

    //If this dataset hasn't been written to the file yet... write it to the file
    if (alreadyWritten == false) {
        outputFile << "\n\nTen Numbers -- Reversed Sorted Order" << std::endl;
        for (auto x: tenReversedSortedOrder)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    //Controls whether or not the newly created data set is added to the vector that holds all data sets
    if (pushedToMasterVect < 2) {
        masterVect.push_back(tenReversedSortedOrder);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTen20Unique()
{
    if (pushedToMasterVect == 2)
        alreadyWritten = false;

    for (int i = 1; i < 6; i++) {
        ten20Unique.push_back(i);
        ten20Unique.push_back(i);
    }
    if (alreadyWritten == false) {
        outputFile << "\n\nTen Numbers -- 20% Unique Values" << std::endl;
        for (auto x: ten20Unique)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 3) {
        masterVect.push_back(ten20Unique);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTen30Randomized()
{
    if (pushedToMasterVect == 3)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 7; i++)
        ten30Randomized.push_back(i);

    for (int j = 1; j < 4; j++)
        ten30Randomized.push_back(randNum = std::rand() % 10);

    if (alreadyWritten == false) {
        outputFile << "\n\nTen Numbers -- 30% Randomized" << std::endl;

        for (auto x: ten30Randomized)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 4) {
        masterVect.push_back(ten30Randomized);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createThouRandom()
{
    if (pushedToMasterVect == 4)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 1000; i++) {

        thouRandom.push_back(randNum = std::rand() % 1000 + 1); //adds a random number 1-1000 to the data set
    }

    //Decides whether or not to add the new data set to the output file
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Thousand Numbers -- Random Order" << std::endl;

        for (auto v: thouRandom) {
            outputFile << v << ", ";
        }
        outputFile << std::endl;
        alreadyWritten = true;
    }

    if (pushedToMasterVect < 5) {
        masterVect.push_back(thouRandom);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createThouReversedSortedOrder()
{
    if (pushedToMasterVect == 5)
        alreadyWritten = false;

    //Enters numbers into the vector for this dataset
    for (int i = 1000; i > 0; i--)
        thouReversedSortedOrder.push_back(i);

    //If this dataset hasn't been written to the file yet... write it to the file
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Thousand Numbers -- Reversed Sorted Order" << std::endl;
        for (auto x: thouReversedSortedOrder)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 6) {
        masterVect.push_back(thouReversedSortedOrder);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createThou20Unique()
{
    if (pushedToMasterVect == 6)
        alreadyWritten = false;

    for (int j = 1; j < 200; j++) {
        for (int i = 111; i < 116; i++) {
            thou20Unique.push_back(i);
        }
    }
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Thousand Numbers -- 20% Unique Values" << std::endl;
        for (auto x: thou20Unique)
            outputFile << x << ", ";

        outputFile << std::endl;
    }
    if (pushedToMasterVect < 7) {
        masterVect.push_back(thou20Unique);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createThou30Randomized()
{
    if (pushedToMasterVect == 7)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 700; i++)
        thou30Randomized.push_back(i);

    for (int j = 1; j < 300; j++)
        thou30Randomized.push_back(randNum = std::rand() % 1000);

    if (alreadyWritten == false) {
        outputFile << "\n\nOne Thousand Numbers -- 30% Randomized" << std::endl;

        for (auto x: thou30Randomized)
            outputFile << x << ", ";

        outputFile << std::endl;
    }
    if (pushedToMasterVect < 8) {
        masterVect.push_back(thou30Randomized);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTenThouRandom()
{
    if (pushedToMasterVect == 8)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 10000; i++) {

        tenThouRandom.push_back(randNum = std::rand() % 10000 + 1); //adds a random number 1-10000 to the data set
    }

    //Decides whether or not to add the new data set to the output file
    if (alreadyWritten == false) {
        outputFile << "\n\nTen Thousand Numbers -- Random Order" << std::endl;

        for (auto v: tenThouRandom) {
            outputFile << v << ", ";
        }
        outputFile << std::endl;
        alreadyWritten = true;
    }

    if (pushedToMasterVect < 9) {
        masterVect.push_back(tenThouRandom);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTenThouReversedSortedOrder()
{
    if (pushedToMasterVect == 9)
        alreadyWritten = false;

    //Enters numbers into the vector for this dataset
    for (int i = 10000; i > 0; i--)
        tenThouReversedSortedOrder.push_back(i);

    //If this dataset hasn't been written to the file yet... write it to the file
    if (alreadyWritten == false) {
        outputFile << "\n\nTen Thousand Numbers -- Reversed Sorted Order" << std::endl;
        for (auto x: tenThouReversedSortedOrder)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 10) {
        masterVect.push_back(tenThouReversedSortedOrder);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTenThou20Unique()
{
    if (pushedToMasterVect == 10)
        alreadyWritten = false;

    for (int j = 1; j < 2000; j++) {
        for (int i = 1; i < 6; i++) {
            tenThou20Unique.push_back(i);
        }
    }
    if (alreadyWritten == false) {
        outputFile << "\n\nTen Thousand Numbers -- 20% Unique Values" << std::endl;
        for (auto x: tenThou20Unique)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 11) {
        masterVect.push_back(tenThou20Unique);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createTenThou30Randomized()
{
    if (pushedToMasterVect == 11)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 7000; i++)
        tenThou30Randomized.push_back(i);

    for (int j = 1; j < 3000; j++)
        tenThou30Randomized.push_back(randNum = std::rand() % 10000);

    if (alreadyWritten == false) {
        outputFile << "\n\nTen Thousand Numbers -- 30% Randomized" << std::endl;

        for (auto x: tenThou30Randomized)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 12) {
        masterVect.push_back(tenThou30Randomized);
        pushedToMasterVect++;
    }

}

template<typename T>
void DataSets<T>::createHunThouRandom()
{
    if (pushedToMasterVect == 12)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 100000; i++) {

        hunThouRandom.push_back(randNum = std::rand() % 100000 + 1); //adds a random number 1-100000 to the data set
    }

    //Decides whether or not to add the new data set to the output file
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Hundred Thousand Numbers -- Random Order" << std::endl;

        for (auto v: hunThouRandom) {
            outputFile << v << ", ";
        }
        outputFile << std::endl;
        alreadyWritten = true;
    }

    if (pushedToMasterVect < 13) {
        masterVect.push_back(hunThouRandom);
        pushedToMasterVect++;
    }
}

template<typename T>
void DataSets<T>::createHunThouReversedSortedOrder()
{
    if (pushedToMasterVect == 13)
        alreadyWritten = false;

    //Enters numbers into the vector for this dataset
    for (int i = 100000; i > 0; i--)
        hunThouReversedSortedOrder.push_back(i);

    //If this dataset hasn't been written to the file yet... write it to the file
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Hundred Thousand Numbers -- Reversed Sorted Order" << std::endl;
        for (auto x: hunThouReversedSortedOrder)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 14) {
        masterVect.push_back(hunThouReversedSortedOrder);
        pushedToMasterVect++;
    }
}

template<typename T>
void DataSets<T>::createHunThou20Unique()
{
    if (pushedToMasterVect == 14)
        alreadyWritten = false;

    for (int j = 1; j < 20000; j++) {
        for (int i = 1; i < 6; i++) {
            hunThou20Unique.push_back(i);
        }
    }
    if (alreadyWritten == false) {
        outputFile << "\n\nOne Hundred Thousand Numbers -- 20% Unique Values" << std::endl;
        for (auto x: hunThou20Unique)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 15) {
        masterVect.push_back(hunThou20Unique);
        pushedToMasterVect++;
    }
}

template<typename T>
void DataSets<T>::createHunThou30Randomized()
{
    if (pushedToMasterVect == 15)
        alreadyWritten = false;

    int randNum;
    for (int i = 0; i < 70000; i++)
        hunThou30Randomized.push_back(i);

    for (int j = 1; j < 30000; j++)
        hunThou30Randomized.push_back(randNum = std::rand() % 100000);

    if (alreadyWritten == false) {
        outputFile << "\n\nOne Hundred Thousand Numbers -- 30% Randomized" << std::endl;

        for (auto x: hunThou30Randomized)
            outputFile << x << ", ";

        outputFile << std::endl;
    }

    if (pushedToMasterVect < 16) {
        masterVect.push_back(hunThou30Randomized);
        pushedToMasterVect++;
    }
    outputFile.close();
}
