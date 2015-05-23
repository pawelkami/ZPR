#include "Game.hpp"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(cppGame)
{
	boost::python::enum_<GameResult>("GameResult")
		.value( "STILL_PLAYING", STILL_PLAYING )
		.value( "DRAW", DRAW )
		.value( "VICTORY", VICTORY )
		;

	boost::python::class_<Game, std::shared_ptr<Game>, boost::noncopyable>("Game", boost::python::no_init)
		.def( "getInstance", &Game::getInstance )
		.staticmethod("getInstance")
		.def( "condition", &Game::condition )
		.def( "get_point", &Game::get_point )
		.def( "getBoard", &Game::getBoard )
		;

	boost::python::def( "getPlayerName", getPlayerName );
}
