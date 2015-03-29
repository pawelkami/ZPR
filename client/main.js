var turn = "";

function new_game(){
  $(".col").map(function() {
    $(this).text("")
  });
}

$(".col").click(function(){
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
