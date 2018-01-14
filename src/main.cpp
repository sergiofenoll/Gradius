#include "utils/Game.hpp"

int main() {
	try {
		sff::utils::Game::get_instance().run();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
