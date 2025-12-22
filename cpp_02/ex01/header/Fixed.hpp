#pragma once

#include <iostream>

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;


	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &input);
		Fixed& operator=(const Fixed &input);
		~Fixed();
		Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);