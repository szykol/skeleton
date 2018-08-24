#include "Random.h"

namespace sen {
	std::mt19937 Random::s_engine(std::random_device{}());
}