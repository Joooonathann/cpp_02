#ifndef __FIXED__
	#define __FIXED__

	#include <iostream>
	#include <cmath>

	class Fixed
	{
		private:
			int					_value;
			static const int	_fraction;
		public:
			Fixed(void);
			Fixed(const int value);
			Fixed(const float value);
			~Fixed(void);
			Fixed(Fixed const &copy);
			Fixed			&operator=(const Fixed &copy);
			bool			operator>(Fixed fixed) const;
			bool			operator<(Fixed fixed) const;
			bool			operator>=(Fixed fixed) const;
			bool			operator<=(Fixed fixed) const;
			bool			operator==(Fixed fixed) const;
			bool			operator!=(Fixed fixed) const;
			float			operator+(Fixed fixed) const;
			float			operator-(Fixed fixed) const;
			float			operator*(Fixed fixed) const;
			float			operator/(Fixed fixed) const;
			Fixed			operator++();
			Fixed			operator--();
			Fixed			operator++(int);
			Fixed			operator--(int);
			int				getRawBits(void) const;
			void			setRawBits(const int raw);
			float			toFloat( void ) const;
			int				toInt( void ) const;
			static 			Fixed &min(Fixed &first, Fixed &second);
			static const 	Fixed &min(Fixed const &first, Fixed const &second);
			static 			Fixed &max(Fixed &first, Fixed &second);
			static const 	Fixed &max(Fixed const &first, const Fixed &second);
	};
	
	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif