// zapisuje imię gracza na serwerze i zwraca mu jego id oraz znak
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

new_game = function() {
  $(".col").map(function() {
    $(this).text("");
  });
  $.ajax({
    type: "POST",
    data: {id: player1.id},
    url: urlReset,
    async: false
  });
};

getOpponentsName = function() {
  $.ajax({
    type: "POST",
    url: urlGetName,
    data: {id: player1.id},
    success: function( out_data ) {
      out_data = $.parseJSON(out_data);

      if(out_data.x === -1 || out_data.y === -1){ // jesli zaczynamy nowa gre to przy pobraniu poczatkowych wartosci jeszcze raz pobierz
        setTimeout(getOpponentsName, 2000);
      }

      if( out_data.playerName === "" ){
        setTimeout(getOpponentsName, 2000);
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
      setTimeout(getOpponentsName, 2000);
    }
  });
};

getOpponentsMove = function() {
  $.ajax({
    type: "POST",
    data: {id: player1.id},
    url: urlGetMove,
    success: function( out_data ) {
      out_data = $.parseJSON(out_data);
      if(out_data.status === "HAS_LEFT")
        alert("Przeciwnik opóścił grę"); // tymczasowe
      else if(out_data.sign === player2.sign) {
        $("#game").children().each(function() {

          if($(this).index() === out_data.y)
          $(this).children().each(function() {
            if($(this).index() === out_data.x)
            $(this).text(player2.sign);
          });
        });

        setStatus( out_data, player2 );   //ustawia okienko wygranej jesli taka nastapi

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

unregister = function() {
  $.ajax({
    type: "POST",
    async: false,
    data: { id: player1.id },
    url: urlUnregister
  });
}
