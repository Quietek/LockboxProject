# LockboxProject
Title:  A Compartmentalized Lockbox

Who: 	Harrison Snook,
	Tanner Tracy,
	Dale Blomgren,
	Dmitriy Tarasov

Description:
	Software for a basic lockbox with multiple compartments and a 10-digit numpad, coded for use with an Arduino, with basic network functionality for failsafe purposes.

Vision Statement:
	"A simple, safe, and interactive compartmentalized lockbox"	

Motivation:
	Keeping track of small things such as keys for many different people can often be a major hassle for a party host or businesses. An easy example of this is keys, where people will often bring their keys to a party but quickly forget where they put them. This device can be used to make sure keys aren't stolen, while you also don't have to keep them on your person at all times.

Risks:
	-Little experience with Arduinos in the past
	-Little large time management experience
	-Possibility of overcomplification of a simple idea
	-Final product changes from prototyple with worse applicable usage due to last minute changes.
	-Aesthetically displeasing

Risk Mitigation:
	-Look at tutorials and build an understanding of Arduino software and functionality
	-Use checkpoints and use project management software to keep people on track and on topic
	-Don't go out of original scope of project (e.g. don't change the functionality of the product halfway through development)
	-Spend time in CAD to keep lock mechanisms and box itself looking pleasing, re-3d print as necessary.

Requirements:

Requirement Type | Requirement	| ID	| Story Points	|	
---------------- | --------------------------------------------------------------------------------- | ----- | ------------- |
User		 | As a User, I want to have a locking box to prevent my keys from being stolen | 1 | 1 | 
User		 | As a User, I want the box to inform me if its been compromised(unusual open) | 2 | 3 |
Administrator	 | As an Admin, I want a master passsword to open the box | 3 | 2 | 
Administrator	 | As an Admin, I want the master key to be sent though a network. | 4 | 4 |
Administrator    | As an Admin, I want to see what boxes are locked/unlocked | 5 | 1 | 
User             | As a User, I want to create and use my own password | 6 | 3|
User             | As a User, I want a UI to interact with | 7 | 6 |

Methodology:
Agile

Project Tracking Software:
Trello
https://trello.com/lockbox1

Project Status: Beta

Repository Organization:
	- OldCode folder to store past pushes to the repository.
	- Current files are found in the root directory of the repository.

Important files:
	- keypadwithchangepassword.ino: Our base logic that the Arduino uses for the lockbox.
	- base_surface.STL and Doors1final.STL: CAD representation of the lockbox.
	- README.md: Important documentation and instructions on using the lockbox.

Implementing keypadwithchangepassword.ino:
	- First download keypadwithchangepassword.ino from repo and arduino development software.
	- After setting up arduino development software, plug in arduino to your local machine.
	- In arduino suite, find tools > port, and then select usb port that your arduino is currently connected to
	- Go to sketch > Include Library > Manage Libraries.  Search Keypad.  Click and say "Install"
	- There is an upload button on the top of the ide.  Upload, and test!


