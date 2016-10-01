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
#include <cstdlib>
#include <time.h>

// Headers from this project
#include "sorter.hpp"

//Template type explicit definitions
template class sorter<int>;
template class sorter<unsigned int>;
template class sorter<long>;
template class sorter<long long>;
template class sorter<float>;
template class sorter<double>;
//template class sorter<char>;
//TODO - make it workable with chars

template <class T>
int sorter<T>::getSize()
{
        return m_size;
}

template <class T>
void sorter<T>::doSelectionSorting(bool order)
{
        unsigned int length = m_size;
        T temp;
        unsigned int max;
        for (int i = 0; i < m_size; i++) {
                max = 0;
                for (unsigned int ind = 0; ind < length; ind++) {
                        if (isGreater(m_array[ind], m_array[max], order)) {
                                max = ind;
                        }
                }
                temp = m_array[max];
                m_array[max] = m_array[length - 1];
                m_array[length - 1] = temp;
                length--;
        }
}

template <class T>
void sorter<T>::doBubbleSorting(bool order)
{
        bool sorted = false;
        int pass = 1;
        int n = m_size;
        while (!sorted && pass < n) {
                sorted = true;
                for (int i = 0; i < n - pass; i++) {
                        if (isGreater(m_array[i], m_array[i+1], order)) {
                                m_array[i] = m_array[i] + m_array[i+1];
                                m_array[i+1] = m_array[i] - m_array[i+1];
                                m_array[i] = m_array[i] - m_array[i+1];
                                sorted = false;
                        }
                }
                pass++;
        }
}

template <class T>
void sorter<T>::doInsertionSorting(bool order)
{
        int n = m_size;
        T next;
        int loc;
        for (int unsorted = 1; unsorted < n; unsorted++) {
                next = m_array[unsorted];
                loc = unsorted;
                while (loc > 0 && isGreater(m_array[loc - 1], next, order)) {
                        m_array[loc] = m_array[loc -1];
                        loc--;
                        m_array[loc] = next;
                }
        }
}

template <class T>
void sorter<T>::doMergeSorting(bool order, int start, int end)
{
        if (end == -1) {
                end = m_size - 1;
        }
        if ((end - start) < 1) {

        } else {
                doMergeSorting(order, start, (end+start)/2);
                doMergeSorting(order, (end+start)/2+1, end);
                merge(start, end, order);
        }
}

template <class T>
void sorter<T>::doQuickSorting(bool order, int left, int right)
{
        if (right == -1) {
                right = m_size - 1;
        }
        if (right-left <=0) {

        } else {
                int pivot = findPivot(left, right);
                int partition = doPartitioning(m_array[pivot], left, right, order);
                doQuickSorting(order, left, partition - 1);
                doQuickSorting(order, partition + 1, right);
        }
}

template <class T>
void sorter<T>::merge(int start, int end, bool order)
{
        int div = (start + end)/2 + 1;
        T *new_array = new T[m_size];
        for (int i = 0; i < m_size; i++) {
                new_array[i] = m_array[i];
        }
        int left_ind = start;
        int right_ind = div;
        int new_ind = start;
        while (left_ind < div && right_ind <= end) {
                if (isGreater(m_array[right_ind], m_array[left_ind], order)) {
                        new_array[new_ind] = m_array[left_ind];
                        new_ind++;
                        left_ind++;
                } else {
                        new_array[new_ind] = m_array[right_ind];
                        new_ind++;
                        right_ind++;
                }
        }
        while (left_ind < div) {
                new_array[new_ind] = m_array[left_ind];
                new_ind++;
                left_ind++;
        }
        while (right_ind <= end) {
                new_array[new_ind] = m_array[right_ind];
                new_ind++;
                right_ind++;
        }

        for (int i = 0; i < m_size; i++) {
                m_array[i] = new_array[i];
        }
}

template <class T>
void sorter<T>::swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
}

template <class T>
int sorter<T>::findPivot(int left, int right) {
        srand (time(NULL));
        int rand_1 = (rand() % (right-left)) + left;
        //int rand_2 = (rand() % (right-left)) + left;
        //int rand_3 = (rand() % (right-left)) + left;

        //if ((m_array[rand_1] <= m_array[rand_2] && m_array[rand_2] <= m_array[rand_3]) ||
        //                (m_array[rand_3] <= m_array[rand_2] && m_array[rand_2] <= m_array[rand_1])) {
        //        return rand_2;
        //} else if ((m_array[rand_2] <= m_array[rand_1] && m_array[rand_1] <= m_array[rand_3]) ||
        //                (m_array[rand_3] <= m_array[rand_1] && m_array[rand_1] <= m_array[rand_2])) {
        //        return rand_1;
        //} else if ((m_array[rand_1] <= m_array[rand_3] && m_array[rand_3] <= m_array[rand_2]) ||
        //                (m_array[rand_2] <= m_array[rand_3] && m_array[rand_3] <= m_array[rand_1])) {
        //        return rand_3;
        //}
        return rand_1;

        //Note, this had to generate 3 randoms and choose the middle one.
        //Nevertheless for big numbers, it causes stack overflow (if I undrstood
        //correctly) and throws Segmentation Fault.
        //
        //TODO - fix this part
}

template <class T>
int sorter<T>::doPartitioning(T pivot, int left, int right, bool order)
{
        int leftPointer = left;
        int rightPointer = right;
        while (true) {
                while (isGreater(pivot, m_array[leftPointer], order)) {
                        leftPointer++;
                }

                while (rightPointer > 0 && isGreater(m_array[rightPointer], pivot, order))  {
                        rightPointer--;
                }

                if (leftPointer >= rightPointer) {
                        break;
                } else if (!(m_array[leftPointer] > m_array[rightPointer]) && !(m_array[leftPointer] < m_array[rightPointer])) {
                        leftPointer++;
                } else {
                        swap(m_array[leftPointer], m_array[rightPointer]);
                }

        }
        return leftPointer;
}

template <class T>
void sorter<T>::print()
{
        for (int i = 0; i < m_size; i++) {
                std::cout << "[" <<  m_array[i] << "] ";
        }
        std::cout << std::endl;
}

template <class T>
void sorter<T>::startTimer()
{
        m_time_1 = std::chrono::high_resolution_clock::now();
}

template <class T>
void sorter<T>::endTimer()
{
        m_time_2 = std::chrono::high_resolution_clock::now();
        m_time = std::chrono::duration_cast<std::chrono::nanoseconds>(m_time_2 - m_time_1).count();
}

template <class T>
long sorter<T>::getDuration()
{
        return m_time;
}

template <class T>
void sorter<T>::reset()
{
        for (int i = 0; i < m_size; i++){
                m_array[i] = m_original_array[i];
        }
}

template <class T>
bool sorter<T>::isGreater(T a, T b, bool asc)
{
        if (a > b && asc) {
                return true;
        } else if (b > a && asc) {
                return false;
        } else if (a > b && !asc) {
                return false;
        } else if (b > a && !asc) {
                return true;
        }

        return 0;
}

template <class T>
sorter<T>::sorter(int s, T* ar)
{
        m_size = s;
        m_array = new T[m_size];
        m_original_array = new T[m_size];
        if (ar == nullptr) {
                for (int i = 0; i < m_size; i++) {
                        srand (time(NULL));
                        m_array[i] = (static_cast <T> (rand())) /(static_cast <float> (RAND_MAX/(m_size - 0)));
                }
        } else {
                m_array = ar;
        }
        for (int i = 0; i < m_size; i++){
                m_original_array[i] = m_array[i];
        }
}

template <class T>
sorter<T>::~sorter()
{
        //destructor
}
