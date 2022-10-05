# Find_Domain_Zones
Find Domain Zones (FDZ) - is the easy linux console utility for searching all used domain zones for domain name. 
For using this utility please write in console `./fdz <name>`. 
Where `<name>` is domain name without the zone.  
Example: `./fdz mobileread`
 
 
 ![CH341A programmer device](https://github.com/bigbigmdm/Find_Domain_Zones/raw/main/fdz_example.png) 


For use this utility need compiling the cource code. 
For compile this utility download the file `fdz.cpp` and write in terminal: `gcc fdz.cpp -o fdz`. 

If you want to make this file a linux command, please copy the executable `fdz` into `/usr/local/bin` directory. 
When it is copied, you will be able to write in the terminal `fdz <name>` without `./` in any directory.
