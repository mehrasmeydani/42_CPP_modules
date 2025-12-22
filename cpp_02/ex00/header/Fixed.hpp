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
		Fixed(const Fixed &input);
		Fixed& operator=(const Fixed &input);
		~Fixed();
		Fixed();
};