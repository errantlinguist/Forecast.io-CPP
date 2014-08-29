#ifndef MULTIMAP_EXTENSION_HPP
#define MULTIMAP_EXTENSION_HPP

#include <unordered_map>
#include <unordered_set>

namespace common
{

template<typename K, typename V>
std::unordered_set<K> createKeySet(
		const std::unordered_multimap<K, V>& multimap)
{
	std::unordered_set<K> result(multimap.size());
	for (auto it = multimap.cbegin(), end = multimap.cend(); it != end; it =
			multimap.equal_range(it->first).second)
	{
		result.insert(it->first);
	}

	return result;
}

}

#endif // MULTIMAP_EXTENSION_HPP
