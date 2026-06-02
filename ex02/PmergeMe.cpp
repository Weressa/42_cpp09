/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:18:54 by assabich          #+#    #+#             */
/*   Updated: 2026/06/02 20:37:25 by assabich         ###   ########.fr       */
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

void    PmergeMe::print_result()
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' '; 
    //PS: check how to remove the last ' '

}

