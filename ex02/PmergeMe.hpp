/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:19:13 by assabich          #+#    #+#             */
/*   Updated: 2026/06/03 21:09:09 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>

struct Pair
{
    int big;
    int small;
};

template <typename T>
typename T::iterator    insert_position(T &cont, int value)
{
    typename T::iterator    left = cont.begin();
    typename T::iterator    right = cont.end();
    
    while (left < right)
    {
        typename T::iterator mid = left + (right - left) / 2;
        
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}


class PmergeMe
{
    public:
    PmergeMe(int ac, char** av);
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &copy);
    
    void    print_before();
    void    sort();

    private:
        PmergeMe();
        std::vector<int>    vec;
        std::deque<int>     deq;
};

#endif