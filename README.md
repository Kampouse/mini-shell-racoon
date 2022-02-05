# mini-shell-racoon
[![wakatime](https://wakatime.com/badge/user/7bb37e6a-4017-4391-ba87-85da4d9ae1ef/project/da9e4fd5-8ed3-4d95-a2f1-d2eea6781f15.svg)](https://wakatime.com/badge/user/7bb37e6a-4017-4391-ba87-85da4d9ae1ef/project/da9e4fd5-8ed3-4d95-a2f1-d2eea6781f15)

- work on linux and macos: \
 install: make install

<details>
 <summary markdown="span">   this project impliment the minimal parts of a shell </summary> 
 
---
  
-  moving in out directory  
- evaluting user input such as -> "$USER" -> jemartel 
- executing  local command   such as  ./minishell  
- executing  absolute command such as /bin/sh  
- executing  command without saying the path 
  
- redirecting input with "input rediction" with the symbol "<" 
- redirecting output with "input rediction" with the symbol ">"  
- redirecting output and adding to the  end with "append rediction" with the symbol ">>"  
- redirecting input with "input 'here-redicetion' " with the symbol "<<" 
- the shell command of (env,export,echo,exit,cd)  
- return value of the lass process passed down the execution from subprocess   
- piping elements from one command to the other "ls | wc | wc" 
    
</details>
<details>
  <summary markdown="span">Program structure</summary>
 
 
---
- parsing: "creates tokens from the base string tha come from readline"
then if an error occcure a this stage it will prompt an error and display the display it to screens 
the tokens are place in a doubly linklist "(yes its not a tree)"
each token in a the list will be typed "its a number"  according to  previous assumpitons

- jobs: a doubly linklist that is create from  the previous list;
each jobs as fews composents: such as the arguments for a command if there is a commands 
if there redirecton ther will be an list:(a doubly link list) 
if there a error somewhere everything before will be deleted

- evalution: each string passed down the pipeline will be converted 
to what it should be  element prefixed with with a $  in and out of a
string will be 'expanded' otherwise the value with the $ before stay the same without the '
the 'quoting can be nested the first seen do the behavior'
the evalution part of the program is self standing and can be use in any 
other project with minimal  change

- execution: at this stage the program will  try to do rediction < > >> but not << since its
done 'in evalution part' any errror will bail an early exit and not execute anything
last part is trying to see if  the arguments is an executable or otherwise
EVERYTHING tha is not  readline in a subprocess will be deleted in an errors or not
</details>
<details>
 <summary markdown="span">  tour of the struggle that we had during the  project </summary> 
 
 ---

- https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/executing/find_part.c#L68
since we are required to free all the memory  forking is quiete tricky to keep track of since we use readline 
give some level of  overhead in term of memory usage:
to get this checked i made program able to be run without readline wich "-c" wich allow  us  to see how  much
memory the program is use without it...
this feature can also be use to make unit test.

- https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/parsing/parsing.c#L16 
- https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/executing/fd.c#L15
handling correctly pipes was quiete a challenge since i could not find alot of example on the subject
that could fit in the project

- https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/jobs/jobs_lst.c#L60
since i took the path of not creating a binary tree i had to  manualy figure out the path of each comand in  any order
the complexity come from the fact that  redirection can take place before the command and after the command  and argument
are in the  middle example "< main.c  cat -e < utils.c" the argument are cat -e and the other tokens are use as redirection

- https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/eval/eval.c#L75
evalution can get a bit messy since you can handle many type of token  than can be followed one after the other
 such as 'hello'"word"github or '$USER'"$USER"$USER or trying or having an random  quote in the other type of quote " 'hello" or the way around
 what should the  evalution return when the enviroment does not have the value a NULL ptr? or simply a empty string? i choose empty string
 since you incrimentaly make a string the memory handling get wild you have to keep track of the base string and not free it while also keeping 
 track of the previous part:
 i solved most of thoses overhead with
 - https://github.com/Kampouse/mini-shell-racoon/blob/e8d0e5a7eccf01fb74ac809bc6414dfa64d47cc3/eval/eval_util.c#L46
 </details>
 <details>
 
 
  <summary markdown="span">  want to know more on how to build a shell? </summary> 
 - https://github.com/csabagabor/Basic-Shell-implementation-in-C/blob/a176b00b5f03027882ea1f7ae6c7f01f697cc328/shell.c#L83 <br>
- https://githubmemory.com/repo/gleal42/42_Minishell <br>
 - https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf <br>
 - https://www.notion.so/Minishell-Materials-7bbd45a806e04395ab578ca3f805806c
</details>
