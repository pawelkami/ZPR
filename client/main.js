var turn = "";
var player1 = { nickname: "" };
var player2 = { nickname: "" };
var gameStarted = false;

function new_game(){
  $(".col").map(function() {
    $(this).text("");
  });
}

$("#start-button").click(function() {
  if($("#nickname-textbox").val().length < 1)
    alert("Podaj swoje imie");
  else {
    player1.nickname = ($("#nickname-textbox")).val();
    $('#nickname-form').delay(150).fadeOut(400);
    gameStarted = true;
  }
});

$(".col").click(function(){
  if(!gameStarted)
    return;
  var row = $(this).parent().index();
  var col = $(this).index();

  if($(this).text().length == 1){
      alert("To miejsce jest juz zajete, prosze wykonac ruch gdzie indziej.");
      return;
  }

  if(turn === "player1"){
    $(this).text("O");
    turn = "player2";
  } else {
    $(this).text("X");
    turn = "player1";
  }

});
