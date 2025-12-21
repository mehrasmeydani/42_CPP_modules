#pragma once

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

	public:
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		Fixed();
};