for k in $(seq 1 $2);
do
	tests=`sed '1q;d' $k.in`
	for i in $(seq 2 $(($tests+1)));
	do
		input=`sed "$i q;d" $k.in`
		output=`sed "$i q;d" $k.out`
		result=`./$1 $input` 
		if [[ "$result" == "$output" ]]; then : ; else echo 0; exit 0; fi;
	done
done
echo 1;
