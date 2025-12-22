#pragma once

#include <iostream>

class Fixed
{
	public:
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;


	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &input);

		bool			operator>(const Fixed &input);
		bool			operator<(const Fixed &input);
		bool			operator>=(const Fixed &input);
		bool			operator<=(const Fixed &input);
		bool			operator==(const Fixed &input);
		bool			operator!=(const Fixed &input);

		Fixed&			operator++(void);
		Fixed			operator++(int);
		Fixed&			operator--(void);
		Fixed			operator--(int);
		
		Fixed&			operator=(const Fixed &input);
		Fixed			operator*(const Fixed &input);
		Fixed			operator/(const Fixed &input);
		Fixed			operator-(const Fixed &input);
		Fixed			operator+(const Fixed &input);

		Fixed&			min(Fixed &input1, Fixed &input2);
		Fixed&			max(Fixed &input1, Fixed &input2);

		const Fixed&	min(const Fixed &input1, const Fixed &input2);
		const Fixed&	max(const Fixed &input1, const Fixed &input2);
		
		~Fixed();
		Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);