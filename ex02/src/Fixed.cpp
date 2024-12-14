#include "../include/Fixed.hpp"

const int	Fixed::_fraction = 8;

Fixed::Fixed(void): _value(0)
{
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_fraction;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_fraction));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

bool		Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool		Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool		Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool		Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool		Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool		Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float		Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float		Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float		Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float		Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed		Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed		Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed		Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	--this->_value;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
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