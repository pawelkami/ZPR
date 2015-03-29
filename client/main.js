var turn = "";
var player1 = { nickname: "" };
var player2 = { nickname: "PLAYER TWO" };
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
    $(".player1Text").text(player1.nickname);
    $(".player2Text").text(player2.nickname);
  }
});

$(".col").click(function(){
  if(!gameStarted)
    return;
  var row = $(this).parent().index();
  var col = $(this).index();

  if($(this).text().length === 1){
      alert("To miejsce jest juz zajete, prosze wykonac ruch gdzie indziej.");
      return;
  }

  if(turn === "player1"){
    $(this).text("O");
    turn = "player2";
    $(".player1Turn").delay(250).text("");
    $(".player2Turn").delay(250).text("X");
  } else {
    $(this).text("X");
    turn = "player1";
    $(".player1Turn").delay(250).text("O");
    $(".player2Turn").delay(250).text("");
  }

});
