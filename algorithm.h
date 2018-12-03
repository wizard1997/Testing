#pragma once

#include <vector>

class Algorithm{

    public:

        enum sortingAlgos{
            bubble,
            insertion,
            merge,
            LAST
        } sortAlgo;

        virtual void createDataSets() = 0;
        virtual void load() = 0;
        virtual void execute() = 0;
        virtual void stats() = 0;

        virtual void display(std::vector<int>&) = 0;
        virtual void save() = 0;

        virtual ~Algorithm() {

        }


};
