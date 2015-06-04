/*
 * File implements boost_python_module of C++ classes and methods which will be used in Python.
 */
#include "Game.hpp"
#include "GameList.hpp"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(cppGame)
{
	boost::python::class_<std::vector<std::string> >("StringVec")
		.def(boost::python::vector_indexing_suite<std::vector<std::string> >())
		;

	boost::python::class_<std::vector <std::vector<std::string> > >("StringMatrix")
		.def(boost::python::vector_indexing_suite<std::vector <std::vector<std::string> > >())
		;

	boost::python::class_<Move>("Move")
		.def_readwrite("x", &Move::x_)
		.def_readwrite("y", &Move::y_)
		.def_readwrite("sign", &Move::sign_)
		;

	boost::python::enum_<GameResult>("GameResult")
		.value( "STILL_PLAYING", STILL_PLAYING )
		.value( "DRAW", DRAW )
		.value( "VICTORY", VICTORY )
		;

	boost::python::class_<GameList, std::shared_ptr<GameList>, boost::noncopyable>("GameList", boost::python::no_init)
		.def( "getInstance", &GameList::getInstance )
		.staticmethod("getInstance")
		.def( "getNewID", &GameList::getNewID )
		.def( "getResult", &GameList::getResult, boost::python::args("id") )
		.def( "makeMove", &GameList::makeMove, boost::python::args("id", "x", "y") )
		.def( "resetGame", &GameList::resetGame, boost::python::args("id") )
		.def( "addPlayer", &GameList::addPlayer, boost::python::args("id", "name") )
		.def( "getOpponentsName", &GameList::getOpponentsName, boost::python::args("id") )
		.def( "getLastMove", &GameList::getLastMove, boost::python::args("id") )
		.def( "getPlayerPoints", &GameList::getPlayerPoints, boost::python::args("id") )
		.def( "getOpponentsPoints", &GameList::getOpponentsPoints, boost::python::args("id") )
		.def( "unregister", &GameList::unregister, boost::python::args("id"))
		.def( "hasOpponentLeft", &GameList::hasOpponentLeft, boost::python::args("id"))
		;
}
