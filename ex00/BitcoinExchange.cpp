/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:04:09 by assabich          #+#    #+#             */
/*   Updated: 2026/05/31 02:57:36 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// 1.canonic form musts

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): _db(copy._db) {}
    
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (&copy != this)
        _db = copy._db;
    return(*this);
}

// 2.the real deal

//fill the map _db from data.csv

void BitcoinExchange::fill_db(std::ifstream &data) 
{
    std::string line;
    
    getline(data, line);
    while (getline(data, line))
    {
        std::string date;
        std::string StrExRate;
        float ExchangeRate;
        
        std::istringstream linef(line);

        getline(linef, date, ',');
        getline(linef, StrExRate);
        
        std::istringstream  Rate(StrExRate);
        if (!(Rate >> ExchangeRate))
            throw std::invalid_argument("Invalid exchange rate");        check_date(date);
        _db[date] = ExchangeRate;
    }
}

// check and calculate input file

void BitcoinExchange::handle_input(std::ifstream &file) 
{
    std::string line;
    getline(file, line);
    if (line != "date | value")
        throw (std::invalid_argument("Error: wrong header." ));

    while (getline(file, line))
    {
        std::string date, pipe;
        std::string str_value;
        float value;
        
        std::istringstream linef(line);
        
        std::string date, pipe, str_value;
        if (!(linef >> date >> pipe >> str_value))
            throw std::invalid_argument("Error: bad input => " + line);

        if (pipe != "|")
            throw std::invalid_argument("Error: bad input => " + line);

        check_date(date);        
        std::istringstream  ssvalue(str_value);
        ssvalue >> value;
        check_value(value);
        float result = value * get_exchange(date);
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

// checkers and getters

void BitcoinExchange::check_date(const std::string& date) 
{
    if(date.size() != 10)
        throw (std::invalid_argument("Error: Invalid date format: " + date));
    
    for (int i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7)
        {
            if(date[i] != '-')
                throw (std::invalid_argument("Error: Invalid date format: " + date));
        }
        else
        {
            if(!isdigit(date[i]))
                throw (std::invalid_argument("Error: Invalid date format: " + date));
        }
    }

    int year, month, day;
    std::istringstream ssyear(date.substr(0,4));
    ssyear >> year;

    std::istringstream ssmonth(date.substr(5,2));
    ssmonth >> month;

    std::istringstream ssday(date.substr(8,2));
    ssday >> day;
    
    if(month < 1 || month > 12)
        throw (std::invalid_argument("Error: Invalid date format: " + date));
    
    if(day < 1 || day > 31)
        throw (std::invalid_argument("Error: Invalid date format: " + date));
    
    if(month == 2)
    {
        if(year % 4 == 0)
        {
            if(day > 29)
                throw (std::invalid_argument("Error: Invalid date format: " + date));
        }
        else
        {
            if(day > 28)
                throw (std::invalid_argument("Error: Invalid date format: " + date));
        }
    }
    else if(month == 4 || month == 6 || month == 9 ||month == 11)
    {
        if(day > 30)
            throw (std::invalid_argument("Error: Invalid date format: " + date));
    }
    else
    {
        if(day > 31)
            throw (std::invalid_argument("Error: Invalid date format: " + date));
    }
}

void BitcoinExchange::check_value(float value)
{
    if (value < 0)
        throw (std::runtime_error("Error: Invalid value: negative number"));
    if (value > 1000)
        throw (std::runtime_error("Error: Invalid value: number too large"));
}

float BitcoinExchange::get_exchange(const std::string &date)
{
    std::map<std::string, float>::iterator i;
    
    i = _db.find(date);
    if (i != _db.end())
        return (i->second);
    
    i = _db.lower_bound(date); //lower_bound gives i+1 date

    if (i == _db.begin()) //the date indicated is before the 1st date
        throw (std::invalid_argument("Error: no exchange rate available." ));
    i--;
    return (i->second);
}