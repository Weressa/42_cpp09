/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:19:42 by assabich          #+#    #+#             */
/*   Updated: 2026/06/03 20:59:01 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    try
    {
        if (ac < 2)
            throw std::runtime_error("Error: format must be:\n./PmergeMe nb1 nb2 ... (minimum two integers)\n");
        PmergeMe    merge(ac, av);        
        merge.print_before();
        merge.sort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}