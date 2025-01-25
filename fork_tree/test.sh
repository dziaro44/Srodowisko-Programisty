function getcpid() {
	local a=`pgrep -P $1 | sed '1q;d'`
	local b=`pgrep -P $1 | sed '2q;d'`
	local c=`pgrep -P $1 | sed '3q;d'`
	if [[ -z "$c" ]]; then : ; else echo 0; return 0; fi
	if [[ $2 -eq 1 ]]; 
		then if [[ -z "$a" ]]; then echo 1; return 0; else echo 0; return 0; fi; 
		else if [[ -z "$a" ]]; then echo 0; return 0; fi;
	fi;
       	if [ $2 -eq 2 ]; 
                then if [[ -z "$b" ]]; then : ; else echo 0; return 0; fi;
                else if [[ -z "$b" ]]; then echo 0; return 0; fi;
        fi;	
	local k=1
	local pow=0
	while [ $k -le $(($2+1)) ] 
	do 
	pow=$(($pow+1))
	k=$(($k*2))
	done
	k=$(($k/2))
	local x=$(($k-2))
	x=$(($x/2))
	local s=$(($2-$k))
	s=$(($s+1))
	
	local first=$x
	local second=$x

	if [[ $s -le $(($k/2)) ]]; then first=$(($first + $s)); else first=$(($first + $k/2)); second=$(($second + $s - $k/2)); fi;
	if [[ $2 -eq 2 ]]; then echo $(getcpid $a 1); return 0; fi;

	local res1=$(getcpid $a $first)
	local res2=$(getcpid $b $second)
	if [[ $res1 -eq 1 && $res2 -eq 1 ]]; then echo 1; return 0; else echo 0; return 0; fi;
}

echo $(getcpid $1 $2)
