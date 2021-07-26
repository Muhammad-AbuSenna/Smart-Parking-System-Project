# Smart-Parking-System-Project

Overview:

I wanted to implement a smart parking system that's remotely trough a Web Application check and indicate the availability of a parking slots within a garage from wherever you are. There were a various ideas to implement such a system, but each one have it’s weaknesses from cost issues to environment issues. So, I decided to use the most suitable way from my point of view.

The idea was to use a sharp IR sensor which senses the object existence if it cuts it's IR lines. sensor is held in the middle of a car slot, so whenever the car covers the slot the sensor will sense it’s existence.


Purposes & Business needs:

In big institutions like Malls, campuses, companies and even public garages such a system will bring more order to it. A client or employee would come knowing where he can park his car saving his time.


System Components:

1. Sharp IR sensor:
 
which will sense the car existence.

Advantages: 

-	Suitable for environment factors.

-	Its sensing range is 150cm which will sense any car of any height.

-	Precise and works in real-time.


2. Microcontroller: 

which will take the sensor readings and send them to a webserver. In my case I have chosen ESP32 microcontroller.

Advantages:

-	It comes with an integrated Wi-Fi module that can connect to the internet and send data to the webserver.

-	Its processing power is great and works in real-time.

-	Ultra power saving.





Implementation: 

System consists of two parts:

1.System prototype: 

That’s the IR sensor and the microcontroller. First, the IR sensor will be held in the middle of the car slot beneath the car, when a car covers the slot it will generate a voltage value corresponds to the car height, the voltage value is then sent to the microcontroller pin which the sensor is attached to.
Then the Esp32 process this value and convert it to a logical 1 or 0 where, 1 stands for the parking slot is occupied with a car and 0 stands for the slot is empty. The esp32 then sends those values to the webserver. 

In my case I used the esp32 as a station, that’s were it will operate as local webserver. So, the Esp32 will handle the client requests. Esp32 will  connect to the Wi-Fi and take an IP, when the user types the IP of the server a request will be sent to the Esp32 then it will respond with the web Application page.

For more accuracy: you can use 2 sensors per a slot (one at the beginning of the slot and other at the end ), to avoid animals or other objects interaction, that’s when both slots are covered that’s indicates for sure that the thing covering the slot is a car. But, that wasn’t necessary for my prototype.

Esp32 is programmed using Arduino IDE.

Note: please Check the media branch in the repository to see a picture of the system prototype.

2. Web Application:
 
My web page consists of 6 boxes elements, each represent a car slot that will be colored with green indicating that the slot is empty. When a car covers the slot it will be colored with red indicating that the slot is occupied.

I added a feature that the user can reserve a slot until he comes, of course I added an option that he can cancel the reservation.

The technologies used to develop this web application is:

-	HTML

-	CSS

-	JavaScript

-	Ajax 

Of course HTML and CSS will build the body of the page, JavaScript will act upon the values that comes in a respond from the Esp32 that will change the car value to the red if the received value is 1 and if it’s 0 it will remain green.

Ajax is used to handle server-client communication. It will frequently send a request for IR values in the backend, which will make the slots status reliable and  updated frequently without reloading the page.

When a slot is hovered, option for reservation appears. on clicking, a request will be sent to the Esp32 that will reserve the clicked slot.

Reservation is done by covering the slot, in my case I used a servo motor that will move to cover the sensor upon a reservation request from the user. Of course it will move out upon request for cancellation.


System cost:

The system is very low cost, the sensor is less than 5$, Esp32 is also costs like 6$ (of course u can use other microcontroller).


Possible future updates: 

A lot more features can be added to the system. For example:

-	Every kind of a car has its height, so you can store those heights in database, measure the height of the car by the sensor (sharp IR sensor is very precise with distances), compare it with the database, and then determine the kind of the car.

-	Improve the security and make the reservation eligible for only certain people. (The web application is not much good from a security POV).

-	If you were to use the system in a public garage you can add a timer that counts the time the car have spent parking and then calculate the cost.


Note: Check other branches in this repository for source code and video of the system working.

