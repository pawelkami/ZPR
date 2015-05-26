#include "Game.hpp"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(cppGame)
{
	boost::python::class_<std::vector <std::vector<std::string> > >("StringMatrix")
		.def(boost::python::vector_indexing_suite<std::vector <std::vector<std::string> > >())
		;

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
		.def( "resetGame", &Game::resetGame )
		;

	boost::python::def( "getPlayerName", getPlayerName );
}
