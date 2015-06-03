var turn = "O";
var player1 = { nickname: "", sign: "", id: -1 };
var player2 = { nickname: "", sign: "" };
var gameStarted = false;
var status = "";

$('#game-result-form').hide();

for(var i = 0; i < 16; ++i) {
  $( "#game" ).append("<div class = 'row'></div>");
}
for(var i = 0; i < 16; ++i)
{
  $(".row").append("<div class = 'col'></div>");
}


//wciśnięcie entera po wprowadzeniu nazwy gracza, powinno dac sam efekt co klikniecie "start"
//(nie liczac tego, ze przycisk nie zmienia swojego wygladu na "klikniety" - da sie to obejsc,
//ale to drobnostka, ktora nie chce na razie zabrudzac kodu)
$("#nickname-textbox").keyup(function (e) {
  if (e.keyCode == 13) {
    $("#start-button").trigger("click");
  }
});

$("#start-button").click(function() {
  if($("#nickname-textbox").val().length < 1)
  alert("Podaj swoje imie");
  else {
    player1.nickname = ($("#nickname-textbox")).val();
    $(".player1Text").text(player1.nickname);


    registerPlayer();
    startWaitingAnimation();
    getOpponentsName();
    $('#nickname-form').delay(150).fadeOut(400);

    $('.player1Points').text("0");
    $('.player2Points').text("0");
    $(".player1Turn").text(player1.sign);
    $(".player2Turn").text(player2.sign);


    if(turn === player2.sign){
      getOpponentsMove();
    }
  }
});

$(".col").click(function(){
  if(!gameStarted || turn !== player1.sign){
    return;
  }
  var row = $(this).parent().index();
  var col = $(this).index();

  if($(this).text().length === 1){
    alert("To miejsce jest juz zajete, prosze wykonac ruch gdzie indziej.");
    return;
  }

  var ret = postMove(row,col);

  if(ret !== "False"){
    $(this).text(player1.sign);
    turn = player2.sign;
    if( ret === "STILL_PLAYING"){
      getOpponentsMove();
    }
  }
});

$("#new-game-button").click(function() {
  $('#game-result-form').hide();
  new_game();
  turn = "O";
  if(player1.sign === "X"){
    $(".player1Turn").fadeTo(200, 0);
    $(".player2Turn").fadeTo(200, 1);
    getOpponentsMove();
  } else {
    $(".player1Turn").fadeTo(200, 1);
    $(".player2Turn").fadeTo(200, 0);
  }

});

var timer;

startWaitingAnimation = function() {
  $(".player2Text").text("Searching player");
  $(".player2Text").fadeTo(500, 0).delay(500).fadeTo(500, 1);
  timer = setInterval(function() {
    $(".player2Text").fadeTo(500, 0).delay(500).fadeTo(500, 1);
  }, 2000);
}

stopWaitingAnimation = function() {
  clearInterval(timer);
  $(".player2Text").stop().fadeTo(0, 1).text(player2.nickname);
}

setStatus = function(out_data, player) {  // funkcja ustawia okienko statusu gry, wlacza sie gdy jest wygrana lub remis
  if( out_data.status === "VICTORY" ){
    $('#result-text').text(player.nickname + " WIN");
    $('#game-result-form').fadeTo(200, 0.9);
    if(player.sign === player1.sign){
      $('.player1Points').text(out_data.points);
    } else {
      $('.player2Points').text(out_data.points);
    }
  } else if( status === "DRAW" ) {
    $('#result-text').text("DRAW");
    $('#game-result-form').fadeTo(200, 0.9);
  } else {
    $(".player1Turn").fadeTo(200, 0);
    $(".player2Turn").fadeTo(200, 1);
  }
}
