/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:18:54 by assabich          #+#    #+#             */
/*   Updated: 2026/06/03 21:11:00 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        long nb = atol(av[i]);
        if (nb < 0 || nb > INT_MAX)
            throw std::runtime_error("Error: number < 0 or > INT_MAX");
    
        vec.push_back(static_cast<int>(nb));
        deq.push_back(static_cast<int>(nb));
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy): vec(copy.vec), deq(copy.deq) {}

PmergeMe::~PmergeMe() {}
    
PmergeMe    &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this->vec != copy.vec)
        vec = copy.vec;
    if (this->deq != copy.deq)
        deq = copy.deq;
    return (*this);
}

void    PmergeMe::print_before()
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' '; 
    //PS: check how to remove the last ' '

}

void    PmergeMe::sort(T &data)
{
    std::T<Pair> pairs;

    int strag = -1;
    for (int i = 0; i + 1 < data.size(); i+= 2)
    {
        Pair p;
        if (data[i] > data[i + 1])
        {
            p.big = data[i];
            p.small = data[i + 1];
        }
        else
        {
            p.big = data[i + 1];
            p.small = data[i];
        }
        pairs.push_back(p);
    }

    if (data.size() % 2)
        strag = data.back();
    
    T   bigs;
    
    for (int i = 0; i < pairs.size(); i++)
        bigs.push_back(pairs[i].big);

    std::T<int> mainchain;

}

