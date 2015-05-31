var turn = "O";
var player1 = { nickname: "", sign: ""};
var player2 = { nickname: "", sign: ""};
var gameStarted = false;
var status = "";

$(".player1Turn").text(player1.sign);  // pierwszemu graczowi przypisujemy kolko
$(".player2Turn").text(player2.sign);  // drugiemu graczowi przypisujemy krzyzyk


//wciśnięcie entera po wprowadzeniu nazwy gracza, powinno dac sam efekt co klikniecie "start"
//(nie liczac tego, ze przycisk nie zmienia swojego wygladu na "klikniety" - da sie to obejsc,
//ale to drobnostka, ktora nie chce na razie zabrudzac kodu)
$("#nickname-textbox").keyup(function (e) {
  if (e.keyCode == 13) {
    $("#start-button").trigger("click");
  }
});

getPlayerID = function() {
  $.ajax({
    type: "GET",
    url: "http://" + window.location.host + "/controller/getid.py",
    success: function(data) {
      //dodaje id do zmiennej player1, ale nie wiem czy nie lepiej uzyc ciasteczek
      player1.id = data;
    }
  });
}

postMove = function(row, col) {
  $.ajax({
    type: "POST",
    data: {x: col, y: row, id: player1.id},
    url: "http://" + window.location.host + "/controller/move.py",
  });
}


callAjaxGet = function(destination, outputDestination) {
  $.ajax({
    type: "GET",
    dataType: "text",
    cache: false,
    url: destination,
    success: function(data) {
      $(outputDestination).replaceWith(data);
    }
  });
}

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
