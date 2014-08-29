#ifndef ENUMERATION_HPP
#define ENUMERATION_HPP

#include <cstddef>

namespace common
{

template<typename E>
constexpr std::size_t getEnumIndex(const E value) noexcept
{
	static_assert(std::is_enum<E>::value, "Type is not an enum.");
	return static_cast<std::size_t>(value);
}

}

#endif /* ENUMERATION_HPP */
