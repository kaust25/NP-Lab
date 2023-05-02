<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="X-UA-Compatible" content="chrome=1, IE=9">
        <meta name="viewport" content="initial-scale=1 maximum-scale=1 user-scalable=0 minimal-ui shrink-to-fit=no" />        
        <script src="https://cdn.jsdelivr.net/npm/phaser@3.15.1/dist/phaser-arcade-physics.min.js"></script>
        <script src="https://s3.amazonaws.com/stitch-sdks/js/bundles/4.6.0/stitch.js"></script>
        <script src="./game.js"></script>
    </head>
    <body style="margin: 0">
        <div style="position: absolute; background-color: green; padding: 10px; margin: 10px; color: #FFFFFF">
            <div id="visitor">
                <input id="gameid" type="text" placeholder="Game ID" onkeypress="joinOrCreateGameKeyPress(event)" />
                <button id="creategame" type="button" onclick="joinOrCreateGame()">Create / Join</button>
            </div>
            <div id="information" style="display: none">
                Game ID: 
            </div>
        </div>
        <div id="ishost" style="position: absolute; background-color: #fff; color: black; padding: 10px; bottom: 10px; right: 10px;">
            Not in a game...
        </div>
        <div id="game" style="margin: 0; padding: 0; background-color: #fff;"></div>
        <script>
            const game = new Game({
                "id": "game",
                "width": window.innerWidth,
                "height": window.innerHeight,
                "realmAppId": "application-0-tnrlk",
                "databaseName": "mongo-draws",
                "collectionName": "game"
            });

            async function joinOrCreateGame() {
                if(!document.getElementById("gameid").value || document.getElementById("gameid").value == "") {
                    return alert("The Game ID Must Not Be Empty");
                }
                try {
                    let result = await game.joinOrCreateGame(document.getElementById("gameid").value);
                    document.getElementById("ishost").innerHTML = result.authId == result.owner_id ? "You're the host!" : "You are not the host!";
                    document.getElementById("visitor").style.display = "none";
                    document.getElementById("information").innerHTML = "Game ID: " + document.getElementById("gameid").value;
                    document.getElementById("information").style.display = "block";
                } catch (e) {
                    console.error(e);
                }
            }

            function joinOrCreateGameKeyPress(event) {
                if(event.keyCode == 13) {
                    joinOrCreateGame();
                    return false;
                }
            }
        </script>
    </body>
</html>
