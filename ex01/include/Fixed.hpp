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
			int				getRawBits(void) const;
			void			setRawBits(const int raw);
			float			toFloat( void ) const;
			int				toInt( void ) const;
	};
	
	std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif