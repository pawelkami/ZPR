# -*- coding: utf-8 -*-

#########################################################################
## Controller of a Tic Tac Toe Game
#########################################################################

from cppGame import *
import json

## Default function which passes URLs to Python functions to index.html
#
def index():
    return dict(
        url_move = URL('move'),
        url_reset = URL('reset'),
        url_register = URL('register'),
        url_getName = URL('getName'),
        url_getMove = URL('getMove'),
        url_unregister = URL('unregister'),
        url_getWinnerPoints = URL('getWinnerPoints')
    )

## Function to register new player
#
def register():
    idnum = GameList.getInstance().getNewID()
    name = str(request.post_vars.name)
    sign = GameList.getInstance().addPlayer(idnum, name)
    return json.dumps({'id' : idnum, 'sign' : sign})


## Function to make move by a player
# @return 'status' - Game result(VICTORY, DRAW, STILL_PLAYING) and 'points' - player points or False if move wasn't made
def move():
    i = int(request.post_vars.x)
    j = int(request.post_vars.y)
    idnum = int(request.post_vars.id)

    ret = GameList.getInstance().makeMove(idnum, i, j)
    if ret == False :       # if False, move wasn't made
        return json.dumps({'status': "False"})
    else:
        status = getGameState(idnum)
        points = GameList.getInstance().getPlayerPoints(idnum)
        return json.dumps({'status': status, 'points': points})

## @return 'playerName' - opponent's name
#
def getName():
    idnum = int(request.post_vars.id)
    playerName = ""
    playerName = GameList.getInstance().getOpponentsName(idnum)
    return json.dumps({'playerName' : playerName})

## @return last move in a game
def getMove():
    idnum = int(request.post_vars.id)
    hasLeft = bool(GameList.getInstance().hasOpponentLeft(idnum))
    if(hasLeft):
        return json.dumps({ "status" : "HAS_LEFT" })
    lastMove = GameList.getInstance().getLastMove(idnum)
    status = getGameState(idnum)
    points = GameList.getInstance().getOpponentsPoints(idnum)
    return json.dumps({'x' : lastMove.x, 'y' : lastMove.y, "sign" : lastMove.sign, "status" : status, 'points' : points})

##
# @param idnum player id
# @return Game result converted to string
def getGameState(idnum):
        game_state = GameList.getInstance().getResult(idnum)
        if game_state == GameResult.VICTORY :
            return "VICTORY"
        elif game_state == GameResult.DRAW :
            return "DRAW"
        else :
            return "STILL_PLAYING"

## Method which resets game which has player with id passed by JSON
def reset():
    GameList.getInstance().resetGame(int(request.post_vars.id))

## Method to unregister Player
def unregister():
    idnum = int(request.post_vars.id)
    GameList.getInstance().unregister(idnum)

## @return Points that has resulted in a VICTORY
def getWinnerPoints():
    idnum = int(request.post_vars.id)
    struc = GameList.getInstance().getWinnerPoints(idnum)
    return json.dumps({'x1' : struc.x1, 'y1': struc.y1, 'x2' : struc.x2, 'y2': struc.y2, 'x3' : struc.x3, 'y3': struc.y3, 'x4' : struc.x4, 'y4': struc.y4, 'x5' : struc.x5, 'y5': struc.y5})
