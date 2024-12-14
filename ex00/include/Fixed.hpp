#ifndef __FIXED__
	#define __FIXED__

	#include <iostream>

	class Fixed
	{
		private:
			int					_value;
			static const int	_fraction;
		public:
			Fixed(void);
			~Fixed(void);
			Fixed(Fixed const &copy);
			Fixed			&operator=(const Fixed &copy);
			int				getRawBits(void) const;
			void			setRawBits(const int raw);
	};

#endif