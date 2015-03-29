var turn = "";
var player1 = { nickname: "" };
var player2 = { nickname: "PLAYER TWO" };
var gameStarted = false;

$(".player1Turn").text("O");  // pierwszemu graczowi przypisujemy kolko
$(".player2Turn").text("X");  // drugiemu graczowi przypisujemy krzyzyk

function new_game(){
  $(".col").map(function() {
    $(this).text("");
  });
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
    $('#nickname-form').delay(150).fadeOut(400);
    gameStarted = true;
    turn = "player1";
    $(".player1Text").text(player1.nickname);
    $(".player2Text").text(player2.nickname);
    $(".player1Turn").fadeIn(200);
    $(".player2Turn").fadeOut(200);
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
    $(".player1Turn").fadeOut(200);
    $(".player2Turn").fadeIn(200);
  } else {
    $(this).text("X");
    turn = "player1";
    $(".player1Turn").fadeIn(200);
    $(".player2Turn").fadeOut(200);
  }

});
