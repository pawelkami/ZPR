# -*- coding: utf-8 -*-
# this file is released under public domain and you can use without limitations

#########################################################################
## This is a sample controller
## - index is the default action of any application
## - user is required for authentication and authorization
## - download is for downloading files uploaded in the db (does streaming)
#########################################################################

from cppGame import *
import json

def index():
    return dict(
        url_move = URL('move'),
        url_reset = URL('reset'),
        url_register = URL('register'),
        url_getName = URL('getName'),
        url_getMove = URL('getMove')
    )


def user():
    """
    exposes:
    http://..../[app]/default/user/login
    http://..../[app]/default/user/logout
    http://..../[app]/default/user/register
    http://..../[app]/default/user/profile
    http://..../[app]/default/user/retrieve_password
    http://..../[app]/default/user/change_password
    http://..../[app]/default/user/manage_users (requires membership in
    use @auth.requires_login()
        @auth.requires_membership('group name')
        @auth.requires_permission('read','table name',record_id)
    to decorate functions that need access control
    """
    return dict(form=auth())


def download():
    """
    allows downloading of uploaded files
    http://..../[app]/default/download/[filename]
    """
    return response.download(request, db)


def call():
    """
    exposes services. for example:
    http://..../[app]/default/call/jsonrpc
    decorate with @services.jsonrpc the functions to expose
    supports xml, json, xmlrpc, jsonrpc, amfrpc, rss, csv
    """
    return service()

def register():
    idnum = GameList.getInstance().getNewID()
    name = str(request.post_vars.name)
    sign = GameList.getInstance().addPlayer(idnum, name)
    return json.dumps({'id' : idnum, 'sign' : sign})

def move():
    i = int(request.post_vars.x)
    j = int(request.post_vars.y)
    idnum = int(request.post_vars.id)

    GameList.getInstance().makeMove(idnum, i, j)
    status = getGameState(idnum)
    return json.dumps({'status': status})


def getName():
    idnum = int(request.post_vars.id)
    playerName = ""
    playerName = GameList.getInstance().getOpponentsName(idnum)
    return json.dumps({'playerName' : playerName})

def getMove():
    idnum = int(request.post_vars.id)
    lastMove = GameList.getInstance().getLastMove(idnum)
    status = getGameState(idnum)
    return json.dumps({'x' : lastMove.x, 'y' : lastMove.y, "sign" : lastMove.sign, "status" : status})


def getGameState(idnum):
        game_state = GameList.getInstance().getResult(idnum)
        if game_state == GameResult.VICTORY :
            return "VICTORY"
        elif game_state == GameResult.DRAW :
            return "DRAW"
        else :
            return "STILL_PLAYING"

def reset():
    GameList.getInstance().resetGame(int(request.post_vars.id))
