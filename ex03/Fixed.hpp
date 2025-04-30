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
		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		bool operator==(const Fixed& rhs);
		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat() const;
		int toInt() const;
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static float getSmallestRepresentable();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
