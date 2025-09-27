/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:01:03 by aelbouz           #+#    #+#             */
/*   Updated: 2025/09/23 11:37:45 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *local_time = std::localtime(&now);
	std::cout
	<<"[" << 1900 +local_time->tm_year
	<< std::setw(2) << std::setfill('0') << local_time->tm_mon + 1
	<< std::setw(2) << std::setfill('0') << local_time->tm_mday
	<< "_"
	<< std::setw(2) << std::setfill('0') << local_time->tm_hour
	<< std::setw(2) << std::setfill('0') << local_time->tm_min
	<< std::setw(2) << std::setfill('0') << local_time->tm_sec
	<< "] ";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:"<< _amount
	<< ";created"
	<<std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
	<< "index:" <<_accountIndex
	<< ";amount:" << _amount
	<< ":closed"<<std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit;
	
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout<<";withdrawal:refused"<<std::endl;
		return false;
	}
	
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals
	<< std::endl;
	return true;
}

int Account::checkAmount() const

{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}
