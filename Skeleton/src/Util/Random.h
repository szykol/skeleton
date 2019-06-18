#pragma once

#include <random>

namespace sen
{
/** 
 * @brief  Basic random number generator
 */
class Random
{
  private:
	static std::mt19937 s_engine;

  public:
	/** 
	 * @brief  Function that returns a value between 
	 * min and max(inclusive for integer types, exclusive for
	 * floating point types) values
	 * @param  min: minimal value
	 * @param  max: maximal value
	 * @retval random number
	 */
	template <typename T>
	static typename std::enable_if<std::is_floating_point<T>::value, T>::type
	get(T min, T max)
	{
		std::uniform_real_distribution<T> d(min, max);
		return d(s_engine);
	}

	template <typename T>
	static typename std::enable_if<std::is_integral<T>::value, T>::type
	get(T min, T max)
	{
		std::uniform_int_distribution<T> d(min, max);
		return d(s_engine);
	}
};

}