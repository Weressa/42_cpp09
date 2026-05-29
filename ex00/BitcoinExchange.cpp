/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:04:09 by assabich          #+#    #+#             */
/*   Updated: 2026/05/29 15:51:36 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): _db(copy._db) {}
    
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (&copy != this)
        _db = copy._db;
    return(*this);
}

std::string get_key(std::string &line)
{
    
}

double get_value(std::string &line)
{
    
}

void BitcoinExchange::check_file(std::ifstream &file) 
{
    std::string line;
    if (getline(data, line) != "date | value")
    {
        std::cerr << "Error: wrong header." << 
        return;
    }

    while (getline(data, line))
    {
        
    }
}




void BitcoinExchange::fill_db(std::ifstream &data) 
{
    std::string line;
    while (getline(data, line))
    {
        _db[get_key(line)] = get_value(line);
    }
}