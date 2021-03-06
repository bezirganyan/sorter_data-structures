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

template <class T>
class sorter
{
private:
        /// Private data members

        T *m_array;
        T *m_original_array;
        int m_size;
        long m_time;
        bool m_timer;
        std::chrono::high_resolution_clock::time_point m_time_1;
        std::chrono::high_resolution_clock::time_point m_time_2;
public:
        /// Getter/Setter

        int getSize();

        /// Sorting methods
        void doSelectionSorting(bool = true);
        void doBubbleSorting(bool = true);
        void doInsertionSorting(bool = true);
        void doMergeSorting(bool = true, int = 0, int = -1);
        void doQuickSorting(bool = true, int = 0, int = -1);

private:
        /// Private assissting functions
        void merge(int, int, bool = true);
        void swap(T&, T&);
        int findPivot(int, int);
        int doPartitioning(T, int, int, bool = true);
        void reverse();
        bool isGreater(T, T, bool = true);
public:
        /// Public assissting functions
        void print();
        long getDuration();
        void startTimer();
        void endTimer();
        void reset();

        /// Constructor
        sorter(int, T* = nullptr);

        /// Destructor
        ~sorter();

};
#endif //SORTING_HPP
