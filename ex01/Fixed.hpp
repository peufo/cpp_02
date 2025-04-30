#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int 				raw;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed& operator=(const Fixed& fixed);
		

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
