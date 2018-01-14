#include "models/Game.hpp"

int main() {
	try {
		sff::game::Game::get_instance().run();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
