#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		static std::string& _trim(std::string& s);
		static bool _isValidDate(const std::string& date);
		static bool _parseValue(const std::string& valueStr, float& outValue);
		float _getRate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void evaluate(const std::string& filename) const;
};

#endif