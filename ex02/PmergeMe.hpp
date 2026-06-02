/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:19:13 by assabich          #+#    #+#             */
/*   Updated: 2026/06/02 20:19:58 by assabich         ###   ########.fr       */
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

class PmergeMe
{
    public:
    PmergeMe(int ac, char** av);
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &copy);
    void    print_result();

    private:
        PmergeMe();
        std::vector<int>    vec;
        std::deque<int>     deq;
};

#endif