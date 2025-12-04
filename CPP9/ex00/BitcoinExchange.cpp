/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:07:37 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 09:56:37 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

// ============================================================================
// Handlers

// Default Constructor
BitcoinExchange::BitcoinExchange() :
	_fileName("Default filename.") {}

// Custom Constructor
BitcoinExchange::BitcoinExchange( const String &filename ) :
	_fileName(filename)
{
	if ( this->_fileName.empty() )
		throw EmptyFileNameException();

	loadDatabase();
}

// Copy Constructor
BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) :
	_fileName(other._fileName),
	_database(other._database) {}

// Assignation operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if ( this != &other )
	{
		this->_fileName = other._fileName;
		this->_database = other._database;
	}

	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// =============================================================================
// Getters

const std::map<String, double> &BitcoinExchange::getDatabase() const
{
	return this->_database;
}

const String &BitcoinExchange::getFileName() const
{
	return this->_fileName;
}

// =============================================================================
// Methods

void BitcoinExchange::loadDatabase()
{
	// Open the file
	std::ifstream file(this->_fileName.c_str());

	// Error handler
	if (!file.is_open())
		throw FileNotFoundException();

	// Get line
	String line;

	// Check first line
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw InvalidDatabaseFormatException();

	while (std::getline(file, line))
	{
		// get the separator pos
		size_t pos = line.find(',');

		if (pos != String::npos)
		{
			// get date
			String date = line.substr(0, pos);

			// get rate
			double rate = std::atof(line.substr(pos + 1).c_str());

			// file ddb
			this->_database[date] = rate;
		}
	}
	file.close();
}

void BitcoinExchange::processFile(const String &inputFile)
{
	// Open file
	std::ifstream file(inputFile.c_str());

	// Error handler
	if ( !file.is_open() ) throw FileNotFoundException();

	// Get line
	String line;

	// Check First line
	if (!std::getline(file, line) || line != "date | value")
	{
		std::cout << "Error: invalid header format.\n";
		file.close();
		return ;
	}

	while ( std::getline(file, line) )
	{
		try
		{
			// Parse date / val
			size_t pos = line.find(" | ");

			if ( pos == String::npos )
			{
				std::cout << "Error: bad input (missing separator) => " << line << std::endl;
				continue;
			}

			// get date
			String date = line.substr(0, pos);

			// get value string
			String valueStr = line.substr(pos + 3);

			// Check value format
			if (!isValidValueFormat(valueStr))
			{
				std::cout << "Error: bad input (invalid value format) => " << valueStr << std::endl;
				continue;
			}

			double value = std::atof(line.substr(pos + 3).c_str());

			// Checking
			if (!isValidDate(date))
			{
				std::cout << "Error: invalid date => " << date << std::endl;
				continue;
			}

			if (!isValidValue(value))
			{
				if (value <= 0)
					std::cout << "Error: not a positive number.\n";
				else
					std::cout << "Error: too large number.\n";
				continue;
			}

			// Ouput
			double exchangeRate = getExchangeRate(date);
			double result = value * exchangeRate;

			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::isValidDate(const String &date)
{
	// Check length
	if (date.length() != 10) return false;

	// Check '-' separator
	if (date[4] != '-' || date[7] != '-') return false;

	// Check number
	for (int i = 0; i < 10; i++)
	{
		// Skip '-'
		if (i == 4 || i == 7) continue;

		if (!isdigit(date[i])) return false;
	}

	// Get values
	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5, 2). c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	// Verif f.... value fev, 30 and leap years
	int daysInMonth;
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		daysInMonth = isLeap ? 29 : 28;
	}

	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;

	else
		daysInMonth = 31;

	return (
		year >= 1000 && year <= 9999 &&
		month >= 1 && month <= 12 &&
		day >= 1 && day <= daysInMonth
	);
}

bool BitcoinExchange::isValidValueFormat(const String &str)
{
	if (str.empty()) return false;

	size_t i = 0;

	if (str[0] == '-' || str[0] == '+') i = 1;

	if (i >= str.length()) return false;

	bool hasDot = false;
	bool hasDigit = false;
	size_t dotPos = 0;

	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot) return false;
			hasDot = true;
			dotPos = i;
		}

		else if (isdigit(str[i]))
			hasDigit = true;
		else
			return false;
	}

	// Check for excessive decimal places (more than 10)
	if (hasDot && (str.length() - dotPos - 1) > 10)
		return false;

	return hasDigit;
}

bool BitcoinExchange::isValidValue(const double &val)
{
	return (val > 0 && val <= 1000);
}

double BitcoinExchange::getExchangeRate(const String &date)
{
	// Iterator on date
	std::map<String, double>::iterator it = _database.find(date);

	// return date if perfect match
	if (it != _database.end()) return it->second;

	// if not check the anterior date
	it = _database.upper_bound(date);

	// check if this date exists
	if (it == _database.begin()) throw NoDataAvailableException();

	// return the anterior date
	--it;
	return it->second;
}

// =============================================================================
// Exceptions

// Files Exceptions
IMPLEMENT_EXCEPTION(FileNotFoundException, "File not found.")
IMPLEMENT_EXCEPTION(EmptyFileNameException, "Filename cannot be empty.")

// BBD Exception
IMPLEMENT_EXCEPTION(NoDataAvailableException, "Nothing found in the database.")
IMPLEMENT_EXCEPTION(InvalidDatabaseFormatException, "Error: invalid database format.")
