//days.c
//Ryan McCabe
//Finished 9/19/24
//This program outputs the day of the week
//rsmccabe@mtu.edu

include <stdio.h>
int main(){
int Y,M,D,w;
int c;

//Here, I made some code that allows the user to put the date and have it be read b-y scan f
printf("Please enter the date [yyyy/mm/dd]:");
scanf("%d %d %d",&Y,&M,&D);
//HEre I had to adjust the day of the week so, I used an if staement
if(M<3){
M+=12;
Y-=1;
}

//c is the century and w is the day of the week
c=Y/100;

w=(D+13*(M+1)/5+Y/4+c/4+5*c)%7;

//I found a neet way to store the days of the week by storing them in an empty vari-able and print them
const char *days[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
printf("The day of the week is: %s\n",days[w]);
//End statement
return 0;
}
~        
