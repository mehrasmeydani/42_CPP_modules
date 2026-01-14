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

		bool			operator>(const Fixed &input) const;
		bool			operator<(const Fixed &input) const;
		bool			operator>=(const Fixed &input) const;
		bool			operator<=(const Fixed &input) const;
		bool			operator==(const Fixed &input) const;
		bool			operator!=(const Fixed &input) const;

		Fixed&			operator++(void);
		Fixed			operator++(int);
		Fixed&			operator--(void);
		Fixed			operator--(int);
		
		Fixed&			operator=(const Fixed &input);
		const Fixed		operator*(const Fixed &input) const;
		const Fixed		operator/(const Fixed &input) const;
		const Fixed		operator-(const Fixed &input) const;
		const Fixed		operator+(const Fixed &input) const;

		static const	Fixed&	min(const Fixed &input1, const Fixed &input2);
		static const	Fixed&	max(const Fixed &input1, const Fixed &input2);

		static  Fixed&	min(Fixed &input1, Fixed &input2);
		static  Fixed&	max(Fixed &input1, Fixed &input2);

		~Fixed();
		Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);