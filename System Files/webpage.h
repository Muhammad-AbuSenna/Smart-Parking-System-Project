//============
//Webpage Code
//============
String webpageCode = R"***(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
  <!-- <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/normalize.css"> -->
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Open+Sans:ital,wght@0,300;0,700;1,300&display=swap">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Akaya+Kanadaka&display=swap">
    <style>
body{
    font-family: 'Akaya Kanadaka', cursive;
    background-color: #000
}

<!-- Start landing-page -->
.landing-page{
    min-height: 100vh;
    background-image: url(asphalt.jpg);
    background-size: cover;
    position: relative;
}

/*.landing-page .overlay {
    background-color: rgb(0 0 1 / 42%);
    position: absolute;
    width: 100%;
    height: 100%;
    left: 0;
    top: 0;
    z-index: 1;
}*/

/*.intro-text {
    color: #fff;
}*/

.header-area {
    position: sticky;
    top: 0;
    z-index: 3;
    color: #fff;
    display: flex;
}

.header-area .logo {
    width: 300px;
    padding: 15px;
    font-weight: bolder;
    font-size: 25px;
}
.header-area .logo:hover {
    color: rgb(15, 230, 15);
    cursor: pointer;
}

.header-area .links {
    list-style: none;
    width: 100%;
    text-align: right;
    padding-left: 0;
    padding-right: 20px;
    font-weight: bold;
}

.header-area .links li {
    display: inline-block;
    margin-left: 50px;
}

.header-area .links li:hover {
    color: rgb(15, 230, 15);
    cursor: pointer;
}
/* Ending landing-page */

/* Start parkin-layout */

.parking-layout {
    width: 50%;
    display: flex;
    flex-wrap: wrap;
    margin: auto;
    margin-top: 50px;
    padding: 20px;
    position: relative;
    z-index: 2;
}

.slot {
    width: calc( 80% / 3 );
    height: 230px;
    display: flex;
    border-style: solid;
    margin: auto;
    margin-bottom: 50px;
    justify-content: space-between;
    justify-content: center;
    align-items: center;
    /* margin-left: 10px;
    margin-right: 10px; */
    border: 2px solid rgb(15, 230, 15);
    border-radius: 20px;
    border-width: 5px;
    color: #fff;
}
.slot:hover {
    border: 4px solid rgb(255, 238, 2);
    font-size: 0px;
}

.slot:hover:after {
    content: attr(hover-content);
    font-size: 24px;
    color: rgb(2, 238, 128);
    cursor: pointer;
}

.slotUpdated {
    width: calc( 80% / 3 );
    height: 230px;
    display: flex;
    border-style: solid;
    margin: auto;
    margin-bottom: 50px;
    justify-content: space-between;
    justify-content: center;
    align-items: center;
    /* margin-left: 10px;
    margin-right: 10px; */
    border: 2px solid rgb(230, 40, 15);
    border-radius: 20px;
    border-width: 5px;
    color: #fff;
}

.butn{
    display:none;
    padding:0.3em 1.2em;
    margin:0 0.1em 0.1em 0;
    border:0.16em solid rgba(2, 238, 128, 0);
    border-radius:2em;
    box-sizing: border-box;
    text-decoration:none;
    font-weight:800;
    color:#FFF;
    text-shadow: 0 0.04em 0.04em rgba(0, 0, 0, 0.384);
    text-align:center;
    transition: all 0.2s;
    background-color: rgb(15, 230, 15);
    cursor: pointer;
}
/* Ending parking-layout */
</style>
</head>



<body id = "page-body">
    <!-- Strarting Page -->

    <div class="landing-page">
       <!-- <div class="overlay"></div> -->
        <div class="header-area">
            <div class="logo">Parking Garage</div>
            <ul class="links">
                <li>HOME</li>
                <li>SERVRCIES</li>
                <li>CONTACT</li>
                <li>PARKE</li>
            </ul>
        </div>
    
        <!-- <div class="intro-text">
            <h1>Parking Area</h1>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
         </div> -->

       <!-- Strarting parking design -->

        <div class="parking-layout">
            <div class="slot" id="slot1" hover-content="RESERVE" onclick="reserve();">
                <span>SLOT 1</span>
            </div>
            <div class="slot" id="slot2" hover-content="RESERVE" onclick="reserve();">SLOT 2</div>
            <div class="slot" id="slot3" hover-content="RESERVE" onclick="reserve();">SLOT 3</div>
            <div class="slot" id="slot4" hover-content="RESERVE" onclick="reserve();">SLOT 4</div>
            <div class="slot" id="slot5" hover-content="RESERVE" onclick="reserve();">SLOT 5</div>
            <div class="slot" id="slot6" hover-content="RESERVE" onclick="reserve();">SLOT 6</div>
        </div>

   <!-- Ending parking design -->
        
    </div>
    
   <button class ='butn' id = 'btn' onclick="unReserve();">UNDO RESERVATION</button>
   <!-- Ending Page -->

  <script>

    var myBtn1 = document.getElementById('btn');
    function reserve(){
      var reserveRequest = new XMLHttpRequest();
       reserveRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          
          console.log(this.responseText);
          myBtn1.style.display = 'block';
        }
      }  
      reserveRequest.open("GET", "reservSlot", true);
      reserveRequest.send();
    }

     function unReserve(){
      var unreserveRequest = new XMLHttpRequest();
       unreserveRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          console.log(this.responseText);
          myBtn1.style.display = 'none';
        }
      }  
      unreserveRequest.open("GET", "unreservSlot", true);
      unreserveRequest.send();
    }
    
    setInterval(function()
    {
      getIRval();
    }, 100);

    function getIRval()
    {
      var IRvalRequest = new XMLHttpRequest();
      IRvalRequest.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          
          IRvalue = this.responseText;
          console.log(IRvalue);
          var mySlot1 = document.getElementById('slot1');
          var mySlot2 = document.getElementById('slot2');
          var mySlot3 = document.getElementById('slot3');
          var mySlot4 = document.getElementById('slot4');
          var mySlot5 = document.getElementById('slot5');
          var mySlot6 = document.getElementById('slot6');

          if (IRvalue.charAt(0) == 'T' ){
                mySlot1.className = 'slotUpdated';
                mySlot1.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(0) == 'F'){
                mySlot1.className = 'slot' ;
                mySlot1.innerHTML = "SLOT 1";
          }
          

          if (IRvalue.charAt(1) == 'T' ){
                mySlot2.className = 'slotUpdated';
                mySlot2.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(1) == 'F'){
                mySlot2.className = 'slot' ;
                mySlot2.innerHTML = "SLOT 2";
          }
          
          
          if (IRvalue.charAt(2) == 'T' ){
                mySlot3.className = 'slotUpdated';
                mySlot3.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(2) == 'F'){
                mySlot3.className = 'slot' ;
                mySlot3.innerHTML = "SLOT 3";
          }

          
          if (IRvalue.charAt(3) == 'T' ){
                mySlot4.className = 'slotUpdated';
                mySlot4.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(3) == 'F'){
                mySlot4.className = 'slot' ;
                mySlot4.innerHTML = "SLOT 4";
          }

          if (IRvalue.charAt(4) == 'T' ){
                mySlot5.className = 'slotUpdated';
                mySlot5.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(4) == 'F'){
                mySlot5.className = 'slot' ;
                mySlot5.innerHTML = "SLOT 5";
          }

          if (IRvalue.charAt(5) == 'T' ){
                mySlot6.className = 'slotUpdated';
                mySlot6.innerHTML = "TAKEN";
          }else if (IRvalue.charAt(5) == 'F'){
                mySlot6.className = 'slot' ;
                mySlot6.innerHTML = "SLOT 6";
          }
          
        }
      };
      IRvalRequest.open("GET", "readIR", true);
      IRvalRequest.send();
    }
  </script>
</body>
</html>
)***";
