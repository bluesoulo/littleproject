#!/bin/bash
echo "hello world!"
functionCopy(){
  command=$*
  length=$(expr $# - 2)
  strs=($command)
  dir=${strs[$(expr $length + 1)]}
  if [ -d $dir ]
  then
   echo "***************"
   cmd=cp
   for str in ${strs[*]:1:$length}
   do
   echo $str
   if [ -f $str ]
   then
    cmd="$cmd $str"
   else
    echo "$str is not a file!"
pelineFunc#cat temFile
   fi
   done
   cmd="$cmd $dir"
   echo $cmd
   $cmd
  else
  echo "there is not $dir dictionary "
  exit 1
  fi
}

pipelineFunc(){
  string=$*
  OLD_IFS="$IFS"
  IFS=$'\|'
  array=($string)
  length=${#array[@]}
  cmd1=${array[0]}
#  echo $cmd1
  cmd1="$cmd1 > temFile"
#  echo "$cmd1"
  eval $cmd1
#  echo "**$length**"
  if [ $length -gt 2 ]
  then
  for var in ${array[@]:1:$(expr $length - 2)}
  do
     IFS="$OLD_IFS"
     eval "$var temFile > temFile1"
     eval "cat temFile1 > temFile"
     OLD_IFS="$IFS"
  done
  fi
  IFS="$OLD_IFS"
 # echo ${array[$(expr $length - 1)]}
  #cmd2="${array[$(expr $length - 1)]} temFile"
  eval "${array[$(expr $length - 1)]} temFile"
  #eval $cmd2
}




while true
do
   read -p "22125254zhangjj@:" command
   strs=($command)
   isPipe=$(echo $command | grep "|")
   if [[ "$isPipe" != "" ]]
   then
   pipelineFunc $command
   elif [ ${strs[0]} == "pwd" ];
   then
   #SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)
   SHELL_FOLDER=$(pwd)
   echo $SHELL_FOLDER
   #elif [ `expr match "$command" "ls"` -gt 0 ];
   elif [ ${strs[0]} == "ls" ];
   then
   FILE_INFOR=$($command)
   echo "$FILE_INFOR"
   elif [ ${strs[0]} == "cd" ];
   then
   cd ${strs[1]}
   elif [ ${strs[0]} == "cp" ];
   then
   functionCopy $command
   elif [ ${strs[0]} == "man" ];
   then
   man=$($command)
   echo "$man"
   elif [ ${strs[0]} == "expr" ];
   then
   #echo "$command"
   #echo -n "result is"
   eval $command
   #elif [[ "$isPipe" != "" ]]
   #then
   #pipelineFunc $command
   else
   echo "command not found!" 
   #echo $(pwd)
   #path=$($command)
   #touch myfile   #创建一个文件
   fi
done

