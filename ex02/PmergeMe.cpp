/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:18:54 by assabich          #+#    #+#             */
/*   Updated: 2026/06/05 19:16:06 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        long nb = atol(av[i]);
        if (nb < 0 || nb > INT_MAX || std::find(vec.begin(), vec.end(), static_cast<int>(nb)) != vec.end())
            throw std::runtime_error("Error: number < 0 or > INT_MAX or duplicate number");
    
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

void    PmergeMe::jacob()
{
    //sort dequeue
    clock_t start = clock();

    deq = sort(deq);

    clock_t end = clock();

    double t_deq = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    
    //sort vector
    start = clock();

    vec = sort(vec);

    end = clock();

    double t_vec = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    print_after(t_vec, t_deq);

}

void    PmergeMe::print_before()
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' '; 
    std::cout << std::endl;
    //PS: check how to remove the last ' '

}

void    PmergeMe::print_after(double t_vec, double t_deq)
{
    std::cout << "After:  ";
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' '; 
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << t_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << t_deq << " us" << std::endl;
}