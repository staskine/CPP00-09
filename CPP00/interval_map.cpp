
#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map; 
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	template<typename V_forward>
	void assign( K const& keyBegin, K const& keyEnd, V_forward&& val )
		requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
	{
		if (m_map.empty())
			return ;
		If (!( keyBegin < keyEnd ))
			return ;
		auto beginI = m_map.find(keyBegin);
		auto EndI = m_map.find(keyEnd - 1);
		if (beginI != m_map.begin()) {
			if (m_map[beginI - 1] == std::forward<V_forward>(val))
				return ;
		}
		auto range = std::ranges::subrange(beginI, m_map.end());
		if (endI != m_map.end())
			range = std::ranges::subrange(beginI, EndI);
		for (auto& [K, V] : range)
			m_map[K] = std::forward<V_Forward>(val);
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};
