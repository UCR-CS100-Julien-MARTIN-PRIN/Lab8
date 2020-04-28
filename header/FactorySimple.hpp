#ifndef __FACTORYSIMPLE_HPP__
#define __FACTORYSIMPLE_HPP__

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "FactoryInterface.hpp"
#include "Operations.hpp"
using namespace std;

class FactorySimple : public FactoryInterface
{
	public:
		/* Constructors */
		FactorySimple() {};	

		Base* parse(char** entry, int length)
		{
			vector<Base*> op;
			Base* temp;
			Base* result;
			string input = entry[0];
			int j = 0;
			string number = "";

			/* Creating all the numbers */
			for (int i = 0; i < length; i++)
			{
				if (input[i] == '+')
				{
					if (number != "")
					{
						temp = new Op(std::stod(number));
						op.push_back(temp);
					}
					
					number = "";
				}
				else if (input[i] == '-')
				{
					if (number != "")
					{
						temp = new Op(std::stod(number));
						op.push_back(temp);
					}

					number = "";
				}
				else if (input[i] == '*')
				{
					if (number != "")
					{
						temp = new Op(std::stod(number));
						op.push_back(temp);
					}

					number = "";
				}
				else if (input[i] == '/')
				{
					if (number != "")
					{
						temp = new Op(std::stod(number));
						op.push_back(temp);
					}

					number = "";
				}
				else
				{
					number += input[i];
				}
			}

			if (number != "")
			{
				temp = new Op(std::stod(number));
				op.push_back(temp);
			}

			/* Creating the expression tree */
			temp = op.at(0);
			result = temp;
			j = 1;

			for (int i = 0; i < length; i++)
			{
				if (j < op.size())
				{
					if (input[i] == '+')
					{
						temp = new Add(result, op.at(j));
						result = temp;
						j++;
					}
					else if (input[i] == '-')
					{
						temp = new Sub(result, op.at(j));
						result = temp;
						j++;
					}
					else if (input[i] == '*')
					{
						if (input[i + 1] == '*')
						{
							temp = new Pow(result, op.at(j));
							result = temp;
							j++;
						}
						else
						{
							temp = new Mult(result, op.at(j));
							result = temp;
							j++;
						}
					}
					else if (input[i] == '/')
					{
						temp = new Div(result, op.at(j));
						result = temp;
						j++;
					}
				}
			}

			return result;
		};

};

#endif
