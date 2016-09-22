// Created by : Grigor Bezirganyan
// Email : grigor.bezirganyan98@gmail.com
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, see <http://www.gnu.org/licenses/>.

// Headers from standard libraries
#include <iostream>

// Headers from this project
#include "sorter.hpp"

// This is the live demo of the library
// For running it type "make" in your
// terminal or command line and the simply run
// the application by typing "./demo"
//
// Read the README.md for more details

int main(void)
{
        int size;
        sorter *sorted;
        std::cout << "Please input size of array" << std::endl;
        std::cin >> size;
        std::cout << "If you want to type array manually type 1\
                \nIf you want to try on live demo typr 0" << std::endl;
        bool live;
        std::cin >> live;
        if (true == live) {
                int *array = new int[size];
                std::cout << "Please input the array" << std::endl;
                for (int i = 0; i < size; i++) {
                        std::cin >> array[i];
                }
                sorted = new sorter(size, array);
        } else {
                sorted = new sorter(size);
        }
        std::cout << "\n\n Original Array " << std::endl;
        sorted->print();
        sorted->startTimer();
        sorted->doSelectionSorting();
        sorted->endTimer();
        std::cout << "\n\n Selection Sort - "<< sorted->getDuration() <<" ns\n\n" << std::endl;
        sorted->print();
        sorted->reset();
        sorted->print();
        sorted->startTimer();
        sorted->doBubbleSorting();
        sorted->endTimer();
        std::cout << "\n\n Bubble Sort -  "<< sorted->getDuration() <<" ns\n\n" << std::endl;
        sorted->print();
        sorted->reset();
        sorted->startTimer();
        sorted->doInsertionSorting();
        sorted->endTimer();
        std::cout << "\n\n Insertion Sort - "<< sorted->getDuration() <<" ns\n\n" << std::endl;
        sorted->print();
        sorted->reset();
        sorted->startTimer();
        sorted->doMergeSorting();
        sorted->endTimer();
        std::cout << "\n\n Merge Sort - "<< sorted->getDuration() <<" ns\n\n" << std::endl;
        sorted->print();
        sorted->reset();
        sorted->startTimer();
        sorted->doQuickSorting();
        sorted->endTimer();
        std::cout << "\n\n Quick Sort - "<< sorted->getDuration() <<" ns\n\n" << std::endl;
        sorted->print();

        return 0;
}
