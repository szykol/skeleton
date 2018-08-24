#pragma once

#include <random>

namespace sen {
	class Random
	{
	private:
		static std::mt19937 s_engine;
	public:
		int getInt(int min, int max);
		float getFloat(int min, int max);

		// for real numbers
		template<typename T>
		typename std::enable_if<std::is_floating_point<T>::value, T>::type
		get(int min, int max)
		{
			std::uniform_real_distribution<T> d(min,max);
			return d(s_engine);
		}

		// for int numbers
		template<typename T>
		typename std::enable_if<std::is_integral<T>::value, T>::type
		get(int min, int max)
		{
			std::uniform_int_distribution<T> d(min,max);
			return d(s_engine);
		}
	};
}