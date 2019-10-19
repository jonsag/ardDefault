# ardDefault
Some startups for arduino sketches

Serial communication via cli
==========

Setup communication  
>$ stty -F <device> cs8 <baud rate> ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts
	
eg.  
>$ stty -F /dev/ttyUSB0 cs8 9600 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts
	
Then you can do  
>$ echo "Hello Arduino" > /dev/ttyUSB0

to send the string (followed by a newline) to your Arduino  

You can also do  
>$ tail -f /dev/ttyUSB0

to read what your Arduino has to tell you  

If the above doesn't work, try  
>$ cat < /dev/ttyUSB0

Using busybox to provide an interactive session with Arduino
==========

Install busybox  
>$ apt install busybox

Use microcom to make an interactive session
>$ busybox microcom -t <baud rate> <device>
	
eg.  
>$ busybox microcom -t 9600 /dev/ttyUSB0
	
Using screen
==========
>$ stty -F /dev/ttyACM0 ispeed 9600 ospeed 9600 -ignpar cs8 -cstopb -echo  

Connect to arduino with screen:  
>$ screen /dev/ttyACM0 9600 -S <session name>  

To get screen command promp, enter  
> [ctrl+a] :  

Then type  
>quit  

and
>[Return]  

or from outside of screen  
>$ screen -X -S <session name> quit  

Kill screen with  
>^ak

or 
>[ctrl+a] k

	
	