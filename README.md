# mini-shell-racoon
[![wakatime](https://wakatime.com/badge/user/7bb37e6a-4017-4391-ba87-85da4d9ae1ef/project/da9e4fd5-8ed3-4d95-a2f1-d2eea6781f15.svg)](https://wakatime.com/badge/user/7bb37e6a-4017-4391-ba87-85da4d9ae1ef/project/da9e4fd5-8ed3-4d95-a2f1-d2eea6781f15)

this project impliment the minimal parts of a shell such

-> moving in out directory
-> evaluting user input such as -> "$USER" -> jemartel
-> executing  local command   such as  ./minishell
-> executing  absolute command such as /bin/sh
-> executing  command without saying the path
-> redirecting input with "input rediction" with the symbol "<"
-> redirecting output with "input rediction" with the symbol ">"
-> redirecting output and adding to the  end with "append rediction" with the symbol ">>"
-> redirecting input with "input 'here-redicetion' " with the symbol "<<"
-> the shell command of (env,export,echo,exit,cd)
-> return value of the lass process passed down the execution from subprocess
-> piping elements from one command to the other "ls | wc | wc" 
--------------------------------------------------------------
the program is structured ->
parsing: "creates tokens from the base string tha come from readline"
then if an error occcure a this stage it will prompt an error and display the display it to screens 
the tokens are place in a doubly linklist "(yes its not a tree)"
each token in a the list will be typed "its a number"  according to  previous assumpitons

jobs: a doubly linklist that is create from  the previous list;
each jobs as fews composents: such as the arguments for a command if there is a commands 
if there redirecton ther will be an list:(a doubly link list) 
if there a error somewhere everything before will be deleted

evalution: each string passed down the pipeline will be converted 
to what it should be  element prefixed with with a $  in and out of a
string will be 'expanded' otherwise the value with the $ before stay the same without the '
the 'quoting can be nested the first seen do the behavior'
the evalution part of the program is self standing and can be use in any 
other project with minimal  change

execution: at this stage the program will  try to do rediction < > >> but not << since its
done 'in evalution part' any errror will bail an early exit and not execute anything
last part is trying to see if  the arguments is an executable or otherwise
EVERYTHING tha is not  readline in a subprocess will be deleted in an errors or not
---------------------------------------------------------------
