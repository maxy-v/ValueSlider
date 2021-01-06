#pragma once
#include <cstddef>
#include <vector>
#include <limits>

template<
	typename T,
	size_t DefaultScaleIndex = std::numeric_limits<size_t>::max()
>
class ValueSlider
{
	static_assert(DefaultScaleIndex >= 0);
public:
	template <typename... Args>
	ValueSlider(Args... Values)
		: m_data{Values...}
	{
		constexpr size_t values_count = sizeof...(Values);
		constexpr size_t default_index = DefaultScaleIndex == std::numeric_limits<size_t>::max()
			? values_count/2
			: DefaultScaleIndex;
		static_assert(default_index  >= 0           , "Array index is too small");
		static_assert(default_index  <  values_count, "Array index is too big");
		m_index = default_index;
	}

	bool prev()
	{
		if (m_index == 0)
			return false;
		m_index--;
		return true;
	}

	bool next()
	{
		if (m_index == m_data.size()-1)
			return false;
		m_index++;
		return true;
	}

	const T& value() const
	{
		return m_data[m_index];
	}

private:
	size_t m_index;
	std::vector<T> m_data;
};