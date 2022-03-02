#pragma once

template <class T1, class T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(const T1& first, const T2& second)
		: m_first(first),
		m_second(second)
	{

	}

	T1& first()
	{
		return m_first;
	}

	const T1& first() const
	{
		return m_first;
	}

	T2& second()
	{
		return m_second;
	}

	const T2& second() const
	{
		return m_second;
	}
};
