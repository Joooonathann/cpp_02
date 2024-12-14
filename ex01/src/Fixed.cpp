#include "../include/Fixed.hpp"

const int	Fixed::_fraction = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fraction;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fraction));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

int			Fixed::getRawBits(void) const
{
	return (this->_value);
}

void		Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_value / (float)(1 << this->_fraction));
}

int	Fixed::toInt(void)const
{
	return (this->_value >> this->_fraction);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}