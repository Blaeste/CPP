/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:07:13 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/02 11:05:55 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes

#pragma once
#include <map>
#include <string>
#include <stdexcept>

// =============================================================================
// Typedef

typedef std::string String;

// =============================================================================
// Defines

#define DECLARE_EXCEPTION(ExceptionName)          \
	class ExceptionName : public std::exception   \
	{                                             \
	public:                                       \
		virtual const char *what() const throw(); \
	};

#define IMPLEMENT_EXCEPTION(ExceptionName, message)           \
	const char *BitcoinExchange::ExceptionName::what() const throw() \
	{                                                         \
		return message;                                       \
	}


// =============================================================================
// Class BitcoinExchange

class BitcoinExchange {

	private:

		// Filename
		String _fileName;

		// Map container
		std::map<String, double> _database;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		BitcoinExchange( void );

		// Custom Constructor
		BitcoinExchange( const String &filename );

		// Copy Constructor
		BitcoinExchange( const BitcoinExchange &other );

		// Assignation operator
		BitcoinExchange&operator=(const BitcoinExchange &other);

		// Destructor
		~BitcoinExchange( void );

		// =====================================================================
		// Getters

		const std::map<String, double> &getDatabase() const;
		const String &getFileName() const;

		// =====================================================================
		// Methods

		void loadDatabase();
		void processFile(const String &inputFile);

		bool isValidDate(const String &date);
		bool isValidValueFormat(const String &str);
		bool isValidValue(const double &val);

		double getExchangeRate(const String &date);

		// =====================================================================
		// Exceptions

		// Files Exceptions
		DECLARE_EXCEPTION(FileNotFoundException);
		DECLARE_EXCEPTION(EmptyFileNameException);

		// BBD Exception
		DECLARE_EXCEPTION(NoDataAvailableException);
		DECLARE_EXCEPTION(InvalidDatabaseFormatException);
};
