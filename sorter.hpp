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

#ifndef SORTING_HPP
#define SORTING_HPP

//Headers from standartd libraries
#include <chrono>

class sorter
{
private:
        /// Private data members

        int *m_array;
        int *m_original_array;
        int m_size;
        long m_time;
        bool m_timer;
        std::chrono::high_resolution_clock::time_point m_time_1;
        std::chrono::high_resolution_clock::time_point m_time_2;
public:
        /// Getter/Setter

        int getSize();

        /// Sorting methods
        void doSelectionSorting();
        void doBubbleSorting();
        void doInsertionSorting();
        void doMergeSorting(int = 0, int = -1);
        void doQuickSorting(int = 0, int = -1);

private:
        /// Private assissting functions
        void merge(int, int);
        void swap(int&, int&);
        int findPivot(int, int);
        int doPartitioning(int, int, int);
        void reverse();
public:
        /// Public assissting functions
        void print();
        long getDuration();
        void startTimer();
        void endTimer();
        void reset();

        /// Constructor
        sorter(int, int* = nullptr);

        /// Destructor
        ~sorter();

};

#endif //SORTING_HPP
