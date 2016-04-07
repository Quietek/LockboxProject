Who: Dale Blomgren, Harrison Snook, Dmitriy Tarasov, Tanner Tracy

Title: LockboxProject

Vision: A simple, safe, and interactive compartmentalized lockbox


Automated Tests: We coded it for specific key values to see if it is properly changing passwords and properly comparing passwords with feedback from a LED response.

Screenshot1: ![Screenshot1](https://github.com/Quietek/LockboxProject/blob/master/IMG1.jpg)
Screenshot2: ![Screenshot2](https://github.com/Quietek/LockboxProject/blob/master/IMG2.jpg)


User Acceptance Tests:

1:Assuming the lockbox device was recently reset (Power was lost and then returned), input the password 1, 2, 3, 4, if the green light flashes and the device opens, the device is working properly, if not, make sure the device itself actually lost power or is brand new, if this is still the case, please report this malfunction to the customer service team.

2:Input a # character and then the correct password as normal(If the device is brand new or recently lost power, this is 1, 2, 3, 4 by default), the device should flash both the red and green light after opening the compartment, input a new 4-character password that will now be the correct password for the device, after this, the device should close, input the same password you just set, and the device should open and the green light should flash.

3:Input an incorrect password, if the red light flashes, but nothing else happens, the device is working properly.



