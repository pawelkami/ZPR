/**
 * Saves player name on the server and gets his sign
 */
registerPlayer = function() {
  $.ajax({
    type: "POST",
    async: false,
    data: {name: player1.nickname},
    url: urlRegister,
    success: function( out_data ) {
      out_data = $.parseJSON(out_data);
      player1.id = out_data.id;
      player1.sign = out_data.sign;
      if(out_data.sign === "O") {
        player2.sign = "X";
      } else {
        player2.sign = "O";
      }
    }
  });
};

/**
 * Sets signal to the server to reset the game
 */
new_game = function() {
  $(".col").map(function() {
    $(this).text("");
    $(this).css({"color" : "white"});
  });
  $.ajax({
    type: "POST",
    data: {id: player1.id},
    url: urlReset,
    async: false
  });
};

/**
 * Calls the server to get opponents name every 2 seconds.
 */
getOpponentsName = function() {
  startWaitingAnimation();
  var ajaxCall = function() {
    $.ajax({
      type: "POST",
      url: urlGetName,
      data: {id: player1.id},
      success: function( out_data ) {
        out_data = $.parseJSON(out_data);

        if(out_data.x === -1 || out_data.y === -1){
          setTimeout(ajaxCall, 2000);
        }

        if( out_data.playerName === "" ){
          setTimeout(ajaxCall, 2000);
        } else {
          player2.nickname = out_data.playerName;
          stopWaitingAnimation();
          gameStarted = true;
          if(player1.sign !== turn)
          $(".player1Turn").fadeTo(200, 0);
          else
          $(".player2Turn").fadeTo(200, 0);
        }
      },
      error: function(){
        setTimeout(ajaxCall, 2000);
      }
    });
  }
  ajaxCall();
};

/**
 * Calls the server to get opponents move every 2 seconds.
 */
getOpponentsMove = function() {
  $.ajax({
    type: "POST",
    data: {id: player1.id},
    url: urlGetMove,
    success: function( out_data ) {
      out_data = $.parseJSON(out_data);
      if(out_data.status === "HAS_LEFT"){

        unregisterPlayer();
        showGameLeftForm();
      }
      else if(out_data.sign === player2.sign) {
        $("#game").children().each(function() {

          if($(this).index() === out_data.y)
            $(this).children().each(function() {
              if($(this).index() === out_data.x)
                $(this).text(player2.sign);
          });
        });

        setStatus( out_data, player2 );

        if( out_data.status === "STILL_PLAYING" ){
          turn = player1.sign;
          $(".player1Turn").fadeTo(200, 1);
          $(".player2Turn").fadeTo(200, 0);
        }
      }
      else setTimeout(getOpponentsMove, 2000);
    },
    error: function() {
      setTimeout(getOpponentsMove, 2000);
    }
  });
}

/**
 * Sends to the server the coordinates of players click.
 */
postMove = function(row, col) {
  var output = "";
  $.ajax({
    type: "POST",
    async: false,
    data: {x: col, y: row, id: player1.id},
    url: urlMove
  }).done(function( out_data ){
    out_data = $.parseJSON(out_data);
    output = out_data.status;

    if(out_data.status === "False"){
      return;
    }
    setStatus( out_data, player1);
  });
  return output;
}

/**
 * Sends information to the server that the player is leaving.
 */
unregisterPlayer = function() {
  $.ajax({
    type: "POST",
    async: false,
    data: { id: player1.id },
    url: urlUnregister
  });
  player1.sign = "";
  player1.id = -1;
}

/**
 * Gets the combination of fields that won the game.
 */
getWinnerPoints = function(){
  $.ajax({
  type: "POST",
    data: {id: player1.id},
    url: urlGetWinnerPoints,
    success: function( out_data ) {
      out_data = $.parseJSON(out_data);
      var tab = [ out_data.x1, out_data.y1, out_data.x2, out_data.y2, out_data.x3, out_data.y3,
                out_data.x4, out_data.y4, out_data.x5, out_data.y5 ];
      for( var i = 0; i < 10; i+=2 ){
        $("#game").children().each(function() {
          if($(this).index() === tab[i+1])
            $(this).children().each(function() {
            if($(this).index() === tab[i])
              $(this).css('color', 'red');
            });
        });
      }
    },
  });
}
