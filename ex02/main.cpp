/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:19:42 by assabich          #+#    #+#             */
/*   Updated: 2026/06/04 20:57:36 by assabich         ###   ########.fr       */
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
        merge.jacob();
        merge.print_after();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}