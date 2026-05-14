/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:53 by assabich          #+#    #+#             */
/*   Updated: 2026/04/06 17:07:11 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "BitcoinExchange.hpp"

int error_file(void)
{
    std::cout << "Error: could not open file." << std::endl;
    return(1);
}

int main(int ac, char** av)
{
    std::ifstream   input;
    std::ifstream   data;
    
    if (ac == 2)
    {
        data.open("data.csv");
        input.open(av[1]);
        if (!input.is_open() || !data.is_open())
        {
            input.close();
            data.close();    
            return(error_file());
        }
        BitcoinExchange btc;
        btc.fill_db(data);
        //actions of
        //1. parsing data and stock in _db map
        //2. reading and multiplying data and printing
        input.close();
        data.close();
    }
    else
        return(error_file());
    return (0);
}
